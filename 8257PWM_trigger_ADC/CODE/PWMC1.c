/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename  : PWMC1.C
**     Project   : PmsmFocDrv
**     Processor : MC56F8257
**     Component : PWMMC
**     Version   : Component 01.703, Driver 01.01, CPU db: 3.00.231
**     Compiler  : Metrowerks DSP C Compiler
**     Date/Time : 2014/4/25, 9:32
**     Abstract  :
**         This bean "PWMMC" implements 6-channel center-aligned or 
**         edge-aligned pulse-width modulator for AC motor control, which 
**         is presented on chip. The device is capable of controlling most 
**         motor types: AC induction motors (ACIM), both brushless (BLDC) 
**         and brush DC motors (BDC), switched (SRM) and variable reluctance  
**         motors (VRM),and stepper motors.
**         Another possibility of using this bean is as a pulse-width modulation 
**         generator that generates 6 signals with variable duty and fixed cycle.
**     Settings  :
**          Component name                                 : PWMC1
**          Device                                         : eFlexPWM
**          Device                                         : eFlexPWM_SM0_Timer
**          Align                                          : center-aligned mode
**          Peripheral initialization                      : eFPWM1
**          Reload                                         : 1
**          Frequency/period                               : 166 �s
**          Output Frequency                               : 6.024 kHz
**          Same frequency in modes                        : yes
**          Dead-time                                      : 2.8 �s
**          Dead-time 1                                    : 2.8 �s
**          Interrupt service/event                        : Enabled
**            Reload interrupt priority                    : medium priority
**            Interrupt on reload                          : INT_PWM_SubModule0_Reload
**            Fault protection                             : Enabled
**              Interrupt on fault 0                       : INT_PWM_Fault
**              Fault 0 interrupt priority                 : maximal priority
**              Interrupt on fault 1                       : INT_PWM_Fault
**              Fault 1 interrupt priority                 : maximal priority
**              Interrupt on fault 2                       : INT_PWM_Fault
**              Fault 2 interrupt priority                 : maximal priority
**              Interrupt on fault 3                       : INT_PWM_Fault
**              Fault 3 interrupt priority                 : maximal priority
**            Interrupt preserve registers                 : yes
**          Channel 0                                      : 
**            Channel                                      : eFlexPWM_SM0_ChannelA
**            PWM pin                                      : GPIOE1_PWM0A
**            PWM pin signal                               : 
**          Channel 1                                      : Enabled
**            Channel                                      : eFlexPWM_SM0_ChannelB
**            PWM pin                                      : GPIOE0_PWM0B
**            PWM pin signal                               : 
**          Channel 2                                      : Enabled
**            Channel                                      : eFlexPWM_SM1_ChannelA
**            PWM pin                                      : GPIOE3_PWM1A
**            PWM pin signal                               : 
**          Channel 3                                      : Enabled
**            Channel                                      : eFlexPWM_SM1_ChannelB
**            PWM pin                                      : GPIOE2_PWM1B
**            PWM pin signal                               : 
**          Channel 4                                      : Enabled
**            Channel                                      : eFlexPWM_SM2_ChannelA
**            PWM pin                                      : GPIOE5_PWM2A_XB_IN3
**            PWM pin signal                               : 
**          Channel 5                                      : Enabled
**            Channel                                      : eFlexPWM_SM2_ChannelB
**            PWM pin                                      : GPIOE4_PWM2B_XB_IN2
**            PWM pin signal                               : 
**          Fault protection                               : controlled by this component
**            Fault 0                                      : Enabled
**              Fault clearing mode                        : automatic
**            Fault 1                                      : Disabled
**            Fault 2                                      : Disabled
**            Fault 3                                      : Disabled
**          Initialization                                 : 
**            Enabled in init. code                        : yes
**            Events enabled in init.                      : yes
**          CPU clock/speed selection                      : 
**            High speed mode                              : This component enabled
**            Low speed mode                               : This component disabled
**            Slow speed mode                              : This component disabled
**          Simulation output mode                         : PWM
**          High output value                              : 1.0
**          Low output value                               : 0.0
**     Contents  :
**         Load             - void PWMC1_Load(void);
**         OutputPadEnable  - void PWMC1_OutputPadEnable(void);
**         OutputPadDisable - void PWMC1_OutputPadDisable(void);
**
**     Copyright : 1997 - 2009 Freescale Semiconductor, Inc. All Rights Reserved.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/


/* MODULE PWMC1. */

#include "PwmMcIsr.h"
#include "PWMC1.h"


/*
** ===================================================================
**     Method      :  PWMC1_InterruptOnReload (component PWMMC)
**
**     Description :
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
#pragma interrupt alignsp saveall
void PWMC1_InterruptOnReload(void)
{
  setRegBits(PWM_SM0_STS,0x1000);      /* Clear reload flag */
    PWMC1_OnReload();                  /* Invoke user event */
}

/*
** ===================================================================
**     Method      :  PWMC1_InterruptOnFault (component PWMMC)
**
**     Description :
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
#pragma interrupt alignsp saveall
void PWMC1_InterruptOnFault(void)
{
  if (getRegBits(PWM_FSTS, (0x01 << 0x00))) {
    setRegBits(PWM_FSTS, (0x01 << 0x00)); /* Reset interrupt request flag */
    PWMC1_OnFault0();                  /* Invoke user event */
  }
}

/*
** ===================================================================
**     Method      :  PWMC1_Init (component PWMMC)
**
**     Description :
**         Initializes the associated peripheral(s) and the bean internal 
**         variables. The method is called automatically as a part of the 
**         application initialization code.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
void PWMC1_Init(void)
{
  eFPWM1_Init();
}

/*
** ===================================================================
**     Method      :  PWMC1_Load (component PWMMC)
**
**     Description :
**         Apply last setting of the methods <SetDuty>, <SetDutyPercent>,
**         both <SetRatio*>, <SetPeriod> and <SetPrescaler>.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
/*
void PWMC1_Load(void)

**  This method is implemented as a macro. See PWMC1.h file.  **

*/

/*
** ===================================================================
**     Method      :  PWMC1_OutputPadEnable (component PWMMC)
**
**     Description :
**         Method enables output pads.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
/*
void PWMC1_OutputPadEnable(void)

**  This method is implemented as a macro. See PWMC1.h file.  **

*/

/*
** ===================================================================
**     Method      :  PWMC1_OutputPadDisable (component PWMMC)
**
**     Description :
**         Method disables output pads.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
/*
void PWMC1_OutputPadDisable(void)

**  This method is implemented as a macro. See PWMC1.h file.  **

*/

/* END PWMC1. */

/*
** ###################################################################
**
**     This file was created by Processor Expert 3.00 [04.35]
**     for the Freescale 56800 series of microcontrollers.
**
** ###################################################################
*/
