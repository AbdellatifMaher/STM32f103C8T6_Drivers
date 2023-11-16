/*
 * main.c
 *
 *  Created on: Jul 11, 2021
 *      Author: 8
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "DIO_interface.h"
#include "NVIC_interface.h"

void main(void)
{
	RCC_voidInitSysClock();
	RCC_voidEnableClock(RCC_APB2,2);
	MGPIO_VidSetPinDirection(GPIOA,0,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_VidSetPinDirection(GPIOA,1,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_VidSetPinDirection(GPIOA,2,OUTPUT_SPEED_2MHZ_PP);
	MNVIC_voidEnableInterrupt(6);
	MNVIC_voidSetPendingFlag(6);
	while(1)
	{

	}
}

void EXTI0_IRQHandler(void)
{
	MGPIO_VidSetPinValue(GPIOA,0,HIGH);
}
void EXTI1_IRQHandler(void)
{
	MGPIO_VidSetPinValue(GPIOA,1,HIGH);
}
