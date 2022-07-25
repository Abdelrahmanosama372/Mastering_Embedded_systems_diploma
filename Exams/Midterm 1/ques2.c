/*
 ============================================================================
 Name        : ques2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float sqr (int val);

int main(void)
{
	int num;
	printf("enter a number:");
	fflush(stdout);
	scanf("%d",&num);
	printf("the square root of %d is: %.3f",num,sqr(num));
	return EXIT_SUCCESS;
}

float sqr (int val)
{
	return pow(val,0.5);
}
