/*
 * main.c
 *
 *  Created on: Sep 9, 2021
 *      Author: 8
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "CLCD_interface.h"
#include "LED_interface.h"
#include "SPI_interface.h"
volatile u8 MYAVR = 0 ;
int main(void)
{
	LED_Type LED1 = {DIO_PORTD,DIO_PIN0,ACTIVE_HIGH};
	LED_Type LED2 = {DIO_PORTD,DIO_PIN7,ACTIVE_HIGH};
	SPI_voidInit();
	LED_voidInit(LED1);
	LED_voidInit(LED2);
	LED_voidOn(LED2);
	CLCD_voidInit();
	while(1)
	{

		MYAVR = SPI_u8Transmitter_ReceiverSlave(5);
		if(MYAVR != 0)
		{
			LED_voidOn(LED1);

		}
	}
	return 0;
}
