/***********************************************************************************/
/* Author  : Abdellatif Maher                                                      */
/* Date    : 2 JUL 2021                                                            */
/* Version : V01                                                                   */
/***********************************************************************************/

#ifndef  RCC_PRIVATE_H
#define  RCC_PRIVATE_H

/************** Register Definitions *******************/
 #define RCC_CR                     *((u32*)0x40021000)
 #define RCC_CFGR                   *((u32*)0x40021004)
 #define RCC_CIR                    *((u32*)0x40021008)
 #define RCC_APB2RSTR               *((u32*)0x4002100C)
 #define RCC_APB1RSTR               *((u32*)0x40021010)
 #define RCC_AHBENR                 *((u32*)0x40021014)
 #define RCC_APB2ENR                *((u32*)0x40021018)
 #define RCC_APB1ENR                *((u32*)0x4002101C)
 #define RCC_BDCR                   *((u32*)0x40021020)
 #define RCC_CSR                    *((u32*)0x40021024)
 
/*******************************************************/
/* Clock Types */
#define RCC_HSE_CRYSTAL      0
#define RCC_HSE_RC           1
#define RCC_HSI              2
#define RCC_PLL              3

/* PLL Options */
#define RCC_PLL_IN_HSI_DIV_2          0
#define RCC_PLL_IN_HSE_CRYSTAL_DIV_2  1
#define RCC_PLL_IN_HSE_CRYSTAL        2
#define RCC_PLL_IN_HSE_RC_DIV_2       3
#define RCC_PLL_IN_HSE_RC             4

/* USB prescaler */ 

#define RCC_USB_DIV_1_5     0
#define RCC_USB_NO_DIV      1

/* APB (high,low)-speed prescaler (APB1,APB2) */ 

#define RCC_HCLK_NO_DIV    0
#define RCC_HCLK_DIV_2	   4
#define RCC_HCLK_DIV_4     5
#define RCC_HCLK_DIV_8     6
#define RCC_HCLK_DIV_16    7

/* AHB prescaler */ 

#define RCC_SYSCLK_NO_DIV     0
#define RCC_SYSCLK_DIV_2      8
#define RCC_SYSCLK_DIV_4      9
#define RCC_SYSCLK_DIV_8      10
#define RCC_SYSCLK_DIV_16     11
#define RCC_SYSCLK_DIV_64     12
#define RCC_SYSCLK_DIV_128    13
#define RCC_SYSCLK_DIV_256    14
#define RCC_SYSCLK_DIV_512	  15


/* ADC prescaler */ 
#define RCC_PCLK2_DIV_2  0
#define RCC_PCLK2_DIV_4  1
#define RCC_PCLK2_DIV_6  2
#define RCC_PCLK2_DIV_8  3

#endif