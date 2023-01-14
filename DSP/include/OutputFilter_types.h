/*
 * OutputFilter_types.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "OutputFilter".
 *
 * Model version              : 1.1
 * Simulink Coder version : 9.3 (R2020a) 18-Nov-2019
 * C++ source code generated on : Tue May 18 11:15:49 2021
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_OutputFilter_types_h_
#define RTW_HEADER_OutputFilter_types_h_
#include "rtwtypes.h"
#include "multiword_types.h"

/* Model Code Variants */
#ifndef struct_tag_cpiFwYyFqHVNWpuN3XOeE
#define struct_tag_cpiFwYyFqHVNWpuN3XOeE

struct tag_cpiFwYyFqHVNWpuN3XOeE
{
  int32_T S0_isInitialized;
  real_T W0_ZERO_STATES[10];
  real_T W1_POLE_STATES[10];
  int32_T W2_PreviousNumChannels;
  real_T P0_ICRTP;
  real_T P1_RTP1COEFF[15];
  real_T P2_RTP2COEFF[10];
  real_T P3_RTP3COEFF[6];
  boolean_T P4_RTP_COEFF3_BOOL[6];
  real_T P5_IC2RTP;
};

#endif                                 /*struct_tag_cpiFwYyFqHVNWpuN3XOeE*/

#ifndef typedef_b_dsp_BiquadFilter_0_OutputFi_T
#define typedef_b_dsp_BiquadFilter_0_OutputFi_T

typedef struct tag_cpiFwYyFqHVNWpuN3XOeE b_dsp_BiquadFilter_0_OutputFi_T;

#endif                               /*typedef_b_dsp_BiquadFilter_0_OutputFi_T*/

#ifndef struct_tag_ybnhXIavtOt5ZJA5GrHLXC
#define struct_tag_ybnhXIavtOt5ZJA5GrHLXC

struct tag_ybnhXIavtOt5ZJA5GrHLXC
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  b_dsp_BiquadFilter_0_OutputFi_T cSFunObject;
};

#endif                                 /*struct_tag_ybnhXIavtOt5ZJA5GrHLXC*/

#ifndef typedef_b_dspcodegen_BiquadFilter_Out_T
#define typedef_b_dspcodegen_BiquadFilter_Out_T

typedef struct tag_ybnhXIavtOt5ZJA5GrHLXC b_dspcodegen_BiquadFilter_Out_T;

#endif                               /*typedef_b_dspcodegen_BiquadFilter_Out_T*/

#ifndef struct_tag_PMfBDzoakfdM9QAdfx2o6D
#define struct_tag_PMfBDzoakfdM9QAdfx2o6D

struct tag_PMfBDzoakfdM9QAdfx2o6D
{
  uint32_T f1[8];
};

#endif                                 /*struct_tag_PMfBDzoakfdM9QAdfx2o6D*/

#ifndef typedef_cell_wrap_OutputFilter_T
#define typedef_cell_wrap_OutputFilter_T

typedef struct tag_PMfBDzoakfdM9QAdfx2o6D cell_wrap_OutputFilter_T;

#endif                                 /*typedef_cell_wrap_OutputFilter_T*/

#ifndef struct_tag_LevZ05996BXRQRKAx7ISoD
#define struct_tag_LevZ05996BXRQRKAx7ISoD

struct tag_LevZ05996BXRQRKAx7ISoD
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  cell_wrap_OutputFilter_T inputVarSize;
  int32_T NumChannels;
  b_dspcodegen_BiquadFilter_Out_T *FilterObj;
};

#endif                                 /*struct_tag_LevZ05996BXRQRKAx7ISoD*/

#ifndef typedef_dsp_LowpassFilter_OutputFilte_T
#define typedef_dsp_LowpassFilter_OutputFilte_T

typedef struct tag_LevZ05996BXRQRKAx7ISoD dsp_LowpassFilter_OutputFilte_T;

#endif                               /*typedef_dsp_LowpassFilter_OutputFilte_T*/

/* Forward declaration for rtModel */
typedef struct tag_RTM_OutputFilter_T RT_MODEL_OutputFilter_T;

#endif                                 /* RTW_HEADER_OutputFilter_types_h_ */
