/*
 * main.c
 *
 *  Created on: Sep 10, 2021
 *      Author: 8
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "RCC_interface.h"
#include "DIO_interface.h"
#include "USART_interface.h"


int main(void)
{
	RCC_voidInitSysClock();
	RCC_voidEnableClock(RCC_APB2,RCC_USART1 );
	RCC_voidEnableClock(RCC_APB2,RCC_GPIOA );

	MGPIO_VidSetPinDirection(GPIOA,PIN9,OUTPUT_SPEED_10MHZ_PP);
	MGPIO_VidSetPinDirection(GPIOA,PIN10,INPUT_FLOATING);

	MGPIO_VidSetPinDirection(GPIOA,PIN0,OUTPUT_SPEED_10MHZ_PP);

	USART_voidInit();

	u8 x ;
	while(1)
	{
		x = USART_u8Receive();
		if(x == '5')
		{
			MGPIO_VidSetPinValue(GPIOA,PIN0,HIGH);
			USART_voidTransmitString((u8 *)"BBBB\r\n");
		}
		else if(x == 'r')
		{
			USART_voidTransmitString((u8 *)"CCCC\r\n");
			MGPIO_VidSetPinValue(GPIOA,PIN0,LOW);
		}

	}
	return 0;
}
