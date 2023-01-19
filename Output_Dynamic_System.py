
# -*- coding: utf-8 -*-
# @Time : 2021/4/20 14:52
# @Author : Rongkai
# @Email : rongkai@mail.ustc.edu.cn
# @Function : The mathematical model of dynamic movement primitives
# @File : Output_Dynamic_System.py
# @Software: PyCharm
# @Platform: Ubuntu 20.04

import numpy as np
import os

class Dynamic_Learning_System(object):

    def __init__(self, Num_Input, Num_State, Num_Output, z_0=0, y_0=0, para_Alpha = 25, para_Beta = 6, para_Gain = 0, para_N = 20, para_h = 2.5, para_r = 1, Time_Step_Len = 0.02):

        '''
        Initialize model parameters
        :param Num_Input: Input Dimension
        :param Num_State: State Dimension
        :param Num_Output: Output Dimension
        :param z_0: Initial state of z
        :param y_0: Initial state of y
        :param para_Alpha: Coefficient alpha
        :param para_Beta: Coefficient beta（alpha：beta=4:1）
        :param para_Gain: Base position adjustment factor
        :param para_N: Number of kernel functions
        :param para_h: Gaussian kernel width adjustment factor
        :param para_r: Magnitude adjustment factor
        :param time_step_len: Status Update Period (second)
        '''
        self.Num_Input = Num_Input
        self.Num_State = Num_State
        self.Num_Output = Num_Output        
        self.initState = np.array([z_0, y_0])
        self.para_Alpha = para_Alpha
        self.para_Beta = para_Beta
        self.para_Gain = para_Gain
        self.para_N = para_N
        self.para_h = para_h * para_N
        self.para_r = para_r
        self.Time_Step_Len = Time_Step_Len
        
        self.weights = np.zeros(para_N)
        self.P_cover = np.ones(para_N)

        self.para_c = np.linspace(0,2*np.pi,self.para_N)

        self.u_w = {}
        self.cov_w = {}

        # Get policy from GKL
        if os.path.exists("temp/weight_walk_mean.npy")==True:
            self.u_w["walk"] = np.load("temp/weight_walk_mean.npy")
        if os.path.exists("temp/weight_walk_cov.npy")==True:
            self.cov_w["walk"] = np.load("temp/weight_walk_cov.npy")
        if os.path.exists("temp/weight_upstair_mean.npy")==True:
            self.u_w["upstair"] = np.load("temp/weight_upstair_mean.npy")
        if os.path.exists("temp/weight_upstair_cov.npy")==True:
            self.cov_w["upstair"] = np.load("temp/weight_upstair_cov.npy")

        self.Q = np.array([[0.03,0],[0,0]])
        self.R = 0.22


        self.e_t_list = []

    def StateUpdate(self, time_steps, states_trans, min_omega, min_phi):
        '''
        ODS dynamics model state update
            :param states_trans: Previous States
            :param min_omega: Angular velocity tracking signal
            :param min_phi: Phase tracking signal
        '''
        para_c = np.linspace(0,2*np.pi,self.para_N)
        z, y = states_trans
        KWR = lambda k,w,r:k * w * r
        E_KWR = 0
        E_K = 0
        self.kernel_list = np.zeros(self.para_N)
        for index in range(0,self.para_N):
            kernel = np.exp(self.para_h * (np.cos(min_phi - para_c[index]) - 1))
            # print(kernel)
            E_KWR = np.add(E_KWR, KWR(kernel, self.weights[index], self.para_r))
            E_K = np.add(E_K, kernel)
            self.kernel_list[index] = kernel
        # print(self.kernel_list)
        check = lambda x: 0.000001 if x == 0 else x
        z_dot = min_omega * (self.para_Alpha * (self.para_Beta * (self.para_Gain - y) - z) + np.true_divide(E_KWR,check(E_K)))
        y_dot = min_omega * z
        return np.squeeze(np.array([z_dot,y_dot],dtype=object))

    def GetKernel(self, phase):
        '''
        Solving the kernel function from the phase
            :param phase: Phase parameter input
            :return Value of each Gaussian kernel function based on the current phase
        '''
        vec_ones = np.ones(self.para_N)
        phase = vec_ones * phase
        kernel = np.exp(self.para_h * (np.cos(phase - self.para_c) - vec_ones))
        return kernel

    def GetFr(self, phase):
        '''
        Solving the forcing term according to the phase
            :param phase: Phase parameter input
            :return Forcing term based on current phase
        '''
        kernel = self.GetKernel(phase)
        kernel_sum = kernel.sum()
        F = (Kernel @ self.weights)/kernel_sum
        Fr = F * self.para_r
        return Fr

    def WeightUpdate(self, y_demo, y_demo_dot, y_demo_dot_dot, min_omega, min_phi, para_Lamada = 0.95):
        '''
        Segmented linear model parameter learning
            :param y_demo: Demonstration of teaching signals
            :param y_demo_dot: First-order derivatives of demonstration signals
            :param y_demo_dot_dot: Second-order derivatives of demonstration signals
            :param min_omega: Angular velocity tracking signal
            :param min_phi: Phase tracking signal
            :param para_Lamada: Forgetting factor
        '''
        e_t=0

        f_targ = (1/min_omega**2) * y_demo_dot_dot - self.para_Alpha * (self.para_Beta * (self.para_Gain - y_demo)- (1/min_omega) * y_demo_dot)
        kernel_list = self.GetKernel(min_phi)
        for index in range(0, self.para_N):
            # Update residuals
            e_t = f_targ - self.weights[index] * self.para_r
            # Update covariance
            self.P_cover[index] = (1/para_Lamada) * (self.P_cover[index] - (self.P_cover[index]**2 * self.para_r**2 ) / ( para_Lamada / (kernel_list[index] + 0.000000001) + self.P_cover[index] * self.para_r**2 ))
            # Update segmented linear model parameters
            self.weights[index] = self.weights[index] + kernel_list[index] * self.P_cover[index] * self.para_r * e_t
        return self.weights

class Output_Dynamic_System_new(Dynamic_Learning_System):

    def __init__(self, Num_Input, Num_State, Num_Output, z_0=0, y_0=0, para_Alpha=25, para_Beta=6, para_Gain=0,
                 para_N=20, para_h=2.5, para_r=0.7, Time_Step_Len=0.02):
        super().__init__(Num_Input, Num_State, Num_Output, z_0, y_0, para_Alpha, para_Beta, para_Gain, para_N, para_h,
                         para_r, Time_Step_Len)

    def StateUpdate(self, time_steps, states_trans, min_omega, min_phi):
        '''
        ODS dynamics model state update
            :param states_trans: ODS mathematical dynamics model state update
            :param weights_trans: Weight vector input
            :param min_omega: Angular velocity tracking signal
            :param min_phi: Phase tracking signal
        '''
        z, y = states_trans
        KWR = lambda k, w, r: k * w * r
        E_KWR = 0
        E_K = 0
        for index in range(0, self.para_N):
            kernel = np.exp(self.para_h * (np.cos(min_phi - self.para_c[index]) - 1))
            E_KWR = np.add(E_KWR, KWR(kernel, self.weights[index], self.para_r))
            E_K = np.add(E_K, kernel)
        # print(self.kernel_list)
        check = lambda x: 0.000001 if x == 0 else x
        z_dot = min_omega * (
                    self.para_Alpha * (self.para_Beta * (self.para_Gain - y) - z) + np.true_divide(E_KWR, check(E_K)))
        y_dot = min_omega * z

        return np.squeeze(np.array([z_dot, y_dot], dtype=object))


        
        
        
        
        
        
        
        
        
        
        
