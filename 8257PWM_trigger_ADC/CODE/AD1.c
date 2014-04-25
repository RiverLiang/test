/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename  : AD1.C
**     Project   : PmsmFocDrv
**     Processor : MC56F8257
**     Component : ADC
**     Version   : Component 01.580, Driver 02.05, CPU db: 3.00.231
**     Compiler  : Metrowerks DSP C Compiler
**     Date/Time : 2014/4/25, 9:32
**     Abstract  :
**         This device "ADC" implements an A/D converter,
**         its control methods and interrupt/event handling procedure.
**     Settings  :
**         AD control register         : ADC_CTRL1   [F080]
**         AD control register         : ADC_CTRL2   [F081]
**         AD control register         : ADC_ZXCTRL  [F082]
**         AD control register         : ADC_CLIST1  [F083]
**         AD control register         : ADC_CLIST2  [F084]
**         AD control register         : ADC_SDIS    [F087]
**         AD control register         : ADC_STAT    [F088]
**         AD control register         : ADC_LIMSTAT [F08A]
**         AD control register         : ADC_ZXSTAT  [F08B]
**         AD control register         : ADC_LOLIM0  [F09C]
**         AD control register         : ADC_LOLIM1  [F09D]
**         AD control register         : ADC_LOLIM2  [F09E]
**         AD control register         : ADC_LOLIM3  [F09F]
**         AD control register         : ADC_LOLIM4  [F0A0]
**         AD control register         : ADC_LOLIM5  [F0A1]
**         AD control register         : ADC_LOLIM6  [F0A2]
**         AD control register         : ADC_LOLIM7  [F0A3]
**         AD control register         : ADC_HILIM0  [F0A4]
**         AD control register         : ADC_HILIM1  [F0A5]
**         AD control register         : ADC_HILIM2  [F0A6]
**         AD control register         : ADC_HILIM3  [F0A7]
**         AD control register         : ADC_HILIM4  [F0A8]
**         AD control register         : ADC_HILIM5  [F0A9]
**         AD control register         : ADC_HILIM6  [F0AA]
**         AD control register         : ADC_HILIM7  [F0AB]
**         AD control register         : ADC_OFFST0  [F0AC]
**         AD control register         : ADC_OFFST1  [F0AD]
**         AD control register         : ADC_OFFST2  [F0AE]
**         AD control register         : ADC_OFFST3  [F0AF]
**         AD control register         : ADC_OFFST4  [F0B0]
**         AD control register         : ADC_OFFST5  [F0B1]
**         AD control register         : ADC_OFFST6  [F0B2]
**         AD control register         : ADC_OFFST7  [F0B3]
**         AD control register         : ADC_PWR     [F0B4]
**         AD control register         : ADC_CAL     [F0B5]
**         AD control register         : ADC_CLIST3  [F085]
**         AD control register         : ADC_CLIST4  [F086]
**         AD control register         : ADC_RDY     [F089]
**         User handling procedure     : not specified
**         Number of conversions       : 1
**         AD resolution               : 12-bit
**
**         Input pins
**
**              Port name              : GPIOA
**              Bit number (in port)   : 0
**              Bit mask of the port   : 0001
**              Port data register     : GPIO_A_DATA [F141]
**              Port control register  : GPIO_A_DDIR [F142]
**              Port function register : GPIO_A_PEREN [F143]
**
**              Port name              : GPIOA
**              Bit number (in port)   : 1
**              Bit mask of the port   : 0002
**              Port data register     : GPIO_A_DATA [F141]
**              Port control register  : GPIO_A_DDIR [F142]
**              Port function register : GPIO_A_PEREN [F143]
**
**              Port name              : GPIOA
**              Bit number (in port)   : 2
**              Bit mask of the port   : 0004
**              Port data register     : GPIO_A_DATA [F141]
**              Port control register  : GPIO_A_DDIR [F142]
**              Port function register : GPIO_A_PEREN [F143]
**
**              Port name              : GPIOB
**              Bit number (in port)   : 1
**              Bit mask of the port   : 0002
**              Port data register     : GPIO_B_DATA [F151]
**              Port control register  : GPIO_B_DDIR [F152]
**              Port function register : GPIO_B_PEREN [F153]
**
**              Port name              : GPIOB
**              Bit number (in port)   : 5
**              Bit mask of the port   : 0020
**              Port data register     : GPIO_B_DATA [F151]
**              Port control register  : GPIO_B_DDIR [F152]
**              Port function register : GPIO_B_PEREN [F153]
**
**              Port name              : GPIOB
**              Bit number (in port)   : 7
**              Bit mask of the port   : 0080
**              Port data register     : GPIO_B_DATA [F151]
**              Port control register  : GPIO_B_DDIR [F152]
**              Port function register : GPIO_B_PEREN [F153]
**
**         Initialization:
**              Conversion             : Enabled
**              Event                  : Enabled
**         High speed mode
**             Prescaler               : divide-by-6
**     Contents  :
**         Enable           - byte AD1_Enable(void);
**         Disable          - byte AD1_Disable(void);
**         Measure          - byte AD1_Measure(bool WaitForResult);
**         EnableIntTrigger - byte AD1_EnableIntTrigger(void);
**         GetValue16       - byte AD1_GetValue16(word *Values);
**
**     Copyright : 1997 - 2009 Freescale Semiconductor, Inc. All Rights Reserved.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/

/* MODULE AD1. */

#include "AD1.h"

#define IDLE            0              /* IDLE state           */
#define MEASURE         1              /* MESURE state         */
#define CONTINUOUS      2              /* CONTINUOUS state     */
#define SINGLE          3              /* SINGLE state         */

/*lint -esym(765,AD1_EnUser) Disable MISRA rule (23) checking for symbols (AD1_EnUser). */
bool AD1_EnUser;                       /* Enable/Disable device */
static bool OutFlg;                    /* Measurement finish flag */
/*lint -esym(765,AD1_ModeFlg) Disable MISRA rule (23) checking for symbols (AD1_ModeFlg). */
volatile byte AD1_ModeFlg;             /* Current state of device */

/*
** ===================================================================
**     Method      :  MainMeasure (component ADC)
**
**     Description :
**         The method performs A/D conversion(s). The method is called 
**         automatically as a part of measure methods or the HWEnDi 
**         method.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
static void MainMeasure(void)
{
  if (getRegBit(ADC_STAT,EOSI0)) {     /* Is a scan cycle completed? */
    setRegBits(ADC_STAT,0x0800);       /* Clear EOSI flag */
    OutFlg = TRUE;                     /* Measured values are available */
    if (!(getRegBit(ADC_CTRL1,SMODE2))) { /* Not running in trigger mode? */
      AD1_ModeFlg = IDLE;              /* Set the bean to the idle mode */
    }
  }
}

/*
** ===================================================================
**     Method      :  HWEnDi (component ADC)
**
**     Description :
**         Enables or disables the peripheral(s) associated with the bean.
**         The method is called automatically as a part of Enable, 
**         Disable and Init methods and several internal methods.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
static void HWEnDi(void)
{
  volatile word i;

  if (AD1_EnUser) {                    /* Enable device? */
    if (getRegBits(ADC_PWR,ADC_PWR_PSTS_MASK)) { /* Is device enabled? */
      /* ADC_PWR: ASB=0,??=0,??=0,??=0,PSTS1=0,PSTS0=0,PUDELAY=0x0D,APD=0,??=0,PD1=0,PD0=0 */
      setReg(ADC_PWR,0xD0);            /* Enable device */
      for (i=0;i<0x64;i++) {}          /* Recovery time of voltage reference */
      while (ADC_PWR&(ADC_PWR_PSTS_MASK)) {} /* Wait for device powered up */
    }
    if (AD1_ModeFlg) {                 /* Launch measurement? */
      OutFlg = FALSE;                  /* Measured values are available */
      setRegBits(ADC_STAT,0x0800);     /* Clear flag */
      if (getRegBit(ADC_CTRL1,SMODE2)) { /* Trigger mode? */
        setRegBit(ADC_CTRL1,SYNC0);    /* Use sync input to initiate a conversion */
        clrRegBit(ADC_CTRL1,STOP0);    /* Normal operation mode */
      }
      else {
        clrRegBits(ADC_CTRL1,ADC_CTRL1_SYNC0_MASK | ADC_CTRL1_STOP0_MASK); /* Set normal operation mode and sync input disabled */
        setRegBit(ADC_CTRL1,START0);   /* Launching of conversion */
      }
    }
    else {
      setRegBit(ADC_CTRL1,STOP0);      /* Stop command issued */
    }
  }
  else {
    setRegBit(ADC_CTRL1,STOP0);        /* Stop command issued */
    /* ADC_PWR: ASB=0,??=0,??=0,??=0,PSTS1=0,PSTS0=0,PUDELAY=0x0D,APD=0,??=1,PD1=1,PD0=1 */
    setReg(ADC_PWR,0xD7);              /* Disable device */
  }
}

/*
** ===================================================================
**     Method      :  AD1_Enable (component ADC)
**
**     Description :
**         Enables A/D converter bean. <Events> may be generated
**         (<DisableEvent>/<EnableEvent>). If possible, this method
**         switches on A/D converter device, voltage reference, etc.
**     Parameters  : None
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
** ===================================================================
*/
byte AD1_Enable(void)
{
  if (AD1_EnUser) {                    /* Is the device enabled by user? */
    return ERR_OK;                     /* If yes then set the flag "device enabled" */
  }
  AD1_EnUser = TRUE;                   /* Set the flag "device enabled" */
  HWEnDi();                            /* Enable the device */
  return ERR_OK;                       /* OK */
}

/*
** ===================================================================
**     Method      :  AD1_Disable (component ADC)
**
**     Description :
**         Disables A/D converter bean. No <events> will be generated.
**         If possible, this method switches off A/D converter device,
**         voltage reference, etc.
**     Parameters  : None
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
** ===================================================================
*/
byte AD1_Disable(void)
{
  if (!AD1_EnUser) {                   /* Is the device disabled by user? */
    return ERR_OK;                     /* If yes then OK */
  }
  AD1_EnUser = FALSE;                  /* If yes then set the flag "device disabled" */
  HWEnDi();                            /* Enable the device */
  return ERR_OK;                       /* OK */
}

/*
** ===================================================================
**     Method      :  AD1_Measure (component ADC)
**
**     Description :
**         This method performs one measurement on all channels that
**         are set in the bean inspector. (Note: If the <number of
**         conversions> is more than one the conversion of A/D channels
**         is performed specified number of times.)
**     Parameters  :
**         NAME            - DESCRIPTION
**         WaitForResult   - Wait for a result of a
**                           conversion. If <interrupt service> is
**                           disabled, A/D peripheral doesn't support
**                           measuring all channels at once or Autoscan
**                           mode property isn't enabled and at the same
**                           time the <number of channel> is greater
**                           than 1, then the WaitForResult parameter is
**                           ignored and the method waits for each
**                           result every time. If the <interrupt
**                           service> is disabled and a <number of
**                           conversions> is greater than 1, the
**                           parameter is ignored and the method also
**                           waits for each result every time.
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
**                           ERR_DISABLED - Device is disabled
**                           ERR_BUSY - A conversion is already running
** ===================================================================
*/
byte AD1_Measure(bool WaitForResult)
{
  if (!AD1_EnUser) {                   /* Is the device disabled by user? */
    return ERR_DISABLED;               /* If yes then error */
  }
  if (AD1_ModeFlg != IDLE) {           /* Is the device in running mode? */
    return ERR_BUSY;                   /* If yes then error */
  }
  setRegBitGroup(ADC_CTRL1,SMODE,0x01); /* Select 'Once Parallel' mode */
  AD1_ModeFlg = MEASURE;               /* Set state of device to the measure mode */
  HWEnDi();                            /* Enable the device */
  if (WaitForResult) {                 /* Is WaitForResult TRUE? */
    while (AD1_ModeFlg == MEASURE) {   /* Calling MainMeasure while IDLE state occured */
      MainMeasure();                   /* A/D converter handler */
    }
  }
  return ERR_OK;                       /* OK */
}

/*
** ===================================================================
**     Method      :  AD1_EnableIntTrigger (component ADC)
**
**     Description :
**         Enables the internal trigger mode. A conversion of all
**         channels that are set in the bean inspector will be launched
**         by an internal sync pulse. If the <Number of conversions> is
**         greater than 1, a conversion will be launched more than once
**         (by an internal signal) according to <Number of conversions>.
**         It's possible to disable the trigger mode by <Stop> method.
**         Version specific information for other derivatives than
**         Freescale HCS12 and HCS12X ] 
**         This EnableIntTrigger method is available only when the
**         <Internal trigger> property is enabled.
**     Parameters  : None
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_BUSY - A conversion is already running
** ===================================================================
*/
byte AD1_EnableIntTrigger(void)
{
  if (AD1_ModeFlg != IDLE) {           /* Is the device in running mode? */
    return ERR_BUSY;                   /* If yes then error */
  }
  setRegBitGroup(ADC_CTRL1,SMODE,0x05); /* Select 'Triggered Parallel' mode */
  AD1_ModeFlg = MEASURE;               /* Set state of device to the measure mode */
  HWEnDi();                            /* Enable the device */
  return ERR_OK;                       /* OK */
}

/*
** ===================================================================
**     Method      :  AD1_GetValue16 (component ADC)
**
**     Description :
**         This method returns the last measured values of all channels
**         justified to the left. Compared with <GetValue> method this
**         method returns more accurate result if the <number of
**         conversions> is greater than 1 and <AD resolution> is less
**         than 16 bits. In addition, the user code dependency on <AD
**         resolution> is eliminated.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * Values          - Pointer to the array that contains
**                           the measured data.
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
**                           ERR_NOTAVAIL - Requested value not
**                           available
**                           ERR_OVERRUN - External trigger overrun flag
**                           was detected after the last value(s) was
**                           obtained (for example by GetValue). This
**                           error may not be supported on some CPUs
**                           (see generated code).
** ===================================================================
*/
byte AD1_GetValue16(word *Values)
{
  if (AD1_ModeFlg != IDLE) {           /* Is the device in any measure mode? */
    MainMeasure();                     /* Call A/D converter handler */
  }
  if (!OutFlg) {                       /* Is measured value(s) available? */
    return ERR_NOTAVAIL;               /* If no then error */
  }
  *Values++ = (getReg(ADC_RSLT0) + 0x00) << 1; /* Store value from result register of device to user buffer */
  *Values++ = (getReg(ADC_RSLT1) + 0x00) << 1; /* Store value from result register of device to user buffer */
  *Values++ = (getReg(ADC_RSLT2) + 0x00) << 1; /* Store value from result register of device to user buffer */
  *Values++ = (getReg(ADC_RSLT4) + 0x00) << 1; /* Store value from result register of device to user buffer */
  *Values++ = (getReg(ADC_RSLT5) + 0x00) << 1; /* Store value from result register of device to user buffer */
  *Values = (getReg(ADC_RSLT6) + 0x00) << 1; /* Store value from result register of device to user buffer */
  return ERR_OK;                       /* OK */
}

/*
** ===================================================================
**     Method      :  AD1_Init (component ADC)
**
**     Description :
**         Initializes the associated peripheral(s) and the beans 
**         internal variables. The method is called automatically as a 
**         part of the application initialization code.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
void AD1_Init(void)
{
  AD1_EnUser = TRUE;                   /* Enable device */
  OutFlg = FALSE;                      /* No measured value */
  AD1_ModeFlg = IDLE;                  /* Device isn't running */
  /* ADC_CTRL1: ??=0,STOP0=1,START0=0,SYNC0=0,EOSIE0=0,ZCIE=0,LLMTIE=0,HLMTIE=0,CHNCFG_L=0,??=0,SMODE=0 */
  setReg(ADC_CTRL1,0x4000);            /* Set control register 1 */
  /* ADC_CAL: SEL_VREFH_1=0,SEL_VREFLO_1=0,SEL_VREFH_0=0,SEL_VREFLO_0=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,SEL_TEST_1=0,SEL_TEST_0=0,SEL_DAC1=0,SEL_DAC0=0 */
  setReg(ADC_CAL,0x00);                /* Set calibration register */
  /* ADC_OFFST0: ??=0,OFFSET=0,??=0,??=0,??=0 */
  setReg(ADC_OFFST0,0x00);             /* Set offset reg. 0 */
  /* ADC_OFFST1: ??=0,OFFSET=0,??=0,??=0,??=0 */
  setReg(ADC_OFFST1,0x00);             /* Set offset reg. 1 */
  /* ADC_OFFST2: ??=0,OFFSET=0,??=0,??=0,??=0 */
  setReg(ADC_OFFST2,0x00);             /* Set offset reg. 2 */
  /* ADC_OFFST4: ??=0,OFFSET=0,??=0,??=0,??=0 */
  setReg(ADC_OFFST4,0x00);             /* Set offset reg. 4 */
  /* ADC_OFFST5: ??=0,OFFSET=0,??=0,??=0,??=0 */
  setReg(ADC_OFFST5,0x00);             /* Set offset reg. 5 */
  /* ADC_OFFST6: ??=0,OFFSET=0,??=0,??=0,??=0 */
  setReg(ADC_OFFST6,0x00);             /* Set offset reg. 6 */
  /* ADC_HILIM0: ??=0,HLMT=0x0FFF,??=0,??=0,??=0 */
  setReg(ADC_HILIM0,0x7FF8);           /* Set high limit reg. 0 */
  /* ADC_HILIM1: ??=0,HLMT=0x0FFF,??=0,??=0,??=0 */
  setReg(ADC_HILIM1,0x7FF8);           /* Set high limit reg. 1 */
  /* ADC_HILIM2: ??=0,HLMT=0x0FFF,??=0,??=0,??=0 */
  setReg(ADC_HILIM2,0x7FF8);           /* Set high limit reg. 2 */
  /* ADC_HILIM4: ??=0,HLMT=0x0FFF,??=0,??=0,??=0 */
  setReg(ADC_HILIM4,0x7FF8);           /* Set high limit reg. 4 */
  /* ADC_HILIM5: ??=0,HLMT=0x0FFF,??=0,??=0,??=0 */
  setReg(ADC_HILIM5,0x7FF8);           /* Set high limit reg. 5 */
  /* ADC_HILIM6: ??=0,HLMT=0x0FFF,??=0,??=0,??=0 */
  setReg(ADC_HILIM6,0x7FF8);           /* Set high limit reg. 6 */
  /* ADC_LOLIM0: ??=0,LLMT=0,??=0,??=0,??=0 */
  setReg(ADC_LOLIM0,0x00);             /* Set low limit reg. 0 */
  /* ADC_LOLIM1: ??=0,LLMT=0,??=0,??=0,??=0 */
  setReg(ADC_LOLIM1,0x00);             /* Set low limit reg. 1 */
  /* ADC_LOLIM2: ??=0,LLMT=0,??=0,??=0,??=0 */
  setReg(ADC_LOLIM2,0x00);             /* Set low limit reg. 2 */
  /* ADC_LOLIM4: ??=0,LLMT=0,??=0,??=0,??=0 */
  setReg(ADC_LOLIM4,0x00);             /* Set low limit reg. 4 */
  /* ADC_LOLIM5: ??=0,LLMT=0,??=0,??=0,??=0 */
  setReg(ADC_LOLIM5,0x00);             /* Set low limit reg. 5 */
  /* ADC_LOLIM6: ??=0,LLMT=0,??=0,??=0,??=0 */
  setReg(ADC_LOLIM6,0x00);             /* Set low limit reg. 6 */
  /* ADC_ZXSTAT: ??=1,??=1,??=1,??=1,??=1,??=1,??=1,??=1,ZCS=0xFF */
  setReg(ADC_ZXSTAT,0xFFFF);           /* Clear zero crossing status flags */
  /* ADC_LIMSTAT: HLS=0xFF,LLS=0xFF */
  setReg(ADC_LIMSTAT,0xFFFF);          /* Clear high and low limit status */
  /* ADC_STAT: CIP0=0,CIP1=0,??=0,EOSI1=0,EOSI0=1,ZCI=0,LLMTI=0,HLMTI=0,RDY=0 */
  setReg(ADC_STAT,0x0800);             /* Clear EOSI flag */
  /* ADC_SDIS: DS15=1,DS14=1,DS13=1,DS12=1,DS11=1,DS10=1,DS9=1,DS8=1,DS7=1,DS6=0,DS5=0,DS4=0,DS3=1,DS2=0,DS1=0,DS0=0 */
  setReg(ADC_SDIS,0xFF88);             /* Enable/disable of samples */
  /* ADC_CLIST1: SAMPLE3=0,SAMPLE2=0,SAMPLE1=1,SAMPLE0=2 */
  setReg(ADC_CLIST1,0x12);             /* Set ADC channel list reg. */
  /* ADC_CLIST2: SAMPLE7=0,SAMPLE6=0x0D,SAMPLE5=5,SAMPLE4=0x0F */
  setReg(ADC_CLIST2,0x0D5F);           /* Set ADC channel list reg. */
  /* ADC_ZXCTRL: ZCE7=0,ZCE6=0,ZCE5=0,ZCE4=0,ZCE3=0,ZCE2=0,ZCE1=0,ZCE0=0 */
  setReg(ADC_ZXCTRL,0x00);             /* Set zero crossing control reg. */
  /* ADC_CTRL2: ??=0,STOP1=0,START1=0,SYNC1=0,EOSIE1=0,??=0,CHNCFG_H=0,SIMULT=1,DIV=2 */
  setReg(ADC_CTRL2,0x22);              /* Set prescaler */
  /* ADC_PWR2: ??=0,??=0,??=0,DIV1=0,??=0,??=0,??=0,??=0,SPEEDB=0,SPEEDA=2 */
  setReg16(ADC_PWR2, 0x02U);            
  HWEnDi();                            /* Enable/disable device according to the status flags */
}

/* END AD1. */

/*
** ###################################################################
**
**     This file was created by Processor Expert 3.00 [04.35]
**     for the Freescale 56800 series of microcontrollers.
**
** ###################################################################
*/
