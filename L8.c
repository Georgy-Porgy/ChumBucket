#include <stdio.h>
#include <stdlib.h>

/*float uzupelnianie()
{

	float* values;
	int rozmiar_tablicy;
	float d;
	printf("Podaj rozmiar tablicy\n");
	scanf_s("%d", &rozmiar_tablicy);

	values = (float*)malloc(sizeof(int) * rozmiar_tablicy);
	for (int i = 0; i < rozmiar_tablicy; i++)
	{
		printf("Podaj liczbe:\n");
		scanf_s("%f", &d);
		values[i] = d;
	}
	for (int i = 0; i < rozmiar_tablicy; i++)
		printf("value[%d] = %g\n", i, values[i]);
	free(values);
}*/

int rozmiar_tablicy();
void uzupelnianie(int r, float *values);
void wypisywanie(float* values, int r);
float dodawanie(float* values, int r);
float srednia(float* values, float a, int r);
float minimum(float* values, int r);
float maximum(float* values, int r);
void sortowanie(float* values, int r);
void suma2(float* values, float tab2[], int r);
void reset(float* values, float tab2[], int r);

void main()
{
	float *values;
	int r_tablica = rozmiar_tablicy();
	float tab2[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	//printf("Tablica ma rozmiar: %d\n", r_tablica);
	values = (float*)malloc(sizeof(int) * r_tablica);
	uzupelnianie(r_tablica, values);
	wypisywanie(values, r_tablica);
	printf("\n\nSuma tablicy to: %g\n", dodawanie(values, r_tablica));
	printf("\nSrednia tablicy to: %g", srednia(values, dodawanie(values, r_tablica), r_tablica));
	printf("\n\nNajmniejsza wartosc tablicy to: %g", minimum(values, r_tablica));
	printf("\n\nNajwieksza wartosc tablicy to: %g\n\n", maximum(values, r_tablica));
	suma2(values, tab2, r_tablica);
	printf("Po dodaniu - ");
	wypisywanie(values, r_tablica);
	reset(values, tab2, r_tablica);
	printf("\n\nSortowanie - ");
	sortowanie(values, r_tablica);
	wypisywanie(values, r_tablica);
	printf("\n\n");
	// Ewntualna mediana

}

int rozmiar_tablicy()
{
	int tablica;
	printf("Podaj rozmiar tablicy: \n");
	scanf_s("%d", &tablica);
	system("cls");
	return tablica;
}

void uzupelnianie(int r, float *values)
{
	float d;
	for (int i = 0; i < r; i++)
	{
		printf("Podaj liczbe:\n");
		scanf_s("%f", &d);
		values[i] = d;
		system("cls");
	}
}

void wypisywanie(float* values, int r)
{
	printf("Tablica={");
	for (int i = 0; i < r; i++)
	{
		printf("%g, ", values[i]);
	}
	printf("}");
}

float dodawanie(float* values, int r)
{
	float suma = 0;
	for (int i = 0; i < r; i++)
	{
		suma = suma + values[i];
	}
	return suma;
}

float srednia(float* values, float a, int r)
{
	float b = a / r;
	return b;
}

float minimum(float* values, int r)
{
	float min = values[0];
	for (int i = 0; i < r; i++)
	{
		if (values[i] < min)
			min = values[i];
	}
	return min;
}

float maximum(float* values, int r)
{
	float max = values[0];
	for (int i = 0; i < r; i++)
	{
		if (values[i] > max)
			max = values[i];
	}
	return max;
}

void sortowanie(float* values, int r)
{
	for (int i = 0; i < r - 1; i++)
	{
		for (int j = 0; j < r - 1 - i; j++)
		{
			if (values[j] > values[j + 1])
			{
				float temp = values[j + 1];
				values[j + 1] = values[j];
				values[j] = temp;
			}
		}
	}
}

void suma2(float* values, float tab2[], int r)
{
	for (int i = 0; i < r; i++)
	{
		values[i] += tab2[i];
	}
}

void reset(float* values, float tab2[], int r)
{
	for (int i = 0; i < r; i++)
	{
		values[i] -= tab2[i];
	}
}



