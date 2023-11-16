/***********************************************************************************/
/* Author  : Abdellatif Maher                                                      */
/* Date    : 6 JUL 2021                                                            */
/* Version : V01                                                                   */
/***********************************************************************************/



#ifndef SSD_INTERFACE_H_
#define SSD_INTERFACE_H_

/****************** Seven Segment Type ***************/
#define SSD_COMMON_CATHODE  0
#define SSD_COMMON_ANODE    1

/****************** DOT State **********************/
#define SSD_CLOSE_DOT 0
#define SSD_OPEN_DOT  1

/*********** Seven Segment Structure *************/
typedef struct{
	u8 Type;
	u8 DataPort;
	u8 FirstPin;
	u8 EnablePort;
	u8 EnablePin;
	u8 DotState ;
}SSD_Type;

void SSD_voidSendNumber( SSD_Type Copy_structConfig , u8 Copy_u8Number );
void SSD_voidEnable    ( SSD_Type Copy_structConfig );
void SSD_voidDisable   ( SSD_Type Copy_structConfig );

#endif