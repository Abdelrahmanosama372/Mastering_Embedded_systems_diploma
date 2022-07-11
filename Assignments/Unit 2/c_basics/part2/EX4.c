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
	float num;
	printf ("Enter a number= ");
	fflush (stdout);
	scanf  ("%f",&num);
	if (num > 0)      printf("%.2f is positive",num);
	else if (num < 0) printf("%.2f is negative",num);
	else              printf("you entered zero");
}
