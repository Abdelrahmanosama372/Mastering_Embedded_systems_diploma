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
	struct Sstudent S[10];
	unsigned int i;
	for (i=0; i<10; i++)
	{
		printf("Enter information of student:\n\n");
		S[i].roll = i+1;
		printf("for roll number %d:\n",S[i].roll);
		printf("Enter name: ");
		fflush(stdout);
		fflush(stdin);
		gets(S[i].name);
		printf("Enter marks: ");
		fflush(stdout);
		fflush(stdin);
		scanf("%f",&S[i].marks);
	}
	for (i=0; i<10; i++)
		{
			printf("\nDisplaying information\n");
			printf("information for roll number %d:\n",i+1);
			printf("name: %s\n",S[i].name);
			printf("Marks: %.2f\n",S[i].marks);
		}


	return EXIT_SUCCESS;
}
