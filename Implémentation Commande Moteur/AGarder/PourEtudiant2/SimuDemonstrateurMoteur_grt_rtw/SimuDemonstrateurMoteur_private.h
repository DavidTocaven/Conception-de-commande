/*
 * SimuDemonstrateurMoteur_private.h
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
#ifndef RTW_HEADER_SimuDemonstrateurMoteur_private_h_
#define RTW_HEADER_SimuDemonstrateurMoteur_private_h_
#include "rtwtypes.h"

/* Private macros used by the generated code to access rtModel */
#ifndef rtmIsMajorTimeStep
# define rtmIsMajorTimeStep(rtm)       (((rtm)->Timing.simTimeStep) == MAJOR_TIME_STEP)
#endif

#ifndef rtmIsMinorTimeStep
# define rtmIsMinorTimeStep(rtm)       (((rtm)->Timing.simTimeStep) == MINOR_TIME_STEP)
#endif

#ifndef rtmSetTFinal
# define rtmSetTFinal(rtm, val)        ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               ((rtm)->Timing.t)
#endif

#ifndef rtmSetTPtr
# define rtmSetTPtr(rtm, val)          ((rtm)->Timing.t = (val))
#endif

#ifndef __RTWTYPES_H__
#error This file requires rtwtypes.h to be included
#else
#ifdef TMWTYPES_PREVIOUSLY_INCLUDED
#error This file requires rtwtypes.h to be included before tmwtypes.h
#else

/* Check for inclusion of an incorrect version of rtwtypes.h */
#ifndef RTWTYPES_ID_C08S16I32L32N32F1
#error This code was generated with a different "rtwtypes.h" than the file included
#endif                                 /* RTWTYPES_ID_C08S16I32L32N32F1 */
#endif                                 /* TMWTYPES_PREVIOUSLY_INCLUDED */
#endif                                 /* __RTWTYPES_H__ */

extern void ModeleDemonstrateurMoteur_Outputs_wrapper(const real_T *Vm,
  real_T *Vs,
  real_T *Vg ,
  const real_T *xC,
  const real_T *R, const int_T p_width0,
  const real_T *L, const int_T p_width1,
  const real_T *Ke, const int_T p_width2,
  const real_T *Kc, const int_T p_width3,
  const real_T *mu, const int_T p_width4,
  const real_T *J, const int_T p_width5,
  const real_T *Cn, const int_T p_width6,
  const real_T *rCn, const int_T p_width7,
  const real_T *Delta1, const int_T p_width8,
  const real_T *Ks, const int_T p_width9,
  const real_T *Kr, const int_T p_width10,
  const real_T *Kg, const int_T p_width11,
  const real_T *Znmrt, const int_T p_width12,
  const real_T *Rchn, const int_T p_width13,
  const real_T *rRch, const int_T p_width14,
  const real_T *Delta2, const int_T p_width15);
extern void ModeleDemonstrateurMoteur_Derivatives_wrapper(const real_T *Vm,
  const real_T *Vs,
  const real_T *Vg,
  real_T *dx ,
  real_T *xC,
  const real_T *R, const int_T p_width0,
  const real_T *L, const int_T p_width1,
  const real_T *Ke, const int_T p_width2,
  const real_T *Kc, const int_T p_width3,
  const real_T *mu, const int_T p_width4,
  const real_T *J, const int_T p_width5,
  const real_T *Cn, const int_T p_width6,
  const real_T *rCn, const int_T p_width7,
  const real_T *Delta1, const int_T p_width8,
  const real_T *Ks, const int_T p_width9,
  const real_T *Kr, const int_T p_width10,
  const real_T *Kg, const int_T p_width11,
  const real_T *Znmrt, const int_T p_width12,
  const real_T *Rchn, const int_T p_width13,
  const real_T *rRch, const int_T p_width14,
  const real_T *Delta2, const int_T p_width15);

/* private model entry point functions */
extern void SimuDemonstrateurMoteur_derivatives(void);

#endif                                 /* RTW_HEADER_SimuDemonstrateurMoteur_private_h_ */
