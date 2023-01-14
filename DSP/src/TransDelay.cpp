/*
 * TransDelay.cpp
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "TransDelay".
 *
 * Model version              : 1.1
 * Simulink Coder version : 9.3 (R2020a) 18-Nov-2019
 * C++ source code generated on : Mon May 10 16:10:38 2021
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "TransDelay.h"
#include "TransDelay_private.h"

/* For variable transport delay block, find the real delay time */
real_T rt_VTDelayfindtDInterpolate(
  real_T x,real_T* tBuf,real_T* uBuf,real_T* xBuf,int_T bufSz,int_T head,int_T
  tail,int_T* pLast,real_T t,real_T tStart,boolean_T discrete,boolean_T
  minorStepAndTAtLastMajorOutput,real_T initOutput,real_T* appliedDelay)
{
  int_T n, k;
  real_T f;
  int_T kp1;
  real_T tminustD, tL, tR, uD, uL, uR, fU;
  if (minorStepAndTAtLastMajorOutput) {
    /* pretend that the entry at head has not been added */
    if (*pLast == head) {
      *pLast = (*pLast == 0) ? bufSz-1 : *pLast-1;
    }

    head = (head == 0) ? bufSz-1 : head-1;
  }

  /*
   * The loop below finds k such that:
   *      x(t)-x(tminustD) =1 or
   *      x - xBuf[k+1] <= 1.0 < x - xBuf[k]
   *
   * Note that we have:
   *
   * tStart = tBuf[0] < tBuf[1] < ... < tBuf[tail] < ... tBuf[head] <= t
   *      0 = xBuf[0] < xBuf[1] < ... < xBuf[tail] < ... xBuf[head] <  x
   *
   * This is true if we assume the direction of transport is always positive
   * such as a flow goes through a pipe from one end to another. However, for
   * model such as convey belt, the transportation can change direction. For
   * this case, there will be more than one solution to x(t)-x(tminustD) = 1,
   * should found the minimum tminustD and tminustD > 0. The search will not
   * be as efficient as the following code.
   */

  /*
   * when x<=1, physically it means the flow didn't reach the output yet,
   * t-tD will be less then zero, so force output to be the initial output
   */
  if (x <= 1) {
    return initOutput;
  }

  /*
   * if the x is monoton increase, only one solution. use k=pLast for now
   */
  k= *pLast;
  n = 0;
  for (;;) {
    n++;
    if (n>bufSz)
      break;
    if (x - xBuf[k] > 1.0) {
      /* move k forward, unless k = head */
      if (k == head) {
        /* xxx this situation means tD= appliedDelay = 0
         *
         * linearly interpolate using (tBuf[head], xBuf[head])
         * and (t,x) to find (tD,xD) such that: x - xD = 1.0
         */
        int_T km1;
        f = (x - 1.0 - xBuf[k]) / (x - xBuf[k]);
        tminustD = (1.0-f)*tBuf[k] + f*t;
        km1 = k-1;
        if (km1 < 0)
          km1 = bufSz-1;
        tL = tBuf[km1];
        tR = tBuf[k];
        uL = uBuf[km1];
        uR = uBuf[k];
        break;
      }

      kp1 = k+1;
      if (kp1 == bufSz)
        kp1 = 0;
      if (x - xBuf[kp1] <= 1.0) {
        /*
         * linearly interpolate using (tBuf[k], xBuf[k])
         * and  (tBuf[k+1], xBuf[k+1]) to find (tminustD,xD)
         * such that: x - xD = 1.0
         */
        f = (x - 1.0 - xBuf[k]) / (xBuf[kp1] - xBuf[k]);
        tL = tBuf[k];
        tR = tBuf[kp1];
        uL = uBuf[k];
        uR = uBuf[kp1];
        tminustD = (1.0-f)*tL + f*tR;
        break;
      }

      k = kp1;
    } else {
      /* moved k backward, unless k = tail */
      if (k == tail) {
        /* This situation means tminustD <= Ttail*/
        f = (x - 1.0)/xBuf[k];
        if (discrete) {
          return(uBuf[tail]);
        }

        kp1 = k+1;
        if (kp1 == bufSz)
          kp1 = 0;

        /* * linearly interpolate using (tStart, 0)
         * and  (tBuf[tail], xBuf[tail]) to find (tminustD,xD)
         * such that: x - xD = 1.0
         */

        /* Here it is better to use Tstart because since x>1, tminustD
         * must > 0. Since x is monotone increase, its linearity is
         * better.
         */
        tminustD = (1-f)*tStart + f*tBuf[k];

        /* linearly interpolate using (t[tail], x[tail])
         * and  (tBuf[tail+1], xBuf[tail+1]) to find (tminustD,xD)
         * such that: x - xD = 1.0.
         * For time delay block, use t[tail] and t[tail+1], not good
         * for transport delay block since it may give tminstD < 0
         */

        /*  f = (tBuf[kp1]-tBuf[k])/(xBuf[kp1]-xBuf[k]);
         *  tminustD = tBuf[kp1]-f*(1+xBuf[kp1]-x);
         */
        tL = tBuf[k];
        tR = tBuf[kp1];
        uL = uBuf[k];
        uR = uBuf[kp1];
        break;
      }

      k = k - 1;
      if (k < 0)
        k = bufSz-1;
    }
  }

  *pLast = k;
  if (tR == tL) {
    fU = 1.0;
  } else {
    fU = (tminustD-tL)/(tR-tL);
  }

  /* for discrete signal, no interpolation, use either uL or uR
   * depend on wehre tminustD is.
   */
  if (discrete) {
    uD= (fU > (1.0-fU))? uR: uL;
  } else {
    uD = (1.0-fU)*uL + fU*uR;
  }

  /* we want return tD= t-(t-tD);*/
  *appliedDelay = t-tminustD;
  return uD;
}

/*
 * This function updates continuous states using the ODE4 fixed-step
 * solver algorithm
 */
void TransDelayModelClass::rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE4_IntgData *id = static_cast<ODE4_IntgData *>(rtsiGetSolverData(si));
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T *f3 = id->f[3];
  real_T temp;
  int_T i;
  int_T nXc = 1;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) std::memcpy(y, x,
                     static_cast<uint_T>(nXc)*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  TransDelay_derivatives();

  /* f1 = f(t + (h/2), y + (h/2)*f0) */
  temp = 0.5 * h;
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (temp*f0[i]);
  }

  rtsiSetT(si, t + temp);
  rtsiSetdX(si, f1);
  this->step();
  TransDelay_derivatives();

  /* f2 = f(t + (h/2), y + (h/2)*f1) */
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (temp*f1[i]);
  }

  rtsiSetdX(si, f2);
  this->step();
  TransDelay_derivatives();

  /* f3 = f(t + h, y + h*f2) */
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (h*f2[i]);
  }

  rtsiSetT(si, tnew);
  rtsiSetdX(si, f3);
  this->step();
  TransDelay_derivatives();

  /* tnew = t + h
     ynew = y + (h/6)*(f0 + 2*f1 + 2*f2 + 2*f3) */
  temp = h / 6.0;
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + temp*(f0[i] + 2.0*f1[i] + 2.0*f2[i] + f3[i]);
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model step function */
void TransDelayModelClass::step()
{
  /* local block i/o variables */
  real_T rtb_VariableTransportDelay;
  if (rtmIsMajorTimeStep((&TransDelay_M))) {
    /* set solver stop time */
    if (!((&TransDelay_M)->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&(&TransDelay_M)->solverInfo, (((&TransDelay_M)
        ->Timing.clockTickH0 + 1) * (&TransDelay_M)->Timing.stepSize0 *
        4294967296.0));
    } else {
      rtsiSetSolverStopTime(&(&TransDelay_M)->solverInfo, (((&TransDelay_M)
        ->Timing.clockTick0 + 1) * (&TransDelay_M)->Timing.stepSize0 +
        (&TransDelay_M)->Timing.clockTickH0 * (&TransDelay_M)->Timing.stepSize0 *
        4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep((&TransDelay_M))) {
    (&TransDelay_M)->Timing.t[0] = rtsiGetT(&(&TransDelay_M)->solverInfo);
  }

  /* VariableTransportDelay: '<Root>/Variable Transport Delay' incorporates:
   *  Inport: '<Root>/In1'
   *  Inport: '<Root>/In2'
   */
  {
    real_T **uBuffer = (real_T**)
      &TransDelay_DW.VariableTransportDelay_PWORK.TUbufferPtrs[0];
    real_T **tBuffer = (real_T**)
      &TransDelay_DW.VariableTransportDelay_PWORK.TUbufferPtrs[1];
    real_T **xBuffer = (real_T**)
      &TransDelay_DW.VariableTransportDelay_PWORK.TUbufferPtrs[2];
    real_T simTime = (&TransDelay_M)->Timing.t[0];
    real_T appliedDelay;

    /* For variable transport dealy, find the real applied dealy
     * here and then output
     */
    rtb_VariableTransportDelay= rt_VTDelayfindtDInterpolate
      (TransDelay_X.VariableTransportDelay_CSTATE,*tBuffer,*uBuffer, *xBuffer,
       TransDelay_DW.VariableTransportDelay_IWORK.CircularBufSize,
       TransDelay_DW.VariableTransportDelay_IWORK.Head,
       TransDelay_DW.VariableTransportDelay_IWORK.Tail,
       &TransDelay_DW.VariableTransportDelay_IWORK.Last, simTime, 0.0,0,
       0, 0.0,
       &appliedDelay);
  }

  /* Outport: '<Root>/Out1' */
  TransDelay_Y.Out1 = rtb_VariableTransportDelay;
  if (rtmIsMajorTimeStep((&TransDelay_M))) {
    /* Update for VariableTransportDelay: '<Root>/Variable Transport Delay' incorporates:
     *  Inport: '<Root>/In1'
     *  Inport: '<Root>/In2'
     */
    {
      real_T **uBuffer = (real_T**)
        &TransDelay_DW.VariableTransportDelay_PWORK.TUbufferPtrs[0];
      real_T **tBuffer = (real_T**)
        &TransDelay_DW.VariableTransportDelay_PWORK.TUbufferPtrs[1];
      real_T **xBuffer = (real_T**)
        &TransDelay_DW.VariableTransportDelay_PWORK.TUbufferPtrs[2];
      real_T simTime = (&TransDelay_M)->Timing.t[0];
      TransDelay_DW.VariableTransportDelay_IWORK.Head =
        ((TransDelay_DW.VariableTransportDelay_IWORK.Head <
          (TransDelay_DW.VariableTransportDelay_IWORK.CircularBufSize-1)) ?
         (TransDelay_DW.VariableTransportDelay_IWORK.Head+1) : 0);
      if (TransDelay_DW.VariableTransportDelay_IWORK.Head ==
          TransDelay_DW.VariableTransportDelay_IWORK.Tail) {
        TransDelay_DW.VariableTransportDelay_IWORK.Tail =
          ((TransDelay_DW.VariableTransportDelay_IWORK.Tail <
            (TransDelay_DW.VariableTransportDelay_IWORK.CircularBufSize-1)) ?
           (TransDelay_DW.VariableTransportDelay_IWORK.Tail+1) : 0);
      }

      (*tBuffer)[TransDelay_DW.VariableTransportDelay_IWORK.Head] = simTime;
      (*uBuffer)[TransDelay_DW.VariableTransportDelay_IWORK.Head] =
        TransDelay_U.In1;
      (*xBuffer)[TransDelay_DW.VariableTransportDelay_IWORK.Head] =
        TransDelay_X.VariableTransportDelay_CSTATE;

      /* when use fixed buffer, reset solver at when buffer is updated
       * to avoid output consistency fail.
       */
    }
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep((&TransDelay_M))) {
    rt_ertODEUpdateContinuousStates(&(&TransDelay_M)->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick0 and the high bits
     * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++(&TransDelay_M)->Timing.clockTick0)) {
      ++(&TransDelay_M)->Timing.clockTickH0;
    }

    (&TransDelay_M)->Timing.t[0] = rtsiGetSolverStopTime(&(&TransDelay_M)
      ->solverInfo);

    {
      /* Update absolute timer for sample time: [0.01s, 0.0s] */
      /* The "clockTick1" counts the number of times the code of this task has
       * been executed. The resolution of this integer timer is 0.01, which is the step size
       * of the task. Size of "clockTick1" ensures timer will not overflow during the
       * application lifespan selected.
       * Timer of this task consists of two 32 bit unsigned integers.
       * The two integers represent the low bits Timing.clockTick1 and the high bits
       * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
       */
      (&TransDelay_M)->Timing.clockTick1++;
      if (!(&TransDelay_M)->Timing.clockTick1) {
        (&TransDelay_M)->Timing.clockTickH1++;
      }
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void TransDelayModelClass::TransDelay_derivatives()
{
  /* Derivatives for VariableTransportDelay: '<Root>/Variable Transport Delay' incorporates:
   *  Inport: '<Root>/In1'
   *  Inport: '<Root>/In2'
   */
  {
    real_T instantDelay;
    instantDelay = TransDelay_U.In2;
    if (instantDelay > 1000.0) {
      instantDelay = 1000.0;
    }

    if (instantDelay < 0.0) {
      ((XDot_TransDelay_T *) (&TransDelay_M)->derivs)
        ->VariableTransportDelay_CSTATE = 0;
    } else {
      ((XDot_TransDelay_T *) (&TransDelay_M)->derivs)
        ->VariableTransportDelay_CSTATE = 1.0/instantDelay;
    }
  }
}

/* Model initialize function */
void TransDelayModelClass::initialize()
{
  /* Registration code */
  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&(&TransDelay_M)->solverInfo, &(&TransDelay_M)
                          ->Timing.simTimeStep);
    rtsiSetTPtr(&(&TransDelay_M)->solverInfo, &rtmGetTPtr((&TransDelay_M)));
    rtsiSetStepSizePtr(&(&TransDelay_M)->solverInfo, &(&TransDelay_M)
                       ->Timing.stepSize0);
    rtsiSetdXPtr(&(&TransDelay_M)->solverInfo, &(&TransDelay_M)->derivs);
    rtsiSetContStatesPtr(&(&TransDelay_M)->solverInfo, (real_T **)
                         &(&TransDelay_M)->contStates);
    rtsiSetNumContStatesPtr(&(&TransDelay_M)->solverInfo, &(&TransDelay_M)
      ->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&(&TransDelay_M)->solverInfo,
      &(&TransDelay_M)->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&(&TransDelay_M)->solverInfo,
      &(&TransDelay_M)->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&(&TransDelay_M)->solverInfo,
      &(&TransDelay_M)->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&(&TransDelay_M)->solverInfo, (&rtmGetErrorStatus
      ((&TransDelay_M))));
    rtsiSetRTModelPtr(&(&TransDelay_M)->solverInfo, (&TransDelay_M));
  }

  rtsiSetSimTimeStep(&(&TransDelay_M)->solverInfo, MAJOR_TIME_STEP);
  (&TransDelay_M)->intgData.y = (&TransDelay_M)->odeY;
  (&TransDelay_M)->intgData.f[0] = (&TransDelay_M)->odeF[0];
  (&TransDelay_M)->intgData.f[1] = (&TransDelay_M)->odeF[1];
  (&TransDelay_M)->intgData.f[2] = (&TransDelay_M)->odeF[2];    
  (&TransDelay_M)->intgData.f[3] = (&TransDelay_M)->odeF[3];
  (&TransDelay_M)->contStates = ((X_TransDelay_T *) &TransDelay_X);
  rtsiSetSolverData(&(&TransDelay_M)->solverInfo, static_cast<void *>
                    (&(&TransDelay_M)->intgData));
  rtsiSetSolverName(&(&TransDelay_M)->solverInfo,"ode4");
  rtmSetTPtr((&TransDelay_M), &(&TransDelay_M)->Timing.tArray[0]);
  (&TransDelay_M)->Timing.stepSize0 = 0.01;

  /* Start for VariableTransportDelay: '<Root>/Variable Transport Delay' incorporates:
   *  Inport: '<Root>/In1'
   *  Inport: '<Root>/In2'
   */
  {
    real_T *pBuffer = &TransDelay_DW.VariableTransportDelay_RWORK.TUbufferArea[0];
    int_T j;
    TransDelay_DW.VariableTransportDelay_IWORK.Tail = 0;
    TransDelay_DW.VariableTransportDelay_IWORK.Head = 0;
    TransDelay_DW.VariableTransportDelay_IWORK.Last = 0;
    TransDelay_DW.VariableTransportDelay_IWORK.CircularBufSize = 1024;
    for (j=0; j < 1024; j++) {
      pBuffer[j] = 0.0;
      pBuffer[1024 + j] = (&TransDelay_M)->Timing.t[0];
    }

    pBuffer[2*1024] = 0.0;
    TransDelay_DW.VariableTransportDelay_PWORK.TUbufferPtrs[0] = (void *)
      &pBuffer[0];
    TransDelay_DW.VariableTransportDelay_PWORK.TUbufferPtrs[1] = (void *)
      &pBuffer[1024];
    TransDelay_DW.VariableTransportDelay_PWORK.TUbufferPtrs[2] = (void *)
      &pBuffer[2*1024];
  }

  /* InitializeConditions for VariableTransportDelay: '<Root>/Variable Transport Delay' incorporates:
   *  Inport: '<Root>/In1'
   *  Inport: '<Root>/In2'
   */
  TransDelay_X.VariableTransportDelay_CSTATE = 0.0;
}

/* Model terminate function */
void TransDelayModelClass::terminate()
{
  /* (no terminate code required) */
}

/* Constructor */
TransDelayModelClass::TransDelayModelClass():
  TransDelay_DW()
  ,TransDelay_X()
  ,TransDelay_U()
  ,TransDelay_Y()
  ,TransDelay_M()
{
  /* Currently there is no constructor body generated.*/
}

/* Destructor */
TransDelayModelClass::~TransDelayModelClass()
{
  /* Currently there is no destructor body generated.*/
}

/* Real-Time Model get method */
RT_MODEL_TransDelay_T * TransDelayModelClass::getRTM()
{
  return (&TransDelay_M);
}
