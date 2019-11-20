#include <stdio.h>

int main()
{
	int Day = 1;
	int Month = 1;
	int Year = 1;
	int Ilosc = 1;
	int Przestepny = 1;
	int YY = 1;
	int C = 1;
	int G = 1;
	int D1s = 1;
	int DzienTygodnia = 1;
	int P = 1;
	int R = 1;
	int Y = 1;
	int Z = 1;
	int LDM = 1;
	int W = 0;
	printf("Podaj rok:");
	scanf_s("%i", &Year);
	if ((Year < 1970) || (Year > 2019))
	{
		printf("Podano niepoprawny rok.\n");
		return 0;
	}
	printf("Podaj miesiac:");
	scanf_s("%i", &Month);
	if ((Month < 1) || (Month > 12))
	{
		printf("Podano niepoprawny miesiac.\n");
		return 0;
	}
	printf("Podaj dzien:");
	scanf_s("%i", &Day);
	if ((Day < 1) || (Day > 31))
	{
		printf("Podano niepoprawny dzien.\n");
		return 0;
	}
	if ((Month == 2) && (Day > 28))
	{
		printf("Podano niepoprawny dzien w miesiacu\n");
		return 0;
	}
	if (((Month == 4) || (Month == 6) || (Month == 9) || (Month == 11)) && (Day > 30))
	{
		printf("Podano niepoprawny dzien w miesiacu\n");
		return 0;
	}
	Przestepny = 0;
	if (Year % 400 == 0)
	{
		printf("Podany rok jest przestepny.\n");
		Przestepny = 1;
	}
	else
		if (Year % 4 == 0)
		{
			printf("Podany rok jest przestepny.\n");
			Przestepny = 1;
		}
		else
		{
			printf("Podany rok nie jest przestepny.\n");
			Przestepny = 0;
		}
	if (Month == 1)
	{
		Ilosc = Day;
	}
	if (Month == 2)
	{
		Ilosc = 31 + Day;
	}
	if (Month == 3)
	{
		Ilosc = 59 + Day;
	}
	if (Month == 4)
	{
		Ilosc = 90 + Day;
	}
	if (Month == 5)
	{
		Ilosc = 119 + Day;
	}
	if (Month == 6)
	{
		Ilosc = 151 + Day;
	}
	if (Month == 7)
	{
		Ilosc = 181 + Day;
	}
	if (Month == 8)
	{
		Ilosc = 212 + Day;
	}
	if (Month == 9)
	{
		Ilosc = 243 + Day;
	}
	if (Month == 10)
	{
		Ilosc = 273 + Day;
	}
	if (Month == 11)
	{
		Ilosc = 304 + Day;
	}
	if (Month == 12)
	{
		Ilosc = 334 + Day;
	}
	if ((Przestepny == 1) && (Month > 2))
	{
		Ilosc = Ilosc + 1;
	}
	YY = (Year - 1) % 100;
	C = (Year - 1) - YY;
	G = YY + YY / 4;
	D1s = (((((C / 100) % 4) * 5) + G) % 7);
	DzienTygodnia = (D1s + Ilosc - 1) % 7;
	if (DzienTygodnia == 0)
	{
		printf("Dzien %02d.%02d.%d to poniedzialek.\n", Day, Month, Year);
	}
	if (DzienTygodnia == 1)
	{
		printf("Dzien %02d.%02d.%d to wtorek.\n", Day, Month, Year);
	}
	if (DzienTygodnia == 2)
	{
		printf("Dzien %02d.%02d.%d to sroda.\n", Day, Month, Year);
	}
	if (DzienTygodnia == 3)
	{
		printf("Dzien %02d.%02d.%d to czwartek.\n", Day, Month, Year);
	}
	if (DzienTygodnia == 4)
	{
		printf("Dzien %02d.%02d.%d to piatek.\n", Day, Month, Year);
	}
	if (DzienTygodnia == 5)
	{
		printf("Dzien %02d.%02d.%d to sobota.\n", Day, Month, Year);
	}
	if (DzienTygodnia == 6)
	{
		printf("Dzien %02d.%02d.%d to niedziela.\n", Day, Month, Year);
	}
	if (Month == 1)
	{
		R = 1;
	}
	if (Month == 2)
	{
		R = 32;
	}
	if (Month == 3)
	{
		R = 60;
	}
	if (Month == 4)
	{
		R = 91;
	}
	if (Month == 5)
	{
		R = 121;
	}
	if (Month == 6)
	{
		R = 152;
	}
	if (Month == 7)
	{
		R = 182;
	}
	if (Month == 8)
	{
		R = 213;
	}
	if (Month == 9)
	{
		R = 244;
	}
	if (Month == 10)
	{
		R = 274;
	}
	if (Month == 11)
	{
		R = 305;
	}
	if (Month == 12)
	{
		R = 335;
	}
	if ((Przestepny == 1) && (Month > 2))
	{
		R = R + 1;
	}
	YY = (Year - 1) % 100;
	C = (Year - 1) - YY;
	G = YY + YY / 4;
	D1s = (((((C / 100) % 4) * 5) + G) % 7);
	P = (D1s + R - 1) % 7;
	printf("Dni od poczatku roku: %d\n", Ilosc);
	if ((Month == 1) || (Month == 3) || (Month == 5) || (Month == 7) || (Month == 8) || (Month == 10) || (Month == 12))
	{
		LDM = 31;
	}
	if ((Month == 4) || (Month == 6) || (Month == 9) || (Month == 11))
	{
		LDM = 30;
	}
	if ((Month == 2) && (Przestepny == 0))
	{
		LDM = 28;
	}
	if ((Month == 2) && (Przestepny == 1))
	{
		LDM = 29;
	}
	printf("Kalendarz na miesiac: %d.%02d\n", Year, Month);
	printf(" Pn  Wt  Sr  Cz  Pt  Sb  Nd\n");
	if (P == 1)
		printf("    ");
	if (P == 2)
		printf("        ");
	if (P == 3)
		printf("            ");
	if (P == 4)
		printf("                 ");
	if (P == 5)
		printf("                     ");
	if (P == 6)
		printf("                        ");
	Y == 1;
	W = P - 1;
	while (Y <= LDM)
	{
		if (Y < 10)
			printf("  %d ", Y);
		if (Y >= 10)
		{
			printf(" %d ", Y);
		}
		++Y;
		if (W % 7 == 5)
		{
			printf("\n");
		}
		++W;

	
	
	}
}
