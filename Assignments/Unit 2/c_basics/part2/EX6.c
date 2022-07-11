/*
 ============================================================================
 Name        : EX6.c
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
	int num, i, sum=0;
	printf ("enter an integer: ");
	fflush (stdout);
	scanf  ("%d",&num);
	for (i=1; i<=num; i++) sum+=i;
	printf ("sum = %d",sum);
}
