/*
 ============================================================================
 Name        : ques5.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int count (int val);

int main(void)
{
	int num;
	printf("enter a number: ");
	fflush(stdout);
	scanf("%d",&num);
	printf("the number of 1's in %d equal: %d ",num,count(num));
	return EXIT_SUCCESS;
}

int count (int val)
{
	int counter = 0;
	while( val != 0)
	{
		if ( (val | 1) == val ) counter++;
		val>>=1;
	}
	return counter;
}
