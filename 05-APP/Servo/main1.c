/*
 * main1.c
 *
 *  Created on: Sep 1, 2021
 *      Author: 8
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "TIMER1_interface.h"
#include <util/delay.h>

/*void T1_voidServoFunc(void)
{
	static u8 Glo_u8Counter = 0;
	Glo_u8Counter ++;
	if(Glo_u8Counter == 2)
	{
		DIO_enumSetPinValue(DIO_PORTA, DIO_PIN0,DIO_LOW);
	}
	else if(Glo_u8Counter == 40)
	{
		DIO_enumSetPinValue(DIO_PORTA, DIO_PIN0,DIO_HIGH);
		Glo_u8Counter = 0;
	}
} */

int main (void)
{
	/*TIMER1_voidInit();
	TIMER1_voidSetOCRA(500);
	TIMER1_voidSetCallBack(T1_voidServoFunc,TIMER1_INT_COMP_A_MATCH);
	DIO_enumSetPinDirection(DIO_PORTA, DIO_PIN0,DIO_OUTPUT);
	DIO_enumSetPinValue(DIO_PORTA, DIO_PIN0,DIO_HIGH);*/
	TIMER1_voidInit();
	DIO_enumSetPinDirection(DIO_PORTD, DIO_PIN5,DIO_OUTPUT);
	TIMER1_voidSetICR1(20000);
//	TIMER1_voidSetOCRA(1000);
	while(1)
	{
		TIMER1_voidSetOCRA(500);
		_delay_ms(1000);
		TIMER1_voidSetOCRA(1450);
		_delay_ms(1000);
		TIMER1_voidSetOCRA(2500);
		_delay_ms(1000);
		/*TIMER1_voidSetOCRA(2000);
		_delay_ms(100);
		TIMER1_voidSetOCRA(2500);
		_delay_ms(100);*/
	}
}

