#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector <float> tablica;
	float temp;

	// Wprowadzenie pierwszej liczby (musi byc co najmniej jedna)
	cout << "Wprowadzaj liczby do tablicy (co najmniej jedna)\nAby zakonczyc wprowadz cos innego od liczby\n";
	while (!(cin >> temp))
	{
		cout << "Wprowadz conajmniej jedna liczbe!\n";

		// Reset strumienia
		cin.clear();
		cin.ignore(132, '\n');
	}
	tablica.push_back(temp);

	// Wprowadzenie kolejnych liczb
	while (cin >> temp)
		tablica.push_back(temp);

	// Wyznaczenie min, max
	float min = tablica[0], max = tablica[0];
	for (float liczba : tablica)
	{
		if (min > liczba)
			min = liczba;
		if (max < liczba)
			max = liczba;
	}

	// Wypisanie min,max
	cout << "\nSposrod tablicy: [ ";
	for (float liczba : tablica)
		cout << liczba << ' ';
	cout << "]\n";
	cout << "Wartosc minimalna: " << min << "\nWartosc maksymalna: " << max << endl;
}