#include <stdio.h>
#include <stdlib.h>

struct employee
{
	char Name[50];
	char id[10];
};
int main(void)
{
	int i;
	struct employee emp1 = {"Alex","1002"};
	struct employee emp2 = {"hany","1003"};
	struct employee emp3 = {"alaa","1004"};
	struct employee *emp_arr[]= {&emp1,&emp2,&emp3};
	struct employee *(*ptr_to_arr_of_str_ptr)[3] = &emp_arr;

	for(i = 0; i < sizeof(emp_arr)/sizeof(emp_arr[0]); i++ )
	{
		printf("Employee Name: %s\nEmployee ID: %s\n",\
				(*(*ptr_to_arr_of_str_ptr+i)) -> Name , \
				(*(*ptr_to_arr_of_str_ptr+i)) -> id);         // -> have higher priority than *
	}

	return EXIT_SUCCESS;
}
