#ifndef SLEXEC_SIMSTRUCT_BRIDGE_H
#define SLEXEC_SIMSTRUCT_BRIDGE_H
/**
 * @file slexec_simstruct_bridge.h
 *
 * This header is the exported C interface to the simulink execution engine
 * (slexec_simbridge) that involves simstruct. It is used by the Rapid
 * Accelerator target. This file should be included from simstruct (and no
 * earlier) so that we have access to preprocessor variables. 
 *
 * 
 */

/* Copyright 2014-2019 The MathWorks, Inc. */

#include "slexec_simbridge.h"
#include "slexec_ssExecutionInfo.h"
#include "slexec_parallel.h"
#include <setjmp.h>

/* Guard against early inclusions */
#ifndef _SIMSTRUCT
#error "This file should be included from simstruc.h"
#endif


/* Run simulation */
SLEXEC_SIMBRIDGE_PUBLISHED_C void ssRunSimulation(SimStruct* S);

/* sti is the (also runtime) index of the *sole* rate in the event spec associated with the event */
/* on which you want to call raise */
/* runMultiplicity is the number of times the tasks in the event clock are run when raised */
SLEXEC_SIMBRIDGE_PUBLISHED_C void ssRaiseEventUsingRateIndexWithRunMultiplicity(
    SimStruct* S,
    int_T sti,
    uint_T runMultiplicity);

/* sti is the (also runtime) index of the *sole* rate in the event spec associated with the event */
/* on which you want to call raise */
SLEXEC_SIMBRIDGE_PUBLISHED_C void ssRaiseEventUsingRateIndex(
    SimStruct* S,
    int_T sti);

/* eventRuntimeIndex is the runtime index of the event on which you want to call raise */
/* runMultiplicity is the number of times the tasks in the event clock are run when raised */
SLEXEC_SIMBRIDGE_PUBLISHED_C void ssRaiseEventWithRunMultiplicity(
    SimStruct* S,
    uint_T eventRuntimeIndex,
    uint_T runMultiplicity);

/* eventRuntimeIndex is the runtime index of the event on which you want to raise the event */
SLEXEC_SIMBRIDGE_PUBLISHED_C void ssRaiseEvent(
    SimStruct* S,
    uint_T eventRuntimeIndex);

/* sti is the (also runtime) index of the first rate of the first task of event that is being raised
 * by enqueuing */
SLEXEC_SIMBRIDGE_PUBLISHED_C void ssRaiseEventWithEnqueueUsingRateIndex(
    SimStruct* S,
    int_T sti);

/* taskRuntimeIndex is the runtime index of the task thay you want to raise by enqueuing */
SLEXEC_SIMBRIDGE_PUBLISHED_C void ssRaiseEventWithEnqueue(
    SimStruct* S,
    uint_T taskRuntimeIndex);

/* sti is the (also runtime) index of the *sole* rate in the task thay you want to disable */
SLEXEC_SIMBRIDGE_PUBLISHED_C void ssDisableTaskUsingRateIndex(
    SimStruct* S,
    int_T sti);

/* taskRuntimeIndex is the runtime index of the task thay you want to disable */
SLEXEC_SIMBRIDGE_PUBLISHED_C void ssDisableTask(
    SimStruct* S,
    uint_T taskRuntimeIndex);

/* sti is the (also runtime) index of the *sole* rate in the task thay you want to enable */
SLEXEC_SIMBRIDGE_PUBLISHED_C void ssEnableTaskUsingRateIndex(
    SimStruct* S,
    int_T sti);

/* taskRuntimeIndex is the runtime index of the task thay you want to enable */
SLEXEC_SIMBRIDGE_PUBLISHED_C void ssEnableTask(
    SimStruct* S,
    uint_T taskRuntimeIndex);

SLEXEC_SIMBRIDGE_PUBLISHED_C void slexecSetNumTicksToNextSampleHitForControllableSampleTime(
    SimStruct* rootS,
    size_t ctrlRateIdx,
    size_t nTicks);

SLEXEC_SIMBRIDGE_PUBLISHED_C size_t slexecGetNumTicksToNextSampleHitForControllableSampleTime(
    SimStruct* rootS,
    size_t ctrlRateIdx);

SLEXEC_SIMBRIDGE_PUBLISHED_C void ssWriteSimMetadata(
    SimStruct* S,
    const char* metadataFilePath
    );

#endif 
