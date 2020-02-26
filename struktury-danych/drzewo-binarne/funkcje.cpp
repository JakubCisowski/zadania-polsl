#include "Funkcje.h"

// Dodawanie elementu do drzewa --------------------------------------------------

void dodajDoDrzewaRekurencyjnie(wezel*& pRoot, const typ& wartosc)
{
	if (not pRoot)  // drzewo puste
		pRoot = new wezel{ wartosc, nullptr, nullptr };
	else
	{
		if (wartosc < pRoot->wartosc) // idziemy w lewo
			dodajDoDrzewaRekurencyjnie(pRoot->pLewy, wartosc);
		else
			dodajDoDrzewaRekurencyjnie(pRoot->pPrawy, wartosc);
	}
}

void dodajDoDrzewaIteracyjnie2(wezel*& pRoot, typ& wartosc)
{
	if (not pRoot)
		pRoot = new wezel{ wartosc, nullptr, nullptr };
	else
	{
		auto p = pRoot;
		while (true)
		{
			if (wartosc < p->wartosc)
			{
				if (p->pLewy)
					p = p->pLewy;
				else
				{
					p->pLewy = new wezel{ wartosc, 0, 0 };
					return;
				}
			}
			else
			{
				if (p->pPrawy)
					p = p->pPrawy;
				else
				{
					p->pPrawy = new wezel{ wartosc, 0, 0 };
					return;
				}
			}
		}
	}
}

void dodajDoDrzewaIteracyjnie(wezel*& pRoot, typ& wartosc)
{
	if (not pRoot)
		pRoot = new wezel{ wartosc, nullptr, nullptr };
	else
	{
		auto p = pRoot;
		while (
			(wartosc < p->wartosc /* mamy isc w lewo */ and p->pLewy /* sciezka w lewo istnieje */)
			or
			(wartosc >= p->wartosc /* mamy isc w prawo */ and p->pPrawy /* sciezka w prawo istnieje */)
			)
		{
			// przesuniecie na nastepny wezel
			if (wartosc < p->wartosc)
				p = p->pLewy;
			else
				p = p->pPrawy;
		}

		// p wskazuje na poprzednik elementu do wstawienia
		if (wartosc < p->wartosc)
			p->pLewy = new wezel{ wartosc, 0, 0 };
		else
			p->pPrawy = new wezel{ wartosc, 0, 0 };
	}
}

// Usuwanie drzewa ---------------------------------------------------------------

void usunDrzewo(wezel*& pRoot)
{
	if (pRoot)
	{
		usunDrzewo(pRoot->pLewy);
		usunDrzewo(pRoot->pPrawy);
		delete pRoot;
		pRoot = nullptr;
	}
}

// Usuwanie wezlow z drzewa ------------------------------------------------------

void usunWezel(wezel*& pRoot, wezel* pDoUsuniecia)
{
}

void usunLiscie(wezel*& pRoot)
{
	if (pRoot)
	{
		if (not pRoot->pLewy and not pRoot->pPrawy)
		{
			// pRoot wskazuje na lisc
			delete pRoot;
			pRoot = 0;
		}
		else
		{
			usunLiscie(pRoot->pLewy);
			usunLiscie(pRoot->pPrawy);
		}
	}
}

// Wypisywanie drzewa ------------------------------------------------------------

void wypisz(wezel* pRoot)
{
	if (pRoot) // jezeli jest co wypisac
	{
		wypisz(pRoot->pLewy);
		std::cout << pRoot->wartosc << std::endl;
		wypisz(pRoot->pPrawy);
	}
}

void wypisz(wezel* pRoot, int wciecie)
{
	if (pRoot) // jezeli jest co wypisac
	{
		wypisz(pRoot->pLewy, wciecie + 1);
		std::cout << std::setw(wciecie * 4) << pRoot->wartosc << std::endl << std::setw(0);
		wypisz(pRoot->pPrawy, wciecie + 1);
	}
}

void wypiszDrzewoWszerz(wezel* pRoot)
{
	if (pRoot)
	{
		std::deque<wezel*> potomki;
		potomki.push_front(pRoot);

		while (not potomki.empty())
		{
			// wyjmij z kolejki adres wezla

			auto p = potomki.back(); // odczytanie wartosci
			potomki.pop_back(); // usuniecie z konca
//             auto p = potomki.front(); // odczytanie wartosci
//             potomki.pop_front(); // usuniecie z konca

			// wypisz wartosc schowana w wezle

			std::cout << p->wartosc << ' ';
			// zapisz do kolejki adresy potomkow:

			if (p->pLewy)
				potomki.push_front(p->pLewy);
			if (p->pPrawy)
				potomki.push_front(p->pPrawy);
		}
	}
}

////std::ostream& operator<<(std::ostream& ss, wezel* pRoot)
////{
////	// TODO: insert return statement here
////}

// Znajdywanie w�z�a w drzewie --------------------------------------------------

wezel* minimalny(wezel* pRoot)
{
	while (pRoot and pRoot->pLewy)
		pRoot = pRoot->pLewy;
	return pRoot;
}

wezel* maksymalny(wezel* pRoot)
{
	return nullptr;
}

wezel* minimalnyR(wezel* pRoot)
{
	return nullptr;
}

wezel* maksymalnyR(wezel* pRoot)
{
	return nullptr;
}

wezel* znajdzIteracyjnie(wezel* pRoot, const typ& wartosc)
{
	while (pRoot)
	{
		if (pRoot->wartosc == wartosc)
			return pRoot;
		if (wartosc < pRoot->wartosc)
			pRoot = pRoot->pLewy;
		else
			pRoot = pRoot->pPrawy;
	}
	return nullptr;
}

wezel* znajdzRekurencyjnie(wezel* pRoot, const typ& wartosc)
{
	if (pRoot)
	{
		if (pRoot->wartosc == wartosc)
			return pRoot;

		if (wartosc < pRoot->wartosc)
			return znajdzRekurencyjnie(pRoot->pLewy, wartosc);
		else
			return znajdzRekurencyjnie(pRoot->pPrawy, wartosc);
	}
	else
		return nullptr;
}

wezel* katy(wezel* pRoot, const int k)
{
	vector<wezel*> wezly;

	if (pRoot)
	{
		std::deque<wezel*> potomki;
		potomki.push_front(pRoot);

		while (not potomki.empty())
		{
			auto p = potomki.back();
			potomki.pop_back();

			wezly.push_back(p);

			if (p->pLewy)
				potomki.push_front(p->pLewy);
			if (p->pPrawy)
				potomki.push_front(p->pPrawy);
		}
	}

	int n = wezly.size();

	do
	{
		for (int i = 0; i < n - 1; i++)
		{
			if (wezly[i] > wezly[i + 1])
			{
				swap(wezly[i], wezly[i + 1]);
			}
		}
		n = n - 1;
	} while (n > 1);

	return wezly[k - 1];
}

// Znajdywanie rodzica -----------------------------------------------------------

wezel* znajdzRodzic(wezel* pRoot, wezel* pPotomek)
{
	if (not pRoot or not pPotomek)
		return nullptr;
	if (pRoot == pPotomek)
		return nullptr;

	if (pPotomek->wartosc < pRoot->wartosc)
	{
		if (pPotomek == pRoot->pLewy)
			return pRoot;
		else
			return znajdzRodzic(pRoot->pLewy, pPotomek);
	}
	else
	{
		if (pPotomek == pRoot->pPrawy)
			return pRoot;
		else
			return znajdzRodzic(pRoot->pPrawy, pPotomek);
	}
}

wezel* znajdzRodzicIter(wezel* pRoot, wezel* pPotomek)
{
	return nullptr;
}

// Znajdywanie nast�pnika --------------------------------------------------------

wezel* znajdzNastepnik(wezel* pRoot, wezel* pPoprzednik)
{
	return nullptr;
}

// Operacje na drzewie -----------------------------------------------------------

void odbij(wezel* pRoot)
{
	if (pRoot)
	{
		odbij(pRoot->pLewy);
		odbij(pRoot->pPrawy);
		wezel* temp = pRoot->pLewy;
		pRoot->pLewy = pRoot->pPrawy;
		pRoot->pPrawy = temp;
	}
}

void rotacja_w_lewo(wezel*& pRoot, wezel* q)
{
}

void rotacja_w_prawo(wezel*& pRoot, wezel* p)
{
}

void zbalansuj(wezel*& pRoot)
{
}

void listawszerz2drzewo(wezel*& pRoot, T lista[], const int rozmiar)
{
	if (rozmiar < 1)
		return;

	pRoot = new wezel{ lista[0], nullptr, nullptr };

	for (int i = 1; i < rozmiar; i++)
	{
		auto temp = pRoot;
		while (true)
		{
			if (lista[i] < temp->wartosc)
			{
				if (temp->pLewy)
				{
					temp = temp->pLewy;
					continue;
				}
				else
				{
					temp->pLewy = new wezel{ lista[i], nullptr, nullptr };
					break;
				}
			}
			if (lista[i] >= temp->wartosc)
			{
				if (temp->pPrawy)
				{
					temp = temp->pPrawy;
					continue;
				}
				else
				{
					temp->pPrawy = new wezel{ lista[i], nullptr, nullptr };
					break;
				}
			}
		}
	}
}

int wysokoscDrzewa(wezel* pRoot)
{
	return pRoot ? 1 + std::max(wysokoscDrzewa(pRoot->pLewy), wysokoscDrzewa(pRoot->pPrawy)) : 0;
}

int policzLiscie(wezel* pRoot)
{
	if (pRoot)
	{
		if (not pRoot->pLewy and not pRoot->pPrawy)
			return 1; // wezel nie ma potomkow, jest zatem lisciem
		else
			return policzLiscie(pRoot->pLewy) + policzLiscie(pRoot->pPrawy);
	}
	else
		return 0;
}

typ zsumujWartosci(wezel* pRoot)
{
	if (pRoot)
		return pRoot->wartosc + zsumujWartosci(pRoot->pLewy) + zsumujWartosci(pRoot->pPrawy);
	else
		return  typ{ }; // domyslna wartosc dla typu
}

int policzWezly(wezel* pRoot)
{
	if (pRoot)
		return 1 + policzWezly(pRoot->pLewy) + policzWezly(pRoot->pPrawy);
	return 0;
}

bool zawiera_ciag_wartosci(wezel*& pRoot, T lista[], const int rozmiar)
{
	return false;
}

void posortowane2zrownowazone(wezel*& pRoot, T lista[], const int rozmiar)
{
}

void odleglosc(wezel* pRoot, wezel* p, wezel* q)
{
}