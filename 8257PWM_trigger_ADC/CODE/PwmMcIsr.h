/** ###################################################################
**     Filename  : PwmMcIsr.H
**     Project   : PmsmFocDrv
**     Processor : MC56F8257
**     Component : Events
**     Version   : Driver 01.03
**     Compiler  : Metrowerks DSP C Compiler
**     Date/Time : 2013-10-1, ÏÂÎç 09:23
**     Abstract  :
**         This is user's event module.
**         Put your event handler code here.
**     Settings  :
**     Contents  :
**         PWMC1_OnReload - void PWMC1_OnReload(void);
**         PWMC1_OnFault0 - void PWMC1_OnFault0(void);
**
** ###################################################################*/

#ifndef __PwmMcIsr_H
#define __PwmMcIsr_H
/* MODULE PwmMcIsr */

#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
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

void PWMC1_OnReload(void);
/*
** ===================================================================
**     Event       :  PWMC1_OnReload (module PwmMcIsr)
**
**     Component   :  PWMC1 [PWMMC]
**     Description :
**         This event is called before PWM cycle according to reload
**         frequency. The event is invoked only when the component is
**         enabled - <Enable> and the events are enabled - <EnableEvent>.
**         This event is enabled only if i<Interrupt service/event> is
**         enabled.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

void PWMC1_OnFault0(void);
/*
** ===================================================================
**     Event       :  PWMC1_OnFault0 (module PwmMcIsr)
**
**     Component   :  PWMC1 [PWMMC]
**     Description :
**         This event is called when fault 0 occurs. Only when the
**         component is enabled - <Enable> and the events are enabled -
**         <EnableEvent>. This event is enabled only if <Interrupt
**         service/event> is enabled and property <Fault protection> is
**         set to controlled by this component. The event clears Fault
**         flag only when the Fault is set to the automatic clearing
**         mode. When the Fault is set to the manual clearing mode, the
**         Fault flag must be cleared by the user using ClearFaultFlag()
**         method.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/


/* END PwmMcIsr */
#endif /* __PwmMcIsr_H*/

/*
** ###################################################################
**
**     This file was created by Processor Expert 3.00 [04.35]
**     for the Freescale 56800 series of microcontrollers.
**
** ###################################################################
*/
