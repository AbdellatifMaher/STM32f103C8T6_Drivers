/***********************************************************************************/
/* Author  : Abdellatif Maher                                                      */
/* Date    : 22 AUG 2022                                                           */
/* Version : V01                                                                   */
/***********************************************************************************/

#ifndef  FPEC_PRIVATE_H
#define  FPEC_PRIVATE_H

typedef struct
{
	volatile u32 ACR;
	volatile u32 KEYR;
	volatile u32 OPTKEYR;
	volatile u32 SR;
	volatile u32 CR;
	volatile u32 AR;
	volatile u32 RESERVED;
	volatile u32 OBR;
	volatile u32 WRPR;
}FPEC_t;

#define FPEC ((FPEC_t*)0x40022000)

#define     KEY1    0x45670123
#define     KEY2    0xCDEF89AB

#endif