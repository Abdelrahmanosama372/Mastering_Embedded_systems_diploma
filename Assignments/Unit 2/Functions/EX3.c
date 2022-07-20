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
#include "string.h"

void rev(char a[],int size);

int main(void)
{
	printf("Enter a sentence: ");
	fflush(stdout);
	char sent[100];
	gets(sent);
	rev(sent,strlen(sent));

	return EXIT_SUCCESS;
}

void rev(char a[],int size)
{
	int i,j;
	char b[size+1];
	for (i=0,j=size-1; i<size; i++,j--)
	{
		b[j] = a[i];
	}
	b[size] = '\0';
	printf("%s",b);
}
