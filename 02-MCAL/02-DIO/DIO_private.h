/***********************************************************************************/
/* Author  : Abdellatif Maher                                                      */
/* Date    : 5 JUL 2021                                                            */
/* Version : V01                                                                   */
/***********************************************************************************/

#ifndef  DIO_PRIVATE_H
#define  DIO_PRIVATE_H

/********** PORTS BASE ADDRESS *************/

#define GPIOA_BASE_ADDRESS     0x40010800
#define GPIOB_BASE_ADDRESS     0x40010C00
#define GPIOC_BASE_ADDRESS     0x40011000

/*********** PORTA REGISTERS ***************/
 #define GPIOA_CRL    *((u32 *)(GPIOA_BASE_ADDRESS + 0x00000000))
 #define GPIOA_CRH    *((u32 *)(GPIOA_BASE_ADDRESS + 0x00000004))
 #define GPIOA_IDR    *((u32 *)(GPIOA_BASE_ADDRESS + 0x00000008))
 #define GPIOA_ODR    *((u32 *)(GPIOA_BASE_ADDRESS + 0x0000000C))
 #define GPIOA_BSRR   *((u32 *)(GPIOA_BASE_ADDRESS + 0x00000010))
 #define GPIOA_BRR    *((u32 *)(GPIOA_BASE_ADDRESS + 0x00000014))
 #define GPIOA_LCKR   *((u32 *)(GPIOA_BASE_ADDRESS + 0x00000018))

/*********** PORTB REGISTERS ***************/
 #define GPIOB_CRL    *((u32 *)(GPIOB_BASE_ADDRESS + 0x00000000))
 #define GPIOB_CRH    *((u32 *)(GPIOB_BASE_ADDRESS + 0x00000004))
 #define GPIOB_IDR    *((u32 *)(GPIOB_BASE_ADDRESS + 0x00000008))
 #define GPIOB_ODR    *((u32 *)(GPIOB_BASE_ADDRESS + 0x0000000C))
 #define GPIOB_BSRR   *((u32 *)(GPIOB_BASE_ADDRESS + 0x00000010))
 #define GPIOB_BRR    *((u32 *)(GPIOB_BASE_ADDRESS + 0x00000014))
 #define GPIOB_LCKR   *((u32 *)(GPIOB_BASE_ADDRESS + 0x00000018))
 
 /*********** PORTC REGISTERS ***************/
 #define GPIOC_CRL    *((u32 *)(GPIOC_BASE_ADDRESS + 0x00000000))
 #define GPIOC_CRH    *((u32 *)(GPIOC_BASE_ADDRESS + 0x00000004))
 #define GPIOC_IDR    *((u32 *)(GPIOC_BASE_ADDRESS + 0x00000008))
 #define GPIOC_ODR    *((u32 *)(GPIOC_BASE_ADDRESS + 0x0000000C))
 #define GPIOC_BSRR   *((u32 *)(GPIOC_BASE_ADDRESS + 0x00000010))
 #define GPIOC_BRR    *((u32 *)(GPIOC_BASE_ADDRESS + 0x00000014))
 #define GPIOC_LCKR   *((u32 *)(GPIOC_BASE_ADDRESS + 0x00000018))

#endif