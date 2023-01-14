/*
 * OmegaFilter.cpp
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "OmegaFilter".
 *
 * Model version              : 1.3
 * Simulink Coder version : 9.3 (R2020a) 18-Nov-2019
 * C++ source code generated on : Tue Jun 21 20:18:56 2022
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "OmegaFilter.h"
#include "OmegaFilter_private.h"

void OmegaFilterModelClass::OmegaFilter_SystemCore_release
  (b_dspcodegen_FIRFilter_OmegaF_T *obj)
{
  if (obj->isInitialized == 1) {
    obj->isInitialized = 2;
  }
}

void OmegaFilterModelClass::Omeg_LPHPFilterBase_releaseImpl
  (dsp_LowpassFilter_OmegaFilter_T *obj)
{
  OmegaFilter_SystemCore_release(obj->FilterObj);
  obj->NumChannels = -1;
}

void OmegaFilterModelClass::Omega_SystemCore_releaseWrapper
  (dsp_LowpassFilter_OmegaFilter_T *obj)
{
  if (obj->isSetupComplete) {
    Omeg_LPHPFilterBase_releaseImpl(obj);
  }
}

void OmegaFilterModelClass::OmegaFilte_SystemCore_release_j
  (dsp_LowpassFilter_OmegaFilter_T *obj)
{
  if (obj->isInitialized == 1) {
    Omega_SystemCore_releaseWrapper(obj);
  }
}

void OmegaFilterModelClass::OmegaFilter_SystemCore_delete_j
  (dsp_LowpassFilter_OmegaFilter_T *obj)
{
  OmegaFilte_SystemCore_release_j(obj);
}

void OmegaFilterModelClass::matlabCodegenHandle_matlabCod_j
  (dsp_LowpassFilter_OmegaFilter_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    OmegaFilter_SystemCore_delete_j(obj);
  }
}

void OmegaFilterModelClass::OmegaFilter_SystemCore_delete
  (b_dspcodegen_FIRFilter_OmegaF_T *obj)
{
  OmegaFilter_SystemCore_release(obj);
}

void OmegaFilterModelClass::matlabCodegenHandle_matlabCodeg
  (b_dspcodegen_FIRFilter_OmegaF_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    OmegaFilter_SystemCore_delete(obj);
  }
}

/* Model step function */
void OmegaFilterModelClass::step()
{
  b_dsp_FIRFilter_0_OmegaFilter_T *obj;
  real_T acc1;
  real_T acc2;
  int32_T j;

  /* MATLABSystem: '<Root>/Lowpass Filter' incorporates:
   *  Inport: '<Root>/In1'
   */
  if (OmegaFilter_DW.obj.FilterObj->isInitialized != 1) {
    OmegaFilter_DW.obj.FilterObj->isSetupComplete = false;
    OmegaFilter_DW.obj.FilterObj->isInitialized = 1;
    OmegaFilter_DW.obj.FilterObj->isSetupComplete = true;

    /* System object Initialization function: dsp.FIRFilter */
    for (j = 0; j < 56; j++) {
      OmegaFilter_DW.obj.FilterObj->cSFunObject.W0_states[j] =
        OmegaFilter_DW.obj.FilterObj->cSFunObject.P0_InitialStates;
    }
  }

  obj = &OmegaFilter_DW.obj.FilterObj->cSFunObject;

  /* System object Outputs function: dsp.FIRFilter */
  /* Consume delay line and beginning of input samples */
  acc2 = OmegaFilter_U.In1 *
    OmegaFilter_DW.obj.FilterObj->cSFunObject.P1_Coefficients[0];
  acc1 = acc2;
  for (j = 0; j < 56; j++) {
    acc2 = obj->P1_Coefficients[j + 1] * obj->W0_states[j];
    acc1 += acc2;
  }

  /* Update delay line for next frame */
  for (j = 54; j >= 0; j--) {
    obj->W0_states[j + 1] = obj->W0_states[j];
  }

  OmegaFilter_DW.obj.FilterObj->cSFunObject.W0_states[0] = OmegaFilter_U.In1;

  /* Outport: '<Root>/Out1' incorporates:
   *  MATLABSystem: '<Root>/Lowpass Filter'
   */
  OmegaFilter_Y.Out1 = acc1;
}

/* Model initialize function */
void OmegaFilterModelClass::initialize()
{
  {
    b_dspcodegen_FIRFilter_OmegaF_T *iobj_0;
    int32_T i;
    static const real_T tmp[57] = { 0.0009555140472706585, 0.0013172048822847372,
      0.0020212881432609821, 0.0027557698393613161, 0.0033846892062883802,
      0.0037360788696529377, 0.0036193623904714652, 0.00285620158045201,
      0.0013146969714213919, -0.001052192685578758, -0.0041752848498438962,
      -0.0078447940608012811, -0.011704783261450314, -0.015266162679272071,
      -0.017941236601250545, -0.019102641257707706, -0.018149780656043463,
      -0.014592307373523138, -0.0081242344282707567, 0.0013139109280307633,
      0.013489907329465213, 0.027873758552753498, 0.0436617366463483,
      0.059835330749837871, 0.075249211489567064, 0.088742382134100017,
      0.0992521400104225, 0.10592658958996702, 0.10821492394145554,
      0.10592658958996702, 0.0992521400104225, 0.088742382134100017,
      0.075249211489567064, 0.059835330749837871, 0.0436617366463483,
      0.027873758552753498, 0.013489907329465213, 0.0013139109280307633,
      -0.0081242344282707567, -0.014592307373523138, -0.018149780656043463,
      -0.019102641257707706, -0.017941236601250545, -0.015266162679272071,
      -0.011704783261450314, -0.0078447940608012811, -0.0041752848498438962,
      -0.001052192685578758, 0.0013146969714213919, 0.00285620158045201,
      0.0036193623904714652, 0.0037360788696529377, 0.0033846892062883802,
      0.0027557698393613161, 0.0020212881432609821, 0.0013172048822847372,
      0.0009555140472706585 };

    /* Start for MATLABSystem: '<Root>/Lowpass Filter' */
    OmegaFilter_DW.gobj_1.matlabCodegenIsDeleted = true;
    OmegaFilter_DW.gobj_2.matlabCodegenIsDeleted = true;
    OmegaFilter_DW.obj.matlabCodegenIsDeleted = true;
    iobj_0 = &OmegaFilter_DW.gobj_2;
    OmegaFilter_DW.obj.isInitialized = 0;
    OmegaFilter_DW.obj.NumChannels = -1;
    OmegaFilter_DW.obj.matlabCodegenIsDeleted = false;
    OmegaFilter_DW.objisempty = true;
    OmegaFilter_DW.obj.isSetupComplete = false;
    OmegaFilter_DW.obj.isInitialized = 1;
    OmegaFilter_DW.gobj_2.isInitialized = 0;

    /* System object Constructor function: dsp.FIRFilter */
    iobj_0->cSFunObject.P0_InitialStates = 0.0;
    for (i = 0; i < 57; i++) {
      iobj_0->cSFunObject.P1_Coefficients[i] = tmp[i];
    }

    OmegaFilter_DW.gobj_2.matlabCodegenIsDeleted = false;
    OmegaFilter_DW.obj.FilterObj = &OmegaFilter_DW.gobj_2;
    OmegaFilter_DW.obj.NumChannels = 1;
    OmegaFilter_DW.obj.isSetupComplete = true;

    /* End of Start for MATLABSystem: '<Root>/Lowpass Filter' */

    /* InitializeConditions for MATLABSystem: '<Root>/Lowpass Filter' */
    if (OmegaFilter_DW.obj.FilterObj->isInitialized == 1) {
      /* System object Initialization function: dsp.FIRFilter */
      for (i = 0; i < 56; i++) {
        OmegaFilter_DW.obj.FilterObj->cSFunObject.W0_states[i] =
          OmegaFilter_DW.obj.FilterObj->cSFunObject.P0_InitialStates;
      }
    }

    /* End of InitializeConditions for MATLABSystem: '<Root>/Lowpass Filter' */
  }
}

/* Model terminate function */
void OmegaFilterModelClass::terminate()
{
  /* Terminate for MATLABSystem: '<Root>/Lowpass Filter' */
  matlabCodegenHandle_matlabCod_j(&OmegaFilter_DW.obj);
  matlabCodegenHandle_matlabCodeg(&OmegaFilter_DW.gobj_2);
  matlabCodegenHandle_matlabCodeg(&OmegaFilter_DW.gobj_1);
}

/* Constructor */
OmegaFilterModelClass::OmegaFilterModelClass():
  OmegaFilter_DW()
  ,OmegaFilter_U()
  ,OmegaFilter_Y()
  ,OmegaFilter_M()
{
  /* Currently there is no constructor body generated.*/
}

/* Destructor */
OmegaFilterModelClass::~OmegaFilterModelClass()
{
  /* Currently there is no destructor body generated.*/
}

/* Real-Time Model get method */
RT_MODEL_OmegaFilter_T * OmegaFilterModelClass::getRTM()
{
  return (&OmegaFilter_M);
}
