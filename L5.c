#include "stdio.h"
#include "math.h"

double sub(double a, double b)
{
	double wyn = a - b;
	return wyn;


}
double add(double a, double b)
{
	double wyn = a + b;
	return wyn;
}
double  mul(double a, double b)
{
	double wyn = a * b;
	return wyn;
}
double div(double a, double b)
{
	double wyn = a / b;
	return wyn;
}
void kalk(int typ, double x, double z)
{

	if (typ == 1)
	{
		printf("\n%g + %g = %g\n", x, z, add(x, z));
	}
	if (typ == 2)
	{
		printf("\n%g - %g= %g\n", x, z, sub(x, z));
	}
	if (typ == 3)
	{
		printf("\n%g * %g= %g\n", x, z, mul(x, z));
	}

	if (typ == 4)
	{
		printf("\n%g / %g= %g\n", x, z, div(x, z));
	}
	if (typ == 5)
	{
		printf("\nsin(%g) = (%g)\n", x, sin(x / 57.29577951308));
	}
	if (typ == 6)
	{
		printf("\ncos(%g) = %g\n", x, cos(x / 57.29577951308));
	}

}

int main(int type, double a, double b)
{
	for (;;)
	{

		do
		{
			printf("\n\n Set equation type\n '1' - addition (a+b)\n '2' - substraction (a-b)\n '3' - multiplication (a*b)\n '4' - division (a/b)\n '5' - sine of an angle (sin(a))\n '6' - cosine of an angle (cos(a))\n  ");
			scanf_s("%d", &type);

		} while (type < 0 or type > 7);
		do
		{

			if (type == 1 || type == 2 || type == 3 || type == 4)
			{
				printf("Input a\n");
				scanf_s("%lf", &a);
				printf("Input b\n");
				scanf_s("%lf", &b);
				kalk(type, a, b);
				int type = 0;
			}
			if (type == 5 || type == 6)
			{
				printf("Input angle\n");
				scanf_s("%lf", &a);
				kalk(type, a, 0);
				int type = 0;
			}
		}

		while (type == 9);
	}

}
