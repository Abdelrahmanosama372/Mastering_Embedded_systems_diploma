/*
 ============================================================================
 Name        : ques6.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int check (int arr[], int counter, int val);
int inc;
int main(void)
{
	    int i,counter=0;
		int num[10];
		printf("if you want to end enter any character\n");
		for(i=0; i<10; i++)
		{
		printf("enter the number: ");
		fflush(stdout);
		counter = i;
		if(!scanf("%d",&num[i])) break;
		}
		printf("the unique number is %d",check(num,counter,num[inc]));

	return EXIT_SUCCESS;
}

int check (int arr[], int counter,int val)
{
	int i,m,j=0;
	for (i=0; i<=counter; i++)
	{
		if(val == arr[i])   j++;
	}
	inc++;
	if(j != 1)  return check(arr,counter,arr[inc]);
	else        return val;

}
