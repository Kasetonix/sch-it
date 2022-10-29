#include <iostream>
using std::cout;
using std::cin;

int main() {
	int number, sumDigitsNumber = 2, sum = 0;
	cout << "Podaj liczbę całkowitą: "; cin >> number;
	number = abs(number);

	while (sumDigitsNumber > 1) {
		/* Wcześniejsze ustawienie zmiennej na 2
		 * umożliwia wykonanie pętli po raz pierwszy */
		sumDigitsNumber = 0;

		/* Patrz: loops-8a.cpp */
		/* fragment liczący sumę cyfr */
		while (number > 0) {
			sum += number % 10;
			number /= 10;
		}
		cout << "Suma cyfr: " << sum << "\n";
		number = sum;

		/* Patrz: loops-9a.cpp */
		/* fragment liczący liczbę cyfr sumy z poprzedniego fragmentu */
		while (sum > 0) {
			sumDigitsNumber++;
			sum /= 10;
		}
	}

	return 0;
}
