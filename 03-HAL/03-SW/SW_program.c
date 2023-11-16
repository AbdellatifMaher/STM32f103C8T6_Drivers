/***********************************************************************************/
/* Author  : Abdellatif Maher                                                      */
/* Date    : 15 JUL 2021                                                           */
/* Version : V01                                                                   */
/***********************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "SW_interface.h"
#include "SW_private.h"
#include "SW_config.h"

void SW_voidInit    ( SW_Type SW_Configuration)
{
	/*DIO_enumSetPinDirection( SW_Configuration.Port , SW_Configuration.Pin , DIO_INPUT);
	
	if( SW_Configuration.Pull_State == SW_PULL_UP )
	{
		DIO_enumSetPinValue( SW_Configuration.Port , SW_Configuration.Pin , DIO_HIGH);
	}
	else if( SW_Configuration.Pull_State == SW_FLOATING )
	{
		DIO_enumSetPinValue( SW_Configuration.Port , SW_Configuration.Pin , DIO_LOW );
	} */
	switch(SW_Configuration.State)
	{
		case SW_PULL_DOWN : MGPIO_VidSetPinDirection(SW_Configuration.Port , SW_Configuration.Pin ,INPUT_PULLUP_PULLDOWN);
							MGPIO_VidSetPinValue(SW_Configuration.Port , SW_Configuration.Pin ,LOW);  break; 
		case SW_PULL_UP   : MGPIO_VidSetPinDirection(SW_Configuration.Port , SW_Configuration.Pin ,INPUT_PULLUP_PULLDOWN);
							MGPIO_VidSetPinValue(SW_Configuration.Port , SW_Configuration.Pin ,HIGH);  break; 
		case SW_FLOATING  : MGPIO_VidSetPinDirection(SW_Configuration.Port , SW_Configuration.Pin ,INPUT_FLOATING);break;
		default           : /* return Error */ break;
	}
}
u8   SW_u8GetPressed( SW_Type SW_Configuration)
{
	u8 LOC_u8Result = 0;
	LOC_u8Result = MGPIO_u8GetPinValue ( SW_Configuration.Port , SW_Configuration.Pin );
	return LOC_u8Result;
}
