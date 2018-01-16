/*
 * TP_Moteur_BO.c
 *
 * Code generation for model "TP_Moteur_BO".
 *
 * Model version              : 1.9
 * Simulink Coder version : 8.3 (R2012b) 20-Jul-2012
 * C source code generated on : Thu Dec 14 08:54:06 2017
 *
 * Target selection: rtwin.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->32-bit x86 compatible
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#include "TP_Moteur_BO.h"
#include "TP_Moteur_BO_private.h"
#include "TP_Moteur_BO_dt.h"

/* options for Real-Time Windows Target board 0 */
static double RTWinBoardOptions0[] = {
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
};

/* list of Real-Time Windows Target timers */
const int RTWinTimerCount = 1;
const double RTWinTimers[2] = {
  0.003, 0.0,
};

/* list of Real-Time Windows Target boards */
const int RTWinBoardCount = 1;
RTWINBOARD RTWinBoards[1] = {
  { "National_Instruments/PCI-6024E", 0U, 6, RTWinBoardOptions0 },
};

/* Block signals (auto storage) */
BlockIO_TP_Moteur_BO TP_Moteur_BO_B;

/* Continuous states */
ContinuousStates_TP_Moteur_BO TP_Moteur_BO_X;

/* Block states (auto storage) */
D_Work_TP_Moteur_BO TP_Moteur_BO_DWork;

/* Real-time model */
RT_MODEL_TP_Moteur_BO TP_Moteur_BO_M_;
RT_MODEL_TP_Moteur_BO *const TP_Moteur_BO_M = &TP_Moteur_BO_M_;

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
  int_T nXc = 4;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  TP_Moteur_BO_derivatives();

  /* f1 = f(t + (h/2), y + (h/2)*f0) */
  temp = 0.5 * h;
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (temp*f0[i]);
  }

  rtsiSetT(si, t + temp);
  rtsiSetdX(si, f1);
  TP_Moteur_BO_output();
  TP_Moteur_BO_derivatives();

  /* f2 = f(t + (h/2), y + (h/2)*f1) */
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (temp*f1[i]);
  }

  rtsiSetdX(si, f2);
  TP_Moteur_BO_output();
  TP_Moteur_BO_derivatives();

  /* f3 = f(t + h, y + h*f2) */
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (h*f2[i]);
  }

  rtsiSetT(si, tnew);
  rtsiSetdX(si, f3);
  TP_Moteur_BO_output();
  TP_Moteur_BO_derivatives();

  /* tnew = t + h
     ynew = y + (h/6)*(f0 + 2*f1 + 2*f2 + 2*f3) */
  temp = h / 6.0;
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + temp*(f0[i] + 2.0*f1[i] + 2.0*f2[i] + f3[i]);
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model output function */
void TP_Moteur_BO_output(void)
{
  /* local block i/o variables */
  real_T rtb_TransferFcn;
  real_T rtb_Observateur[2];
  real_T temp;
  if (rtmIsMajorTimeStep(TP_Moteur_BO_M)) {
    /* set solver stop time */
    if (!(TP_Moteur_BO_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&TP_Moteur_BO_M->solverInfo,
                            ((TP_Moteur_BO_M->Timing.clockTickH0 + 1) *
        TP_Moteur_BO_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&TP_Moteur_BO_M->solverInfo,
                            ((TP_Moteur_BO_M->Timing.clockTick0 + 1) *
        TP_Moteur_BO_M->Timing.stepSize0 + TP_Moteur_BO_M->Timing.clockTickH0 *
        TP_Moteur_BO_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(TP_Moteur_BO_M)) {
    TP_Moteur_BO_M->Timing.t[0] = rtsiGetT(&TP_Moteur_BO_M->solverInfo);
  }

  /* Integrator: '<S3>/Integrator' */
  TP_Moteur_BO_B.Integrator = TP_Moteur_BO_X.Integrator_CSTATE;

  /* ManualSwitch: '<Root>/Manual Switch' incorporates:
   *  Constant: '<Root>/Constant1'
   */
  if (TP_Moteur_BO_P.ManualSwitch_CurrentSetting == 1) {
    TP_Moteur_BO_B.ManualSwitch = TP_Moteur_BO_B.Integrator;
  } else {
    TP_Moteur_BO_B.ManualSwitch = TP_Moteur_BO_P.Constant1_Value;
  }

  /* End of ManualSwitch: '<Root>/Manual Switch' */
  if (rtmIsMajorTimeStep(TP_Moteur_BO_M)) {
    /* S-Function Block: <S1>/Analog Output */
    {
      {
        ANALOGIOPARM parm;
        parm.mode = (RANGEMODE) TP_Moteur_BO_P.AnalogOutput_RangeMode;
        parm.rangeidx = TP_Moteur_BO_P.AnalogOutput_VoltRange;
        RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1,
                       &TP_Moteur_BO_P.AnalogOutput_Channels,
                       &TP_Moteur_BO_B.ManualSwitch, &parm);
      }
    }

    /* S-Function Block: <S1>/Analog Input */
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE) TP_Moteur_BO_P.AnalogInput_RangeMode;
      parm.rangeidx = TP_Moteur_BO_P.AnalogInput_VoltRange;
      RTBIO_DriverIO(0, ANALOGINPUT, IOREAD, 2,
                     TP_Moteur_BO_P.AnalogInput_Channels,
                     TP_Moteur_BO_B.AnalogInput, &parm);
    }
  }

  /* SignalGenerator: '<Root>/Signal Generator1' */
  temp = TP_Moteur_BO_P.SignalGenerator1_Frequency * TP_Moteur_BO_M->Timing.t[0];
  if (temp - floor(temp) >= 0.5) {
    temp = TP_Moteur_BO_P.SignalGenerator1_Amplitude;
  } else {
    temp = -TP_Moteur_BO_P.SignalGenerator1_Amplitude;
  }

  /* End of SignalGenerator: '<Root>/Signal Generator1' */

  /* Gain: '<Root>/Ke' incorporates:
   *  Constant: '<Root>/Constant'
   *  Sum: '<Root>/Sum'
   */
  TP_Moteur_BO_B.Ke = (temp + TP_Moteur_BO_P.Constant_Value) *
    TP_Moteur_BO_P.Ke_Gain;
  if (rtmIsMajorTimeStep(TP_Moteur_BO_M)) {
  }

  /* StateSpace: '<S4>/Observateur ' */
  {
    rtb_Observateur[0] = (TP_Moteur_BO_P.Observateur_C[0])*
      TP_Moteur_BO_X.Observateur_CSTATE[0];
    rtb_Observateur[1] = (TP_Moteur_BO_P.Observateur_C[1])*
      TP_Moteur_BO_X.Observateur_CSTATE[1];
  }

  /* Sum: '<S4>/Sum' incorporates:
   *  Gain: '<S4>/Gain'
   */
  TP_Moteur_BO_B.Sum[0] = 0.0 - (TP_Moteur_BO_P.Gain_Gain[0] * rtb_Observateur[0]
    + TP_Moteur_BO_P.Gain_Gain[2] * rtb_Observateur[1]);
  TP_Moteur_BO_B.Sum[1] = 0.0 - (TP_Moteur_BO_P.Gain_Gain[1] * rtb_Observateur[0]
    + TP_Moteur_BO_P.Gain_Gain[3] * rtb_Observateur[1]);
  if (rtmIsMajorTimeStep(TP_Moteur_BO_M)) {
  }

  /* Sum: '<S3>/Sum' incorporates:
   *  Gain: '<S3>/N '
   *  Gain: '<S3>/retourEE0'
   */
  TP_Moteur_BO_B.Sum_m = TP_Moteur_BO_P.N_Gain * TP_Moteur_BO_B.Ke -
    TP_Moteur_BO_P.retourEE0_Gain * rtb_Observateur[1];

  /* TransferFcn: '<S3>/Transfer Fcn' */
  rtb_TransferFcn = TP_Moteur_BO_P.TransferFcn_C*
    TP_Moteur_BO_X.TransferFcn_CSTATE;
  if (rtmIsMajorTimeStep(TP_Moteur_BO_M)) {
  }
}

/* Model update function */
void TP_Moteur_BO_update(void)
{
  if (rtmIsMajorTimeStep(TP_Moteur_BO_M)) {
    rt_ertODEUpdateContinuousStates(&TP_Moteur_BO_M->solverInfo);
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++TP_Moteur_BO_M->Timing.clockTick0)) {
    ++TP_Moteur_BO_M->Timing.clockTickH0;
  }

  TP_Moteur_BO_M->Timing.t[0] = rtsiGetSolverStopTime
    (&TP_Moteur_BO_M->solverInfo);

  {
    /* Update absolute timer for sample time: [0.003s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick1"
     * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++TP_Moteur_BO_M->Timing.clockTick1)) {
      ++TP_Moteur_BO_M->Timing.clockTickH1;
    }

    TP_Moteur_BO_M->Timing.t[1] = TP_Moteur_BO_M->Timing.clockTick1 *
      TP_Moteur_BO_M->Timing.stepSize1 + TP_Moteur_BO_M->Timing.clockTickH1 *
      TP_Moteur_BO_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Derivatives for root system: '<Root>' */
void TP_Moteur_BO_derivatives(void)
{
  /* Derivatives for Integrator: '<S3>/Integrator' */
  ((StateDerivatives_TP_Moteur_BO *) TP_Moteur_BO_M->ModelData.derivs)
    ->Integrator_CSTATE = TP_Moteur_BO_B.Sum_m;

  /* Derivatives for StateSpace: '<S4>/Observateur ' */
  {
    ((StateDerivatives_TP_Moteur_BO *) TP_Moteur_BO_M->ModelData.derivs)
      ->Observateur_CSTATE[0] = (TP_Moteur_BO_P.Observateur_A[0])*
      TP_Moteur_BO_X.Observateur_CSTATE[0]
      + (TP_Moteur_BO_P.Observateur_A[1])*TP_Moteur_BO_X.Observateur_CSTATE[1];
    ((StateDerivatives_TP_Moteur_BO *) TP_Moteur_BO_M->ModelData.derivs)
      ->Observateur_CSTATE[0] += (TP_Moteur_BO_P.Observateur_B[0])*
      TP_Moteur_BO_B.AnalogInput[0];
    ((StateDerivatives_TP_Moteur_BO *) TP_Moteur_BO_M->ModelData.derivs)
      ->Observateur_CSTATE[1] = (TP_Moteur_BO_P.Observateur_A[2])*
      TP_Moteur_BO_X.Observateur_CSTATE[0]
      + (TP_Moteur_BO_P.Observateur_A[3])*TP_Moteur_BO_X.Observateur_CSTATE[1];
    ((StateDerivatives_TP_Moteur_BO *) TP_Moteur_BO_M->ModelData.derivs)
      ->Observateur_CSTATE[1] += (TP_Moteur_BO_P.Observateur_B[1])*
      TP_Moteur_BO_B.AnalogInput[0]
      + (TP_Moteur_BO_P.Observateur_B[2])*TP_Moteur_BO_B.Integrator;
  }

  /* Derivatives for TransferFcn: '<S3>/Transfer Fcn' */
  {
    ((StateDerivatives_TP_Moteur_BO *) TP_Moteur_BO_M->ModelData.derivs)
      ->TransferFcn_CSTATE = 0.0;
    ((StateDerivatives_TP_Moteur_BO *) TP_Moteur_BO_M->ModelData.derivs)
      ->TransferFcn_CSTATE += (TP_Moteur_BO_P.TransferFcn_A)*
      TP_Moteur_BO_X.TransferFcn_CSTATE;
  }
}

/* Model initialize function */
void TP_Moteur_BO_initialize(void)
{
  /* S-Function Block: <S1>/Analog Output */

  /* no initial value should be set */

  /* InitializeConditions for Integrator: '<S3>/Integrator' */
  TP_Moteur_BO_X.Integrator_CSTATE = TP_Moteur_BO_P.Integrator_IC;

  /* InitializeConditions for StateSpace: '<S4>/Observateur ' */
  TP_Moteur_BO_X.Observateur_CSTATE[0] = TP_Moteur_BO_P.Observateur_X0;
  TP_Moteur_BO_X.Observateur_CSTATE[1] = TP_Moteur_BO_P.Observateur_X0;

  /* InitializeConditions for TransferFcn: '<S3>/Transfer Fcn' */
  TP_Moteur_BO_X.TransferFcn_CSTATE = 0.0;
}

/* Model terminate function */
void TP_Moteur_BO_terminate(void)
{
  /* S-Function Block: <S1>/Analog Output */

  /* no final value should be set */
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/

/* Solver interface called by GRT_Main */
#ifndef USE_GENERATED_SOLVER

void rt_ODECreateIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEDestroyIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEUpdateContinuousStates(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

#endif

void MdlOutputs(int_T tid)
{
  TP_Moteur_BO_output();

  /* tid is required for a uniform function interface.
   * Argument tid is not used in the function. */
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  TP_Moteur_BO_update();

  /* tid is required for a uniform function interface.
   * Argument tid is not used in the function. */
  UNUSED_PARAMETER(tid);
}

void MdlInitializeSizes(void)
{
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
}

void MdlStart(void)
{
  TP_Moteur_BO_initialize();
}

void MdlTerminate(void)
{
  TP_Moteur_BO_terminate();
}

RT_MODEL_TP_Moteur_BO *TP_Moteur_BO(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)TP_Moteur_BO_M, 0,
                sizeof(RT_MODEL_TP_Moteur_BO));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&TP_Moteur_BO_M->solverInfo,
                          &TP_Moteur_BO_M->Timing.simTimeStep);
    rtsiSetTPtr(&TP_Moteur_BO_M->solverInfo, &rtmGetTPtr(TP_Moteur_BO_M));
    rtsiSetStepSizePtr(&TP_Moteur_BO_M->solverInfo,
                       &TP_Moteur_BO_M->Timing.stepSize0);
    rtsiSetdXPtr(&TP_Moteur_BO_M->solverInfo, &TP_Moteur_BO_M->ModelData.derivs);
    rtsiSetContStatesPtr(&TP_Moteur_BO_M->solverInfo,
                         &TP_Moteur_BO_M->ModelData.contStates);
    rtsiSetNumContStatesPtr(&TP_Moteur_BO_M->solverInfo,
      &TP_Moteur_BO_M->Sizes.numContStates);
    rtsiSetErrorStatusPtr(&TP_Moteur_BO_M->solverInfo, (&rtmGetErrorStatus
      (TP_Moteur_BO_M)));
    rtsiSetRTModelPtr(&TP_Moteur_BO_M->solverInfo, TP_Moteur_BO_M);
  }

  rtsiSetSimTimeStep(&TP_Moteur_BO_M->solverInfo, MAJOR_TIME_STEP);
  TP_Moteur_BO_M->ModelData.intgData.y = TP_Moteur_BO_M->ModelData.odeY;
  TP_Moteur_BO_M->ModelData.intgData.f[0] = TP_Moteur_BO_M->ModelData.odeF[0];
  TP_Moteur_BO_M->ModelData.intgData.f[1] = TP_Moteur_BO_M->ModelData.odeF[1];
  TP_Moteur_BO_M->ModelData.intgData.f[2] = TP_Moteur_BO_M->ModelData.odeF[2];
  TP_Moteur_BO_M->ModelData.intgData.f[3] = TP_Moteur_BO_M->ModelData.odeF[3];
  TP_Moteur_BO_M->ModelData.contStates = ((real_T *) &TP_Moteur_BO_X);
  rtsiSetSolverData(&TP_Moteur_BO_M->solverInfo, (void *)
                    &TP_Moteur_BO_M->ModelData.intgData);
  rtsiSetSolverName(&TP_Moteur_BO_M->solverInfo,"ode4");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = TP_Moteur_BO_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    TP_Moteur_BO_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    TP_Moteur_BO_M->Timing.sampleTimes =
      (&TP_Moteur_BO_M->Timing.sampleTimesArray[0]);
    TP_Moteur_BO_M->Timing.offsetTimes =
      (&TP_Moteur_BO_M->Timing.offsetTimesArray[0]);

    /* task periods */
    TP_Moteur_BO_M->Timing.sampleTimes[0] = (0.0);
    TP_Moteur_BO_M->Timing.sampleTimes[1] = (0.003);

    /* task offsets */
    TP_Moteur_BO_M->Timing.offsetTimes[0] = (0.0);
    TP_Moteur_BO_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(TP_Moteur_BO_M, &TP_Moteur_BO_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = TP_Moteur_BO_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    TP_Moteur_BO_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(TP_Moteur_BO_M, 9999.0);
  TP_Moteur_BO_M->Timing.stepSize0 = 0.003;
  TP_Moteur_BO_M->Timing.stepSize1 = 0.003;

  /* External mode info */
  TP_Moteur_BO_M->Sizes.checksums[0] = (3727079594U);
  TP_Moteur_BO_M->Sizes.checksums[1] = (2395913382U);
  TP_Moteur_BO_M->Sizes.checksums[2] = (217121089U);
  TP_Moteur_BO_M->Sizes.checksums[3] = (35044031U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    TP_Moteur_BO_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(TP_Moteur_BO_M->extModeInfo,
      &TP_Moteur_BO_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(TP_Moteur_BO_M->extModeInfo,
                        TP_Moteur_BO_M->Sizes.checksums);
    rteiSetTPtr(TP_Moteur_BO_M->extModeInfo, rtmGetTPtr(TP_Moteur_BO_M));
  }

  TP_Moteur_BO_M->solverInfoPtr = (&TP_Moteur_BO_M->solverInfo);
  TP_Moteur_BO_M->Timing.stepSize = (0.003);
  rtsiSetFixedStepSize(&TP_Moteur_BO_M->solverInfo, 0.003);
  rtsiSetSolverMode(&TP_Moteur_BO_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  TP_Moteur_BO_M->ModelData.blockIO = ((void *) &TP_Moteur_BO_B);
  (void) memset(((void *) &TP_Moteur_BO_B), 0,
                sizeof(BlockIO_TP_Moteur_BO));

  /* parameters */
  TP_Moteur_BO_M->ModelData.defaultParam = ((real_T *)&TP_Moteur_BO_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &TP_Moteur_BO_X;
    TP_Moteur_BO_M->ModelData.contStates = (x);
    (void) memset((void *)&TP_Moteur_BO_X, 0,
                  sizeof(ContinuousStates_TP_Moteur_BO));
  }

  /* states (dwork) */
  TP_Moteur_BO_M->Work.dwork = ((void *) &TP_Moteur_BO_DWork);
  (void) memset((void *)&TP_Moteur_BO_DWork, 0,
                sizeof(D_Work_TP_Moteur_BO));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    TP_Moteur_BO_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 14;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.B = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.P = &rtPTransTable;
  }

  /* Initialize Sizes */
  TP_Moteur_BO_M->Sizes.numContStates = (4);/* Number of continuous states */
  TP_Moteur_BO_M->Sizes.numY = (0);    /* Number of model outputs */
  TP_Moteur_BO_M->Sizes.numU = (0);    /* Number of model inputs */
  TP_Moteur_BO_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  TP_Moteur_BO_M->Sizes.numSampTimes = (2);/* Number of sample times */
  TP_Moteur_BO_M->Sizes.numBlocks = (21);/* Number of blocks */
  TP_Moteur_BO_M->Sizes.numBlockIO = (6);/* Number of block outputs */
  TP_Moteur_BO_M->Sizes.numBlockPrms = (36);/* Sum of parameter "widths" */
  return TP_Moteur_BO_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
