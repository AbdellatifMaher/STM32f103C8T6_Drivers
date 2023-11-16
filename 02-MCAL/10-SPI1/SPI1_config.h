/***********************************************************************************/
/* Author  : Abdellatif Maher                                                      */
/* Date    : 7 SEP 2021                                                            */
/* Version : V01                                                                   */
/***********************************************************************************/



#ifndef SPI1_CONFIG_H
#define SPI1_CONFIG_H

/* Write it in a pair port,pin */
#define SPI1_SLAVE_PIN  			 	GPIOA,0

#define SPI_DATA_FRAME     			 	SPI_8BIT_DATA

#define SPI_SLAVE_PIN_MANAGE  			SPI_SW_MANAGE

#define SPI_DATA_ORDER      			SPI_FIRST_LSB

#define SPI_CLOCK_RATE     			 	SPI_CLOCK_RATE_FREQ_DIVID_BY_2

#define SPI_MODE             			SPI_MASTER

#define SPI_CLOCK_POLARITY   			SPI_LEADING_FALLING_TRAILING_RISING

#define SPI_CLOCK_PHASE      			SPI_LEADING_SETUP_TRAILING_SAMPLE

#define SPI_INTERRUPT_ENABLE            SPI_INTERRUPT_DISABLE

#endif 