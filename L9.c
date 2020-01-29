#include "pch.h"
#include <stdio.h>
#include <stdlib.h>


void fileWrite(int i);
void filePrint(int i);
void fileCheck(int i);


int main()
{
	int pliki = 1;

	for (pliki = 1; pliki < 11; pliki++)
	{
		fileWrite(pliki);
	}
	printf("\n");

	for (pliki = 1; pliki < 11; pliki++)
	{
		printf("\n%d zestaw 100 liczb:\n", pliki);
		filePrint(pliki);
	}
	printf("\n");

	for (pliki = 1; pliki < 11; pliki++)
	{
		fileCheck(pliki);
	}
	printf("\n");

	return 0;
}

void fileWrite(int i)
{
	int j;
	int x;
	char fileName[100];

	sprintf_s(fileName, 100, "plik%d.txt", i);

	FILE* outputFile;
	fopen_s(&outputFile, fileName, "wt");
	if (outputFile == NULL)
	{
		printf("Blad otwarcia pliku %d do zapisu \n", i);
	}
	else
	{
		for (j = 1; j < 101; j++)
		{
			x = rand() % 11;
			fprintf_s(outputFile, "%d\n", x);
		}
		printf("\n");
		fclose(outputFile);
	}
}

void filePrint(int i)
{
	int x;
	int j;
	char fileName[100];

	sprintf_s(fileName, 100, "plik%d.txt", i);
	FILE* outputFile;
	fopen_s(&outputFile, fileName, "r");

	if (outputFile == NULL)
	{
		printf("Blad otwarcia pliku %d do odczytu \n", i);
	}
	else
	{
		for (j = 1; j < 101; j++)
		{
			fscanf_s(outputFile, "%d\n", &x);
			printf("%d\t", x);
		}
		fclose(outputFile);
	}
}

void fileCheck(int i)
{
	int x;
	int j, k;
	int ile_razy, liczba_pop;
	char fileName[100], fileName2[100];
	int tab_liczb[11];
	int tab_rzad[11];

	sprintf_s(fileName2, 100, "results.txt");
	FILE* outputFile2;
	fopen_s(&outputFile2, fileName2, "a+");

	if (outputFile2 == NULL)
	{
		printf("Blad otwarcia pliku wynikow do zapisu \n");
	}
	else
	{
		sprintf_s(fileName, 100, "plik%d.txt", i);
		FILE* outputFile;
		fopen_s(&outputFile, fileName, "r");

		if (outputFile == NULL)
		{
			printf("Blad otwarcia pliku %d do odczytu ", i);
		}
		else
		{
			for (k = 0; k < 11; k++)
			{
				tab_liczb[k] = 0;
				tab_rzad[k] = 0;
			}

			ile_razy = 0;
			for (j = 1; j < 101; j++)
			{
				fscanf_s(outputFile, "%i\n", &x);
				tab_liczb[x] = tab_liczb[x] + 1;
				if (j == 1)
				{
					liczba_pop = x;
					ile_razy = ile_razy + 1;
				}
				else
				{
					if (j == 100)
					{
						if (liczba_pop == x)
						{
						// liczba 100 w pliku taka sama jak liczba 99 w pliku
							ile_razy = ile_razy + 1;
							if (tab_rzad[x] < ile_razy)
								tab_rzad[x] = ile_razy;
						}
						else
						{
						// wpisanie wyniku dla 99 liczby w pliku
							if (tab_rzad[liczba_pop] < ile_razy)
								tab_rzad[liczba_pop] = ile_razy;
						// wpisanie wyniku dla 100 liczby w pliku
							ile_razy = 1;
							if (tab_rzad[x] < ile_razy)
								tab_rzad[x] = ile_razy;
						}
					}
					else
					{
						if (liczba_pop == x)
							ile_razy = ile_razy + 1;
						else
						{
							if (tab_rzad[liczba_pop] < ile_razy)
								tab_rzad[liczba_pop] = ile_razy;
							ile_razy = 1;
							liczba_pop = x;
						}
					}
				}
			}
			fclose(outputFile);
			
			fprintf_s(outputFile2, "%s\n", fileName);
			printf("%s\n", fileName);
			
			for (k = 0; k < 11; k++)
			{
				fprintf_s(outputFile2, "%d\t %d\t %d\n", k, tab_liczb[k], tab_rzad[k]);
				printf("Liczb %d \t jest \t %d \t max ilosc z rzedu \t %d \n", k, tab_liczb[k], tab_rzad[k]);
			}
		}
		fclose(outputFile2);
	}
}

