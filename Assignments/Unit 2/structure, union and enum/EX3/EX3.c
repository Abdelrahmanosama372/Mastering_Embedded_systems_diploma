/*
 ============================================================================
 Name        : EX3.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

struct complex
{
	float real, img;
};

struct complex complex_add(struct complex,struct complex);

int main(void)
{
	struct complex C1,C2,total;
	printf("for 1st complex number\n");
	printf("enter real and imaginary respectively: ");
	fflush(stdout);
	scanf("%f %f",&C1.real,&C1.img);
	printf("for 2nd complex number\n");
	printf("enter real and imaginary respectively: ");
	fflush(stdout);
	scanf("%f %f",&C2.real,&C2.img);
	total = complex_add(C1,C2);
	printf("sum=%.1f+%.1fi",total.real,total.img);

	return EXIT_SUCCESS;
}

struct complex complex_add(struct complex c1,struct complex c2)
{
	struct complex tot;
	tot.real = c1.real+ c2.real;
	tot.img  = c1.img + c2.img;
	return tot;
}
