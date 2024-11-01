/*
 * lcd.h
 *
 * Created: 3/17/2024 12:16:25 PM
 *  Author: Abdelrahman
 */ 


#ifndef LCD_H_
#define LCD_H_

#include "stm32f103x6.h"
#include "stm32f103x6_gpio_driver.h"


typedef struct
{
	GPIO_TypeDef *DATA_Gpio;
	GPIO_TypeDef *CTRL_Gpio;
	uint16_t RS;
	uint16_t EN;
	uint16_t D4;
	uint16_t D5;
	uint16_t D6;
	uint16_t D7;
}Lcd_Config;

#define LCD_FUNC_4_BIT_MODE         0x28
#define LCD_FUNC_8_BIT_MODE         0x38  /* not supported by this driver */

#define LCD_CLEAR_DISPLAY			0x01
#define LCD_RETURN_HOME				0x02

#define LCD_DISP_ON					0x0C	
#define LCD_DISP_OFF				0x08
#define LCD_DISP_CURSOR_ON			0x0A
#define LCD_DISP_CURSOR_OFF			0x08
#define LCD_DISP_CURSOR_BLINK		0x0F
#define LCD_DISP_MOVE_RIGHT		    0x1C
#define LCD_DISP_MOVE_LEFT          0x18

#define LCD_CURSOR_MOVE_RIGHT       0x14
#define LCD_CURSOR_MOVE_LEFT        0x10

#define LCD_ENTRY_DEC				0x04
#define LCD_ENTRY_DEC_SHIFT			0x05
#define LCD_ENTRY_INC				0x06
#define LCD_ENTRY_INC_SHIFT			0x07

#define LCD_FIRST_ROW		0x80
#define LCD_SECOND_ROW		0xC0
#define LCD_THIRD_ROW      0x90
#define LCD_FOURTH_ROW     0xD0

#define LCD_COL_0		0x00
#define LCD_COL_1		0x01
#define LCD_COL_2		0x02
#define LCD_COL_3		0x03
#define LCD_COL_4		0x04
#define LCD_COL_5		0x05
#define LCD_COL_6		0x06
#define LCD_COL_7		0x07
#define LCD_COL_8		0x08
#define LCD_COL_9		0x09
#define LCD_COL_10		0x0A
#define LCD_COL_11		0x0B
#define LCD_COL_12		0x0C
#define LCD_COL_13		0x0D
#define LCD_COL_14		0x0E
#define LCD_COL_15		0x0F

#define AUTOMATIC_WRAP   0

#define getBitAT(command, pos)    ((command >> pos) & 0x01)

// ------------------ APIS  ------------------
void LCD_init(Lcd_Config *lcd);
void LCD_lcd_kick(Lcd_Config *lcd);
void LCD_writeCommand(Lcd_Config *lcd, unsigned char command);
void LCD_writeChar(Lcd_Config *lcd, char ch);
void LCD_writeString(Lcd_Config *lcd, char *str);
void LCD_writeInteger(Lcd_Config *lcd, int number);
void LCD_writeFloat(Lcd_Config *lcd, float number);
void LCD_clearDisplay(Lcd_Config *lcd);
void LCD_backClearDisplay(Lcd_Config *lcd);
void LCD_goTo_X_and_Y(Lcd_Config *lcd, unsigned char x, unsigned char y);
void LCD_check_lcd_isbusy(Lcd_Config *lcd);
#endif /* LCD_H_ */
