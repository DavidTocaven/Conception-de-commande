/*
 * SimuDemonstrateurMoteur.h
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
#ifndef RTW_HEADER_SimuDemonstrateurMoteur_h_
#define RTW_HEADER_SimuDemonstrateurMoteur_h_
#ifndef SimuDemonstrateurMoteur_COMMON_INCLUDES_
# define SimuDemonstrateurMoteur_COMMON_INCLUDES_
#include <float.h>
#include <stddef.h>
#include <math.h>
#include <string.h>
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "rt_logging.h"
#include "rt_nonfinite.h"
#endif                                 /* SimuDemonstrateurMoteur_COMMON_INCLUDES_ */

#include "SimuDemonstrateurMoteur_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
# define rtmGetFinalTime(rtm)          ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWLogInfo
# define rtmGetRTWLogInfo(rtm)         ((rtm)->rtwLogInfo)
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTFinal
# define rtmGetTFinal(rtm)             ((rtm)->Timing.tFinal)
#endif

/* Block signals (auto storage) */
typedef struct {
  real_T Gain;                         /* '<Root>/Gain' */
  real_T Sum;                          /* '<S2>/Sum' */
  real_T SFunctionBuilder_o1;          /* '<Root>/S-Function Builder' */
  real_T SFunctionBuilder_o2;          /* '<Root>/S-Function Builder' */
  real_T Sum_d[2];                     /* '<S3>/Sum' */
} BlockIO_SimuDemonstrateurMoteur;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  struct {
    void *LoggedData;
  } Scope_PWORK;                       /* '<Root>/Scope' */

  struct {
    void *LoggedData;
  } ref_PWORK;                         /* '<Root>/ref' */

  struct {
    void *LoggedData;
  } ref1_PWORK;                        /* '<S1>/ref1' */

  struct {
    void *LoggedData;
  } ObservateurEtat_PWORK;             /* '<S3>/Observateur Etat  ' */

  struct {
    void *LoggedData;
  } Scope_PWORK_b;                     /* '<S3>/Scope' */

  struct {
    void *LoggedData;
  } Scope1_PWORK;                      /* '<S3>/Scope1' */
} D_Work_SimuDemonstrateurMoteur;

/* Continuous states (auto storage) */
typedef struct {
  real_T Observateur_CSTATE[2];        /* '<S3>/Observateur ' */
  real_T SFunctionBuilder_CSTATE[4];   /* '<Root>/S-Function Builder' */
} ContinuousStates_SimuDemonstrat;

/* State derivatives (auto storage) */
typedef struct {
  real_T Observateur_CSTATE[2];        /* '<S3>/Observateur ' */
  real_T SFunctionBuilder_CSTATE[4];   /* '<Root>/S-Function Builder' */
} StateDerivatives_SimuDemonstrat;

/* State disabled  */
typedef struct {
  boolean_T Observateur_CSTATE[2];     /* '<S3>/Observateur ' */
  boolean_T SFunctionBuilder_CSTATE[4];/* '<Root>/S-Function Builder' */
} StateDisabled_SimuDemonstrateur;

#ifndef ODE4_INTG
#define ODE4_INTG

/* ODE4 Integration Data */
typedef struct {
  real_T *y;                           /* output */
  real_T *f[4];                        /* derivatives */
} ODE4_IntgData;

#endif

/* Parameters (auto storage) */
struct Parameters_SimuDemonstrateurMot_ {
  real_T Constant_Value;               /* Expression: 0
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T SignalGenerator_Amplitude;    /* Expression: 1
                                        * Referenced by: '<Root>/Signal Generator'
                                        */
  real_T SignalGenerator_Frequency;    /* Expression: 0.2
                                        * Referenced by: '<Root>/Signal Generator'
                                        */
  real_T Gain_Gain;                    /* Expression: 3
                                        * Referenced by: '<Root>/Gain'
                                        */
  real_T N_Gain;                       /* Expression: 1/EE2_bf.gain
                                        * Referenced by: '<S2>/N '
                                        */
  real_T Observateur_A[4];             /* Computed Parameter: Observateur_A
                                        * Referenced by: '<S3>/Observateur '
                                        */
  real_T Observateur_B[3];             /* Computed Parameter: Observateur_B
                                        * Referenced by: '<S3>/Observateur '
                                        */
  real_T Observateur_C[2];             /* Computed Parameter: Observateur_C
                                        * Referenced by: '<S3>/Observateur '
                                        */
  real_T Observateur_X0;               /* Expression: 0
                                        * Referenced by: '<S3>/Observateur '
                                        */
  real_T retourEE0_Gain;               /* Expression: K(2)
                                        * Referenced by: '<S2>/retourEE0'
                                        */
  real_T SFunctionBuilder_P1;          /* Expression: R
                                        * Referenced by: '<Root>/S-Function Builder'
                                        */
  real_T SFunctionBuilder_P2;          /* Expression: L
                                        * Referenced by: '<Root>/S-Function Builder'
                                        */
  real_T SFunctionBuilder_P3;          /* Expression: Ke
                                        * Referenced by: '<Root>/S-Function Builder'
                                        */
  real_T SFunctionBuilder_P4;          /* Expression: Kc
                                        * Referenced by: '<Root>/S-Function Builder'
                                        */
  real_T SFunctionBuilder_P5;          /* Expression: mu
                                        * Referenced by: '<Root>/S-Function Builder'
                                        */
  real_T SFunctionBuilder_P6;          /* Expression: J2
                                        * Referenced by: '<Root>/S-Function Builder'
                                        */
  real_T SFunctionBuilder_P7;          /* Expression: Cn
                                        * Referenced by: '<Root>/S-Function Builder'
                                        */
  real_T SFunctionBuilder_P8;          /* Expression: rCn
                                        * Referenced by: '<Root>/S-Function Builder'
                                        */
  real_T SFunctionBuilder_P9;          /* Expression: 2*rand(1)-1
                                        * Referenced by: '<Root>/S-Function Builder'
                                        */
  real_T SFunctionBuilder_P10;         /* Expression: Ks
                                        * Referenced by: '<Root>/S-Function Builder'
                                        */
  real_T SFunctionBuilder_P11;         /* Expression: Kr
                                        * Referenced by: '<Root>/S-Function Builder'
                                        */
  real_T SFunctionBuilder_P12;         /* Expression: Kg
                                        * Referenced by: '<Root>/S-Function Builder'
                                        */
  real_T SFunctionBuilder_P13;         /* Expression: 0.01
                                        * Referenced by: '<Root>/S-Function Builder'
                                        */
  real_T SFunctionBuilder_P14;         /* Expression: Rchn
                                        * Referenced by: '<Root>/S-Function Builder'
                                        */
  real_T SFunctionBuilder_P15;         /* Expression: rRch
                                        * Referenced by: '<Root>/S-Function Builder'
                                        */
  real_T SFunctionBuilder_P16;         /* Expression: 2*rand(1)-1
                                        * Referenced by: '<Root>/S-Function Builder'
                                        */
  real_T Gain_Gain_m[4];               /* Expression: EE2.ee.c
                                        * Referenced by: '<S3>/Gain'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_SimuDemonstrateurMoteur {
  const char_T *errorStatus;
  RTWLogInfo *rtwLogInfo;
  RTWSolverInfo solverInfo;

  /*
   * ModelData:
   * The following substructure contains information regarding
   * the data used in the model.
   */
  struct {
    real_T *contStates;
    real_T *derivs;
    boolean_T *contStateDisabled;
    boolean_T zCCacheNeedsReset;
    boolean_T derivCacheNeedsReset;
    boolean_T blkStateChange;
    real_T odeY[6];
    real_T odeF[4][6];
    ODE4_IntgData intgData;
  } ModelData;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    int_T numContStates;
    int_T numSampTimes;
  } Sizes;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    time_T tFinal;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Block parameters (auto storage) */
extern Parameters_SimuDemonstrateurMot SimuDemonstrateurMoteur_P;

/* Block signals (auto storage) */
extern BlockIO_SimuDemonstrateurMoteur SimuDemonstrateurMoteur_B;

/* Continuous states (auto storage) */
extern ContinuousStates_SimuDemonstrat SimuDemonstrateurMoteur_X;

/* Block states (auto storage) */
extern D_Work_SimuDemonstrateurMoteur SimuDemonstrateurMoteur_DWork;

/* Model entry point functions */
extern void SimuDemonstrateurMoteur_initialize(void);
extern void SimuDemonstrateurMoteur_step(void);
extern void SimuDemonstrateurMoteur_terminate(void);

/* Real-time Model object */
extern RT_MODEL_SimuDemonstrateurMoteu *const SimuDemonstrateurMoteur_M;

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
 * '<Root>' : 'SimuDemonstrateurMoteur'
 * '<S1>'   : 'SimuDemonstrateurMoteur/Subsystem'
 * '<S2>'   : 'SimuDemonstrateurMoteur/Subsystem/Commande '
 * '<S3>'   : 'SimuDemonstrateurMoteur/Subsystem/Observator'
 */
#endif                                 /* RTW_HEADER_SimuDemonstrateurMoteur_h_ */
