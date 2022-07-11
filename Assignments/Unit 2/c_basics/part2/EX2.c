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
	char ch;
	printf ("Enter an alphabet: ");
	fflush (stdout);
	scanf  ("%c", &ch);
	if ( ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')       printf("%c is a vowel", ch );
	else if ( ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')  printf("%c is a vowel", ch );
	else                                                                      printf("%c is a consonant", ch);
}
