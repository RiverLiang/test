/** ###################################################################
**     Filename  : HallIsr.C
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
/* MODULE HallIsr */

#include "Cpu.h"
#include "CpuIsr.h"
#include "PwmMcIsr.h"
#include "HallIsr.h"

/* User includes (#include below this line is not maintained by Processor Expert) */

#include "User_Header.h"


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
#pragma interrupt called /* Comment this line if the appropriate 'Interrupt preserve registers' property */
                         /* is set to 'yes' (#pragma interrupt saveall is generated before the ISR)      */
void Hall_W_OnInterrupt(void)
{
  /* place your Hall_W interrupt procedure body here */
  

}


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
#pragma interrupt called /* Comment this line if the appropriate 'Interrupt preserve registers' property */
                         /* is set to 'yes' (#pragma interrupt saveall is generated before the ISR)      */
void Hall_V_OnInterrupt(void)
{
  /* place your Hall_V interrupt procedure body here */
 
}



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
#pragma interrupt called /* Comment this line if the appropriate 'Interrupt preserve registers' property */
                         /* is set to 'yes' (#pragma interrupt saveall is generated before the ISR)      */
void Hall_U_OnInterrupt(void)
{
  /* place your Hall_U interrupt procedure body here */
  

}


/* END HallIsr */

/*
** ###################################################################
**
**     This file was created by Processor Expert 3.00 [04.35]
**     for the Freescale 56800 series of microcontrollers.
**
** ###################################################################
*/
