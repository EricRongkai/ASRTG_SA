/*
 * OmegaFilter_types.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "OmegaFilter".
 *
 * Model version              : 1.3
 * Simulink Coder version : 9.3 (R2020a) 18-Nov-2019
 * C++ source code generated on : Tue Jun 21 20:18:56 2022
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_OmegaFilter_types_h_
#define RTW_HEADER_OmegaFilter_types_h_
#include "rtwtypes.h"
#include "multiword_types.h"

/* Model Code Variants */
#ifndef struct_tag_GLYPJ9kJzVU8XOonIMoNAB
#define struct_tag_GLYPJ9kJzVU8XOonIMoNAB

struct tag_GLYPJ9kJzVU8XOonIMoNAB
{
  int32_T S0_isInitialized;
  real_T W0_states[56];
  real_T P0_InitialStates;
  real_T P1_Coefficients[57];
};

#endif                                 /*struct_tag_GLYPJ9kJzVU8XOonIMoNAB*/

#ifndef typedef_b_dsp_FIRFilter_0_OmegaFilter_T
#define typedef_b_dsp_FIRFilter_0_OmegaFilter_T

typedef struct tag_GLYPJ9kJzVU8XOonIMoNAB b_dsp_FIRFilter_0_OmegaFilter_T;

#endif                               /*typedef_b_dsp_FIRFilter_0_OmegaFilter_T*/

#ifndef struct_tag_28TgtasAeBf5IygvJBsVmD
#define struct_tag_28TgtasAeBf5IygvJBsVmD

struct tag_28TgtasAeBf5IygvJBsVmD
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  b_dsp_FIRFilter_0_OmegaFilter_T cSFunObject;
};

#endif                                 /*struct_tag_28TgtasAeBf5IygvJBsVmD*/

#ifndef typedef_b_dspcodegen_FIRFilter_OmegaF_T
#define typedef_b_dspcodegen_FIRFilter_OmegaF_T

typedef struct tag_28TgtasAeBf5IygvJBsVmD b_dspcodegen_FIRFilter_OmegaF_T;

#endif                               /*typedef_b_dspcodegen_FIRFilter_OmegaF_T*/

#ifndef struct_tag_PMfBDzoakfdM9QAdfx2o6D
#define struct_tag_PMfBDzoakfdM9QAdfx2o6D

struct tag_PMfBDzoakfdM9QAdfx2o6D
{
  uint32_T f1[8];
};

#endif                                 /*struct_tag_PMfBDzoakfdM9QAdfx2o6D*/

#ifndef typedef_cell_wrap_OmegaFilter_T
#define typedef_cell_wrap_OmegaFilter_T

typedef struct tag_PMfBDzoakfdM9QAdfx2o6D cell_wrap_OmegaFilter_T;

#endif                                 /*typedef_cell_wrap_OmegaFilter_T*/

#ifndef struct_tag_EAjuv1ZfYd1px8WR7WPmnH
#define struct_tag_EAjuv1ZfYd1px8WR7WPmnH

struct tag_EAjuv1ZfYd1px8WR7WPmnH
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  cell_wrap_OmegaFilter_T inputVarSize;
  int32_T NumChannels;
  b_dspcodegen_FIRFilter_OmegaF_T *FilterObj;
};

#endif                                 /*struct_tag_EAjuv1ZfYd1px8WR7WPmnH*/

#ifndef typedef_dsp_LowpassFilter_OmegaFilter_T
#define typedef_dsp_LowpassFilter_OmegaFilter_T

typedef struct tag_EAjuv1ZfYd1px8WR7WPmnH dsp_LowpassFilter_OmegaFilter_T;

#endif                               /*typedef_dsp_LowpassFilter_OmegaFilter_T*/

/* Forward declaration for rtModel */
typedef struct tag_RTM_OmegaFilter_T RT_MODEL_OmegaFilter_T;

#endif                                 /* RTW_HEADER_OmegaFilter_types_h_ */
