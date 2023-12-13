/***********************************************************************************/
/* Author  : Abdellatif Maher                                                      */
/* Date    : 2 JUL 2021                                                            */
/* Version : V01                                                                   */
/***********************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"


#include "RCC_interface.h"
#include "RCC_private.h"
#include "RCC_config.h"


void RCC_voidInitSysClock(void)
{	
	#if     RCC_CLOCK_TYPE == RCC_HSE_CRYSTAL
		
		RCC_CFGR = (0x00000001 | (RCC_USB_PRE<<22) |(RCC_ADC_PRE<<14) |(RCC_APB2_PRE<<11) |(RCC_APB1_PRE<<8)|(RCC_AHB_PRE<<4));
		
		RCC_CR   = 0x00010000; /* Enable HSE without bypass */
		//while(!(GET_BIT(RCC_CR,17))); /* Check if enabled */
		
	#elif   RCC_CLOCK_TYPE == RCC_HSE_RC
		
		RCC_CFGR = (0x00000001 | (RCC_USB_PRE<<22) |(RCC_ADC_PRE<<14) |(RCC_APB2_PRE<<11) |(RCC_APB1_PRE<<8)|(RCC_AHB_PRE<<4));
		
		RCC_CR   = 0x00050000; /* Enable HSE with bypass */
		//while(!(GET_BIT(RCC_CR,17))); /* Check if enabled */
		
	#elif   RCC_CLOCK_TYPE == RCC_HSI
		
		RCC_CFGR = (0x00000000 | (RCC_USB_PRE<<22) |(RCC_ADC_PRE<<14) |(RCC_APB2_PRE<<11) |(RCC_APB1_PRE<<8)|(RCC_AHB_PRE<<4));
		
		RCC_CR   = 0x00000081; /* Enable HSI + Trimming = 0 */
		//while(!(GET_BIT(RCC_CR,1))); /* Check if enabled */
		
	#elif   RCC_CLOCK_TYPE == RCC_PLL
	
		#if   RCC_PLL_INPUT == RCC_PLL_IN_HSI_DIV_2
			
			RCC_CFGR = (0x00000002 | (RCC_USB_PRE<<22)| ((RCC_PLL_MUL_VAL - 2) << 18) |(RCC_ADC_PRE<<14) |(RCC_APB2_PRE<<11) |(RCC_APB1_PRE<<8)|(RCC_AHB_PRE<<4));
		
			RCC_CR = 0x01000081; /* Enable PLL With HSI + Trimming = 0 */
			//while(!(GET_BIT(RCC_CR,1))); /* Check if enabled */
			//while(!(GET_BIT(RCC_CR,25))); /* Check if enabled */
			
		#elif RCC_PLL_INPUT == RCC_PLL_IN_HSE_CRYSTAL_DIV_2
			
			RCC_CFGR = (0x00030002 | (RCC_USB_PRE<<22)| ((RCC_PLL_MUL_VAL - 2) << 18) |(RCC_ADC_PRE<<14) |(RCC_APB2_PRE<<11) |(RCC_APB1_PRE<<8)|(RCC_AHB_PRE<<4));
			
			RCC_CR = 0x01010000; /* Enable PLL With HSI + Trimming = 0 */
			//while(!(GET_BIT(RCC_CR,17))); /* Check if enabled */
			//while(!(GET_BIT(RCC_CR,25))); /* Check if enabled */
			
		#elif RCC_PLL_INPUT == RCC_PLL_IN_HSE_CRYSTAL
			
			RCC_CFGR = (0x00010002 | (RCC_USB_PRE<<22)| ((RCC_PLL_MUL_VAL - 2) << 18) |(RCC_ADC_PRE<<14) |(RCC_APB2_PRE<<11) |(RCC_APB1_PRE<<8)|(RCC_AHB_PRE<<4));
			
			RCC_CR = 0x01010000; /* Enable PLL With HSI + Trimming = 0 */
			//while(!(GET_BIT(RCC_CR,17))); /* Check if enabled */
			//while(!(GET_BIT(RCC_CR,25))); /* Check if enabled */
			
		#elif RCC_PLL_INPUT == RCC_PLL_IN_HSE_RC_DIV_2
			
			RCC_CFGR = (0x00030002 | (RCC_USB_PRE<<22)| ((RCC_PLL_MUL_VAL - 2) << 18) |(RCC_ADC_PRE<<14) |(RCC_APB2_PRE<<11) |(RCC_APB1_PRE<<8)|(RCC_AHB_PRE<<4));
			
			RCC_CR = 0x01050000; /* Enable PLL With HSI + Trimming = 0 */
			//while(!(GET_BIT(RCC_CR,17))); /* Check if enabled */
			//while(!(GET_BIT(RCC_CR,25))); /* Check if enabled */
			
		#elif RCC_PLL_INPUT == RCC_PLL_IN_HSE_RC
		
			RCC_CFGR = ( 0x00010002 | (RCC_USB_PRE<<22)| ((RCC_PLL_MUL_VAL - 2) << 18) |(RCC_ADC_PRE<<14) |(RCC_APB2_PRE<<11) |(RCC_APB1_PRE<<8)|(RCC_AHB_PRE<<4));
			
			RCC_CR = 0x01050000; /* Enable PLL With HSI + Trimming = 0 */
			//while(!(GET_BIT(RCC_CR,17))); /* Check if enabled */
			//while(!(GET_BIT(RCC_CR,25))); /* Check if enabled */
			
		#endif  
	
	#else
		#error("You chosed Wrong Clock type")
	#endif
}



void RCC_voidEnableClock(u8 Copy_u8BusId, u8 Copy_u8PerId)
{
	if (Copy_u8PerId <= 31)
	{
		switch (Copy_u8BusId)
		{
			case RCC_AHB  : SET_BIT(RCC_AHBENR  ,Copy_u8PerId);   break;
			case RCC_APB1 : SET_BIT(RCC_APB1ENR ,Copy_u8PerId);   break;
			case RCC_APB2 : SET_BIT(RCC_APB2ENR ,Copy_u8PerId);   break;
		}
	}
	
	else
	{
		/* Return Error */
	}

}


void RCC_voidDisableClock(u8 Copy_u8BusId, u8 Copy_u8PerId)
{
	if (Copy_u8PerId <= 31)
	{
		switch (Copy_u8BusId)
		{
			case RCC_AHB  : CLR_BIT(RCC_AHBENR  ,Copy_u8PerId);   break;
			case RCC_APB1 : CLR_BIT(RCC_APB1ENR ,Copy_u8PerId);   break;
			case RCC_APB2 : CLR_BIT(RCC_APB2ENR ,Copy_u8PerId);   break;
		}
	}
	
	else
	{
		/* Return Error */
	}

}