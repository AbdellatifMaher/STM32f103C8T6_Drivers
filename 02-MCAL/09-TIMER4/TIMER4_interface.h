/***********************************************************************************/
/* Author  : Abdellatif Maher                                                      */
/* Date    : 3 SEP 2021                                                           */
/* Version : V01                                                                   */
/***********************************************************************************/


#ifndef   TIMER4_INTERFACE_H
#define   TIMER4_INTERFACE_H



#define TIMER4_FILTER_CLOCK_DIVISION_X1     0
#define TIMER4_FILTER_CLOCK_DIVISION_X2     1
#define TIMER4_FILTER_CLOCK_DIVISION_X4     2


/* Auto Reload Buffer */

#define TIMER4_ARR_PRELOAD_DISABLE          0
#define TIMER4_ARR_PRELOAD_ENABLE           1

/* aligned Mode */

#define TIMER4_UP_ALIGNED_MODE				0
#define TIMER4_DOWN_ALIGNED_MODE		    0
#define TIMER4_CENTER_ALIGNED_MODE1_UP		0
#define TIMER4_CENTER_ALIGNED_MODE2_DOWN	0
#define TIMER4_CENTER_ALIGNED_MODE3_UPDOWN	0


/* Interrupts */
#define TIMER4_DISABLE_INTERRUPT            0
#define TIMER4_UPDATE_INTERRUPT             1
#define TIMER4_CC1_INTERRUPT                2
#define TIMER4_CC2_INTERRUPT                4
#define TIMER4_CC3_INTERRUPT                8
#define TIMER4_CC4_INTERRUPT                16
#define TIMER4_TRIGGER_INTERRUPT            64

/* Channel Configuration */

#define TIMER4_CHANNEL_OUTPUT               0
#define TIMER4_CHANNEL_INPUT                1
#define TIMER4_CHANNEL_INPUT_MAPPED         2
#define TIMER4_CHANNEL_INPUT_TRC            3

/* Output Channel Mode */

#define TIMER4_OC_FORZEN_MODE                    0
#define TIMER4_OC_SET_ON_COMPARE_MODE            1
#define TIMER4_OC_CLR_ON_COMPARE_MODE            2
#define TIMER4_OC_TOG_ON_COMPARE_MODE            3
#define TIMER4_OC_PWM_MODE1                      6
#define TIMER4_OC_PWM_MODE2                      7

/* Input Channel Prescaler */

#define TIMER4_IC_NO_PRESCALER                   0
#define TIMER4_IC_PRESCALER_BY_2                 1
#define TIMER4_IC_PRESCALER_BY_4                 2
#define TIMER4_IC_PRESCALER_BY_8                 3

/* Channel Output Polarity */


#define TIMER4_OC_POLARIT_ACTIVE_HIGH            0
#define TIMER4_OC_POLARIT_ACTIVE_LOW             1

/* Channel Input Polarity */
#define TIMER4_IC_POLARIT_RISING_EDGE            0
#define TIMER4_IC_POLARIT_FALLING_EDGE           1

typedef enum {
	UG4,
	CC1G4,
	CC2G4,
	CC3G4,
	CC4G4,
	TG4=6
}TIMER4_EVENTs;

typedef enum {
	UIF4,
	CC1IF4,
	CC2IF4,
	CC3IF4,
	CC4IF4,
	TIF4=6,
	CC1OF4=9,
	CC2OF4,
	CC3OF4,
	CC4OF4,
}TIMER4_FLAGS;

void TIMER4_voidInit2(void);
void TIMER4_voidInit(void);
void TIMER4_voidEnable(void);
void TIMER4_voidDisable(void);
void TIMER4_voidChangeAlignedMode(u8 Copy_u8Mode);
void TIMER4_voidClearFlag(u8 Copy_u8Flag);
u8   TIMER4_u8GetFlag(u8 Copy_u8Flag);
void TIMER4_voidGenerateEvent(u8 Copy_u8Event);
void TIMER4_voidSetCounter(u16 Copy_u16Counter);
u16  TIMER4_u16GetCounter(void);
void TIMER4_voidSetPrescaler(u16 Copy_u16Prescaler);
u16  TIMER4_u16GetPrescaler(void);
void TIMER4_voidSetAutoreload(u16 Copy_u16Number);
u16  TIMER4_u16GetAutoreload(void);
void TIMER4_voidSetCC1(u16 Copy_u16Number);
u16  TIMER4_u16GetCC1(void);
void TIMER4_voidSetCC2(u16 Copy_u16Number);
u16  TIMER4_u16GetCC2(void);
void TIMER4_voidSetCC3(u16 Copy_u16Number);
u16  TIMER4_u16GetCC3(void);
void TIMER4_voidSetCC4(u16 Copy_u16Number);
u16  TIMER4_u16GetCC4(void);
void TIMER4_voidDisableInterrupt(u8 Copy_u8Interrupt);
void TIMER4_voidEnableInterrupt(u8 Copy_u8Interrupt);
void TIMER4_voidSetCallBack( void(*Copy_pvoidCallBack)(void) , u8 Copy_u8Interrupt);
void TIMER4_voidStartChannel1(u8 Copy_u8Configuration,u8 Copy_u8Mode,u8 Copy_u8Polarity);
void TIMER4_voidStartChannel2(u8 Copy_u8Configuration,u8 Copy_u8Mode,u8 Copy_u8Polarity);
void TIMER4_voidStartChannel3(u8 Copy_u8Configuration,u8 Copy_u8Mode,u8 Copy_u8Polarity);
void TIMER4_voidStartChannel4(u8 Copy_u8Configuration,u8 Copy_u8Mode,u8 Copy_u8Polarity);
void TIMER4_voidPWM( u8 Copy_u8Channel, u8 Copy_u8PWMMode, u8 Copy_u8OnTime);
void TIMER4_voidChannelDisable(u8 Copy_u8Channel);


#endif 
