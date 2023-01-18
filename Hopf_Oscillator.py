
# -*- coding: utf-8 -*-
# @Time : 2021/4/21 21:40
# @Author : Rongkai
# @Email : rongkai@mail.ustc.edu.cn
# @Function : Hopf nonlinear oscillator model
# @File : Hopf_Oscillator.py
# @Software: PyCharm
# @Platform: Ubuntu 20.04

import numpy as np

class AdapHopfCpg(object):

    def __init__(self, alpha=1, mu=1, ep=0.3, eta=1, x_0 = 0.1, y_0=0.1, w_0=0.5, a_0=0.1, a_1=0.1, timestep=0.02):
        '''
		Initialization parameters
        :param alpha: Attractive strength parameters of the oscillator
        :param mu: Oscillator amplitude parameters
        :param ep: Adaptive coupling strength
        :param x_0: Initial value of the state vector x
        :param y_0: Initial value of the state vector y
        :param w_0: Initial value of the state vector w
        :param timestep: Time step
        '''
        self.alpha = alpha
        self.mu = mu
        self.ep = ep
        self.eta = eta
        self.timestep = timestep
        self.initState = np.array([x_0, y_0, w_0, a_0, a_1])

    def StateUpdate(self, time_steps, states_trans, y_demo):
        '''
        hopf oscillator mathematical model
        :param y_demo: Input Data
        '''
        x, y, w, a0, a1 = states_trans
        if w < 0:
            states_trans = self.initState
        e_t = y_demo - (a0 + a1 * x)
        r_square = x**2 + y**2
        x_dot = self.alpha * (self.mu - r_square) * x - w * y + self.ep * e_t
        y_dot = self.alpha * (self.mu - r_square) * y + w * x
        w_dot =  - self.ep * e_t * y/np.sqrt(r_square)
        a0_dot = self.eta * e_t
        a1_dot = self.eta * x * e_t
        return np.array([x_dot, y_dot, w_dot, a0_dot, a1_dot])

#%%
