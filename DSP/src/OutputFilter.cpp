/*
 * OutputFilter.cpp
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "OutputFilter".
 *
 * Model version              : 1.1
 * Simulink Coder version : 9.3 (R2020a) 18-Nov-2019
 * C++ source code generated on : Tue May 18 11:15:49 2021
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "OutputFilter.h"
#include "OutputFilter_private.h"

real_T OutputFilterModelClass::OutputF_BiquadFilter_outputImpl
  (b_dspcodegen_BiquadFilter_Out_T *obj, real_T varargin_1)
{
  real_T varargout_1;
  real_T stageIn;

  /* System object Outputs function: dsp.BiquadFilter */
  varargout_1 = ((obj->cSFunObject.P1_RTP1COEFF[2] *
                  obj->cSFunObject.W0_ZERO_STATES[1] +
                  (obj->cSFunObject.P1_RTP1COEFF[1] *
                   obj->cSFunObject.W0_ZERO_STATES[0] +
                   obj->cSFunObject.P1_RTP1COEFF[0] * varargin_1)) -
                 obj->cSFunObject.P2_RTP2COEFF[0] *
                 obj->cSFunObject.W1_POLE_STATES[0]) -
    obj->cSFunObject.P2_RTP2COEFF[1] * obj->cSFunObject.W1_POLE_STATES[1];
  obj->cSFunObject.W0_ZERO_STATES[1] = obj->cSFunObject.W0_ZERO_STATES[0];
  obj->cSFunObject.W0_ZERO_STATES[0] = varargin_1;
  obj->cSFunObject.W1_POLE_STATES[1] = obj->cSFunObject.W1_POLE_STATES[0];
  obj->cSFunObject.W1_POLE_STATES[0] = varargout_1;
  stageIn = varargout_1;
  varargout_1 = ((obj->cSFunObject.P1_RTP1COEFF[5] *
                  obj->cSFunObject.W0_ZERO_STATES[3] +
                  (obj->cSFunObject.P1_RTP1COEFF[4] *
                   obj->cSFunObject.W0_ZERO_STATES[2] +
                   obj->cSFunObject.P1_RTP1COEFF[3] * varargout_1)) -
                 obj->cSFunObject.P2_RTP2COEFF[2] *
                 obj->cSFunObject.W1_POLE_STATES[2]) -
    obj->cSFunObject.P2_RTP2COEFF[3] * obj->cSFunObject.W1_POLE_STATES[3];
  obj->cSFunObject.W0_ZERO_STATES[3] = obj->cSFunObject.W0_ZERO_STATES[2];
  obj->cSFunObject.W0_ZERO_STATES[2] = stageIn;
  obj->cSFunObject.W1_POLE_STATES[3] = obj->cSFunObject.W1_POLE_STATES[2];
  obj->cSFunObject.W1_POLE_STATES[2] = varargout_1;
  stageIn = varargout_1;
  varargout_1 = ((obj->cSFunObject.P1_RTP1COEFF[8] *
                  obj->cSFunObject.W0_ZERO_STATES[5] +
                  (obj->cSFunObject.P1_RTP1COEFF[7] *
                   obj->cSFunObject.W0_ZERO_STATES[4] +
                   obj->cSFunObject.P1_RTP1COEFF[6] * varargout_1)) -
                 obj->cSFunObject.P2_RTP2COEFF[4] *
                 obj->cSFunObject.W1_POLE_STATES[4]) -
    obj->cSFunObject.P2_RTP2COEFF[5] * obj->cSFunObject.W1_POLE_STATES[5];
  obj->cSFunObject.W0_ZERO_STATES[5] = obj->cSFunObject.W0_ZERO_STATES[4];
  obj->cSFunObject.W0_ZERO_STATES[4] = stageIn;
  obj->cSFunObject.W1_POLE_STATES[5] = obj->cSFunObject.W1_POLE_STATES[4];
  obj->cSFunObject.W1_POLE_STATES[4] = varargout_1;
  stageIn = varargout_1;
  varargout_1 = ((obj->cSFunObject.P1_RTP1COEFF[11] *
                  obj->cSFunObject.W0_ZERO_STATES[7] +
                  (obj->cSFunObject.P1_RTP1COEFF[10] *
                   obj->cSFunObject.W0_ZERO_STATES[6] +
                   obj->cSFunObject.P1_RTP1COEFF[9] * varargout_1)) -
                 obj->cSFunObject.P2_RTP2COEFF[6] *
                 obj->cSFunObject.W1_POLE_STATES[6]) -
    obj->cSFunObject.P2_RTP2COEFF[7] * obj->cSFunObject.W1_POLE_STATES[7];
  obj->cSFunObject.W0_ZERO_STATES[7] = obj->cSFunObject.W0_ZERO_STATES[6];
  obj->cSFunObject.W0_ZERO_STATES[6] = stageIn;
  obj->cSFunObject.W1_POLE_STATES[7] = obj->cSFunObject.W1_POLE_STATES[6];
  obj->cSFunObject.W1_POLE_STATES[6] = varargout_1;
  stageIn = varargout_1;
  varargout_1 = ((obj->cSFunObject.P1_RTP1COEFF[14] *
                  obj->cSFunObject.W0_ZERO_STATES[9] +
                  (obj->cSFunObject.P1_RTP1COEFF[13] *
                   obj->cSFunObject.W0_ZERO_STATES[8] +
                   obj->cSFunObject.P1_RTP1COEFF[12] * varargout_1)) -
                 obj->cSFunObject.P2_RTP2COEFF[8] *
                 obj->cSFunObject.W1_POLE_STATES[8]) -
    obj->cSFunObject.P2_RTP2COEFF[9] * obj->cSFunObject.W1_POLE_STATES[9];
  obj->cSFunObject.W0_ZERO_STATES[9] = obj->cSFunObject.W0_ZERO_STATES[8];
  obj->cSFunObject.W0_ZERO_STATES[8] = stageIn;
  obj->cSFunObject.W1_POLE_STATES[9] = obj->cSFunObject.W1_POLE_STATES[8];
  obj->cSFunObject.W1_POLE_STATES[8] = varargout_1;
  return varargout_1;
}

void OutputFilterModelClass::OutputFilter_SystemCore_release
  (b_dspcodegen_BiquadFilter_Out_T *obj)
{
  if (obj->isInitialized == 1) {
    obj->isInitialized = 2;
  }
}

void OutputFilterModelClass::Outp_LPHPFilterBase_releaseImpl
  (dsp_LowpassFilter_OutputFilte_T *obj)
{
  OutputFilter_SystemCore_release(obj->FilterObj);
  obj->NumChannels = -1;
}

void OutputFilterModelClass::Outpu_SystemCore_releaseWrapper
  (dsp_LowpassFilter_OutputFilte_T *obj)
{
  if (obj->isSetupComplete) {
    Outp_LPHPFilterBase_releaseImpl(obj);
  }
}

void OutputFilterModelClass::OutputFilt_SystemCore_release_g
  (dsp_LowpassFilter_OutputFilte_T *obj)
{
  if (obj->isInitialized == 1) {
    Outpu_SystemCore_releaseWrapper(obj);
  }
}

void OutputFilterModelClass::OutputFilte_SystemCore_delete_g
  (dsp_LowpassFilter_OutputFilte_T *obj)
{
  OutputFilt_SystemCore_release_g(obj);
}

void OutputFilterModelClass::matlabCodegenHandle_matlabCod_g
  (dsp_LowpassFilter_OutputFilte_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    OutputFilte_SystemCore_delete_g(obj);
  }
}

void OutputFilterModelClass::OutputFilter_SystemCore_delete
  (b_dspcodegen_BiquadFilter_Out_T *obj)
{
  OutputFilter_SystemCore_release(obj);
}

void OutputFilterModelClass::matlabCodegenHandle_matlabCodeg
  (b_dspcodegen_BiquadFilter_Out_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    OutputFilter_SystemCore_delete(obj);
  }
}

/* Model step function */
void OutputFilterModelClass::step()
{
  int32_T i;

  /* MATLABSystem: '<Root>/Lowpass Filter' */
  if (OutputFilter_DW.obj.FilterObj->isInitialized != 1) {
    OutputFilter_DW.obj.FilterObj->isSetupComplete = false;
    OutputFilter_DW.obj.FilterObj->isInitialized = 1;
    OutputFilter_DW.obj.FilterObj->isSetupComplete = true;

    /* System object Initialization function: dsp.BiquadFilter */
    for (i = 0; i < 10; i++) {
      OutputFilter_DW.obj.FilterObj->cSFunObject.W0_ZERO_STATES[i] =
        OutputFilter_DW.obj.FilterObj->cSFunObject.P0_ICRTP;
    }

    for (i = 0; i < 10; i++) {
      OutputFilter_DW.obj.FilterObj->cSFunObject.W1_POLE_STATES[i] =
        OutputFilter_DW.obj.FilterObj->cSFunObject.P5_IC2RTP;
    }
  }

  /* Outport: '<Root>/Out1' incorporates:
   *  Inport: '<Root>/In1'
   *  MATLABSystem: '<Root>/Lowpass Filter'
   */
  OutputFilter_Y.Out1 = OutputF_BiquadFilter_outputImpl
    (OutputFilter_DW.obj.FilterObj, OutputFilter_U.In1);
}

/* Model initialize function */
void OutputFilterModelClass::initialize()
{
  {
    b_dspcodegen_BiquadFilter_Out_T *iobj_0;
    int32_T i;
    static const real_T tmp[15] = { 0.13028248809856738, -0.21020647540920676,
      0.13028248809856741, 0.11389775971916542, 0.11389775971916542, 0.0,
      0.37564688385120537, -0.66833141524575379, 0.37564688385120537,
      0.070668003820800254, -0.0718661068967752, 0.070668003820800254,
      0.47963104263999579, -0.83579096925230434, 0.47963104263999612 };

    static const real_T tmp_0[10] = { -1.7765639435572051, 0.86222285820358036,
      -0.8660800117246511, 0.0, -1.8359410567060894, 0.97930100587415037,
      -1.7462808673121328, 0.78648307458248246, -1.806841079303805,
      0.93031219533149212 };

    /* Start for MATLABSystem: '<Root>/Lowpass Filter' */
    OutputFilter_DW.gobj_1.matlabCodegenIsDeleted = true;
    OutputFilter_DW.gobj_2.matlabCodegenIsDeleted = true;
    OutputFilter_DW.obj.matlabCodegenIsDeleted = true;
    iobj_0 = &OutputFilter_DW.gobj_2;
    OutputFilter_DW.obj.isInitialized = 0;
    OutputFilter_DW.obj.NumChannels = -1;
    OutputFilter_DW.obj.matlabCodegenIsDeleted = false;
    OutputFilter_DW.objisempty = true;
    OutputFilter_DW.obj.isSetupComplete = false;
    OutputFilter_DW.obj.isInitialized = 1;
    OutputFilter_DW.gobj_2.isInitialized = 0;

    /* System object Constructor function: dsp.BiquadFilter */
    iobj_0->cSFunObject.P0_ICRTP = 0.0;
    for (i = 0; i < 15; i++) {
      iobj_0->cSFunObject.P1_RTP1COEFF[i] = tmp[i];
    }

    for (i = 0; i < 10; i++) {
      iobj_0->cSFunObject.P2_RTP2COEFF[i] = tmp_0[i];
    }

    for (i = 0; i < 6; i++) {
      iobj_0->cSFunObject.P3_RTP3COEFF[i] = 0.0;
    }

    for (i = 0; i < 6; i++) {
      iobj_0->cSFunObject.P4_RTP_COEFF3_BOOL[i] = false;
    }

    iobj_0->cSFunObject.P5_IC2RTP = 0.0;
    OutputFilter_DW.gobj_2.matlabCodegenIsDeleted = false;
    OutputFilter_DW.obj.FilterObj = &OutputFilter_DW.gobj_2;
    OutputFilter_DW.obj.NumChannels = 1;
    OutputFilter_DW.obj.isSetupComplete = true;

    /* End of Start for MATLABSystem: '<Root>/Lowpass Filter' */

    /* InitializeConditions for MATLABSystem: '<Root>/Lowpass Filter' */
    if (OutputFilter_DW.obj.FilterObj->isInitialized == 1) {
      /* System object Initialization function: dsp.BiquadFilter */
      for (i = 0; i < 10; i++) {
        OutputFilter_DW.obj.FilterObj->cSFunObject.W0_ZERO_STATES[i] =
          OutputFilter_DW.obj.FilterObj->cSFunObject.P0_ICRTP;
      }

      for (i = 0; i < 10; i++) {
        OutputFilter_DW.obj.FilterObj->cSFunObject.W1_POLE_STATES[i] =
          OutputFilter_DW.obj.FilterObj->cSFunObject.P5_IC2RTP;
      }
    }

    /* End of InitializeConditions for MATLABSystem: '<Root>/Lowpass Filter' */
  }
}

/* Model terminate function */
void OutputFilterModelClass::terminate()
{
  /* Terminate for MATLABSystem: '<Root>/Lowpass Filter' */
  matlabCodegenHandle_matlabCod_g(&OutputFilter_DW.obj);
  matlabCodegenHandle_matlabCodeg(&OutputFilter_DW.gobj_2);
  matlabCodegenHandle_matlabCodeg(&OutputFilter_DW.gobj_1);
}

/* Constructor */
OutputFilterModelClass::OutputFilterModelClass():
  OutputFilter_DW()
  ,OutputFilter_U()
  ,OutputFilter_Y()
  ,OutputFilter_M()
{
  /* Currently there is no constructor body generated.*/
}

/* Destructor */
OutputFilterModelClass::~OutputFilterModelClass()
{
  /* Currently there is no destructor body generated.*/
}

/* Real-Time Model get method */
RT_MODEL_OutputFilter_T * OutputFilterModelClass::getRTM()
{
  return (&OutputFilter_M);
}
