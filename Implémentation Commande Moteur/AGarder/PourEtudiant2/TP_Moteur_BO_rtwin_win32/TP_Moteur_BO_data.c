/*
 * TP_Moteur_BO_data.c
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

/* Block parameters (auto storage) */
Parameters_TP_Moteur_BO TP_Moteur_BO_P = {
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S3>/Integrator'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Constant1'
                                        */
  10.0,                                /* Expression: MaxMissedTicks
                                        * Referenced by: '<S1>/Analog Output'
                                        */
  0.0,                                 /* Expression: YieldWhenWaiting
                                        * Referenced by: '<S1>/Analog Output'
                                        */
  10.0,                                /* Expression: MaxMissedTicks
                                        * Referenced by: '<S1>/Analog Input'
                                        */
  0.0,                                 /* Expression: YieldWhenWaiting
                                        * Referenced by: '<S1>/Analog Input'
                                        */
  2.0,                                 /* Expression: 2
                                        * Referenced by: '<Root>/Signal Generator1'
                                        */
  0.1,                                 /* Expression: 0.1
                                        * Referenced by: '<Root>/Signal Generator1'
                                        */
  2.0,                                 /* Expression: 2
                                        * Referenced by: '<Root>/Constant'
                                        */
  0.5,                                 /* Expression: 0.5
                                        * Referenced by: '<Root>/Ke'
                                        */

  /*  Computed Parameter: Observateur_A
   * Referenced by: '<S4>/Observateur '
   */
  { -5.0493843798523832, 1.0, -0.051823196825787676, -3.9506156201476168 },

  /*  Computed Parameter: Observateur_B
   * Referenced by: '<S4>/Observateur '
   */
  { 4.5444459418671448, 0.046640877143208907, 56.741108354011587 },

  /*  Computed Parameter: Observateur_C
   * Referenced by: '<S4>/Observateur '
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S4>/Observateur '
                                        */

  /*  Expression: EE2.ee.c
   * Referenced by: '<S4>/Gain'
   */
  { 0.0, 1.1111111111111112, 0.105, 0.0 },
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S3>/N '
                                        */
  0.088989879230926078,                /* Expression: K(2)
                                        * Referenced by: '<S3>/retourEE0'
                                        */
  -1.0,                                /* Computed Parameter: TransferFcn_A
                                        * Referenced by: '<S3>/Transfer Fcn'
                                        */
  1.0,                                 /* Computed Parameter: TransferFcn_C
                                        * Referenced by: '<S3>/Transfer Fcn'
                                        */
  0,                                   /* Expression: Channels
                                        * Referenced by: '<S1>/Analog Output'
                                        */
  0,                                   /* Expression: RangeMode
                                        * Referenced by: '<S1>/Analog Output'
                                        */
  0,                                   /* Expression: VoltRange
                                        * Referenced by: '<S1>/Analog Output'
                                        */

  /*  Expression: Channels
   * Referenced by: '<S1>/Analog Input'
   */
  { 0, 2 },
  0,                                   /* Expression: RangeMode
                                        * Referenced by: '<S1>/Analog Input'
                                        */
  0,                                   /* Expression: VoltRange
                                        * Referenced by: '<S1>/Analog Input'
                                        */
  0U                                   /* Computed Parameter: ManualSwitch_CurrentSetting
                                        * Referenced by: '<Root>/Manual Switch'
                                        */
};
