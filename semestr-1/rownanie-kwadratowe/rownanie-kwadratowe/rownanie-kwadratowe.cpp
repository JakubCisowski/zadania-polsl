#include <iostream>
#include <cmath>	// sqrt

using namespace std;

void wprowadzLiczbe(float &x);
void rownanieKwadratowe(float a, float b, float c);

int main() {
	float a=0,b=0,c=0;

	cout << "Program obliczajacy rownanie kwadratowe [ax^2 + bx + c]\n";

	cout << "Wprowadz a:" << endl;
	wprowadzLiczbe(a);
	cout << "Wprowadz b:" << endl;
	wprowadzLiczbe(b);
	cout << "Wprowadz c:" << endl;
	wprowadzLiczbe(c);

	rownanieKwadratowe(a, b, c);
	cout << endl;

	return 0;
}

void wprowadzLiczbe(float &x) {
	while (!(cin >> x)) {
		cout << "Blad, wprowadz liczbe! \n";

		// Resetowanie strumienia
		cin.clear();
		cin.ignore(132, '\n');
	}

}

void rownanieKwadratowe(float a, float b, float c) {
	cout << endl << "Rozwiazania rownania kwadratowego o postaci [" ;
	cout << a << "x^2 + " << b << "x + " << c << " = 0] :" << endl;

	if (a == 0 && b == 0 && c == 0)
		cout << "Rownanie tozsamosciowe - nieskonczenie wiele rozwiazan";
	else if (a == 0 && b == 0 && c != 0)
		cout << "Sprzecznosc - brak rozwiazan";
	else if ((a == 0 || b == 0) && c == 0)
		cout << "x = 0";
	else if (a == 0 && b != 0 && c != 0)
		cout << "x = " << (-1 * c) / b;
	else if (a != 0 && b == 0 && c != 0)
	{
		if ((-1 * c) / a < 0)
			cout << "Sprzecznosc - brak rozwiazan";
		else
			cout << "x1 = " << sqrt((-1 * c) / a) << ", x2 = -" << sqrt((-1 * c) / a);
	}
	else if (a != 0 && b != 0 && c == 0)
		cout << "x1 = 0, x2 = " << (-1*b)/a;
	else 
	{
		float delta = (b * b) - 4 * a * c;

		if (delta < 0)
			cout << "Brak rozwiazan";
		else if (delta == 0)
			cout << "x = " << (-1 * b) / (2 * a);
		else
			cout << "x1 = " << (-1 * b - sqrt(delta)) / (2 * a) << ", x2 = " << (-1 * b + sqrt(delta)) / (2 * a);
	}
}