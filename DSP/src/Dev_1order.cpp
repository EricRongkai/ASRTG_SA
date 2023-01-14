/*
 * Dev_1order.cpp
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Dev_1order".
 *
 * Model version              : 1.4
 * Simulink Coder version : 9.3 (R2020a) 18-Nov-2019
 * C++ source code generated on : Wed Jun 22 15:58:30 2022
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Dev_1order.h"
#include "Dev_1order_private.h"

void Dev_1orderModelClass::Dev_1order_SystemCore_release
  (b_dspcodegen_FIRFilter_Dev_1o_T *obj)
{
  if (obj->isInitialized == 1) {
    obj->isInitialized = 2;
  }
}

void Dev_1orderModelClass::Dev__LPHPFilterBase_releaseImpl
  (dsp_LowpassFilter_Dev_1order_T *obj)
{
  Dev_1order_SystemCore_release(obj->FilterObj);
  obj->NumChannels = -1;
}

void Dev_1orderModelClass::Dev_1_SystemCore_releaseWrapper
  (dsp_LowpassFilter_Dev_1order_T *obj)
{
  if (obj->isSetupComplete) {
    Dev__LPHPFilterBase_releaseImpl(obj);
  }
}

void Dev_1orderModelClass::Dev_1order_SystemCore_release_e
  (dsp_LowpassFilter_Dev_1order_T *obj)
{
  if (obj->isInitialized == 1) {
    Dev_1_SystemCore_releaseWrapper(obj);
  }
}

void Dev_1orderModelClass::Dev_1order_SystemCore_delete_e
  (dsp_LowpassFilter_Dev_1order_T *obj)
{
  Dev_1order_SystemCore_release_e(obj);
}

void Dev_1orderModelClass::matlabCodegenHandle_matlabCod_e
  (dsp_LowpassFilter_Dev_1order_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    Dev_1order_SystemCore_delete_e(obj);
  }
}

void Dev_1orderModelClass::Dev_1order_SystemCore_delete
  (b_dspcodegen_FIRFilter_Dev_1o_T *obj)
{
  Dev_1order_SystemCore_release(obj);
}

void Dev_1orderModelClass::matlabCodegenHandle_matlabCodeg
  (b_dspcodegen_FIRFilter_Dev_1o_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    Dev_1order_SystemCore_delete(obj);
  }
}

/* Model step function */
void Dev_1orderModelClass::step()
{
  b_dsp_FIRFilter_0_Dev_1order_T *obj;
  real_T acc1;
  real_T acc2;
  int32_T j;
  real_T rtb_TSamp;
  real_T rtb_Diff;

  /* SampleTimeMath: '<S1>/TSamp' incorporates:
   *  Inport: '<Root>/In1'
   *
   * About '<S1>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  rtb_TSamp = Dev_1order_U.In1 * Dev_1order_P.TSamp_WtEt;

  /* Sum: '<S1>/Diff' incorporates:
   *  UnitDelay: '<S1>/UD'
   */
  rtb_Diff = rtb_TSamp - Dev_1order_DW.UD_DSTATE;

  /* MATLABSystem: '<Root>/Lowpass Filter3' */
  if (Dev_1order_DW.obj.FilterObj->isInitialized != 1) {
    Dev_1order_DW.obj.FilterObj->isSetupComplete = false;
    Dev_1order_DW.obj.FilterObj->isInitialized = 1;
    Dev_1order_DW.obj.FilterObj->isSetupComplete = true;

    /* System object Initialization function: dsp.FIRFilter */
    for (j = 0; j < 15; j++) {
      Dev_1order_DW.obj.FilterObj->cSFunObject.W0_states[j] =
        Dev_1order_DW.obj.FilterObj->cSFunObject.P0_InitialStates;
    }
  }

  obj = &Dev_1order_DW.obj.FilterObj->cSFunObject;

  /* System object Outputs function: dsp.FIRFilter */
  /* Consume delay line and beginning of input samples */
  acc2 = rtb_Diff * Dev_1order_DW.obj.FilterObj->cSFunObject.P1_Coefficients[0];
  acc1 = acc2;
  for (j = 0; j < 15; j++) {
    acc2 = obj->P1_Coefficients[j + 1] * obj->W0_states[j];
    acc1 += acc2;
  }

  /* Update delay line for next frame */
  for (j = 13; j >= 0; j--) {
    obj->W0_states[j + 1] = obj->W0_states[j];
  }

  Dev_1order_DW.obj.FilterObj->cSFunObject.W0_states[0] = rtb_Diff;

  /* Outport: '<Root>/Out1' incorporates:
   *  MATLABSystem: '<Root>/Lowpass Filter3'
   */
  Dev_1order_Y.Out1 = acc1;

  /* Update for UnitDelay: '<S1>/UD' */
  Dev_1order_DW.UD_DSTATE = rtb_TSamp;
}

/* Model initialize function */
void Dev_1orderModelClass::initialize()
{
  {
    b_dspcodegen_FIRFilter_Dev_1o_T *iobj_0;
    int32_T i;
    static const real_T tmp[16] = { 0.0075191496157868331, 0.027234775460433337,
      0.025399175018532155, -0.023798015829950926, -0.072622779912097729,
      -0.0095365491506878217, 0.19086514245015551, 0.38162162396588528,
      0.38162162396588528, 0.19086514245015551, -0.0095365491506878217,
      -0.072622779912097729, -0.023798015829950926, 0.025399175018532155,
      0.027234775460433337, 0.0075191496157868331 };

    /* InitializeConditions for UnitDelay: '<S1>/UD' */
    Dev_1order_DW.UD_DSTATE = Dev_1order_P.DiscreteDerivative2_ICPrevScale;

    /* Start for MATLABSystem: '<Root>/Lowpass Filter3' */
    Dev_1order_DW.gobj_1.matlabCodegenIsDeleted = true;
    Dev_1order_DW.gobj_2.matlabCodegenIsDeleted = true;
    Dev_1order_DW.obj.matlabCodegenIsDeleted = true;
    iobj_0 = &Dev_1order_DW.gobj_2;
    Dev_1order_DW.obj.isInitialized = 0;
    Dev_1order_DW.obj.NumChannels = -1;
    Dev_1order_DW.obj.matlabCodegenIsDeleted = false;
    Dev_1order_DW.objisempty = true;
    Dev_1order_DW.obj.isSetupComplete = false;
    Dev_1order_DW.obj.isInitialized = 1;
    Dev_1order_DW.gobj_2.isInitialized = 0;

    /* System object Constructor function: dsp.FIRFilter */
    iobj_0->cSFunObject.P0_InitialStates = 0.0;
    for (i = 0; i < 16; i++) {
      iobj_0->cSFunObject.P1_Coefficients[i] = tmp[i];
    }

    Dev_1order_DW.gobj_2.matlabCodegenIsDeleted = false;
    Dev_1order_DW.obj.FilterObj = &Dev_1order_DW.gobj_2;
    Dev_1order_DW.obj.NumChannels = 1;
    Dev_1order_DW.obj.isSetupComplete = true;

    /* End of Start for MATLABSystem: '<Root>/Lowpass Filter3' */

    /* InitializeConditions for MATLABSystem: '<Root>/Lowpass Filter3' */
    if (Dev_1order_DW.obj.FilterObj->isInitialized == 1) {
      /* System object Initialization function: dsp.FIRFilter */
      for (i = 0; i < 15; i++) {
        Dev_1order_DW.obj.FilterObj->cSFunObject.W0_states[i] =
          Dev_1order_DW.obj.FilterObj->cSFunObject.P0_InitialStates;
      }
    }

    /* End of InitializeConditions for MATLABSystem: '<Root>/Lowpass Filter3' */
  }
}

/* Model terminate function */
void Dev_1orderModelClass::terminate()
{
  /* Terminate for MATLABSystem: '<Root>/Lowpass Filter3' */
  matlabCodegenHandle_matlabCod_e(&Dev_1order_DW.obj);
  matlabCodegenHandle_matlabCodeg(&Dev_1order_DW.gobj_2);
  matlabCodegenHandle_matlabCodeg(&Dev_1order_DW.gobj_1);
}

/* Constructor */
Dev_1orderModelClass::Dev_1orderModelClass():
  Dev_1order_DW()
  ,Dev_1order_U()
  ,Dev_1order_Y()
  ,Dev_1order_M()
{
  /* Currently there is no constructor body generated.*/
}

/* Destructor */
Dev_1orderModelClass::~Dev_1orderModelClass()
{
  /* Currently there is no destructor body generated.*/
}

/* Real-Time Model get method */
RT_MODEL_Dev_1order_T * Dev_1orderModelClass::getRTM()
{
  return (&Dev_1order_M);
}
