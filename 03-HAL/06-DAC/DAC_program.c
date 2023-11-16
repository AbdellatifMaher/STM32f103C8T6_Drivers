/***********************************************************************************/
/* Author  : Abdellatif Maher                                                      */
/* Date    : 15 AUG 2021                                                           */
/* Version : V01                                                                   */
/***********************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
               
#include "DIO_interface.h"
#include "STK_interface.h"

#include "DAC_interface.h"
#include "DAC_private.h"
#include "DAC_config.h"
#include "song.h"

void DAC_Init(void)
{
	MGPIO_VidSetPinDirection(DAC_BIT0,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_VidSetPinDirection(DAC_BIT1,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_VidSetPinDirection(DAC_BIT2,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_VidSetPinDirection(DAC_BIT3,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_VidSetPinDirection(DAC_BIT4,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_VidSetPinDirection(DAC_BIT5,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_VidSetPinDirection(DAC_BIT6,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_VidSetPinDirection(DAC_BIT7,OUTPUT_SPEED_2MHZ_PP);
}
void DAC_Start(void)
{
	MSTK_voidInit();
	MSTK_voidSetIntervalPeriodic( DAC_TIME_OF_SAMPLE , DAC_PlaySong);
}

void DAC_PlaySong(void)
{
	static u32  LOC_u32Counter = 0;
	MGPIO_VidSetPinValue(DAC_BIT0,GET_BIT(DAC_NAME_OF_ARRAY[LOC_u32Counter],PIN0));
	MGPIO_VidSetPinValue(DAC_BIT1,GET_BIT(DAC_NAME_OF_ARRAY[LOC_u32Counter],PIN1));
	MGPIO_VidSetPinValue(DAC_BIT2,GET_BIT(DAC_NAME_OF_ARRAY[LOC_u32Counter],PIN2));
	MGPIO_VidSetPinValue(DAC_BIT3,GET_BIT(DAC_NAME_OF_ARRAY[LOC_u32Counter],PIN3));
	MGPIO_VidSetPinValue(DAC_BIT4,GET_BIT(DAC_NAME_OF_ARRAY[LOC_u32Counter],PIN4));
	MGPIO_VidSetPinValue(DAC_BIT5,GET_BIT(DAC_NAME_OF_ARRAY[LOC_u32Counter],PIN5));
	MGPIO_VidSetPinValue(DAC_BIT6,GET_BIT(DAC_NAME_OF_ARRAY[LOC_u32Counter],PIN6));
	MGPIO_VidSetPinValue(DAC_BIT7,GET_BIT(DAC_NAME_OF_ARRAY[LOC_u32Counter],PIN7));
	LOC_u32Counter++;
	if(LOC_u32Counter == DAC_SIZE_OF_ARRAY)
	{
		LOC_u32Counter = 0;
	}

}