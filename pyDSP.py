# -*- coding: utf-8 -*-
# @Time : 2022/4/19 下午5:25
# @Author : Rongkai
# @Email : rongkai@mail.ustc.edu.cn
# @Function : 
# @File : DSP.py
# @Software: PyCharm
# @Platform: Ubuntu 20.04
import DSP.build.DSP_Fun as DSP_Fun

# Initialize DSP
def DSP_init():
    DSP_Fun.initIIRLowapass()
    DSP_Fun.initIIRLowapassR()
    DSP_Fun.initIIRLowapassL()
    DSP_Fun.initDev1()
    DSP_Fun.initDev2()
    DSP_Fun.initOutputFilter()
    DSP_Fun.initTVD()
    DSP_Fun.initOmegaLFilter()
    DSP_Fun.initOmegaRFilter()

# Low-pass filter（cut-off 5hz）
def DSP_IIR_LowPassFilter(input):
    DSP_Fun.setIIRLPInput(input)
    output = DSP_Fun.stepIIRLP()
    return output
# Low-pass filter（cut-off 5hz）for hip joint
def DSP_IIR_LowPassFilter_L(input):
    DSP_Fun.setIIRLPInputL(input)
    output = DSP_Fun.stepIIRLPL()
    return output
# Low-pass filter（cut-off 5hz）for hip joint
def DSP_IIR_LowPassFilter_R(input):
    DSP_Fun.setIIRLPInputR(input)
    output = DSP_Fun.stepIIRLPR()
    return output

# Low-pass filter（cut-off 2hz）
def DSP_IIR_LowPassFilter_omegaL(input):
    DSP_Fun.setOmegaLFilterInput(input)
    output = DSP_Fun.stepOmegaLFilter()
    return output

# Low-pass filter（cut-off 2hz）
def DSP_IIR_LowPassFilter_omegaR(input):
    DSP_Fun.setOmegaRFilterInput(input)
    output = DSP_Fun.stepOmegaRFilter()
    return output

# Low-pass filter（cut-off 2hz）
def DSP_IIR_LowPassFilter_output(input):
    DSP_Fun.setOutputFilterInput(input)
    output = DSP_Fun.stepOutputFilter()
    return output

# Band Pass Filter（cut-off 0.2-3hz）
def DSP_IIR_BandPassRFilter(input):
    DSP_Fun.setIIRBPRInput(input)
    output = DSP_Fun.stepIIRBPR()
    return output

# Band Pass Filter（cut-off 0.2-3hz）
def DSP_IIR_BandPassLFilter(input):
    DSP_Fun.setIIRBPLInput(input)
    output = DSP_Fun.stepIIRBPL()
    return output

# First order differential
def DSP_1order_difference(input):
    DSP_Fun.setDev1Input(input)
    output = DSP_Fun.stepDev1()
    return output

# 二阶差分
def DSP_2order_difference(input):
    DSP_Fun.setDev2Input(input)
    output = DSP_Fun.stepDev2()
    return output
