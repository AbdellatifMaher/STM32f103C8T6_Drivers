/****************************************************************/
/* Author    : Abdellatif Maher                                 */
/* Date      : 15 SEP 2021                                      */
/* Version   : V01                                              */
/****************************************************************/
#ifndef TFT_INTERFACE_H
#define TFT_INTERFACE_H

#define TFT_SLEEP_OUT_CMD        0x11

#define TFT_COLOR_MODE_CMD       0x3A

#define TFT_RGB444_CMD			 0x03
#define TFT_RGB565_CMD			 0x05
#define TFT_RGB666_CMD			 0x06

#define TFT_DISPLAY_ON_CMD       0x29

#define TFT_SET_X_ADDRESS_CMD	 0x2A
#define TFT_SET_Y_ADDRESS_CMD	 0x2B

#define TFT_RAM_WRITE_CMD		 0x2C

void TFT_voidInit		  (void);
void TFT_voidDisplayImage (const u16* Copy_Image);
void TFT_voidFillColor 	  (u16 Copy_u16Color);
void TFT_voidDrawRect (u8 x1,u8 x2, u8 y1,u8 y2,u16 Copy_u16Color);

#endif