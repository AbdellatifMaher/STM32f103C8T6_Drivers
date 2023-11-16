/****************************************************************/
/* Author    : Abdellatif Maher                                 */
/* Date      : 12 SEP 2021                                      */
/* Version   : V01                                              */
/****************************************************************/
#ifndef ESP_INTERFACE_H
#define ESP_INTERFACE_H


#define ESP_TEST	         		 (u8*)"AT\r\n"

#define ESP_SW_RESTART       		 (u8*)"AT+RST\r\n"

#define ESP_ECHO_TURN_OFF    		 (u8*)"ATE0\r\n"

#define ESP_ECHO_TURN_ON     	     (u8*)"ATE1\r\n"

#define ESP_FIRST_MODE_CONFIG		 (u8*)"AT+CWMODE=1\r\n"

#define ESP_ROUTER_CONNECT(X,Y)      	(u8*)"AT+CWJAP_CUR="X","Y"\r\n"

#define ESP_SITE_CONNECT(X)       	 	(u8*)"AT+CIPSTART=\"TCP\","X",80\r\n"

#define ESP_SEND_DATA(X)         	 	(u8*)"AT+CIPSEND="#X"\r\n"

#define ESP_DATA(X)                  	(u8*)"GET "X"\r\n"

/*define receiving time out for each command that if it exceeded it means no more data*/
/*It varies depending on the router and server and also Clock freq, you'll need to try it*/
#define ESP_ECHO_TIMEOUT		100
#define ESP_MODE_TIMEOUT		150
#define ESP_ROUTER_TIMEOUT		35000
#define ESP_SERVER_TIMEOUT		30000
#define ESP_PREREQUEST_TIMEOUT	200
#define ESP_REQUEST_TIMEOUT		29000

void ESP_voidInit(void);

void ESP_voidSendCommand(u8 * Copy_u8Command , u32 Copy_u32Timeout);

u8 ESP_u8GetData(u8 * Copy_ptrLink);

u8 ESP_u8ValidateCmd(u32 Copy_u32Timeout);



#endif
