/***********************************************************************************/
/* Author  : Abdellatif Maher                                                      */
/* Date    : 14 JUL 2021                                                           */
/* Version : V01                                                                   */
/***********************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"               

#include "STK_interface.h"
#include "STK_private.h"
#include "STK_config.h"


void (*STK_CallBack)(void)=NULL;
u8 GLO_u32STKPerVar = 0 ;

void MSTK_voidInit(void)
{
      STK->CTRL = 0x00000000 | (STK_CLK<<2) ;
}

void MSTK_voidSetBusyWait(u32 Copy_u32Ticks)
{
	/* Load ticks to load register */
	STK->LOAD = Copy_u32Ticks ; 
	
	/* Start Timer */
	SET_BIT( STK->CTRL , 0);
	
	/* Wait till flag is raised */
	while( !(GET_BIT( STK->CTRL , 16)));
	
	/* Stop Timer */
	CLR_BIT( STK->CTRL , 0);
	STK->LOAD = 0 ;
	STK->VALUE = 0;
}

void MSTK_voidSetIntervalSingle(u32 Copy_u32Ticks , void(*Copy_ptr)(void))
{
	/* Disable Timer */
	CLR_BIT(STK->CTRL,0);
	STK->VALUE = 0;
	
	/* Load ticks to load register */
		STK->LOAD = Copy_u32Ticks ;
	
	/* Start Timer */	
		SET_BIT( STK->CTRL , 0);
	
	/* Save CallBack */
		STK_CallBack = Copy_ptr ;
		
	/* Enable STK Interrupt */	
		SET_BIT( STK->CTRL , 1);
		
		GLO_u32STKPerVar = 0;
}
void MSTK_voidSetIntervalPeriodic(u32 Copy_u32Ticks , void(*Copy_ptr)(void))
{
	/* Load ticks to load register */
		STK->LOAD = Copy_u32Ticks ;
	
	/* Start Timer */	
		SET_BIT( STK->CTRL , 0);
	
	/* Save CallBack */
		STK_CallBack = Copy_ptr ;
		
	/* Enable STK Interrupt */	
		SET_BIT( STK->CTRL , 1);
		
	/* Set Mode to Periodic */ 	
		GLO_u32STKPerVar = 1;
}
void MSTK_voidStopInterval(void)
{
	/* Disable STK Interrupt */
	CLR_BIT( STK->CTRL , 1);
	
	/* Stop Timer */
	CLR_BIT( STK->CTRL , 0);	
	STK->LOAD = 0 ;
	STK->VALUE = 0;
	GLO_u32STKPerVar = 0;
}

u32 MSTK_u32GetElapsedTime(void)
{
	u32 LOC_u32Time = STK->LOAD - STK->VALUE; 
	return LOC_u32Time ;
}
u32 MSTK_u32GetRemainingTime(void)
{
	u32 LOC_u32Time = STK->VALUE ; 
	return LOC_u32Time ;
}

void SysTick_Handler(void)
{
	if(STK_CallBack != NULL)
	{
	u8 LOC_u8Temp = 0 ;
	if (GLO_u32STKPerVar == 0 )
	{
		/* Disable STK Interrupt */
	    CLR_BIT( STK->CTRL , 1);
	
		/* Stop Timer */
		CLR_BIT( STK->CTRL , 0);	
		STK->LOAD = 0 ;
		STK->VALUE = 0;
	}
	
	/* Callback notification */
	STK_CallBack();
	
	/* Clear interrupt flag */
	LOC_u8Temp = GET_BIT(STK->CTRL,16);
	}
}