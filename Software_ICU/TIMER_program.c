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

void TIMER1_voidSetTimerValue(uint16 Copy_uint16Value)
{
	TCNT1 = Copy_uint16Value ;
}

uint16 TIMER1_GetTimerReading(void)
{
  return TCNT1;
}
