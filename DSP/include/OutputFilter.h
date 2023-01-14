/*
 * OutputFilter.h
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

#ifndef RTW_HEADER_OutputFilter_h_
#define RTW_HEADER_OutputFilter_h_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "OutputFilter_types.h"

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
  b_dspcodegen_BiquadFilter_Out_T gobj_1;/* '<Root>/Lowpass Filter' */
  b_dspcodegen_BiquadFilter_Out_T gobj_2;/* '<Root>/Lowpass Filter' */
  dsp_LowpassFilter_OutputFilte_T obj; /* '<Root>/Lowpass Filter' */
  boolean_T objisempty;                /* '<Root>/Lowpass Filter' */
  boolean_T isInitialized;             /* '<Root>/Lowpass Filter' */
} DW_OutputFilter_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T In1;                          /* '<Root>/In1' */
} ExtU_OutputFilter_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T Out1;                         /* '<Root>/Out1' */
} ExtY_OutputFilter_T;

/* Real-time Model Data Structure */
struct tag_RTM_OutputFilter_T {
  const char_T *errorStatus;
};

/* Class declaration for model OutputFilter */
class OutputFilterModelClass {
  /* public data and function members */
 public:
  /* model initialize function */
  void initialize();

  /* model step function */
  void step();

  /* model terminate function */
  void terminate();

  /* Constructor */
  OutputFilterModelClass();

  /* Destructor */
  ~OutputFilterModelClass();

  /* Root-level structure-based inputs set method */

  /* Root inports set method */
  void setExternalInputs(const ExtU_OutputFilter_T* pExtU_OutputFilter_T)
  {
    OutputFilter_U = *pExtU_OutputFilter_T;
  }

  /* Root-level structure-based outputs get method */

  /* Root outports get method */
  const ExtY_OutputFilter_T & getExternalOutputs() const
  {
    return OutputFilter_Y;
  }

  /* Real-Time Model get method */
  RT_MODEL_OutputFilter_T * getRTM();

  /* private data and function members */
 private:
  /* Block states */
  DW_OutputFilter_T OutputFilter_DW;

  /* External inputs */
  ExtU_OutputFilter_T OutputFilter_U;

  /* External outputs */
  ExtY_OutputFilter_T OutputFilter_Y;

  /* Real-Time Model */
  RT_MODEL_OutputFilter_T OutputFilter_M;

  /* private member function(s) for subsystem '<Root>'*/
  real_T OutputF_BiquadFilter_outputImpl(b_dspcodegen_BiquadFilter_Out_T *obj,
    real_T varargin_1);
  void OutputFilter_SystemCore_release(b_dspcodegen_BiquadFilter_Out_T *obj);
  void Outp_LPHPFilterBase_releaseImpl(dsp_LowpassFilter_OutputFilte_T *obj);
  void Outpu_SystemCore_releaseWrapper(dsp_LowpassFilter_OutputFilte_T *obj);
  void OutputFilt_SystemCore_release_g(dsp_LowpassFilter_OutputFilte_T *obj);
  void OutputFilte_SystemCore_delete_g(dsp_LowpassFilter_OutputFilte_T *obj);
  void matlabCodegenHandle_matlabCod_g(dsp_LowpassFilter_OutputFilte_T *obj);
  void OutputFilter_SystemCore_delete(b_dspcodegen_BiquadFilter_Out_T *obj);
  void matlabCodegenHandle_matlabCodeg(b_dspcodegen_BiquadFilter_Out_T *obj);
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
 * '<Root>' : 'OutputFilter'
 */
#endif                                 /* RTW_HEADER_OutputFilter_h_ */
