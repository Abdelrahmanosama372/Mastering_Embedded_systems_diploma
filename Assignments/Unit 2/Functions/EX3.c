/*
 ============================================================================
 Name        : EX3.c
 Author      : Abdelrahman osama
 Description : Reverse string using recursion
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "string.h"

void rev(char a[], char rev_str[],int curr_char, int len);

int main(void)
{
	printf("Enter a sentence: ");
	fflush(stdout);
	char sent[100] = "hello world";
	char rev_str[100];
	gets(sent);
	rev(sent, rev_str, 0, strlen(sent));
	
	printf("%s",rev_str);
	return EXIT_SUCCESS;
}

void rev(char a[], char rev_str[],int curr_char, int len)
{
	if(a[curr_char] == 0)
	{
		rev_str[curr_char] = 0;
		return;
	}

	rev(a,rev_str, curr_char+1, len);
	rev_str[len-(curr_char+1)] = a[curr_char];
}
