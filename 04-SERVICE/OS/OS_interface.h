/***********************************************************************************/
/* Author  : Abdellatif Maher                                                      */
/* Date    : 14 AUG 2021                                                           */
/* Version : V01                                                                   */
/***********************************************************************************/
#ifndef OS_INTERFACE_H
#define OS_INTERFACE_H

void OS_voidCreateTask(u8 Copy_u8ID , u16 Copy_u16Priodicity , void (*ptr) (void), u16 Copy_u16FirstDelay);
void OS_voidStart(void);
#endif