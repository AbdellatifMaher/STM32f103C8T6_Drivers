/***********************************************************************************/
/* Author  : Abdellatif Maher                                                      */
/* Date    : 3 SEP 2021                                                           */
/* Version : V01                                                                   */
/***********************************************************************************/


#ifndef    TIMER2_PRIVATE_H
#define    TIMER2_PRIVATE_H
typedef struct {
	u32 CR1 ;
	u32 CR2 ;
	u32 SMCR;
	u32 DIER;
	u32 SR  ;
	u32 EGR ;
	u32 CCMR1;	
	u32 CCMR2;
	u32 CCER;
	u32 CNT;
	u32 PSC;
	u32 ARR;
	u32 RCR;
	u32 CCR1;
	u32 CCR2;
	u32 CCR3;
	u32 CCR4;
	u32 BDTR;
	u32 DCR;
	u32 DMAR;
}TIMER2;

#define     TIM2    ((volatile TIMER2*)0x40000000)

typedef enum {
	UIF,
	CC1IF,
	CC2IF,
	CC3IF,
	CC4IF,
	TIF=6,
	CC1OF=9,
	CC2OF,
	CC3OF,
	CC4OF,
}TIMER2_FLAGS;

#endif 
