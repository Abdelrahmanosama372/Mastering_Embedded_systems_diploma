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

#define	LCD_DATA_PORT 			    GPIOA
#define D4  GPIO_PIN_0
#define D5  GPIO_PIN_1
#define D6  GPIO_PIN_2
#define D7  GPIO_PIN_3

#define	LCD_CTRL_PORT				GPIOA
#define RS_SWITCH GPIO_PIN_4
#define RW_SWITCH GPIO_PIN_5
#define EN_SWITCH GPIO_PIN_6

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
#define LCD_BEGIN_AT_FIRST_ROW		0x80
#define LCD_BEGIN_AT_SECOND_ROW		0xC0

#define getBitAT(command, pos)    ((command >> pos) & 0x01)

// ------------------ APIS  ------------------
void LCD_init();
void LCD_lcd_kick();
void LCD_writeCommand(unsigned char command);
void LCD_writeChar(char ch);
void LCD_writeString(char *str);
void LCD_writeInteger(int number);
void LCD_writeFloat(float number);
void LCD_clearDisplay();
void LCD_backClearDisplay();
void LCD_goTo_X_and_Y(unsigned char x, unsigned char y); 
void LCD_check_lcd_isbusy();
#endif /* LCD_H_ */
