#include <stdio.h>
#include <stdlib.h>

int counter(int val);

int main(void)
{
	int num;
	printf("enter the number: ");
	fflush(stdout);
	scanf("%d",&num);
	printf("max number of successive 1's is %d",counter(num));
	return EXIT_SUCCESS;
}

int counter(int val)
{
	int count=0,max_count=0;
	while(val != 0)
	{
			while((val | 1) == val)
			{
				count++;
				val>>=1;
			}
	val>>=1;
	max_count= count > max_count ?  count:max_count;
	count = 0;
	}
	return max_count;
}
