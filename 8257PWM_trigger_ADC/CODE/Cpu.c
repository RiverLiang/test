/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename  : Cpu.C
**     Project   : PmsmFocDrv
**     Processor : MC56F8257
**     Component : 56F8257
**     Version   : Component 01.014, Driver 02.08, CPU db: 3.00.231
**     Datasheet : MC56F824x/5xPB Rev. 1.0.0, 09/2008; MC56F82XXRM Rev. 0 Draft A 11/2008
**     Compiler  : Metrowerks DSP C Compiler
**     Date/Time : 2013-10-3, ���� 11:17
**     Abstract  :
**
**     Settings  :
**
**     Contents  :
**         EnableInt      - void Cpu_EnableInt(void);
**         DisableInt     - void Cpu_DisableInt(void);
**         GetResetSource - byte Cpu_GetResetSource(void);
**         SetWaitMode    - void Cpu_SetWaitMode(void);
**         SetStopMode    - void Cpu_SetStopMode(void);
**         Delay100US     - asm void Cpu_Delay100US(word us100);
**
**     (c) Freescale Semiconductor
**     2004 All Rights Reserved
**
**     Copyright : 1997 - 2009 Freescale Semiconductor, Inc. All Rights Reserved.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/

/* MODULE Cpu. */
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
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
#include "CpuIsr.h"
#include "PwmMcIsr.h"
#include "HallIsr.h"
#include "Cpu.h"


/* Global variables */
volatile word SR_lock = 0;             /* Lock */
volatile word SR_reg;                  /* Current value of the SR register */
/*
** ===================================================================
**     Method      :  Cpu_Interrupt (component 56F8257)
**
**     Description :
**         The method services unhandled interrupt vectors.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
#pragma interrupt alignsp
void Cpu_Interrupt(void)
{
  asm(DEBUGHLT);                       /* Halt the core and placing it in the debug processing state */
}

/*
** ===================================================================
**     Method      :  Cpu__ivINT_GPIO_F (component 56F8257)
**
**     Description :
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
#pragma interrupt alignsp saveall
void Cpu__ivINT_GPIO_F(void)
{
  word regIntFlag_GPIO_F_IPEND = getReg(GPIO_F_IPEND);

  if (regIntFlag_GPIO_F_IPEND & GPIO_F_IPEND_IP6_MASK) /* Is an interrupt flag set? */
  setReg16(GPIO_F_IEDGE, GPIO_F_IEDGE_IES6_MASK);
  if (regIntFlag_GPIO_F_IPEND & GPIO_F_IPEND_IP7_MASK) /* Is an interrupt flag set? */
  setReg16(GPIO_F_IEDGE, GPIO_F_IEDGE_IES7_MASK);
  if (regIntFlag_GPIO_F_IPEND & GPIO_F_IPEND_IP1_MASK) /* Is an interrupt flag set? */
  setReg16(GPIO_F_IEDGE, GPIO_F_IEDGE_IES1_MASK);
  if (regIntFlag_GPIO_F_IPEND & GPIO_F_IPEND_IP6_MASK) { /* Is the interrupt flag set? */
    Hall_U_OnInterrupt();              /* Call the service routine */
  }
  if (regIntFlag_GPIO_F_IPEND & GPIO_F_IPEND_IP7_MASK) { /* Is the interrupt flag set? */
    Hall_V_OnInterrupt();              /* Call the service routine */
  }
  if (regIntFlag_GPIO_F_IPEND & GPIO_F_IPEND_IP1_MASK) { /* Is the interrupt flag set? */
    Hall_W_OnInterrupt();              /* Call the service routine */
  }
}

/*
** ===================================================================
**     Method      :  Cpu_Delay100US (component 56F8257)
**
**     Description :
**         This method realizes software delay. The length of delay
**         is at least 100 microsecond multiply input parameter
**         [us100]. As the delay implementation is not based on real
**         clock, the delay time may be increased by interrupt
**         service routines processed during the delay. Adding read
**         wait states for external program memory can cause delay
**         extension as well. The method is independent on selected
**         speed mode.
**     Parameters  :
**         NAME            - DESCRIPTION
**         us100           - Number of 100 us delay repetitions.
**     Returns     : Nothing
** ===================================================================
*/
/*lint -save -e???? Disable MISRA rule (all) checking. */
asm void Cpu_Delay100US(word us100)
{
  /* Total irremovable overhead: about 16 cycles */
  /* move.w: 2 cycles overhead (load parameter into register) */
  /* jsr:    5 cycles overhead (jump to subroutine) */
  /* rts:    8 cycles overhead (return from subroutine) */
  /* nop:    1 cycles overhead (aditional nops) */

  loop:
  /* 100 us delay block begin */
  /*
   * Delay
   *   - requested                  : 100 us @ 60MHz,
   *   - possible                   : 6000 c, 100000 ns
   *   - without removable overhead : 5994 c, 99900 ns
   */
  adda #2, SP                          /* (1 c: 16.67 ns) move SP forward */
  move.l A10, X:(SP)                   /* (2 c: 33.33 ns) push A */
  move.w #0x0BAD, A                    /* (2 c: 33.33 ns) number of iterations */
  do A, label0                         /* (8 c: 133.33 ns) repeat 2989x nop */
    nop                                /* (1 c: 16.67 ns) wait for 1 c */
  label0:
  move.l X:(SP), A                     /* (2 c: 33.33 ns) pop A */
  suba #2, SP                          /* (1 c: 16.67 ns) move SP back */
  /* 100 us delay block end */
  dec.w Y0                             /* us100 parameter is passed via Y0 register */
  jne loop                             /* next loop */
  nop                                  /* avoid pipeline conflicts */
  rts                                  /* return from subroutine */
}
/*lint -restore */

/*
** ===================================================================
**     Method      :  Cpu_DisableInt (component 56F8257)
**
**     Description :
**         Disables all maskable interrupts
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
/*
void Cpu_DisableInt(void)

**      This method is implemented as macro in the header module. **
*/

/*
** ===================================================================
**     Method      :  Cpu_EnableInt (component 56F8257)
**
**     Description :
**         Enables all maskable interrupts
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
/*
void Cpu_EnableInt(void)

**      This method is implemented as macro in the header module. **
*/

/*
** ===================================================================
**     Method      :  Cpu_SetStopMode (component 56F8257)
**
**     Description :
**         Sets low power mode - Stop mode.
**         For more information about the stop mode see this CPU
**         documentation.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
/*
void Cpu_SetStopMode(void)

**      This method is implemented as macro in the header module. **
*/

/*
** ===================================================================
**     Method      :  Cpu_SetWaitMode (component 56F8257)
**
**     Description :
**         Sets low power mode - Wait mode.
**         For more information about the wait mode see this CPU
**         documentation.
**         Release from wait mode: Reset or interrupt
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
/*
void Cpu_SetWaitMode(void)

**      This method is implemented as macro in the header module. **
*/

/*
** ===================================================================
**     Method      :  Cpu_GetResetSource (component 56F8257)
**
**     Description :
**         Gets low byte of the reset status register.
**     Parameters  : None
**     Returns     :
**         ---             - Content of the reset status register.
**                           You can use predefined constants listed
**                           bellow to find out a reset cause.
**                           Reset source (predefined constants):
**                           RSTSRC_POR - Power-on reset
**                           RSTSRC_PIN - External reset
**                           RSTSRC_COP - COP reset
**                           RSTSRC_SWR - Software reset
** ===================================================================
*/
/*
byte Cpu_GetResetSource(void)

**      This method is implemented as macro in the header module. **
*/

/*
** ===================================================================
**     Method      :  _EntryPoint (component 56F8257)
**
**     Description :
**         Initializes the whole system like timing and so on. At the end 
**         of this function, the C startup is invoked to initialize stack,
**         memory areas and so on.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
extern void init_56800_(void);         /* Forward declaration of external startup function declared in startup file */

/*** !!! Here you can place your own code using property "User data declarations" on the build options tab. !!! ***/

void _EntryPoint(void)
{
  #pragma constarray off

  /*** !!! Here you can place your own code before PE initialization using property "User code before PE initialization" on the build options tab. !!! ***/

  /*** ### MC56F8257 "Cpu" init code ... ***/
  /*** PE initialization code after reset ***/
  /* System clock initialization */
  /* SIM_GPS0: C0=0 */
  clrSetReg16Bits(SIM_GPS0, 0x01U, 0x00U); 
  /* SIM_PCE0: GPIOC=1 */
  setReg16Bits(SIM_PCE0, 0x10U);        
  /* GPIO_C_PUPEN: PU1=0 */
  clrReg16Bits(GPIO_C_PUPEN, 0x02U);    
  /* GPIO_C_PEREN: PE1=1 */
  setReg16Bits(GPIO_C_PEREN, 0x02U);    
  /* GPIO_C_PUPEN: PU0=0 */
  clrReg16Bits(GPIO_C_PUPEN, 0x01U);    
  /* GPIO_C_PEREN: PE0=1 */
  setReg16Bits(GPIO_C_PEREN, 0x01U);    
  clrRegBit(OCCS_OSCTL, CLK_MODE);     /* Power-up the external crystal oscillator */
  clrRegBit(OCCS_OSCTL, EXT_SEL);      /* Select an external crystal oscillator to be used */
  setRegBit(OCCS_OSCTL, COHL);         /* External crystal oscillator clock source */
  /* OCCS_OSCTL: OSC_DIV2=0 */
  clrSetReg16Bits(OCCS_OSCTL, 0x0800U, 0x00U); /* External crystal oscillator range - no additional division */ 
  /* Wait about 10ms for external oscillator stabilization */
  asm {
    /*
     * Delay
     *   - requested                  : 10 ms @ 4MHz,
     *   - possible                   : 40000 c, 10000000 ns
     */
    move.w #0x4E1B, A                  /* (2 c: 500 ns) number of iterations */
    do A, label0                       /* (8 c: 2000 ns) repeat 19995x nop */
      nop                              /* (1 c: 250 ns) wait for 1 c */
    label0:
  }
  setRegBit(OCCS_CTRL, PRECS);         /* Select an external clock source for the CPU core */
  setRegBit(OCCS_OSCTL, ROPD);         /* Power down the internal relaxation oscillator */
  /* SIM_PCE0: GPIOC=0 */
  clrReg16Bits(SIM_PCE0, 0x10U);        
  setReg(OCCS_CTRL, (OCCS_CTRL_PRECS_MASK | OCCS_CTRL_LCKON_MASK | OCCS_CTRL_ZSRC0_MASK)); /* Enable PLL, LCKON and select clock source from prescaler */
  /* OCCS_DIVBY: LORTP=2,COD=0,??=0,PLLDB=0x1D */
  setReg16(OCCS_DIVBY, 0x201DU);       /* Set the clock prescalers */ 
  while(!getRegBit(OCCS_STAT, LCK0)){} /* Wait for PLL lock */
  setReg(OCCS_CTRL, (OCCS_CTRL_PRECS_MASK | OCCS_CTRL_LCKON_MASK | OCCS_CTRL_ZSRC1_MASK)); /* Select clock source from postscaler */
  /* FM_CLKDIV: ??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,DIVLD=0,PRDIV8=0,DIV=0x28 */
  setReg16(FM_CLKDIV, 0x28U);          /* Set the flash clock prescaler */ 
  /*** End of PE initialization code after reset ***/

  /*** !!! Here you can place your own code after PE initialization using property "User code after PE initialization" on the build options tab. !!! ***/

  setReg(COP_CTRL, 0);                 /* Disable COP running after reset */
  asm(JMP init_56800_);                /* Jump to C startup code */
}

/*
** ===================================================================
**     Method      :  PE_low_level_init (component 56F8257)
**
**     Description :
**         Initializes beans and provides common register initialization. 
**         The method is called automatically as a part of the 
**         application initialization code.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
void PE_low_level_init(void)
{
  /* SIM_SD0: TA0=0,TA1=0,TA2=0,TA3=0,TB0=0,TB1=0,TB2=0,TB3=0,ADC=0,GPIOA=0,GPIOB=0,GPIOC=0,GPIOD=0,GPIOE=0,GPIOF=0,??=0 */
  setReg16(SIM_SD0, 0x00U);            /* Set up the STOP disable register 0 */ 
  /* SIM_SD1: ??=0,DAC=0,CMPA=0,CMPB=0,CMPC=0,SCI0=0,SCI1=0,QSPI0=0,IIC0=0,IIC1=0,CRC=0,REFA=0,REFB=0,REFC=0,??=0,MSCAN=0 */
  setReg16(SIM_SD1, 0x00U);            /* Set up the STOP disable register 1 */ 
  /* SIM_SD2: ??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,PWMCH0=0,PWMCH1=0,PWMCH2=0,PWMCH3=0 */
  setReg16(SIM_SD2, 0x00U);            /* Set up the STOP disable register 2 */ 
/* Enable peripheral clock */
  /* SIM_PCE0: TA0=1,TA1=1,ADC=1,GPIOA=1,GPIOB=1,GPIOC=1,GPIOE=1,GPIOF=1 */
  setReg16Bits(SIM_PCE0, 0xC0F6U);     /* Enable prph.clocks in the SIM_PCE0 register before Common initialization */ 
  /* SIM_PCE1: DAC=1,SCI1=1,QSPI0=1,HFM=1,MSCAN=1 */
  setReg16Bits(SIM_PCE1, 0x4303U);     /* Enable prph.clocks in the SIM_PCE1 register before Common initialization */ 
  /* SIM_PCE2: PWMCH0=1,PWMCH1=1,PWMCH2=1 */
  setReg16Bits(SIM_PCE2, 0x0EU);       /* Enable prph.clocks in the SIM_PCE2 register before Common initialization */ 
  /* GPIO_A_DRIVE: ??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,DRIVE7=0,DRIVE6=0,DRIVE5=0,DRIVE4=0,DRIVE3=0,DRIVE2=0,DRIVE1=0,DRIVE0=0 */
  setReg16(GPIO_A_DRIVE, 0x00U);       /* Set High/Low drive strength on GPIOA pins according to the CPU bean settings */ 
  /* GPIO_B_DRIVE: ??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,DRIVE7=0,DRIVE6=0,DRIVE5=0,DRIVE4=0,DRIVE3=0,DRIVE2=0,DRIVE1=0,DRIVE0=0 */
  setReg16(GPIO_B_DRIVE, 0x00U);       /* Set High/Low drive strength on GPIOB pins according to the CPU bean settings */ 
  /* GPIO_C_DRIVE: DRIVE15=0,DRIVE14=0,DRIVE13=0,DRIVE12=0,DRIVE11=0,DRIVE10=0,DRIVE9=0,DRIVE8=0,DRIVE7=0,DRIVE6=0,DRIVE5=0,DRIVE4=0,DRIVE3=0,DRIVE2=0,DRIVE1=0,DRIVE0=0 */
  setReg16(GPIO_C_DRIVE, 0x00U);       /* Set High/Low drive strength on GPIOC pins according to the CPU bean settings */ 
  /* GPIO_D_DRIVE: ??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,DRIVE4=0,DRIVE3=0,DRIVE2=0,DRIVE1=0,DRIVE0=0 */
  setReg16(GPIO_D_DRIVE, 0x00U);       /* Set High/Low drive strength on GPIOD pins according to the CPU bean settings */ 
  /* GPIO_E_DRIVE: ??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,DRIVE7=0,DRIVE6=0,DRIVE5=0,DRIVE4=0,DRIVE3=0,DRIVE2=0,DRIVE1=0,DRIVE0=0 */
  setReg16(GPIO_E_DRIVE, 0x00U);       /* Set High/Low drive strength on GPIOE pins according to the CPU bean settings */ 
  /* GPIO_F_DRIVE: ??=0,??=0,??=0,??=0,??=0,??=0,??=0,DRIVE8=0,DRIVE7=0,DRIVE6=0,DRIVE5=0,DRIVE4=0,DRIVE3=0,DRIVE2=0,DRIVE1=0,DRIVE0=0 */
  setReg16(GPIO_F_DRIVE, 0x00U);       /* Set High/Low drive strength on GPIOF pins according to the CPU bean settings */ 
  /* SIM_PCR: TMRA_CR=0,TMRB_CR=0,SCI0_CR=0,SCI1_CR=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0 */
  setReg16(SIM_PCR, 0x00U);            /* Set the TMR; TMRB; QSCI0; QSCI1 module clock rates */ 
  /* SIM_CTRL: ??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,ONCEEBL=0,SWRST=0,STOP_DISABLE=0,WAIT_DISABLE=0 */
  setReg16(SIM_CTRL, 0x00U);           /* Set up the SIM control register */ 
  /* SIM_CLKOUT: ??=0,??=0,??=1,??=0,??=0,??=0,??=0,??=0,??=0,TEST=0,CLKDIS=1,CLKOSEL=0 */
  setReg16(SIM_CLKOUT, 0x2020U);       /* Set up the SIM clock output select register */ 
  /* Set two's complement rounding and enable saturation */
  asm {
    bfset #0x10,OMR
    bfset #0x20,OMR
    bfclr #0x40,SR
  }
  /* Common initialization of the CPU registers */
  /* INTC_IPR5: PWM_RELOAD0_IPL=2 */
  clrSetReg16Bits(INTC_IPR5, 0x40U, 0x80U); 
  /* INTC_IPR4: PWM_FAULT_IPL=3 */
  setReg16Bits(INTC_IPR4, 0x30U);       
  /* GPIO_E_PEREN: PE5=1,PE4=1,PE3=1,PE2=1,PE1=1,PE0=1 */
  setReg16Bits(GPIO_E_PEREN, 0x3FU);    
  /* SIM_GPS3: E5=0,E4=0,A0=0 */
  clrReg16Bits(SIM_GPS3, 0x51U);        
  /* XB_XBC10: CODE21=6 */
  clrSetReg16Bits(XB_XBC10, 0x1900U, 0x0600U); 
  /* GPIO_F_PEREN: PE7=0,PE6=0,PE5=1,PE2=1,PE1=0,PE0=1 */
  clrSetReg16Bits(GPIO_F_PEREN, 0xC2U, 0x25U); 
  /* GPIO_A_PEREN: PE2=1,PE1=1,PE0=1 */
  setReg16Bits(GPIO_A_PEREN, 0x07U);    
  /* GPIO_B_PEREN: PE7=1,PE5=1,PE1=1 */
  setReg16Bits(GPIO_B_PEREN, 0xA2U);    
  /* XB_XBC3: CODE6=0x10 */
  clrSetReg16Bits(XB_XBC3, 0x0FU, 0x10U); 
  /* INTC_IPR6: GPIOF_IPL=3 */
  setReg16Bits(INTC_IPR6, 0xC0U);       
  /* GPIO_F_IASSRT: IA7=0,IA6=0,IA1=0 */
  clrReg16Bits(GPIO_F_IASSRT, 0xC2U);   
  /* GPIO_F_IPEND: IP7=0,IP6=0,IP1=0 */
  clrReg16Bits(GPIO_F_IPEND, 0xC2U);    
  /* GPIO_F_IPOL: IPOL7=0,IPOL6=0,IPOL1=0 */
  clrReg16Bits(GPIO_F_IPOL, 0xC2U);     
  /* GPIO_F_PUPEN: PU7=0,PU6=0,PU1=0 */
  clrReg16Bits(GPIO_F_PUPEN, 0xC2U);    
  /* GPIO_F_DDIR: DD7=0,DD6=0,DD1=0 */
  clrReg16Bits(GPIO_F_DDIR, 0xC2U);     
  /* TMRA_ENBL: ENBL&=~3 */
  clrReg16Bits(TMRA_ENBL, 0x03U);       
  /* SIM_GPS1: C11=2,C9=0,C8=0 */
  clrSetReg16Bits(SIM_GPS1, 0x45U, 0x80U); 
  /* SIM_GPS2: F5=0,F2=1 */
  clrSetReg16Bits(SIM_GPS2, 0x0400U, 0x10U); 
  /* GPIO_C_PEREN: PE11=1,PE9=0,PE8=1,PE7=1,PE5=1,PE4=0,PE3=0 */
  clrSetReg16Bits(GPIO_C_PEREN, 0x0218U, 0x09A0U); 
  /* INTC_IPR2: QSCI1_TDRE_IPL=2,QSCI1_TIDLE_IPL=2,QSCI1_RCV_IPL=2,QSCI1_RERR_IPL=2 */
  clrSetReg16Bits(INTC_IPR2, 0x0550U, 0x0AA0U); 
  /* XB_XBC1: CODE2=0x10 */
  clrSetReg16Bits(XB_XBC1, 0x0FU, 0x10U); 
  /* GPIO_C_IEN: IEN4=0,IEN3=0 */
  clrReg16Bits(GPIO_C_IEN, 0x18U);      
  /* GPIO_C_IASSRT: IA4=0,IA3=0 */
  clrReg16Bits(GPIO_C_IASSRT, 0x18U);   
  /* GPIO_C_IEDGE: IES4=1,IES3=1 */
  setReg16Bits(GPIO_C_IEDGE, 0x18U);    
  /* GPIO_C_PUPEN: PU4=0,PU3=0 */
  clrReg16Bits(GPIO_C_PUPEN, 0x18U);    
  /* GPIO_C_DDIR: DD9=1,DD4=0,DD3=0 */
  clrSetReg16Bits(GPIO_C_DDIR, 0x18U, 0x0200U); 
  /* GPIO_C_DATA: D9=1 */
  setReg16Bits(GPIO_C_DATA, 0x0200U);   
  /* SIM_GPS0: C7=0 */
  clrReg16Bits(SIM_GPS0, 0x4000U);      
  /* Disable peripheral clock after initialization of their registers (if the clocks should not be enabled in init. code) */
  /* SIM_PCE0: TA2=0,TA3=0,TB0=0,TB1=0,TB2=0,TB3=0,GPIOA=0,GPIOB=0,GPIOD=0,GPIOE=0,??=0 */
  clrReg16Bits(SIM_PCE0, 0x3F6DU);     /* Disable prph.clocks in the SIM_PCE0 register after Common initialization */ 
  /* SIM_PCE1: ??=0,CMPA=0,CMPB=0,CMPC=0,SCI0=0,IIC0=0,IIC1=0,CRC=0,REFA=0,REFB=0,REFC=0 */
  clrReg16Bits(SIM_PCE1, 0xBCFCU);     /* Disable prph.clocks in the SIM_PCE1 register after Common initialization */ 
  /* SIM_PCE2: ??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,PWMCH3=0 */
  clrReg16Bits(SIM_PCE2, 0xFFF1U);     /* Disable prph.clocks in the SIM_PCE2 register after Common initialization */ 
  /* ### Init_eFlexPWM "eFPWM1" init code ... */
  /* ### Call "eFPWM1_Init();" init method in a user code, i.e. in the main code */
  /* ### Note:   To enable automatic calling of the "eFPWM1" init code here must be
                 set the property Call Init method to 'yes'
   */
  /* ### PWMMC "PWMC1" init code ... */
  PWMC1_Init();


  /* ### ADC "AD1" init code ... */
  AD1_Init();
  /* ### WatchDog "WDog1" init code ... */
  WDog1_Init();
  /* ### FreeCntr "HallTmr" init code ... */
  HallTmr_Init();
  /* ### Asynchro serial "Inhr1" init code ... */
  Inhr1_Init();
  /* ### PC_Master "PC_M1" init code ... */
  PC_M1_PE_Init();
  /* ### CrossbarSwitch "XBAR1" init code ... */
  /* ### DAC "DA1" init code ... */
  DA1_Init();
  /* ### SynchroMaster "Resolver" init code ... */
  Resolver_Init();
  /* Common peripheral initialization - ENABLE */
  /* GPIO_F_IEDGE: IES7=1,IES6=1,IES1=1 */
  setReg16Bits(GPIO_F_IEDGE, 0xC2U);    
  /* GPIO_F_IEN: IEN7=1,IEN6=1,IEN1=1 */
  setReg16Bits(GPIO_F_IEN, 0xC2U);      
  /* TMRA_ENBL: ENBL|=3 */
  setReg16Bits(TMRA_ENBL, 0x03U);       
  setRegBit(COP_CTRL,CEN);             /* Enable COP */
  __EI(3);                             /* Enable interrupts of the selected priority level */
}

/* END Cpu. */

/*
** ###################################################################
**
**     This file was created by Processor Expert 3.00 [04.35]
**     for the Freescale 56800 series of microcontrollers.
**
** ###################################################################
*/