/***********************************************************************************/
/* Author  : Abdellatif Maher                                                      */
/* Date    : 7 SEP 2021                                                            */
/* Version : V01                                                                   */
/***********************************************************************************/



#ifndef SPI1_INTERFACE_H
#define SPI1_INTERFACE_H

/* Data Frame */ 
#define SPI_8BIT_DATA         0
#define SPI_16BIT_DATA        1

/* SLAVE PIN */ 
#define SPI_HW_MANAGE         0
#define SPI_SW_MANAGE         3

/* Data Order */ 
#define SPI_FIRST_MSB                0
#define SPI_FIRST_LSB                1

/* Clock Rate */ 
#define SPI_CLOCK_RATE_FREQ_DIVID_BY_2          0
#define SPI_CLOCK_RATE_FREQ_DIVID_BY_4 			1	
#define SPI_CLOCK_RATE_FREQ_DIVID_BY_8          2 
#define SPI_CLOCK_RATE_FREQ_DIVID_BY_16         3
#define SPI_CLOCK_RATE_FREQ_DIVID_BY_32         4 
#define SPI_CLOCK_RATE_FREQ_DIVID_BY_64         5
#define SPI_CLOCK_RATE_FREQ_DIVID_BY_128 		6
#define SPI_CLOCK_RATE_FREQ_DIVID_BY_256 		7

/* Master/Slave Mode */ 
#define SPI_SLAVE                    0
#define SPI_MASTER                   1

/* Clock Polarity */ 
#define SPI_LEADING_RISING_TRAILING_FALLING     0
#define SPI_LEADING_FALLING_TRAILING_RISING     1

/* Clock Phase */ 
#define SPI_LEADING_SAMPLE_TRAILING_SETUP     	0
#define SPI_LEADING_SETUP_TRAILING_SAMPLE     	1

/* Interrupt Enable */ 
#define SPI_INTERRUPT_DISABLE                 (0b00000000)
#define SPI_TX_EMPTY_INTERRUPT				  (0b10000000)	
#define SPI_RX_NOT_EMPTY_INTERRUPT			  (0b01000000)
#define SPI_ERROR_INTERRUPT					  (0b00100000)

/*  Flags */ 
typedef enum 
{
	RXNE,
	TXE,
	CHSIDE,
	UDR,
	CRCERR,
	MODF,
	OVR,
	BSY
}SPI_Flags;

void SPI1_voidInit(void); 

void SPI1_voidSendReceiveSynch(u8 Copy_u8DataToTransmit, u8 * Copy_DataToReceive);

void SPI1_voidSendReceiveAsynch(u8 Copy_u8DataToTransmit, void (*CallBack)(u8));



#endif 