/***********************************************************************************/
/* Author  : Abdellatif Maher                                                      */
/* Date    : 1 JUL 2021                                                            */
/* Version : V01                                                                   */
/***********************************************************************************/

#ifndef  BIT_MATH_H
#define  BIT_MATH_H

#define SET_BIT(VAR,BIT) (VAR |= (1<<BIT)) 

#define CLR_BIT(VAR,BIT) (VAR &= (~(1<<BIT)))
 
#define TOG_BIT(VAR,BIT) (VAR ^= (1<<BIT))

#define GET_BIT(VAR,BIT) ((VAR >> (BIT))&1)


#endif
 