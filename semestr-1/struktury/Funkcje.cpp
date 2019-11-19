#include "Funkcje.h"
#include <cmath>
#include <ctime>

// Sekcja 1

double odleglosc(const punkt& a, const punkt& b)
{
	return sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2) + pow(b.z - a.z, 2));
}

vector <punkt> wylosuj_punkty(const int N)
{
	vector<punkt> punkty;
	srand(time(NULL));
	for (int i = 0; i < N; i++)
	{
		punkt x{ rand(),rand(),rand() };
		punkty.push_back(x);
	}

	return punkty;
}

pair<punkt, punkt> najdalsze_punkty(const vector<punkt>& chmura)
{
	pair<punkt, punkt> najdalsze;
	double maxOdleglosc = 0;

	for (int i = 0; i < chmura.size() - 1; i++)
	{
		for (int j = i + 1; j < chmura.size(); j++)
		{
			double odl = odleglosc(chmura[i], chmura[j]);
			if (odl > maxOdleglosc)
			{
				maxOdleglosc = odl;
				najdalsze.first = chmura[i];
				najdalsze.second = chmura[j];
			}
		}
	}

	return najdalsze;
}

bool wspolliniowe(const punkt& a, const punkt& b, const punkt& c)
{
	return (odleglosc(a, b) == odleglosc(a, b) + odleglosc(b, c)) || (abs(odleglosc(a, b) - odleglosc(b, c))) == odleglosc(a, c) ? true : false;
}

void wypisz(ostream& str, const punkt& a)
{
	str << a.x << " " << a.y << " " << a.z << endl;
}

void wypisz(ostream& str, const vector<punkt>& a)
{
	for (punkt p : a)
	{
		str << p.x << " " << p.y << " " << p.z << endl;
	}
}

//W pliku jest ewidentnie bool
bool pole_trojkata(const punkt& a, const punkt& b, const punkt& c)
{
	return true; // ka¿dy trójk¹t ma pole
}

//Niestety, wykracza poza nasza znajomosc algebry liniowej :):
double najmniejsze_pole_trojkata(const vector<punkt>& chmura)
{
	return 0;
}

//j.w.
double kat(const punkt& a, const punkt& b, const punkt& c)
{
	return 0;
}

//j.w.
double odleglosc(const punkt& a, const punkt& b, const punkt& c, const punkt& z)
{
	return 0;
}

// Sekcja 2

vector<karta> utworz_talie_brydz()
{
	vector<karta> talia;
	vector<kolor> kolory{ kolor::pik,kolor::kier,kolor::karo,kolor::trefl };
	vector<wartosc> wartosci{ wartosc::as, wartosc::krol, wartosc::dama, wartosc::walet, wartosc::dziesiatka, wartosc::dziewiatka, wartosc::osemka,
		wartosc::siodemka, wartosc::szostka, wartosc::piatka, wartosc::czworka, wartosc::trojka, wartosc::dwojka };

	for (int i = 0; i < kolory.size(); i++)
	{
		for (int j = 0; j < wartosci.size(); j++)
		{
			karta k;
			k._kolor = kolory[i];
			k._wartosc = wartosci[j];
			talia.push_back(k);
		}
	}

	return talia;
}

vector<karta> utworz_talie_skat()
{
	vector<karta> talia;
	vector<kolor> kolory{ kolor::pik,kolor::kier,kolor::karo,kolor::trefl };
	vector<wartosc> wartosci{ wartosc::as, wartosc::krol, wartosc::dama, wartosc::walet, wartosc::dziesiatka, wartosc::dziewiatka, wartosc::osemka,
		wartosc::siodemka };

	for (int i = 0; i < kolory.size(); i++)
	{
		for (int j = 0; j < wartosci.size(); j++)
		{
			karta k;
			k._kolor = kolory[i];
			k._wartosc = wartosci[j];
			talia.push_back(k);
		}
	}

	return talia;
}

vector<karta> utworz_talie_tysiac()
{
	vector<karta> talia;
	vector<kolor> kolory{ kolor::pik,kolor::kier,kolor::karo,kolor::trefl };
	vector<wartosc> wartosci{ wartosc::as, wartosc::krol, wartosc::dama, wartosc::walet, wartosc::dziesiatka, wartosc::dziewiatka };

	for (int i = 0; i < kolory.size(); i++)
	{
		for (int j = 0; j < wartosci.size(); j++)
		{
			karta k;
			k._kolor = kolory[i];
			k._wartosc = wartosci[j];
			talia.push_back(k);
		}
	}

	return talia;
}

vector<karta> potasuj(const vector<karta>& talia)
{
	srand(time(NULL));
	vector<karta> potasowanaTalia;
	vector<int> indeksy;

	for (int i = 0; i < talia.size(); i++)
	{
		indeksy.push_back(0);
	}

	for (int i = 0; i < talia.size(); i++)
	{
		bool contains = false;
		while (contains == false)
		{
			int index = rand() % talia.size();

			if (indeksy[index] == 0)
			{
				contains = true;
				indeksy[index]++;
				potasowanaTalia.push_back(talia[index]);
			}
		}
	}

	return potasowanaTalia;
}

vector<reka> rozdaj(const vector<karta>& talia, const int liczba_graczy)
{
	vector<reka> rece;

	for (int i = 0; i < liczba_graczy; i++)
	{
		reka r;
		rece.push_back(r);
	}

	vector<karta> potasowanaTalia = potasuj(talia);
	int ileKart = 0;
	int maxKart = talia.size() / liczba_graczy;

	while (ileKart < maxKart * liczba_graczy)
	{
		for (int j = 0; j < liczba_graczy; j++)
		{
			rece[j].push_back(potasowanaTalia[ileKart++]);
		}
	}

	return rece;
}

void wypisz(ostream& str, const karta& k)
{
	switch (k._wartosc)
	{
	case wartosc::dwojka:
		str << "dwojka ";
		break;
	case wartosc::trojka:
		str << "trojka ";
		break;

	case wartosc::czworka:
		str << "czworka ";
		break;

	case wartosc::piatka:
		str << "piatka ";
		break;

	case wartosc::szostka:
		str << "szostka ";
		break;

	case wartosc::siodemka:
		str << "siodemka ";
		break;

	case wartosc::osemka:
		str << "osemka ";
		break;

	case wartosc::dziewiatka:
		str << "dziewiatka ";
		break;

	case wartosc::dziesiatka:
		str << "dzeisiatka ";
		break;

	case wartosc::walet:
		str << "walet ";
		break;

	case wartosc::dama:
		str << "dama ";
		break;

	case wartosc::krol:
		str << "krol ";
		break;

	case wartosc::as:
		str << "as ";
		break;
	}

	switch (k._kolor)
	{
	case kolor::karo:
		str << "karo";
		break;

	case kolor::kier:
		str << "kier; ";
		break;

	case kolor::pik:
		str << "pik; ";
		break;

	case kolor::trefl:
		str << "trefl; ";
		break;
	}
	str << endl;
}

void wypisz(ostream& str, const reka& r)
{
	for (auto karta : r)
	{
		wypisz(str, karta);
	}
}

void wypisz(ostream& str, const vector<reka>& rozdanie)
{
	for (auto reka : rozdanie)
	{
		wypisz(str, reka);
		str << endl;
	}
}