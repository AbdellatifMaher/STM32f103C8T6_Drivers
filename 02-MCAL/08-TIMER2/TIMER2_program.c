/***********************************************************************************/
/* Author  : Abdellatif Maher                                                      */
/* Date    : 3 SEP 2021                                                           */
/* Version : V01                                                                   */
/***********************************************************************************/


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "STK_interface.h"
#include "TIMER2_interface.h"
#include "TIMER2_private.h"
#include "TIMER2_config.h"


void (*TIMER2_ptrFunc[6])(void)={0};

void TIMER2_voidInit(void)
{
		#if TIMER2_FILTER_CLOCK_DIVISION == TIMER2_FILTER_CLOCK_DIVISION_X1
					CLR_BIT(TIM2->CR1,8); CLR_BIT(TIM2->CR1,9);
		#elif TIMER2_FILTER_CLOCK_DIVISION == TIMER2_FILTER_CLOCK_DIVISION_X2
				SET_BIT(TIM2->CR1,8); CLR_BIT(TIM2->CR1,9);
		#elif TIMER2_FILTER_CLOCK_DIVISION == TIMER2_FILTER_CLOCK_DIVISION_X4
				CLR_BIT(TIM2->CR1,8); SET_BIT(TIM2->CR1,9);
		#endif

		#if    TIMER2_ARR_BUFFER == TIMER2_ARR_PRELOAD_DISABLE
				CLR_BIT(TIM2->CR1,7);
		#elif    TIMER2_ARR_BUFFER == TIMER2_ARR_PRELOAD_ENABLE
				SET_BIT(TIM2->CR1,7);
		#endif

		#if TIMER2_Aligned_MODE == TIMER2_UP_ALIGNED_MODE
					CLR_BIT(TIM2->CR1,5); CLR_BIT(TIM2->CR1,6);
					CLR_BIT(TIM2->CR1,4);
		#elif TIMER2_Aligned_MODE == TIMER2_DOWN_ALIGNED_MODE
					CLR_BIT(TIM2->CR1,5); CLR_BIT(TIM2->CR1,6);
					SET_BIT(TIM2->CR1,4);
		#elif TIMER2_Aligned_MODE == TIMER2_CENTER_ALIGNED_MODE1_UP
				SET_BIT(TIM2->CR1,5); CLR_BIT(TIM2->CR1,6);
		#elif TIMER2_Aligned_MODE == TIMER2_CENTER_ALIGNED_MODE2_DOWN
					SET_BIT(TIM2->CR1,5); CLR_BIT(TIM2->CR1,6);
		#elif TIMER2_Aligned_MODE == TIMER2_CENTER_ALIGNED_MODE3_UPDOWN
				SET_BIT(TIM2->CR1,8); SET_BIT(TIM2->CR1,9);
		#endif

		#ifdef    TIMER2_INTERRUPT_MODE
		   TIM2->DIER = 0 ;
		   TIM2->DIER = TIMER2_INTERRUPT_MODE ;
		#endif

		 TIM2->CR1 = 0b0010000000;
		 TIM2->CR2 = 0;
		 TIM2->SMCR= 0;
		 TIM2->DIER=1;
}
void TIMER2_voidEnable(void)
{
	SET_BIT(TIM2->CR1,0);
}
void TIMER2_voidDisable(void)
{
	CLR_BIT(TIM2->CR1,0);
}
void TIMER2_voidChangeAlignedMode(u8 Copy_u8Mode)
{
	/* Counter must be disabled to switch */
	TIMER2_voidDisable();
		#if Copy_u8Mode == TIMER2_UP_ALIGNED_MODE
					CLR_BIT(TIM2->CR1,5); CLR_BIT(TIM2->CR1,6);
					CLR_BIT(TIM2->CR1,4);
		#elif Copy_u8Mode == TIMER2_DOWN_ALIGNED_MODE
					CLR_BIT(TIM2->CR1,5); CLR_BIT(TIM2->CR1,6);
					SET_BIT(TIM2->CR1,4);
		#elif Copy_u8Mode == TIMER2_CENTER_ALIGNED_MODE1_UP
				SET_BIT(TIM2->CR1,5); CLR_BIT(TIM2->CR1,6);
		#elif Copy_u8Mode == TIMER2_CENTER_ALIGNED_MODE2_DOWN
					SET_BIT(TIM2->CR1,5); CLR_BIT(TIM2->CR1,6);
		#elif Copy_u8Mode == TIMER2_CENTER_ALIGNED_MODE3_UPDOWN
				SET_BIT(TIM2->CR1,8); SET_BIT(TIM2->CR1,9);
		#endif
	TIMER2_voidEnable();
}

void TIMER2_voidClearFlag(u8 Copy_u8Flag)
{
	CLR_BIT(TIM2->SR,Copy_u8Flag);
}
u8   TIMER2_u8GetFlag(u8 Copy_u8Flag)
{
	return GET_BIT(TIM2->SR,Copy_u8Flag);
}
void TIMER2_voidGenerateEvent(u8 Copy_u8Event)
{
	SET_BIT(TIM2->EGR,Copy_u8Event);
}
void TIMER2_voidSetCounter(u16 Copy_u16Counter)
{
	TIM2->CNT = Copy_u16Counter;
}
u16 TIMER2_u16GetCounter(void)
{
	 return TIM2->CNT ;
}
void TIMER2_voidSetPrescaler(u16 Copy_u16Prescaler)
{
	TIM2->PSC = Copy_u16Prescaler;
}
u16 TIMER2_u16GetPrescaler(void)
{
	return TIM2->PSC;
}
void TIMER2_voidSetAutoreload(u16 Copy_u16Number)
{
	TIM2->ARR = Copy_u16Number;
}
u16 TIMER2_u16GetAutoreload(void)
{
	return TIM2->ARR;
}
void TIMER2_voidSetCC1(u16 Copy_u16Number)
{
	TIM2->CCR1 = Copy_u16Number;
}
u16 TIMER2_u16GetCC1(void)
{
	return TIM2->CCR1 ;
}
void TIMER2_voidSetCC2(u16 Copy_u16Number)
{
	TIM2->CCR2 = Copy_u16Number;
}
u16 TIMER2_u16GetCC2(void)
{
	return TIM2->CCR2 ;
}
void TIMER2_voidSetCC3(u16 Copy_u16Number)
{
	TIM2->CCR3 = Copy_u16Number;
}
u16 TIMER2_u16GetCC3(void)
{
	return TIM2->CCR3 ;
}
void TIMER2_voidSetCC4(u16 Copy_u16Number)
{
	TIM2->CCR4 = Copy_u16Number;
}
u16 TIMER2_u16GetCC4(void)
{
	return TIM2->CCR4 ;
}
void TIMER2_voidDisableInterrupt(u8 Copy_u8Interrupt)
{
	if( Copy_u8Interrupt == TIMER2_DISABLE_INTERRUPT )
	{
		  TIM2->DIER = 0 ;
	}
	else if ( Copy_u8Interrupt ==TIMER2_UPDATE_INTERRUPT)
	{
		TIM2->DIER &= 0b11111110;
	}
	else if ( Copy_u8Interrupt == TIMER2_CC1_INTERRUPT)
	{
		TIM2->DIER &= 0b11111101;
	}
	else if ( Copy_u8Interrupt == TIMER2_CC2_INTERRUPT)
	{
		TIM2->DIER &= 0b11111011;
	}
	else if ( Copy_u8Interrupt == TIMER2_CC3_INTERRUPT)
	{
		TIM2->DIER &= 0b11110111;
	}
	else if ( Copy_u8Interrupt == TIMER2_CC4_INTERRUPT)
	{
		TIM2->DIER &= 0b11101111;
	}
	else if ( Copy_u8Interrupt == TIMER2_TRIGGER_INTERRUPT)
	{
			TIM2->DIER &= 0b10111111;
	}
}
void TIMER2_voidEnableInterrupt(u8 Copy_u8Interrupt)
{
	if ( Copy_u8Interrupt ==TIMER2_UPDATE_INTERRUPT)
		{
			TIM2->DIER |= TIMER2_UPDATE_INTERRUPT;
		}
		else if ( Copy_u8Interrupt == TIMER2_CC1_INTERRUPT)
		{
			TIM2->DIER |= TIMER2_CC1_INTERRUPT;
		}
		else if ( Copy_u8Interrupt == TIMER2_CC2_INTERRUPT)
		{
			TIM2->DIER |= TIMER2_CC2_INTERRUPT;
		}
		else if ( Copy_u8Interrupt == TIMER2_CC3_INTERRUPT)
		{
			TIM2->DIER |= TIMER2_CC3_INTERRUPT;
		}
		else if ( Copy_u8Interrupt == TIMER2_CC4_INTERRUPT)
		{
			TIM2->DIER |= TIMER2_CC4_INTERRUPT;
		}
		else if ( Copy_u8Interrupt == TIMER2_TRIGGER_INTERRUPT)
		{
				TIM2->DIER |= TIMER2_TRIGGER_INTERRUPT;
		}
}
void TIMER2_voidSetCallBack( void(*Copy_pvoidCallBack)(void) , u8 Copy_u8Interrupt)
{	if ( Copy_u8Interrupt ==TIMER2_UPDATE_INTERRUPT)
	{
		TIMER2_ptrFunc[0] = Copy_pvoidCallBack;
	}
	else if ( Copy_u8Interrupt == TIMER2_CC1_INTERRUPT)
	{
		TIMER2_ptrFunc[1] = Copy_pvoidCallBack;
	}
	else if ( Copy_u8Interrupt == TIMER2_CC2_INTERRUPT)
	{
		TIMER2_ptrFunc[2] = Copy_pvoidCallBack;
	}
	else if ( Copy_u8Interrupt == TIMER2_CC3_INTERRUPT)
	{
		TIMER2_ptrFunc[3] = Copy_pvoidCallBack;
	}
	else if ( Copy_u8Interrupt == TIMER2_CC4_INTERRUPT)
	{
		TIMER2_ptrFunc[4] = Copy_pvoidCallBack;
	}
	else if ( Copy_u8Interrupt == TIMER2_TRIGGER_INTERRUPT)
	{
		TIMER2_ptrFunc[5] = Copy_pvoidCallBack;
	}

}
void TIMER2_voidStartChannel1(u8 Copy_u8Configuration,u8 Copy_u8Mode,u8 Copy_u8Polarity)
{
	/******************************************/
	TIM2->CCMR1 &= 0xFFFC;
	TIM2->CCMR1 |= Copy_u8Configuration;
	/******************************************/
	if(Copy_u8Configuration == TIMER2_CHANNEL_OUTPUT)
	{
		/******************************************/
		TIM2->CCMR1 &= 0xFF8F;
		TIM2->CCMR1 |= (Copy_u8Mode<<4);
		/******************************************/
		if(Copy_u8Polarity == TIMER2_OC_POLARIT_ACTIVE_LOW)
		{
		SET_BIT(TIM2->CCER,1);
		}
		else if (Copy_u8Polarity == TIMER2_OC_POLARIT_ACTIVE_HIGH)
		{
		CLR_BIT(TIM2->CCER,1);
		}
		/******************************************/
		MGPIO_VidSetPinDirection(GPIOA,PIN0,OUTPUT_SPEED_10MHZ_AFPP);
		SET_BIT(TIM2->CCER,0);
		/******************************************/
	}
	else
	{
		/******************************************/
			TIM2->CCMR1 &= 0xFFF3;
			TIM2->CCMR1 |= (Copy_u8Mode<<2);
		/******************************************/
			if(Copy_u8Polarity == TIMER2_IC_POLARIT_RISING_EDGE)
			{
				CLR_BIT(TIM2->CCER,1);
			}
			else if (Copy_u8Polarity == TIMER2_IC_POLARIT_FALLING_EDGE)
			{
				SET_BIT(TIM2->CCER,1);
			}
		/******************************************/
			//MGPIO_VidSetPinDirection(GPIOA,PIN0,OUTPUT_SPEED_10MHZ_AFPP);
			SET_BIT(TIM2->CCER,0);
		/******************************************/
	}


}
void TIMER2_voidStartChannel2(u8 Copy_u8Configuration,u8 Copy_u8Mode,u8 Copy_u8Polarity)
{
	/******************************************/
	TIM2->CCMR1 &= 0xFCFF;
	TIM2->CCMR1 |= (Copy_u8Configuration<<8);
	/******************************************/
	if(Copy_u8Configuration == TIMER2_CHANNEL_OUTPUT)
	{
		/******************************************/
		TIM2->CCMR1 &= 0x8FFF;
		TIM2->CCMR1 |= (Copy_u8Mode<<12);
		/******************************************/
		if(Copy_u8Polarity == TIMER2_OC_POLARIT_ACTIVE_LOW)
		{
		SET_BIT(TIM2->CCER,5);
		}
		else if (Copy_u8Polarity == TIMER2_OC_POLARIT_ACTIVE_HIGH)
		{
		CLR_BIT(TIM2->CCER,5);
		}
		/******************************************/
		MGPIO_VidSetPinDirection(GPIOA,PIN0,OUTPUT_SPEED_10MHZ_AFPP);
		SET_BIT(TIM2->CCER,4);
		/******************************************/
	}
	else
	{
		/******************************************/
			TIM2->CCMR1 &= 0xF3FF;
			TIM2->CCMR1 |= (Copy_u8Mode<<10);
		/******************************************/
			if(Copy_u8Polarity == TIMER2_IC_POLARIT_RISING_EDGE)
			{
				CLR_BIT(TIM2->CCER,5);
			}
			else if (Copy_u8Polarity == TIMER2_IC_POLARIT_FALLING_EDGE)
			{
				SET_BIT(TIM2->CCER,5);
			}
		/******************************************/
			//MGPIO_VidSetPinDirection(GPIOA,PIN0,OUTPUT_SPEED_10MHZ_AFPP);
			SET_BIT(TIM2->CCER,4);
		/******************************************/
	}


}

void TIMER2_voidStartChannel3(u8 Copy_u8Configuration,u8 Copy_u8Mode,u8 Copy_u8Polarity)
{
	/******************************************/
	TIM2->CCMR2 &= 0xFFFC;
	TIM2->CCMR2 |= Copy_u8Configuration;
	/******************************************/
	if(Copy_u8Configuration == TIMER2_CHANNEL_OUTPUT)
	{
		/******************************************/
		TIM2->CCMR2 &= 0xFF8F;
		TIM2->CCMR2 |= (Copy_u8Mode<<4);
		/******************************************/
		if(Copy_u8Polarity == TIMER2_OC_POLARIT_ACTIVE_LOW)
		{
		SET_BIT(TIM2->CCER,9);
		}
		else if (Copy_u8Polarity == TIMER2_OC_POLARIT_ACTIVE_HIGH)
		{
		CLR_BIT(TIM2->CCER,9);
		}
		/******************************************/
		MGPIO_VidSetPinDirection(GPIOA,PIN0,OUTPUT_SPEED_10MHZ_AFPP);
		SET_BIT(TIM2->CCER,8);
		/******************************************/
	}
	else
	{
		/******************************************/
			TIM2->CCMR2 &= 0xFFF3;
			TIM2->CCMR2 |= (Copy_u8Mode<<2);
		/******************************************/
			if(Copy_u8Polarity == TIMER2_IC_POLARIT_RISING_EDGE)
			{
				CLR_BIT(TIM2->CCER,9);
			}
			else if (Copy_u8Polarity == TIMER2_IC_POLARIT_FALLING_EDGE)
			{
				SET_BIT(TIM2->CCER,9);
			}
		/******************************************/
			//MGPIO_VidSetPinDirection(GPIOA,PIN0,OUTPUT_SPEED_10MHZ_AFPP);
			SET_BIT(TIM2->CCER,8);
		/******************************************/
	}


}
void TIMER2_voidStartChannel4(u8 Copy_u8Configuration,u8 Copy_u8Mode,u8 Copy_u8Polarity)
{
	/******************************************/
	TIM2->CCMR2 &= 0xFCFF;
	TIM2->CCMR2 |= (Copy_u8Configuration<<8);
	/******************************************/
	if(Copy_u8Configuration == TIMER2_CHANNEL_OUTPUT)
	{
		/******************************************/
		TIM2->CCMR2 &= 0x8FFF;
		TIM2->CCMR2 |= (Copy_u8Mode<<12);
		/******************************************/
		if(Copy_u8Polarity == TIMER2_OC_POLARIT_ACTIVE_LOW)
		{
		SET_BIT(TIM2->CCER,13);
		}
		else if (Copy_u8Polarity == TIMER2_OC_POLARIT_ACTIVE_HIGH)
		{
		CLR_BIT(TIM2->CCER,13);
		}
		/******************************************/
		MGPIO_VidSetPinDirection(GPIOA,PIN0,OUTPUT_SPEED_10MHZ_AFPP);
		SET_BIT(TIM2->CCER,12);
		/******************************************/
	}
	else
	{
		/******************************************/
			TIM2->CCMR2 &= 0xF3FF;
			TIM2->CCMR2 |= (Copy_u8Mode<<10);
		/******************************************/
			if(Copy_u8Polarity == TIMER2_IC_POLARIT_RISING_EDGE)
			{
				CLR_BIT(TIM2->CCER,13);
			}
			else if (Copy_u8Polarity == TIMER2_IC_POLARIT_FALLING_EDGE)
			{
				SET_BIT(TIM2->CCER,13);
			}
		/******************************************/
			//MGPIO_VidSetPinDirection(GPIOA,PIN0,OUTPUT_SPEED_10MHZ_AFPP);
			SET_BIT(TIM2->CCER,12);
		/******************************************/
	}


}
void TIMER2_voidPWM( u8 Copy_u8Channel, u8 Copy_u8PWMMode, u8 Copy_u8OnTime)
{
	switch(Copy_u8Channel)
	{
	case 1 : TIMER2_voidStartChannel1(TIMER2_CHANNEL_OUTPUT,Copy_u8PWMMode,TIMER2_OC_POLARIT_ACTIVE_HIGH);
			 TIMER2_voidSetCC1(Copy_u8OnTime);break;
	case 2 : TIMER2_voidStartChannel2(TIMER2_CHANNEL_OUTPUT,Copy_u8PWMMode,TIMER2_OC_POLARIT_ACTIVE_HIGH);
			 TIMER2_voidSetCC2(Copy_u8OnTime);break;
	case 3 : TIMER2_voidStartChannel3(TIMER2_CHANNEL_OUTPUT,Copy_u8PWMMode,TIMER2_OC_POLARIT_ACTIVE_HIGH);
			 TIMER2_voidSetCC3(Copy_u8OnTime);break;
	case 4 : TIMER2_voidStartChannel4(TIMER2_CHANNEL_OUTPUT,Copy_u8PWMMode,TIMER2_OC_POLARIT_ACTIVE_HIGH);
			 TIMER2_voidSetCC4(Copy_u8OnTime);break;
	}

}
void TIMER2_voidChannelDisable(u8 Copy_u8Channel)
{
	if(Copy_u8Channel < 5)
	{
	Copy_u8Channel = Copy_u8Channel*4 - 4 ;
	CLR_BIT(TIM2->CCER,Copy_u8Channel);
	}
	else {
		for(u8 i = 0 ; i<=12;i+=4)
		{
			CLR_BIT(TIM2->CCER,i);
		}
	}
}

void TIM2_IRQHandler(void)
{
	if ( TIMER2_u8GetFlag(UIF) == 1)
	{
		if(TIMER2_ptrFunc[0] != 0)
		{
			TIMER2_ptrFunc[0]();
		}
	}
   if ( TIMER2_u8GetFlag(CC1IF) == 1)
	{
		if(TIMER2_ptrFunc[1] != 0)
		{
			TIMER2_ptrFunc[1]();
		}
	}
	if ( TIMER2_u8GetFlag(CC2IF) == 1)
	{
		if(TIMER2_ptrFunc[2] != 0)
		{
			TIMER2_ptrFunc[2]();
		}
	}
    if ( TIMER2_u8GetFlag(CC3IF) == 1)
	{
    	if(TIMER2_ptrFunc[3] != 0)
		{
			TIMER2_ptrFunc[3]();
		}
	}
    if ( TIMER2_u8GetFlag(CC4IF) == 1)
		{
			if(TIMER2_ptrFunc[4] != 0)
			{
				TIMER2_ptrFunc[4]();
			}
		}
	if ( TIMER2_u8GetFlag(TIF) == 1)
	{
		if(TIMER2_ptrFunc[5] != 0)
		{
			TIMER2_ptrFunc[5]();
		}
	}
}
