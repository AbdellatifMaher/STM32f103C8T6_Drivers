/***********************************************************************************/
/* Author  : Abdellatif Maher                                                      */
/* Date    : 16 AUG 2021                                                           */
/* Version : V01                                                                   */
/***********************************************************************************/
#ifndef DMA_INTERFACE_H
#define DMA_INTERFACE_H

/* Memory to Memory Mode */ 
 
#define DMA_DISABLE_MEM_MODE    0
#define DMA_ENABLE_MEM_MODE     1

/* Channel Priority Level */ 

#define  DMA_CHANNEL_PRIORITY_LEVEL_LOW      	  0
#define  DMA_CHANNEL_PRIORITY_LEVEL_MEDIUM        1
#define  DMA_CHANNEL_PRIORITY_LEVEL_HIGH          2
#define  DMA_CHANNEL_PRIORITY_LEVEL_VERYHIGH      3

/* ELEMENT SIZE */ 

#define DMA_8_BIT_SIZE          0
#define DMA_16_BIT_SIZE         1
#define DMA_32_BIT_SIZE         2

/* INCREMENT MODE */ 

#define DMA_DISABLE_INCREMENT_MODE    0
#define DMA_ENABLE_INCREMENT_MODE     1

/* CIRCULAR MODE */ 

#define DMA_DISABLE_CIRCULAR_MODE    0
#define DMA_ENABLE_CIRCULAR_MODE     1

/* Data Direction */
#define  DMA_READ_FROM_PERIPHERAL     0
#define  DMA_READ_FROM_MEMORY         1

/* INTERRUPTS */ 

#define DMA_INTERRUPT_DISABLE                                         0 
#define DMA_INTERRUPT_ENABLE_COMPLETE 								  1
#define DMA_INTERRUPT_ENABLE_HALF 									  2
#define DMA_INTERRUPT_ENABLE_COMPLETE_AND_HALF 						  3
#define DMA_INTERRUPT_ENABLE_ERROR                                    4
#define DMA_INTERRUPT_ENABLE_COMPLETE_AND_ERROR                       5
#define DMA_INTERRUPT_ENABLE_HALF_AND_ERROR                           6
#define DMA_INTERRUPT_ENABLE_COMPLETE_AND_HALF_AND_ERROR              7

/* Channels */ 

#define DMA_CHANNEL_1                  0
#define DMA_CHANNEL_2                  1
#define DMA_CHANNEL_3                  2
#define DMA_CHANNEL_4                  3
#define DMA_CHANNEL_5                  4
#define DMA_CHANNEL_6                  5
#define DMA_CHANNEL_7                  6


void DMA_voidInit(void);
void DMA_voidChannelStart(u8 Copy_u8Channel , u32* Copy_ptrSourceAddress, u32* Copy_ptrDestinationAddress, u16 Copy_u16BlockLength);
void DMA_voidSelectExtraChannel(u8 Copy_u8Channel , u32 Copy_u32RegValue);

#endif