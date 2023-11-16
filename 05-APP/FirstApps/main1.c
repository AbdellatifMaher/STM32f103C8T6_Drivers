/*
 * main1.c
 *
 *  Created on: Jul 16, 2021
 *      Author: 8
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "RCC_interface.h"
#include "DIO_interface.h"
#include "LED_interface.h"
#include "STK_interface.h"



void main(void)
{
	LED_Type LEDs[8] = { {GPIOA , PIN0 , ACTIVE_HIGH} ,
						 {GPIOA , PIN1 , ACTIVE_HIGH} ,
						 {GPIOA , PIN2 , ACTIVE_HIGH} ,
						 {GPIOA , PIN3 , ACTIVE_HIGH} ,
						 {GPIOA , PIN4 , ACTIVE_HIGH} ,
						 {GPIOA , PIN5 , ACTIVE_HIGH} ,
						 {GPIOA , PIN6 , ACTIVE_HIGH} ,
						 {GPIOA , PIN7 , ACTIVE_HIGH} };
	RCC_voidInitSysClock();
	RCC_voidEnableClock(RCC_APB2,RCC_GPIOA);
	MSTK_voidInit();
	for(u8 LOC_u8Counter = 0 ; LOC_u8Counter < 8 ; LOC_u8Counter++)
	{
		LED_voidInit(LEDs[LOC_u8Counter]);
	}

	while(1)
	{
		for(u8 LOC_u8Counter1 = 0 ; LOC_u8Counter1 < 4 ; LOC_u8Counter1++)
		{
			for(u8 LOC_u8Counter2 = 0 ; LOC_u8Counter2 < 8 ; LOC_u8Counter2++)
			{
				if(LOC_u8Counter2 == 0)	{
					LED_voidOff(LEDs[7]);
					LED_voidOn(LEDs[0]);
					MSTK_voidSetBusyWait(200000);

						}
				else{
					LED_voidOff(LEDs[LOC_u8Counter2 - 1]);
					LED_voidOn(LEDs[LOC_u8Counter2]);
					MSTK_voidSetBusyWait(200000);

				   }
			}

			}
		for(u8 LOC_u8Counter1 = 0 ; LOC_u8Counter1 < 4 ; LOC_u8Counter1++)
		{
			for(u8 LOC_u8Counter2 = 0 ; LOC_u8Counter2 < 8 ; LOC_u8Counter2++)
			{
					if(LOC_u8Counter2 < 4)
					{
						LED_voidOn(LEDs[LOC_u8Counter2]);
						LED_voidOn(LEDs[7 - LOC_u8Counter2]);
						MSTK_voidSetBusyWait(200000);
					}
					else{

						LED_voidOff(LEDs[LOC_u8Counter2]);
						LED_voidOff(LEDs[7 - LOC_u8Counter2]);
						MSTK_voidSetBusyWait(200000);
					}

				}

			}
		for(u8 LOC_u8Counter1 = 0 ; LOC_u8Counter1 < 4 ; LOC_u8Counter1++)
		{
			for(u8 LOC_u8Counter2 = 0 ; LOC_u8Counter2 < 8 ; LOC_u8Counter2++)
			{
				LED_voidOn(LEDs[LOC_u8Counter2]);

				}
			MSTK_voidSetBusyWait(200000);
			for(u8 LOC_u8Counter2 = 0 ; LOC_u8Counter2 < 8 ; LOC_u8Counter2++)
			{
				LED_voidOff(LEDs[LOC_u8Counter2]);

				}
				MSTK_voidSetBusyWait(200000);



			}

	}
}
