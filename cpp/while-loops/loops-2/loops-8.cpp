#include <iostream>
using std::cout;
using std::cin;

int main() {
	int number, sum = 0;
	cout << "Podaj liczbę całkowitą: "; cin >> number;
	number = abs(number);

	/* Dopóki liczba jest
	 * większa od zera do
	 * sumy dodajemy resztę
	 * z dzielenia przez 10
	 * danej liczby */
	while (number > 0) {
		sum += number % 10;
		number /= 10;
	}

	cout << "Suma cyfr tej liczby wynosi " << sum << "\n";

	return 0;
}
