/***********************************************************************************/
/* Author  : Abdellatif Maher                                                      */
/* Date    : 7 SEP 2021                                                            */
/* Version : V01                                                                   */
/***********************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "SPI1_interface.h"
#include "SPI1_config.h"
#include "SPI1_private.h"



void (*CallBack)(u8)=0;

void SPI1_voidInit(void)
{
	SPI1->CR1  = 0;
	SPI1->CR1  = SPI_CLOCK_PHASE ;
	SPI1->CR1 |= (SPI_CLOCK_POLARITY<<1);
	SPI1->CR1 |= (SPI_MODE<<2);
	SPI1->CR1 |= (SPI_CLOCK_RATE<<3);
	SPI1->CR1 |= (SPI_DATA_ORDER<<7);
	SPI1->CR1 |= (SPI_SLAVE_PIN_MANAGE<<9);
	SPI1->CR1 |= (SPI_DATA_FRAME<<11);
	SPI1->CR2  = 0 ;
	SPI1->CR2 |= SPI_INTERRUPT_ENABLE ;
	SPI1->CR1 |= (1<<6);
//	SPI->CR1 = 0x0347; /* 0000 0011 0100 0111 */
	MGPIO_VidSetPinDirection(SPI1_SLAVE_PIN,OUTPUT_SPEED_10MHZ_PP);
}

void SPI1_voidSendReceiveSynch(u8 Copy_u8DataToTransmit, u8 *Copy_DataToReceive)
{
	/* Clear For Slave Select Pin */
	MGPIO_VidSetPinValue(SPI1_SLAVE_PIN,LOW);
	
	/* Send Data */
	SPI1 -> DR = Copy_u8DataToTransmit;
	
	/* Wait Busy Flag to finish */
	while (GET_BIT(SPI1 -> SR, BSY) == 1);

 	/* Return to the received data */
	*Copy_DataToReceive = SPI1 -> DR;
	
	/* Set Salve Select Pin */
	MGPIO_VidSetPinValue(SPI1_SLAVE_PIN,HIGH);
}
void SPI1_voidSendReceiveAsynch(u8 Copy_u8DataToTransmit, void (*CallBack)(u8))
{
	/* Empty */
}



