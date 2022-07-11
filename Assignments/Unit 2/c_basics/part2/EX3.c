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

int main(void)
{
	float num , max=0;
	int i;
	printf ("Enter three numbers = ");
	fflush(stdout);
	scanf ("%f",&num);
	max=num;
	for (i=0; i<2; i++)
	{
		scanf ("%f",&num);
		if ( num > max)  max = num;
	}
	printf ("largest num = %.2f",max);;
}
