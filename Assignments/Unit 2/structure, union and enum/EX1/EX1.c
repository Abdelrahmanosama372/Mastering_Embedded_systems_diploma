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

struct Sstudent
{
	char name[50];
	unsigned int roll;
    float marks;
};

int main(void)
{
	struct Sstudent S[100];
	unsigned int i,m;
	unsigned char j;
	for (i=0; i<100; i++)
	{
		printf("Enter information of student%d:\n\n",i+1);
		printf("Enter name: ");
		fflush(stdout);
		fflush(stdin);
		gets(S[i].name);
		printf("Enter roll number: ");
		fflush(stdout);
		fflush(stdin);
		scanf("%d",&S[i].roll);
		printf("Enter marks: ");
		fflush(stdout);
		fflush(stdin);
		scanf("%f",&S[i].marks);
		printf("if you want to end enter e: ");
		fflush(stdout);
		fflush(stdin);
		scanf("%c",&j);
		if(j=='e'||j=='E') break;
	}
	for (m=0; m<=i && m<100; m++)
		{
			printf("\nDisplaying information\n");
			printf("name: %s\n",S[m].name);
			printf("Roll: %d\n",S[m].roll);
			printf("Marks: %.2f\n",S[m].marks);
		}


	return EXIT_SUCCESS;
}
