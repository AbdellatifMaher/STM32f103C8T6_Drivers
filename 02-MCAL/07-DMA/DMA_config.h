/***********************************************************************************/
/* Author  : Abdellatif Maher                                                      */
/* Date    : 16 AUG 2021                                                           */
/* Version : V01                                                                   */
/***********************************************************************************/
#ifndef DMA_CONFIG_H
#define DMA_CONFIG_H

#define DMA_CHANNEL                    DMA_CHANNEL_1 

#define DMA_MEMORY_TO_MEMORY_MODE      DMA_ENABLE_MEM_MODE

#define DMA_CHANNEL_PRIORITY           DMA_CHANNEL_PRIORITY_LEVEL_VERYHIGH

#define DMA_MEMORY_SIZE                DMA_8_BIT_SIZE
#define DMA_PERIPHERAL_SIZE	           DMA_8_BIT_SIZE

#define DMA_MEMORY_INCREMENT           DMA_ENABLE_INCREMENT_MODE
#define DMA_PERIPHERAL_INCREMENT       DMA_ENABLE_INCREMENT_MODE

#define DMA_CIRCULAR_MODE 			   DMA_DISABLE_CIRCULAR_MODE 

#define DMA_DATA_DIRECTION             DMA_READ_FROM_PERIPHERAL


#define DMA_INTERRUPT_ENABLE           DMA_INTERRUPT_ENABLE_COMPLETE

#endif