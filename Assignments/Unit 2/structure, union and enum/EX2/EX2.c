/*
 ============================================================================
 Name        : EX2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

struct Sdistance
{
	int feet;
	float inch;
};

struct Sdistance add_distance (struct Sdistance, struct Sdistance);

int main(void)
{
	struct Sdistance D1, D2, total_dis;
	printf("enter the information of 1st distance\n");
	printf("enter feet: ");
    fflush(stdout);
	scanf("%d",&D1.feet);
	printf("enter inch: ");
	fflush(stdout);
	scanf("%f",&D1.inch);
	printf("enter the information of 2nd distance\n");
	printf("enter feet: ");
    fflush(stdout);
	scanf("%d",&D2.feet);
	printf("enter inch: ");
	fflush(stdout);
	scanf("%f",&D2.inch);
	total_dis=add_distance (D1,D2);
	printf("sum of distances=%d'-%.1f\"",total_dis.feet,total_dis.inch);
}

struct Sdistance add_distance (struct Sdistance d1, struct Sdistance d2)
	{
		struct Sdistance total_dis;
		total_dis.feet = d1.feet + d2.feet;
		total_dis.inch = d1.inch + d2.inch;
		if (total_dis.inch >=12)
		{
			total_dis.feet+=1;
			total_dis.inch-=12;
		}
		return total_dis;
	}
