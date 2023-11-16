/***********************************************************************************/
/* Author  : Abdellatif Maher                                                      */
/* Date    : 28 JUL 2021                                                           */
/* Version : V01                                                                   */
/***********************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"               

#include "DIO_interface.h"
#include "NVIC_interface.h"
#include "EXTI_interface.h"
#include "STK_interface.h"

#include "IR_interface.h"
#include "IR_private.h"
#include "IR_config.h"

volatile u8   GLO_u8StartFlag       = 0;
volatile u32  GLO_u32FrameData[50]  = {0};
volatile u8   GLO_u8EdgeCounter     = 0;
volatile u8   GLO_u8Data            = 0;

void (*GLO_ptrFunc)(void); 


void  IR_voidInit(void)
{
	/* IO Pins Initialization */
	MGPIO_VidSetPinDirection(IR_PORT,IR_EXTI_LINE,INPUT_FLOATING);
	
	
	/* EXTI Initializtion */
	MEXTI_voidSetCallBack(IR_EXTI_LINE , GetFrame )
	MEXTI_voidSetSignalLatch(IR_EXTI_LINE,FALLING);
	switch(IR_PORT)
	{
		case GPIOA : MAFIO_voidSetEXTIConfiguration(IR_EXTI_LINE,0); break;
		case GPIOB : MAFIO_voidSetEXTIConfiguration(IR_EXTI_LINE,1);  break;
		case GPIOC : MAFIO_voidSetEXTIConfiguration(IR_EXTI_LINE,2); break;
	}
	
	/* Enable EXTI from NVIC */
	if(IR_EXTI_LINE < 5)
	{
			MNVIC_voidEnableInterrupt((IR_EXTI_LINE + 6));

	}
	else if(IR_EXTI_LINE < 10)
	{
		MNVIC_voidEnableInterrupt(23);
	}
	else 
	{
		MNVIC_voidEnableInterrupt(40);
	}
}


void TakeAction(void)
{
	u8 LOC_u8Counter;
	GLO_u8Data = 0;

	if ( (GLO_u32FrameData[0] >= 10000) && (GLO_u32FrameData[0] <= 14000) )
	{
		for (LOC_u8Counter=0;LOC_u8Counter <8;LOC_u8Counter++)
		{
			if (  (GLO_u32FrameData[17+LOC_u8Counter] >= 2000) && (GLO_u32FrameData[17+LOC_u8Counter] <=2300) )
			{
				SET_BIT(GLO_u8Data,LOC_u8Counter);
			}

			else
			{
				CLR_BIT(GLO_u8Data,LOC_u8Counter);
			}
		}
		
		GLO_ptrFunc();
	}

	else
	{
		/* Invalid Frame */
	}
	GLO_u8StartFlag     = 0;
	GLO_u32FrameData[0] = 0;
	GLO_u8EdgeCounter   = 0;
}
void GetFrame(void)
{
	if (GLO_u8StartFlag == 0)
	{
		/* Start Timer */
		MSTK_voidSetIntervalSingle(500000,TakeAction);
		GLO_u8StartFlag = 1;
	}

	else
	{
		GLO_u32FrameData[GLO_u8EdgeCounter] = MSTK_u32GetElapsedTime();
		MSTK_voidSetIntervalSingle(500000,TakeAction);
		GLO_u8EdgeCounter++;
	}
}