/** ###################################################################
**     Filename  : User_Const.H
**     Project   : PmsmFocDrv
**     Processor : MC56F8257
**     Compiler  : Metrowerks DSP C Compiler
**     Date/Time : 2013-10-1, ÏÂÎç 09:54
**     Contents  :
**         User source code
**
** ###################################################################*/

#ifndef __User_Const_H
#define __User_Const_H

#include "IO_Map.h"
/* MODULE User_Const */


//	--------------------------------------------------------------------------------------------------------
//	ADC Channel Configuration(Simultaneous Parallel Scan Modes triggered by SYNC0 from PWM submodule0 VAL0)
//	--------------------------------------------------------------------------------------------------------
//	ADC_A Converter
#define AD_IU			(getReg(ADC_RSLT0))
#define AD_IV			(getReg(ADC_RSLT1))
#define AD_PS			(getReg(ADC_RSLT2))

//	ADC_B Converter
#define AD_IW			(getReg(ADC_RSLT4))
#define AD_VDC			(getReg(ADC_RSLT5))
#define AD_T_SENSE		(getReg(ADC_RSLT6))



/* END User_Const */

#endif
