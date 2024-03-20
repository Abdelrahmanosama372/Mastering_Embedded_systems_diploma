/*
 * keyPad.h
 *
 * Created: 3/20/2024 2:28:45 PM
 *  Author: Abdelrahman
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_

#include <avr/io.h>

#define R0 0
#define R1 1
#define R2 2
#define R3 3
#define C0 4
#define C1 5
#define C2 6
#define C3 7

#define KEYPAD_DDR   DDRC
#define KEYPAD_PORT  PORTC
#define KEYPAD_PIN  PINC

void Keypad_init();
char Keypad_getkey();


#endif /* KEYPAD_H_ */