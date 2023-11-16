/***********************************************************************************/
/* Author  : Abdellatif Maher                                                      */
/* Date    : 2 JUL 2021                                                            */
/* Version : V01                                                                   */
/***********************************************************************************/

#ifndef  RCC_INTERFACE_H
#define  RCC_INTERFACE_H

/************************ Buses **************************/

#define RCC_AHB       0 
#define RCC_APB1      1
#define RCC_APB2      2

/*******************************************************/

/************** Number of peripheral ******************/
#define RCC_AFIO      0 /* APB2 */
#define RCC_GPIOA     2 /* APB2 */
#define RCC_GPIOB     3 /* APB2 */
#define RCC_GPIOC     4 /* APB2 */
#define RCC_TIM2      0
#define RCC_TIM3      1
#define RCC_TIM4      2
#define RCC_TIM5      3
#define RCC_TIM6      4 
#define RCC_TIM7      5
#define RCC_SPI1 	  12/* APB2 */
#define RCC_USART1 	  14/* APB2 */
/*****************************************************/


void RCC_voidInitSysClock(void);
void RCC_voidEnableClock(u8 Copy_u8BusId, u8 Copy_u8PerId);
void RCC_voidDisableClock(u8 Copy_u8BusId, u8 Copy_u8PerId);


#endif