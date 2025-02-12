/***************************************************/
/***************************************************/
/***********   Author: Mohsen Youssif  **************/
/***********   layer:  HAL            **************/
/***********   SWC: CLCD              **************/
/***********   Version: 1.00          **************/
/***************************************************/
/***************************************************/
#ifndef  CLCD_INTERFACE_H_
#define  CLCD_INTERFACE_H_


void CLCD_voidInit(void);

/* This function used to send command to LCD */
void CLCD_voidSendCommand(uint8 copy_uint8Command);

/* This function used to send Data to LCD */
void CLCD_voidSendData(uint8 copy_uint8Data);

/*Function used to send string Data to LCD*/
void CLCD_voidSendString(const char* copy_pcString);

/*Function used to calculate the address with the help of x,y*/
void CLCD_voidGoToXY(uint8 Copy_uint8Xposition,uint8 Copy_uint8Yposition);

/*Function used to display special character at LCD*/
void CLCD_voidWriteSpecialCharacter(uint8* Copy_puint8Pattern,uint8 Copy_uint8PatternNumber,uint8 Copy_uint8Xposition,uint8 Copy_uint8Yposition );

/**
 * @brief  Writes an unsigned 32-bit number to the character LCD.
 *
 * This function takes a number and prints it on the LCD as a sequence of characters.
 * It first reverses the number while preserving its digits, then prints them correctly.
 *
 * @param  Copy_uint32Number  The number to be displayed on the LCD.
 */
void CLCD_voidWriteNumber(uint32 Copy_uint32Number);

#endif
