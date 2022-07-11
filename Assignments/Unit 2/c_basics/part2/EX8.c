/*
 ============================================================================
 Name        : EX8.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	char oper;
	float result;
	float num1, num2;
	printf("Enter operator either + or - or * or divide: ");
	fflush(stdout);
	scanf ("%c",&oper);
	printf("Enter two operands: ");
	fflush(stdout);
	scanf ("%f %f",&num1,&num2);
	switch(oper)
	{
	case '+':
		result=num1+num2;
	break;
	case '-':
		result=num1-num2;
	break;
	case '*':
		result=num1*num2;
	break;
	case '/':
		result=num1/num2;
	default:
		printf("Error!!!");
	}
	printf("%.1f %c %.1f = %.1f",num1,oper,num2,result);

	return EXIT_SUCCESS;
}
