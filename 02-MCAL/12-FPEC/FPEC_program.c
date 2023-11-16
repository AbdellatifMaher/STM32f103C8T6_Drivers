/***********************************************************************************/
/* Author  : Abdellatif Maher                                                      */
/* Date    : 22 AUG 2022                                                           */
/* Version : V01                                                                   */
/***********************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "FPEC_interface.h"
#include "FPEC_config.h"
#include "FPEC_private.h"


void FPEC_voidEraseAppArea(void)
{
    u8 Counter;
	
	for (Counter=4;Counter<128;Counter++)
	{
		FPEC_voidFlashPageErase(Counter);
	}

}
	
void FPEC_voidFlashPageErase(u8 Copy_u8PageNumber)
{
    /* Wait Busy Flag */
	while (GET_BIT(FPEC->SR,0) == 1);   /* Bit0 -> BSY: Busy */

	/* Check if FPEC is locked or not */
	if ( GET_BIT(FPEC->CR,7) == 1)   /* Bit7 -> LOCK: Lock */ 
	{
        /* Unlock Sequence */
		FPEC -> KEYR = KEY1;   /* Key1 */ 
		FPEC -> KEYR = KEY2;  /* Key2 */ 
	}
	
	/* Page Erase Operation */
	SET_BIT(FPEC->CR,1);   /* BIT1 -> PER: Page erase*/

	/* Write Page address */
	FPEC->AR = (u32)(Copy_u8PageNumber * 1024) + 0x08000000 ;

	/* Start operation */
	SET_BIT(FPEC->CR,6); /* BIT6 -> STRT: Start*/

	/* Wait Busy Flag */
	while (GET_BIT(FPEC->SR,0) == 1); /* Bit0 -> BSY: Busy */

	/* EOP */
	SET_BIT(FPEC->SR,5);  /* Bit5 -> EOP: End of operation Reset by writing a 1 */
	CLR_BIT(FPEC->CR,1);  /* Bit1 -> PER: Page erase */
}

void FPEC_voidFlashWrite(u32 Copy_u32Address, u16* Copy_u16Data, u8 Copy_u8Length)
{
    u8 Counter;
	volatile u16 Temp;

    /* Wait Busy Flag */
	while (GET_BIT(FPEC->SR,0) == 1);  /* Bit0 -> BSY: Busy */

	/* Check if FPEC is locked or not */
	if ( GET_BIT(FPEC->CR,7) == 1)   /* Bit7 -> LOCK: Lock */ 
	{
        /* Unlock Sequence */
		FPEC -> KEYR = KEY1;   /* Key1 */ 
		FPEC -> KEYR = KEY2;  /* Key2 */ 
	}
	
	for (Counter = 0; Counter< Copy_u8Length; Counter++)
	{
		/* Write Flash Programming */
		SET_BIT(FPEC->CR,0);  /* Bit0 -> PG: Programming */

		/* Half word operation */

		Temp = Copy_u16Data[Counter];   // Why? 
		*((volatile u16*)Copy_u32Address) = Copy_u16Data[Counter];
		Copy_u32Address += 2 ;   

		/* Wait Busy Flag */
		while (GET_BIT(FPEC->SR,0) == 1); /* Bit0 -> BSY: Busy */
	
		/* EOP */
		SET_BIT(FPEC->SR,5); /* Bit5 -> EOP: End of operation Reset by writing a 1 */
		CLR_BIT(FPEC->CR,0); /* Bit0 -> PG: Programming */
	}

}