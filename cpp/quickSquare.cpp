#include <iostream>
using std::cout;
using std::cin;

int main() {
	int base, power;
	long long result, currentExponent;

	cout << "Wprowadź podstawę potęgi: "; cin >> base;
	cout << "Wprowadź wykładnik potęgi: "; cin >> power;

	currentExponent = base; result = 1;

	while (power > 0) {
		/* Algorytm zamiany dec -> bin
		 * z obliczeniem wartości potęgi */
		if (power % 2 == 1) 
			result *= currentExponent;
		power /= 2;

		/* Podnoszenie potęgi tymczasowej do potęgi 2,
		 * by przejść do następnego kroku */
		if (power > 0)
			currentExponent *= currentExponent;
	}

	cout << "Wynik potęgowania: " << result << "\n";

	return 0;
}
