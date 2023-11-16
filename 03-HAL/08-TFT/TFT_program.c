/****************************************************************/
/* Author    : Abdellatif Maher                                 */
/* Date      : 15 SEP 2021                                      */
/* Version   : V01                                              */
/****************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "SPI1_interface.h"
#include "STK_interface.h"

#include "TFT_interface.h"
#include "TFT_private.h"
#include "TFT_config.h"


void TFT_voidInit		  (void)
{
	/* Reset Pulse */
	MGPIO_VidSetPinValue(TFT_RST_PIN,HIGH);
	MSTK_voidSetBusyWait(100);
	MGPIO_VidSetPinValue(TFT_RST_PIN,LOW);
	MSTK_voidSetBusyWait(1);
	MGPIO_VidSetPinValue(TFT_RST_PIN,HIGH);
	MSTK_voidSetBusyWait(100);
	MGPIO_VidSetPinValue(TFT_RST_PIN,LOW);
	MSTK_voidSetBusyWait(100);
	MGPIO_VidSetPinValue(TFT_RST_PIN,HIGH);
	MSTK_voidSetBusyWait(120000);
	
	/* Sleep Out Command */
	voidWriteCommand(TFT_SLEEP_OUT_CMD);
	
	/* Wait 150 ms */
	MSTK_voidSetBusyWait(150000);
	
	/* Color Mode Command */
	voidWriteCommand(TFT_COLOR_MODE_CMD);
	voidWriteData   (TFT_RGB565_CMD);
	
	/* Display On Command */
	voidWriteCommand(TFT_DISPLAY_ON_CMD);
}
void TFT_voidDisplayImage (const u16* Copy_Image)
{
	u16 counter;
	u8 Data;

	/* Set X Address */
	voidWriteCommand(TFT_SET_X_ADDRESS_CMD);
	voidWriteData(0);
	voidWriteData(0);
	voidWriteData(0);
	voidWriteData(127);
	
	/* Set Y Address */
	voidWriteCommand(TFT_SET_Y_ADDRESS_CMD);
	voidWriteData(0);
	voidWriteData(0);
	voidWriteData(0);
	voidWriteData(159);

	/* RAM Write */
	voidWriteCommand(TFT_RAM_WRITE_CMD);

	for(counter = 0; counter< 20480;counter++)
	{
		Data = Copy_Image[counter] >> 8;

		/* Write the high byte */
		voidWriteData(Data);
		/* Write the low byte */
		Data = Copy_Image[counter] & 0x00ff;
		voidWriteData(Data);
	}
}
void TFT_voidFillColor (u16 Copy_u16Color)
{
	u16 counter;
	u8 Data;

	/* Set X Address */
	voidWriteCommand(TFT_SET_X_ADDRESS_CMD);
	voidWriteData(0);
	voidWriteData(0);
	voidWriteData(0);
	voidWriteData(127);
	
	/* Set Y Address */
	voidWriteCommand(TFT_SET_Y_ADDRESS_CMD);
	voidWriteData(0);
	voidWriteData(0);
	voidWriteData(0);
	voidWriteData(159);

	/* RAM Write */
	voidWriteCommand(TFT_RAM_WRITE_CMD);

	for(counter = 0; counter< 20480;counter++)
	{
		Data = Copy_u16Color >> 8;

		/* Write the high byte */
		voidWriteData(Data);
		/* Write the low byte */
		Data = Copy_u16Color & 0x00ff;
		voidWriteData(Data);
	}
}

void TFT_voidDrawRect (u8 x1,u8 x2, u8 y1,u8 y2,u16 Copy_u16Color)
{
	u16 counter;
	u8 Data;
	u16 Size = (x2 - x1) * (y2 - y1);
	/* Set X Address */
	voidWriteCommand(TFT_SET_X_ADDRESS_CMD);
	voidWriteData(0);
	voidWriteData(x1);
	voidWriteData(0);
	voidWriteData(x2);
	
	/* Set Y Address */
	voidWriteCommand(TFT_SET_Y_ADDRESS_CMD);
	voidWriteData(0);
	voidWriteData(y1);
	voidWriteData(0);
	voidWriteData(y2);

	/* RAM Write */
	voidWriteCommand(TFT_RAM_WRITE_CMD);

	for(counter = 0; counter< Size;counter++)
	{
		Data = Copy_u16Color >> 8;

		/* Write the high byte */
		voidWriteData(Data);
		/* Write the low byte */
		Data = Copy_u16Color & 0x00ff;
		voidWriteData(Data);
	}
}
static void voidWriteCommand(u8 Copy_u8Command)
{
	u8 Local_u8Temp;
	
	/* Set A0 Pin to Low */
	MGPIO_VidSetPinValue(TFT_A0_PIN,LOW);
	
	/* Send Command over SPI */
	SPI1_voidSendReceiveSynch(Copy_u8Command,&Local_u8Temp);
}
static void voidWriteData   (u8 Copy_u8Data)
{
	u8 Local_u8Temp;
	
	/* Set A0 Pin to High */
	MGPIO_VidSetPinValue(TFT_A0_PIN,HIGH);
	
	/* Send data over SPI */
	SPI1_voidSendReceiveSynch(Copy_u8Data,&Local_u8Temp);
}
