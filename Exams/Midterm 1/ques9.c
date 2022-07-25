/*
 ============================================================================
 Name        : ques9.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse (char string[],int pos[],int size);
int main(void)
{
	int i,j=0;
	int position[20]={};
	char str[100];
	printf("enter a string of max 99 characters: ");
	fflush(stdout);
	gets(str);
	fflush(stdout);
	fflush(stdin);
	for(i = 0 ; str[i] != '\0' ; i++ )
	{
		if (str[i] == ' ')
		{
			position[j] = i;
			j++;
		}
	}
	reverse(str,position,j);
	printf("%s",str);


	return EXIT_SUCCESS;
}

void reverse (char string[],int pos[],int size)
{
	int m,n,q=0;
	char reversed_str[100];
	for(m=size-1; m >=0 ; m--)
	{
		for(n=pos[m]+1; string[n] != '\0' && string[n] != ' ' ; n++)
		{
			reversed_str[q] = string[n];
			q++;
		}
		reversed_str[q]=' ';
		q++;
	}
	for(n=0; string[n] != '\0' && string[n] != ' ' ; n++)
		{
		reversed_str[q] = string[n];
		q++;
		}
	reversed_str[q] = '\0';                  // ending string
	strcpy(string,reversed_str);             // putting reversed characters in origibal string
}
