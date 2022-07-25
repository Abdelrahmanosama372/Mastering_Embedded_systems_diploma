

#include <stdio.h>
#include <stdlib.h>

void reverse (int val);

int main(void)
{
	int num;
	printf("enter the number: ");
	fflush(stdout);
	scanf("%d",&num);
	reverse(num);

	return EXIT_SUCCESS;
}

void reverse (int val)
{
	printf("the reverse of the number is: ");
	while(val != 0)
	{
		printf("%d",val%10);
		val/=10;
	}
}
