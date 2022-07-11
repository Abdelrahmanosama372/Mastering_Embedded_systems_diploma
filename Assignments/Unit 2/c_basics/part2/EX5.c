/*
 ============================================================================
 Name        : EX5.c
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
	char ch;
	printf ("Enter a character: ");
	fflush (stdout);
	scanf  ("%c",&ch);

	// from Ascii table the alphabets lies between 65 and 122 decimal values
	if ( (int)ch >=65 && (int)ch <=122 ) printf("%c is an alphabet",ch);
	else                                 printf("%c is not an alphabet",ch);
}
