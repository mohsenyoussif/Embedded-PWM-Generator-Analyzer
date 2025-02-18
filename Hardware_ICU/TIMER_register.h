/***************************************************/
/***************************************************/
/***********   Author: Mohsen Youssif  **************/
/***********   layer:  MCAL            **************/
/***********   SWC: TIMER        **************/
/***********   Version: 1.00          **************/
/***************************************************/
/***************************************************/

#ifndef  TIMER_REGISTER_H
#define  TIMER_REGISTER_H

#define TCCR0        *((volatile uint8*)0x53)      /*Timer0 control register*/
#define TCCR0_WGM00       6                        /*Wave geerator Mode bit0*/
#define TCCR0_WGM01       3                        /*Wave geerator Mode bit1*/
#define TCCR0_COM01       5
#define TCCR0_COM00       4
#define TCCR0_CS02        2                        /*Prescaler bit2*/
#define TCCR0_CS01        1                        /*Prescaler bit1*/
#define TCCR0_CS00        0                        /*Prescaler bit0*/
												   
#define OCR0        *((volatile uint8*)0x5C)       /*Output compare register 0*/
												   
#define TIMSK       *((volatile uint8*)0x59)       /*Timer mask*/
#define TIMSK_OCIE0    1                           /*Output compare 0 interrupt enable */
#define TIMSK_TICIE1    5

#define TIFR       *((volatile uint8*)0x58)       
#define TIFR_OCF0     1                           

/*Timer1*/
#define TCCR1A			*((volatile uint8*)0X4F)     /*Timer1 control registerA*/
#define TCCR1A_COM1A0      6                    /* Compare Output Mode for Channel A*/
#define TCCR1A_COM1A1      7
#define TCCR1A_WGM11       1
#define TCCR1A_WGM10       0

#define TCCR1B			*((volatile uint8*)0X4E)     /*Timer1 control registerB*/
#define TCCR1B_ICES1      6
#define TCCR1B_WGM13      4
#define TCCR1B_WGM12      3
#define TCCR1B_CS10       0
#define TCCR1B_CS11       1
#define TCCR1B_CS12       2

#define TCNT1H          *((volatile uint8*)(0x4D))
#define TCNT1L          *((volatile uint8 *)(0x4C))
#define TCNT1			*((volatile uint16*)0X4C)    /* uint6 for HIGH & LOW */
#define OCR1AL          *((volatile uint8 *)(0x4A))
#define OCR1AH          *((volatile uint8 *)(0x4B))
#define OCR1A			*((volatile uint16*)0X4A)
#define OCR1BL          *((volatile uint8 *)(0x48))
#define OCR1BH          *((volatile uint8 *)(0x49))
#define OCR1B			*((volatile uint16*)0X48)
#define ICR1H           *((volatile uint8 *)(0x47))
#define ICR1L           *((volatile uint8 *)(0x46))
#define ICR1			*((volatile uint16*)0X46)


#endif
