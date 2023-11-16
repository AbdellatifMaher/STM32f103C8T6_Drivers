/***********************************************************************************/
/* Author  : Abdellatif Maher                                                      */
/* Date    : 14 JUL 2021                                                           */
/* Version : V01                                                                   */
/***********************************************************************************/
#ifndef STK_PRIVATE_H
#define STK_PRIVATE_H

typedef struct {
	volatile u32 CTRL  ;
	volatile u32 LOAD  ;
	volatile u32 VALUE ;
	volatile u32 CALIB ;
}STK_type;

#define STK   ((volatile STK_type *)0xE000E010)     

#define STK_AHB_DIV_8    0
#define STK_AHB          1    

#define NULL             0

#endif