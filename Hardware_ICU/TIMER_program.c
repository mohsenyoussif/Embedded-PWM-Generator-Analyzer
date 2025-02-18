/***************************************************/
/***************************************************/
/***********   Author: Mohsen Youssif  **************/
/***********   layer:  MCAL            **************/
/***********   SWC: TIMER        **************/
/***********   Version: 1.00          **************/
/***************************************************/
/***************************************************/

#include "Platform_Types.h"
#include "BIT_MATH.h"

#include "TIMER_interface.h"
#include "TIMER_register.h"
#include "TIMER_private.h"
#include "TIMER_config.h"

static void (*TIMER0_pvCallBackFUNC)(void) = NULL ;

static void (*ICU_pvCallBackFUNC)(void) = NULL ;

void TIMER0_voidInit(void)
{
	/*choose Fast PWM mode */
	SET_BIT(TCCR0,TCCR0_WGM00);
	SET_BIT(TCCR0,TCCR0_WGM01);
	
	/*Clear OC0 on compare match, set OC0 at TOP (non- inverted mode) */
		CLR_BIT(TCCR0,TCCR0_COM00);
		SET_BIT(TCCR0,TCCR0_COM01);

	/*Define the timer clock , prescaler /8 */
	CLR_BIT(TCCR0,TCCR0_CS00);
	SET_BIT(TCCR0,TCCR0_CS01);
	CLR_BIT(TCCR0,TCCR0_CS02);
	
	/*SET the compare match value to 64 for duty cycle 25% */
	OCR0=COMPAREVALUE;
}

void TIMER0_voidSetCompMatchValue(uint8 Copy_uint8Value)
{
	OCR0 = Copy_uint8Value ;
}

void TIMER1_voidInit(void)
{
	/*Initialize at normal Mode , prescaler /8 */
	CLR_BIT(TCCR1B,TCCR1B_CS10);
	SET_BIT(TCCR1B,TCCR1B_CS11);
	CLR_BIT(TCCR1B,TCCR1B_CS12);
}

uint8 TIMER0_uint8setcallBack(void(*copy_pvCallBackFunc)(void))
{
	 uint8 Local_uint8ErrorStatus =OK;
	 if(copy_pvCallBackFunc !=NULL)
	 {
		 TIMER0_pvCallBackFUNC=copy_pvCallBackFunc;
	 }
     else{
		 Local_uint8ErrorStatus =NULL_POINTER ;
	 }

	return Local_uint8ErrorStatus ;
}

void TIMER1_voidSetTimerValue(uint16 Copy_uint16Value)
{
	TCNT1 = Copy_uint16Value ;
}

uint16 TIMER1_GetTimerReading(void)
{
  return TCNT1;
}

void ICU_voidInit(void)
{
	 /*Set trigger source to rising edge initially*/
	  SET_BIT(TCCR1B,TCCR1B_ICES1);

	/*Input Capture Interrupt Enable*/
	  SET_BIT(TIMSK,TIMSK_TICIE1);
}

uint8 ICU_uint8SetTriggerEdge(uint8 Copy_uint8Edge)
{
	uint8 Local_uint8ErrorState = OK ;
   if(Copy_uint8Edge == ICU_RISING_EDGE)
   {
	   SET_BIT(TCCR1B,TCCR1B_ICES1);
   }else if(Copy_uint8Edge == ICU_FAILING_EDGE)
   {
	   CLR_BIT(TCCR1B,TCCR1B_ICES1);
   }else
   {
	   Local_uint8ErrorState = NOK ;
   }
   return Local_uint8ErrorState ;
}

void ICU_voidEnableInturrept(void)
{
	SET_BIT(TIMSK,TIMSK_TICIE1);
}

void ICU_voidDisableInturrept(void)
{
	CLR_BIT(TIMSK,TIMSK_TICIE1);
}

uint16 ICU_uint16ReadInputCapture(void)
{
	return ICR1;
}

uint8 ICU_uint8SetCallBack(void (*Copy_pvCallBackFUNC)(void))
{
	uint8 Local_uint8ErrorState = OK ;

	if(Copy_pvCallBackFUNC !=NULL)
	{
       ICU_pvCallBackFUNC = Copy_pvCallBackFUNC ;
	}else
	{
		Local_uint8ErrorState = NULL_POINTER ;
	}

	return Local_uint8ErrorState ;
}

void __vector_10(void)__attribute__((signal));
void __vector_10(void)
{
	if(TIMER0_pvCallBackFUNC !=NULL)
	{
		TIMER0_pvCallBackFUNC();
	}
}

/*ICU ISR*/
void __vector_6(void)__attribute__((signal));
void __vector_6(void)
{
	if(ICU_pvCallBackFUNC !=NULL)
	{
		ICU_pvCallBackFUNC();
	}
}
