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

int power(int base_num , int power_num);

int main(void)
{
	int base_num,power_num,res;
	printf("Enter base number: ");
	fflush(stdout);
	scanf("%d",&base_num);
	printf("Enter power number(positive integer): ");
	fflush(stdout);
	scanf("%d",&power_num);
	res = power(base_num , power_num);
	printf("%d^%d = %d",base_num , power_num , res);

	return EXIT_SUCCESS;
}

int power(int base_num , int power_num)
{
	if (power_num == 1) return base_num;
	else return ( base_num * power(base_num , power_num-1) );
}
