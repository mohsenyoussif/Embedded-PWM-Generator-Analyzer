/***************************************************/
/***************************************************/
/***********   Author: Mohsen Youssif  **************/
/***********   layer:  MCAL            **************/
/***********   SWC: TIMER        **************/
/***********   Version: 1.00          **************/
/***************************************************/
/***************************************************/

#ifndef  TIMER_INTERFACE_H
#define  TIMER_INTERFACE_H


void TIMER0_voidInit(void);

uint8 TIMER0_uint8setcallBack(void*copy_pvCallBackFunc(void));

void TIMER1_voidInit(void);

void TIMER1_voidSetTimerValue(uint16 Copy_uint16Value);
uint16 TIMER1_GetTimerReading(void);
#endif
