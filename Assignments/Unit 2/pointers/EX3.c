
#include <stdio.h>
#include <stdlib.h>
#include "string.h"

int main(void)
{
	char str[100];
	int i;
	printf ("Input a string : ");
	fflush(stdout);
	gets (str);
	char *ptr = &str[strlen(str)-1];
	printf("Reverse of the string is : ");
	for (i=0; i<strlen(str); i++)   printf("%c",*ptr--);




	return EXIT_SUCCESS;
}
