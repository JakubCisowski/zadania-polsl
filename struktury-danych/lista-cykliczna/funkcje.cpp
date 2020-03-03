#include "Funkcje.h"

void dodaj(element*& pHead, const T wartosc)
{
	if (!pHead)
	{
		pHead = new element;
		pHead->wartosc = wartosc;
		pHead->pNext = pHead;
		return;
	}

	element* nowy = new element{ wartosc,pHead };
	element* temp = pHead;

	while (temp->pNext != pHead)
	{
		temp = temp->pNext;
	}

	temp->pNext = nowy;

	pHead = nowy;
}

void usun(element*& pHead)
{
	auto temp2 = pHead;
	int rozmiar = 0;
	int x = 0;

	while (temp2->pNext != pHead)
	{
		rozmiar++;
		temp2 = temp2->pNext;
	}

	temp2 = pHead;

	while (x++ < rozmiar)
	{
		auto temp3 = temp2->pNext;
		delete temp2;
		temp2 = temp3;
	}

	delete temp2;

	pHead = nullptr;
}

void wypisz(element* pHead)
{
	if (pHead)
	{
		element* temp = pHead;

		while (temp->pNext != pHead)
		{
			cout << temp->wartosc << ' ';
			temp = temp->pNext;
		}
		cout << temp->wartosc;
	}
}

int zliczElementy(element* pHead)
{
	element* temp = pHead;
	int rozmiar = 0;

	while (temp->pNext != pHead)
	{
		rozmiar++;
		temp = temp->pNext;
	}

	return rozmiar;
}

void usun(element*& pHead, const T& wartosc)
{
	if (pHead->wartosc == wartosc)
	{
		auto temp2 = pHead;

		while (temp2->pNext != pHead)
		{
			temp2 = temp2->pNext;
		}
		temp2->pNext = pHead->pNext;

		temp2 = pHead->pNext;
		delete pHead;
		pHead = temp2;
		return;
	}

	auto temp = pHead;

	while (temp->pNext != pHead)
	{
		if (temp->pNext->wartosc == wartosc)
		{
			auto temp3 = temp->pNext->pNext;
			delete temp->pNext;
			temp->pNext = temp3;
			return;
		}
		temp = temp->pNext;
	}
}

void usunWszystkie(element*& pHead, const T& wartosc)
{
	while (pHead->wartosc == wartosc && pHead)
	{
		auto temp2 = pHead;

		while (temp2->pNext != pHead)
		{
			temp2 = temp2->pNext;
		}
		temp2->pNext = pHead->pNext;

		if (pHead->pNext == pHead)
		{
			delete pHead;
			pHead = nullptr;
			return;
		}

		auto temp3 = pHead->pNext;
		delete pHead;
		pHead = temp3;
	}

	element* temp = pHead;

	while (temp->pNext != pHead && pHead)
	{
		if (temp->pNext->wartosc == wartosc)
		{
			auto temp3 = temp->pNext->pNext;
			delete temp->pNext;
			temp->pNext = temp3;
		}
		temp = temp->pNext;
	}
}

void usun(element*& pHead, const element* pDoUsuniecia)
{
	if (pHead == pDoUsuniecia)
	{
		auto temp2 = pHead;

		while (temp2->pNext != pHead)
		{
			temp2 = temp2->pNext;
		}
		temp2->pNext = pHead->pNext;

		temp2 = pHead->pNext;
		delete pHead;
		pHead = temp2;
		return;
	}

	auto temp = pHead;

	while (temp->pNext != pHead)
	{
		if (temp->pNext == pDoUsuniecia)
		{
			auto temp3 = temp->pNext->pNext;
			delete temp->pNext;
			temp->pNext = temp3;
			return;
		}
		temp = temp->pNext;
	}
}

void polacz(element*& pH1, element*& pH2)
{
	auto temp = pH1;

	while (temp->pNext != pH1)
	{
		temp = temp->pNext;
	}
	temp->pNext = pH2;

	temp = pH2;

	while (temp->pNext != pH2)
	{
		temp = temp->pNext;
	}
	temp->pNext = pH1;

	pH2 = nullptr;
}