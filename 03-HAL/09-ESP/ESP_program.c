/****************************************************************/
/* Author    : Abdellatif Maher                                 */
/* Date      : 12 SEP 2021                                      */
/* Version   : V01                                              */
/****************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "USART_interface.h"
#include "ESP_interface.h"
#include "ESP_config.h"
#include "ESP_private.h"


u8 Local_u8Response[100] = {0};

void ESP_voidInit(void)
{
	u8 Local_u8Result = 0;
	
	while(Local_u8Result == 0)
	{
		/* Stop ECHO */
		USART_voidTransmitString(ESP_ECHO_TURN_OFF);
		Local_u8Result = ESP_u8ValidateCmd(ESP_ECHO_TIMEOUT);
	}
	
	Local_u8Result = 0;
	
	while(Local_u8Result == 0)
	{
		/* Set station mode */
		USART_voidTransmitString(ESP_FIRST_MODE_CONFIG);
		Local_u8Result = ESP_u8ValidateCmd(ESP_MODE_TIMEOUT);
	}
}



void ESP_voidSendCommand(u8 * Copy_u8Command , u32 Copy_u32Timeout)
{
	u8 Local_u8Result = 0;

	while(Local_u8Result == 0)
	{
		/* Stop ECHO */

		USART_voidTransmitString(Copy_u8Command);
		Local_u8Result = ESP_u8ValidateCmd(Copy_u32Timeout);
	}
}

u8 ESP_u8GetData(u8 * Copy_ptrLink)
{
	ESP_voidSendCommand(ESP_SEND_DATA(49),ESP_PREREQUEST_TIMEOUT);

	ESP_voidSendCommand(Copy_ptrLink,ESP_REQUEST_TIMEOUT);

	u8 Result;
	/* When we receive data from server it would be in the form +IPD,NUMBER_OF_LETTERS_RECIEVED;DATA*/
	for(u8 i = 0; i < 98; i++)
	{
		/*Checking that the data received have IPD*/
	if(Local_u8Response[i] == 'I' && Local_u8Response[i+1] == 'P' && Local_u8Response[i+2] == 'D')
		{
			/*Return data in the 6th position after the I*/
			Result = Local_u8Response[i+6];
		}
	}
	return Result;
}

u8 ESP_u8ValidateCmd(u32 Copy_u32Timeout)
{

	u8 Counter = 0;
	u8 Dummy = 0;
	u8 Result = 0;
	
	/* Empty The Response  */
	for(u8 J = 0; J < 100; J++)
	{
		Local_u8Response[J] = 0;
	}

	/*Make sure that the MC is not receiving any more data from the ESP*/
	while (Dummy != 255)
	{
		Dummy = USART_u8ReceiveTimeout(Copy_u32Timeout);
		Local_u8Response[Counter] = Dummy;
		Counter++;
	}
	
	/*	Deleting last element as it is always 255 for stop receiving data	*/
		Local_u8Response[Counter-1] = 0;

	/* Check if Ok */
/*	if (Local_u8Response[i-3] == 'O' && Local_u8Response[i-2] == 'K')
	{
		Result = 1;
	}*/

	/* Checks if any of the received data contains the word "OK" meaning the command is done successfully*/
	for(u8 i = 0; i < Counter - 2; i ++)
	{
		if(Local_u8Response[i] == 'O' && Local_u8Response[i+1] == 'K')
		{
			Result = 1;
		}
	}
	
	return Result;
}

