/*
 * main.c
 *
 *  Created on: Aug 14, 2021
 *      Author: 8
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "DIO_interface.h"
#include "STK_interface.h"
#include "LED_interface.h"
#include "OS_interface.h"

LED_Type LED1 = { GPIOA , PIN0 , ACTIVE_HIGH};
LED_Type LED2 = { GPIOA , PIN1 , ACTIVE_HIGH};
LED_Type LED3 = { GPIOA , PIN2 , ACTIVE_HIGH};

void FLED1(void)
{
	LED_voidToggle(LED1);
}
void FLED2(void)
{
	LED_voidToggle(LED2);
}
void FLED3(void)
{
	LED_voidToggle(LED3);
}


int main(void)
{


	RCC_voidInitSysClock();
	RCC_voidEnableClock(RCC_APB2,RCC_GPIOA);
	LED_voidInit(LED1);
	LED_voidInit(LED2);
	LED_voidInit(LED3);

	OS_voidCreateTask(0,1000,FLED1,0);
	OS_voidCreateTask(1,2000,FLED2,1);
	OS_voidCreateTask(2,3000,FLED3,2);

	OS_voidStart();

	while(1)
	{

	}
}


