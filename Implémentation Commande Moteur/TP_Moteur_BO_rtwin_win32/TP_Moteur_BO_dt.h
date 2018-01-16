/*
 * TP_Moteur_BO_dt.h
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

#include "ext_types.h"

/* data type size table */
static uint_T rtDataTypeSizes[] = {
  sizeof(real_T),
  sizeof(real32_T),
  sizeof(int8_T),
  sizeof(uint8_T),
  sizeof(int16_T),
  sizeof(uint16_T),
  sizeof(int32_T),
  sizeof(uint32_T),
  sizeof(boolean_T),
  sizeof(fcn_call_T),
  sizeof(int_T),
  sizeof(pointer_T),
  sizeof(action_T),
  2*sizeof(uint32_T)
};

/* data type name table */
static const char_T * rtDataTypeNames[] = {
  "real_T",
  "real32_T",
  "int8_T",
  "uint8_T",
  "int16_T",
  "uint16_T",
  "int32_T",
  "uint32_T",
  "boolean_T",
  "fcn_call_T",
  "int_T",
  "pointer_T",
  "action_T",
  "timer_uint32_pair_T"
};

/* data type transitions for block I/O structure */
static DataTypeTransition rtBTransitions[] = {
  { (char_T *)(&TP_Moteur_BO_B.Integrator), 0, 0, 8 }
  ,

  { (char_T *)(&TP_Moteur_BO_DWork.AnalogOutput_PWORK), 11, 0, 7 }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  2U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&TP_Moteur_BO_P.Integrator_IC), 0, 0, 28 },

  { (char_T *)(&TP_Moteur_BO_P.AnalogOutput_Channels), 6, 0, 7 },

  { (char_T *)(&TP_Moteur_BO_P.ManualSwitch_CurrentSetting), 3, 0, 1 }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  3U,
  rtPTransitions
};

/* [EOF] TP_Moteur_BO_dt.h */
