/*
 * IIRFilter_Lowpass.h
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

#ifndef RTW_HEADER_IIRFilter_Lowpass_h_
#define RTW_HEADER_IIRFilter_Lowpass_h_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "IIRFilter_Lowpass_types.h"

/* Shared type includes */
#include "multiword_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Block states (default storage) for system '<Root>' */
typedef struct {
  b_dspcodegen_FIRFilter_IIRFil_T gobj_1;/* '<Root>/Lowpass Filter2' */
  b_dspcodegen_FIRFilter_IIRFil_T gobj_2;/* '<Root>/Lowpass Filter2' */
  dsp_LowpassFilter_IIRFilter_L_T obj; /* '<Root>/Lowpass Filter2' */
  boolean_T objisempty;                /* '<Root>/Lowpass Filter2' */
  boolean_T isInitialized;             /* '<Root>/Lowpass Filter2' */
} DW_IIRFilter_Lowpass_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T In1;                          /* '<Root>/In1' */
} ExtU_IIRFilter_Lowpass_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T Out1;                         /* '<Root>/Out1' */
} ExtY_IIRFilter_Lowpass_T;

/* Real-time Model Data Structure */
struct tag_RTM_IIRFilter_Lowpass_T {
  const char_T *errorStatus;
};

/* Class declaration for model IIRFilter_Lowpass */
class IIRFilter_LowpassModelClass {
  /* public data and function members */
 public:
  /* model initialize function */
  void initialize();

  /* model step function */
  void step();

  /* model terminate function */
  void terminate();

  /* Constructor */
  IIRFilter_LowpassModelClass();

  /* Destructor */
  ~IIRFilter_LowpassModelClass();

  /* Root-level structure-based inputs set method */

  /* Root inports set method */
  void setExternalInputs(const ExtU_IIRFilter_Lowpass_T
    * pExtU_IIRFilter_Lowpass_T)
  {
    IIRFilter_Lowpass_U = *pExtU_IIRFilter_Lowpass_T;
  }

  /* Root-level structure-based outputs get method */

  /* Root outports get method */
  const ExtY_IIRFilter_Lowpass_T & getExternalOutputs() const
  {
    return IIRFilter_Lowpass_Y;
  }

  /* Real-Time Model get method */
  RT_MODEL_IIRFilter_Lowpass_T * getRTM();

  /* private data and function members */
 private:
  /* Block states */
  DW_IIRFilter_Lowpass_T IIRFilter_Lowpass_DW;

  /* External inputs */
  ExtU_IIRFilter_Lowpass_T IIRFilter_Lowpass_U;

  /* External outputs */
  ExtY_IIRFilter_Lowpass_T IIRFilter_Lowpass_Y;

  /* Real-Time Model */
  RT_MODEL_IIRFilter_Lowpass_T IIRFilter_Lowpass_M;

  /* private member function(s) for subsystem '<Root>'*/
  void IIRFilter_Lo_SystemCore_release(b_dspcodegen_FIRFilter_IIRFil_T *obj);
  void IIRF_LPHPFilterBase_releaseImpl(dsp_LowpassFilter_IIRFilter_L_T *obj);
  void IIRFi_SystemCore_releaseWrapper(dsp_LowpassFilter_IIRFilter_L_T *obj);
  void IIRFilter__SystemCore_release_a(dsp_LowpassFilter_IIRFilter_L_T *obj);
  void IIRFilter_L_SystemCore_delete_a(dsp_LowpassFilter_IIRFilter_L_T *obj);
  void matlabCodegenHandle_matlabCod_a(dsp_LowpassFilter_IIRFilter_L_T *obj);
  void IIRFilter_Low_SystemCore_delete(b_dspcodegen_FIRFilter_IIRFil_T *obj);
  void matlabCodegenHandle_matlabCodeg(b_dspcodegen_FIRFilter_IIRFil_T *obj);
};

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'IIRFilter_Lowpass'
 */
#endif                                 /* RTW_HEADER_IIRFilter_Lowpass_h_ */
