/*
 ============================================================================
 Name        : EX7.c
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
	int num, i, fact=1;
	printf ("enter an integer: ");
	fflush (stdout);
	scanf  ("%d",&num);
	if ( num < 0)         printf("Error!!! Factorial of negative number doesn't exist");
	else
	{
		for(i=num; i>=1; i--) fact*=i;
		printf ("Factorial = %d",fact);
	}


}
