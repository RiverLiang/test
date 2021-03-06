/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename  : Vectors.C
**     Project   : PmsmFocDrv
**     Processor : MC56F8257
**     Version   : Component 01.014, Driver 02.08, CPU db: 3.00.231
**     Compiler  : Metrowerks DSP C Compiler
**     Date/Time : 2014/4/25, 9:32
**     Abstract  :
**
**     Settings  :
**
**
**     Copyright : 1997 - 2009 Freescale Semiconductor, Inc. All Rights Reserved.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/

#include "Cpu.h"
#include "PWMC1.h"
#include "eFPWM1.h"
#include "MFR1.h"
#include "AD1.h"
#include "WDog1.h"
#include "Hall_U.h"
#include "Hall_V.h"
#include "Hall_W.h"
#include "HallTmr.h"
#include "PC_M1.h"
#include "Inhr1.h"
#include "XBAR1.h"
#include "DA1.h"
#include "SYS_EN.h"
#include "REVorTEMP.h"
#include "Resolver.h"
#include "CpuIsr.h"
#include "PwmMcIsr.h"
#include "HallIsr.h"

/*lint -save -e40 -e718 -e746 -e745 -e939 -e937 -e957 -e505 -e522 -e533 Disable MISRA rule (20,75,71,53,83) checking. */

extern void _EntryPoint(void);         /* Startup routine */

volatile asm void _vectboot(void);
#pragma define_section interrupt_vectorsboot "interrupt_vectorsboot.text"  RX
#pragma section interrupt_vectorsboot begin
volatile asm void _vectboot(void) {
  JMP  _EntryPoint                     /* Reset vector (Used) */
  JMP  _EntryPoint                     /* COP reset vector (Used) */
}
#pragma section interrupt_vectorsboot end

volatile asm void _vect(void);
#pragma define_section interrupt_vectors "interrupt_vectors.text"  RX
#pragma section interrupt_vectors begin
volatile asm void _vect(void) {
  JMP  _EntryPoint                     /* Interrupt no. 0 (Used)   - ivINT_Reset */
  JMP  _EntryPoint                     /* Interrupt no. 1 (Used)   - ivINT_COPReset  */
  JSR  Cpu_Interrupt                   /* Interrupt no. 2 (Unused) - ivINT_Illegal_Instruction  */
  JSR  Cpu_Interrupt                   /* Interrupt no. 3 (Unused) - ivINT_SW3  */
  JSR  Cpu_Interrupt                   /* Interrupt no. 4 (Unused) - ivINT_HWStackOverflow  */
  JSR  Cpu_Interrupt                   /* Interrupt no. 5 (Unused) - ivINT_MisalignedLongWordAccess  */
  JSR  Cpu_Interrupt                   /* Interrupt no. 6 (Unused) - ivINT_OnCE_StepCounter  */
  JSR  Cpu_Interrupt                   /* Interrupt no. 7 (Unused) - ivINT_OnCE_BreakpointUnit  */
  JSR  Cpu_Interrupt                   /* Interrupt no. 8 (Unused) - ivINT_OnCE_TraceBuffer  */
  JSR  Cpu_Interrupt                   /* Interrupt no. 9 (Unused) - ivINT_OnCE_TxREmpty  */
  JSR  Cpu_Interrupt                   /* Interrupt no. 10 (Unused) - ivINT_OnCE_RxRFull  */
  JSR  Cpu_Interrupt                   /* Interrupt no. 11 (Unused) - ivINT_SW2  */
  JSR  Cpu_Interrupt                   /* Interrupt no. 12 (Unused) - ivINT_SW1  */
  JSR  Cpu_Interrupt                   /* Interrupt no. 13 (Unused) - ivINT_SW0  */
  JSR  Cpu_Interrupt                   /* Interrupt no. 14 (Unused) - ivINT_LVI  */
  JSR  Cpu_Interrupt                   /* Interrupt no. 15 (Unused) - ivINT_PLL  */
  JSR  Cpu_Interrupt                   /* Interrupt no. 16 (Unused) - ivINT_TMRB3  */
  JSR  Cpu_Interrupt                   /* Interrupt no. 17 (Unused) - ivINT_TMRB2  */
  JSR  Cpu_Interrupt                   /* Interrupt no. 18 (Unused) - ivINT_TMRB1  */
  JSR  Cpu_Interrupt                   /* Interrupt no. 19 (Unused) - ivINT_TMRB0  */
  JSR  Cpu_Interrupt                   /* Interrupt no. 20 (Unused) - ivINT_ADCB_Complete  */
  JSR  Cpu_Interrupt                   /* Interrupt no. 21 (Unused) - ivINT_ADCA_Complete  */
  JSR  Cpu_Interrupt                   /* Interrupt no. 22 (Unused) - ivINT_ADC_ZC_LE  */
  JSR  Cpu_Interrupt                   /* Interrupt no. 23 (Unused) - ivINT_MSCAN_Tx  */
  JSR  Cpu_Interrupt                   /* Interrupt no. 24 (Unused) - ivINT_MSCAN_Rx  */
  JSR  Cpu_Interrupt                   /* Interrupt no. 25 (Unused) - ivINT_MSCAN_Error  */
  JSR  Cpu_Interrupt                   /* Interrupt no. 26 (Unused) - ivINT_MSCAN_WakeUp  */
  JSR  Inhr1_InterruptError            /* Interrupt no. 27 (Used)   - ivINT_QSCI1_RxError  */
  JSR  Inhr1_InterruptRx               /* Interrupt no. 28 (Used)   - ivINT_QSCI1_RxFull  */
  JSR  Cpu_Interrupt                   /* Interrupt no. 29 (Unused) - ivINT_QSCI1_TxIdle  */
  JSR  Inhr1_InterruptTx               /* Interrupt no. 30 (Used)   - ivINT_QSCI1_TxEmpty  */
  JSR  Cpu_Interrupt                   /* Interrupt no. 31 (Unused) - ivINT_QSCI0_RxError  */
  JSR  Cpu_Interrupt                   /* Interrupt no. 32 (Unused) - ivINT_QSCI0_RxFull  */
  JSR  Cpu_Interrupt                   /* Interrupt no. 33 (Unused) - ivINT_QSCI0_TxIdle  */
  JSR  Cpu_Interrupt                   /* Interrupt no. 34 (Unused) - ivINT_QSCI0_TxEmpty  */
  JSR  Cpu_Interrupt                   /* Interrupt no. 35 (Unused) - ivINT_SPI_TxEmpty  */
  JSR  Cpu_Interrupt                   /* Interrupt no. 36 (Unused) - ivINT_SPI_RxFull  */
  JSR  Cpu_Interrupt                   /* Interrupt no. 37 (Unused) - ivINT_I2C1  */
  JSR  Cpu_Interrupt                   /* Interrupt no. 38 (Unused) - ivINT_I2C0  */
  JSR  Cpu_Interrupt                   /* Interrupt no. 39 (Unused) - ivINT_TMRA3  */
  JSR  Cpu_Interrupt                   /* Interrupt no. 40 (Unused) - ivINT_TMRA2  */
  JSR  Cpu_Interrupt                   /* Interrupt no. 41 (Unused) - ivINT_TMRA1  */
  JSR  Cpu_Interrupt                   /* Interrupt no. 42 (Unused) - ivINT_TMRA0  */
  JSR  PWMC1_InterruptOnFault          /* Interrupt no. 43 (Used)   - ivINT_PWM_Fault  */
  JSR  Cpu_Interrupt                   /* Interrupt no. 44 (Unused) - ivINT_PWM_ReloadError  */
  JSR  Cpu_Interrupt                   /* Interrupt no. 45 (Unused) - ivINT_PWM_SubModule3_Reload  */
  JSR  Cpu_Interrupt                   /* Interrupt no. 46 (Unused) - ivINT_PWM_SubModule3_InputCapture  */
  JSR  Cpu_Interrupt                   /* Interrupt no. 47 (Unused) - ivINT_PWM_SubModule3_Compare  */
  JSR  Cpu_Interrupt                   /* Interrupt no. 48 (Unused) - ivINT_PWM_SubModule2_Reload  */
  JSR  Cpu_Interrupt                   /* Interrupt no. 49 (Unused) - ivINT_PWM_SubModule2_Compare  */
  JSR  Cpu_Interrupt                   /* Interrupt no. 50 (Unused) - ivINT_PWM_SubModule1_Reload  */
  JSR  Cpu_Interrupt                   /* Interrupt no. 51 (Unused) - ivINT_PWM_SubModule1_Compare  */
  JSR  PWMC1_InterruptOnReload         /* Interrupt no. 52 (Used)   - ivINT_PWM_SubModule0_Reload  */
  JSR  Cpu_Interrupt                   /* Interrupt no. 53 (Unused) - ivINT_PWM_SubModule0_Compare  */
  JSR  Cpu_Interrupt                   /* Interrupt no. 54 (Unused) - ivINT_HFM_ERR  */
  JSR  Cpu_Interrupt                   /* Interrupt no. 55 (Unused) - ivINT_HFM_CC  */
  JSR  Cpu_Interrupt                   /* Interrupt no. 56 (Unused) - ivINT_HFM_CBE  */
  JSR  Cpu_Interrupt                   /* Interrupt no. 57 (Unused) - ivINT_CMPC_Rising_Falling  */
  JSR  Cpu_Interrupt                   /* Interrupt no. 58 (Unused) - ivINT_CMPB_Rising_Falling  */
  JSR  Cpu_Interrupt                   /* Interrupt no. 59 (Unused) - ivINT_CMPA_Rising_Falling  */
  JSR  Cpu__ivINT_GPIO_F               /* Interrupt no. 60 (Used)   - ivINT_GPIO_F  */
  JSR  Cpu_Interrupt                   /* Interrupt no. 61 (Unused) - ivINT_GPIO_E  */
  JSR  Cpu_Interrupt                   /* Interrupt no. 62 (Unused) - ivINT_GPIO_D  */
  JSR  Cpu_Interrupt                   /* Interrupt no. 63 (Unused) - ivINT_GPIO_C  */
  JSR  Cpu_Interrupt                   /* Interrupt no. 64 (Unused) - ivINT_GPIO_B  */
  JSR  Cpu_Interrupt                   /* Interrupt no. 65 (Unused) - ivINT_GPIO_A  */
  JSR  Cpu_Interrupt                   /* Interrupt no. 66 (Unused) - ivINT_LP  */
}
#pragma section interrupt_vectors end

/*lint -restore */

/* Disable MISRA rules for interurupt routines */
/*lint -esym(765,Cpu_Interrupt) Disable MISRA rule (23) checking for symbols (Cpu_Interrupt). */
/*lint -esym(765,Inhr1_InterruptError) Disable MISRA rule (23) checking for symbols (Inhr1_InterruptError). */
/*lint -esym(765,Inhr1_InterruptRx) Disable MISRA rule (23) checking for symbols (Inhr1_InterruptRx). */
/*lint -esym(765,Inhr1_InterruptTx) Disable MISRA rule (23) checking for symbols (Inhr1_InterruptTx). */
/*lint -esym(765,PWMC1_InterruptOnFault) Disable MISRA rule (23) checking for symbols (PWMC1_InterruptOnFault). */
/*lint -esym(765,PWMC1_InterruptOnReload) Disable MISRA rule (23) checking for symbols (PWMC1_InterruptOnReload). */
/*lint -esym(765,Cpu__ivINT_GPIO_F) Disable MISRA rule (23) checking for symbols (Cpu__ivINT_GPIO_F). */

/*
** ###################################################################
**
**     This file was created by Processor Expert 3.00 [04.35]
**     for the Freescale 56800 series of microcontrollers.
**
** ###################################################################
*/
