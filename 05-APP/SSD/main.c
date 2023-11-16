/*
 * main.c
 *
 *  Created on: Jul 7, 2021
 *      Author: 8
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "DIO_interface.h"
#include "SSD_interface.h"

void main(void)
{
	RCC_voidInitSysClock();
	RCC_voidEnableClock(RCC_APB2,RCC_GPIOA);
	SSD_Type LOC_structMySSD = { SSD_COMMON_CATHODE , GPIOA , PIN0 , GPIOA , PIN8 , SSD_OPEN_DOT};
	SSD_voidEnable(LOC_structMySSD);

	while(1)
	{
		for(u8 LOC_u8Counter=0; LOC_u8Counter < 10 ; LOC_u8Counter++)
		{
			SSD_voidSendNumber(LOC_structMySSD,LOC_u8Counter);
			for(u32 i = 0 ; i<1000 ; i++)
					 {
						 for(u32 j = 0; j <500 ; j++)
						 {
							 asm("NOP");
						 }
					 }

					  for(u32 i = 0 ; i<1000 ; i++)
					  {
					 	  for(u32 j = 0; j <500 ; j++)
					 	  {
					 		 asm("NOP");
					 	  }
					  }
		}
	}
}


