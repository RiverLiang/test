/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename  : HallTmr.H
**     Project   : PmsmFocDrv
**     Processor : MC56F8257
**     Component : FreeCntr
**     Version   : Component 01.112, Driver 02.04, CPU db: 3.00.231
**     Compiler  : Metrowerks DSP C Compiler
**     Date/Time : 2014/4/25, 9:32
**     Abstract  :
**         This device "FreeCntr" implements a free running counter for
**         time measurement.
**     Settings  :
**         Timer name                  : TMRA01 (32-bit)
**         Counter shared              : No
**
**         High speed mode
**             Prescaler               : divide-by-1
**             Clock                   : 60000000 Hz
**           Period
**             Xtal ticks              : 572662306
**             microseconds            : 71582788
**             milliseconds            : 71583
**             seconds                 : 72
**             seconds (real)          : 71.582788266667
**           Frequency of counting (Bus clock / prescaler)
**             Hz                      : 60000000
**
**         Initialization:
**              Timer                  : Enabled
**
**         Timer registers
**              Counter                : TMRA1_CNTR [F015]
**              Mode                   : TMRA1_CTRL [F016]
**              Run                    : TMRA1_CTRL [F016]
**              Prescaler              : TMRA1_CTRL [F016]
**
**         User handling procedure     : not specified
**     Contents  :
**         Reset           - byte HallTmr_Reset(void);
**         GetCounterValue - byte HallTmr_GetCounterValue(HallTmr_TTimerValue *Value);
**
**     Copyright : 1997 - 2009 Freescale Semiconductor, Inc. All Rights Reserved.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/

#ifndef __HallTmr
#define __HallTmr

/* MODULE HallTmr. */

/*Include shared modules, which are used for whole project*/
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
#include "Cpu.h"

#ifndef __BWUserType_HallTmr_TTimerValue
#define __BWUserType_HallTmr_TTimerValue
  typedef dword HallTmr_TTimerValue;   /* Counter or compare value, width depend on timer width, 8, 16, 32 or 64 bits. */
#endif

#define HallTmr_PRESCALER_VALUE 0x01UL /* Initial prescaler value of the timer. It is available only if the bean is enabled in high speed mode. */
#define HallTmr_PRESCALER_VALUE_HIGH 0x01UL /* Prescaler value of the timer in high speed mode. It is available only if the bean is enabled in high speed mode. */
#define HallTmr_COUNTER_INPUT_CLOCK_HIGH 0x03938700UL /* Counter input clock value in high speed mode [Hz] (integer number). It is available only if the bean is enabled in high speed mode. */
#define HallTmr_COUNTER_INPUT_CLOCK 0x03938700UL /* Initial counter input clock value [Hz] (integer number). It is available only if the bean is enabled in high speed mode. */
#define HallTmr_UP_COUNTER 1           /* The timer counts upwards */
/* Deprecated constants */
#define HallTmr_FChigh     0x03938700UL /* Frequency of counting in high speed CPU mode */

byte HallTmr_Reset(void);
/*
** ===================================================================
**     Method      :  HallTmr_Reset (component FreeCntr)
**
**     Description :
**         This method resets the timer-counter (sets to zero for
**         up-counting HW or to appropriate value for down-counting HW).
**         The method is available only if the counter register can be
**         set by software and the counter is not shared.
**     Parameters  : None
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
** ===================================================================
*/

byte HallTmr_GetCounterValue(HallTmr_TTimerValue *Value);
/*
** ===================================================================
**     Method      :  HallTmr_GetCounterValue (component FreeCntr)
**
**     Description :
**         This method returns a content of counter.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * Value           - A pointer to the returned 32-bit value.
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
** ===================================================================
*/

void HallTmr_Init(void);
/*
** ===================================================================
**     Method      :  HallTmr_Init (component FreeCntr)
**
**     Description :
**         Initializes the associated peripheral(s) and the beans 
**         internal variables. The method is called automatically as a 
**         part of the application initialization code.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/

/* END HallTmr. */

#endif /* ifndef __HallTmr */
/*
** ###################################################################
**
**     This file was created by Processor Expert 3.00 [04.35]
**     for the Freescale 56800 series of microcontrollers.
**
** ###################################################################
*/
