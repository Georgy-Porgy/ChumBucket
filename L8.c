#include "pch.h"
#include <stdlib.h>
#include <stdio.h>
#define VALUES_SIZE 10

void foo()
{
	int*values;
	values = (int *)malloc(sizeof(int)*VALUES_SIZE);
	for (int i = 0; i < VALUES_SIZE; i++)
	{
		values[i] = i * 2;
		*(values + i) += 3;
	}
	for (int i = 0; i < VALUES_SIZE; i++)
		printf("value[%d] = %d\n", i, values[i]);
	free(values);
}



int main(void)
{
     
	}


