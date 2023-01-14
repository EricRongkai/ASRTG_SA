/*
 * Dev_1order.h
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

#ifndef RTW_HEADER_Dev_1order_h_
#define RTW_HEADER_Dev_1order_h_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "Dev_1order_types.h"

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
  b_dspcodegen_FIRFilter_Dev_1o_T gobj_1;/* '<Root>/Lowpass Filter3' */
  b_dspcodegen_FIRFilter_Dev_1o_T gobj_2;/* '<Root>/Lowpass Filter3' */
  dsp_LowpassFilter_Dev_1order_T obj;  /* '<Root>/Lowpass Filter3' */
  real_T UD_DSTATE;                    /* '<S1>/UD' */
  boolean_T objisempty;                /* '<Root>/Lowpass Filter3' */
  boolean_T isInitialized;             /* '<Root>/Lowpass Filter3' */
} DW_Dev_1order_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T In1;                          /* '<Root>/In1' */
} ExtU_Dev_1order_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T Out1;                         /* '<Root>/Out1' */
} ExtY_Dev_1order_T;

/* Parameters (default storage) */
struct P_Dev_1order_T_ {
  real_T DiscreteDerivative2_ICPrevScale;
                              /* Mask Parameter: DiscreteDerivative2_ICPrevScale
                               * Referenced by: '<S1>/UD'
                               */
  real_T TSamp_WtEt;                   /* Computed Parameter: TSamp_WtEt
                                        * Referenced by: '<S1>/TSamp'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_Dev_1order_T {
  const char_T *errorStatus;
};

/* Class declaration for model Dev_1order */
class Dev_1orderModelClass {
  /* public data and function members */
 public:
  /* model initialize function */
  void initialize();

  /* model step function */
  void step();

  /* model terminate function */
  void terminate();

  /* Constructor */
  Dev_1orderModelClass();

  /* Destructor */
  ~Dev_1orderModelClass();

  /* Root-level structure-based inputs set method */

  /* Root inports set method */
  void setExternalInputs(const ExtU_Dev_1order_T* pExtU_Dev_1order_T)
  {
    Dev_1order_U = *pExtU_Dev_1order_T;
  }

  /* Root-level structure-based outputs get method */

  /* Root outports get method */
  const ExtY_Dev_1order_T & getExternalOutputs() const
  {
    return Dev_1order_Y;
  }

  /* Real-Time Model get method */
  RT_MODEL_Dev_1order_T * getRTM();

  /* private data and function members */
 private:
  /* Tunable parameters */
  static P_Dev_1order_T Dev_1order_P;

  /* Block states */
  DW_Dev_1order_T Dev_1order_DW;

  /* External inputs */
  ExtU_Dev_1order_T Dev_1order_U;

  /* External outputs */
  ExtY_Dev_1order_T Dev_1order_Y;

  /* Real-Time Model */
  RT_MODEL_Dev_1order_T Dev_1order_M;

  /* private member function(s) for subsystem '<Root>'*/
  void Dev_1order_SystemCore_release(b_dspcodegen_FIRFilter_Dev_1o_T *obj);
  void Dev__LPHPFilterBase_releaseImpl(dsp_LowpassFilter_Dev_1order_T *obj);
  void Dev_1_SystemCore_releaseWrapper(dsp_LowpassFilter_Dev_1order_T *obj);
  void Dev_1order_SystemCore_release_e(dsp_LowpassFilter_Dev_1order_T *obj);
  void Dev_1order_SystemCore_delete_e(dsp_LowpassFilter_Dev_1order_T *obj);
  void matlabCodegenHandle_matlabCod_e(dsp_LowpassFilter_Dev_1order_T *obj);
  void Dev_1order_SystemCore_delete(b_dspcodegen_FIRFilter_Dev_1o_T *obj);
  void matlabCodegenHandle_matlabCodeg(b_dspcodegen_FIRFilter_Dev_1o_T *obj);
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
 * '<Root>' : 'Dev_1order'
 * '<S1>'   : 'Dev_1order/Discrete Derivative2'
 */
#endif                                 /* RTW_HEADER_Dev_1order_h_ */
