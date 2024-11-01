/*
 * keyPad.c
 *
 * Created: 3/20/2024 2:28:22 PM
 *  Author: Abdelrahman
 */ 

#include "../Inc/keyPad.h"

uint16_t ROWS[] = {R0, R1, R2, R3};
uint16_t COLS[] = {C0, C1, C2};
uint8_t Keys[][3]= {{'*', '0', '#'},
					{'7', '8', '9'},
					{'4', '5', '6'},
					{'1', '2', '3'}};

void delay2(){
	volatile int i,j;
		for(i=-5000; i<5000; i++)
			for(j=-10; j<10; j++);
}
void keypad_gpio_init();

void Keypad_init(){
	keypad_gpio_init();
	MCAL_GPIO_Write_Pin(KEYPAD_PORT, ALL_PINS, GPIO_PIN_SET);
}

char Keypad_getkey(){
	uint8_t key = '!';
	while(key == '!')
	{
		int i,j;
		for(i=0; i<sizeof(COLS)/sizeof(COLS[0]); i++){
			MCAL_GPIO_Write_Pin(KEYPAD_PORT, ALL_PINS, GPIO_PIN_SET);
			MCAL_GPIO_Write_Pin(KEYPAD_PORT, COLS[i], GPIO_PIN_RESET);
			for(j=0; j<sizeof(ROWS)/sizeof(ROWS[0]); j++){
				if(!MCAL_GPIO_Read_Pin(KEYPAD_PORT, ROWS[j])){
					while(!MCAL_GPIO_Read_Pin(KEYPAD_PORT, ROWS[j]));
					return Keys[j][i];
				}
			}
		}
	}
	return key;
}


void keypad_gpio_init(){
	GPIO_Pin_Config pinConfig;
	pinConfig.Pin_Mode = Input_Pull_Up;

	pinConfig.Pin_Number = R0;
	MCAL_GPIO_Init(KEYPAD_PORT, &pinConfig);

	pinConfig.Pin_Number = R1;
	MCAL_GPIO_Init(KEYPAD_PORT, &pinConfig);

	pinConfig.Pin_Number = R2;
	MCAL_GPIO_Init(KEYPAD_PORT, &pinConfig);

	pinConfig.Pin_Number = R3;
	MCAL_GPIO_Init(KEYPAD_PORT, &pinConfig);

	pinConfig.Pin_Mode = General_Purpose_Output_PP;
	pinConfig.Pin_Speed = GPIO_Pin_Max_Speed2M;

	pinConfig.Pin_Number = C0;
	MCAL_GPIO_Init(KEYPAD_PORT, &pinConfig);

	pinConfig.Pin_Number = C1;
	MCAL_GPIO_Init(KEYPAD_PORT, &pinConfig);

	pinConfig.Pin_Number = C2;
	MCAL_GPIO_Init(KEYPAD_PORT, &pinConfig);
}
