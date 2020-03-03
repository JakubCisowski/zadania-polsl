#pragma once
#include <iostream>
using namespace std;

typedef int T;

struct element
{
	T wartosc;
	element* pNext;
};

void dodaj(element*& pHead, const T wartosc);

void usun(element*& pHead);

void wypisz(element* pHead);

int zliczElementy(element* pHead);

void usun(element*& pHead, const T& wartosc);

void usunWszystkie(element*& pHead, const T& wartosc);

void usun(element*& pHead, const element* pDoUsuniecia);

void polacz(element*& pH1, element*& pH2);