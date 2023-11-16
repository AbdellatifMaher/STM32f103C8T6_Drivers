/***********************************************************************************/
/* Author  : Abdellatif Maher                                                      */
/* Date    : 15 JUL 2021                                                           */
/* Version : V01                                                                   */
/***********************************************************************************/


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "LED_interface.h"
#include "LED_private.h"
#include "LED_config.h"



void LED_voidInit  ( LED_Type LED_Configuration )
{
	MGPIO_VidSetPinDirection(LED_Configuration.Port , LED_Configuration.Pin , OUTPUT_SPEED_10MHZ_PP);
}
void LED_voidOn    ( LED_Type LED_Configuration )
{
	if( LED_Configuration.Active_State == ACTIVE_HIGH )
	{
		MGPIO_VidSetPinValue(LED_Configuration.Port , LED_Configuration.Pin , HIGH);
	}
	else if( LED_Configuration.Active_State == ACTIVE_LOW )
	{
		MGPIO_VidSetPinValue(LED_Configuration.Port , LED_Configuration.Pin , LOW);
	}
}
void LED_voidOff   ( LED_Type LED_Configuration )
{
	if( LED_Configuration.Active_State == ACTIVE_HIGH )
	{
		MGPIO_VidSetPinValue(LED_Configuration.Port , LED_Configuration.Pin , LOW);
	}
	else if( LED_Configuration.Active_State == ACTIVE_LOW )
	{
		MGPIO_VidSetPinValue(LED_Configuration.Port , LED_Configuration.Pin , HIGH);
	}	
}
void LED_voidToggle( LED_Type LED_Configuration )
{
	u8 LOC_u8LastState ;
	LOC_u8LastState = MGPIO_u8GetPinValue ( LED_Configuration.Port , LED_Configuration.Pin );
	MGPIO_VidSetPinValue( LED_Configuration.Port , LED_Configuration.Pin , !LOC_u8LastState  );
}
