/*
 ============================================================================
 Name        : EX2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int N,i;
	float sum=0;
	printf ("Enter the number of data: ");
	fflush (stdout);
	scanf ("%d",&N);
	float arr [N-1];

	for (i=0; i<N; i++)
	{
		printf("Enter a number: ");
		fflush (stdout);
		scanf ("%f",&arr[i]);
	}
	for (i=0; i<N; i++)
	{
		sum+=arr[i];
	}
	printf("Average = %f",sum/N);
}
