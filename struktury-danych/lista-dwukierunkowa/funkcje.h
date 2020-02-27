#pragma once
#include <iostream>
using namespace std;

typedef int T;
typedef int typ;

struct element
{
	T wartosc;
	element* pPrev;
	element* pNext;
};

// Plik Lista_dwukierunkowa.pdf

void dodajNaKoniec(element*& pHead, element*& pTail, const T& wartosc);

element* znajdz(element* pHead, const T& wartosc);

void usunListe(element*& pHead, element*& pTail);

void usunElementy(element*& pHead, element*& pTail, const T& wartosc);

void dodajDoListyPosortowanej(element*& pHead, element*& pTail, const T& wartosc);

void odwrocListe(element*& pHead, element*& pTail);

void przenies(element*& pHeadWej, element*& pTailWej, const T& wartosc, element*& pHeadWyj, element*& pTailWyj);

void posortujListe(element*& pHead, element*& pTail);

void przesunListe(element*& pHead, element*& pTail);

// Wyklad

void dodajNaPoczatek(element*& pHead, element*& pTail, const typ& wartosc);

void usunRekurencyjnie(element*& pHead, element*& pTail);

void wypiszOdKonca(element* pTail);

void wypiszOdPoczatku(element* pHead);

// Powtorzone

//void dodajNaPoczatek(element*& pHead, element*& pTail, const typ& wartosc);