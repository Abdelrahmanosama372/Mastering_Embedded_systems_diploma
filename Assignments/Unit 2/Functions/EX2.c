/*
 ============================================================================
 Name        : EX2.c
 Author      : Abdelrahman osama
 Description : Calculate factorial of a number using recursion
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
	printf("Factorial of %d = %d\n",num,factorial(num));
}

int factorial (int x)
{
	if ( x == 1) 
		return 1;
	return x * factorial(x-1);
}
