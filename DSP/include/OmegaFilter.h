/*
 * OmegaFilter.h
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

#ifndef RTW_HEADER_OmegaFilter_h_
#define RTW_HEADER_OmegaFilter_h_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "OmegaFilter_types.h"

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
  b_dspcodegen_FIRFilter_OmegaF_T gobj_1;/* '<Root>/Lowpass Filter' */
  b_dspcodegen_FIRFilter_OmegaF_T gobj_2;/* '<Root>/Lowpass Filter' */
  dsp_LowpassFilter_OmegaFilter_T obj; /* '<Root>/Lowpass Filter' */
  boolean_T objisempty;                /* '<Root>/Lowpass Filter' */
  boolean_T isInitialized;             /* '<Root>/Lowpass Filter' */
} DW_OmegaFilter_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T In1;                          /* '<Root>/In1' */
} ExtU_OmegaFilter_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T Out1;                         /* '<Root>/Out1' */
} ExtY_OmegaFilter_T;

/* Real-time Model Data Structure */
struct tag_RTM_OmegaFilter_T {
  const char_T *errorStatus;
};

/* Class declaration for model OmegaFilter */
class OmegaFilterModelClass {
  /* public data and function members */
 public:
  /* model initialize function */
  void initialize();

  /* model step function */
  void step();

  /* model terminate function */
  void terminate();

  /* Constructor */
  OmegaFilterModelClass();

  /* Destructor */
  ~OmegaFilterModelClass();

  /* Root-level structure-based inputs set method */

  /* Root inports set method */
  void setExternalInputs(const ExtU_OmegaFilter_T* pExtU_OmegaFilter_T)
  {
    OmegaFilter_U = *pExtU_OmegaFilter_T;
  }

  /* Root-level structure-based outputs get method */

  /* Root outports get method */
  const ExtY_OmegaFilter_T & getExternalOutputs() const
  {
    return OmegaFilter_Y;
  }

  /* Real-Time Model get method */
  RT_MODEL_OmegaFilter_T * getRTM();

  /* private data and function members */
 private:
  /* Block states */
  DW_OmegaFilter_T OmegaFilter_DW;

  /* External inputs */
  ExtU_OmegaFilter_T OmegaFilter_U;

  /* External outputs */
  ExtY_OmegaFilter_T OmegaFilter_Y;

  /* Real-Time Model */
  RT_MODEL_OmegaFilter_T OmegaFilter_M;

  /* private member function(s) for subsystem '<Root>'*/
  void OmegaFilter_SystemCore_release(b_dspcodegen_FIRFilter_OmegaF_T *obj);
  void Omeg_LPHPFilterBase_releaseImpl(dsp_LowpassFilter_OmegaFilter_T *obj);
  void Omega_SystemCore_releaseWrapper(dsp_LowpassFilter_OmegaFilter_T *obj);
  void OmegaFilte_SystemCore_release_j(dsp_LowpassFilter_OmegaFilter_T *obj);
  void OmegaFilter_SystemCore_delete_j(dsp_LowpassFilter_OmegaFilter_T *obj);
  void matlabCodegenHandle_matlabCod_j(dsp_LowpassFilter_OmegaFilter_T *obj);
  void OmegaFilter_SystemCore_delete(b_dspcodegen_FIRFilter_OmegaF_T *obj);
  void matlabCodegenHandle_matlabCodeg(b_dspcodegen_FIRFilter_OmegaF_T *obj);
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
 * '<Root>' : 'OmegaFilter'
 */
#endif                                 /* RTW_HEADER_OmegaFilter_h_ */
