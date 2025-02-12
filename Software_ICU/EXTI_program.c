/***************************************************/
/***************************************************/
/***********   Author: Mohsen Youssif  **************/
/***********   layer:  MCAL            **************/
/***********   SWC: EXTI                **************/
/***********   Version: 1.00          **************/
/***************************************************/
/***************************************************/

#include "Platform_Types.h"
#include "BIT_MATH.h"

#include "EXTI_registers.h"
#include "EXTI_interface.h"
#include "EXTI_private.h"
#include "EXTI_config.h"

/*Global  pointer to Function to hold INT0 ISR addresses */
void (*EXTI_pvInt0Fun)(void)=NULL;

void EXTI_voidInt0Init(void)
{

	/*Set Sense control for INT0 to  low level
	 * ISC01 -> 0  ISC00 ->  0  The low level of INT0 generates an interrupt request */

#if INT0_SENSE_CONTROL == EXTI_LOW_LEVEL_SENCE_CONTROL

	CLR_BIT(MCUCR,MCUCR_ISC00);
	CLR_BIT(MCUCR,MCUCR_ISC01);

	/*Set Sense control for INT0 to  on change
	 * ISC01 -> 0  ISC00 ->  1  The on change of INT0 generates an interrupt request */

#elif INT0_SENSE_CONTROL == EXTI_ONCHANGE_SENCE_CONTROL

	CLR_BIT(MCUCR,MCUCR_ISC01);
	SET_BIT(MCUCR,MCUCR_ISC00);

	/*Set Sense control for INT0 to falling edge
	 * ISC01 -> 1  ISC00 ->  0  The falling edge of INT0 generates an interrupt request */


#elif INT0_SENSE_CONTROL == EXTI_FALLING_EDGE_SENCE_CONTROL

	SET_BIT(MCUCR,MCUCR_ISC01 );
	CLR_BIT(MCUCR,MCUCR_ISC00);


	/*Set Sense control for INT0 to rising edge
	 * ISC01 -> 1  ISC00 ->  1  The rising edge of INT0 generates an interrupt request */

#elif INT0_SENSE_CONTROL == EXTI_RISING_EDGE_SENCE_CONTROL
	SET_BIT(MCUCR,MCUCR_ISC01);
	SET_BIT(MCUCR,MCUCR_ISC00);

#else
	/*Error message if the user enter wrong sence control value   */
#error"You choose a wrong INT0_SENSE_CONTROL configuration options !!"

#endif


	/*Check peripheral interrupt enable initial state */

	/*peripheral interrupt enable for INT0  ((SIE))*/

#if INT0_INITIAL_STATE == ENABLED
	SET_BIT(GICR,GICR_INT0);

	/*peripheral interrupt disable for INT0  ((SIE))*/

#elif INT0_INITIAL_STATE == DISABLED
	CLR_BIT(GICR,GICR_INT0);
#else
#error "You choose a wrong INT0_INITIAL_STATE configuration options !! "
#endif


}



uint8 EXTI_uint8Int0SetSenseControl(uint8 Copy_uint8Sense )
{
	uint8 Local_uint8ErrorState = OK ;
	if(Copy_uint8Sense == EXTI_LOW_LEVEL_SENCE_CONTROL)
	{
		CLR_BIT(MCUCR,MCUCR_ISC00);
		CLR_BIT(MCUCR,MCUCR_ISC01);
		Local_uint8ErrorState = OK;
	}
	else if( Copy_uint8Sense == EXTI_ONCHANGE_SENCE_CONTROL)
	{
		CLR_BIT(MCUCR,MCUCR_ISC01);
		SET_BIT(MCUCR,MCUCR_ISC00);
		Local_uint8ErrorState = OK;
	}else if(Copy_uint8Sense == EXTI_FALLING_EDGE_SENCE_CONTROL)
	{
		SET_BIT(MCUCR,MCUCR_ISC01 );
		CLR_BIT(MCUCR,MCUCR_ISC00);
		Local_uint8ErrorState = OK ;
	}else if(Copy_uint8Sense == EXTI_RISING_EDGE_SENCE_CONTROL)
	{
		SET_BIT(MCUCR,MCUCR_ISC01);
		SET_BIT(MCUCR,MCUCR_ISC00);
		Local_uint8ErrorState = OK;
	}else
	{
		Local_uint8ErrorState =NOK ;
	}

	return Local_uint8ErrorState;
}



uint8 EXTI_uint8Int0SetCallBack(void(*Copy_pvInt0Func)(void))
{
	uint8 Local_uint8ErrorState = OK ;
	if(Copy_pvInt0Func != NULL)
	{

		EXTI_pvInt0Fun =Copy_pvInt0Func;

	}else
	{
		Local_uint8ErrorState =NULL_pointer ;
	}

	return Local_uint8ErrorState ;
}

uint8 EXTI_uint8Disable(uint8 Copy_IntID)
{
	uint8 Local_uint8ErrorState = OK ;

	/*Check the user pass the correct Value*/
	if( (Copy_IntID == INT0) ||(Copy_IntID == INT0)||(Copy_IntID ==INT0))
	{
		/*Clear the required bit*/
		CLR_BIT(GICR,Copy_IntID);
	}else
	{
		Local_uint8ErrorState = NOK;
	}


	return Local_uint8ErrorState ;
}
uint8 EXTI_uint8IntEnable(uint8 Copy_IntID )
{
	uint8 Local_uint8ErrorState = OK ;

		/*Check the user pass the correct Value*/
		if( (Copy_IntID == INT0) ||(Copy_IntID == INT0)||(Copy_IntID ==INT0))
		{
			/*Clear the required bit*/
			SET_BIT(GICR,Copy_IntID);
		}else
		{
			Local_uint8ErrorState = NOK;
		}


		return Local_uint8ErrorState ;
}

/*ISR OF INT0*/
void __vector_1(void)__attribute__((signal));
void __vector_1(void)
{
	if(EXTI_pvInt0Fun !=NULL)
	{
		EXTI_pvInt0Fun();

	}
}

