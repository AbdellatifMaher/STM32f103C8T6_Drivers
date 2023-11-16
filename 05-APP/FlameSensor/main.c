/*
 * main.c
 *
 *  Created on: Feb 5, 2022
 *      Author: Abdellatif
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"


#include "RCC_interface.h"
#include "DIO_interface.h"
#include "AFIO_interface.h"
#include "NVIC_interface.h"
#include "EXTI_interface.h"


void func(void)
{
	MGPIO_VidSetPinValue(GPIOA,PIN1,!(MGPIO_u8GetPinValue(GPIOA,PIN1)));
}

void main(void)
{
/**************** FOR INTERRUPT **********************
	RCC_voidInitSysClock();
	RCC_voidEnableClock(RCC_APB2,RCC_GPIOA);
	RCC_voidEnableClock(RCC_APB2,RCC_AFIO);

	MEXTI_voidSetCallBack(0,func);

	MGPIO_VidSetPinDirection(GPIOA,PIN0,INPUT_PULLUP_PULLDOWN);
	MGPIO_VidSetPinValue(GPIOA,PIN0,LOW);
	MAFIO_voidSetEXTIConfiguration(0,0);

	MEXTI_voidInit();
	MEXTI_voidEnableEXTI(0);

	MNVIC_voidEnableInterrupt(6);

	MGPIO_VidSetPinDirection(GPIOA,PIN1,OUTPUT_SPEED_10MHZ_PP);
	MGPIO_VidSetPinValue(GPIOA,PIN1,LOW);
*/

/************** For polling *****************************/
	RCC_voidInitSysClock();
	RCC_voidEnableClock(RCC_APB2,RCC_GPIOC);


	MGPIO_VidSetPinDirection(GPIOC,PIN13,INPUT_PULLUP_PULLDOWN);
	MGPIO_VidSetPinValue(GPIOC,PIN13,LOW);
	MGPIO_VidSetPinDirection(GPIOC,PIN14,OUTPUT_SPEED_10MHZ_PP);
	MGPIO_VidSetPinValue(GPIOC,PIN14,LOW);

	while(1)
	{
		if( MGPIO_u8GetPinValue(GPIOC,PIN13) == HIGH)
		{
			MGPIO_VidSetPinValue(GPIOC,PIN14,HIGH);
		}
		else
		{
			MGPIO_VidSetPinValue(GPIOC,PIN14,LOW);
		}

	}
}


