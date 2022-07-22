/*
 ============================================================================
 Name        : EX5.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

# define pi 3.14
# define area(r)(pi*r*r)

int main(void)
{
	float area,radius;
	printf("enter the radius:");
	fflush(stdout);
	scanf("%f",&radius);
	printf("area=%.2f",area=area(radius));
	return EXIT_SUCCESS;
}
