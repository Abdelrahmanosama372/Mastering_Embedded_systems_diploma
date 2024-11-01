/*
 * led.c
 *
 * Created: 3/17/2024 12:16:01 PM
 *  Author: Abdelrahman
 */ 

#include "../Inc/lcd.h"

#include <stdio.h>

unsigned char number_of_characters = 0;
unsigned char is_clearing = 0;

void delay();
void Lcd_gpio_init();
void LCD_init(Lcd_Config *lcd){
	delay();
	Lcd_gpio_init(lcd);
	delay();
	LCD_writeCommand(lcd, (char)0x02);
	LCD_writeCommand(lcd, LCD_FUNC_4_BIT_MODE);
	LCD_writeCommand(lcd, LCD_ENTRY_INC);
	LCD_writeCommand(lcd, LCD_FIRST_ROW);
	LCD_writeCommand(lcd, LCD_DISP_CURSOR_BLINK);
}

void LCD_lcd_kick(Lcd_Config *lcd){
	MCAL_GPIO_Write_Pin(lcd->CTRL_Gpio, lcd->EN, GPIO_PIN_SET);
	delay();
	MCAL_GPIO_Write_Pin(lcd->CTRL_Gpio, lcd->EN, GPIO_PIN_RESET);
}

void LCD_writeCommand(Lcd_Config *lcd, unsigned char command){
	//LCD_check_lcd_isbusy();
	MCAL_GPIO_Write_Pin(lcd->DATA_Gpio, lcd->D4, getBitAT(command,4));
	MCAL_GPIO_Write_Pin(lcd->DATA_Gpio, lcd->D5, getBitAT(command,5));
	MCAL_GPIO_Write_Pin(lcd->DATA_Gpio, lcd->D6, getBitAT(command,6));
	MCAL_GPIO_Write_Pin(lcd->DATA_Gpio, lcd->D7, getBitAT(command,7));

	MCAL_GPIO_Write_Pin(lcd->CTRL_Gpio, lcd->RS, GPIO_PIN_RESET);

	LCD_lcd_kick(lcd);

	MCAL_GPIO_Write_Pin(lcd->DATA_Gpio, lcd->D4, getBitAT(command,0));
	MCAL_GPIO_Write_Pin(lcd->DATA_Gpio, lcd->D5, getBitAT(command,1));
	MCAL_GPIO_Write_Pin(lcd->DATA_Gpio, lcd->D6, getBitAT(command,2));
	MCAL_GPIO_Write_Pin(lcd->DATA_Gpio, lcd->D7, getBitAT(command,3));

	LCD_lcd_kick(lcd);
}

void LCD_writeChar(Lcd_Config *lcd, char ch){
	if(number_of_characters == 16 && AUTOMATIC_WRAP) {
		LCD_goTo_X_and_Y(lcd, LCD_SECOND_ROW, LCD_COL_0);
	}else if(number_of_characters == 32 && AUTOMATIC_WRAP){
		LCD_goTo_X_and_Y(lcd, LCD_THIRD_ROW, LCD_COL_0);
	}else if(number_of_characters == 48 && AUTOMATIC_WRAP){
		LCD_goTo_X_and_Y(lcd, LCD_FOURTH_ROW, LCD_COL_0);
	}

	if(!is_clearing)
		number_of_characters++;

	MCAL_GPIO_Write_Pin(lcd->DATA_Gpio, lcd->D4, getBitAT(ch,4));
	MCAL_GPIO_Write_Pin(lcd->DATA_Gpio, lcd->D5, getBitAT(ch,5));
	MCAL_GPIO_Write_Pin(lcd->DATA_Gpio, lcd->D6, getBitAT(ch,6));
	MCAL_GPIO_Write_Pin(lcd->DATA_Gpio, lcd->D7, getBitAT(ch,7));

	MCAL_GPIO_Write_Pin(lcd->CTRL_Gpio, lcd->RS, GPIO_PIN_SET);

	LCD_lcd_kick(lcd);

	MCAL_GPIO_Write_Pin(lcd->DATA_Gpio, lcd->D4, getBitAT(ch,0));
	MCAL_GPIO_Write_Pin(lcd->DATA_Gpio, lcd->D5, getBitAT(ch,1));
	MCAL_GPIO_Write_Pin(lcd->DATA_Gpio, lcd->D6, getBitAT(ch,2));
	MCAL_GPIO_Write_Pin(lcd->DATA_Gpio, lcd->D7, getBitAT(ch,3));

	LCD_lcd_kick(lcd);
}

void LCD_writeString(Lcd_Config *lcd, char *str){
	while(*str){
		LCD_writeChar(lcd, *str);
		str++;
	}
}

void LCD_writeInteger(Lcd_Config *lcd, int number) {
	char buffer[8];
	snprintf(buffer,sizeof(buffer),"%d",number);
	LCD_writeString(lcd, buffer);
}

void LCD_writeFloat(Lcd_Config *lcd, float number){
	int tmp_num;
	tmp_num = (int)number;
	LCD_writeInteger(lcd, tmp_num);
	LCD_writeChar(lcd, '.');
	tmp_num = ((int)(number*100)) % 100;
	tmp_num < 0 ?
		LCD_writeInteger(lcd, -tmp_num) : LCD_writeInteger(lcd, tmp_num);
}

void LCD_clearDisplay(Lcd_Config *lcd){
	//LCD_check_lcd_isbusy(lcd);
	LCD_writeCommand(lcd, LCD_CLEAR_DISPLAY);
	number_of_characters = 0;
}

void LCD_backClearDisplay(Lcd_Config *lcd){
	LCD_writeCommand(lcd, LCD_ENTRY_DEC);
	is_clearing = 1;
	uint8_t i;
	for(i=number_of_characters+1; i>0; i--){
		switch(i)
		{
			case 16:
				LCD_goTo_X_and_Y(lcd, LCD_FIRST_ROW, LCD_COL_15);
				break;
			case 32:
				LCD_goTo_X_and_Y(lcd, LCD_SECOND_ROW, LCD_COL_15);
				break;
			case 48:
				LCD_goTo_X_and_Y(lcd, LCD_THIRD_ROW, LCD_COL_15);
				break;
		}
		LCD_writeChar(lcd, ' ');
	}
	LCD_writeCommand(lcd, LCD_FIRST_ROW);
	LCD_writeCommand(lcd, LCD_ENTRY_INC);
	is_clearing = 0;
	number_of_characters = 0;
}

void LCD_goTo_X_and_Y(Lcd_Config *lcd, unsigned char x, unsigned char y){
	LCD_writeCommand(lcd, x + y);
}

//void LCD_check_lcd_isbusy(){
//	LCD_CTRL_PORT |= (1 << RW_SWITCH_SWITCH);
//	LCD_CTRL_PORT &= ~(1 << RS_SWITCH_SWITCH);
//	LCD_DATA_DDR &= ~(0x0F);
//	LCD_lcd_kick();
//	LCD_DATA_DDR |= (0x08);
//	LCD_CTRL_PORT &= ~(1 << RW_SWITCH_SWITCH);
//}

void Lcd_gpio_init(Lcd_Config *lcd){
	GPIO_Pin_Config pinConfig;
	pinConfig.Pin_Mode = General_Purpose_Output_PP;
	pinConfig.Pin_Speed = GPIO_Pin_Max_Speed2M;

	pinConfig.Pin_Number = lcd->D4;
	MCAL_GPIO_Init(lcd->DATA_Gpio, &pinConfig);

	pinConfig.Pin_Number = lcd->D5;
	MCAL_GPIO_Init(lcd->DATA_Gpio, &pinConfig);

	pinConfig.Pin_Number = lcd->D6;
	MCAL_GPIO_Init(lcd->DATA_Gpio, &pinConfig);

	pinConfig.Pin_Number = lcd->D7;
	MCAL_GPIO_Init(lcd->DATA_Gpio, &pinConfig);

	pinConfig.Pin_Number = lcd->RS;
	MCAL_GPIO_Init(lcd->CTRL_Gpio, &pinConfig);

	pinConfig.Pin_Number = lcd->EN;
	MCAL_GPIO_Init(lcd->CTRL_Gpio, &pinConfig);
}

void delay(){
	volatile int i,j;
		for(i=-500; i<500; i++)
			for(j=-10; j<10; j++);
}
