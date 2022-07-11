/*
 ============================================================================
 Name        : EX4.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	float num1, num2;
	printf ("Enter two numbers: ");
	fflush (stdout);
	scanf ("%f %f", &num1, &num2);
	printf ("Product: %f" , num1*num2);
}
