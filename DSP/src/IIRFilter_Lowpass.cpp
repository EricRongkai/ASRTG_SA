/*
 * IIRFilter_Lowpass.cpp
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "IIRFilter_Lowpass".
 *
 * Model version              : 1.4
 * Simulink Coder version : 9.3 (R2020a) 18-Nov-2019
 * C++ source code generated on : Tue Jun 21 22:10:03 2022
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "IIRFilter_Lowpass.h"
#include "IIRFilter_Lowpass_private.h"

void IIRFilter_LowpassModelClass::IIRFilter_Lo_SystemCore_release
  (b_dspcodegen_FIRFilter_IIRFil_T *obj)
{
  if (obj->isInitialized == 1) {
    obj->isInitialized = 2;
  }
}

void IIRFilter_LowpassModelClass::IIRF_LPHPFilterBase_releaseImpl
  (dsp_LowpassFilter_IIRFilter_L_T *obj)
{
  IIRFilter_Lo_SystemCore_release(obj->FilterObj);
  obj->NumChannels = -1;
}

void IIRFilter_LowpassModelClass::IIRFi_SystemCore_releaseWrapper
  (dsp_LowpassFilter_IIRFilter_L_T *obj)
{
  if (obj->isSetupComplete) {
    IIRF_LPHPFilterBase_releaseImpl(obj);
  }
}

void IIRFilter_LowpassModelClass::IIRFilter__SystemCore_release_a
  (dsp_LowpassFilter_IIRFilter_L_T *obj)
{
  if (obj->isInitialized == 1) {
    IIRFi_SystemCore_releaseWrapper(obj);
  }
}

void IIRFilter_LowpassModelClass::IIRFilter_L_SystemCore_delete_a
  (dsp_LowpassFilter_IIRFilter_L_T *obj)
{
  IIRFilter__SystemCore_release_a(obj);
}

void IIRFilter_LowpassModelClass::matlabCodegenHandle_matlabCod_a
  (dsp_LowpassFilter_IIRFilter_L_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    IIRFilter_L_SystemCore_delete_a(obj);
  }
}

void IIRFilter_LowpassModelClass::IIRFilter_Low_SystemCore_delete
  (b_dspcodegen_FIRFilter_IIRFil_T *obj)
{
  IIRFilter_Lo_SystemCore_release(obj);
}

void IIRFilter_LowpassModelClass::matlabCodegenHandle_matlabCodeg
  (b_dspcodegen_FIRFilter_IIRFil_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    IIRFilter_Low_SystemCore_delete(obj);
  }
}

/* Model step function */
void IIRFilter_LowpassModelClass::step()
{
  b_dsp_FIRFilter_0_IIRFilter_L_T *obj;
  real_T acc1;
  real_T acc2;
  int32_T j;

  /* MATLABSystem: '<Root>/Lowpass Filter2' incorporates:
   *  Inport: '<Root>/In1'
   */
  if (IIRFilter_Lowpass_DW.obj.FilterObj->isInitialized != 1) {
    IIRFilter_Lowpass_DW.obj.FilterObj->isSetupComplete = false;
    IIRFilter_Lowpass_DW.obj.FilterObj->isInitialized = 1;
    IIRFilter_Lowpass_DW.obj.FilterObj->isSetupComplete = true;

    /* System object Initialization function: dsp.FIRFilter */
    for (j = 0; j < 14; j++) {
      IIRFilter_Lowpass_DW.obj.FilterObj->cSFunObject.W0_states[j] =
        IIRFilter_Lowpass_DW.obj.FilterObj->cSFunObject.P0_InitialStates;
    }
  }

  obj = &IIRFilter_Lowpass_DW.obj.FilterObj->cSFunObject;

  /* System object Outputs function: dsp.FIRFilter */
  /* Consume delay line and beginning of input samples */
  acc2 = IIRFilter_Lowpass_U.In1 *
    IIRFilter_Lowpass_DW.obj.FilterObj->cSFunObject.P1_Coefficients[0];
  acc1 = acc2;
  for (j = 0; j < 14; j++) {
    acc2 = obj->P1_Coefficients[j + 1] * obj->W0_states[j];
    acc1 += acc2;
  }

  /* Update delay line for next frame */
  for (j = 12; j >= 0; j--) {
    obj->W0_states[j + 1] = obj->W0_states[j];
  }

  IIRFilter_Lowpass_DW.obj.FilterObj->cSFunObject.W0_states[0] =
    IIRFilter_Lowpass_U.In1;

  /* Outport: '<Root>/Out1' incorporates:
   *  MATLABSystem: '<Root>/Lowpass Filter2'
   */
  IIRFilter_Lowpass_Y.Out1 = acc1;
}

/* Model initialize function */
void IIRFilter_LowpassModelClass::initialize()
{
  {
    b_dspcodegen_FIRFilter_IIRFil_T *iobj_0;
    int32_T i;
    static const real_T tmp[15] = { -0.011913233876841215, -0.015690193271413078,
      -0.0068952064992313065, 0.026980922381559448, 0.086849551868564148,
      0.15882268770791191, 0.21817272483293618, 0.24119821311402573,
      0.21817272483293618, 0.15882268770791191, 0.086849551868564148,
      0.026980922381559448, -0.0068952064992313065, -0.015690193271413078,
      -0.011913233876841215 };

    /* Start for MATLABSystem: '<Root>/Lowpass Filter2' */
    IIRFilter_Lowpass_DW.gobj_1.matlabCodegenIsDeleted = true;
    IIRFilter_Lowpass_DW.gobj_2.matlabCodegenIsDeleted = true;
    IIRFilter_Lowpass_DW.obj.matlabCodegenIsDeleted = true;
    iobj_0 = &IIRFilter_Lowpass_DW.gobj_2;
    IIRFilter_Lowpass_DW.obj.isInitialized = 0;
    IIRFilter_Lowpass_DW.obj.NumChannels = -1;
    IIRFilter_Lowpass_DW.obj.matlabCodegenIsDeleted = false;
    IIRFilter_Lowpass_DW.objisempty = true;
    IIRFilter_Lowpass_DW.obj.isSetupComplete = false;
    IIRFilter_Lowpass_DW.obj.isInitialized = 1;
    IIRFilter_Lowpass_DW.gobj_2.isInitialized = 0;

    /* System object Constructor function: dsp.FIRFilter */
    iobj_0->cSFunObject.P0_InitialStates = 0.0;
    for (i = 0; i < 15; i++) {
      iobj_0->cSFunObject.P1_Coefficients[i] = tmp[i];
    }

    IIRFilter_Lowpass_DW.gobj_2.matlabCodegenIsDeleted = false;
    IIRFilter_Lowpass_DW.obj.FilterObj = &IIRFilter_Lowpass_DW.gobj_2;
    IIRFilter_Lowpass_DW.obj.NumChannels = 1;
    IIRFilter_Lowpass_DW.obj.isSetupComplete = true;

    /* End of Start for MATLABSystem: '<Root>/Lowpass Filter2' */

    /* InitializeConditions for MATLABSystem: '<Root>/Lowpass Filter2' */
    if (IIRFilter_Lowpass_DW.obj.FilterObj->isInitialized == 1) {
      /* System object Initialization function: dsp.FIRFilter */
      for (i = 0; i < 14; i++) {
        IIRFilter_Lowpass_DW.obj.FilterObj->cSFunObject.W0_states[i] =
          IIRFilter_Lowpass_DW.obj.FilterObj->cSFunObject.P0_InitialStates;
      }
    }

    /* End of InitializeConditions for MATLABSystem: '<Root>/Lowpass Filter2' */
  }
}

/* Model terminate function */
void IIRFilter_LowpassModelClass::terminate()
{
  /* Terminate for MATLABSystem: '<Root>/Lowpass Filter2' */
  matlabCodegenHandle_matlabCod_a(&IIRFilter_Lowpass_DW.obj);
  matlabCodegenHandle_matlabCodeg(&IIRFilter_Lowpass_DW.gobj_2);
  matlabCodegenHandle_matlabCodeg(&IIRFilter_Lowpass_DW.gobj_1);
}

/* Constructor */
IIRFilter_LowpassModelClass::IIRFilter_LowpassModelClass():
  IIRFilter_Lowpass_DW()
  ,IIRFilter_Lowpass_U()
  ,IIRFilter_Lowpass_Y()
  ,IIRFilter_Lowpass_M()
{
  /* Currently there is no constructor body generated.*/
}

/* Destructor */
IIRFilter_LowpassModelClass::~IIRFilter_LowpassModelClass()
{
  /* Currently there is no destructor body generated.*/
}

/* Real-Time Model get method */
RT_MODEL_IIRFilter_Lowpass_T * IIRFilter_LowpassModelClass::getRTM()
{
  return (&IIRFilter_Lowpass_M);
}
