/** ###################################################################
**     Filename  : PwmMcIsr.C
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
/* MODULE PwmMcIsr */

#include "Cpu.h"
#include "CpuIsr.h"
#include "PwmMcIsr.h"
#include "HallIsr.h"

/* User includes (#include below this line is not maintained by Processor Expert) */
#include "User_Header.h"
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
#pragma interrupt called /* Comment this line if the appropriate 'Interrupt preserve registers' property */
                         /* is set to 'yes' (#pragma interrupt saveall is generated before the ISR)      */
void PWMC1_OnReload(void)
{	

  /* Write your code here ... */
	static u2 adVdc = 0; 
	static u2 adIu = 0; 
	static u2 adIv = 0; 
	static u2 adIw = 0; 
	
	adVdc = AD_VDC;

	adIu = AD_IU;
	adIv = AD_IV;
	adIw = AD_IW;

	

	
//	setReg( PWM_SM0_VAL2, +(halfPwmMcDutyU) );
//	setReg( PWM_SM0_VAL3, -(halfPwmMcDutyU) );	
	
//	setReg( PWM_SM1_VAL2, +(halfPwmMcDutyV) );
//	setReg( PWM_SM1_VAL3, -(halfPwmMcDutyV) );	
	
//	setReg( PWM_SM2_VAL2, +(halfPwmMcDutyW) );
//	setReg( PWM_SM2_VAL3, -(halfPwmMcDutyW) );
	
	PWMC1_Load();
		 
 }

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
#pragma interrupt called /* Comment this line if the appropriate 'Interrupt preserve registers' property */
                         /* is set to 'yes' (#pragma interrupt saveall is generated before the ISR)      */
void PWMC1_OnFault0(void)
{
  /* Write your code here ... */
}

/* END PwmMcIsr */

/*
** ###################################################################
**
**     This file was created by Processor Expert 3.00 [04.35]
**     for the Freescale 56800 series of microcontrollers.
**
** ###################################################################
*/
