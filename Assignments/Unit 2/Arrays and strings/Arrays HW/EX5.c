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

int main(void)
{
	int num, i, element;
	printf ("Enter the number of Elements: ");
	fflush (stdout);
	scanf ("%d",&num);
	int arr[num];
	for ( i = 0; i < num; i++ )
	{
		scanf ("%d", &arr[i]);
	}
	printf ("Enter the element to be searched: ");
	fflush (stdout);
	scanf ("%d",&element);
	for (i = 0; i < num; i++)
	{
		if (arr[i] == element)
		{
			printf ("Number found at location: %d ", i+1);
			break;
		}
	}
	if ( i == 5 ) printf ("Number entered is not in array");
}
