/*
 ============================================================================
 Name        : EX1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "string.h"

int main(void)
{
	char ch;
	char str [200];
	int i, counter = 0;
	printf ("enter a string: ");
	fflush (stdout);
	gets(str);
	printf ("enter a character to find frequency: ");
	fflush (stdout);
	scanf("%c",&ch);
	for (i=0; i< strlen(str); i++)
	{
		if(str[i] == ch) counter+=1;
	}
	printf ("frequency of %c = %d",ch,counter);
}
