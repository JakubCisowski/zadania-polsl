#pragma once
#include <vector>
#include <iostream>
using namespace std;

// sekcja 1
struct punkt
{
	double x, y, z;
};

double odleglosc(const punkt& a, const punkt& b);
vector <punkt> wylosuj_punkty(const int N);
pair<punkt, punkt> najdalsze_punkty(const vector<punkt>& chmura);
bool wspolliniowe(const punkt& a, const punkt& b, const punkt& c);
void wypisz(ostream& str, const punkt& a);
void wypisz(ostream& str, const vector<punkt>& a);
bool pole_trojkata(const punkt& a, const punkt& b, const punkt& c);
double najmniejsze_pole_trojkata(const vector<punkt>& chmura);
double kat(const punkt& a, const punkt& b, const punkt& c);
double odleglosc(const punkt& a, const punkt& b, const punkt& c, const punkt& z);

// sekcja 2
enum class kolor
{
	pik, kier, karo, trefl
};

enum class wartosc
{
	as, krol, dama, walet, dziesiatka, dziewiatka, osemka, siodemka, szostka, piatka, czworka, trojka, dwojka
};

struct karta
{
	kolor _kolor;
	wartosc _wartosc;
};

typedef vector<karta> reka;

vector<karta> utworz_talie_brydz();
vector<karta> utworz_talie_skat();
vector<karta> utworz_talie_tysiac();
vector<karta> potasuj(const vector<karta>& talia);
vector<reka> rozdaj(const vector<karta>& talia, const int liczba_graczy);
void wypisz(ostream& str, const karta& k);
void wypisz(ostream& str, const reka& r);
void wypisz(ostream& str, const vector<reka>& rozdanie);