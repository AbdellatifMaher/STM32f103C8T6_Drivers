/***********************************************************************************/
/* Author  : Abdellatif Maher                                                      */
/* Date    : 16 AUG 2021                                                           */
/* Version : V01                                                                   */
/***********************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
               
#include "DMA_interface.h"
#include "DMA_private.h"
#include "DMA_config.h"


void DMA_voidInit(void)
{
	/* Disable The Channel */ 
	
	CLR_BIT(DMA->Channel[DMA_CHANNEL].CCR,0);
	
	/* Memory to Memory Mode */ 
	
	#if DMA_MEMORY_TO_MEMORY_MODE == DMA_DISABLE_MEM_MODE
		
		CLR_BIT(DMA->Channel[DMA_CHANNEL].CCR,14);
		
	#elif DMA_MEMORY_TO_MEMORY_MODE ==  DMA_ENABLE_MEM_MODE	
			
		SET_BIT(DMA->Channel[DMA_CHANNEL].CCR,14);	
	#endif 
	
	/* Channel Priority Level */ 
	
	#if DMA_CHANNEL_PRIORITY == DMA_CHANNEL_PRIORITY_LEVEL_LOW
		
		CLR_BIT(DMA->Channel[DMA_CHANNEL].CCR,12);
		CLR_BIT(DMA->Channel[DMA_CHANNEL].CCR,13);
		
	#elif DMA_CHANNEL_PRIORITY ==  DMA_CHANNEL_PRIORITY_LEVEL_MEDIUM	
			
		SET_BIT(DMA->Channel[DMA_CHANNEL].CCR,12);
		CLR_BIT(DMA->Channel[DMA_CHANNEL].CCR,13);
		
	#elif DMA_CHANNEL_PRIORITY ==  DMA_CHANNEL_PRIORITY_LEVEL_HIGH	
			
		CLR_BIT(DMA->Channel[DMA_CHANNEL].CCR,12);
		SET_BIT(DMA->Channel[DMA_CHANNEL].CCR,13);
		
	#elif DMA_CHANNEL_PRIORITY ==  DMA_CHANNEL_PRIORITY_LEVEL_VERYHIGH	
			
		SET_BIT(DMA->Channel[DMA_CHANNEL].CCR,12);
		SET_BIT(DMA->Channel[DMA_CHANNEL].CCR,13);	
		
	#endif 
	
	/* Memory SIZE */ 
	#if DMA_MEMORY_SIZE == DMA_8_BIT_SIZE
		
		CLR_BIT(DMA->Channel[DMA_CHANNEL].CCR,10);
		CLR_BIT(DMA->Channel[DMA_CHANNEL].CCR,11);
		
	#elif DMA_MEMORY_SIZE ==  DMA_16_BIT_SIZE	
			
		SET_BIT(DMA->Channel[DMA_CHANNEL].CCR,10);
		CLR_BIT(DMA->Channel[DMA_CHANNEL].CCR,11);
		
	#elif DMA_MEMORY_SIZE ==  DMA_32_BIT_SIZE	
				
		CLR_BIT(DMA->Channel[DMA_CHANNEL].CCR,10);
		SET_BIT(DMA->Channel[DMA_CHANNEL].CCR,11);	
		
	#endif 
	
	/* Peripheral SIZE */ 
	#if DMA_PERIPHERAL_SIZE == DMA_8_BIT_SIZE
		
		CLR_BIT(DMA->Channel[DMA_CHANNEL].CCR,8);
		CLR_BIT(DMA->Channel[DMA_CHANNEL].CCR,9);
		
	#elif DMA_PERIPHERAL_SIZE ==  DMA_16_BIT_SIZE	
			
		SET_BIT(DMA->Channel[DMA_CHANNEL].CCR,8);
		CLR_BIT(DMA->Channel[DMA_CHANNEL].CCR,9);
		
	#elif DMA_PERIPHERAL_SIZE ==  DMA_32_BIT_SIZE	
				
		CLR_BIT(DMA->Channel[DMA_CHANNEL].CCR,8);
		SET_BIT(DMA->Channel[DMA_CHANNEL].CCR,9);	
		
	#endif 
	
	/* MEMORY INCREMENT MODE */ 
	#if DMA_MEMORY_INCREMENT == DMA_DISABLE_INCREMENT_MODE
		
		CLR_BIT(DMA->Channel[DMA_CHANNEL].CCR,7);
		
	#elif DMA_MEMORY_INCREMENT ==  DMA_ENABLE_INCREMENT_MODE	
			
		SET_BIT(DMA->Channel[DMA_CHANNEL].CCR,7);	
	#endif
	
	/* Peripheral INCREMENT MODE */ 
	#if DMA_PERIPHERAL_INCREMENT == DMA_DISABLE_INCREMENT_MODE
		
		CLR_BIT(DMA->Channel[DMA_CHANNEL].CCR,6);
		
	#elif DMA_PERIPHERAL_INCREMENT ==  DMA_ENABLE_INCREMENT_MODE	
			
		SET_BIT(DMA->Channel[DMA_CHANNEL].CCR,6);	
	#endif
	
	/* CIRCULAR MODE */ 
	#if DMA_CIRCULAR_MODE == DMA_DISABLE_CIRCULAR_MODE
		
		CLR_BIT(DMA->Channel[DMA_CHANNEL].CCR,5);
		
	#elif DMA_CIRCULAR_MODE ==  DMA_ENABLE_CIRCULAR_MODE	
			
		SET_BIT(DMA->Channel[DMA_CHANNEL].CCR,5);	
	#endif
	
	/* Data Direction */
	#if DMA_DATA_DIRECTION == DMA_READ_FROM_PERIPHERAL
		
		CLR_BIT(DMA->Channel[DMA_CHANNEL].CCR,5);
		
	#elif DMA_DATA_DIRECTION ==  DMA_READ_FROM_MEMORY	
			
		SET_BIT(DMA->Channel[DMA_CHANNEL].CCR,5);	
	#endif
	
	/* INTERRUPTS */
	
	#if DMA_INTERRUPT_ENABLE == DMA_INTERRUPT_DISABLE
		
		CLR_BIT(DMA->Channel[DMA_CHANNEL].CCR,1);
		CLR_BIT(DMA->Channel[DMA_CHANNEL].CCR,2);
		CLR_BIT(DMA->Channel[DMA_CHANNEL].CCR,3);
		
	#elif DMA_INTERRUPT_ENABLE ==  DMA_INTERRUPT_ENABLE_COMPLETE	
			
		SET_BIT(DMA->Channel[DMA_CHANNEL].CCR,1);
		CLR_BIT(DMA->Channel[DMA_CHANNEL].CCR,2);
		CLR_BIT(DMA->Channel[DMA_CHANNEL].CCR,3);
		
	#elif DMA_INTERRUPT_ENABLE ==  DMA_INTERRUPT_ENABLE_HALF	
				
		CLR_BIT(DMA->Channel[DMA_CHANNEL].CCR,1);
		SET_BIT(DMA->Channel[DMA_CHANNEL].CCR,2);
		CLR_BIT(DMA->Channel[DMA_CHANNEL].CCR,3);
		
	#elif DMA_INTERRUPT_ENABLE == DMA_INTERRUPT_ENABLE_COMPLETE_AND_HALF
		
		SET_BIT(DMA->Channel[DMA_CHANNEL].CCR,1);
		SET_BIT(DMA->Channel[DMA_CHANNEL].CCR,2);
		CLR_BIT(DMA->Channel[DMA_CHANNEL].CCR,3);
		
	#elif DMA_INTERRUPT_ENABLE ==  DMA_INTERRUPT_ENABLE_ERROR	
			
		CLR_BIT(DMA->Channel[DMA_CHANNEL].CCR,1);
		CLR_BIT(DMA->Channel[DMA_CHANNEL].CCR,2);
		SET_BIT(DMA->Channel[DMA_CHANNEL].CCR,3);
		
	#elif DMA_INTERRUPT_ENABLE ==  DMA_INTERRUPT_ENABLE_COMPLETE_AND_ERROR	
				
		SET_BIT(DMA->Channel[DMA_CHANNEL].CCR,1);
		CLR_BIT(DMA->Channel[DMA_CHANNEL].CCR,2);
		SET_BIT(DMA->Channel[DMA_CHANNEL].CCR,3);	
		
	#elif DMA_INTERRUPT_ENABLE ==  DMA_INTERRUPT_ENABLE_HALF_AND_ERROR	
			
		CLR_BIT(DMA->Channel[DMA_CHANNEL].CCR,1);
		SET_BIT(DMA->Channel[DMA_CHANNEL].CCR,2);
		SET_BIT(DMA->Channel[DMA_CHANNEL].CCR,3);
		
	#elif DMA_INTERRUPT_ENABLE ==  DMA_INTERRUPT_ENABLE_COMPLETE_AND_HALF_AND_ERROR	
				
		SET_BIT(DMA->Channel[DMA_CHANNEL].CCR,1);
		SET_BIT(DMA->Channel[DMA_CHANNEL].CCR,2);
		SET_BIT(DMA->Channel[DMA_CHANNEL].CCR,3);	
		
	#endif
	
}
void DMA_voidChannelStart(u8 Copy_u8Channel , u32* Copy_ptrPeripheralAddress, u32* Copy_ptrMemoryAddress, u16 Copy_u16BlockLength)
{
	CLR_BIT(DMA->Channel[DMA_CHANNEL].CCR,0);
	DMA->Channel[Copy_u8Channel].CNDTR = Copy_u16BlockLength ;
	DMA->Channel[Copy_u8Channel].CPAR  = Copy_ptrPeripheralAddress ;
	DMA->Channel[Copy_u8Channel].CMAR  = Copy_ptrMemoryAddress ;
	SET_BIT(DMA->Channel[DMA_CHANNEL].CCR,0);
}
void DMA_voidSelectExtraChannel(u8 Copy_u8Channel , u32 Copy_u32RegValue)
{
	CLR_BIT(DMA->Channel[DMA_CHANNEL].CCR,0);
	DMA->Channel[Copy_u8Channel].CCR = Copy_u32RegValue ;
}
void DMA_voidInterruptFunction(void (*Fptr) (void))
{
	
}