/***********************************************************************************/
/* Author  : Abdellatif Maher                                                      */
/* Date    : 3 SEP 2021                                                           */
/* Version : V01                                                                   */
/***********************************************************************************/


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_module.h"
#include "STK_module.h"
#include "TIMER4_interface.h"
#include "TIMER4_private.h"
#include "TIMER4_config.h"


void (*TIMER4_ptrFunc[6])(void)={0};

void TIMER4_voidInit(void)
{
		#if TIMER4_FILTER_CLOCK_DIVISION == TIMER4_FILTER_CLOCK_DIVISION_X1
					CLR_BIT(TIM4->CR1,8); CLR_BIT(TIM4->CR1,9);
		#elif TIMER4_FILTER_CLOCK_DIVISION == TIMER4_FILTER_CLOCK_DIVISION_X2
				SET_BIT(TIM4->CR1,8); CLR_BIT(TIM4->CR1,9);
		#elif TIMER4_FILTER_CLOCK_DIVISION == TIMER4_FILTER_CLOCK_DIVISION_X4
				CLR_BIT(TIM4->CR1,8); SET_BIT(TIM4->CR1,9);
		#endif

		#if    TIMER4_ARR_BUFFER == TIMER4_ARR_PRELOAD_DISABLE
				CLR_BIT(TIM4->CR1,7);
		#elif    TIMER4_ARR_BUFFER == TIMER4_ARR_PRELOAD_ENABLE
				SET_BIT(TIM4->CR1,7);
		#endif

		#if TIMER4_Aligned_MODE == TIMER4_UP_ALIGNED_MODE
					CLR_BIT(TIM4->CR1,5); CLR_BIT(TIM4->CR1,6);
					CLR_BIT(TIM4->CR1,4);
		#elif TIMER4_Aligned_MODE == TIMER4_DOWN_ALIGNED_MODE
					CLR_BIT(TIM4->CR1,5); CLR_BIT(TIM4->CR1,6);
					SET_BIT(TIM4->CR1,4);
		#elif TIMER4_Aligned_MODE == TIMER4_CENTER_ALIGNED_MODE1_UP
				SET_BIT(TIM4->CR1,5); CLR_BIT(TIM4->CR1,6);
		#elif TIMER4_Aligned_MODE == TIMER4_CENTER_ALIGNED_MODE2_DOWN
					SET_BIT(TIM4->CR1,5); CLR_BIT(TIM4->CR1,6);
		#elif TIMER4_Aligned_MODE == TIMER4_CENTER_ALIGNED_MODE3_UPDOWN
				SET_BIT(TIM4->CR1,8); SET_BIT(TIM4->CR1,9);
		#endif

		#ifdef    TIMER4_INTERRUPT_MODE
		   TIM4->DIER = 0 ;
		   TIM4->DIER = TIMER4_INTERRUPT_MODE ;
		#endif


}
void TIMER4_voidInit2(void)
{
	SET_BIT(TIM4->CR1,0);
	SET_BIT(TIM4->DIER,0);
}
void TIMER4_voidEnable(void)
{
	SET_BIT(TIM4->CR1,0);
}
void TIMER4_voidDisable(void)
{
	CLR_BIT(TIM4->CR1,0);
}
void TIMER4_voidChangeAlignedMode(u8 Copy_u8Mode)
{
	/* Counter must be disabled to switch */
	TIMER4_voidDisable();
		#if Copy_u8Mode == TIMER4_UP_ALIGNED_MODE
					CLR_BIT(TIM4->CR1,5); CLR_BIT(TIM4->CR1,6);
					CLR_BIT(TIM4->CR1,4);
		#elif Copy_u8Mode == TIMER4_DOWN_ALIGNED_MODE
					CLR_BIT(TIM4->CR1,5); CLR_BIT(TIM4->CR1,6);
					SET_BIT(TIM4->CR1,4);
		#elif Copy_u8Mode == TIMER4_CENTER_ALIGNED_MODE1_UP
				SET_BIT(TIM4->CR1,5); CLR_BIT(TIM4->CR1,6);
		#elif Copy_u8Mode == TIMER4_CENTER_ALIGNED_MODE2_DOWN
					SET_BIT(TIM4->CR1,5); CLR_BIT(TIM4->CR1,6);
		#elif Copy_u8Mode == TIMER4_CENTER_ALIGNED_MODE3_UPDOWN
				SET_BIT(TIM4->CR1,8); SET_BIT(TIM4->CR1,9);
		#endif
	TIMER4_voidEnable();
}

void TIMER4_voidClearFlag(u8 Copy_u8Flag)
{
	CLR_BIT(TIM4->SR,Copy_u8Flag);
}
u8   TIMER4_u8GetFlag(u8 Copy_u8Flag)
{
	return GET_BIT(TIM4->SR,Copy_u8Flag);
}
void TIMER4_voidGenerateEvent(u8 Copy_u8Event)
{
	SET_BIT(TIM4->EGR,Copy_u8Event);
}
void TIMER4_voidSetCounter(u16 Copy_u16Counter)
{
	TIM4->CNT = Copy_u16Counter;
}
u16 TIMER4_u16GetCounter(void)
{
	 return TIM4->CNT ;
}
void TIMER4_voidSetPrescaler(u16 Copy_u16Prescaler)
{
	TIM4->PSC = Copy_u16Prescaler;
}
u16 TIMER4_u16GetPrescaler(void)
{
	return TIM4->PSC;
}
void TIMER4_voidSetAutoreload(u16 Copy_u16Number)
{
	TIM4->ARR = Copy_u16Number;
}
u16 TIMER4_u16GetAutoreload(void)
{
	return TIM4->ARR;
}
void TIMER4_voidSetCC1(u16 Copy_u16Number)
{
	TIM4->CCR1 = Copy_u16Number;
}
u16 TIMER4_u16GetCC1(void)
{
	return TIM4->CCR1 ;
}
void TIMER4_voidSetCC2(u16 Copy_u16Number)
{
	TIM4->CCR2 = Copy_u16Number;
}
u16 TIMER4_u16GetCC2(void)
{
	return TIM4->CCR2 ;
}
void TIMER4_voidSetCC3(u16 Copy_u16Number)
{
	TIM4->CCR3 = Copy_u16Number;
}
u16 TIMER4_u16GetCC3(void)
{
	return TIM4->CCR3 ;
}
void TIMER4_voidSetCC4(u16 Copy_u16Number)
{
	TIM4->CCR4 = Copy_u16Number;
}
u16 TIMER4_u16GetCC4(void)
{
	return TIM4->CCR4 ;
}
void TIMER4_voidDisableInterrupt(u8 Copy_u8Interrupt)
{
	if( Copy_u8Interrupt == TIMER4_DISABLE_INTERRUPT )
	{
		  TIM4->DIER = 0 ;
	}
	else if ( Copy_u8Interrupt ==TIMER4_UPDATE_INTERRUPT)
	{
		TIM4->DIER &= 0b11111110;
	}
	else if ( Copy_u8Interrupt == TIMER4_CC1_INTERRUPT)
	{
		TIM4->DIER &= 0b11111101;
	}
	else if ( Copy_u8Interrupt == TIMER4_CC2_INTERRUPT)
	{
		TIM4->DIER &= 0b11111011;
	}
	else if ( Copy_u8Interrupt == TIMER4_CC3_INTERRUPT)
	{
		TIM4->DIER &= 0b11110111;
	}
	else if ( Copy_u8Interrupt == TIMER4_CC4_INTERRUPT)
	{
		TIM4->DIER &= 0b11101111;
	}
	else if ( Copy_u8Interrupt == TIMER4_TRIGGER_INTERRUPT)
	{
			TIM4->DIER &= 0b10111111;
	}
}
void TIMER4_voidEnableInterrupt(u8 Copy_u8Interrupt)
{
	if ( Copy_u8Interrupt ==TIMER4_UPDATE_INTERRUPT)
		{
			TIM4->DIER |= TIMER4_UPDATE_INTERRUPT;
		}
		else if ( Copy_u8Interrupt == TIMER4_CC1_INTERRUPT)
		{
			TIM4->DIER |= TIMER4_CC1_INTERRUPT;
		}
		else if ( Copy_u8Interrupt == TIMER4_CC2_INTERRUPT)
		{
			TIM4->DIER |= TIMER4_CC2_INTERRUPT;
		}
		else if ( Copy_u8Interrupt == TIMER4_CC3_INTERRUPT)
		{
			TIM4->DIER |= TIMER4_CC3_INTERRUPT;
		}
		else if ( Copy_u8Interrupt == TIMER4_CC4_INTERRUPT)
		{
			TIM4->DIER |= TIMER4_CC4_INTERRUPT;
		}
		else if ( Copy_u8Interrupt == TIMER4_TRIGGER_INTERRUPT)
		{
				TIM4->DIER |= TIMER4_TRIGGER_INTERRUPT;
		}
}
void TIMER4_voidSetCallBack( void(*Copy_pvoidCallBack)(void) , u8 Copy_u8Interrupt)
{	if ( Copy_u8Interrupt ==TIMER4_UPDATE_INTERRUPT)
	{
		TIMER4_ptrFunc[0] = Copy_pvoidCallBack;
	}
	else if ( Copy_u8Interrupt == TIMER4_CC1_INTERRUPT)
	{
		TIMER4_ptrFunc[1] = Copy_pvoidCallBack;
	}
	else if ( Copy_u8Interrupt == TIMER4_CC2_INTERRUPT)
	{
		TIMER4_ptrFunc[2] = Copy_pvoidCallBack;
	}
	else if ( Copy_u8Interrupt == TIMER4_CC3_INTERRUPT)
	{
		TIMER4_ptrFunc[3] = Copy_pvoidCallBack;
	}
	else if ( Copy_u8Interrupt == TIMER4_CC4_INTERRUPT)
	{
		TIMER4_ptrFunc[4] = Copy_pvoidCallBack;
	}
	else if ( Copy_u8Interrupt == TIMER4_TRIGGER_INTERRUPT)
	{
		TIMER4_ptrFunc[5] = Copy_pvoidCallBack;
	}

}
void TIMER4_voidStartChannel1(u8 Copy_u8Configuration,u8 Copy_u8Mode,u8 Copy_u8Polarity)
{
	/******************************************/
	TIM4->CCMR1 &= 0xFFFC;
	TIM4->CCMR1 |= Copy_u8Configuration;
	/******************************************/
	if(Copy_u8Configuration == TIMER4_CHANNEL_OUTPUT)
	{
		/******************************************/
		TIM4->CCMR1 &= 0xFF8F;
		TIM4->CCMR1 |= (Copy_u8Mode<<4);
		/******************************************/
		if(Copy_u8Polarity == TIMER4_OC_POLARIT_ACTIVE_LOW)
		{
		SET_BIT(TIM4->CCER,1);
		}
		else if (Copy_u8Polarity == TIMER4_OC_POLARIT_ACTIVE_HIGH)
		{
		CLR_BIT(TIM4->CCER,1);
		}
		/******************************************/
		//MGPIO_VidSetPinDirection(GPIOA,PIN0,OUTPUT_SPEED_10MHZ_AFPP);
		SET_BIT(TIM4->CCER,0);
		/******************************************/
	}
	else
	{
		/******************************************/
			TIM4->CCMR1 &= 0xFFF3;
			TIM4->CCMR1 |= (Copy_u8Mode<<2);
		/******************************************/
			if(Copy_u8Polarity == TIMER4_IC_POLARIT_RISING_EDGE)
			{
				CLR_BIT(TIM4->CCER,1);
			}
			else if (Copy_u8Polarity == TIMER4_IC_POLARIT_FALLING_EDGE)
			{
				SET_BIT(TIM4->CCER,1);
			}
		/******************************************/
			//MGPIO_VidSetPinDirection(GPIOA,PIN0,OUTPUT_SPEED_10MHZ_AFPP);
			SET_BIT(TIM4->CCER,0);
		/******************************************/
	}


}
void TIMER4_voidStartChannel2(u8 Copy_u8Configuration,u8 Copy_u8Mode,u8 Copy_u8Polarity)
{
	/******************************************/
	TIM4->CCMR1 &= 0xFCFF;
	TIM4->CCMR1 |= (Copy_u8Configuration<<8);
	/******************************************/
	if(Copy_u8Configuration == TIMER4_CHANNEL_OUTPUT)
	{
		/******************************************/
		TIM4->CCMR1 &= 0x8FFF;
		TIM4->CCMR1 |= (Copy_u8Mode<<12);
		/******************************************/
		if(Copy_u8Polarity == TIMER4_OC_POLARIT_ACTIVE_LOW)
		{
		SET_BIT(TIM4->CCER,5);
		}
		else if (Copy_u8Polarity == TIMER4_OC_POLARIT_ACTIVE_HIGH)
		{
		CLR_BIT(TIM4->CCER,5);
		}
		/******************************************/
		MGPIO_VidSetPinDirection(GPIOA,PIN0,OUTPUT_SPEED_10MHZ_AFPP);
		SET_BIT(TIM4->CCER,4);
		/******************************************/
	}
	else
	{
		/******************************************/
			TIM4->CCMR1 &= 0xF3FF;
			TIM4->CCMR1 |= (Copy_u8Mode<<10);
		/******************************************/
			if(Copy_u8Polarity == TIMER4_IC_POLARIT_RISING_EDGE)
			{
				CLR_BIT(TIM4->CCER,5);
			}
			else if (Copy_u8Polarity == TIMER4_IC_POLARIT_FALLING_EDGE)
			{
				SET_BIT(TIM4->CCER,5);
			}
		/******************************************/
			//MGPIO_VidSetPinDirection(GPIOA,PIN0,OUTPUT_SPEED_10MHZ_AFPP);
			SET_BIT(TIM4->CCER,4);
		/******************************************/
	}


}

void TIMER4_voidStartChannel3(u8 Copy_u8Configuration,u8 Copy_u8Mode,u8 Copy_u8Polarity)
{
	/******************************************/
	TIM4->CCMR2 &= 0xFFFC;
	TIM4->CCMR2 |= Copy_u8Configuration;
	/******************************************/
	if(Copy_u8Configuration == TIMER4_CHANNEL_OUTPUT)
	{
		/******************************************/
		TIM4->CCMR2 &= 0xFF8F;
		TIM4->CCMR2 |= (Copy_u8Mode<<4);
		/******************************************/
		if(Copy_u8Polarity == TIMER4_OC_POLARIT_ACTIVE_LOW)
		{
		SET_BIT(TIM4->CCER,9);
		}
		else if (Copy_u8Polarity == TIMER4_OC_POLARIT_ACTIVE_HIGH)
		{
		CLR_BIT(TIM4->CCER,9);
		}
		/******************************************/
		MGPIO_VidSetPinDirection(GPIOA,PIN0,OUTPUT_SPEED_10MHZ_AFPP);
		SET_BIT(TIM4->CCER,8);
		/******************************************/
	}
	else
	{
		/******************************************/
			TIM4->CCMR2 &= 0xFFF3;
			TIM4->CCMR2 |= (Copy_u8Mode<<2);
		/******************************************/
			if(Copy_u8Polarity == TIMER4_IC_POLARIT_RISING_EDGE)
			{
				CLR_BIT(TIM4->CCER,9);
			}
			else if (Copy_u8Polarity == TIMER4_IC_POLARIT_FALLING_EDGE)
			{
				SET_BIT(TIM4->CCER,9);
			}
		/******************************************/
			//MGPIO_VidSetPinDirection(GPIOA,PIN0,OUTPUT_SPEED_10MHZ_AFPP);
			SET_BIT(TIM4->CCER,8);
		/******************************************/
	}


}
void TIMER4_voidStartChannel4(u8 Copy_u8Configuration,u8 Copy_u8Mode,u8 Copy_u8Polarity)
{
	/******************************************/
	TIM4->CCMR2 &= 0xFCFF;
	TIM4->CCMR2 |= (Copy_u8Configuration<<8);
	/******************************************/
	if(Copy_u8Configuration == TIMER4_CHANNEL_OUTPUT)
	{
		/******************************************/
		TIM4->CCMR2 &= 0x8FFF;
		TIM4->CCMR2 |= (Copy_u8Mode<<12);
		/******************************************/
		if(Copy_u8Polarity == TIMER4_OC_POLARIT_ACTIVE_LOW)
		{
		SET_BIT(TIM4->CCER,13);
		}
		else if (Copy_u8Polarity == TIMER4_OC_POLARIT_ACTIVE_HIGH)
		{
		CLR_BIT(TIM4->CCER,13);
		}
		/******************************************/
		MGPIO_VidSetPinDirection(GPIOA,PIN0,OUTPUT_SPEED_10MHZ_AFPP);
		SET_BIT(TIM4->CCER,12);
		/******************************************/
	}
	else
	{
		/******************************************/
			TIM4->CCMR2 &= 0xF3FF;
			TIM4->CCMR2 |= (Copy_u8Mode<<10);
		/******************************************/
			if(Copy_u8Polarity == TIMER4_IC_POLARIT_RISING_EDGE)
			{
				CLR_BIT(TIM4->CCER,13);
			}
			else if (Copy_u8Polarity == TIMER4_IC_POLARIT_FALLING_EDGE)
			{
				SET_BIT(TIM4->CCER,13);
			}
		/******************************************/
			//MGPIO_VidSetPinDirection(GPIOA,PIN0,OUTPUT_SPEED_10MHZ_AFPP);
			SET_BIT(TIM4->CCER,12);
		/******************************************/
	}


}
void TIMER4_voidPWM( u8 Copy_u8Channel, u8 Copy_u8PWMMode, u8 Copy_u8OnTime)
{
	switch(Copy_u8Channel)
	{
	case 1 : TIMER4_voidStartChannel1(TIMER4_CHANNEL_OUTPUT,Copy_u8PWMMode,TIMER4_OC_POLARIT_ACTIVE_HIGH);
			 TIMER4_voidSetCC1(Copy_u8OnTime);break;
	case 2 : TIMER4_voidStartChannel2(TIMER4_CHANNEL_OUTPUT,Copy_u8PWMMode,TIMER4_OC_POLARIT_ACTIVE_HIGH);
			 TIMER4_voidSetCC2(Copy_u8OnTime);break;
	case 3 : TIMER4_voidStartChannel3(TIMER4_CHANNEL_OUTPUT,Copy_u8PWMMode,TIMER4_OC_POLARIT_ACTIVE_HIGH);
			 TIMER4_voidSetCC3(Copy_u8OnTime);break;
	case 4 : TIMER4_voidStartChannel4(TIMER4_CHANNEL_OUTPUT,Copy_u8PWMMode,TIMER4_OC_POLARIT_ACTIVE_HIGH);
			 TIMER4_voidSetCC4(Copy_u8OnTime);break;
	}

}
void TIMER4_voidChannelDisable(u8 Copy_u8Channel)
{
	if(Copy_u8Channel < 5)
	{
	Copy_u8Channel = Copy_u8Channel*4 - 4 ;
	CLR_BIT(TIM4->CCER,Copy_u8Channel);
	}
	else {
		for(u8 i = 0 ; i<=12;i+=4)
		{
			CLR_BIT(TIM4->CCER,i);
		}
	}
}

void TIM4_IRQHandler(void)
{
	if ( TIMER4_u8GetFlag(UIF4) == 1)
	{
		if(TIMER4_ptrFunc[0] != 0)
		{
			TIMER4_ptrFunc[0]();
			TIMER4_voidClearFlag(UIF4);
			//CLR_BIT(TIM4->SR,UIF);
		}
	}
   if ( TIMER4_u8GetFlag(CC1IF4) == 1)
	{
		if(TIMER4_ptrFunc[1] != 0)
		{
			TIMER4_ptrFunc[1]();
		}
	}
	if ( TIMER4_u8GetFlag(CC2IF4) == 1)
	{
		if(TIMER4_ptrFunc[2] != 0)
		{
			TIMER4_ptrFunc[2]();
		}
	}
    if ( TIMER4_u8GetFlag(CC3IF4) == 1)
	{
    	if(TIMER4_ptrFunc[3] != 0)
		{
			TIMER4_ptrFunc[3]();
		}
	}
    if ( TIMER4_u8GetFlag(CC4IF4) == 1)
		{
			if(TIMER4_ptrFunc[4] != 0)
			{
				TIMER4_ptrFunc[4]();
			}
		}
	if ( TIMER4_u8GetFlag(TIF4) == 1)
	{
		if(TIMER4_ptrFunc[5] != 0)
		{
			TIMER4_ptrFunc[5]();
		}
	}
}
/*
void TIM4_IRQHandler(void)
{
	TIMER4_ptrFunc[0]();
	CLR_BIT(TIM4->SR,UIF);
}*/
