/*
 ============================================================================
 Name        : EX1.c
 Author      : Abdelrahman osama
 Description : print prime numbers between two intervals
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void fun (int a, int b);

int main(void)
{
	int num1, num2;
	printf("Enter two numbers (intervals): ");
	fflush(stdout);
	scanf("%d %d",&num1,&num2);
	fun(num1,num2);
	return EXIT_SUCCESS;
}

void fun (int a, int b)
{
	int counter=0;
	printf("prime numbers between %d and %d are: ",a,b);
	for(int i=a; i<=b; i++)
	{
		for(int j=2; j<=i; j++)
			{
				if(i%j == 0)  counter++;
			}
		//printf("%d  ",counter);
		if (counter == 1)	printf("%d ",i);
		counter=0;
	}
}
