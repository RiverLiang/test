/** ###################################################################
**     Filename  : PmsmFocDrv.C
**     Project   : PmsmFocDrv
**     Processor : MC56F8257
**     Version   : Driver 01.14
**     Compiler  : Metrowerks DSP C Compiler
**     Date/Time : 2013-10-1, ÏÂÎç 06:34
**     Abstract  :
**         Main module.
**         This module contains user's application code.
**     Settings  :
**     Contents  :
**         No public methods
**
** ###################################################################*/
/* MODULE PmsmFocDrv */


/* Including needed modules to compile this module/procedure */
#include "Cpu.h"
#include "CpuIsr.h"
#include "PwmMcIsr.h"
#include "HallIsr.h"
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
/* Including shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"

#include "User_Header.h"


void main(void)
{
  /* Write your local variable definition here */
  /*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
	PE_low_level_init();
  /*** End of Processor Expert internal initialization.                    ***/

  /* Write your code here */

	setReg(ADC_CLIST1,0x12);
	setReg(ADC_SDIS,0xFF88);
	setRegBitGroup(ADC_CTRL1,SMODE,0x01);
	AD1_Enable();
	

	Cpu_EnableInt();

	while(1)
	{
		WDog1_Clear();
		

	}
}

/* END PmsmFocDrv */
/*
** ###################################################################
**
**     This file was created by Processor Expert 3.00 [04.35]
**     for the Freescale 56800 series of microcontrollers.
**
** ###################################################################
*/
