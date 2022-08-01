#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int i;
	int elements;
	int arr[15];
	int *ptr=arr;
	printf("Input the number of elements to store in the array (max 15): ");
	fflush(stdout);
	scanf("%d",(int*)&elements);   // casting to avoid warning by compiler
	printf("Input %d number of elements in the array :\n", elements);
	for (i=0; i<elements; i++)
	{
		fflush(stdout);
		fflush(stdin);
		printf("element -%d : ", i+1);
		fflush(stdout);
		fflush(stdin);
		scanf("%d",ptr+i);
		fflush(stdout);
		fflush(stdin);
	}
	printf("The elements of array in reverse order are :\n");
	fflush(stdout);
	for (i=elements-1; i>= 0; i--) printf("element -%d : %d \n",i+1,*(ptr+i));





	return EXIT_SUCCESS;
}
