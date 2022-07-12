/*
 ============================================================================
 Name        : EX1.c
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
	int i,j;
	float matrix_1 [2][2], matrix_2 [2][2];
	printf("Enter elements of 1st matrix:\n");
	for (i=0; i<2; i++)
	{
		for (j=0; j<2; j++)
		{
			printf ("Enter a%d%d: ",i+1,j+1);
			fflush (stdout);
			scanf ("%f",&matrix_1[i][j]);
		}
	}

	printf("Enter elements of 2nd matrix:\n");
	for (i=0; i<2; i++)
	{
		for (j=0; j<2; j++)
		{
			printf ("Enter b%d%d: ",i+1,j+1);
			fflush (stdout);
			scanf ("%f",&matrix_2[i][j]);
		}
	}

	printf ("sum of Matrix:\n");
	for (i=0; i<2; i++)
		{
			for (j=0; j<2; j++)
			{
				printf ("%.1f\t",matrix_1[i][j]+matrix_2[i][j]);
			}
			printf("\n");
		}



}
