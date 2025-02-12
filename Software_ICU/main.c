

#include "Platform_Types.h"
#include "BIT_MATH.h"

#include "PORT_interface.h"  // Initializes the I/O ports
#include "DIO_interface.h"   // Handles GPIO operations
#include "EXTI_interface.h"  // External interrupt configurations
#include "TIMER_interface.h" // Timer module configurations
#include "GIE_interface.h"   // Global interrupt control

#include "CLCD_interface.h"  // LCD display interface

#include "ICU_SW.h"  // Software ICU (Input Capture Unit) for measuring signal properties

// External variables to store the period time and ON time of the PWM signal
extern uint16 PeriodTime_Ticks;
extern uint16 ON_Ticks;

int main(void)
{
    // Initialize all configured I/O ports
    PORT_voidInit();

    // Set up external interrupt INT0 to trigger the ICU function
    EXTI_uint8Int0SetCallBack(&ICU_SW);
    EXTI_voidInt0Init();

    // Initialize timers
    TIMER1_voidInit();  // Used to measure the input signal
    TIMER0_voidInit();  // Used to generate the PWM signal

    // Enable global interrupts
    GIE_voidEnable();

    // Initialize the LCD display
    CLCD_voidInit();

    while(1)
    {
        // Wait until both period time and ON time values are measured
        while((PeriodTime_Ticks == 0) && (ON_Ticks == 0));

        // Display the measured period time on the LCD
        CLCD_voidGoToXY(0,0);
        CLCD_voidSendString("P_Ticks = ");
        CLCD_voidWriteNumber(PeriodTime_Ticks);

        // Display the measured ON time on the LCD
        CLCD_voidGoToXY(1,0);
        CLCD_voidSendString("ON Ticks = ");
        CLCD_voidWriteNumber(ON_Ticks);
    }

    return 0;
}
