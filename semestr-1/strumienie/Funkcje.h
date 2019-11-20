#pragma once
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

void zapisz_liczby(ostream& str, const double liczby[], const int N);
void zapisz_liczby(ostream& str, const vector<double>& liczby);
void zapisz_losowe(ostream& str);
double srednia_liczb(istream& str);
double frobenius(istream& str);
void uniq(istream& wejscie, ostream& wyjscie);
void ile_w_wierszu(istream& wejscie, ostream& wyjscie);
void srednia_wiersza(istream& wejscie, ostream& wyjscie);
void transponuj(istream& wejscie, ostream& wyjscie);
void pierwsze(istream& wejscie, ostream& wyjscie);
vector<string> rozdziel(const string& tekst);
vector<int> tworz_histogram(const string& nazwa_pliku);
void zapisz_histogram(const vector<int>& histogram, const string& nazwa_pliku, int maksimum = 30);