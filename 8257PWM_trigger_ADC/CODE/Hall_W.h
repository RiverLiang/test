/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename  : Hall_W.H
**     Project   : PmsmFocDrv
**     Processor : MC56F8257
**     Component : ExtInt
**     Version   : Component 02.094, Driver 02.04, CPU db: 3.00.231
**     Compiler  : Metrowerks DSP C Compiler
**     Date/Time : 2014/4/25, 9:32
**     Abstract  :
**         This bean "ExtInt" implements an external 
**         interrupt, its control methods and interrupt/event 
**         handling procedure.
**         The bean uses one pin which generates interrupt on 
**         selected edge.
**     Settings  :
**         Interrupt name              : INT_GPIO_F
**         User handling procedure     : Hall_W_OnInterrupt
**
**         Used pin                    :
**             ----------------------------------------------------
**                Number (on package)  |    Name
**             ----------------------------------------------------
**                       50            |  GPIOF1_CLKO1_XB_IN7
**             ----------------------------------------------------
**
**         Port name                   : GPIOF_Low
**
**         Bit number (in port)        : 1
**         Bit mask of the port        : 0002
**
**         Signal edge/level           : rising
**         Priority                    : 2
**         Pull option                 : off
**         Initial state               : Enabled
**
**         Edge register               : GPIO_F_IPOL [F196]
**         Priority register           : INTC_IPR6 [F0C6]
**         Enable register             : GPIO_F_IEN [F195]
**         Request register            : GPIO_F_IEDGE [F198]
**
**         Port data register          : GPIO_F_DATA [F191]
**         Port control register       : GPIO_F_DDIR [F192]
**         Port function register      : GPIO_F_PEREN [F193]
**     Contents  :
**         GetVal  - bool Hall_W_GetVal(void);
**         SetEdge - byte Hall_W_SetEdge(byte edge);
**
**     Copyright : 1997 - 2009 Freescale Semiconductor, Inc. All Rights Reserved.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/

#ifndef __Hall_W_H
#define __Hall_W_H

/* MODULE Hall_W. */

/*Including shared modules, which are used in the whole project*/
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
#include "HallIsr.h"
#include "Cpu.h"


#define Hall_W_PIN_MASK         ((byte)0x02) /* Pin mask */

#define Hall_W_GetVal() ((bool)(getRegBits(GPIO_F_RDATA,Hall_W_PIN_MASK)))
/*
** ===================================================================
**     Method      :  Hall_W_GetVal (component ExtInt)
**
**     Description :
**         Returns the actual value of the input pin of the bean.
**     Parameters  : None
**     Returns     :
**         ---             - Returned input value. Possible values:
**                           FALSE - logical "0" (Low level)
**                           TRUE - logical "1" (High level)
** ===================================================================
*/

byte Hall_W_SetEdge(byte edge);
/*
** ===================================================================
**     Method      :  Hall_W_SetEdge (component ExtInt)
**
**     Description :
**         Sets the edge type for this bean that generates the
**         interrupt.
**     Parameters  :
**         NAME            - DESCRIPTION
**         edge            - Edge type:
**                           0 - falling edge
**                           1 - rising edge
**                           2 - both edges
**                           3 - low level
**                           4 - high level
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_RANGE - Value is out of range
** ===================================================================
*/

/* END Hall_W. */

#endif /* __Hall_W_H*/
/*
** ###################################################################
**
**     This file was created by Processor Expert 3.00 [04.35]
**     for the Freescale 56800 series of microcontrollers.
**
** ###################################################################
*/
