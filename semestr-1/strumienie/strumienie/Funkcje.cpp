#include "Funkcje.h"
#include <ctime>
#include <string>

void zapisz_liczby(ostream& str, const double liczby[], const int N)
{
	for (int i = 0; i < N; i++)
	{
		str << liczby[i] << ' ';
	}
	str << endl;
}

void zapisz_liczby(ostream& str, const vector<double>& liczby)
{
	for (auto liczba : liczby)
	{
		str << liczba << ' ';
	}
	str << endl;
}

void zapisz_losowe(ostream& str)
{
	srand(time(NULL));
	int iloscLiczb = rand() % 500;

	for (int i = 0; i < iloscLiczb; i++)
	{
		str << rand() % 50000 << ' ';
	}

	str << endl;
}

double srednia_liczb(istream& str)
{
	double liczba;
	double srednia = 0;
	int licznik = 0;

	while (str >> liczba)
	{
		srednia += liczba;
		licznik++;
	}

	if (licznik == 0)
	{
		return 0;
	}
	else
	{
		return srednia / licznik;
	}
}

double frobenius(istream& str)
{
	double liczba;
	double norma = 0;

	while (str >> liczba)
	{
		norma += liczba * liczba;
	}

	return norma;
}

void uniq(istream& wejscie, ostream& wyjscie)
{
	int liczba;
	int ostatnia;
	bool pierwsza = true;

	while (wejscie >> liczba)
	{
		if (!pierwsza)
		{
			if (liczba != ostatnia)
			{
				wyjscie << liczba << ' ';
			}
		}
		else
		{
			wyjscie << liczba << ' ';
		}
		pierwsza = false;
		ostatnia = liczba;
	}
	wyjscie << endl;
}

void ile_w_wierszu(istream& wejscie, ostream& wyjscie)
{
	int iloscSpacji = 0;
	string wiersz;

	while (getline(wejscie, wiersz))
	{
		for (int i = 0; i < wiersz.size(); i++)
		{
			if (wiersz[i] == 32)
			{
				iloscSpacji++;
			}
		}
		wyjscie << iloscSpacji + 1 << endl;
		iloscSpacji = 0;
	}
}

void srednia_wiersza(istream& wejscie, ostream& wyjscie)
{
	string wiersz;

	while (getline(wejscie, wiersz))
	{
		string liczba = "";
		int sumaWiersza = 0;
		int iloscLiczb = 0;
		for (int i = 0; i < wiersz.length(); i++)
		{
			if (wiersz[i] != 32)
			{
				liczba.push_back(wiersz[i]);
			}
			if (wiersz[i] == 32)
			{
				iloscLiczb++;
				int liczbaliczba = stoi(liczba);
				sumaWiersza += liczbaliczba;
				liczba = "";
			}
		}
		wyjscie << (double)sumaWiersza / (double)iloscLiczb << endl;
	}
}

void transponuj(istream& wejscie, ostream& wyjscie)
{
	string wiersz;
	vector< vector<double>> macierz;
	vector< vector<double>> transponowana;
	int nrWiersza = 0, nrKolumny = 0;

	while (getline(wejscie, wiersz))
	{
		string liczba = "";

		vector<double> pusty;
		macierz.push_back(pusty);

		for (int i = 0; i < wiersz.length(); i++)
		{
			if (wiersz[i] != 32)
			{
				liczba.push_back(wiersz[i]);
			}
			if (wiersz[i] == 32)
			{
				double liczbaliczba = stod(liczba);
				liczba = "";
				macierz[nrWiersza].push_back(liczbaliczba);
				nrKolumny++;
			}
		}
		nrWiersza++;
	}

	for (int i = 0; i < nrKolumny; i++)
	{
		vector<double> pusty;
		transponowana.push_back(pusty);

		for (int j = 0; j < nrWiersza; j++)
		{
			transponowana[i].push_back(macierz[j][i]);
			wyjscie << macierz[j][i] << " ";
		}
		wyjscie << endl;
	}
}

void pierwsze(istream& wejscie, ostream& wyjscie)
{
	string wiersz;

	while (getline(wejscie, wiersz))
	{
		string slowo = "";

		for (int i = 0; i < wiersz.length(); i++)
		{
			if (wiersz[i] != 32)
			{
				slowo.push_back(wiersz[i]);
			}
			if (wiersz[i] == 32)
			{
				wyjscie << slowo << " ";
				slowo = "";
				break;
			}
		}
	}
}

vector<string> rozdziel(const string& tekst)
{
	vector<string> slowa;
	string slowo = "";

	for (int i = 0; i < tekst.length(); i++)
	{
		if (tekst[i] != 32)
		{
			slowo.push_back(tekst[i]);
		}
		if (tekst[i] == 32 || tekst[i] == 9)
		{
			if (slowo != "")
			{
				slowa.push_back(slowo);
				slowo = "";
			}
		}
	}

	return slowa;
}

vector<int> tworz_histogram(const string& nazwa_pliku)
{
	vector<int> histogram;
	string napis = "";

	for (int i = 0; i < 26; i++)
	{
		histogram.push_back(0);
	}

	ifstream wejscie(nazwa_pliku);
	getline(wejscie, napis);

	for (int i = 0; i < napis.length(); i++)
	{
		if ((napis[i] >= 65 && napis[i] <= 90))
		{
			histogram[napis[i] - 65] += 1;
		}
		else if ((napis[i] >= 97 && napis[i] <= 122))
		{
			histogram[napis[i] - 97] += 1;
		}
	}

	return histogram;
}

void zapisz_histogram(const vector<int>& histogram, const string& nazwa_pliku, int maksimum)
{
	ofstream wyjscie(nazwa_pliku);
	int najwieksza = 0;
	int wartoscNajwiekszej = 0;

	for (int i = 0; i < histogram.size(); i++)
	{
		if (histogram[i] > wartoscNajwiekszej)
		{
			wartoscNajwiekszej = histogram[i];
			najwieksza = i;
		}
	}

	double proporcja = (double)maksimum / wartoscNajwiekszej;

	for (int i = 0; i < histogram.size(); i++)
	{
		double iloscGwiazdek = proporcja * histogram[i];
		wyjscie << (char)(i + 65) << ' ' << histogram[i] << ' ';

		for (int j = 0; j < iloscGwiazdek; j++)
		{
			wyjscie << "*";
		}
		wyjscie << endl;
	}
}