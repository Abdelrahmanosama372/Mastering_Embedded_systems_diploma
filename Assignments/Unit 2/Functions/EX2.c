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

int factorial (int x);

int main(void)
{
	int num;
	printf("Enter a positive integer: ");
	fflush(stdout);
	scanf("%d",&num);
	printf("Factorial of %d = %d",num,factorial(num));
}

int factorial (int x)
{
	if ( x == 1) return 1;
	x = x * factorial(x-1);
	return x;

}
