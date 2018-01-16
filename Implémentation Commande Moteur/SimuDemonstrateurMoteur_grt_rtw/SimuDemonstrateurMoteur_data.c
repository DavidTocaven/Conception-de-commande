/*
 * SimuDemonstrateurMoteur_data.c
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

/* Block parameters (auto storage) */
Parameters_SimuDemonstrateurMot SimuDemonstrateurMoteur_P = {
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Constant'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<Root>/Signal Generator'
                                        */
  0.2,                                 /* Expression: 0.2
                                        * Referenced by: '<Root>/Signal Generator'
                                        */
  3.0,                                 /* Expression: 3
                                        * Referenced by: '<Root>/Gain'
                                        */
  1.5106205747605161,                  /* Expression: 1/EE2_bf.gain
                                        * Referenced by: '<S2>/N '
                                        */

  /*  Computed Parameter: Observateur_A
   * Referenced by: '<S3>/Observateur '
   */
  { -5.0493843798523832, 1.0, -0.051823196825787676, -3.9506156201476168 },

  /*  Computed Parameter: Observateur_B
   * Referenced by: '<S3>/Observateur '
   */
  { 4.5444459418671448, 0.046640877143208907, 56.741108354011587 },

  /*  Computed Parameter: Observateur_C
   * Referenced by: '<S3>/Observateur '
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S3>/Observateur '
                                        */
  0.088989879230926078,                /* Expression: K(2)
                                        * Referenced by: '<S2>/retourEE0'
                                        */
  6.2,                                 /* Expression: R
                                        * Referenced by: '<Root>/S-Function Builder'
                                        */
  0.0008,                              /* Expression: L
                                        * Referenced by: '<Root>/S-Function Builder'
                                        */
  0.034377467707849392,                /* Expression: Ke
                                        * Referenced by: '<Root>/S-Function Builder'
                                        */
  0.035,                               /* Expression: Kc
                                        * Referenced by: '<Root>/S-Function Builder'
                                        */
  0.00019897959183673468,              /* Expression: mu
                                        * Referenced by: '<Root>/S-Function Builder'
                                        */
  9.9489795918367342E-5,               /* Expression: J2
                                        * Referenced by: '<Root>/S-Function Builder'
                                        */
  0.0003,                              /* Expression: Cn
                                        * Referenced by: '<Root>/S-Function Builder'
                                        */
  0.00015,                             /* Expression: rCn
                                        * Referenced by: '<Root>/S-Function Builder'
                                        */
  0.19704733751348225,                 /* Expression: 2*rand(1)-1
                                        * Referenced by: '<Root>/S-Function Builder'
                                        */
  10.0,                                /* Expression: Ks
                                        * Referenced by: '<Root>/S-Function Builder'
                                        */
  0.1111111111111111,                  /* Expression: Kr
                                        * Referenced by: '<Root>/S-Function Builder'
                                        */
  0.105,                               /* Expression: Kg
                                        * Referenced by: '<Root>/S-Function Builder'
                                        */
  0.01,                                /* Expression: 0.01
                                        * Referenced by: '<Root>/S-Function Builder'
                                        */
  100.0,                               /* Expression: Rchn
                                        * Referenced by: '<Root>/S-Function Builder'
                                        */
  0.5,                                 /* Expression: rRch
                                        * Referenced by: '<Root>/S-Function Builder'
                                        */
  -0.058151487283331971,               /* Expression: 2*rand(1)-1
                                        * Referenced by: '<Root>/S-Function Builder'
                                        */

  /*  Expression: EE2.ee.c
   * Referenced by: '<S3>/Gain'
   */
  { 0.0, 1.1111111111111112, 0.105, 0.0 }
};
