#include <iostream>
using std::cout;
using std::cin;

int main() {
	int number, sum = 0;
	cout << "Podaj liczbę całkowitą: "; cin >> number;
	number = abs(number);

	/* Patrz: loops-8a.cpp */
	while (number > 0) {
		if (number % 2 == 1)
			sum += number % 10;
		number /= 10;
	}

	cout << "Suma nieparzystych cyfr tej liczby wynosi " << sum << "\n";

	return 0;
}
