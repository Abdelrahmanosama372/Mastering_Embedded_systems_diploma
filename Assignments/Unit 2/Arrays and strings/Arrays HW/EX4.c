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

int main(void)
{
	int num, i, element, loc;
	printf ("Enter the number of Elements: ");
	fflush (stdout);
	scanf ("%d",&num);
	int arr[20];
	for ( i = 0; i < num; i++ )
	{
		scanf ("%d", &arr[i]);
	}
	printf ("Enter the element to be inserted: ");
	fflush (stdout);
	scanf ("%d",&element);
	printf ("Enter the location: ");
	fflush (stdout);
	scanf ("%d", &loc );
	for ( i = num; i >=loc; i-- ) arr[i] = arr[i-1];
	arr[loc-1] = element;
	for ( i = 0; i < num+1; i++ ) printf ("%d\t",arr[i]);



}
