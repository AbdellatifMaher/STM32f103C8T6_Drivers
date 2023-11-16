/*
 * main.c
 *
 *  Created on: Sep 13, 2021
 *      Author: 8
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "RCC_interface.h"
#include "DIO_interface.h"
#include "STK_interface.h"
#include "USART_interface.h"
#include "USART_private.h"
#include "ESP_interface.h"

int main(void)
{
	RCC_voidInitSysClock();
	RCC_voidEnableClock(RCC_APB2,RCC_USART1 );
	RCC_voidEnableClock(RCC_APB2,RCC_GPIOA );

	MGPIO_VidSetPinDirection(GPIOA,PIN9,OUTPUT_SPEED_10MHZ_AFPP);
	MGPIO_VidSetPinDirection(GPIOA,PIN10,INPUT_FLOATING);

	MGPIO_VidSetPinDirection(GPIOA,PIN0,OUTPUT_SPEED_10MHZ_PP);
	MGPIO_VidSetPinDirection(GPIOA,PIN1,OUTPUT_SPEED_10MHZ_PP);
	MSTK_voidInit();

	USART_voidInit();

	ESP_voidInit();

	ESP_voidSendCommand(ESP_TEST,ESP_ECHO_TIMEOUT);

	ESP_voidSendCommand(ESP_ROUTER_CONNECT("\"ACDIMMER\"","\"5VoltTo220\""),ESP_ROUTER_TIMEOUT);
//	USART_voidTransmitString((u8*)"ATE0\r\n");
//	USART1 -> DR = 'A';
//	while((GET_BIT((USART1 -> SR), TC)) == 0);
//	CLR_BIT((USART1 -> SR), TC);
//	while((GET_BIT((USART1 -> SR), TXE)) == 0);
//	USART1 -> DR = 'T';
//	while((GET_BIT((USART1 -> SR), TC)) == 0);
//	CLR_BIT((USART1 -> SR), TC);
//	while((GET_BIT((USART1 -> SR), TXE)) == 0);
/*	USART1 -> DR = '\r';
//	while((GET_BIT((USART1 -> SR), TC)) == 0);
//	CLR_BIT((USART1 -> SR), TC);
	while((GET_BIT((USART1 -> SR), TXE)) == 0);
	USART1 -> DR = '\n';
	while((GET_BIT((USART1 -> SR), TC)) == 0);
//	CLR_BIT((USART1 -> SR), TC);
	while((GET_BIT((USART1 -> SR), TXE)) == 0);*/
//	u8 X = USART_u8Receive();
//	u8 Y = USART_u8Receive();
//	MGPIO_VidSetPinValue(GPIOA,PIN0,HIGH);
//	MSTK_voidSetBusyWait(500000);
//	MGPIO_VidSetPinValue(GPIOA,PIN0,LOW);

/*	USART_voidTransmitString((u8*)"AT\r\n");
		 X = USART_u8Receive();
		 Y = USART_u8Receive();
	if( X == 'O' || Y == 'K')
	{
		MGPIO_VidSetPinValue(GPIOA,PIN0,HIGH);
	}
	if(X == '\r' || Y == '\n')
	{
		MGPIO_VidSetPinValue(GPIOA,PIN1,HIGH);
	}*/

/*	ESP_voidSendCommand(ESP_SW_RESTART);

	MGPIO_VidSetPinValue(GPIOA,PIN0,HIGH);
	MSTK_voidSetBusyWait(500000);
	MGPIO_VidSetPinValue(GPIOA,PIN0,LOW);

	ESP_voidSendCommand(ESP_FIRST_MODE_CONFIG);

	MGPIO_VidSetPinValue(GPIOA,PIN0,HIGH);
	MSTK_voidSetBusyWait(500000);
	MGPIO_VidSetPinValue(GPIOA,PIN0,LOW);*/
	while(1)
	{
		ESP_voidSendCommand(ESP_SITE_CONNECT("\"162.253.155.227\""),ESP_SERVER_TIMEOUT);
		u8 LED1 = ESP_u8GetData(ESP_DATA("http://abdofirstweb.orgfree.com/LEDfile.txt"));

		if(LED1 == '1')
		{
			MGPIO_VidSetPinValue(GPIOA,PIN0,HIGH);
		}
		else if (LED1 == '0')
		{
			MGPIO_VidSetPinValue(GPIOA,PIN0,LOW);
		}
		else
		{
			MGPIO_VidSetPinValue(GPIOA,PIN0,HIGH);
		}

	}
	return 0;
}




