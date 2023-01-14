# -*- coding: utf-8 -*-
# @Time : 2021/4/21 21:58
# @Author : Rongkai
# @Email : rongkai@mail.ustc.edu.cn
# @Function : Data iterator
# @File : DataLoader.py
# @Software: PyCharm
# @Platform: Ubuntu 20.04
import time

import numpy as np
import pandas as pd
import pika
import DSP.build.DSP_Fun as DSP_Fun
import struct
import json5
import threading

class CSV_DataIter(object):

    def __init__(self,filedir:str,filename:str,column:list,skiprows=1):
        '''
        Read CSV file and create data iterator
            :param filedir: Folder name
            :param filename: File Name
            :param column: column name
        '''
        self.filename = '{}/{}'.format(filedir,filename)
        self.data_frame = pd.read_csv(self.filename, skiprows=skiprows)
        self.data_array = np.array(self.data_frame)
        self.target_column = self.data_frame[column].values.tolist()
        self.data_iter = iter(self.target_column)
        self.data_len = self.data_frame.shape[0]
        self.index_now = -1
        print(self.data_frame.columns)
        print(self.data_frame.info)

    def getone(self):
        '''
        Iterate to get one frame of data
        '''
        self.index_now += 1
        return next(self.data_iter)

    def start_publish(self, period=20):
        #Connect to Rabbit
        self.connection = pika.BlockingConnection(pika.ConnectionParameters(host='localhost'))
        #Build Rabbit protocol channel
        self.channel = self.connection.channel()
        self.channel.exchange_declare("Joint_Data_EXC",exchange_type='fanout')
        self.publish_running = True
        def run():
            i = self.data_len
            while (not i == 0) and self.publish_running:
                i -= 1
                self.channel.basic_publish(exchange='Joint_Data_EXC', routing_key='', body=json5.dumps(self.getone()))
                time.sleep(0.02)
            try:
                sys.exit(0)
            except:
                print("CSV_Loader_Shutdown")
        CSV_Publish_Thread = threading.Thread(target=run)
        CSV_Publish_Thread.start()

    def stop_publish(self):
        self.publish_running = False

class Dataloader_Subscriber(object):
    def __init__(self,*args, **kwargs):
        #Connect to Rabbit
        self.connection = pika.BlockingConnection(pika.ConnectionParameters(host='localhost'))
        #Build Rabbit protocol channel
        self.channel = self.connection.channel()
        self.channel.exchange_declare("Joint_Data_EXC",exchange_type='fanout')
        result = self.channel.queue_declare(queue='', exclusive=True)
        self.queue_name = result.method.queue
        self.channel.queue_bind(queue=self.queue_name,exchange="Joint_Data_EXC",routing_key='')
        self.__lock = threading.Lock()

    def default_callback(self,ch, method, properties, body):
        print(" [x] %r:%r consumed" % (method.routing_key, body))

    def consume(self,callback):
        self.channel.basic_consume(queue=self.queue_name,on_message_callback=callback)
        self.channel.start_consuming()       #阻塞

    def start_listen(self,callback_fun = None):
        if callback_fun == None:
            callback = self.default_callback
        else:
            callback = callback_fun
        consumer_thread = threading.Thread(Target=self.consume(callback))
        consumer_thread.start()

    def get_one(self):
        data = self.channel.basic_get(queue=self.queue_name,auto_ack=True)
        return data

    def __enter__(self):
        return self

    def __exit__(self, exc_type, exc_value, traceback):
        self.connection.close()



if __name__ == '__main__':
    myloader = CSV_DataIter('TestData','Gait_0.csv','L_calf')
    
    
