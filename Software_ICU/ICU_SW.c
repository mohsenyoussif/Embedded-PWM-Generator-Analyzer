

#include "Platform_Types.h"

#include "TIMER_interface.h"
#include "EXTI_interface.h"
#include "ICU_SW.h"

uint16 PeriodTime_Ticks = 0 ;
uint16 ON_Ticks = 0 ;
void ICU_SW(void)
{
	/*Initiate counter to know iam in which state of 3 states*/
	static uint8 Local_uint8Counter = 0 ;

	Local_uint8Counter++;
	if(Local_uint8Counter == 1) /*First rising edge*/
	{
	/*Clear the timer @ the beginning*/
	TIMER1_voidSetTimerValue(0);
	}
	else if(Local_uint8Counter == 2) /*Second  rising edge*/
	{
		/*Read Timer value to get the period time */
		PeriodTime_Ticks= TIMER1_GetTimerReading();
		/*Change Trigger to Failing Edge*/
		EXTI_uint8Int0SetSenseControl(EXTI_FALLING_EDGE_SENCE_CONTROL);

	}
	else if(Local_uint8Counter == 3)
	{
		ON_Ticks = TIMER1_GetTimerReading();
		ON_Ticks -= PeriodTime_Ticks ;
		/*Disable INT0 */
	 	EXTI_uint8Disable(INT0);

	}


}

