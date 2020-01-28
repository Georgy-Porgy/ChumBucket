#include <stdlib.h>
#include <stdio.h>

float * czytaj_tab(int ilosc);
void wypisz_tab(float *tab, int ilosc);
float sumuj_tab(float *tab, int ilosc);
float srednia_tab(float *tab, int ilosc);
float min_tab(float *tab, int ilosc);
float max_tab(float *tab, int ilosc);
float * dodaj_tablice(float *tab1, float *tab2, int ilosc);

int main()
{
	int ilosc_tab;
	float wynik;
	
	printf("Podaj liczbe elementow tablicy: ");
	scanf_s("%i", &ilosc_tab);

	float *tab1 = (float *)malloc(sizeof(float) * ilosc_tab);
	printf("Pierwsza tablica \n");
	tab1 = czytaj_tab(ilosc_tab);
	wypisz_tab(tab1, ilosc_tab);

	wynik = sumuj_tab(tab1, ilosc_tab);
	printf("Suma elementow tablicy: \t %f \n", wynik);
	wynik = srednia_tab(tab1, ilosc_tab);
	printf("Srednia z elementow tablicy: \t %f \n", wynik);
	wynik = 0;
	wynik = min_tab(tab1, ilosc_tab);
	printf("Najmniejszy element w tablicy: \t %f \n", wynik);
	wynik = 0;
	wynik = max_tab(tab1, ilosc_tab);
	printf("Najwiekszy element w tablicy: \t %f \n", wynik);
	printf("Druga tablica \n");
	float *tab2 = (float *)malloc(sizeof(float) * ilosc_tab);
	tab2 = czytaj_tab(ilosc_tab);
	wypisz_tab(tab2, ilosc_tab);
	float *tab3 = (float *)malloc(sizeof(float) * ilosc_tab);
	tab3 = dodaj_tablice(tab1, tab2, ilosc_tab);
	printf("\n");
	printf("Tablica sum elementow dwoch tablic \n");
	wypisz_tab(tab3, ilosc_tab);

	free(tab1);
	free(tab2);
	free(tab3);
	return 0;
}

float *czytaj_tab(int ilosc)
{
	float x;
	float *tab = (float *)malloc(sizeof(float) * ilosc);
	printf("Podaj elementy tablicy (%i):", ilosc);
	for (int i = 0; i < ilosc; i++)
	{
		scanf_s("%f", &x);
		tab[i] = x;
	}
	return tab;
}

void wypisz_tab(float *tab, int ilosc)
{
	int i = 0;

	printf("Elementy tablicy:");
	for (i = 0; i < ilosc; i++)
	{
		if (i % 5 == 0)
		{
			printf("\n");
		}
		printf("%f \t", tab[i]);
	}
	printf("\n");
}

float sumuj_tab(float *tab, int ilosc)
{
	float suma = 0;
	for (int i = 0; i < ilosc; i++)
	{
		suma = suma + tab[i];
	}
	return suma;
}

float srednia_tab(float *tab, int ilosc)
{
	float suma;
	suma = sumuj_tab(tab, ilosc);
	return suma / ilosc;
}

float min_tab(float *tab, int ilosc)
{
	float minimum = 0;
	minimum = tab[0];
	for (int i = 1; i < ilosc; i++)
	{
		if (minimum > tab[i])
			minimum = tab[i];
	}
	return minimum;
}

float max_tab(float *tab, int ilosc)
{
	float maximum = 0;
	maximum = tab[0];
	for (int i = 1; i < ilosc; i++)
	{
		if (maximum < tab[i])
			maximum = tab[i];
	}
	return maximum;
}

float *dodaj_tablice(float *tab1, float *tab2, int ilosc)
{
	float *tab3 = (float *)malloc(sizeof(float) * ilosc);
	for (int i = 0; i < ilosc; i++)
		tab3[i] = 0;
	for (int i = 0; i < ilosc; i++)
	{
		tab3[i] = tab1[i] + tab2[i];
	}
	return tab3;
}
