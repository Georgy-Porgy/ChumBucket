#include <stdio.h>
int get_value(int lower, int upper);
int czy_przestepny(int Year);
int wypisz_dzien_tygodnia(int dzientygodnia);
int ilosc_dni_miesiaca(int month, int year);
int wyswietl_kalendarz(int month, int year, int dnimiesiaca, int dzientygodniamiesiac);
int wylicz_dni(int day, int month, int year);
int main(void)
{
	int C = 0;
	int YY = 0;
	int G = 0;
	int dzientygodnia = 0;
	int dzienpoczatekroku = 0;
	int dnimiesiaca = 0;
	int dzientygodniamiesiac = 0;

	printf("Podaj dzien: ");
	int Day = get_value(1, 31);
	if (Day < 1)
		return 0;

	printf("Podaj miesiac:");
	int Month = get_value(1, 12);
	if (Month < 1)
		return 0;

	printf("Podaj rok:");
	int Year = get_value(1970, -1);
	if (Year < 1)
		return 0;

	int rokprzestepny = czy_przestepny(Year);

	if (rokprzestepny == 1)
		printf("Podany rok %i jest przestepny \n", Year);
	else
		printf("Podany rok %i nie jest przestepny \n", Year);

	YY = (Year - 1) % 100;
	C = (Year - 1) - YY;
	G = YY + YY / 4;
	dzienpoczatekroku = (((((C / 100) % 4) * 5) + G) % 7);

	int Ilosc = wylicz_dni(Day, Month, Year);
	int iloscMiesiac = wylicz_dni(1, Month, Year);
	printf("Dni od poczatku roku: %i\n", Ilosc);

	dzientygodnia = (dzienpoczatekroku + Ilosc - 1) % 7;

	dzientygodniamiesiac = (dzienpoczatekroku + iloscMiesiac - 1) % 7;
	printf("Dzien tygodnia dla 01.%d.%d to ", Month, Year);
	int wypisz = wypisz_dzien_tygodnia(dzientygodniamiesiac);
	printf("\n");

	printf("Podany dzien tygodnia %i.%i.%i to ", Day, Month, Year);
	wypisz = wypisz_dzien_tygodnia(dzientygodnia);
	printf("\n");

	dnimiesiaca = ilosc_dni_miesiaca(Month, Year);
	printf("\n");
	printf("Kalendarz na miesiac %i.%i \n", Month, Year);
	printf("Pn  Wt  Sr  Cz  Pt  So  Nd \n");
	int wyswietl = wyswietl_kalendarz(Month, Year, dnimiesiaca, dzientygodniamiesiac);
}



int get_value(int lower, int upper)
{
	int x = 0;
	scanf_s("%d", &x);
	if (x < lower)
	{
		printf("Podano niepoprawna wartosc\n");
		x = 0;
		return x;
	}
	if (upper == -1)
		return x;
	if (x > upper)
	{
		printf("Podano niepoprawna wartosc\n");
		x = 0;
		return x;
	}
	return x;
}
int czy_przestepny(int Year)
{
	int rokprzestepny = 0;
	if (((Year % 4 == 0) && (Year % 100 != 0)) || (Year % 400 == 0))
	{
		rokprzestepny = 1;
	}
	else
	{
		rokprzestepny = 0;
	}
	return rokprzestepny;
}
int wypisz_dzien_tygodnia(int dzientygodnia)
{
	if (dzientygodnia == 0)
		printf("poniedzialek.");
	if (dzientygodnia == 1)
		printf("wtorek.");
	if (dzientygodnia == 2)
		printf("sroda.");
	if (dzientygodnia == 3)
		printf("czwartek.");
	if (dzientygodnia == 4)
		printf("piatek.");
	if (dzientygodnia == 5)
		printf("sobota.");
	if (dzientygodnia == 6)
		printf("niedziela.");
	return 0;
}
int ilosc_dni_miesiaca(int month, int year)
{
	int dnimiesiaca;
	int rokprzestepny = czy_przestepny(year);
	dnimiesiaca = 31;
	if ((month == 4) || (month == 6) || (month == 9) || (month == 11))
	{
		dnimiesiaca = 30;
	}
	if (month == 2)
	{
		dnimiesiaca = 28;
		if (rokprzestepny == 1)
		{
			dnimiesiaca = 29;
		}
	}
	return dnimiesiaca;
}
int wyswietl_kalendarz(int month, int year, int dnimiesiaca, int dzientygodniamiesiac)
{
	int x = 0;
	int y;
	if (dzientygodniamiesiac != 0)
	{
		while (x < dzientygodniamiesiac)
		{
			printf("    ");
			x = x + 1;
		}
	}
	y = 1;
	while (y <= dnimiesiaca)
	{
		if (y < 10)
			printf(" %i  ", y);
		else
			printf("%i  ", y);
		y = y + 1;
		x = x + 1;
		if (x % 7 == 0)
		{

			printf("\n");
			x = 0;
		}
	}
	return 0;
}
int wylicz_dni(int day, int month, int year)
{
	int Ilosc = 0;
	int iloscMiesiac = 0;
	if (month == 1)
	{
		Ilosc = day;
		iloscMiesiac = 1;
	}
	if (month == 2)
	{
		Ilosc = 31 + day;
		iloscMiesiac = 31 + 1;
	}
	if (month == 3)
	{
		Ilosc = 59 + day;
		iloscMiesiac = 59 + 1;
	}
	if (month == 4)
	{
		Ilosc = 90 + day;
		iloscMiesiac = 90 + 1;
	}
	if (month == 5)
	{
		Ilosc = 120 + day;
		iloscMiesiac = 120 + 1;
	}
	if (month == 6)
	{
		Ilosc = 151 + day;
		iloscMiesiac = 151 + 1;
	}
	if (month == 7)
	{
		Ilosc = 181 + day;
		iloscMiesiac = 181 + 1;
	}
	if (month == 8)
	{
		Ilosc = 212 + day;
		iloscMiesiac = 212 + 1;
	}
	if (month == 9)
	{
		Ilosc = 243 + day;
		iloscMiesiac = 243 + 1;
	}
	if (month == 10)
	{
		Ilosc = 273 + day;
		iloscMiesiac = 273 + 1;
	}
	if (month == 11)
	{
		Ilosc = 304 + day;
		iloscMiesiac = 304 + 1;
	}
	if (month == 12)
	{
		Ilosc = 334 + day;
		iloscMiesiac = 334 + 1;
	}
	int rokprzestepny = czy_przestepny(year);
	if ((rokprzestepny == 1) && (month > 2))
	{
		Ilosc = Ilosc + 1;
		iloscMiesiac = iloscMiesiac + 1;
	}
	return Ilosc;
}


