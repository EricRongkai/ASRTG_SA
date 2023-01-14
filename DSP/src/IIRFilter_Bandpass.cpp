/*
 * IIRFilter_Bandpass.cpp
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

#include "IIRFilter_Bandpass.h"
#include "IIRFilter_Bandpass_private.h"

/* Model step function */
void IIRFilter_BandpassModelClass::step()
{
  real_T rtb_delay155;
  real_T rtb_delay166;
  real_T rtb_delay133;
  real_T rtb_delay111;
  real_T rtb_g1;
  real_T rtb_numsum211;
  real_T rtb_numsum222;
  real_T rtb_numsum233;
  real_T rtb_numsum244;
  real_T rtb_delay133_d;
  real_T rtb_delay111_i;
  real_T rtb_numsum211_h;
  real_T rtb_numsum222_h;
  real_T rtb_numsum233_p;
  real_T rtb_numsum255;
  real_T rtb_numsum244_j;

  /* Delay: '<S8>/delay1(5)5' */
  rtb_delay155 = IIRFilter_Bandpass_DW.delay155_DSTATE;

  /* Delay: '<S8>/delay1(6)6' */
  rtb_delay166 = IIRFilter_Bandpass_DW.delay166_DSTATE;

  /* Delay: '<S8>/delay1(3)3' */
  rtb_delay133 = IIRFilter_Bandpass_DW.delay133_DSTATE;

  /* Delay: '<S8>/delay1(1)1' */
  rtb_delay111 = IIRFilter_Bandpass_DW.delay111_DSTATE;

  /* Gain: '<S7>/g(1)' incorporates:
   *  Inport: '<Root>/In1'
   */
  rtb_g1 = IIRFilter_Bandpass_P.g1_Gain * IIRFilter_Bandpass_U.In1;

  /* Sum: '<S8>/numsum2(1)1' incorporates:
   *  Delay: '<S8>/delay1(1)1'
   *  Delay: '<S8>/delay1(2)2'
   *  Delay: '<S8>/delay2(1)1'
   *  Delay: '<S8>/delay2(2)2'
   *  Gain: '<S8>/gain1(1)(1)'
   *  Gain: '<S8>/gain2(1)(1)'
   *  Sum: '<S8>/densum1(1)1'
   *  Sum: '<S8>/densum2(1)1'
   *  Sum: '<S8>/numsum1(1)1'
   */
  rtb_numsum211 = ((rtb_g1 - IIRFilter_Bandpass_DW.delay222_DSTATE) *
                   IIRFilter_Bandpass_P.gain111_Gain +
                   IIRFilter_Bandpass_DW.delay211_DSTATE) +
    (IIRFilter_Bandpass_DW.delay111_DSTATE -
     IIRFilter_Bandpass_DW.delay122_DSTATE) * IIRFilter_Bandpass_P.gain211_Gain;

  /* Sum: '<S8>/numsum2(2)2' incorporates:
   *  Delay: '<S8>/delay1(2)2'
   *  Delay: '<S8>/delay1(3)3'
   *  Delay: '<S8>/delay2(2)2'
   *  Delay: '<S8>/delay2(3)3'
   *  Gain: '<S8>/gain1(2)(2)'
   *  Gain: '<S8>/gain2(2)(2)'
   *  Sum: '<S8>/densum1(2)2'
   *  Sum: '<S8>/densum2(2)2'
   *  Sum: '<S8>/numsum1(2)2'
   */
  rtb_numsum222 = ((rtb_numsum211 - IIRFilter_Bandpass_DW.delay233_DSTATE) *
                   IIRFilter_Bandpass_P.gain122_Gain +
                   IIRFilter_Bandpass_DW.delay222_DSTATE) +
    (IIRFilter_Bandpass_DW.delay122_DSTATE -
     IIRFilter_Bandpass_DW.delay133_DSTATE) * IIRFilter_Bandpass_P.gain222_Gain;

  /* Sum: '<S8>/numsum2(3)3' incorporates:
   *  Delay: '<S8>/delay1(3)3'
   *  Delay: '<S8>/delay1(4)4'
   *  Delay: '<S8>/delay2(3)3'
   *  Delay: '<S8>/delay2(4)4'
   *  Gain: '<S8>/gain1(3)(3)'
   *  Gain: '<S8>/gain2(3)(3)'
   *  Sum: '<S8>/densum1(3)3'
   *  Sum: '<S8>/densum2(3)3'
   *  Sum: '<S8>/numsum1(3)3'
   */
  rtb_numsum233 = ((rtb_numsum222 - IIRFilter_Bandpass_DW.delay244_DSTATE) *
                   IIRFilter_Bandpass_P.gain133_Gain +
                   IIRFilter_Bandpass_DW.delay233_DSTATE) +
    (IIRFilter_Bandpass_DW.delay133_DSTATE -
     IIRFilter_Bandpass_DW.delay144_DSTATE) * IIRFilter_Bandpass_P.gain233_Gain;

  /* Sum: '<S8>/numsum2(4)4' incorporates:
   *  Delay: '<S8>/delay1(4)4'
   *  Delay: '<S8>/delay1(5)5'
   *  Delay: '<S8>/delay2(4)4'
   *  Delay: '<S8>/delay2(5)5'
   *  Gain: '<S8>/gain1(4)(4)'
   *  Gain: '<S8>/gain2(4)(4)'
   *  Sum: '<S8>/densum1(4)4'
   *  Sum: '<S8>/densum2(4)4'
   *  Sum: '<S8>/numsum1(4)4'
   */
  rtb_numsum244 = ((rtb_numsum233 - IIRFilter_Bandpass_DW.delay255_DSTATE) *
                   IIRFilter_Bandpass_P.gain144_Gain +
                   IIRFilter_Bandpass_DW.delay244_DSTATE) +
    (IIRFilter_Bandpass_DW.delay144_DSTATE -
     IIRFilter_Bandpass_DW.delay155_DSTATE) * IIRFilter_Bandpass_P.gain244_Gain;

  /* Sum: '<S8>/numsum2(5)5' incorporates:
   *  Delay: '<S8>/delay1(5)5'
   *  Delay: '<S8>/delay1(6)6'
   *  Delay: '<S8>/delay2(5)5'
   *  Delay: '<S8>/delay2(6)6'
   *  Gain: '<S8>/gain1(5)(5)'
   *  Gain: '<S8>/gain2(5)(5)'
   *  Sum: '<S8>/densum1(5)5'
   *  Sum: '<S8>/densum2(5)5'
   *  Sum: '<S8>/numsum1(5)5'
   */
  rtb_numsum255 = ((rtb_numsum244 - IIRFilter_Bandpass_DW.delay266_DSTATE) *
                   IIRFilter_Bandpass_P.gain155_Gain +
                   IIRFilter_Bandpass_DW.delay255_DSTATE) +
    (IIRFilter_Bandpass_DW.delay155_DSTATE -
     IIRFilter_Bandpass_DW.delay166_DSTATE) * IIRFilter_Bandpass_P.gain255_Gain;

  /* Delay: '<S6>/delay1(3)3' */
  rtb_delay133_d = IIRFilter_Bandpass_DW.delay133_DSTATE_h;

  /* Delay: '<S6>/delay1(1)1' */
  rtb_delay111_i = IIRFilter_Bandpass_DW.delay111_DSTATE_p;

  /* Sum: '<S6>/numsum2(1)1' incorporates:
   *  Delay: '<S6>/delay1(1)1'
   *  Delay: '<S6>/delay1(2)2'
   *  Delay: '<S6>/delay2(1)1'
   *  Delay: '<S6>/delay2(2)2'
   *  Gain: '<S6>/gain1(1)(1)'
   *  Gain: '<S6>/gain2(1)(1)'
   *  Inport: '<Root>/In1'
   *  Sum: '<S6>/densum1(1)1'
   *  Sum: '<S6>/densum2(1)1'
   *  Sum: '<S6>/numsum1(1)1'
   */
  rtb_numsum211_h = ((IIRFilter_Bandpass_U.In1 -
                      IIRFilter_Bandpass_DW.delay222_DSTATE_g) *
                     IIRFilter_Bandpass_P.gain111_Gain_j +
                     IIRFilter_Bandpass_DW.delay211_DSTATE_b) +
    (IIRFilter_Bandpass_DW.delay111_DSTATE_p -
     IIRFilter_Bandpass_DW.delay122_DSTATE_h) *
    IIRFilter_Bandpass_P.gain211_Gain_f;

  /* Sum: '<S6>/numsum2(2)2' incorporates:
   *  Delay: '<S6>/delay1(2)2'
   *  Delay: '<S6>/delay1(3)3'
   *  Delay: '<S6>/delay2(2)2'
   *  Delay: '<S6>/delay2(3)3'
   *  Gain: '<S6>/gain1(2)(2)'
   *  Gain: '<S6>/gain2(2)(2)'
   *  Sum: '<S6>/densum1(2)2'
   *  Sum: '<S6>/densum2(2)2'
   *  Sum: '<S6>/numsum1(2)2'
   */
  rtb_numsum222_h = ((rtb_numsum211_h - IIRFilter_Bandpass_DW.delay233_DSTATE_b)
                     * IIRFilter_Bandpass_P.gain122_Gain_j +
                     IIRFilter_Bandpass_DW.delay222_DSTATE_g) +
    (IIRFilter_Bandpass_DW.delay122_DSTATE_h -
     IIRFilter_Bandpass_DW.delay133_DSTATE_h) *
    IIRFilter_Bandpass_P.gain222_Gain_d;

  /* Sum: '<S6>/numsum2(3)3' incorporates:
   *  Delay: '<S6>/delay1(3)3'
   *  Delay: '<S6>/delay1(4)4'
   *  Delay: '<S6>/delay2(3)3'
   *  Delay: '<S6>/delay2(4)4'
   *  Gain: '<S6>/gain1(3)(3)'
   *  Gain: '<S6>/gain2(3)(3)'
   *  Sum: '<S6>/densum1(3)3'
   *  Sum: '<S6>/densum2(3)3'
   *  Sum: '<S6>/numsum1(3)3'
   */
  rtb_numsum233_p = ((rtb_numsum222_h - IIRFilter_Bandpass_DW.delay244_DSTATE_e)
                     * IIRFilter_Bandpass_P.gain133_Gain_c +
                     IIRFilter_Bandpass_DW.delay233_DSTATE_b) +
    (IIRFilter_Bandpass_DW.delay133_DSTATE_h -
     IIRFilter_Bandpass_DW.delay144_DSTATE_h) *
    IIRFilter_Bandpass_P.gain233_Gain_c;

  /* Sum: '<S6>/numsum2(4)4' incorporates:
   *  Delay: '<S6>/delay1(4)4'
   *  Delay: '<S6>/delay1(5)5'
   *  Delay: '<S6>/delay2(4)4'
   *  Delay: '<S6>/delay2(5)5'
   *  Gain: '<S6>/gain1(4)(4)'
   *  Gain: '<S6>/gain2(4)(4)'
   *  Sum: '<S6>/densum1(4)4'
   *  Sum: '<S6>/densum2(4)4'
   *  Sum: '<S6>/numsum1(4)4'
   */
  rtb_numsum244_j = ((rtb_numsum233_p - IIRFilter_Bandpass_DW.delay255_DSTATE_m)
                     * IIRFilter_Bandpass_P.gain144_Gain_c +
                     IIRFilter_Bandpass_DW.delay244_DSTATE_e) +
    (IIRFilter_Bandpass_DW.delay144_DSTATE_h -
     IIRFilter_Bandpass_DW.delay155_DSTATE_l) *
    IIRFilter_Bandpass_P.gain244_Gain_o;

  /* Outport: '<Root>/Out1' incorporates:
   *  Gain: '<S4>/g(1)'
   *  Sum: '<S3>/Sum1'
   */
  IIRFilter_Bandpass_Y.Out1 = (rtb_numsum255 + rtb_numsum244_j) *
    IIRFilter_Bandpass_P.g1_Gain_b;

  /* Update for Delay: '<S8>/delay1(5)5' */
  IIRFilter_Bandpass_DW.delay155_DSTATE = rtb_numsum244;

  /* Update for Delay: '<S8>/delay1(6)6' */
  IIRFilter_Bandpass_DW.delay166_DSTATE = rtb_numsum255;

  /* Update for Delay: '<S8>/delay2(4)4' incorporates:
   *  Delay: '<S8>/delay1(4)4'
   */
  IIRFilter_Bandpass_DW.delay244_DSTATE = IIRFilter_Bandpass_DW.delay144_DSTATE;

  /* Update for Delay: '<S8>/delay1(3)3' */
  IIRFilter_Bandpass_DW.delay133_DSTATE = rtb_numsum222;

  /* Update for Delay: '<S8>/delay1(4)4' */
  IIRFilter_Bandpass_DW.delay144_DSTATE = rtb_numsum233;

  /* Update for Delay: '<S8>/delay2(2)2' incorporates:
   *  Delay: '<S8>/delay1(2)2'
   */
  IIRFilter_Bandpass_DW.delay222_DSTATE = IIRFilter_Bandpass_DW.delay122_DSTATE;

  /* Update for Delay: '<S8>/delay1(1)1' */
  IIRFilter_Bandpass_DW.delay111_DSTATE = rtb_g1;

  /* Update for Delay: '<S8>/delay1(2)2' */
  IIRFilter_Bandpass_DW.delay122_DSTATE = rtb_numsum211;

  /* Update for Delay: '<S8>/delay2(1)1' */
  IIRFilter_Bandpass_DW.delay211_DSTATE = rtb_delay111;

  /* Update for Delay: '<S8>/delay2(3)3' */
  IIRFilter_Bandpass_DW.delay233_DSTATE = rtb_delay133;

  /* Update for Delay: '<S8>/delay2(5)5' */
  IIRFilter_Bandpass_DW.delay255_DSTATE = rtb_delay155;

  /* Update for Delay: '<S8>/delay2(6)6' */
  IIRFilter_Bandpass_DW.delay266_DSTATE = rtb_delay166;

  /* Update for Delay: '<S6>/delay2(4)4' incorporates:
   *  Delay: '<S6>/delay1(4)4'
   */
  IIRFilter_Bandpass_DW.delay244_DSTATE_e =
    IIRFilter_Bandpass_DW.delay144_DSTATE_h;

  /* Update for Delay: '<S6>/delay1(3)3' */
  IIRFilter_Bandpass_DW.delay133_DSTATE_h = rtb_numsum222_h;

  /* Update for Delay: '<S6>/delay1(4)4' */
  IIRFilter_Bandpass_DW.delay144_DSTATE_h = rtb_numsum233_p;

  /* Update for Delay: '<S6>/delay2(2)2' incorporates:
   *  Delay: '<S6>/delay1(2)2'
   */
  IIRFilter_Bandpass_DW.delay222_DSTATE_g =
    IIRFilter_Bandpass_DW.delay122_DSTATE_h;

  /* Update for Delay: '<S6>/delay1(1)1' incorporates:
   *  Inport: '<Root>/In1'
   */
  IIRFilter_Bandpass_DW.delay111_DSTATE_p = IIRFilter_Bandpass_U.In1;

  /* Update for Delay: '<S6>/delay1(2)2' */
  IIRFilter_Bandpass_DW.delay122_DSTATE_h = rtb_numsum211_h;

  /* Update for Delay: '<S6>/delay2(1)1' */
  IIRFilter_Bandpass_DW.delay211_DSTATE_b = rtb_delay111_i;

  /* Update for Delay: '<S6>/delay2(3)3' */
  IIRFilter_Bandpass_DW.delay233_DSTATE_b = rtb_delay133_d;

  /* Update for Delay: '<S6>/delay2(5)5' incorporates:
   *  Delay: '<S6>/delay1(5)5'
   */
  IIRFilter_Bandpass_DW.delay255_DSTATE_m =
    IIRFilter_Bandpass_DW.delay155_DSTATE_l;

  /* Update for Delay: '<S6>/delay1(5)5' */
  IIRFilter_Bandpass_DW.delay155_DSTATE_l = rtb_numsum244_j;
}

/* Model initialize function */
void IIRFilter_BandpassModelClass::initialize()
{
  /* InitializeConditions for Delay: '<S8>/delay1(5)5' */
  IIRFilter_Bandpass_DW.delay155_DSTATE =
    IIRFilter_Bandpass_P.delay155_InitialCondition;

  /* InitializeConditions for Delay: '<S8>/delay1(6)6' */
  IIRFilter_Bandpass_DW.delay166_DSTATE =
    IIRFilter_Bandpass_P.delay166_InitialCondition;

  /* InitializeConditions for Delay: '<S8>/delay2(4)4' */
  IIRFilter_Bandpass_DW.delay244_DSTATE =
    IIRFilter_Bandpass_P.delay244_InitialCondition;

  /* InitializeConditions for Delay: '<S8>/delay1(3)3' */
  IIRFilter_Bandpass_DW.delay133_DSTATE =
    IIRFilter_Bandpass_P.delay133_InitialCondition;

  /* InitializeConditions for Delay: '<S8>/delay1(4)4' */
  IIRFilter_Bandpass_DW.delay144_DSTATE =
    IIRFilter_Bandpass_P.delay144_InitialCondition;

  /* InitializeConditions for Delay: '<S8>/delay2(2)2' */
  IIRFilter_Bandpass_DW.delay222_DSTATE =
    IIRFilter_Bandpass_P.delay222_InitialCondition;

  /* InitializeConditions for Delay: '<S8>/delay1(1)1' */
  IIRFilter_Bandpass_DW.delay111_DSTATE =
    IIRFilter_Bandpass_P.delay111_InitialCondition;

  /* InitializeConditions for Delay: '<S8>/delay1(2)2' */
  IIRFilter_Bandpass_DW.delay122_DSTATE =
    IIRFilter_Bandpass_P.delay122_InitialCondition;

  /* InitializeConditions for Delay: '<S8>/delay2(1)1' */
  IIRFilter_Bandpass_DW.delay211_DSTATE =
    IIRFilter_Bandpass_P.delay211_InitialCondition;

  /* InitializeConditions for Delay: '<S8>/delay2(3)3' */
  IIRFilter_Bandpass_DW.delay233_DSTATE =
    IIRFilter_Bandpass_P.delay233_InitialCondition;

  /* InitializeConditions for Delay: '<S8>/delay2(5)5' */
  IIRFilter_Bandpass_DW.delay255_DSTATE =
    IIRFilter_Bandpass_P.delay255_InitialCondition;

  /* InitializeConditions for Delay: '<S8>/delay2(6)6' */
  IIRFilter_Bandpass_DW.delay266_DSTATE =
    IIRFilter_Bandpass_P.delay266_InitialCondition;

  /* InitializeConditions for Delay: '<S6>/delay2(4)4' */
  IIRFilter_Bandpass_DW.delay244_DSTATE_e =
    IIRFilter_Bandpass_P.delay244_InitialCondition_f;

  /* InitializeConditions for Delay: '<S6>/delay1(3)3' */
  IIRFilter_Bandpass_DW.delay133_DSTATE_h =
    IIRFilter_Bandpass_P.delay133_InitialCondition_j;

  /* InitializeConditions for Delay: '<S6>/delay1(4)4' */
  IIRFilter_Bandpass_DW.delay144_DSTATE_h =
    IIRFilter_Bandpass_P.delay144_InitialCondition_f;

  /* InitializeConditions for Delay: '<S6>/delay2(2)2' */
  IIRFilter_Bandpass_DW.delay222_DSTATE_g =
    IIRFilter_Bandpass_P.delay222_InitialCondition_l;

  /* InitializeConditions for Delay: '<S6>/delay1(1)1' */
  IIRFilter_Bandpass_DW.delay111_DSTATE_p =
    IIRFilter_Bandpass_P.delay111_InitialCondition_n;

  /* InitializeConditions for Delay: '<S6>/delay1(2)2' */
  IIRFilter_Bandpass_DW.delay122_DSTATE_h =
    IIRFilter_Bandpass_P.delay122_InitialCondition_c;

  /* InitializeConditions for Delay: '<S6>/delay2(1)1' */
  IIRFilter_Bandpass_DW.delay211_DSTATE_b =
    IIRFilter_Bandpass_P.delay211_InitialCondition_n;

  /* InitializeConditions for Delay: '<S6>/delay2(3)3' */
  IIRFilter_Bandpass_DW.delay233_DSTATE_b =
    IIRFilter_Bandpass_P.delay233_InitialCondition_p;

  /* InitializeConditions for Delay: '<S6>/delay2(5)5' */
  IIRFilter_Bandpass_DW.delay255_DSTATE_m =
    IIRFilter_Bandpass_P.delay255_InitialCondition_o;

  /* InitializeConditions for Delay: '<S6>/delay1(5)5' */
  IIRFilter_Bandpass_DW.delay155_DSTATE_l =
    IIRFilter_Bandpass_P.delay155_InitialCondition_i;
}

/* Model terminate function */
void IIRFilter_BandpassModelClass::terminate()
{
  /* (no terminate code required) */
}

/* Constructor */
IIRFilter_BandpassModelClass::IIRFilter_BandpassModelClass():
  IIRFilter_Bandpass_DW()
  ,IIRFilter_Bandpass_U()
  ,IIRFilter_Bandpass_Y()
  ,IIRFilter_Bandpass_M()
{
  /* Currently there is no constructor body generated.*/
}

/* Destructor */
IIRFilter_BandpassModelClass::~IIRFilter_BandpassModelClass()
{
  /* Currently there is no destructor body generated.*/
}

/* Real-Time Model get method */
RT_MODEL_IIRFilter_Bandpass_T * IIRFilter_BandpassModelClass::getRTM()
{
  return (&IIRFilter_Bandpass_M);
}
