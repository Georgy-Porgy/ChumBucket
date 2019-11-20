#include "stdio.h"

void tab(int t[])
{
	int j = 0;
	for (int i = 0; i < 10; i++)
	{
		j++;
		printf("\n");


		for (int x = 0; x < 10; x++)
			if (t[x] >= j)
			{
				printf("#");
			}
			else if (t[x] < j)
			{
				printf(" ");
			}
	}
}
int main(void)
{
	int t1[10] = { 1, 2, 3, 1, 2, 3, 5, 5, 4, 5 };
	int t2[] = { 1, 2, 3, 4, 5 };
	int t3[5] = { 1, 2, 3, 4, 5 };
	tab(t1);
	tab(t2);
	tab(t3);
}
