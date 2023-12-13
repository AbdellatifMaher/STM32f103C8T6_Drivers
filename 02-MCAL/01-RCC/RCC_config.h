/***********************************************************************************/
/* Author  : Abdellatif Maher                                                      */
/* Date    : 2 JUL 2021                                                            */
/* Version : V01                                                                   */
/***********************************************************************************/

#ifndef  RCC_CONFIG_H
#define  RCC_CONFIG_H

/* Options:    RCC_HSE_CRYSTAL
               RCC_HSE_RC
               RCC_HSI
               RCC_PLL			   */
#define RCC_CLOCK_TYPE    RCC_HSE_CRYSTAL


/* Options:     RCC_PLL_IN_HSI_DIV_2
                RCC_PLL_IN_HSE_CRYSTAL_DIV_2  
				RCC_PLL_IN_HSE_CRYSTAL        
				RCC_PLL_IN_HSE_RC_DIV_2       
				RCC_PLL_IN_HSE_RC       */
				
/* Note: Select value only if you have PLL as input clock source */
#if RCC_CLOCK_TYPE == RCC_PLL
#define RCC_PLL_INPUT     RCC_PLL_IN_HSE_CRYSTAL_DIV_2
#endif


/* Options: 2 to 16 */
/* Note: Select value only if you have PLL as input clock source */
#if RCC_CLOCK_TYPE == RCC_PLL
#define RCC_PLL_MUL_VAL   4
#endif

/* Options:    RCC_USB_DIV_1_5
               RCC_USB_NO_DIV  */
#define RCC_USB_PRE    RCC_USB_NO_DIV

/* Options:     RCC_HCLK_NO_DIV
                RCC_HCLK_DIV_2	 
				RCC_HCLK_DIV_4  
				RCC_HCLK_DIV_8  
				RCC_HCLK_DIV_16 */

#define RCC_APB1_PRE      RCC_HCLK_NO_DIV             /* Max Freq = 36M Hz */
#define RCC_APB2_PRE      RCC_HCLK_NO_DIV


/* Options:     RCC_SYSCLK_NO_DIV   
                RCC_SYSCLK_DIV_2     
				RCC_SYSCLK_DIV_4     
				RCC_SYSCLK_DIV_8     
				RCC_SYSCLK_DIV_16    
				RCC_SYSCLK_DIV_64   
				RCC_SYSCLK_DIV_128  
				RCC_SYSCLK_DIV_256  
				RCC_SYSCLK_DIV_512	*/

#define RCC_AHB_PRE      RCC_SYSCLK_NO_DIV 

/* Options:     RCC_PCLK2_DIV_2 
                RCC_PCLK2_DIV_4  
				RCC_PCLK2_DIV_6  
				RCC_PCLK2_DIV_8  */

#define RCC_ADC_PRE      RCC_PCLK2_DIV_2


#endif