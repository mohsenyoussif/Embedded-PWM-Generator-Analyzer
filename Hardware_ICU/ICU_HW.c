

#include "ICU_HW.h"

#include "Platform_Types.h"

#include "TIMER_interface.h"


uint16 PeriodTime_Ticks = 0 ;
uint16 ON_Ticks = 0 ;
void ICU_Hw(void)
{

	/*Initiate 3 variables to save the 3 states reading*/
	static uint16 Reading1,Reading2,Reading3 ;

	/*Initiate counter to know iam in which state of 3 states*/
	static uint8 Local_uint8Counter = 0 ;
	Local_uint8Counter++;

	if(Local_uint8Counter == 1) /*First rising edge*/
	{
	Reading1 = ICU_uint16ReadInputCapture();
	}
	else if(Local_uint8Counter == 2) /*Second  rising edge*/
	{
		Reading2 = ICU_uint16ReadInputCapture();
       PeriodTime_Ticks = Reading2 - Reading1 ;
       ICU_uint8SetTriggerEdge(ICU_FAILING_EDGE);
	}
	else if(Local_uint8Counter == 3)
	{
		Reading3 = ICU_uint16ReadInputCapture();
		ON_Ticks = Reading3 - Reading2;

		/*Disable ICUinterrupt */
	 	ICU_voidDisableInturrept();

	}


}

