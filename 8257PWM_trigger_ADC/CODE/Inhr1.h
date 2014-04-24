/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename  : Inhr1.H
**     Project   : PmsmFocDrv
**     Processor : MC56F8257
**     Component : AsynchroSerial
**     Version   : Component 02.472, Driver 02.06, CPU db: 3.00.231
**     Compiler  : Metrowerks DSP C Compiler
**     Date/Time : 2013-10-2, ���� 03:30
**     Abstract  :
**         This bean "AsynchroSerial" implements an asynchronous serial
**         communication. The bean supports different settings of
**         parity, word width, stop-bit and communication speed,
**         user can select interrupt or polling handler.
**         Communication speed can be changed also in runtime.
**         The bean requires one on-chip asynchronous serial channel.
**     Settings  :
**         Serial channel              : QSCI1
**
**         Protocol
**             Init baud rate          : 9600baud
**             Width                   : 8 bits
**             Stop bits               : 1
**             Parity                  : none
**             Breaks                  : Disabled
**             Input buffer size       : 0
**             Output buffer size      : 0
**
**         Registers
**             Input buffer            : QSCI1_DATA [F1F4]
**             Output buffer           : QSCI1_DATA [F1F4]
**             Control register        : QSCI1_CTRL1 [F1F1]
**             Mode register           : QSCI1_CTRL1 [F1F1]
**             Baud setting reg.       : QSCI1_RATE [F1F0]
**
**         Input interrupt
**             Vector name             : INT_QSCI1_RxFull
**             Priority                : 1
**
**         Output interrupt
**             Vector name             : INT_QSCI1_TxEmpty
**             Priority                : 1
**
**         Used pins:
**         ----------------------------------------------------------
**           Function | On package           |    Name
**         ----------------------------------------------------------
**            Input   |     42               |  GPIOF5_RXD1_XB_OUT5
**            Output  |     37               |  GPIOC11_CANTX_SCL1_TXD1
**         ----------------------------------------------------------
**
**
**
**     Contents  :
**         RecvChar - byte Inhr1_RecvChar(Inhr1_TComData *Chr);
**         SendChar - byte Inhr1_SendChar(Inhr1_TComData Chr);
**         GetError - byte Inhr1_GetError(Inhr1_TError *Err);
**
**     Copyright : 1997 - 2009 Freescale Semiconductor, Inc. All Rights Reserved.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/

#ifndef __Inhr1
#define __Inhr1

/* MODULE Inhr1. */

#include "Cpu.h"



#ifndef __BWUserType_Inhr1_TError
#define __BWUserType_Inhr1_TError
  typedef union {
    byte err;
    struct {
      bool OverRun  : 1;               /* Overrun error flag */
      bool Framing  : 1;               /* Framing error flag */
      bool Parity   : 1;               /* Parity error flag */
      bool RxBufOvf : 1;               /* Rx buffer full error flag */
      bool Noise    : 1;               /* Noise error flag */
      bool Break    : 1;               /* Break detect */
      bool LINSync  : 1;               /* LIN synchronization error */
      bool BitError  : 1;              /* Bit error flag - mismatch to the expected value happened. */
    } errName;
  } Inhr1_TError;                      /* Error flags. For languages which don't support bit access is byte access only to error flags possible. */
#endif

#ifndef __BWUserType_Inhr1_TComData
#define __BWUserType_Inhr1_TComData
  typedef byte Inhr1_TComData;         /* User type for communication. Size of this type depends on the communication data witdh */
#endif

byte Inhr1_RecvChar(Inhr1_TComData *Chr);
/*
** ===================================================================
**     Method      :  Inhr1_RecvChar (component AsynchroSerial)
**
**     Description :
**         If any data is received, this method returns one
**         character, otherwise it returns an error code (it does
**         not wait for data). This method is enabled only if the
**         receiver property is enabled.
**         [Note:] Because the preferred method to handle error and
**         break exception in the interrupt mode is to use events
**         <OnError> and <OnBreak> the return value ERR_RXEMPTY has
**         higher priority than other error codes. As a consequence
**         the information about an exception in interrupt mode is
**         returned only if there is a valid character ready to be
**         read.
**         Version specific information for Freescale 56800
**         derivatives ] 
**         DMA mode:
**         If DMA controller is available on the selected CPU and
**         the receiver is configured to use DMA controller then
**         this method only sets the selected DMA channel. Then the
**         status of the DMA transfer can be checked using
**         GetCharsInRxBuf method. See an example of a typical usage
**         for details about the communication using DMA.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * Chr             - Pointer to a received character
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
**                           ERR_RXEMPTY - No data in receiver
**                           ERR_BREAK - Break character is detected
**                           (only when the <Interrupt service>
**                           property is disabled and the <Break
**                           signal> property is enabled)
**                           ERR_COMMON - common error occurred (the
**                           <GetError> method can be used for error
**                           specification)
**                           Version specific information for
**                           Freescale 56800 derivatives ] 
**                           DMA mode:
**                           If DMA controller is available on the
**                           selected CPU and the receiver is
**                           configured to use DMA controller then
**                           only ERR_OK, ERR_RXEMPTY, and ERR_SPEED
**                           error code can be returned from this
**                           method.
** ===================================================================
*/

byte Inhr1_SendChar(Inhr1_TComData Chr);
/*
** ===================================================================
**     Method      :  Inhr1_SendChar (component AsynchroSerial)
**
**     Description :
**         Sends one character to the channel. If the bean is
**         temporarily disabled (Disable method) SendChar method
**         only stores data into an output buffer. In case of a zero
**         output buffer size, only one character can be stored.
**         Enabling the bean (Enable method) starts the transmission
**         of the stored data. This method is available only if the
**         transmitter property is enabled.
**         Version specific information for Freescale 56800
**         derivatives ] 
**         DMA mode:
**         If DMA controller is available on the selected CPU and
**         the transmitter is configured to use DMA controller then
**         this method only sets selected DMA channel. Then the
**         status of the DMA transfer can be checked using
**         GetCharsInTxBuf method. See an example of a typical usage
**         for details about communication using DMA.
**     Parameters  :
**         NAME            - DESCRIPTION
**         Chr             - Character to send
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
**                           ERR_TXFULL - Transmitter is full
** ===================================================================
*/

byte Inhr1_GetError(Inhr1_TError *Err);
/*
** ===================================================================
**     Method      :  Inhr1_GetError (component AsynchroSerial)
**
**     Description :
**         Returns a set of errors on the channel (errors that
**         cannot be returned by given methods). The errors
**         accumulate in a set; after calling [GetError] this set is
**         returned and cleared.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * Err             - Pointer to the returned set of errors
**     Returns     :
**         ---             - Error code (if GetError did not succeed),
**                           possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
** ===================================================================
*/

void Inhr1_InterruptRx(void);
/*
** ===================================================================
**     Method      :  Inhr1_InterruptRx (component AsynchroSerial)
**
**     Description :
**         The method services the receive interrupt of the selected 
**         peripheral(s) and eventually invokes the bean's event(s).
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/

void Inhr1_InterruptTx(void);
/*
** ===================================================================
**     Method      :  Inhr1_InterruptTx (component AsynchroSerial)
**
**     Description :
**         The method services the receive interrupt of the selected 
**         peripheral(s) and eventually invokes the bean's event(s).
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/

void Inhr1_InterruptError(void);
/*
** ===================================================================
**     Method      :  Inhr1_InterruptError (component AsynchroSerial)
**
**     Description :
**         The method services the receive interrupt of the selected 
**         peripheral(s) and eventually invokes the bean's event(s).
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/

void Inhr1_Init(void);
/*
** ===================================================================
**     Method      :  Inhr1_Init (component AsynchroSerial)
**
**     Description :
**         Initializes the associated peripheral(s) and the bean internal 
**         variables. The method is called automatically as a part of the 
**         application initialization code.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/



/* END Inhr1. */

/*
** ###################################################################
**
**     This file was created by Processor Expert 3.00 [04.35]
**     for the Freescale 56800 series of microcontrollers.
**
** ###################################################################
*/

#endif /* ifndef __Inhr1 */
