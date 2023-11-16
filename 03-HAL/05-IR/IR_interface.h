/***********************************************************************************/
/* Author  : Abdellatif Maher                                                      */
/* Date    : 28 JUL 2021                                                           */
/* Version : V01                                                                   */
/***********************************************************************************/
#ifndef IR_INTERFACE_H
#define IR_INTERFACE_H

extern volatile u8   GLO_u8Data  ; 

extern void (*GLO_ptrFunc)(void); 

void  IR_voidInit(void);

#endif