#include <iostream>
#include <string>
using namespace std;

void Zadanie1(int W, int K)
{
	cout << "Zadanie 1 dla [W = " << W << ", K = " << K << "]: " << endl;
	for (int i = 0; i < W; i++)
	{
		char znak = i % 2 == 0 ? 'X' : '.';
		for (int j = 0; j < K; j++)
		{
			cout << znak;
		}
		cout << endl;
	}
	cout << endl;
}
void Zadanie2(int W, int K)
{
	cout << "Zadanie 2 dla [W = " << W << ", K = " << K << "]: " << endl;
	for (int i = 0; i < W; i++)
	{
		for (int j = 0; j < K; j++)
		{
			char znak = j % 2 == 0 ? 'X' : '.';
			cout << znak;
		}
		cout << endl;
	}
	cout << endl;
}
void Zadanie3(int N)
{
	cout << "Zadanie 3 dla [N = " << N << "]: " << endl;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			char znak = j < i ? '.' : 'X';
			cout << znak;
		}
		cout << endl;
	}
	cout << endl;
}

void Zadanie4(int N)
{
	cout << "Zadanie 4 dla [N = " << N << "]: " << endl;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			char znak = j > N - (i + 2) ? 'X' : '.';
			cout << znak;
		}
		cout << endl;
	}
	cout << endl;
}

void Zadanie5(int N)
{
	cout << "Zadanie 5 dla [N = " << N << "]: " << endl;
	for (int i = 0; i < N; i++)
	{
		if (i <= N / 2)
		{
			for (int j = 0; j < i; j++)
			{
				cout << ".";
			}
			for (int j = 0; j < N - 2 * i;j++)
			{
				cout << "X";
			}
			for (int j = 0; j < i; j++)
			{
				cout << ".";
			}
		}
		else
		{
			for (int j = 0; j < N - i - 1; j++)
			{
				cout << ".";
			}
			for (int j = 0; j < 2 + 2 * i - N;j++)
			{
				cout << "X";
			}
			for (int j = 0; j < N - i - 1; j++)
			{
				cout << ".";
			}
		}
		cout << endl;
	}
	cout << endl;
}

void Zadanie6(int N)
{
	cout << "Zadanie 6 dla [N = " << N << "]: " << endl;
	for (int i = 0; i < N; i++)
	{
		// .X.X
		if (i < N / 2)
		{
			for (int j = 0; j < i; j++)
				cout << '.';
			for (int j = 0; j < N / 2 - i; j++)
				cout << 'X';
			for (int j = 0; j < N / 2 - i - 1; j++)
				cout << '.';
			for (int j = 0; j < i + 1; j++)
				cout << 'X';
		}
		else
		{
			for (int j = 0; j < N - i; j++)
				cout << 'X';
			for (int j = 0; j < i - N / 2; j++)
				cout << '.';
			for (int j = 0; j < i - N / 2 + 1; j++)
				cout << 'X';
			for (int j = 0; j < N - 1 - i; j++)
				cout << '.';
		}


		cout << endl;
	}
	cout << endl;
}

void Zadanie7(int N)
{
	cout << "Zadanie 7 dla [N = " << N << "]: " << endl;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			char znak;
			if (i % 2 == 0)
				znak = j % 2 == 0 ? 'X' : '.';
			else
				znak = j % 2 == 0 ? '.' : 'X';
			cout << znak;
		}
		cout << endl;
	}
	cout << endl;
}

void Zadanie8(int N)
{
	cout << "Zadanie 8 dla [N = " << N << "]: " << endl;
	for (int i = 0; i < N; i++)
	{
		if (i < N / 2)
		{
			for (int j = 0; j < N / 2; j++)
				cout << 'X';
			for (int j = 0; j < N / 2; j++)
				cout << '.';
		}
		else
		{
			for (int j = 0; j < N / 2; j++)
				cout << '.';
			for (int j = 0; j < N / 2; j++)
				cout << 'X';
		}
		cout << endl;
	}
	cout << endl;
}

void Zadanie9(int N)
{
	cout << "Zadanie 9 dla [N = " << N << "]: " << endl;

	for (int k = 0; k < N * N; k++) // wyœwietla wszystkie wiersze
	{
		for (int i = 0; i < N; i++) // wyswietla pojedynczy wiersz
		{
			if (k / N % 2 == 0)
			{
				if (i % 2 == 0)
				{
					for (int j = 0; j < N; j++)
						cout << 'X';
				}
				else
				{
					for (int j = 0; j < N; j++)
						cout << '.';
				}
			}
			else
			{
				if (i % 2 == 0)
				{
					for (int j = 0; j < N; j++)
						cout << '.';
				}
				else
				{
					for (int j = 0; j < N; j++)
						cout << 'X';
				}
			}
		}
		cout << endl;
	}

	cout << endl;
}

void Zadanie10(int W, int K)
{
	string poczatek = "";
	cout << "Zadanie 10 dla [W = " << W << ", K = " << K << "]: " << endl;
	for (int i = 0; i < W; i++)
	{
		cout << poczatek;

		if (i % 2 == 0)
		{
			for (int k = poczatek.size(); k < K; k++)
				cout << 'X';
		}
		else
		{
			for (int k = poczatek.size(); k < K; k++)
				cout << '.';
		}


		cout << endl;

		if (i % 2 == 0)
		{
			poczatek += "X.";
		}
	}
	cout << endl;
}

void Zadanie11(int W, int K)
{
	string poczatek = "";
	string koniec = "";
	cout << "Zadanie 11 dla [W = " << W << ", K = " << K << "]: " << endl;
	for (int i = 0; i < W; i++)
	{
		if (i > W / 2 && i % 2 == 0)
		{
			poczatek = poczatek.substr(0, poczatek.size() - 2);
			koniec = koniec.substr(0, koniec.size() - 2);
		}

		cout << poczatek;

		if (i % 2 == 0)
		{
			for (int k = poczatek.size() + koniec.size(); k < K; k++)
				cout << 'X';
		}
		else
		{
			for (int k = poczatek.size() + koniec.size(); k < K; k++)
				cout << '.';
		}

		cout << koniec << endl;

		if (i <= W / 2 && i % 2 == 0)
		{
			poczatek += "X.";
			koniec += ".X";
		}

	}
	cout << endl;
}

int main()
{
	Zadanie1(5, 8);
	Zadanie2(5, 8);
	Zadanie3(6);
	Zadanie4(6);
	Zadanie5(7); // dzia³a dla N nieparzystych
	Zadanie6(10); // dzia³a dla N parzystych
	Zadanie7(8);
	Zadanie8(8); // dzia³a dla N parzystych
	Zadanie9(3);
	Zadanie10(7, 7);
	Zadanie11(11, 12);

	return 0;
}
