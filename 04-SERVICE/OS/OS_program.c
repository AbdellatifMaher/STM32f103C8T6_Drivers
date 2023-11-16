/***********************************************************************************/
/* Author  : Abdellatif Maher                                                      */
/* Date    : 14 AUG 2021                                                           */
/* Version : V01                                                                   */
/***********************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"               

#include "STK_interface.h"

#include "OS_interface.h"
#include "OS_private.h"
#include "OS_config.h"

#define NULL (void *)0

static Task OS_Tasks[NUMBER_OF_TASKS] = {NULL};  

void OS_voidCreateTask(u8 Copy_u8ID , u16 Copy_u16Priodicity , void (*ptr) (void), u16 Copy_u16FirstDelay)
{
	OS_Tasks[Copy_u8ID].priodicity = Copy_u16Priodicity;
	OS_Tasks[Copy_u8ID].Fptr = ptr;
	OS_Tasks[Copy_u8ID].FirstDelay = Copy_u16FirstDelay * SCHEDULAR_TICK;
}
void OS_voidStart(void)
{
	MSTK_voidInit();
	MSTK_voidSetIntervalPeriodic(SCHEDULAR_TICK,Schedular);
}
/*
volatile u16 TickCounts = 0;
void Schedular(void)
{
	for(u8 i =0 ; i< NUMBER_OF_TASKS ; i++)
	{
		if(TickCounts %OS_Tasks[i].priodicity == 0 )
		{
			OS_Tasks[i].Fptr();
		}
	}
	TickCounts++;
} */ 

static void Schedular (void)
{
	for(u8 i = 0; i < NUMBER_OF_TASKS ; i++)
	{
		if(OS_Tasks[i].FirstDelay == 0)
		{
			OS_Tasks[i].Fptr();
			OS_Tasks[i].FirstDelay = OS_Tasks[i].priodicity -1;
		}
		else 
		{
			OS_Tasks[i].FirstDelay--;
		}
	}
	
}