/***********************************************************************************/
/* Author  : Abdellatif Maher                                                      */
/* Date    : 3 SEP 2021                                                           */
/* Version : V01                                                                   */
/***********************************************************************************/


#ifndef   TIMER2_INTERFACE_H
#define   TIMER2_INTERFACE_H



#define TIMER2_FILTER_CLOCK_DIVISION_X1     0
#define TIMER2_FILTER_CLOCK_DIVISION_X2     1
#define TIMER2_FILTER_CLOCK_DIVISION_X4     2


/* Auto Reload Buffer */

#define TIMER2_ARR_PRELOAD_DISABLE          0
#define TIMER2_ARR_PRELOAD_ENABLE           1

/* aligned Mode */

#define TIMER2_UP_ALIGNED_MODE				0
#define TIMER2_DOWN_ALIGNED_MODE		    0
#define TIMER2_CENTER_ALIGNED_MODE1_UP		0
#define TIMER2_CENTER_ALIGNED_MODE2_DOWN	0
#define TIMER2_CENTER_ALIGNED_MODE3_UPDOWN	0


/* Interrupts */
#define TIMER2_DISABLE_INTERRUPT            0
#define TIMER2_UPDATE_INTERRUPT             1
#define TIMER2_CC1_INTERRUPT                2
#define TIMER2_CC2_INTERRUPT                4
#define TIMER2_CC3_INTERRUPT                8
#define TIMER2_CC4_INTERRUPT                16
#define TIMER2_TRIGGER_INTERRUPT            64

/* Channel Configuration */

#define TIMER2_CHANNEL_OUTPUT               0
#define TIMER2_CHANNEL_INPUT                1
#define TIMER2_CHANNEL_INPUT_MAPPED         2
#define TIMER2_CHANNEL_INPUT_TRC            3

/* Output Channel Mode */

#define TIMER2_OC_FORZEN_MODE                    0
#define TIMER2_OC_SET_ON_COMPARE_MODE            1
#define TIMER2_OC_CLR_ON_COMPARE_MODE            2
#define TIMER2_OC_TOG_ON_COMPARE_MODE            3
#define TIMER2_OC_PWM_MODE1                      6
#define TIMER2_OC_PWM_MODE2                      7

/* Input Channel Prescaler */

#define TIMER2_IC_NO_PRESCALER                   0
#define TIMER2_IC_PRESCALER_BY_2                 1
#define TIMER2_IC_PRESCALER_BY_4                 2
#define TIMER2_IC_PRESCALER_BY_8                 3

/* Channel Output Polarity */


#define TIMER2_OC_POLARIT_ACTIVE_HIGH            0
#define TIMER2_OC_POLARIT_ACTIVE_LOW             1

/* Channel Input Polarity */
#define TIMER2_IC_POLARIT_RISING_EDGE            0
#define TIMER2_IC_POLARIT_FALLING_EDGE           1

typedef enum {
	UG,
	CC1G,
	CC2G,
	CC3G,
	CC4G,
	TG=6
}TIMER2_EVENTs;


void TIMER2_voidInit(void);
void TIMER2_voidEnable(void);
void TIMER2_voidDisable(void);
void TIMER2_voidChangeAlignedMode(u8 Copy_u8Mode);
void TIMER2_voidClearFlag(u8 Copy_u8Flag);
u8   TIMER2_u8GetFlag(u8 Copy_u8Flag);
void TIMER2_voidGenerateEvent(u8 Copy_u8Event);
void TIMER2_voidSetCounter(u16 Copy_u16Counter);
u16  TIMER2_u16GetCounter(void);
void TIMER2_voidSetPrescaler(u16 Copy_u16Prescaler);
u16  TIMER2_u16GetPrescaler(void);
void TIMER2_voidSetAutoreload(u16 Copy_u16Number);
u16  TIMER2_u16GetAutoreload(void);
void TIMER2_voidSetCC1(u16 Copy_u16Number);
u16  TIMER2_u16GetCC1(void);
void TIMER2_voidSetCC2(u16 Copy_u16Number);
u16  TIMER2_u16GetCC2(void);
void TIMER2_voidSetCC3(u16 Copy_u16Number);
u16  TIMER2_u16GetCC3(void);
void TIMER2_voidSetCC4(u16 Copy_u16Number);
u16  TIMER2_u16GetCC4(void);
void TIMER2_voidDisableInterrupt(u8 Copy_u8Interrupt);
void TIMER2_voidEnableInterrupt(u8 Copy_u8Interrupt);
void TIMER2_voidSetCallBack( void(*Copy_pvoidCallBack)(void) , u8 Copy_u8Interrupt);
void TIMER2_voidStartChannel1(u8 Copy_u8Configuration,u8 Copy_u8Mode,u8 Copy_u8Polarity);
void TIMER2_voidStartChannel2(u8 Copy_u8Configuration,u8 Copy_u8Mode,u8 Copy_u8Polarity);
void TIMER2_voidStartChannel3(u8 Copy_u8Configuration,u8 Copy_u8Mode,u8 Copy_u8Polarity);
void TIMER2_voidStartChannel4(u8 Copy_u8Configuration,u8 Copy_u8Mode,u8 Copy_u8Polarity);
void TIMER2_voidPWM( u8 Copy_u8Channel, u8 Copy_u8PWMMode, u8 Copy_u8OnTime);
void TIMER2_voidChannelDisable(u8 Copy_u8Channel);


#endif 