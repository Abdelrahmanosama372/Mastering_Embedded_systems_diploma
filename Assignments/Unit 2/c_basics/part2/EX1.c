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

int main(void)
{
	for (int i=0; i<2; i++)
	{
		int num;
		printf ("Enter an integer you want to check: ");
		fflush (stdout);
		scanf  ("%d" , &num);
		if ( num % 2 == 0)      printf ("%d is even",num);
		else                    printf ("%d is odd",num);
		printf("\n");
	}
}
