/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename  : WDog1.C
**     Project   : PmsmFocDrv
**     Processor : MC56F8257
**     Component : WatchDog
**     Version   : Component 02.121, Driver 02.01, CPU db: 3.00.231
**     Compiler  : Metrowerks DSP C Compiler
**     Date/Time : 2014/4/25, 9:32
**     Abstract  :
**         This device "WatchDog" implements a watchdog.
**         When enabled, the watchdog timer counts until it reaches
**         a critical value corresponding to the period specified
**         in 'Properties'. Then, the watchdog causes a CPU reset.
**         Applications may clear the timer before it reaches the critical
**         value. The timer then restarts the watchdog counter.
**         Watchdog is used for increasing the safety of the system
**         (unforeseeable situations can cause system crash or an
**         infinite loop - watchdog can restart the system or handle
**         the situation).
**
**         Note: Watchdog can be enabled or disabled in the initialization
**               code only. If the watchdog is once enabled user have
**               to call Clear method in defined time intervals.
**     Settings  :
**         Watchdog causes             : Reset CPU
**
**         Initial Watchdog state      : Enabled
**
**         High speed mode
**           Watchdog period/frequency
**             microseconds            : 171
**             Hz                      : 5859
**             kHz                     : 6
**
**         Run register                : COP_CTRL  [F110]
**         Mode register               : COP_CTRL  [F110]
**         Prescaler register          : COP_TOUT  [F111]
**     Contents  :
**         Enable - byte WDog1_Enable(void);
**         Clear  - byte WDog1_Clear(void);
**
**     Copyright : 1997 - 2009 Freescale Semiconductor, Inc. All Rights Reserved.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/

/* MODULE WDog1. */

#include "WDog1.h"


/*
** ===================================================================
**     Method      :  WDog1_Enable (component WatchDog)
**
**     Description :
**         Enables the bean - starts the watchdog timer counting. 
**     Parameters  : None
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
**                           ERR_PROTECT - This device does is protected
** ===================================================================
*/
byte WDog1_Enable(void)
{
  setRegBit(COP_CTRL,CEN);             /* Enable COP */
  return ERR_OK;                       /* OK */
}

/*
** ===================================================================
**     Method      :  WDog1_Clear (component WatchDog)
**
**     Description :
**         Clears the watchdog timer (it makes the timer restart from
**         zero).
**     Parameters  : None
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
**                           ERR_DISABLED - The Bean is disabled
** ===================================================================
*/
byte WDog1_Clear(void)
{
  setReg(COP_CNTR,0x5555);             /* Write first key */
  setReg(COP_CNTR,0xAAAA);             /* Write second key */
  return ERR_OK;                       /* OK */
}

/*
** ===================================================================
**     Method      :  WDog1_Init (component WatchDog)
**
**     Description :
**         Initializes the associated peripheral(s) and the beans 
**         internal variables. The method is called automatically as a 
**         part of the application initialization code.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
void WDog1_Init(void)
{
  /* COP_CTRL: ??=0,??=0,??=0,??=0,??=0,??=0,PSS=0,??=0,CLKSEL=2,CLOREN=0,CSEN=0,CWEN=0,CEN=0,CWP=0 */
  setReg(COP_CTRL,0x40);               /* Set up mode */
  setReg(COP_TOUT,0x27FF);             /* Initial timeout value */
}

/* END WDog1. */

/*
** ###################################################################
**
**     This file was created by Processor Expert 3.00 [04.35]
**     for the Freescale 56800 series of microcontrollers.
**
** ###################################################################
*/
