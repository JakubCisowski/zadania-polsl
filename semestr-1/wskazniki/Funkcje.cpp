#include "Funkcje.h"
#include <fstream>
#include <ctime>
#include <vector>
using namespace std;

int* generuj_tablice(const int SIZE)
{
	int* tablica = new int[SIZE];
	for (int i = 0; i < SIZE; i++)
	{
		tablica[i] = rand() % 5500;
	}
	return tablica;
}

int* konkatenuj(const int* t1, const int n1, const int* t2, const int n2)
{
	int* tablica = new int[n1 + n2];

	for (int i = 0; i < n1 + n2; i++)
	{
		if (i < n1)
		{
			tablica[i] = t1[i];
		}
		else
		{
			tablica[i] = t2[i - n1];
		}
	}

	return tablica;
}

int* scal(const int* t1, const int n1, const int* t2, const int n2)
{
	int x = 0, y = 0;
	int* tablica = new int[n1 + n2];
	while (x + y < n1 + n2)
	{
		if (x == n1)
		{
			tablica[x + y] = t2[y++];
		}
		else if (y == n2)
		{
			tablica[x + y] = t1[x++];
		}
		else if (t1[x] < t2[y])
		{
			tablica[x + y] = t1[x++];
		}
		else
		{
			tablica[x + y] = t2[y++];
		}
	}

	return tablica;
}

double* wczytaj(istream& ss)
{
	vector<double> liczby;
	double jd;
	while (ss >> jd)
	{
		liczby.push_back(jd);
	}

	double* tablica = new double[liczby.size()];
	for (int i = 0; i < liczby.size(); i++)
	{
		tablica[i] = liczby[i];
	}
	return tablica;
}