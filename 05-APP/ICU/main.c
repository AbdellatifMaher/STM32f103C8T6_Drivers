/*
 * main.c
 *
 *  Created on: Sep 2, 2021
 *      Author: 8
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "TIMER1_interface.h"
#include "TIMER0_interface.h"
#include "EXTI_interface.h"
#include "CLCD_interface.h"
#include <util/delay.h>

u64 Period = 0;
u64 Duty = 0;

void ICU_voidSW(void)
{
	static u16 Counter = 0;
	Counter ++;
	if(Counter == 1)
	{
		TIMER1_voidSetCounter(0);
	}
	else if(Counter == 2)
	{
		Period = TIMER1_u16GetCounter();
		EXTI_voidSetSignalLatch(EXTI_FALLING_EDGE ,EXTI_LINE0);
	}
	else if(Counter == 3)
	{
		Duty = TIMER1_u16GetCounter();
		Duty = Duty - Period ;
	//	EXTI_voidDisableInterrupt(EXTI_LINE0);
		EXTI_voidSetSignalLatch(EXTI_RISING_EDGE ,EXTI_LINE0);
		Counter = 0;
	}

}




int main(void)
{
	EXTI_voidInit();
	EXTI_voidEnableInterrupt(EXTI_LINE0);
	EXTI_voidSetCallBack(ICU_voidSW ,EXTI_LINE0 );
	EXTI_voidEnableGlobalInterrupt();
	TIMER1_voidInit();
	TIMER0_voidInit();
	TIMER0_voidPWM(64);
	CLCD_voidInit();
	while(1)
	{


		while( Period == 0 && Duty == 0);

			CLCD_voidClear();
			CLCD_voidSetPosition(1,1);
			CLCD_voidSendNumber(Period);
			CLCD_voidSetPosition(2,1);
			CLCD_voidSendNumber(Duty);
		/*	Period = 0;
			Duty = 0;*/
			_delay_ms(1000);

	}
}
