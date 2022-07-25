#include <stdio.h>
#include <stdlib.h>

void prime (int x, int y);

int main(void)
{
	int num1,num2;
	printf("enter two number:");
	fflush(stdout);
	fflush(stdin);
	scanf("%d %d",&num1,&num2);
	prime(num1,num2);
	return EXIT_SUCCESS;
}

void prime (int x, int y)
{

	int i,j,counter=0;
	printf("the prime numbers between %d and %d are: ",x,y);
	fflush(stdout);
	for (i=x;i<=y;i++)
	{
		for(j=2;j<=i;j++)
		{
			if(i%j == 0 ) counter++;
		}
		if(counter == 1 || i == 1)  printf("%d ",i);
		counter = 0;
	}

}
