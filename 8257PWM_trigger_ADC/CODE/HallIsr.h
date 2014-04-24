/** ###################################################################
**     Filename  : HallIsr.H
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
**         Hall_W_OnInterrupt - void Hall_W_OnInterrupt(void);
**         Hall_V_OnInterrupt - void Hall_V_OnInterrupt(void);
**         Hall_U_OnInterrupt - void Hall_U_OnInterrupt(void);
**
** ###################################################################*/

#ifndef __HallIsr_H
#define __HallIsr_H
/* MODULE HallIsr */

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

void Hall_W_OnInterrupt(void);
/*
** ===================================================================
**     Event       :  Hall_W_OnInterrupt (module HallIsr)
**
**     Component   :  Hall_W [ExtInt]
**     Description :
**         This event is called when an active signal edge/level has
**         occurred.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void Hall_V_OnInterrupt(void);
/*
** ===================================================================
**     Event       :  Hall_V_OnInterrupt (module HallIsr)
**
**     Component   :  Hall_V [ExtInt]
**     Description :
**         This event is called when an active signal edge/level has
**         occurred.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void Hall_U_OnInterrupt(void);
/*
** ===================================================================
**     Event       :  Hall_U_OnInterrupt (module HallIsr)
**
**     Component   :  Hall_U [ExtInt]
**     Description :
**         This event is called when an active signal edge/level has
**         occurred.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

/* END HallIsr */
#endif /* __HallIsr_H*/

/*
** ###################################################################
**
**     This file was created by Processor Expert 3.00 [04.35]
**     for the Freescale 56800 series of microcontrollers.
**
** ###################################################################
*/
