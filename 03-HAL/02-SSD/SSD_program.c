/***********************************************************************************/
/* Author  : Abdellatif Maher                                                      */
/* Date    : 6 JUL 2021                                                            */
/* Version : V01                                                                   */
/***********************************************************************************/


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "SSD_interface.h"
#include "SSD_private.h"
#include "SSD_config.h"

//Common Cathode
const u8 SSD_u8Numbers[10]={0b10111111, 0b10000110 ,0b11011011,0b11001111,0b11100110 ,0b11101101,0b11111101 ,0b10000111, 0b11111111,0b11101111 };

void SSD_voidSendNumber( SSD_Type Copy_structConfig , u8 Copy_u8Number )
{
	for(u8 LOC_u8Counter = Copy_structConfig.FirstPin ; LOC_u8Counter < (Copy_structConfig.FirstPin + 8) ; LOC_u8Counter++)
	{
		if( LOC_u8Counter == (Copy_structConfig.FirstPin+7) && Copy_structConfig.DotState == SSD_CLOSE_DOT )
		{
			/* Empty Operation */ 
		}
		else
		{
			MGPIO_VidSetPinDirection( Copy_structConfig.DataPort , LOC_u8Counter , OUTPUT_SPEED_10MHZ_PP); 
		}
	}
	if( Copy_structConfig.Type == SSD_COMMON_CATHODE ){
		u8 LOC_u8Counter2 = 0;
    for(u8 LOC_u8Counter = Copy_structConfig.FirstPin ; LOC_u8Counter < (Copy_structConfig.FirstPin + 8) ; LOC_u8Counter++)
	{
		
		if( LOC_u8Counter == (Copy_structConfig.FirstPin+7) && Copy_structConfig.DotState == SSD_CLOSE_DOT )
		{
			/* Empty Operation */ 
		}
		else
		{
			MGPIO_VidSetPinValue( Copy_structConfig.DataPort , LOC_u8Counter , GET_BIT(SSD_u8Numbers[Copy_u8Number] , LOC_u8Counter2)); 
			LOC_u8Counter2++;
		}
	}
		
	}
	else if( Copy_structConfig.Type == SSD_COMMON_ANODE ){
		u8 LOC_u8Counter2 = 0;
	 for(u8 LOC_u8Counter = Copy_structConfig.FirstPin ; LOC_u8Counter < (Copy_structConfig.FirstPin + 8) ; LOC_u8Counter++)
	{
		
		if( LOC_u8Counter == (Copy_structConfig.FirstPin+7) && Copy_structConfig.DotState == SSD_CLOSE_DOT )
		{
			/* Empty Operation */ 
		}
		else
		{
			MGPIO_VidSetPinValue( Copy_structConfig.DataPort , LOC_u8Counter , GET_BIT(~(SSD_u8Numbers[Copy_u8Number]) , LOC_u8Counter2)); 
			LOC_u8Counter2++;
		}
	}
		
	}
}
void SSD_voidEnable    ( SSD_Type Copy_structConfig )
{
	MGPIO_VidSetPinDirection( Copy_structConfig.EnablePort , Copy_structConfig.EnablePin , OUTPUT_SPEED_10MHZ_PP); 
	if( Copy_structConfig.Type == SSD_COMMON_CATHODE ){
		
		MGPIO_VidSetPinValue( Copy_structConfig.EnablePort , Copy_structConfig.EnablePin , LOW );
		
	}else if( Copy_structConfig.Type == SSD_COMMON_ANODE ){
		
		MGPIO_VidSetPinValue( Copy_structConfig.EnablePort , Copy_structConfig.EnablePin , HIGH );
		
	}
}
void SSD_voidDisable   ( SSD_Type Copy_structConfig )
{
	if( Copy_structConfig.Type == SSD_COMMON_CATHODE ){
		
		MGPIO_VidSetPinValue( Copy_structConfig.EnablePort , Copy_structConfig.EnablePin , HIGH );
		
	}else if( Copy_structConfig.Type == SSD_COMMON_ANODE ){
		
		MGPIO_VidSetPinValue( Copy_structConfig.EnablePort , Copy_structConfig.EnablePin , LOW );
		
	}
}