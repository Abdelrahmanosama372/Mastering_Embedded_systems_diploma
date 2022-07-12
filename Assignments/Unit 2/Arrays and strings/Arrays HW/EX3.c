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

int main(void)
{
	int rows, columns, i, j;
	printf ("enter rows and columns of matrix: ");
	fflush (stdout);
	scanf ("%d %d",&rows,&columns);
	float arr[rows][columns], trans[rows][columns];
	for (i=0; i<rows; i++)
	{
		for (j=0; j<columns; j++)
		{
			printf ("enter elements a%d%d : ",i+1,j+1);
			fflush (stdout);
			scanf ("%f",&arr[i][j]);
		}
	}

	printf("Entered matrix: \n");
	for (i=0; i<rows; i++)
		{
			for (j=0; j<columns; j++)
			{
				printf ("%.1f\t",arr[i][j]);
				trans[j][i]=arr[i][j];
			}
			printf ("\n");
		}

	printf("\nTranspose of matrix: \n");
	for (i=0; i<columns; i++)
		{
			for (j=0; j<rows; j++)
			{
				printf ("%.1f\t",trans[i][j]);
			}
			printf ("\n");
		}

}
