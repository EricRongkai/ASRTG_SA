/*
 * IIRFilter_Bandpass.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "IIRFilter_Bandpass".
 *
 * Model version              : 1.3
 * Simulink Coder version : 9.3 (R2020a) 18-Nov-2019
 * C++ source code generated on : Tue Jun  7 22:05:18 2022
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_IIRFilter_Bandpass_h_
#define RTW_HEADER_IIRFilter_Bandpass_h_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "IIRFilter_Bandpass_types.h"

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
  real_T delay155_DSTATE;              /* '<S8>/delay1(5)5' */
  real_T delay166_DSTATE;              /* '<S8>/delay1(6)6' */
  real_T delay244_DSTATE;              /* '<S8>/delay2(4)4' */
  real_T delay133_DSTATE;              /* '<S8>/delay1(3)3' */
  real_T delay144_DSTATE;              /* '<S8>/delay1(4)4' */
  real_T delay222_DSTATE;              /* '<S8>/delay2(2)2' */
  real_T delay111_DSTATE;              /* '<S8>/delay1(1)1' */
  real_T delay122_DSTATE;              /* '<S8>/delay1(2)2' */
  real_T delay211_DSTATE;              /* '<S8>/delay2(1)1' */
  real_T delay233_DSTATE;              /* '<S8>/delay2(3)3' */
  real_T delay255_DSTATE;              /* '<S8>/delay2(5)5' */
  real_T delay266_DSTATE;              /* '<S8>/delay2(6)6' */
  real_T delay244_DSTATE_e;            /* '<S6>/delay2(4)4' */
  real_T delay133_DSTATE_h;            /* '<S6>/delay1(3)3' */
  real_T delay144_DSTATE_h;            /* '<S6>/delay1(4)4' */
  real_T delay222_DSTATE_g;            /* '<S6>/delay2(2)2' */
  real_T delay111_DSTATE_p;            /* '<S6>/delay1(1)1' */
  real_T delay122_DSTATE_h;            /* '<S6>/delay1(2)2' */
  real_T delay211_DSTATE_b;            /* '<S6>/delay2(1)1' */
  real_T delay233_DSTATE_b;            /* '<S6>/delay2(3)3' */
  real_T delay255_DSTATE_m;            /* '<S6>/delay2(5)5' */
  real_T delay155_DSTATE_l;            /* '<S6>/delay1(5)5' */
} DW_IIRFilter_Bandpass_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T In1;                          /* '<Root>/In1' */
} ExtU_IIRFilter_Bandpass_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T Out1;                         /* '<Root>/Out1' */
} ExtY_IIRFilter_Bandpass_T;

/* Parameters (default storage) */
struct P_IIRFilter_Bandpass_T_ {
  real_T delay155_InitialCondition;    /* Expression: 0
                                        * Referenced by: '<S8>/delay1(5)5'
                                        */
  real_T delay166_InitialCondition;    /* Expression: 0
                                        * Referenced by: '<S8>/delay1(6)6'
                                        */
  real_T gain255_Gain;                 /* Expression: -1.93215586845229925
                                        * Referenced by: '<S8>/gain2(5)(5)'
                                        */
  real_T delay244_InitialCondition;    /* Expression: 0
                                        * Referenced by: '<S8>/delay2(4)4'
                                        */
  real_T delay133_InitialCondition;    /* Expression: 0
                                        * Referenced by: '<S8>/delay1(3)3'
                                        */
  real_T delay144_InitialCondition;    /* Expression: 0
                                        * Referenced by: '<S8>/delay1(4)4'
                                        */
  real_T gain233_Gain;                 /* Expression: -1.94532811490731139
                                        * Referenced by: '<S8>/gain2(3)(3)'
                                        */
  real_T delay222_InitialCondition;    /* Expression: 0
                                        * Referenced by: '<S8>/delay2(2)2'
                                        */
  real_T delay111_InitialCondition;    /* Expression: 0
                                        * Referenced by: '<S8>/delay1(1)1'
                                        */
  real_T delay122_InitialCondition;    /* Expression: 0
                                        * Referenced by: '<S8>/delay1(2)2'
                                        */
  real_T gain211_Gain;                 /* Expression: -1.99834441701264121
                                        * Referenced by: '<S8>/gain2(1)(1)'
                                        */
  real_T g1_Gain;                      /* Expression: -1
                                        * Referenced by: '<S7>/g(1)'
                                        */
  real_T gain111_Gain;                 /* Expression: 0.999332407214604479
                                        * Referenced by: '<S8>/gain1(1)(1)'
                                        */
  real_T delay211_InitialCondition;    /* Expression: 0
                                        * Referenced by: '<S8>/delay2(1)1'
                                        */
  real_T delay233_InitialCondition;    /* Expression: 0
                                        * Referenced by: '<S8>/delay2(3)3'
                                        */
  real_T gain122_Gain;                 /* Expression: 0.992858091128718367
                                        * Referenced by: '<S8>/gain1(2)(2)'
                                        */
  real_T gain222_Gain;                 /* Expression: -1.99143125926165876
                                        * Referenced by: '<S8>/gain2(2)(2)'
                                        */
  real_T gain133_Gain;                 /* Expression: 0.953064633048068099
                                        * Referenced by: '<S8>/gain1(3)(3)'
                                        */
  real_T delay255_InitialCondition;    /* Expression: 0
                                        * Referenced by: '<S8>/delay2(5)5'
                                        */
  real_T gain144_Gain;                 /* Expression: 0.961455728450977487
                                        * Referenced by: '<S8>/gain1(4)(4)'
                                        */
  real_T gain244_Gain;                 /* Expression: -1.91878241495516555
                                        * Referenced by: '<S8>/gain2(4)(4)'
                                        */
  real_T delay266_InitialCondition;    /* Expression: 0
                                        * Referenced by: '<S8>/delay2(6)6'
                                        */
  real_T gain155_Gain;                 /* Expression: 0.99473415957977207
                                        * Referenced by: '<S8>/gain1(5)(5)'
                                        */
  real_T delay244_InitialCondition_f;  /* Expression: 0
                                        * Referenced by: '<S6>/delay2(4)4'
                                        */
  real_T delay133_InitialCondition_j;  /* Expression: 0
                                        * Referenced by: '<S6>/delay1(3)3'
                                        */
  real_T delay144_InitialCondition_f;  /* Expression: 0
                                        * Referenced by: '<S6>/delay1(4)4'
                                        */
  real_T gain233_Gain_c;               /* Expression: -1.91936650153047506
                                        * Referenced by: '<S6>/gain2(3)(3)'
                                        */
  real_T delay222_InitialCondition_l;  /* Expression: 0
                                        * Referenced by: '<S6>/delay2(2)2'
                                        */
  real_T delay111_InitialCondition_n;  /* Expression: 0
                                        * Referenced by: '<S6>/delay1(1)1'
                                        */
  real_T delay122_InitialCondition_c;  /* Expression: 0
                                        * Referenced by: '<S6>/delay1(2)2'
                                        */
  real_T gain211_Gain_f;               /* Expression: -1.9962947849448327
                                        * Referenced by: '<S6>/gain2(1)(1)'
                                        */
  real_T gain111_Gain_j;               /* Expression: 0.997385360058028358
                                        * Referenced by: '<S6>/gain1(1)(1)'
                                        */
  real_T delay211_InitialCondition_n;  /* Expression: 0
                                        * Referenced by: '<S6>/delay2(1)1'
                                        */
  real_T delay233_InitialCondition_p;  /* Expression: 0
                                        * Referenced by: '<S6>/delay2(3)3'
                                        */
  real_T gain122_Gain_j;               /* Expression: 0.980482573936554025
                                        * Referenced by: '<S6>/gain1(2)(2)'
                                        */
  real_T gain222_Gain_d;               /* Expression: -1.97788083200610565
                                        * Referenced by: '<S6>/gain2(2)(2)'
                                        */
  real_T gain133_Gain_c;               /* Expression: 0.942506822918530163
                                        * Referenced by: '<S6>/gain1(3)(3)'
                                        */
  real_T delay255_InitialCondition_o;  /* Expression: 0
                                        * Referenced by: '<S6>/delay2(5)5'
                                        */
  real_T gain144_Gain_c;               /* Expression: 0.981413290893906387
                                        * Referenced by: '<S6>/gain1(4)(4)'
                                        */
  real_T delay155_InitialCondition_i;  /* Expression: 0
                                        * Referenced by: '<S6>/delay1(5)5'
                                        */
  real_T gain244_Gain_o;               /* Expression: -1.92507238215036458
                                        * Referenced by: '<S6>/gain2(4)(4)'
                                        */
  real_T g1_Gain_b;                    /* Expression: 0.5
                                        * Referenced by: '<S4>/g(1)'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_IIRFilter_Bandpass_T {
  const char_T *errorStatus;
};

/* Class declaration for model IIRFilter_Bandpass */
class IIRFilter_BandpassModelClass {
  /* public data and function members */
 public:
  /* model initialize function */
  void initialize();

  /* model step function */
  void step();

  /* model terminate function */
  void terminate();

  /* Constructor */
  IIRFilter_BandpassModelClass();

  /* Destructor */
  ~IIRFilter_BandpassModelClass();

  /* Root-level structure-based inputs set method */

  /* Root inports set method */
  void setExternalInputs(const ExtU_IIRFilter_Bandpass_T
    * pExtU_IIRFilter_Bandpass_T)
  {
    IIRFilter_Bandpass_U = *pExtU_IIRFilter_Bandpass_T;
  }

  /* Root-level structure-based outputs get method */

  /* Root outports get method */
  const ExtY_IIRFilter_Bandpass_T & getExternalOutputs() const
  {
    return IIRFilter_Bandpass_Y;
  }

  /* Real-Time Model get method */
  RT_MODEL_IIRFilter_Bandpass_T * getRTM();

  /* private data and function members */
 private:
  /* Tunable parameters */
  static P_IIRFilter_Bandpass_T IIRFilter_Bandpass_P;

  /* Block states */
  DW_IIRFilter_Bandpass_T IIRFilter_Bandpass_DW;

  /* External inputs */
  ExtU_IIRFilter_Bandpass_T IIRFilter_Bandpass_U;

  /* External outputs */
  ExtY_IIRFilter_Bandpass_T IIRFilter_Bandpass_Y;

  /* Real-Time Model */
  RT_MODEL_IIRFilter_Bandpass_T IIRFilter_Bandpass_M;
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
 * '<Root>' : 'IIRFilter_Bandpass'
 * '<S1>'   : 'IIRFilter_Bandpass/Bandpass Filter1'
 * '<S2>'   : 'IIRFilter_Bandpass/Bandpass Filter1/Generated Filter Block'
 * '<S3>'   : 'IIRFilter_Bandpass/Bandpass Filter1/Generated Filter Block/Stage1'
 * '<S4>'   : 'IIRFilter_Bandpass/Bandpass Filter1/Generated Filter Block/Stage2'
 * '<S5>'   : 'IIRFilter_Bandpass/Bandpass Filter1/Generated Filter Block/Stage1/Stage1'
 * '<S6>'   : 'IIRFilter_Bandpass/Bandpass Filter1/Generated Filter Block/Stage1/Stage2'
 * '<S7>'   : 'IIRFilter_Bandpass/Bandpass Filter1/Generated Filter Block/Stage1/Stage1/Stage1'
 * '<S8>'   : 'IIRFilter_Bandpass/Bandpass Filter1/Generated Filter Block/Stage1/Stage1/Stage2'
 */
#endif                                 /* RTW_HEADER_IIRFilter_Bandpass_h_ */
