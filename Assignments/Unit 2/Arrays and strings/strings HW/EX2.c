/*
 ============================================================================
 Name        : EX2.c
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
	int i;
	char str[100];
	printf ("Enter a string: ");
	fflush (stdout);
	gets (str);
	for (i = 0; i < 100 && str[i] != 0; i++);
	printf ("length of string = %d",i);
}
