#include <stdio.h>
#include <stdlib.h>

void wypisywanie(float tab[]);
void uzupelnianie(float tab[]);
void sortowanie(float tab[]);
float srednia(float tab[], float a);
float dodawanie(float tab[]);
float minimum(float tab[]);
float maximum(float tab[]);
float mediana(float tab[]);
void suma2(float tab[], float tab2[]);
void reset(float tab[], float tab2[]);

void main()
{
	float tab[] = { 1, 2, 3, 4, 5, 6, 7, 8 , 9, 10 };
	float tab2[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	//uzupelnianie(tab);
	wypisywanie(tab);
	printf("\n\nSuma tablicy to: %g\n", dodawanie(tab));
	printf("\nSrednia tablicy to: %g", srednia(tab, dodawanie(tab)));
	printf("\n\nNajmniejsza wartosc tablicy to: %g", minimum(tab));
	printf("\n\nNajwieksza wartosc tablicy to: %g\n\n", maximum(tab));
	suma2(tab, tab2);
	printf("Po dodaniu - ");
	wypisywanie(tab);
	reset(tab, tab2);
	printf("\n\n");
	printf("Sortowanie - ");
	sortowanie(tab);
	wypisywanie(tab);
	printf("\n\nMediana to: %g\n\n", mediana(tab));
	printf("\n\n");
}

void uzupelnianie(float tab[])
{
	float d;
	for (int i = 0; i < 10; i++)
	{
		printf("Podaj liczbe do tablicy: ");
		scanf_s("%g", &d);
		tab[i] = d;
		system("cls");
	}
}

void wypisywanie(float tab[])
{
	printf("Tablica={");
	for (int i = 0; i < 9; i++)
	{
		printf("%g, ", tab[i]);
	}
	printf("%g}", tab[9]);
}

void sortowanie(float tab[])
{
	for (int i = 0; i < 10 - 1; i++)
	{
		for (int j = 0; j < 10 - 1 - i; j++)
		{
			if (tab[j] > tab[j + 1])
			{
				int temp = tab[j + 1];
				tab[j + 1] = tab[j];
				tab[j] = temp;
			}
		}
	}
}

float dodawanie(float tab[])
{
	float suma = 0;
	for (int i = 0; i < 10; i++)
	{
		suma = suma + tab[i];
	}
	return suma;
}

float srednia(float tab[], float a)
{
	float b = a / 10;
	return b;
}

float minimum(float tab[])
{
	float min = tab[0];
	for (int i = 0; i < 10; i++)
	{
		if (tab[i] < min)
			min = tab[i];
	}
	return min;
}

float maximum(float tab[])
{
	float max = tab[0];
	for (int i = 0; i < 10; i++)
	{
		if (tab[i] > max)
			max = tab[i];
	}
	return max;
}

float mediana(float tab[])
{
	float b = (tab[4] + tab[5]) / 2;
	return b;
}


void suma2(float tab[], float tab2[])
{
	for (int i = 0; i < 10; i++)
	{
		tab[i] += tab2[i];
	}
}

void reset(float tab[], float tab2[])
{
	for (int i = 0; i < 10; i++)
	{
		tab[i] -= tab2[i];
	}
}

