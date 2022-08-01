#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int i;
	char x = 65;
	char *ptr =  &x;
	for (i=0; i<26; i++) printf("%c ",(*ptr)++);


	return EXIT_SUCCESS;
}
