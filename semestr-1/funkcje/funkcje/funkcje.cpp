#include <iostream>
#include <vector>
using namespace std;

//Przeciazenia wypisan

void Wypisz(double tab[], int rozmiar)
{
	for (int i = 0; i < rozmiar; i++)
	{
		cout << tab[i] << ' ';
	}
	cout << endl;
}

void Wypisz(unsigned int tab[], int rozmiar)
{
	for (int i = 0; i < rozmiar; i++)
	{
		cout << tab[i] << ' ';
	}
	cout << endl;
}

void Wypisz(int tab[], int N)
{
	for (int i = 0; i < N; i++)
	{
		cout << tab[i] << ' ';
	}
	cout << endl;
}

void Wypisz(vector<double> liczby)
{
	for (int i = 0; i < liczby.size(); i++)
	{
		cout << liczby[i] << ' ';
	}
	cout << endl;
}

void Wypisz(vector<int> liczby)
{
	for (int i = 0; i < liczby.size(); i++)
	{
		cout << liczby[i] << ' ';
	}
	cout << endl;
}

//Koniec przeciazen

double Zadanie1(double x1, double x2, double x3, double x4, double x5)
{
	double min = x1;

	if (x2 < min)
	{
		min = x2;
	}
	if (x3 < min)
	{
		min = x3;
	}
	if (x4 < min)
	{
		min = x4;
	}
	if (x5 < min)
	{
		min = x5;
	}

	return min;
}

double Zadanie2(double tab[], int rozmiar)
{
	double min = tab[0];

	for (int i = 1; i < rozmiar; i++)
	{
		if (tab[i] < min)
		{
			min = tab[i];
		}
	}

	return min;
}

void Zadanie3(double tab[], int rozmiar)
{
	for (int i = 0; i <= rozmiar / 2; i++)
	{
		swap(tab[i], tab[rozmiar - 1 - i]);
	}
}

int Zadanie4(int tab[], int rozmiar)
{
	int licznik = 0;

	for (int i = 0; i < rozmiar; i++)
	{
		if (tab[i] % 2 == 0)
		{
			licznik++;
		}
	}

	return licznik;
}

void Zadanie5(unsigned int tab[], int rozmiar, unsigned int m)
{
	for (int i = 0; i < rozmiar; i++)
	{
		tab[i] %= m;
	}
}

void Zadanie6(vector<double>& liczby)
{
	for (int i = 0; i <= liczby.size() / 2; i++)
	{
		swap(liczby[i], liczby[liczby.size() - 1 - i]);
	}
}

vector<int> Zadanie7(vector<int> v1, vector<int> v2)
{
	int i1 = 0, i2 = 0;
	vector <int> v3;
	while (i1 < v1.size() || i2 < v2.size())
	{
		if (i1 == v1.size())
		{
			v3.push_back(v2[i2++]);
		}
		else if (i2 == v2.size())
		{
			v3.push_back(v1[i1++]);
		}
		else if (v1[i1] < v2[i2])
		{
			v3.push_back(v1[i1++]);
		}
		else
		{
			v3.push_back(v2[i2++]);
		}
	}
	return v3;
}

vector<int> Zadanie8(vector<int> v1, vector<int> v2)
{
	vector<int> v3;
	for (int i = 0; i < v1.size(); i++)
	{
		bool czy = true;
		for (int j = 0; j < v2.size(); j++)
		{
			if (v2[j] == v1[i])
			{
				czy = false;
			}
		}
		if (czy)
		{
			v3.push_back(v1[i]);
		}
	}

	return v3;
}

vector<int> Zadanie9(const int N)
{
	vector<int> pierwsze;
	int liczba = 2;

	while (pierwsze.size() < N)
	{
		bool czy = true;
		for (int i = 2; i <= sqrt(liczba); i++)
		{
			if (liczba % i == 0)
			{
				czy = false;
				break;
			}
		}
		if (czy)
		{
			pierwsze.push_back(liczba);
		}
		liczba++;
	}

	return pierwsze;
}

int Zadanie10(int a, int b)
{
	while (a != b)
	{
		if (a > b)
		{
			a -= b;
		}
		else
		{
			b -= a;
		}
	}
	return a;
}

vector<int> Zadanie11(int a)
{
	vector<int> dzielniki;
	int dzielnik = 2;
	while (a != 1)
	{
		if (a % dzielnik == 0)
		{
			a /= dzielnik;
			dzielniki.push_back(dzielnik);
		}
		else
		{
			dzielnik++;
		}
	}

	return dzielniki;
}

double Zadanie12(int tab[], int k)
{
	double wartosc = (double)tab[k];
	for (int i = k - 1; i >= 0; i--)
	{
		wartosc = (1 / wartosc) + tab[i];
	}
	return wartosc;
}

//Niemozliwe do wykonania gdyz liczby zmiennoprzecinkowe sa jedynie przyblizeniami
void Zadanie13(double r)
{
}

void Zadanie14(int tab[])
{
	const int N = 6;
	int tab2[N]{};

	for (int i = 0; i < N; i++)
	{
		int licznik = 0;

		for (int j = 0; j < i; j++)
		{
			if (tab[j] < tab[i])
			{
				licznik++;
			}
		}
		tab2[i] += licznik;
	}

	Wypisz(tab2, N);
}

//Niemozliwe do wykonania gdyz w jezyku C++ nie da sie zwrocic tablicy (a musimy jakos sprawdzic poprawnosc uzywajac funkcji Zadanie14)
void Zadanie15(int tab[])
{
}

int main()
{
	double Tab[]{ 5.3 , 6.2, 2.0, -12.7, 0 };
	int Tab2[]{ 5,6,2,-12,0 };
	unsigned int Tab3[]{ 5,6,2,12,0 };
	int Tab4[]{ 2,1,1,1 };
	int Tab5[]{ 1,2,3,4,5,6 };
	vector<double> Vec = { 5.3 , 6.2, 2.0, -12.7, 0 };
	vector<int> Vec2 = { 1, 2, 3, 4, 5 };
	vector<int> Vec3 = { 6, 7, 8, 9 };

	cout << "Zadanie1: " << Zadanie1(5.3, 6.2, 2.0, -12.7, 0) << endl;
	cout << "Zadanie2: " << Zadanie2(Tab, 5) << endl;
	cout << "Zadanie3: ";
	Zadanie3(Tab, 5);
	Wypisz(Tab, 5);
	cout << "Zadanie4: " << Zadanie4(Tab2, 5) << endl;
	cout << "Zadanie5: ";
	Zadanie5(Tab3, 5, 7);
	Wypisz(Tab3, 5);
	cout << "Zadanie6: ";
	Zadanie6(Vec);
	Wypisz(Vec);
	cout << "Zadanie7: ";
	Wypisz(Zadanie7(Vec2, Vec3));
	cout << "Zadanie8: ";
	Wypisz(Zadanie8(Vec2, Vec3));
	cout << "Zadanie9: ";
	Wypisz(Zadanie9(20));
	cout << "Zadanie10: " << Zadanie10(12, 8) << endl;
	cout << "Zadanie11: ";
	Wypisz(Zadanie11(126));
	cout << "Zadanie12: " << Zadanie12(Tab4, 3) << endl;
	cout << "Zadanie13: niemozliwe - zobacz komentarz" << endl;
	cout << "Zadanie14: ";
	Zadanie14(Tab5);
	cout << "Zadanie15: niemozliwe - zobacz komentarz" << endl;

	return 0;
}