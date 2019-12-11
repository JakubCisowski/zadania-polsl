#pragma once
#include <iostream>
using namespace std;

// Definicja elementu listy jednokierunkowej --------------------------------------------------

typedef int typ;

struct element
{
	typ wartosc;       ///< wartosc przechowywana w li�cie
	element* pNext;   ///< wskaznik na nastepny element
};

// Wyklad -------------------------------------------------------------------------------------

element* znajdzElementRekurencyjnie(element* pHead, typ liczba);

element* znajdzElementIteracyjnie(element* pHead, typ liczba);

element* znajdzPoprzednikIteracyjnie(element* pHead, element* pNastepnik);

element* znajdzPoprzednikRekurencyjnie(element* pHead, element* pNastepnik);

void dodajNaPoczatek(element*& pHead, typ liczba);

void dodajNaKoniecIteracyjnie(element*& pHead, typ liczba);

void dodajNaKoniecRekurencyjnie(element*& pHead, typ liczba);

void usunListeIteracyjnie(element*& pHead);

void usunListeOdPoczatkuRekurencyjnie(element*& pHead);

void usunListeOdKoncaRekurencyjnie(element*& pHead);

void wypiszOdPoczatkuIteracyjnie(element* pHead);

void wypiszOdPoczatkuRekurencyjnie(element* pHead, ostream& ss);

void wypiszOdKoncaRekurencyjnie(element* pHead, ostream& ss);

//Plik Lista_Jednokierunkowa.pdf ------------------------------------------------------------

void usunElement(element*& pHead, element* pDoUsuniecia);

void usunElement(element*& pHead, typ wartosc);

void usunElementy(element*& pHead, typ wartosc);

void usunOstatniIteracyjnie(element*& pHead);

void odwrocListe(element*& pHead);

// todo: ponizej

void usunPowtorzenia(element*& pHead);

void usunParzyste(element*& pHead);

void dodajIteracyjnieDoListyPosortowanej(element*& pHead, typ liczba);

void dodajRekurencyjnieDoListyPosortowanej(element*& pHead, typ liczba);

// useless funkcje z pdf ponizej -----------------------------------------------------------
void usunOstatniRekurencyjnie(element*& pHead);

element* sumaMnogosciowa(element* pH1, element* pH2);

element* iloczynMnogosciowy(element* pH1, element* pH2);

element* roznicaMnogosciowa(element* pH1, element* pH2);

element* scalListyPosortowane(element*& pH1, element*& pH2);