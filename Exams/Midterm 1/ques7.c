/*
 ============================================================================
 Name        : ques7.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int counter (int val);
int sum;                // default value is 0

int main(void)
{
	int num = 100;
	printf("the sum of values between the two numbers 1 and %d = %d"
			,num,counter(num));

	return EXIT_SUCCESS;
}

int counter (int val)
{
	sum+=val;
	if (val == 0) return 0;
	counter(--val);
	return sum;

}
