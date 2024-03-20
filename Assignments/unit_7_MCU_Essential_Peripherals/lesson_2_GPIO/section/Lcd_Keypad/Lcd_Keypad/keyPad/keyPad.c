/*
 * keyPad.c
 *
 * Created: 3/20/2024 2:28:22 PM
 *  Author: Abdelrahman
 */ 

#include "keyPad.h"
//#include <util/delay.h>

uint8_t ROWS[] = {R0, R1, R2, R3};
uint8_t COLS[] = {C0, C1, C2, C3};
uint8_t Keys[][4]= {{'7', '8', '9', '/'},
					{'4', '5', '6', '*'},
					{'1', '2', '3', '-'},
					{'r', '0', '=', '+'}};

void Keypad_init(){
	KEYPAD_DDR  &= ~((1<<R0) | (1<<R1) | (1<<R2) | (1<<R3));
	KEYPAD_DDR  |= (1<<C0) | (1<<C1) | (1<<C2) | (1<<C3);
	KEYPAD_PORT = 0xFF;
}

char Keypad_getkey(){
	int i,j;
	for(i=0; i<4; i++){
		KEYPAD_PORT = 0xFF;
		KEYPAD_PORT &= ~(1<<COLS[i]);
		for(j=0; j<4; j++){
			if(!(KEYPAD_PIN & (1 << ROWS[j]))){
				while(!(KEYPAD_PIN & (1 << ROWS[j])));
				return Keys[i][j];
			}
		}
	}
	return '!';
}
