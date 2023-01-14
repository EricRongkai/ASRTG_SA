// 创建日期：2021.5.10
// 功能：基于pybind11的 C++ -> Python  程序调用接口
// 作者：刘镕恺

#include <iostream>
#include "TransDelay.h"
#include "pybind11/pybind11.h"
#include "IIRFilter_Bandpass.h"
#include "IIRFilter_Lowpass.h"
#include "OmegaFilter.h"
#include "Dev_1order.h"
#include "Dev_2order.h"
#include "OutputFilter.h"
#include "time.h"

//引入pybind11用于生成python工具库
namespace py = pybind11;

// int main()
// {
//     std::cout << "The DSP library is constructed" <<std::endl;
// }

/*************************** Kernal Sleep ****************************/

int nanoSleep_ms(unsigned int mSeconds)
{
    struct timespec req, rem;
    if(mSeconds > 999)
    {   
        req.tv_sec = (unsigned int)(mSeconds / 1000);             /* Must be Non-Negative */
        req.tv_nsec = (mSeconds - (req.tv_sec * 1000)) * 1000000; /* Must be in range of 0 to 999999999 */
    } 
    else
    {   
        req.tv_sec = 0;                                           /* Must be Non-Negative */
        req.tv_nsec = mSeconds * 1000000;                         /* Must be in range of 0 to 999999999 */
    }   
    return nanosleep(&req,&rem);
}


/*************************** TVD ****************************/

/* External inputs */
ExtU_TransDelay_T input = { 0,0 };
/* External outputs */
ExtY_TransDelay_T output = { 0 };
/* instantiation */
TransDelayModelClass MyTVModel;

std::string initTVD(void)
{
    MyTVModel.initialize();
    return "successful initialize TVD!";
}

void TVD_setInput(float In1, float In2)
{
    input.In1 = In1;
    input.In2 = In2;
    MyTVModel.setExternalInputs(&input);
}

float TVD_step(void)
{
    MyTVModel.step();
    output = MyTVModel.getExternalOutputs();
    float out = output.Out1;
    return out;
}

/*************************** IIRBandapass 0.2-3Hz ****************************/

/* External inputs */
ExtU_IIRFilter_Bandpass_T IIRFilter_BandpassR_U = { 0 };
/* External outputs */
ExtY_IIRFilter_Bandpass_T IIRFilter_BandpassR_Y = { 0 };
/* instantiation */
IIRFilter_BandpassModelClass MyIIR_BandpassR;

void IIRBandapassR_setInput(float In1)
{
    IIRFilter_BandpassR_U.In1 = In1;
    MyIIR_BandpassR.setExternalInputs(&IIRFilter_BandpassR_U);
}

float IIRBandapassR_step(void)
{
    MyIIR_BandpassR.step();
    IIRFilter_BandpassR_Y = MyIIR_BandpassR.getExternalOutputs();
    float out = IIRFilter_BandpassR_Y.Out1;
    return out;
}

/* External inputs */
ExtU_IIRFilter_Bandpass_T IIRFilter_BandpassL_U = { 0 };
/* External outputs */
ExtY_IIRFilter_Bandpass_T IIRFilter_BandpassL_Y = { 0 };
/* instantiation */
IIRFilter_BandpassModelClass MyIIR_BandpassL;

void IIRBandapassL_setInput(float In1)
{
    IIRFilter_BandpassL_U.In1 = In1;
    MyIIR_BandpassL.setExternalInputs(&IIRFilter_BandpassL_U);
}

float IIRBandapassL_step(void)
{
    MyIIR_BandpassL.step();
    IIRFilter_BandpassL_Y = MyIIR_BandpassL.getExternalOutputs();
    float out = IIRFilter_BandpassL_Y.Out1;
    return out;
}
/*************************** IIRLowapass 5hz****************************/

/* External inputs */
ExtU_IIRFilter_Lowpass_T IIRFilter_Lowpass_U = { 0 };
/* External outputs */
ExtY_IIRFilter_Lowpass_T IIRFilter_Lowpass_Y = { 0 };
/* instantiation */
IIRFilter_LowpassModelClass MyIIR_Lowpass;

std::string initIIRLowapass(void)
{
    MyIIR_Lowpass.initialize();
    return "successful initialize input lowpass filter!";
}

void IIRLowapass_setInput(float In1)
{
    IIRFilter_Lowpass_U.In1 = In1;
    MyIIR_Lowpass.setExternalInputs(&IIRFilter_Lowpass_U);
}

float IIRLowapass_step(void)
{
    MyIIR_Lowpass.step();
    IIRFilter_Lowpass_Y = MyIIR_Lowpass.getExternalOutputs();
    float out = IIRFilter_Lowpass_Y.Out1;
    return out;
}

/* External inputs */
ExtU_IIRFilter_Lowpass_T IIRFilter_LowpassR_U = { 0 };
/* External outputs */
ExtY_IIRFilter_Lowpass_T IIRFilter_LowpassR_Y = { 0 };
/* instantiation */
IIRFilter_LowpassModelClass MyIIR_LowpassR;

std::string initIIRLowapassR(void)
{
    MyIIR_LowpassR.initialize();
    return "successful initialize input lowpassR filter!";
}

void IIRLowapassR_setInput(float In1)
{
    IIRFilter_LowpassR_U.In1 = In1;
    MyIIR_LowpassR.setExternalInputs(&IIRFilter_LowpassR_U);
}

float IIRLowapassR_step(void)
{
    MyIIR_LowpassR.step();
    IIRFilter_LowpassR_Y = MyIIR_LowpassR.getExternalOutputs();
    float out = IIRFilter_LowpassR_Y.Out1;
    return out;
}

/* External inputs */
ExtU_IIRFilter_Lowpass_T IIRFilter_LowpassL_U = { 0 };
/* External outputs */
ExtY_IIRFilter_Lowpass_T IIRFilter_LowpassL_Y = { 0 };
/* instantiation */
IIRFilter_LowpassModelClass MyIIR_LowpassL;

std::string initIIRLowapassL(void)
{
    MyIIR_LowpassL.initialize();
    return "successful initialize input lowpass filter!";
}

void IIRLowapassL_setInput(float In1)
{
    IIRFilter_LowpassL_U.In1 = In1;
    MyIIR_LowpassL.setExternalInputs(&IIRFilter_LowpassL_U);
}

float IIRLowapassL_step(void)
{
    MyIIR_LowpassL.step();
    IIRFilter_LowpassL_Y = MyIIR_LowpassL.getExternalOutputs();
    float out = IIRFilter_LowpassL_Y.Out1;
    return out;
}
/*************************** OmegaFilter ****************************/

/* External inputs */
ExtU_OmegaFilter_T OmegaLFilter_U = { 0 };
/* External outputs */
ExtY_OmegaFilter_T OmegaLFilter_Y = { 0 };
/* instantiation */
OmegaFilterModelClass MyOmegaLFilter;

std::string initOmegaLFilter(void)
{
    MyOmegaLFilter.initialize();
    return "successful initialize OmegaLFilter!";
}

void OmegaLFilter_setInput(float In1)
{
    OmegaLFilter_U.In1 = In1;
    MyOmegaLFilter.setExternalInputs(&OmegaLFilter_U);
}

float OmegaLFilter_step(void)
{
    MyOmegaLFilter.step();
    OmegaLFilter_Y = MyOmegaLFilter.getExternalOutputs();
    float out = OmegaLFilter_Y.Out1;
    return out;
}

/* External inputs */
ExtU_OmegaFilter_T OmegaRFilter_U = { 0 };
/* External outputs */
ExtY_OmegaFilter_T OmegaRFilter_Y = { 0 };
/* instantiation */
OmegaFilterModelClass MyOmegaRFilter;

std::string initOmegaRFilter(void)
{
    MyOmegaRFilter.initialize();
    return "successful initialize OmegaRFilter!";
}

void OmegaRFilter_setInput(float In1)
{
    OmegaRFilter_U.In1 = In1;
    MyOmegaRFilter.setExternalInputs(&OmegaRFilter_U);
}

float OmegaRFilter_step(void)
{
    MyOmegaRFilter.step();
    OmegaRFilter_Y = MyOmegaRFilter.getExternalOutputs();
    float out = OmegaRFilter_Y.Out1;
    return out;
}

/*************************** Dev1 ****************************/

/* External inputs */
ExtU_Dev_1order_T Dev1_U = { 0 };
/* External outputs */
ExtY_Dev_1order_T Dev1_Y = { 0 };
/* instantiation */
Dev_1orderModelClass MyDev1;

std::string initDev1(void)
{
    MyDev1.initialize();
    return "successful initialize first order dev!";
}

void Dev1_setInput(float In1)
{
    Dev1_U.In1 = In1;
    MyDev1.setExternalInputs(&Dev1_U);
}

float Dev1_step(void)
{
    MyDev1.step();
    Dev1_Y = MyDev1.getExternalOutputs();
    float out = Dev1_Y.Out1;
    return out;
}

/*************************** Dev2 ****************************/

/* External inputs */
ExtU_Dev_2order_T Dev2_U = { 0 };
/* External outputs */
ExtY_Dev_2order_T Dev2_Y = { 0 };
/* instantiation */
Dev_2orderModelClass MyDev2;

std::string initDev2(void)
{
    MyDev2.initialize();
    return "successful initialize second order dev2!";
}

void Dev2_setInput(float In1)
{
    Dev2_U.In1 = In1;
    MyDev2.setExternalInputs(&Dev2_U);
}

float Dev2_step(void)
{
    MyDev2.step();
    Dev2_Y = MyDev2.getExternalOutputs();
    float out = Dev2_Y.Out1;
    return out;
}

/*************************** Output Filter ****************************/

/* External inputs */
ExtU_OutputFilter_T OutputFilter_U = { 0 };
/* External outputs */
ExtY_OutputFilter_T OutputFilter_Y = { 0 };
/* instantiation */
OutputFilterModelClass MyOutputFilter;

std::string initOutputFilter(void)
{
    MyOutputFilter.initialize();
    return "successful initialize output filter!";
}

void OutputFilter_setInput(float In1)
{
    OutputFilter_U.In1 = In1;
    MyOutputFilter.setExternalInputs(&OutputFilter_U);
}

float OutputFilter_step(void)
{
    MyOutputFilter.step();
    OutputFilter_Y = MyOutputFilter.getExternalOutputs();
    float out = OutputFilter_Y.Out1;
    return out;
}

PYBIND11_MODULE(DSP_Fun, m) {
    m.doc() = "Matlab C++ -> Python interface";

    m.def("nanoSleep_ms", &nanoSleep_ms, py::arg("muileseconds") = 0, "set variable");

    m.def("initTVD",&initTVD, "initialize initialize input lowpass filter");
    m.def("setTVDInput", &TVD_setInput, py::arg("data") = 0, py::arg("instan_D") = 0, "set variable");
    m.def("stepTVD", &TVD_step, "calculate next step");

    m.def("setIIRBPRInput", &IIRBandapassR_setInput, py::arg("data") = 0, "set variable");
    m.def("stepIIRBPR", &IIRBandapassR_step, "calculate next step");

    m.def("setIIRBPLInput", &IIRBandapassL_setInput, py::arg("data") = 0, "set variable");
    m.def("stepIIRBPL", &IIRBandapassL_step, "calculate next step");

    m.def("initIIRLowapass", &initIIRLowapass, "initialize input lowpass filter");
    m.def("setIIRLPInput", &IIRLowapass_setInput, py::arg("data") = 0, "set variable");
    m.def("stepIIRLP", &IIRLowapass_step, "calculate next step");

    m.def("initIIRLowapassL", &initIIRLowapassL, "initialize input lowpassL filter");
    m.def("setIIRLPInputL", &IIRLowapassL_setInput, py::arg("data") = 0, "set variable");
    m.def("stepIIRLPL", &IIRLowapassL_step, "calculate next step");

    m.def("initIIRLowapassR", &initIIRLowapassR, "initialize input lowpassR filter");
    m.def("setIIRLPInputR", &IIRLowapassR_setInput, py::arg("data") = 0, "set variable");
    m.def("stepIIRLPR", &IIRLowapassR_step, "calculate next step");

    m.def("initOmegaLFilter", &initOmegaLFilter, "initialize OmegaLFilter");
    m.def("setOmegaLFilterInput", &OmegaLFilter_setInput, py::arg("data") = 0, "set variable");
    m.def("stepOmegaLFilter", &OmegaLFilter_step, "calculate next step");

    m.def("initOmegaRFilter", &initOmegaRFilter, "initialize OmegaRFilter");
    m.def("setOmegaRFilterInput", &OmegaRFilter_setInput, py::arg("data") = 0, "set variable");
    m.def("stepOmegaRFilter", &OmegaRFilter_step, "calculate next step");

    m.def("initDev1", &initDev1, "initialize Dev1");
    m.def("setDev1Input", &Dev1_setInput, py::arg("data") = 0, "set variable");
    m.def("stepDev1", &Dev1_step, "calculate next step");

    m.def("initDev2", &initDev2, "initialize Dev2");
    m.def("setDev2Input", &Dev2_setInput, py::arg("data") = 0, "set variable");
    m.def("stepDev2", &Dev2_step, "calculate next step");

    m.def("initOutputFilter", &initOutputFilter, "initialize OutputFilter");
    m.def("setOutputFilterInput", &OutputFilter_setInput, py::arg("data") = 0, "set variable");
    m.def("stepOutputFilter", &OutputFilter_step, "calculate next step");
}

