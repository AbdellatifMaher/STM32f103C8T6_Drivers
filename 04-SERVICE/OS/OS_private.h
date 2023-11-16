/* Author  : Abdellatif Maher                                                      */
/* Date    : 14 AUG 2021                                                           */
/* Version : V01                                                                   */
/***********************************************************************************/
#ifndef OS_PRIVATE_H
#define OS_PRIVATE_H

typedef struct {
	u16 priodicity ;
	void (*Fptr) (void);
	u16 FirstDelay ;
}Task;

#define SCHEDULAR_TICK   1000

static void Schedular (void);
#endif