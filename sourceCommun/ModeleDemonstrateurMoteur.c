/*
 * File: ModeleDemonstrateurMoteur.c
 *
 *
  *
  *   --- THIS FILE GENERATED BY S-FUNCTION BUILDER: 3.0 ---
  *
  *   This file is an S-function produced by the S-Function
  *   Builder which only recognizes certain fields.  Changes made
  *   outside these fields will be lost the next time the block is
  *   used to load, edit, and resave this file. This file will be overwritten
  *   by the S-function Builder block. If you want to edit this file by hand, 
  *   you must change it only in the area defined as:  
  *
  *        %%%-SFUNWIZ_defines_Changes_BEGIN
  *        #define NAME 'replacement text' 
  *        %%% SFUNWIZ_defines_Changes_END
  *
  *   DO NOT change NAME--Change the 'replacement text' only.
  *
  *   For better compatibility with the Simulink Coder, the
  *   "wrapper" S-function technique is used.  This is discussed
  *   in the Simulink Coder's Manual in the Chapter titled,
  *   "Wrapper S-functions".
  *
  *  -------------------------------------------------------------------------
  * | See matlabroot/simulink/src/sfuntmpl_doc.c for a more detailed template |
  *  ------------------------------------------------------------------------- 
 * Created: Sat Nov 19 17:39:40 2016
 * 
 *
 */

#define S_FUNCTION_LEVEL 2
#define S_FUNCTION_NAME ModeleDemonstrateurMoteur
/*<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/
/* %%%-SFUNWIZ_defines_Changes_BEGIN --- EDIT HERE TO _END */
#define NUM_INPUTS          1
/* Input Port  0 */
#define IN_PORT_0_NAME      Vm
#define INPUT_0_WIDTH       1
#define INPUT_DIMS_0_COL    1
#define INPUT_0_DTYPE       real_T
#define INPUT_0_COMPLEX     COMPLEX_NO
#define IN_0_FRAME_BASED    FRAME_NO
#define IN_0_BUS_BASED      0
#define IN_0_BUS_NAME       
#define IN_0_DIMS           1-D
#define INPUT_0_FEEDTHROUGH 1
#define IN_0_ISSIGNED        0
#define IN_0_WORDLENGTH      8
#define IN_0_FIXPOINTSCALING 1
#define IN_0_FRACTIONLENGTH  9
#define IN_0_BIAS            0
#define IN_0_SLOPE           0.125

#define NUM_OUTPUTS          2
/* Output Port  0 */
#define OUT_PORT_0_NAME      Vs
#define OUTPUT_0_WIDTH       1
#define OUTPUT_DIMS_0_COL    1
#define OUTPUT_0_DTYPE       real_T
#define OUTPUT_0_COMPLEX     COMPLEX_NO
#define OUT_0_FRAME_BASED    FRAME_NO
#define OUT_0_BUS_BASED      0
#define OUT_0_BUS_NAME       
#define OUT_0_DIMS           1-D
#define OUT_0_ISSIGNED        1
#define OUT_0_WORDLENGTH      8
#define OUT_0_FIXPOINTSCALING 1
#define OUT_0_FRACTIONLENGTH  3
#define OUT_0_BIAS            0
#define OUT_0_SLOPE           0.125
/* Output Port  1 */
#define OUT_PORT_1_NAME      Vg
#define OUTPUT_1_WIDTH       1
#define OUTPUT_DIMS_1_COL    1
#define OUTPUT_1_DTYPE       real_T
#define OUTPUT_1_COMPLEX     COMPLEX_NO
#define OUT_1_FRAME_BASED    FRAME_NO
#define OUT_1_BUS_BASED      0
#define OUT_1_BUS_NAME       
#define OUT_1_DIMS           1-D
#define OUT_1_ISSIGNED        1
#define OUT_1_WORDLENGTH      8
#define OUT_1_FIXPOINTSCALING 1
#define OUT_1_FRACTIONLENGTH  3
#define OUT_1_BIAS            0
#define OUT_1_SLOPE           0.125

#define NPARAMS              16
/* Parameter  1 */
#define PARAMETER_0_NAME      R
#define PARAMETER_0_DTYPE     real_T
#define PARAMETER_0_COMPLEX   COMPLEX_NO
/* Parameter  2 */
#define PARAMETER_1_NAME      L
#define PARAMETER_1_DTYPE     real_T
#define PARAMETER_1_COMPLEX   COMPLEX_NO
/* Parameter  3 */
#define PARAMETER_2_NAME      Ke
#define PARAMETER_2_DTYPE     real_T
#define PARAMETER_2_COMPLEX   COMPLEX_NO
/* Parameter  4 */
#define PARAMETER_3_NAME      Kc
#define PARAMETER_3_DTYPE     real_T
#define PARAMETER_3_COMPLEX   COMPLEX_NO
/* Parameter  5 */
#define PARAMETER_4_NAME      mu
#define PARAMETER_4_DTYPE     real_T
#define PARAMETER_4_COMPLEX   COMPLEX_NO
/* Parameter  6 */
#define PARAMETER_5_NAME      J
#define PARAMETER_5_DTYPE     real_T
#define PARAMETER_5_COMPLEX   COMPLEX_NO
/* Parameter  7 */
#define PARAMETER_6_NAME      Cn
#define PARAMETER_6_DTYPE     real_T
#define PARAMETER_6_COMPLEX   COMPLEX_NO
/* Parameter  8 */
#define PARAMETER_7_NAME      rCn
#define PARAMETER_7_DTYPE     real_T
#define PARAMETER_7_COMPLEX   COMPLEX_NO
/* Parameter  9 */
#define PARAMETER_8_NAME      Delta1
#define PARAMETER_8_DTYPE     real_T
#define PARAMETER_8_COMPLEX   COMPLEX_NO
/* Parameter  10 */
#define PARAMETER_9_NAME      Ks
#define PARAMETER_9_DTYPE     real_T
#define PARAMETER_9_COMPLEX   COMPLEX_NO
/* Parameter  11 */
#define PARAMETER_10_NAME      Kr
#define PARAMETER_10_DTYPE     real_T
#define PARAMETER_10_COMPLEX   COMPLEX_NO
/* Parameter  12 */
#define PARAMETER_11_NAME      Kg
#define PARAMETER_11_DTYPE     real_T
#define PARAMETER_11_COMPLEX   COMPLEX_NO
/* Parameter  13 */
#define PARAMETER_12_NAME      Znmrt
#define PARAMETER_12_DTYPE     real_T
#define PARAMETER_12_COMPLEX   COMPLEX_NO
/* Parameter  14 */
#define PARAMETER_13_NAME      Rchn
#define PARAMETER_13_DTYPE     real_T
#define PARAMETER_13_COMPLEX   COMPLEX_NO
/* Parameter  15 */
#define PARAMETER_14_NAME      rRch
#define PARAMETER_14_DTYPE     real_T
#define PARAMETER_14_COMPLEX   COMPLEX_NO
/* Parameter  16 */
#define PARAMETER_15_NAME      Delta2
#define PARAMETER_15_DTYPE     real_T
#define PARAMETER_15_COMPLEX   COMPLEX_NO

#define SAMPLE_TIME_0        0
#define NUM_DISC_STATES      0
#define DISC_STATES_IC       [0]
#define NUM_CONT_STATES      4
#define CONT_STATES_IC       [0,0,0,0]

#define SFUNWIZ_GENERATE_TLC 1
#define SOURCEFILES "__SFB__"
#define PANELINDEX           6
#define USE_SIMSTRUCT        0
#define SHOW_COMPILE_STEPS   0                   
#define CREATE_DEBUG_MEXFILE 0
#define SAVE_CODE_ONLY       0
#define SFUNWIZ_REVISION     3.0
/* %%%-SFUNWIZ_defines_Changes_END --- EDIT HERE TO _BEGIN */
/*<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/
#include "simstruc.h"
#define PARAM_DEF0(S) ssGetSFcnParam(S, 0)
#define PARAM_DEF1(S) ssGetSFcnParam(S, 1)
#define PARAM_DEF2(S) ssGetSFcnParam(S, 2)
#define PARAM_DEF3(S) ssGetSFcnParam(S, 3)
#define PARAM_DEF4(S) ssGetSFcnParam(S, 4)
#define PARAM_DEF5(S) ssGetSFcnParam(S, 5)
#define PARAM_DEF6(S) ssGetSFcnParam(S, 6)
#define PARAM_DEF7(S) ssGetSFcnParam(S, 7)
#define PARAM_DEF8(S) ssGetSFcnParam(S, 8)
#define PARAM_DEF9(S) ssGetSFcnParam(S, 9)
#define PARAM_DEF10(S) ssGetSFcnParam(S, 10)
#define PARAM_DEF11(S) ssGetSFcnParam(S, 11)
#define PARAM_DEF12(S) ssGetSFcnParam(S, 12)
#define PARAM_DEF13(S) ssGetSFcnParam(S, 13)
#define PARAM_DEF14(S) ssGetSFcnParam(S, 14)
#define PARAM_DEF15(S) ssGetSFcnParam(S, 15)

#define IS_PARAM_DOUBLE(pVal) (mxIsNumeric(pVal) && !mxIsLogical(pVal) &&\
!mxIsEmpty(pVal) && !mxIsSparse(pVal) && !mxIsComplex(pVal) && mxIsDouble(pVal))

extern void ModeleDemonstrateurMoteur_Outputs_wrapper(const real_T *Vm,
                          real_T *Vs,
                          real_T *Vg ,
			   const real_T *xC,
                          const real_T  *R, const int_T  p_width0, 
                          const real_T  *L, const int_T  p_width1, 
                          const real_T  *Ke, const int_T  p_width2, 
                          const real_T  *Kc, const int_T  p_width3, 
                          const real_T  *mu, const int_T  p_width4, 
                          const real_T  *J, const int_T  p_width5, 
                          const real_T  *Cn, const int_T  p_width6, 
                          const real_T  *rCn, const int_T  p_width7, 
                          const real_T  *Delta1, const int_T  p_width8, 
                          const real_T  *Ks, const int_T  p_width9, 
                          const real_T  *Kr, const int_T  p_width10, 
                          const real_T  *Kg, const int_T  p_width11, 
                          const real_T  *Znmrt, const int_T  p_width12, 
                          const real_T  *Rchn, const int_T  p_width13, 
                          const real_T  *rRch, const int_T  p_width14, 
                          const real_T  *Delta2, const int_T p_width15);
extern void ModeleDemonstrateurMoteur_Derivatives_wrapper(const real_T *Vm,
                          const real_T *Vs,
                          const real_T *Vg,
                          real_T *dx ,
                          real_T *xC, 
                          const real_T  *R,  const int_T  p_width0,
                          const real_T  *L,  const int_T  p_width1,
                          const real_T  *Ke,  const int_T  p_width2,
                          const real_T  *Kc,  const int_T  p_width3,
                          const real_T  *mu,  const int_T  p_width4,
                          const real_T  *J,  const int_T  p_width5,
                          const real_T  *Cn,  const int_T  p_width6,
                          const real_T  *rCn,  const int_T  p_width7,
                          const real_T  *Delta1,  const int_T  p_width8,
                          const real_T  *Ks,  const int_T  p_width9,
                          const real_T  *Kr,  const int_T  p_width10,
                          const real_T  *Kg,  const int_T  p_width11,
                          const real_T  *Znmrt,  const int_T  p_width12,
                          const real_T  *Rchn,  const int_T  p_width13,
                          const real_T  *rRch,  const int_T  p_width14,
                           const real_T *Delta2, const int_T  p_width15);

/*====================*
 * S-function methods *
 *====================*/
#define MDL_CHECK_PARAMETERS
 #if defined(MDL_CHECK_PARAMETERS) && defined(MATLAB_MEX_FILE)
   /* Function: mdlCheckParameters =============================================
     * Abstract:
     *    Validate our parameters to verify they are okay.
     */
    static void mdlCheckParameters(SimStruct *S)
    {
     int paramIndex  = 0;
     bool validParam = false;
     /* All parameters must match the S-function Builder Dialog */
     

	 {
	  const mxArray *pVal0 = ssGetSFcnParam(S,0);
	  if (!IS_PARAM_DOUBLE(pVal0)) {
	    validParam = true;
	    paramIndex = 0;
	    goto EXIT_POINT;
	  }
	 }

	 {
	  const mxArray *pVal1 = ssGetSFcnParam(S,1);
	  if (!IS_PARAM_DOUBLE(pVal1)) {
	    validParam = true;
	    paramIndex = 1;
	    goto EXIT_POINT;
	  }
	 }

	 {
	  const mxArray *pVal2 = ssGetSFcnParam(S,2);
	  if (!IS_PARAM_DOUBLE(pVal2)) {
	    validParam = true;
	    paramIndex = 2;
	    goto EXIT_POINT;
	  }
	 }

	 {
	  const mxArray *pVal3 = ssGetSFcnParam(S,3);
	  if (!IS_PARAM_DOUBLE(pVal3)) {
	    validParam = true;
	    paramIndex = 3;
	    goto EXIT_POINT;
	  }
	 }

	 {
	  const mxArray *pVal4 = ssGetSFcnParam(S,4);
	  if (!IS_PARAM_DOUBLE(pVal4)) {
	    validParam = true;
	    paramIndex = 4;
	    goto EXIT_POINT;
	  }
	 }

	 {
	  const mxArray *pVal5 = ssGetSFcnParam(S,5);
	  if (!IS_PARAM_DOUBLE(pVal5)) {
	    validParam = true;
	    paramIndex = 5;
	    goto EXIT_POINT;
	  }
	 }

	 {
	  const mxArray *pVal6 = ssGetSFcnParam(S,6);
	  if (!IS_PARAM_DOUBLE(pVal6)) {
	    validParam = true;
	    paramIndex = 6;
	    goto EXIT_POINT;
	  }
	 }

	 {
	  const mxArray *pVal7 = ssGetSFcnParam(S,7);
	  if (!IS_PARAM_DOUBLE(pVal7)) {
	    validParam = true;
	    paramIndex = 7;
	    goto EXIT_POINT;
	  }
	 }

	 {
	  const mxArray *pVal8 = ssGetSFcnParam(S,8);
	  if (!IS_PARAM_DOUBLE(pVal8)) {
	    validParam = true;
	    paramIndex = 8;
	    goto EXIT_POINT;
	  }
	 }

	 {
	  const mxArray *pVal9 = ssGetSFcnParam(S,9);
	  if (!IS_PARAM_DOUBLE(pVal9)) {
	    validParam = true;
	    paramIndex = 9;
	    goto EXIT_POINT;
	  }
	 }

	 {
	  const mxArray *pVal10 = ssGetSFcnParam(S,10);
	  if (!IS_PARAM_DOUBLE(pVal10)) {
	    validParam = true;
	    paramIndex = 10;
	    goto EXIT_POINT;
	  }
	 }

	 {
	  const mxArray *pVal11 = ssGetSFcnParam(S,11);
	  if (!IS_PARAM_DOUBLE(pVal11)) {
	    validParam = true;
	    paramIndex = 11;
	    goto EXIT_POINT;
	  }
	 }

	 {
	  const mxArray *pVal12 = ssGetSFcnParam(S,12);
	  if (!IS_PARAM_DOUBLE(pVal12)) {
	    validParam = true;
	    paramIndex = 12;
	    goto EXIT_POINT;
	  }
	 }

	 {
	  const mxArray *pVal13 = ssGetSFcnParam(S,13);
	  if (!IS_PARAM_DOUBLE(pVal13)) {
	    validParam = true;
	    paramIndex = 13;
	    goto EXIT_POINT;
	  }
	 }

	 {
	  const mxArray *pVal14 = ssGetSFcnParam(S,14);
	  if (!IS_PARAM_DOUBLE(pVal14)) {
	    validParam = true;
	    paramIndex = 14;
	    goto EXIT_POINT;
	  }
	 }

	 {
	  const mxArray *pVal15 = ssGetSFcnParam(S,15);
	  if (!IS_PARAM_DOUBLE(pVal15)) {
	    validParam = true;
	    paramIndex = 15;
	    goto EXIT_POINT;
	  }
	 }
      
     EXIT_POINT:
      if (validParam) {
          char parameterErrorMsg[1024];
          sprintf(parameterErrorMsg, "The data type and or complexity of parameter  %d does not match the "
                  "information specified in the S-function Builder dialog. "
                  "For non-double parameters you will need to cast them using int8, int16, "
                  "int32, uint8, uint16, uint32 or boolean.", paramIndex + 1);
	  ssSetErrorStatus(S,parameterErrorMsg);
      }
	return;
    }
 #endif /* MDL_CHECK_PARAMETERS */
/* Function: mdlInitializeSizes ===============================================
 * Abstract:
 *   Setup sizes of the various vectors.
 */
static void mdlInitializeSizes(SimStruct *S)
{

    DECL_AND_INIT_DIMSINFO(inputDimsInfo);
    DECL_AND_INIT_DIMSINFO(outputDimsInfo);
    ssSetNumSFcnParams(S, NPARAMS);  /* Number of expected parameters */
      #if defined(MATLAB_MEX_FILE)
	if (ssGetNumSFcnParams(S) == ssGetSFcnParamsCount(S)) {
	  mdlCheckParameters(S);
	  if (ssGetErrorStatus(S) != NULL) {
	    return;
	  }
	 } else {
	   return; /* Parameter mismatch will be reported by Simulink */
	 }
      #endif

    ssSetNumContStates(S, NUM_CONT_STATES);
    ssSetNumDiscStates(S, NUM_DISC_STATES);

    if (!ssSetNumInputPorts(S, NUM_INPUTS)) return;
    ssSetInputPortWidth(S, 0, INPUT_0_WIDTH);
    ssSetInputPortDataType(S, 0, SS_DOUBLE);
    ssSetInputPortComplexSignal(S, 0, INPUT_0_COMPLEX);
    ssSetInputPortDirectFeedThrough(S, 0, INPUT_0_FEEDTHROUGH);
    ssSetInputPortRequiredContiguous(S, 0, 1); /*direct input signal access*/

    if (!ssSetNumOutputPorts(S, NUM_OUTPUTS)) return;
    /* Output Port 0 */
    ssSetOutputPortWidth(S, 0, OUTPUT_0_WIDTH);
    ssSetOutputPortDataType(S, 0, SS_DOUBLE);
    ssSetOutputPortComplexSignal(S, 0, OUTPUT_0_COMPLEX);
    /* Output Port 1 */
    ssSetOutputPortWidth(S, 1, OUTPUT_1_WIDTH);
    ssSetOutputPortDataType(S, 1, SS_DOUBLE);
    ssSetOutputPortComplexSignal(S, 1, OUTPUT_1_COMPLEX);

    ssSetNumSampleTimes(S, 1);
    ssSetNumRWork(S, 0);
    ssSetNumIWork(S, 0);
    ssSetNumPWork(S, 0);
    ssSetNumModes(S, 0);
    ssSetNumNonsampledZCs(S, 0);

    /* Take care when specifying exception free code - see sfuntmpl_doc.c */
    ssSetOptions(S, (SS_OPTION_EXCEPTION_FREE_CODE |
                     SS_OPTION_USE_TLC_WITH_ACCELERATOR | 
		     SS_OPTION_WORKS_WITH_CODE_REUSE));
}

# define MDL_SET_INPUT_PORT_FRAME_DATA
static void mdlSetInputPortFrameData(SimStruct  *S, 
                                     int_T      port,
                                     Frame_T    frameData)
{
    ssSetInputPortFrameData(S, port, frameData);
}
/* Function: mdlInitializeSampleTimes =========================================
 * Abstract:
 *    Specifiy  the sample time.
 */
static void mdlInitializeSampleTimes(SimStruct *S)
{
    ssSetSampleTime(S, 0, SAMPLE_TIME_0);
    ssSetOffsetTime(S, 0, 0.0);
}
#define MDL_INITIALIZE_CONDITIONS
 /* Function: mdlInitializeConditions ========================================
  * Abstract:
  *    Initialize the states
  */
 static void mdlInitializeConditions(SimStruct *S)
 {
   
   real_T *xC   = ssGetContStates(S);
    
    
    xC[0] =  0;
    xC[1] =  0;
    xC[2] =  0;
    xC[3] =  0;
 }
#define MDL_SET_INPUT_PORT_DATA_TYPE
static void mdlSetInputPortDataType(SimStruct *S, int port, DTypeId dType)
{
    ssSetInputPortDataType( S, 0, dType);
}
#define MDL_SET_OUTPUT_PORT_DATA_TYPE
static void mdlSetOutputPortDataType(SimStruct *S, int port, DTypeId dType)
{
    ssSetOutputPortDataType(S, 0, dType);
}

#define MDL_SET_DEFAULT_PORT_DATA_TYPES
static void mdlSetDefaultPortDataTypes(SimStruct *S)
{
  ssSetInputPortDataType( S, 0, SS_DOUBLE);
 ssSetOutputPortDataType(S, 0, SS_DOUBLE);
}
/* Function: mdlOutputs =======================================================
 *
*/
static void mdlOutputs(SimStruct *S, int_T tid)
{
    const real_T   *Vm  = (const real_T*) ssGetInputPortSignal(S,0);
    real_T        *Vs  = (real_T *)ssGetOutputPortRealSignal(S,0);
    real_T        *Vg  = (real_T *)ssGetOutputPortRealSignal(S,1);
    const real_T   *xC = ssGetContStates(S);
    const int_T   p_width0  = mxGetNumberOfElements(PARAM_DEF0(S));
    const int_T   p_width1  = mxGetNumberOfElements(PARAM_DEF1(S));
    const int_T   p_width2  = mxGetNumberOfElements(PARAM_DEF2(S));
    const int_T   p_width3  = mxGetNumberOfElements(PARAM_DEF3(S));
    const int_T   p_width4  = mxGetNumberOfElements(PARAM_DEF4(S));
    const int_T   p_width5  = mxGetNumberOfElements(PARAM_DEF5(S));
    const int_T   p_width6  = mxGetNumberOfElements(PARAM_DEF6(S));
    const int_T   p_width7  = mxGetNumberOfElements(PARAM_DEF7(S));
    const int_T   p_width8  = mxGetNumberOfElements(PARAM_DEF8(S));
    const int_T   p_width9  = mxGetNumberOfElements(PARAM_DEF9(S));
    const int_T   p_width10  = mxGetNumberOfElements(PARAM_DEF10(S));
    const int_T   p_width11  = mxGetNumberOfElements(PARAM_DEF11(S));
    const int_T   p_width12  = mxGetNumberOfElements(PARAM_DEF12(S));
    const int_T   p_width13  = mxGetNumberOfElements(PARAM_DEF13(S));
    const int_T   p_width14  = mxGetNumberOfElements(PARAM_DEF14(S));
    const int_T   p_width15  = mxGetNumberOfElements(PARAM_DEF15(S));
    const real_T  *R  = (const real_T *)mxGetData(PARAM_DEF0(S));
    const real_T  *L  = (const real_T *)mxGetData(PARAM_DEF1(S));
    const real_T  *Ke  = (const real_T *)mxGetData(PARAM_DEF2(S));
    const real_T  *Kc  = (const real_T *)mxGetData(PARAM_DEF3(S));
    const real_T  *mu  = (const real_T *)mxGetData(PARAM_DEF4(S));
    const real_T  *J  = (const real_T *)mxGetData(PARAM_DEF5(S));
    const real_T  *Cn  = (const real_T *)mxGetData(PARAM_DEF6(S));
    const real_T  *rCn  = (const real_T *)mxGetData(PARAM_DEF7(S));
    const real_T  *Delta1  = (const real_T *)mxGetData(PARAM_DEF8(S));
    const real_T  *Ks  = (const real_T *)mxGetData(PARAM_DEF9(S));
    const real_T  *Kr  = (const real_T *)mxGetData(PARAM_DEF10(S));
    const real_T  *Kg  = (const real_T *)mxGetData(PARAM_DEF11(S));
    const real_T  *Znmrt  = (const real_T *)mxGetData(PARAM_DEF12(S));
    const real_T  *Rchn  = (const real_T *)mxGetData(PARAM_DEF13(S));
    const real_T  *rRch  = (const real_T *)mxGetData(PARAM_DEF14(S));
    const real_T  *Delta2  = (const real_T *)mxGetData(PARAM_DEF15(S));

    ModeleDemonstrateurMoteur_Outputs_wrapper(Vm, Vs, Vg, xC, R, p_width0, L, p_width1, Ke, p_width2, Kc, p_width3, mu, p_width4, J, p_width5, Cn, p_width6, rCn, p_width7, Delta1, p_width8, Ks, p_width9, Kr, p_width10, Kg, p_width11, Znmrt, p_width12, Rchn, p_width13, rRch, p_width14, Delta2, p_width15);
}

#define MDL_DERIVATIVES  /* Change to #undef to remove function */
/* Function: mdlDerivatives =================================================
   * Abstract:
   *    In this function, you compute the S-function block's derivatives.
   *    The derivatives are placed in the derivative vector, ssGetdX(S).
   */
  static void mdlDerivatives(SimStruct *S)
  {
    const real_T   *Vm  = (const real_T*) ssGetInputPortSignal(S,0);
    real_T         *dx  = ssGetdX(S);
    real_T         *xC  = ssGetContStates(S);
    real_T        *Vs  = (real_T *) ssGetOutputPortRealSignal(S,0);
    real_T        *Vg  = (real_T *) ssGetOutputPortRealSignal(S,1);
    const int_T   p_width0  = mxGetNumberOfElements(PARAM_DEF0(S));
    const int_T   p_width1  = mxGetNumberOfElements(PARAM_DEF1(S));
    const int_T   p_width2  = mxGetNumberOfElements(PARAM_DEF2(S));
    const int_T   p_width3  = mxGetNumberOfElements(PARAM_DEF3(S));
    const int_T   p_width4  = mxGetNumberOfElements(PARAM_DEF4(S));
    const int_T   p_width5  = mxGetNumberOfElements(PARAM_DEF5(S));
    const int_T   p_width6  = mxGetNumberOfElements(PARAM_DEF6(S));
    const int_T   p_width7  = mxGetNumberOfElements(PARAM_DEF7(S));
    const int_T   p_width8  = mxGetNumberOfElements(PARAM_DEF8(S));
    const int_T   p_width9  = mxGetNumberOfElements(PARAM_DEF9(S));
    const int_T   p_width10  = mxGetNumberOfElements(PARAM_DEF10(S));
    const int_T   p_width11  = mxGetNumberOfElements(PARAM_DEF11(S));
    const int_T   p_width12  = mxGetNumberOfElements(PARAM_DEF12(S));
    const int_T   p_width13  = mxGetNumberOfElements(PARAM_DEF13(S));
    const int_T   p_width14  = mxGetNumberOfElements(PARAM_DEF14(S));
    const int_T   p_width15  = mxGetNumberOfElements(PARAM_DEF15(S));
    const real_T  *R  = (const real_T *)mxGetData(PARAM_DEF0(S));
    const real_T  *L  = (const real_T *)mxGetData(PARAM_DEF1(S));
    const real_T  *Ke  = (const real_T *)mxGetData(PARAM_DEF2(S));
    const real_T  *Kc  = (const real_T *)mxGetData(PARAM_DEF3(S));
    const real_T  *mu  = (const real_T *)mxGetData(PARAM_DEF4(S));
    const real_T  *J  = (const real_T *)mxGetData(PARAM_DEF5(S));
    const real_T  *Cn  = (const real_T *)mxGetData(PARAM_DEF6(S));
    const real_T  *rCn  = (const real_T *)mxGetData(PARAM_DEF7(S));
    const real_T  *Delta1  = (const real_T *)mxGetData(PARAM_DEF8(S));
    const real_T  *Ks  = (const real_T *)mxGetData(PARAM_DEF9(S));
    const real_T  *Kr  = (const real_T *)mxGetData(PARAM_DEF10(S));
    const real_T  *Kg  = (const real_T *)mxGetData(PARAM_DEF11(S));
    const real_T  *Znmrt  = (const real_T *)mxGetData(PARAM_DEF12(S));
    const real_T  *Rchn  = (const real_T *)mxGetData(PARAM_DEF13(S));
    const real_T  *rRch  = (const real_T *)mxGetData(PARAM_DEF14(S));
    const real_T  *Delta2  = (const real_T *)mxGetData(PARAM_DEF15(S));

    ModeleDemonstrateurMoteur_Derivatives_wrapper(Vm, Vs, Vg,dx,  xC, R, p_width0, L, p_width1, Ke, p_width2, Kc, p_width3, mu, p_width4, J, p_width5, Cn, p_width6, rCn, p_width7, Delta1, p_width8, Ks, p_width9, Kr, p_width10, Kg, p_width11, Znmrt, p_width12, Rchn, p_width13, rRch, p_width14, Delta2, p_width15);
}

/* Function: mdlTerminate =====================================================
 * Abstract:
 *    In this function, you should perform any actions that are necessary
 *    at the termination of a simulation.  For example, if memory was
 *    allocated in mdlStart, this is the place to free it.
 */
static void mdlTerminate(SimStruct *S)
{
}
#ifdef  MATLAB_MEX_FILE    /* Is this file being compiled as a MEX-file? */
#include "simulink.c"      /* MEX-file interface mechanism */
#else
#include "cg_sfun.h"       /* Code generation registration function */
#endif


