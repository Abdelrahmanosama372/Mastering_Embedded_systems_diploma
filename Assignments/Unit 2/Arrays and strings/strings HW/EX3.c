/*
 ============================================================================
 Name        : EX3.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "string.h"

int main(void) {
	char str[100], rev_str[100];
	int i;
	printf ("Enter the string: ");
	fflush (stdout);
	gets (str);
	for (i=0; i<strlen(str); i++)
	{
		rev_str[i] = str[strlen(str)-i-1];
	}
	rev_str[i] = 0;
	printf ("Reverse string is: %s ", rev_str);
}

