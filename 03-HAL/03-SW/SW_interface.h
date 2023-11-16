/***********************************************************************************/
/* Author  : Abdellatif Maher                                                      */
/* Date    : 15 JUL 2021                                                           */
/* Version : V01                                                                   */
/***********************************************************************************/


#ifndef SW_INTERFACE_H_
#define SW_INTERFACE_H_

#define SW_PULL_DOWN  0
#define SW_PULL_UP    1
#define SW_FLOATING   2

typedef struct
{
	u8 Port      ;
	u8 Pin       ;
	u8 State     ;
}SW_Type;

void SW_voidInit    ( SW_Type SW_Configuration);
u8   SW_u8GetPressed( SW_Type SW_Configuration);

#endif