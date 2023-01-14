/*
 * Dev_1order_types.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Dev_1order".
 *
 * Model version              : 1.4
 * Simulink Coder version : 9.3 (R2020a) 18-Nov-2019
 * C++ source code generated on : Wed Jun 22 15:58:30 2022
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Dev_1order_types_h_
#define RTW_HEADER_Dev_1order_types_h_
#include "rtwtypes.h"
#include "multiword_types.h"

/* Model Code Variants */
#ifndef struct_tag_8AoxuF5dcwIfWXVz5LjVrH
#define struct_tag_8AoxuF5dcwIfWXVz5LjVrH

struct tag_8AoxuF5dcwIfWXVz5LjVrH
{
  int32_T S0_isInitialized;
  real_T W0_states[15];
  real_T P0_InitialStates;
  real_T P1_Coefficients[16];
};

#endif                                 /*struct_tag_8AoxuF5dcwIfWXVz5LjVrH*/

#ifndef typedef_b_dsp_FIRFilter_0_Dev_1order_T
#define typedef_b_dsp_FIRFilter_0_Dev_1order_T

typedef struct tag_8AoxuF5dcwIfWXVz5LjVrH b_dsp_FIRFilter_0_Dev_1order_T;

#endif                                /*typedef_b_dsp_FIRFilter_0_Dev_1order_T*/

#ifndef struct_tag_uTNYyZUOJxJwytPEQirfTC
#define struct_tag_uTNYyZUOJxJwytPEQirfTC

struct tag_uTNYyZUOJxJwytPEQirfTC
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  b_dsp_FIRFilter_0_Dev_1order_T cSFunObject;
};

#endif                                 /*struct_tag_uTNYyZUOJxJwytPEQirfTC*/

#ifndef typedef_b_dspcodegen_FIRFilter_Dev_1o_T
#define typedef_b_dspcodegen_FIRFilter_Dev_1o_T

typedef struct tag_uTNYyZUOJxJwytPEQirfTC b_dspcodegen_FIRFilter_Dev_1o_T;

#endif                               /*typedef_b_dspcodegen_FIRFilter_Dev_1o_T*/

#ifndef struct_tag_PMfBDzoakfdM9QAdfx2o6D
#define struct_tag_PMfBDzoakfdM9QAdfx2o6D

struct tag_PMfBDzoakfdM9QAdfx2o6D
{
  uint32_T f1[8];
};

#endif                                 /*struct_tag_PMfBDzoakfdM9QAdfx2o6D*/

#ifndef typedef_cell_wrap_Dev_1order_T
#define typedef_cell_wrap_Dev_1order_T

typedef struct tag_PMfBDzoakfdM9QAdfx2o6D cell_wrap_Dev_1order_T;

#endif                                 /*typedef_cell_wrap_Dev_1order_T*/

#ifndef struct_tag_PoxJbswOc30SDyZW4OAZbB
#define struct_tag_PoxJbswOc30SDyZW4OAZbB

struct tag_PoxJbswOc30SDyZW4OAZbB
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  cell_wrap_Dev_1order_T inputVarSize;
  int32_T NumChannels;
  b_dspcodegen_FIRFilter_Dev_1o_T *FilterObj;
};

#endif                                 /*struct_tag_PoxJbswOc30SDyZW4OAZbB*/

#ifndef typedef_dsp_LowpassFilter_Dev_1order_T
#define typedef_dsp_LowpassFilter_Dev_1order_T

typedef struct tag_PoxJbswOc30SDyZW4OAZbB dsp_LowpassFilter_Dev_1order_T;

#endif                                /*typedef_dsp_LowpassFilter_Dev_1order_T*/

/* Parameters (default storage) */
typedef struct P_Dev_1order_T_ P_Dev_1order_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_Dev_1order_T RT_MODEL_Dev_1order_T;

#endif                                 /* RTW_HEADER_Dev_1order_types_h_ */
