// ==============================================================
// File generated by Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC
// Version: 2015.1
// Copyright (C) 2015 Xilinx Inc. All rights reserved.
//
// ==============================================================

#ifndef XV_DEINTERLACER_H
#define XV_DEINTERLACER_H

#ifdef __cplusplus
extern "C" {
#endif

/***************************** Include Files *********************************/
#ifndef __linux__
#include "xil_types.h"
#include "xil_assert.h"
#include "xstatus.h"
#include "xil_io.h"
#else
#include <stdint.h>
#include <assert.h>
#include <dirent.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <unistd.h>
#include <stddef.h>
#endif
#include "xv_deinterlacer_hw.h"

/**************************** Type Definitions ******************************/
#ifdef __linux__
typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
#else
typedef struct {
    u16 DeviceId;
    u32 Axilites_BaseAddress;
} XV_deinterlacer_Config;
#endif

typedef struct {
    u32 Axilites_BaseAddress;
    u32 IsReady;
} XV_deinterlacer;

/***************** Macros (Inline Functions) Definitions *********************/
#ifndef __linux__
#define XV_deinterlacer_WriteReg(BaseAddress, RegOffset, Data) \
    Xil_Out32((BaseAddress) + (RegOffset), (u32)(Data))
#define XV_deinterlacer_ReadReg(BaseAddress, RegOffset) \
    Xil_In32((BaseAddress) + (RegOffset))
#else
#define XV_deinterlacer_WriteReg(BaseAddress, RegOffset, Data) \
    *(volatile u32*)((BaseAddress) + (RegOffset)) = (u32)(Data)
#define XV_deinterlacer_ReadReg(BaseAddress, RegOffset) \
    *(volatile u32*)((BaseAddress) + (RegOffset))

#define Xil_AssertVoid(expr)    assert(expr)
#define Xil_AssertNonvoid(expr) assert(expr)

#define XST_SUCCESS             0
#define XST_DEVICE_NOT_FOUND    2
#define XST_OPEN_DEVICE_FAILED  3
#define XIL_COMPONENT_IS_READY  1
#endif

/************************** Function Prototypes *****************************/
#ifndef __linux__
int XV_deinterlacer_Initialize(XV_deinterlacer *InstancePtr, u16 DeviceId);
XV_deinterlacer_Config* XV_deinterlacer_LookupConfig(u16 DeviceId);
int XV_deinterlacer_CfgInitialize(XV_deinterlacer *InstancePtr, XV_deinterlacer_Config *ConfigPtr);
#else
int XV_deinterlacer_Initialize(XV_deinterlacer *InstancePtr, const char* InstanceName);
int XV_deinterlacer_Release(XV_deinterlacer *InstancePtr);
#endif

void XV_deinterlacer_Start(XV_deinterlacer *InstancePtr);
u32 XV_deinterlacer_IsDone(XV_deinterlacer *InstancePtr);
u32 XV_deinterlacer_IsIdle(XV_deinterlacer *InstancePtr);
u32 XV_deinterlacer_IsReady(XV_deinterlacer *InstancePtr);
void XV_deinterlacer_EnableAutoRestart(XV_deinterlacer *InstancePtr);
void XV_deinterlacer_DisableAutoRestart(XV_deinterlacer *InstancePtr);

void XV_deinterlacer_Set_read_fb(XV_deinterlacer *InstancePtr, u32 Data);
u32 XV_deinterlacer_Get_read_fb(XV_deinterlacer *InstancePtr);
void XV_deinterlacer_Set_write_fb(XV_deinterlacer *InstancePtr, u32 Data);
u32 XV_deinterlacer_Get_write_fb(XV_deinterlacer *InstancePtr);
void XV_deinterlacer_Set_colorFormat(XV_deinterlacer *InstancePtr, u32 Data);
u32 XV_deinterlacer_Get_colorFormat(XV_deinterlacer *InstancePtr);
void XV_deinterlacer_Set_algo(XV_deinterlacer *InstancePtr, u32 Data);
u32 XV_deinterlacer_Get_algo(XV_deinterlacer *InstancePtr);

void XV_deinterlacer_InterruptGlobalEnable(XV_deinterlacer *InstancePtr);
void XV_deinterlacer_InterruptGlobalDisable(XV_deinterlacer *InstancePtr);
void XV_deinterlacer_InterruptEnable(XV_deinterlacer *InstancePtr, u32 Mask);
void XV_deinterlacer_InterruptDisable(XV_deinterlacer *InstancePtr, u32 Mask);
void XV_deinterlacer_InterruptClear(XV_deinterlacer *InstancePtr, u32 Mask);
u32 XV_deinterlacer_InterruptGetEnabled(XV_deinterlacer *InstancePtr);
u32 XV_deinterlacer_InterruptGetStatus(XV_deinterlacer *InstancePtr);

#ifdef __cplusplus
}
#endif

#endif
