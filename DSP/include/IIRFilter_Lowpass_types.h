/*
 * IIRFilter_Lowpass_types.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "IIRFilter_Lowpass".
 *
 * Model version              : 1.4
 * Simulink Coder version : 9.3 (R2020a) 18-Nov-2019
 * C++ source code generated on : Tue Jun 21 22:10:03 2022
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_IIRFilter_Lowpass_types_h_
#define RTW_HEADER_IIRFilter_Lowpass_types_h_
#include "rtwtypes.h"
#include "multiword_types.h"

/* Model Code Variants */
#ifndef struct_tag_QljhZULzUrUoKvbR6oB4c
#define struct_tag_QljhZULzUrUoKvbR6oB4c

struct tag_QljhZULzUrUoKvbR6oB4c
{
  int32_T S0_isInitialized;
  real_T W0_states[14];
  real_T P0_InitialStates;
  real_T P1_Coefficients[15];
};

#endif                                 /*struct_tag_QljhZULzUrUoKvbR6oB4c*/

#ifndef typedef_b_dsp_FIRFilter_0_IIRFilter_L_T
#define typedef_b_dsp_FIRFilter_0_IIRFilter_L_T

typedef struct tag_QljhZULzUrUoKvbR6oB4c b_dsp_FIRFilter_0_IIRFilter_L_T;

#endif                               /*typedef_b_dsp_FIRFilter_0_IIRFilter_L_T*/

#ifndef struct_tag_0HywhCEBWEGQm4ZncysCJC
#define struct_tag_0HywhCEBWEGQm4ZncysCJC

struct tag_0HywhCEBWEGQm4ZncysCJC
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  b_dsp_FIRFilter_0_IIRFilter_L_T cSFunObject;
};

#endif                                 /*struct_tag_0HywhCEBWEGQm4ZncysCJC*/

#ifndef typedef_b_dspcodegen_FIRFilter_IIRFil_T
#define typedef_b_dspcodegen_FIRFilter_IIRFil_T

typedef struct tag_0HywhCEBWEGQm4ZncysCJC b_dspcodegen_FIRFilter_IIRFil_T;

#endif                               /*typedef_b_dspcodegen_FIRFilter_IIRFil_T*/

#ifndef struct_tag_PMfBDzoakfdM9QAdfx2o6D
#define struct_tag_PMfBDzoakfdM9QAdfx2o6D

struct tag_PMfBDzoakfdM9QAdfx2o6D
{
  uint32_T f1[8];
};

#endif                                 /*struct_tag_PMfBDzoakfdM9QAdfx2o6D*/

#ifndef typedef_cell_wrap_IIRFilter_Lowpass_T
#define typedef_cell_wrap_IIRFilter_Lowpass_T

typedef struct tag_PMfBDzoakfdM9QAdfx2o6D cell_wrap_IIRFilter_Lowpass_T;

#endif                                 /*typedef_cell_wrap_IIRFilter_Lowpass_T*/

#ifndef struct_tag_v8YZxKkoAwDLGsv49wWlxB
#define struct_tag_v8YZxKkoAwDLGsv49wWlxB

struct tag_v8YZxKkoAwDLGsv49wWlxB
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  cell_wrap_IIRFilter_Lowpass_T inputVarSize;
  int32_T NumChannels;
  b_dspcodegen_FIRFilter_IIRFil_T *FilterObj;
};

#endif                                 /*struct_tag_v8YZxKkoAwDLGsv49wWlxB*/

#ifndef typedef_dsp_LowpassFilter_IIRFilter_L_T
#define typedef_dsp_LowpassFilter_IIRFilter_L_T

typedef struct tag_v8YZxKkoAwDLGsv49wWlxB dsp_LowpassFilter_IIRFilter_L_T;

#endif                               /*typedef_dsp_LowpassFilter_IIRFilter_L_T*/

/* Forward declaration for rtModel */
typedef struct tag_RTM_IIRFilter_Lowpass_T RT_MODEL_IIRFilter_Lowpass_T;

#endif                               /* RTW_HEADER_IIRFilter_Lowpass_types_h_ */
