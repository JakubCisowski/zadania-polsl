#include "Funkcje.h"

// Dodawanie elementu do listy ---------------------------------------------

void dodajNaKoniec(element*& pHead, element*& pTail, const T& wartosc)
{
	if (not pHead) // lista pusta
		pHead = pTail = new element{ wartosc, nullptr, nullptr };
	else
	{
		auto pNowy = new element{ wartosc, pTail, nullptr };
		pNowy->pPrev->pNext = pNowy;
		pTail = pNowy;
	}
}

void dodajDoListyPosortowanej(element*& pHead, element*& pTail, const T& wartosc)
{
	element* temp = pHead;

	if (temp->wartosc > wartosc)
	{
		pHead = new element{ wartosc, nullptr, pHead };
		return;
	}

	while (temp)
	{
		if (temp->wartosc > wartosc)
		{
			temp->pPrev->pNext = new element{ wartosc, temp->pPrev, temp };
			temp->pPrev = temp->pPrev->pNext;
			return;
		}
		temp = temp->pNext;
	}
	// jest najwiekszy wiec dodajemy na koniec
	pTail->pNext = new element{ wartosc, pTail, nullptr };
	pTail = pTail->pNext;
}

void dodajNaPoczatek(element*& pHead, element*& pTail, const typ& wartosc)
{
	if (not pHead) // lista pusta
		pHead = pTail = new element{ wartosc, nullptr, nullptr };
	else
	{
		auto pNowy = new element{ wartosc, nullptr, pHead };
		pNowy->pNext->pPrev = pNowy;
		pHead = pNowy;
	}
}

// Usuwanie listy ---------------------------------------------------

void usunListe(element*& pHead, element*& pTail)
{
	while (pHead)
	{
		element* temp = pHead->pNext;
		delete pHead;
		pHead = temp;
	}
}

void usunElementy(element*& pHead, element*& pTail, const T& wartosc)
{
	element* temp = pHead;
	while (temp)
	{
		if (temp->wartosc == wartosc)
		{
			element* temp2 = temp->pNext;
			element* temp3 = temp->pPrev;
			delete temp;
			temp->pPrev->pNext = temp2;
			temp->pNext->pPrev = temp3;
		}
		else
		{
			temp = temp->pNext;
		}
	}
}

void usunRekurencyjnie(element*& pHead, element*& pTail)
{
	if (pHead)
	{
		usunRekurencyjnie(pHead->pNext, pTail);
		delete pHead;
		pHead = pTail = nullptr;
	}
}

// Wypisywanie listy --------------------------------------------

void wypiszOdKonca(element* pTail)
{
	if (pTail)
	{
		std::cout << pTail->wartosc << ' ';
		wypiszOdKonca(pTail->pPrev);
	}
}

void wypiszOdPoczatku(element* pHead)
{
	while (pHead)
	{
		std::cout << pHead->wartosc << ' ';
		pHead = pHead->pNext;
	}
}

// Znajdywanie elementu w liscie

element* znajdz(element* pHead, const T& wartosc)
{
	while (pHead)
	{
		if (pHead->wartosc == wartosc)
		{
			return pHead;
		}
		pHead = pHead->pNext;
	}
	return nullptr;
}

// Operacje na liscie --------------------------------------------------------

void odwrocListe(element*& pHead, element*& pTail)
{
	auto temp = pHead;

	while (temp)
	{
		auto temp2 = temp->pNext;
		temp->pNext = temp->pPrev;
		temp->pPrev = temp2;
		temp = temp->pPrev;
	}

	auto temp3 = pHead;
	pHead = pTail;
	pTail = temp3;
}

void przenies(element*& pHeadWej, element*& pTailWej, const T& wartosc, element*& pHeadWyj, element*& pTailWyj)
{
	auto temp = pHeadWej;
	auto temp2 = pHeadWyj;

	while (temp)
	{
		if (temp->wartosc == wartosc)
		{
			if (temp->pPrev)
			{
				temp->pPrev->pNext = temp->pNext;
			}
			if (temp->pNext)
			{
				temp->pNext->pPrev = temp->pPrev;
			}

			if (not pHeadWyj)
				pHeadWyj = pTailWyj = new element{ temp->wartosc, nullptr, nullptr };
			else
			{
				auto pNowy = new element{ temp->wartosc, pTailWyj, nullptr };
				pNowy->pPrev->pNext = pNowy;
				pTailWyj = pNowy;
			}

			if (wartosc == pHeadWej->wartosc)
			{
				pHeadWej = temp->pNext;
			}

			auto x = temp->pNext;
			delete temp;
			temp = x;
		}
		else
		{
			temp = temp->pNext;
		}
	}
}

void posortujListe(element*& pHead, element*& pTail)
{
	auto temp = pHead;
	element* pHead2 = nullptr;
	element* pTail2 = nullptr;

	element* pHead1 = pHead;

	int x = 0;
	int iloscElementow = 0;

	while (temp)
	{
		temp = temp->pNext;
		iloscElementow++;
	}

	// wykonujemy tyle razy ile jest elementow
	while (x++ < iloscElementow)
	{
		// usuwamy najmniejszy i dodajemy do drugiej listy

		// wyznaczamy najmniejszy

		auto temp2 = pHead1;  // !mozemy usuwac z poczaktu
		int minWartosc = 1000000000;
		element* minElement = nullptr;
		while (temp2)
		{
			if (temp2->wartosc < minWartosc)
			{
				minWartosc = temp2->wartosc;
				minElement = temp2;
			}
			temp2 = temp2->pNext;
		}

		// dodajemy do docelowej listy

		if (not pHead2)
			pHead2 = pTail2 = new element{ minWartosc, nullptr, nullptr };
		else
		{
			auto pNowy = new element{ minWartosc, pTail2, nullptr };
			pNowy->pPrev->pNext = pNowy;
			pTail2 = pNowy;
		}

		// usuwamy z pierwotnej listy
		if (minElement == pHead1)
		{
			pHead1 = pHead1->pNext;
		}

		if (minElement->pPrev)
		{
			minElement->pPrev->pNext = minElement->pNext;
		}

		if (minElement->pNext)
		{
			minElement->pNext->pPrev = minElement->pPrev;
		}

		delete minElement;
	}

	pHead = pHead2;
	pTail = pTail2;
}

void przesunListe(element*& pHead, element*& pTail)
{
	if (pHead && (pTail != pHead))
	{
		auto temp = pHead;
		auto temp2 = pTail->pPrev;

		pHead = pTail;
		pHead->pNext = temp;
		pHead->pNext->pPrev = pHead;
		pHead->pPrev = nullptr;

		pTail = temp2;
		pTail->pNext = nullptr;
	}
}