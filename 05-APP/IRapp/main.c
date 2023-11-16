/*
 * main.c
 *
 *  Created on: Jul 28, 2021
 *      Author: 8
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "DIO_interface.h"
#include "NVIC_interface.h"
#include "EXTI_interface.h"
#include "STK_interface.h"
#include "AFIO_interface.h"
#include "IR_interface.h"

void MyFunc(void)
{
	switch(GLO_u8Data)
	{

	  case 12:MGPIO_VidSetPinValue(GPIOA,PIN1,HIGH); break;
	  case 24:MGPIO_VidSetPinValue(GPIOA,PIN2,HIGH); break;
	  case 94:MGPIO_VidSetPinValue(GPIOA,PIN3,HIGH); break;
	  case 8:MGPIO_VidSetPinValue(GPIOA,PIN1,LOW); break;
	  case 28:MGPIO_VidSetPinValue(GPIOA,PIN2,LOW); break;
	  case 90:MGPIO_VidSetPinValue(GPIOA,PIN3,LOW); break;
	  case 69:MGPIO_VidSetPinValue(GPIOA,PIN1,!(MGPIO_u8GetPinValue(GPIOA,PIN1)));
	  	  	  MGPIO_VidSetPinValue(GPIOA,PIN1,!(MGPIO_u8GetPinValue(GPIOA,PIN2)));
	  	  	  MGPIO_VidSetPinValue(GPIOA,PIN1,!(MGPIO_u8GetPinValue(GPIOA,PIN3))); break;
	}
}

void main(void)
{
	RCC_voidInitSysClock();
	RCC_voidEnableClock(RCC_APB2 ,RCC_GPIOA);
	RCC_voidEnableClock(RCC_APB2 ,RCC_AFIO);
	MGPIO_VidSetPinDirection(GPIOA,PIN1,OUTPUT_SPEED_10MHZ_PP);
	MGPIO_VidSetPinDirection(GPIOA,PIN2,OUTPUT_SPEED_10MHZ_PP);
	MGPIO_VidSetPinDirection(GPIOA,PIN3,OUTPUT_SPEED_10MHZ_PP);
	GLO_ptrFunc = MyFunc ;
	IR_voidInit();

	while(1)
	{

	}
}


