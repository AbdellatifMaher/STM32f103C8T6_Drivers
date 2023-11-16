/***********************************************************************************/
/* Author  : Abdellatif Maher                                                      */
/* Date    : 19 JUL 2021                                                           */
/* Version : V01                                                                   */
/***********************************************************************************/


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "STK_interface.h"
#include "LEDMRX_interface.h"
#include "LEDMRX_private.h"
#include "LEDMRX_config.h"



void HLEDMAT_voidInit(void)
{
	for(u8  LOC_u8Counter = 0 ; LOC_u8Counter < 8 ; LOC_u8Counter ++)
	{
		MGPIO_VidSetPinDirection( GLO_arrRowPotrs[LOC_u8Counter],GLO_arrRowPins[LOC_u8Counter],OUTPUT_SPEED_2MHZ_PP); 
	}
	for(u8  LOC_u8Counter = 0 ; LOC_u8Counter < 8 ; LOC_u8Counter ++)
	{
		MGPIO_VidSetPinDirection( GLO_arrColPotrs[LOC_u8Counter],GLO_arrColPins[LOC_u8Counter],OUTPUT_SPEED_2MHZ_PP); 
		MGPIO_VidSetPinValue(GLO_arrColPotrs[LOC_u8Counter],GLO_arrColPins[LOC_u8Counter], HIGH);
	}
}

void HLEDMAT_voidDisplayFrame(u8 *Copy_u8Frame)
{
	for(u8  LOC_u8Counter = 0 ; LOC_u8Counter < 8 ; LOC_u8Counter ++)
	{
		
		SetRowsValue(Copy_u8Frame[LOC_u8Counter]);
		ActivateColumn(LOC_u8Counter);
		MSTK_voidSetBusyWait(2000);
		MGPIO_VidSetPinValue(GLO_arrColPotrs[Copy_u8Col],GLO_arrColPins[Copy_u8Col], HIGH);

	}
}

void SetRowsValue  (u8 Copy_u8Value)
{
	for(u8  LOC_u8Counter = 0 ; LOC_u8Counter < 8 ; LOC_u8Counter ++)
	{
		MGPIO_VidSetPinValue( GLO_arrRowPotrs[LOC_u8Counter],GLO_arrRowPins[LOC_u8Counter],GET_BIT(Copy_u8Value,LOC_u8Counter)); 
	}
}
void ActivateColumn(u8 Copy_u8Col)
{
	if(Copy_u8Col == 0)
	{
		MGPIO_VidSetPinValue(GLO_arrColPotrs[7],GLO_arrColPins[7], HIGH);
		MGPIO_VidSetPinValue(GLO_arrColPotrs[Copy_u8Col],GLO_arrColPins[Copy_u8Col], LOW);
	}
	else
	{
		MGPIO_VidSetPinValue(GLO_arrColPotrs[Copy_u8Col -1],GLO_arrColPins[Copy_u8Col -1], HIGH);
		MGPIO_VidSetPinValue(GLO_arrColPotrs[Copy_u8Col],GLO_arrColPins[Copy_u8Col], LOW);
	}
}