#include <iostream>
#include <algorithm>
using namespace std;

const int W = 5, K = 4;

void Wypisz(int tab[], const int N)
{
	for (int i=0;i<N;i++)
	{
		cout << tab[i] << " ";
	}
	cout << endl;
}

void Wypisz2d(int tab[W][K])
{
	for(int i=0; i<W; i++)
	{
		for(int j=0; j<K; j++)
		{
			cout << tab[i][j] << ' ';
		}
		cout << endl;
	}
}

void Zadanie1(int tab[], const int N)
{
	bool czyZamiana = true;
	int i = 0;

	while (czyZamiana)	
	{
		czyZamiana = false;
		for (int j = 1; j < N - i; j++)
		{
			if (tab[j - 1] > tab[j])
			{
				swap(tab[j - 1], tab[j]);
				czyZamiana = true;
			}
		}
		i++;
	}
}

void Zadanie2(int tab[], int tab2[], int tab3[], const int N, const int M)
{
	int i = 0, j = 0, k = 0;
	while (i<N || j<M)
	{
		if (i != N && j != M)
		{
			if (tab[i] < tab2[j])
			{
				tab3[k++] = tab[i++];
			}
			else
			{
				tab3[k++] = tab2[j++];
			}
		}
		else if (i == N)
		{
			tab3[k++] = tab2[j++];
		}
		else if (j == M)
		{
			tab3[k++] = tab[i++];
		}
	}
}

void Zadanie3(int tab[], int tab2[], const int M)
{
	for(int i=0; i<M; i++)
	{
		for(int j=0; j<i;j++)
		{
			if (tab[j] < tab[i])
			{
				tab2[i]++;
			}
		}
	}
}

void Zadanie4(int tab[][K])
{
	int liczba = 1;
	int i = 0, j = 0;
	bool wDol = true;

	while (j<K)
	{
		tab[i][j] = liczba++;

		if (wDol)
		{
			i++;
		}
		else
		{
			i--;
		}

		if (i == -1)
		{
			j++;
			i++;
			wDol = !wDol;
		}
		else if (i == W)
		{
			j++;
			i--;
			wDol = !wDol;
		}
	}
}

void Zadanie5(int tab[][K])
{
	int liczba = 1;
	int i = 0, j = 0;
	int id, jd;

	while (liczba <= W * K)
	{
		tab[i][j] = liczba++;
		id = i;
		jd = j;
		while(jd-1 >= 0 && id+1 < W)
		{
			id++;
			jd--;
			tab[id][jd] = liczba++;
		}
		if (j + 1 < K)
		{
			j++;
		}
		else
		{
			i++;
		}

	}
}

void Zadanie6(int tab[][K])
{
	int liczba = 1;
	int i = 0, j = 0;
	int p=0, l=0, d=0, g=0; // ile wierszy/kolumn juz zapelnilismy
	char sposobPrzechodzenia = 'P'; // prawo/lewo/dol/gora

	while (liczba <= W*K)
	{
		tab[i][j] = liczba++;
		if (j == K - 1 - d && sposobPrzechodzenia=='P')
		{
			sposobPrzechodzenia = 'D';
			d++;
		}
		else if (i == W - 1 - l && sposobPrzechodzenia=='D')
		{
			sposobPrzechodzenia = 'L';
			l++;
		}
		else if (j == g && sposobPrzechodzenia=='L')
		{
			sposobPrzechodzenia = 'G';
			g++;
		}
		else if (i==p+1 && sposobPrzechodzenia=='G')
		{
			sposobPrzechodzenia = 'P';
			p++;
		}

		switch(sposobPrzechodzenia)
		{
			case 'P':
				j++;
				break;
			case 'L':
				j--;
				break;
			case 'D':
				i++;
				break;
			case 'G':
				i--;
				break;
		}
	}
}

void Zadanie7(int tab[][K])
{
	for(int i=0; i<W; i++) // iterowanie po wierszach
	{
		bool czyZamiana = true;
		int k = 0;

		while (czyZamiana)	
		{
			czyZamiana = false;
			for (int j = 1; j < K - k; j++)
			{
				if (tab[i][j - 1] > tab[i][j])
				{
					swap(tab[i][j - 1], tab[i][j]);
					czyZamiana = true;
				}
			}
			k++;
		}
	}
}

// Zadanie 8 i 9 sa niewykonalne biorac pod uwage obecne umiejetnosci matematyczne

void Zadanie10(int tab[][K])
{
	int maksymalneMin = tab[0][0];

	for (int i = 0; i < W;i++)
	{
		int min = tab[i][0];
		for (int j = 1; j < K;j++)
		{
			if (tab[i][j] < min)
			{
				min = tab[i][j];
			}
		}
		cout << "Min dla wiersza " << i << "-tego: " << min << endl;
		if (min > maksymalneMin)
		{
			maksymalneMin = min;
		}
	}

	cout << "Maksymalne minimum: " << maksymalneMin <<  "." << endl;
}

// Zadaanie 11 jest analogiczne do pozostalych (rozni sie tylko struktura danych)


int main()
{
	const int N = 5, M = 6;
	int tab[N] = {7,2,5,3,6};
	int tab2[M] = {9,3,5,7,8,1};
	int tab3[N + M];
	int tab4[M] = { 0,8,4,3,9,4 };
	int tab5[M] = {};
	int tab6[W][K] = {};
	int tab7[W][K] = { {7,5,3,2}, {0,12,1,3}, {5,5,5,3}, {2,5,7,8}, {9,6,4,1} };


	cout << "Zadanie 1: " << endl;
	cout << "Tablica nieposortowana" << endl;
	Wypisz(tab, N);
	Zadanie1(tab, N);
	cout << "Tablica posortowana" << endl;
	Wypisz(tab, N);

	cout << endl;
	cout << "Zadanie 2:" << endl;
	cout << "Posortowana tablica nr 1:" << endl;
	Wypisz(tab, N);
	cout << "Posortowana tablica nr 2:" << endl;
	Zadanie1(tab2,M);
	Wypisz(tab2,M);
	cout << "Scalone tablice nr 1 i 2:" << endl;
	Zadanie2(tab, tab2, tab3, N, M);
	Wypisz(tab3,N+M);
	
	cout << endl;
	cout << "Zadanie 3:" << endl;
	cout << "Tablica wejsciowa:" << endl;
	Wypisz(tab4, M);
	cout << "Tablica wyjsciowa:" << endl;
	Zadanie3(tab4,tab5,M);
	Wypisz(tab5,M);

	cout << endl;
	cout << "Zadanie 4:" << endl;
	cout << "Tablica wyjsciowa:" << endl;
	Zadanie4(tab6);
	Wypisz2d(tab6);

	cout << endl;
	cout << "Zadanie 5:" << endl;
	cout << "Tablica wyjsciowa:" << endl;
	Zadanie5(tab6);
	Wypisz2d(tab6);

	cout << endl;
	cout << "Zadanie 6:" << endl;
	cout << "Tablica wyjsciowa:" << endl;
	Zadanie6(tab6);
	Wypisz2d(tab6);

	cout << endl;
	cout << "Zadanie 7:" << endl;
	cout << "Tablica wyjsciowa:" << endl;
	Zadanie7(tab7);
	Wypisz2d(tab7);

	cout << endl;
	cout << "Zadanie 10:" << endl;
	cout << "Tablica wyjsciowa:" << endl;
	Wypisz2d(tab6);
	Zadanie10(tab6);


	return 0;
}
