/*
 ============================================================================
 Name        : ques1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int sum (int val);

int main(void)
{
	int num;
	printf("enter a number:");
	fflush(stdout);
	scanf("%d",&num);
	printf("the sum of digits is: %d",sum(num));
	return EXIT_SUCCESS;
}

int sum (int val)
{
	int total=0;
	while (val!=0)
	{
		total+=val%10;
		val/=10;
	}
	return total;
}
