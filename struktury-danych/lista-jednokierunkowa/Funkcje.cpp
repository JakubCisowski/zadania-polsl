#include "Funkcje.h"
using namespace std;

// Dodawanie elementu do listy -------------------------------------------------

void dodajNaPoczatek(element*& pHead, typ liczba)
{
	pHead = new element{ liczba, pHead };
}

void dodajNaKoniecIteracyjnie(element*& pHead, typ liczba)
{
	if (not pHead)
	{
		pHead = new element{ liczba, nullptr };
	}
	else
	{
		auto p = pHead;
		while (p->pNext)
			p = p->pNext;

		p->pNext = new element{ liczba, nullptr };
	}
}

void dodajNaKoniecRekurencyjnie(element*& pHead, typ liczba)
{
	if (not pHead)
	{
		pHead = new element{ liczba, nullptr };
	}
	else
	{
		dodajNaKoniecRekurencyjnie(pHead->pNext, liczba);
	}
}

// Dodawanie elementu do listy posortowanej -------------------------------------
////
////void dodajIteracyjnieDoListyPosortowanej(element*& pHead, typ liczba)
////{
////	if (not pHead)
////	{
////		pHead = new element{ liczba, nullptr };
////	}
////	else
////	{
////		bool nieNajwiekszy = false;
////		auto p = pHead;
////		while (p->pNext)
////		{
////			if (p->pNext->pNext->wartosc < liczba)
////			{
////				p = p->pNext;
////			}
////			else
////			{
////				nieNajwiekszy = true;
////				break;
////			}
////		}
////		if (nieNajwiekszy)
////		{
////			auto p2 = new element{ liczba, p->pNext->pNext };
////			p->pNext->pNext = p2;
////		}
////		else
////		{
////			auto p2 = new element{ liczba, nullptr };
////			p->pNext = p2;
////		}
////	}
////}
////
////void dodajRekurencyjnieDoListyPosortowanej(element*& pHead, typ liczba)
////{
////}

// Usuwanie listy ---------------------------------------------------------------

void usunListeIteracyjnie(element*& pHead)
{
	while (pHead)
	{
		auto p = pHead->pNext;
		delete pHead;
		pHead = p;
	}
}

void usunListeOdPoczatkuRekurencyjnie(element*& pHead)
{
	if (pHead)
	{
		auto p = pHead->pNext;
		delete pHead;
		pHead = nullptr;
		usunListeOdPoczatkuRekurencyjnie(p);
	}
}

void usunListeOdKoncaRekurencyjnie(element*& pHead)
{
	if (pHead)
	{
		usunListeOdKoncaRekurencyjnie(pHead->pNext);
		delete pHead;
		pHead = nullptr;
	}
}

// Usuwanie elementu z listy -------------------------------------------------------

void usunElement(element*& pHead, element* pDoUsuniecia)
{
	auto p = pHead;
	while (p->pNext)
	{
		if (p->pNext == pDoUsuniecia)
		{
			element* temp = pDoUsuniecia->pNext;
			delete p->pNext;
			p->pNext = temp;
			break;
		}
		p = p->pNext;
	}
}

void usunElement(element*& pHead, typ wartosc)
{
	auto p = pHead;
	while (p->pNext)
	{
		if (p->pNext->wartosc == wartosc)
		{
			element* temp = p->pNext->pNext;
			delete p->pNext;
			p->pNext = temp;
			break;
		}
		p = p->pNext;
	}
}

void usunElementy(element*& pHead, typ wartosc)
{
	auto p = pHead;
	while (p->pNext)
	{
		if (p->pNext->wartosc == wartosc)
		{
			element* temp = p->pNext->pNext;
			delete p->pNext;
			p->pNext = temp;
		}
		if (p->pNext)
		{
			p = p->pNext;
		}
		else
		{
			break;
		}
	}
}

void usunOstatniIteracyjnie(element*& pHead)
{
	if (pHead)
	{
		auto p = pHead;
		element* previous = nullptr;
		while (p->pNext)
		{
			previous = p;
			p = p->pNext;
		}
		delete p;
		previous->pNext = nullptr;
	}
}

void usunPowtorzenia(element*& pHead)
{
	if (pHead)
	{
		vector<typ> elementy;

		auto p = pHead;
		elementy.push_back(p->wartosc);
		while (p->pNext)
		{
			bool czyWystapil = false;
			// Sprawdzanie czy element o takiej wartosci juz wczesniej wystapil
			// Jesli wystapil to usuwamy go z listy
			for (typ wartosc : elementy)
			{
				if (wartosc == p->pNext->wartosc)
				{
					element* temp = p->pNext->pNext;
					delete p->pNext;
					p->pNext = temp;
					czyWystapil = true;
					break;
				}
			}
			if (!czyWystapil)
			{
				elementy.push_back(p->pNext->wartosc);
				p = p->pNext;
			}
		}
	}
}

void usunParzyste(element*& pHead)
{
	if (pHead)
	{
		auto p = pHead;
		while (p->pNext)
		{
			if (p->pNext->wartosc % 2 == 0)
			{
				element* temp = p->pNext->pNext;
				delete p->pNext;
				p->pNext = temp;
			}
			else
			{
				p = p->pNext;
			}
		}
	}
}

// Wypisywanie listy ---------------------------------------------------------------

void wypiszOdPoczatkuIteracyjnie(element* pHead)
{
	while (pHead)
	{
		cout << pHead->wartosc << ' ';
		pHead = pHead->pNext;
	}
}

void wypiszOdPoczatkuRekurencyjnie(element* pHead, ostream& ss)
{
	if (pHead)
	{
		ss << pHead->wartosc << ' ';
		wypiszOdPoczatkuRekurencyjnie(pHead->pNext, ss);
	}
}

void wypiszOdKoncaRekurencyjnie(element* pHead, ostream& ss)
{
	if (pHead)
	{
		wypiszOdKoncaRekurencyjnie(pHead->pNext, ss);
		ss << pHead->wartosc << ' ';
	}
}

// Znajdywanie elementu --------------------------------------------------------------

element* znajdzElementRekurencyjnie(element* pHead, typ liczba)
{
	if (pHead)
	{
		if (pHead->wartosc == liczba)
		{
			return pHead;
		}
		else
		{
			return znajdzElementRekurencyjnie(pHead->pNext, liczba);
		}
	}
	else
	{
		return nullptr;
	}
}

element* znajdzElementIteracyjnie(element* pHead, typ liczba)
{
	while (pHead)
	{
		if (pHead->wartosc == liczba)
		{
			return pHead;
		}
		pHead = pHead->pNext;
	}
	return nullptr;
}

// Znajdywanie poprzednika ------------------------------------------------------------

element* znajdzPoprzednikIteracyjnie(element* pHead, element* pNastepnik)
{
	if (not pHead or pNastepnik == pHead)
	{
		return nullptr;
	}

	auto p = pHead;
	while (p and p->pNext != pNastepnik)
	{
		p = p->pNext;
	}

	return p;
}

element* znajdzPoprzednikRekurencyjnie(element* pHead, element* pNastepnik)
{
	if (not pHead or pNastepnik == pHead)
	{
		return nullptr;
	}

	if (pHead and pHead->pNext != pNastepnik)
	{
		znajdzPoprzednikRekurencyjnie(pHead->pNext, pNastepnik);
	}
	else
	{
		return pHead;
	}
}

// Odwracanie listy -------------------------------------------------------------------

void odwrocListe(element*& pHead)
{
	auto p = pHead;
	element* poprzednik = nullptr;
	auto nastepnik = p->pNext;

	while (p->pNext)
	{
		p->pNext = poprzednik;
		poprzednik = p;
		p = nastepnik;
		nastepnik = p->pNext;
	}

	pHead = p;
	pHead->pNext = poprzednik;
}