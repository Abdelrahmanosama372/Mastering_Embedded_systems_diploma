
#include <stdio.h>
#include <stdlib.h>

void reverse (int arr[],int size);

int main(void)
{
	int i,counter=0;
	int num[10];
	printf("if you want to end enter any character\n");
	for(i=0; i<10; i++)
	{
	printf("enter the numbers: ");
	fflush(stdout);
	if(! scanf("%d",&num[i]))      break;
	counter=i;
	}
	reverse(num,counter);

	return EXIT_SUCCESS;

}

void reverse (int arr[],int size)
{
	printf("the values after begin reversed: ");
	fflush(stdout);
	int m,n,temp;
	for (n = 0, m = size ; m!=n ; m--,n++)
	{
		temp=arr[n];
		arr[n]=arr[m];
		arr[m]=temp;
	}
	for (m = 0; m <= size;m++) printf("%d ",arr[m]);
}
