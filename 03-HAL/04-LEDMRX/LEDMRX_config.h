/***********************************************************************************/
/* Author  : Abdellatif Maher                                                      */
/* Date    : 19 JUL 2021                                                           */
/* Version : V01                                                                   */
/***********************************************************************************/

#ifndef LEDMRX_CONFIG_H_
#define LEDMRX_CONFIG_H_

u8 GLO_arrRowPins[8] = {PIN0,PIN1,PIN2,PIN3,PIN4,PIN5,PIN6,PIN7};
u8 GLO_arrColPins[8] = {PIN0,PIN1,PIN5,PIN6,PIN7,PIN8,PIN9,PIN10};

u8 GLO_arrRowPotrs[8] = {GPIOA,GPIOA,GPIOA,GPIOA,GPIOA,GPIOA,GPIOA,GPIOA};
u8 GLO_arrColPotrs[8] = {GPIOB,GPIOB,GPIOB,GPIOB,GPIOB,GPIOB,GPIOB,GPIOB};

#endif