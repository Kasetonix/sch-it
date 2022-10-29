#include <iostream>
using std::cout;
using std::cin;

int main() {
	float number, numberInit; int power;
	cout << "Wprowadź liczbę rzeczywistą: "; cin >> number;
	cout << "Wprowadź wykładnik potęgi: "; cin >> power;
	/* utworzenie zmiennej przechowującej początkową wartość potęgi */
	numberInit = number;

	for (int i = 1; i < power; i++) {
		/* potęgowanie to mnożenie czegoś przez siebie tyle razy, jaki jest wykładnik
		 * wykorzystujemy do tego zmienną przechowującą początkową wartość potęgi */
		number = number * numberInit;
	}

	cout << numberInit << " podniesione do potęgi " << power << " wynosi " << number << ".\n";

	return 0;
}
