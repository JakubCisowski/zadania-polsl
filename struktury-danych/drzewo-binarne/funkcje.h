#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <deque>
#include <iomanip>
#include <algorithm>
using namespace std;

typedef int T;
typedef int typ;

struct wezel
{
	T wartosc;
	wezel* pLewy;
	wezel* pPrawy;
};

// Wyklad ------------------------------------------------

void dodajDoDrzewaRekurencyjnie(wezel*& pRoot, const typ& wartosc);

void dodajDoDrzewaIteracyjnie(wezel*& pRoot, typ& wartosc);

void dodajDoDrzewaIteracyjnie2(wezel*& pRoot, typ& wartosc);

void wypisz(wezel* pRoot);

void wypisz(wezel* pRoot, int wciecie);

void usunDrzewo(wezel*& pRoot);

wezel* znajdzRekurencyjnie(wezel* pRoot, const typ& wartosc);

wezel* znajdzIteracyjnie(wezel* pRoot, const typ& wartosc);

std::ostream& operator << (std::ostream& ss, wezel* pRoot);

typ zsumujWartosci(wezel* pRoot);

int policzWezly(wezel* pRoot);

int wysokoscDrzewa(wezel* pRoot);

void usunLiscie(wezel*& pRoot);

int policzLiscie(wezel* pRoot);

wezel* znajdzRodzic(wezel* pRoot, wezel* pPotomek);

wezel* znajdzRodzicIter(wezel* pRoot, wezel* pPotomek);

wezel* minimalny(wezel* pRoot);

wezel* maksymalny(wezel* pRoot);

wezel* minimalnyR(wezel* pRoot);

wezel* maksymalnyR(wezel* pRoot);

void wypiszDrzewoWszerz(wezel* pRoot);

// Plik Drzewa_poszukiwan_binarnych.pdf ------------------

void odbij(wezel* pRoot);

wezel* znajdzNastepnik(wezel* pRoot, wezel* pPoprzednik);

void usunWezel(wezel*& pRoot, wezel* pDoUsuniecia);

void rotacja_w_lewo(wezel*& pRoot, wezel* q);

void rotacja_w_prawo(wezel*& pRoot, wezel* p);

void zbalansuj(wezel*& pRoot);

void listawszerz2drzewo(wezel*& pRoot, T lista[], const int rozmiar);

wezel* katy(wezel* pRoot, const int k);

bool zawiera_ciag_wartosci(wezel*& pRoot, T lista[], const int rozmiar);

void posortowane2zrownowazone(wezel*& pRoot, T lista[], const int rozmiar);

void odleglosc(wezel* pRoot, wezel* p, wezel* q);

// Powtorzone --------------------------------------------

// Bylo na wykladzie
//void wypiszWszerz(wezel* pRoot);