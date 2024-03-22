/*
 * led.c
 *
 * Created: 3/17/2024 12:16:01 PM
 *  Author: Abdelrahman
 */ 

#include "../HAL/Inc/lcd.h"

#include <stdio.h>

unsigned char number_of_characters = 0;
unsigned char is_clearing = 0;

void delay();
void Lcd_gpio_init();
void LCD_init(){
	delay();
	Lcd_gpio_init();
	delay();
	LCD_writeCommand((char)0x02);
	LCD_writeCommand(LCD_FUNC_4_BIT_MODE);
	LCD_writeCommand(LCD_ENTRY_INC);
	LCD_writeCommand(LCD_BEGIN_AT_FIRST_ROW);
	LCD_writeCommand(LCD_DISP_CURSOR_BLINK);
}

void LCD_lcd_kick(){
	MCAL_GPIO_Write_Pin(LCD_CTRL_PORT, EN_SWITCH, GPIO_PIN_SET);
	delay();
	MCAL_GPIO_Write_Pin(LCD_CTRL_PORT, EN_SWITCH, GPIO_PIN_RESET);
}

void LCD_writeCommand(unsigned char command){
	//LCD_check_lcd_isbusy();
	MCAL_GPIO_Write_Pin(LCD_DATA_PORT, D4, getBitAT(command,4));
	MCAL_GPIO_Write_Pin(LCD_DATA_PORT, D5, getBitAT(command,5));
	MCAL_GPIO_Write_Pin(LCD_DATA_PORT, D6, getBitAT(command,6));
	MCAL_GPIO_Write_Pin(LCD_DATA_PORT, D7, getBitAT(command,7));

	MCAL_GPIO_Write_Pin(LCD_CTRL_PORT, RS_SWITCH, GPIO_PIN_RESET);
	MCAL_GPIO_Write_Pin(LCD_CTRL_PORT, RW_SWITCH, GPIO_PIN_RESET);

	LCD_lcd_kick ();

	MCAL_GPIO_Write_Pin(LCD_DATA_PORT, D4, getBitAT(command,0));
	MCAL_GPIO_Write_Pin(LCD_DATA_PORT, D5, getBitAT(command,1));
	MCAL_GPIO_Write_Pin(LCD_DATA_PORT, D6, getBitAT(command,2));
	MCAL_GPIO_Write_Pin(LCD_DATA_PORT, D7, getBitAT(command,3));

	LCD_lcd_kick();
}

void LCD_writeChar(char ch){
	if(number_of_characters == 16) {
		LCD_goTo_X_and_Y(1,0);
	}
	if(!is_clearing)
		number_of_characters++;

	MCAL_GPIO_Write_Pin(LCD_DATA_PORT, D4, getBitAT(ch,4));
	MCAL_GPIO_Write_Pin(LCD_DATA_PORT, D5, getBitAT(ch,5));
	MCAL_GPIO_Write_Pin(LCD_DATA_PORT, D6, getBitAT(ch,6));
	MCAL_GPIO_Write_Pin(LCD_DATA_PORT, D7, getBitAT(ch,7));

	MCAL_GPIO_Write_Pin(LCD_CTRL_PORT, RS_SWITCH, 1);

	LCD_lcd_kick();

	MCAL_GPIO_Write_Pin(LCD_DATA_PORT, D4, getBitAT(ch,0));
	MCAL_GPIO_Write_Pin(LCD_DATA_PORT, D5, getBitAT(ch,1));
	MCAL_GPIO_Write_Pin(LCD_DATA_PORT, D6, getBitAT(ch,2));
	MCAL_GPIO_Write_Pin(LCD_DATA_PORT, D7, getBitAT(ch,3));

	LCD_lcd_kick();
}

void LCD_writeString(char *str){
	while(*str){
		LCD_writeChar(*str);
		str++;
	}
}

void LCD_writeInteger(int number) {
	char buffer[8];
	snprintf(buffer,sizeof(buffer),"%d",number);
	LCD_writeString(buffer);
}

void LCD_writeFloat(float number){
	int tmp_num;
	tmp_num = (int)number;
	LCD_writeInteger(tmp_num);
	LCD_writeChar('.');
	tmp_num = ((int)(number*100)) % 100;
	tmp_num < 0 ?
		LCD_writeInteger(-tmp_num) : LCD_writeInteger(tmp_num);
}

void LCD_clearDisplay(){
	//LCD_check_lcd_isbusy();
	LCD_writeCommand(LCD_CLEAR_DISPLAY);
	number_of_characters = 0;
}

void LCD_backClearDisplay(){
	LCD_writeCommand(LCD_ENTRY_DEC);
	is_clearing = 1;
	int i;
	for(i=number_of_characters+1; i>0; i--){
		if(i==16)
			LCD_goTo_X_and_Y(0,15);
		LCD_writeChar(' ');
	}
	LCD_writeCommand(LCD_BEGIN_AT_FIRST_ROW);
	LCD_writeCommand(LCD_ENTRY_INC);
	is_clearing = 0;
	number_of_characters = 0;
}

void LCD_goTo_X_and_Y(unsigned char x, unsigned char y){
	if(x == 0){
		LCD_writeCommand(LCD_BEGIN_AT_FIRST_ROW + y);
	}else{
		LCD_writeCommand(LCD_BEGIN_AT_SECOND_ROW + y);
	}
}

//void LCD_check_lcd_isbusy(){
//	LCD_CTRL_PORT |= (1 << RW_SWITCH_SWITCH);
//	LCD_CTRL_PORT &= ~(1 << RS_SWITCH_SWITCH);
//	LCD_DATA_DDR &= ~(0x0F);
//	LCD_lcd_kick();
//	LCD_DATA_DDR |= (0x08);
//	LCD_CTRL_PORT &= ~(1 << RW_SWITCH_SWITCH);
//}

void Lcd_gpio_init(){
	GPIO_Pin_Config pinConfig;
	pinConfig.Pin_Mode = General_Purpose_Output_PP;
	pinConfig.Pin_Speed = GPIO_Pin_Max_Speed2M;

	pinConfig.Pin_Number = D4;
	MCAL_GPIO_Init(LCD_DATA_PORT, &pinConfig);

	pinConfig.Pin_Number = D5;
	MCAL_GPIO_Init(LCD_DATA_PORT, &pinConfig);

	pinConfig.Pin_Number = D6;
	MCAL_GPIO_Init(LCD_DATA_PORT, &pinConfig);

	pinConfig.Pin_Number = D7;
	MCAL_GPIO_Init(LCD_DATA_PORT, &pinConfig);

	pinConfig.Pin_Number = RS_SWITCH;
	MCAL_GPIO_Init(LCD_CTRL_PORT, &pinConfig);

	pinConfig.Pin_Number = RW_SWITCH;
	MCAL_GPIO_Init(LCD_CTRL_PORT, &pinConfig);

	pinConfig.Pin_Number = EN_SWITCH;
	MCAL_GPIO_Init(LCD_CTRL_PORT, &pinConfig);
}

void delay(){
	volatile int i,j;
		for(i=-500; i<500; i++)
			for(j=-10; j<10; j++);
}
