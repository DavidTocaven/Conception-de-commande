/*
 * SimuDemonstrateurMoteur.c
 *
 * Code generation for model "SimuDemonstrateurMoteur".
 *
 * Model version              : 1.6
 * Simulink Coder version : 8.3 (R2012b) 20-Jul-2012
 * C source code generated on : Thu Dec 14 08:08:18 2017
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#include "SimuDemonstrateurMoteur.h"
#include "SimuDemonstrateurMoteur_private.h"

/* Block signals (auto storage) */
BlockIO_SimuDemonstrateurMoteur SimuDemonstrateurMoteur_B;

/* Continuous states */
ContinuousStates_SimuDemonstrat SimuDemonstrateurMoteur_X;

/* Block states (auto storage) */
D_Work_SimuDemonstrateurMoteur SimuDemonstrateurMoteur_DWork;

/* Real-time model */
RT_MODEL_SimuDemonstrateurMoteu SimuDemonstrateurMoteur_M_;
RT_MODEL_SimuDemonstrateurMoteu *const SimuDemonstrateurMoteur_M =
  &SimuDemonstrateurMoteur_M_;

/*
 * This function updates continuous states using the ODE4 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE4_IntgData *id = (ODE4_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T *f3 = id->f[3];
  real_T temp;
  int_T i;
  int_T nXc = 6;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  SimuDemonstrateurMoteur_derivatives();

  /* f1 = f(t + (h/2), y + (h/2)*f0) */
  temp = 0.5 * h;
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (temp*f0[i]);
  }

  rtsiSetT(si, t + temp);
  rtsiSetdX(si, f1);
  SimuDemonstrateurMoteur_step();
  SimuDemonstrateurMoteur_derivatives();

  /* f2 = f(t + (h/2), y + (h/2)*f1) */
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (temp*f1[i]);
  }

  rtsiSetdX(si, f2);
  SimuDemonstrateurMoteur_step();
  SimuDemonstrateurMoteur_derivatives();

  /* f3 = f(t + h, y + h*f2) */
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (h*f2[i]);
  }

  rtsiSetT(si, tnew);
  rtsiSetdX(si, f3);
  SimuDemonstrateurMoteur_step();
  SimuDemonstrateurMoteur_derivatives();

  /* tnew = t + h
     ynew = y + (h/6)*(f0 + 2*f1 + 2*f2 + 2*f3) */
  temp = h / 6.0;
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + temp*(f0[i] + 2.0*f1[i] + 2.0*f2[i] + f3[i]);
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model step function */
void SimuDemonstrateurMoteur_step(void)
{
  /* local block i/o variables */
  real_T rtb_Observateur[2];
  real_T rtb_N;
  if (rtmIsMajorTimeStep(SimuDemonstrateurMoteur_M)) {
    /* set solver stop time */
    if (!(SimuDemonstrateurMoteur_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&SimuDemonstrateurMoteur_M->solverInfo,
                            ((SimuDemonstrateurMoteur_M->Timing.clockTickH0 + 1)
        * SimuDemonstrateurMoteur_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&SimuDemonstrateurMoteur_M->solverInfo,
                            ((SimuDemonstrateurMoteur_M->Timing.clockTick0 + 1) *
        SimuDemonstrateurMoteur_M->Timing.stepSize0 +
        SimuDemonstrateurMoteur_M->Timing.clockTickH0 *
        SimuDemonstrateurMoteur_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(SimuDemonstrateurMoteur_M)) {
    SimuDemonstrateurMoteur_M->Timing.t[0] = rtsiGetT
      (&SimuDemonstrateurMoteur_M->solverInfo);
  }

  /* SignalGenerator: '<Root>/Signal Generator' */
  rtb_N = SimuDemonstrateurMoteur_P.SignalGenerator_Frequency *
    SimuDemonstrateurMoteur_M->Timing.t[0];
  if (rtb_N - floor(rtb_N) >= 0.5) {
    rtb_N = SimuDemonstrateurMoteur_P.SignalGenerator_Amplitude;
  } else {
    rtb_N = -SimuDemonstrateurMoteur_P.SignalGenerator_Amplitude;
  }

  /* End of SignalGenerator: '<Root>/Signal Generator' */

  /* Gain: '<Root>/Gain' incorporates:
   *  Constant: '<Root>/Constant'
   *  Sum: '<Root>/Sum'
   */
  SimuDemonstrateurMoteur_B.Gain = (SimuDemonstrateurMoteur_P.Constant_Value -
    rtb_N) * SimuDemonstrateurMoteur_P.Gain_Gain;

  /* Gain: '<S2>/N ' */
  rtb_N = SimuDemonstrateurMoteur_P.N_Gain * SimuDemonstrateurMoteur_B.Gain;

  /* StateSpace: '<S3>/Observateur ' */
  {
    rtb_Observateur[0] = (SimuDemonstrateurMoteur_P.Observateur_C[0])*
      SimuDemonstrateurMoteur_X.Observateur_CSTATE[0];
    rtb_Observateur[1] = (SimuDemonstrateurMoteur_P.Observateur_C[1])*
      SimuDemonstrateurMoteur_X.Observateur_CSTATE[1];
  }

  /* Sum: '<S2>/Sum' incorporates:
   *  Gain: '<S2>/retourEE0'
   */
  SimuDemonstrateurMoteur_B.Sum = rtb_N -
    SimuDemonstrateurMoteur_P.retourEE0_Gain * rtb_Observateur[1];

  /* S-Function (ModeleDemonstrateurMoteur): '<Root>/S-Function Builder' */
  {
    real_T *pxc = &SimuDemonstrateurMoteur_X.SFunctionBuilder_CSTATE[0];
    ModeleDemonstrateurMoteur_Outputs_wrapper(&SimuDemonstrateurMoteur_B.Sum,
      &SimuDemonstrateurMoteur_B.SFunctionBuilder_o1,
      &SimuDemonstrateurMoteur_B.SFunctionBuilder_o2, pxc,
      &SimuDemonstrateurMoteur_P.SFunctionBuilder_P1, 1,
      &SimuDemonstrateurMoteur_P.SFunctionBuilder_P2, 1,
      &SimuDemonstrateurMoteur_P.SFunctionBuilder_P3, 1,
      &SimuDemonstrateurMoteur_P.SFunctionBuilder_P4, 1,
      &SimuDemonstrateurMoteur_P.SFunctionBuilder_P5, 1,
      &SimuDemonstrateurMoteur_P.SFunctionBuilder_P6, 1,
      &SimuDemonstrateurMoteur_P.SFunctionBuilder_P7, 1,
      &SimuDemonstrateurMoteur_P.SFunctionBuilder_P8, 1,
      &SimuDemonstrateurMoteur_P.SFunctionBuilder_P9, 1,
      &SimuDemonstrateurMoteur_P.SFunctionBuilder_P10, 1,
      &SimuDemonstrateurMoteur_P.SFunctionBuilder_P11, 1,
      &SimuDemonstrateurMoteur_P.SFunctionBuilder_P12, 1,
      &SimuDemonstrateurMoteur_P.SFunctionBuilder_P13, 1,
      &SimuDemonstrateurMoteur_P.SFunctionBuilder_P14, 1,
      &SimuDemonstrateurMoteur_P.SFunctionBuilder_P15, 1,
      &SimuDemonstrateurMoteur_P.SFunctionBuilder_P16, 1);
  }

  if (rtmIsMajorTimeStep(SimuDemonstrateurMoteur_M)) {
  }

  /* Sum: '<S3>/Sum' incorporates:
   *  Gain: '<S3>/Gain'
   */
  SimuDemonstrateurMoteur_B.Sum_d[0] = 0.0 -
    (SimuDemonstrateurMoteur_P.Gain_Gain_m[0] * rtb_Observateur[0] +
     SimuDemonstrateurMoteur_P.Gain_Gain_m[2] * rtb_Observateur[1]);
  SimuDemonstrateurMoteur_B.Sum_d[1] = 0.0 -
    (SimuDemonstrateurMoteur_P.Gain_Gain_m[1] * rtb_Observateur[0] +
     SimuDemonstrateurMoteur_P.Gain_Gain_m[3] * rtb_Observateur[1]);
  if (rtmIsMajorTimeStep(SimuDemonstrateurMoteur_M)) {
  }

  if (rtmIsMajorTimeStep(SimuDemonstrateurMoteur_M)) {
    /* Matfile logging */
    rt_UpdateTXYLogVars(SimuDemonstrateurMoteur_M->rtwLogInfo,
                        (SimuDemonstrateurMoteur_M->Timing.t));
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(SimuDemonstrateurMoteur_M)) {
    /* signal main to stop simulation */
    {                                  /* Sample time: [0.0s, 0.0s] */
      if ((rtmGetTFinal(SimuDemonstrateurMoteur_M)!=-1) &&
          !((rtmGetTFinal(SimuDemonstrateurMoteur_M)-
             (((SimuDemonstrateurMoteur_M->Timing.clockTick1+
                SimuDemonstrateurMoteur_M->Timing.clockTickH1* 4294967296.0)) *
              0.2)) > (((SimuDemonstrateurMoteur_M->Timing.clockTick1+
                         SimuDemonstrateurMoteur_M->Timing.clockTickH1*
                         4294967296.0)) * 0.2) * (DBL_EPSILON))) {
        rtmSetErrorStatus(SimuDemonstrateurMoteur_M, "Simulation finished");
      }
    }

    rt_ertODEUpdateContinuousStates(&SimuDemonstrateurMoteur_M->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick0 and the high bits
     * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++SimuDemonstrateurMoteur_M->Timing.clockTick0)) {
      ++SimuDemonstrateurMoteur_M->Timing.clockTickH0;
    }

    SimuDemonstrateurMoteur_M->Timing.t[0] = rtsiGetSolverStopTime
      (&SimuDemonstrateurMoteur_M->solverInfo);

    {
      /* Update absolute timer for sample time: [0.2s, 0.0s] */
      /* The "clockTick1" counts the number of times the code of this task has
       * been executed. The resolution of this integer timer is 0.2, which is the step size
       * of the task. Size of "clockTick1" ensures timer will not overflow during the
       * application lifespan selected.
       * Timer of this task consists of two 32 bit unsigned integers.
       * The two integers represent the low bits Timing.clockTick1 and the high bits
       * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
       */
      SimuDemonstrateurMoteur_M->Timing.clockTick1++;
      if (!SimuDemonstrateurMoteur_M->Timing.clockTick1) {
        SimuDemonstrateurMoteur_M->Timing.clockTickH1++;
      }
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void SimuDemonstrateurMoteur_derivatives(void)
{
  /* Derivatives for StateSpace: '<S3>/Observateur ' */
  {
    ((StateDerivatives_SimuDemonstrat *)
      SimuDemonstrateurMoteur_M->ModelData.derivs)->Observateur_CSTATE[0] =
      (SimuDemonstrateurMoteur_P.Observateur_A[0])*
      SimuDemonstrateurMoteur_X.Observateur_CSTATE[0]
      + (SimuDemonstrateurMoteur_P.Observateur_A[1])*
      SimuDemonstrateurMoteur_X.Observateur_CSTATE[1];
    ((StateDerivatives_SimuDemonstrat *)
      SimuDemonstrateurMoteur_M->ModelData.derivs)->Observateur_CSTATE[0] +=
      (SimuDemonstrateurMoteur_P.Observateur_B[0])*
      SimuDemonstrateurMoteur_B.SFunctionBuilder_o1;
    ((StateDerivatives_SimuDemonstrat *)
      SimuDemonstrateurMoteur_M->ModelData.derivs)->Observateur_CSTATE[1] =
      (SimuDemonstrateurMoteur_P.Observateur_A[2])*
      SimuDemonstrateurMoteur_X.Observateur_CSTATE[0]
      + (SimuDemonstrateurMoteur_P.Observateur_A[3])*
      SimuDemonstrateurMoteur_X.Observateur_CSTATE[1];
    ((StateDerivatives_SimuDemonstrat *)
      SimuDemonstrateurMoteur_M->ModelData.derivs)->Observateur_CSTATE[1] +=
      (SimuDemonstrateurMoteur_P.Observateur_B[1])*
      SimuDemonstrateurMoteur_B.SFunctionBuilder_o1
      + (SimuDemonstrateurMoteur_P.Observateur_B[2])*
      SimuDemonstrateurMoteur_B.Sum;
  }

  /* S-Function "ModeleDemonstrateurMoteur_wrapper" Block: <Root>/S-Function Builder */
  {
    real_T *pxc = &SimuDemonstrateurMoteur_X.SFunctionBuilder_CSTATE[0];
    real_T *dx = &((StateDerivatives_SimuDemonstrat *)
                   SimuDemonstrateurMoteur_M->ModelData.derivs)
      ->SFunctionBuilder_CSTATE[0];
    ModeleDemonstrateurMoteur_Derivatives_wrapper(&SimuDemonstrateurMoteur_B.Sum,
      &SimuDemonstrateurMoteur_B.SFunctionBuilder_o1,
      &SimuDemonstrateurMoteur_B.SFunctionBuilder_o2, dx, pxc,
      &SimuDemonstrateurMoteur_P.SFunctionBuilder_P1, 1,
      &SimuDemonstrateurMoteur_P.SFunctionBuilder_P2, 1,
      &SimuDemonstrateurMoteur_P.SFunctionBuilder_P3, 1,
      &SimuDemonstrateurMoteur_P.SFunctionBuilder_P4, 1,
      &SimuDemonstrateurMoteur_P.SFunctionBuilder_P5, 1,
      &SimuDemonstrateurMoteur_P.SFunctionBuilder_P6, 1,
      &SimuDemonstrateurMoteur_P.SFunctionBuilder_P7, 1,
      &SimuDemonstrateurMoteur_P.SFunctionBuilder_P8, 1,
      &SimuDemonstrateurMoteur_P.SFunctionBuilder_P9, 1,
      &SimuDemonstrateurMoteur_P.SFunctionBuilder_P10, 1,
      &SimuDemonstrateurMoteur_P.SFunctionBuilder_P11, 1,
      &SimuDemonstrateurMoteur_P.SFunctionBuilder_P12, 1,
      &SimuDemonstrateurMoteur_P.SFunctionBuilder_P13, 1,
      &SimuDemonstrateurMoteur_P.SFunctionBuilder_P14, 1,
      &SimuDemonstrateurMoteur_P.SFunctionBuilder_P15, 1,
      &SimuDemonstrateurMoteur_P.SFunctionBuilder_P16, 1);
  }
}

/* Model initialize function */
void SimuDemonstrateurMoteur_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)SimuDemonstrateurMoteur_M, 0,
                sizeof(RT_MODEL_SimuDemonstrateurMoteu));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&SimuDemonstrateurMoteur_M->solverInfo,
                          &SimuDemonstrateurMoteur_M->Timing.simTimeStep);
    rtsiSetTPtr(&SimuDemonstrateurMoteur_M->solverInfo, &rtmGetTPtr
                (SimuDemonstrateurMoteur_M));
    rtsiSetStepSizePtr(&SimuDemonstrateurMoteur_M->solverInfo,
                       &SimuDemonstrateurMoteur_M->Timing.stepSize0);
    rtsiSetdXPtr(&SimuDemonstrateurMoteur_M->solverInfo,
                 &SimuDemonstrateurMoteur_M->ModelData.derivs);
    rtsiSetContStatesPtr(&SimuDemonstrateurMoteur_M->solverInfo,
                         &SimuDemonstrateurMoteur_M->ModelData.contStates);
    rtsiSetNumContStatesPtr(&SimuDemonstrateurMoteur_M->solverInfo,
      &SimuDemonstrateurMoteur_M->Sizes.numContStates);
    rtsiSetErrorStatusPtr(&SimuDemonstrateurMoteur_M->solverInfo,
                          (&rtmGetErrorStatus(SimuDemonstrateurMoteur_M)));
    rtsiSetRTModelPtr(&SimuDemonstrateurMoteur_M->solverInfo,
                      SimuDemonstrateurMoteur_M);
  }

  rtsiSetSimTimeStep(&SimuDemonstrateurMoteur_M->solverInfo, MAJOR_TIME_STEP);
  SimuDemonstrateurMoteur_M->ModelData.intgData.y =
    SimuDemonstrateurMoteur_M->ModelData.odeY;
  SimuDemonstrateurMoteur_M->ModelData.intgData.f[0] =
    SimuDemonstrateurMoteur_M->ModelData.odeF[0];
  SimuDemonstrateurMoteur_M->ModelData.intgData.f[1] =
    SimuDemonstrateurMoteur_M->ModelData.odeF[1];
  SimuDemonstrateurMoteur_M->ModelData.intgData.f[2] =
    SimuDemonstrateurMoteur_M->ModelData.odeF[2];
  SimuDemonstrateurMoteur_M->ModelData.intgData.f[3] =
    SimuDemonstrateurMoteur_M->ModelData.odeF[3];
  SimuDemonstrateurMoteur_M->ModelData.contStates = ((real_T *)
    &SimuDemonstrateurMoteur_X);
  rtsiSetSolverData(&SimuDemonstrateurMoteur_M->solverInfo, (void *)
                    &SimuDemonstrateurMoteur_M->ModelData.intgData);
  rtsiSetSolverName(&SimuDemonstrateurMoteur_M->solverInfo,"ode4");
  rtmSetTPtr(SimuDemonstrateurMoteur_M,
             &SimuDemonstrateurMoteur_M->Timing.tArray[0]);
  rtmSetTFinal(SimuDemonstrateurMoteur_M, 10.0);
  SimuDemonstrateurMoteur_M->Timing.stepSize0 = 0.2;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    SimuDemonstrateurMoteur_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(SimuDemonstrateurMoteur_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(SimuDemonstrateurMoteur_M->rtwLogInfo, (NULL));
    rtliSetLogT(SimuDemonstrateurMoteur_M->rtwLogInfo, "tout");
    rtliSetLogX(SimuDemonstrateurMoteur_M->rtwLogInfo, "");
    rtliSetLogXFinal(SimuDemonstrateurMoteur_M->rtwLogInfo, "");
    rtliSetSigLog(SimuDemonstrateurMoteur_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(SimuDemonstrateurMoteur_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(SimuDemonstrateurMoteur_M->rtwLogInfo, 0);
    rtliSetLogMaxRows(SimuDemonstrateurMoteur_M->rtwLogInfo, 1000);
    rtliSetLogDecimation(SimuDemonstrateurMoteur_M->rtwLogInfo, 1);
    rtliSetLogY(SimuDemonstrateurMoteur_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(SimuDemonstrateurMoteur_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(SimuDemonstrateurMoteur_M->rtwLogInfo, (NULL));
  }

  /* block I/O */
  (void) memset(((void *) &SimuDemonstrateurMoteur_B), 0,
                sizeof(BlockIO_SimuDemonstrateurMoteur));

  /* states (continuous) */
  {
    (void) memset((void *)&SimuDemonstrateurMoteur_X, 0,
                  sizeof(ContinuousStates_SimuDemonstrat));
  }

  /* states (dwork) */
  (void) memset((void *)&SimuDemonstrateurMoteur_DWork, 0,
                sizeof(D_Work_SimuDemonstrateurMoteur));

  /* Matfile logging */
  rt_StartDataLoggingWithStartTime(SimuDemonstrateurMoteur_M->rtwLogInfo, 0.0,
    rtmGetTFinal(SimuDemonstrateurMoteur_M),
    SimuDemonstrateurMoteur_M->Timing.stepSize0, (&rtmGetErrorStatus
    (SimuDemonstrateurMoteur_M)));

  /* InitializeConditions for StateSpace: '<S3>/Observateur ' */
  SimuDemonstrateurMoteur_X.Observateur_CSTATE[0] =
    SimuDemonstrateurMoteur_P.Observateur_X0;
  SimuDemonstrateurMoteur_X.Observateur_CSTATE[1] =
    SimuDemonstrateurMoteur_P.Observateur_X0;

  /* S-Function Block: <Root>/S-Function Builder */
  {
    real_T *xC = &SimuDemonstrateurMoteur_X.SFunctionBuilder_CSTATE[0];
    xC[0] = 0;
    xC[1] = 0;
    xC[2] = 0;
    xC[3] = 0;
  }
}

/* Model terminate function */
void SimuDemonstrateurMoteur_terminate(void)
{
}
