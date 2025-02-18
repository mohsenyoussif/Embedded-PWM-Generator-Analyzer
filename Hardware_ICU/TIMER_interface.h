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


/**/
#define ICU_RISING_EDGE           1
#define ICU_FAILING_EDGE          0
void TIMER0_voidInit(void);

uint8 TIMER0_uint8setcallBack(void(*copy_pvCallBackFunc)(void));
void TIMER0_voidSetCompMatchValue(uint8 Copy_uint8Value);

void TIMER1_voidInit(void);
void TIMER1_voidSetTimerValue(uint16 Copy_uint16Value);
uint16 TIMER1_GetTimerReading(void);

void ICU_voidInit(void);
uint8 ICU_uint8SetTriggerEdge(uint8 Copy_uint8Edge);
void ICU_voidEnableInturrept(void);
void ICU_voidDisableInturrept(void);
uint8 ICU_uint8SetCallBack(void (*Copy_pvCallBackFUNC)(void));
uint16 ICU_uint16ReadInputCapture(void);
#endif
