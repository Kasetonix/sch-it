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
		/* W wypadku gdy wykładnik jest liczbą nieparzystą
		 * mnożymy wynik przez obecny wynik
		 * pomocniczej potęgi [currentExponent] */
		if (power % 2 == 1) 
			result *= currentExponent;

		/* dzielimy wykładnika przez dwa (bez reszty) */
		power /= 2;

		/* W wypadku, gdy wykładnik po dzieleniu nadal
		 * jest większy od zera podnosimy pomocniczą potęgę
		 * do potęgi 2 */
		if (power > 0)
			currentExponent *= currentExponent;
	}

	cout << "Wynik potęgowania: " << result << "\n";

	return 0;
}
