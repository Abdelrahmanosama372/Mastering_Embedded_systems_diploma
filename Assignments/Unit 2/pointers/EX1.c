#include <stdio.h>
#include <stdlib.h>

#define pointer_loc_assign(var,ptr) \
	            printf("Now %s is assigned with the address of %s\n",#ptr,#var);\
				printf("Address of pointer %s : %p\nContent of pointer %s : %d\n\n", #ptr,ptr,#ptr,*ptr)

#define var_Assign(var,ptr) \
	            printf("The value of %s assigned to %d now\n",#var,var);\
				printf("Address of pointer %s : %p\nContent of pointer %s : %d\n\n", #ptr,ptr,#ptr,*ptr)

#define pointer_Assign(var,ptr) \
	            printf("The pointer variable %s is assigned with the value %d now\n",#ptr,*ptr);\
				printf("Address of %s : %p\nvalue of %s : %d\n\n", #var,&var,#var,var)

#define var_status(var) \
	            printf("Address of %s : %p\nvalue of %s : %d\n\n", #var,&var,#var,var)

int main(void)
{
	int m = 29;
	var_status(m);

	int *ab = &m;
	pointer_loc_assign(m,ab);

	m = 34;
	var_Assign(m,ab);

	*ab = 7;
	pointer_Assign(m,ab);



	return EXIT_SUCCESS;
}
