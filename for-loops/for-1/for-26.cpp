#include <iostream>
using std::cout;
using std::cin;

int main() {
	int number, sum = 0;
	cout << "Wprowadź liczbę naturalną większą od 0: "; cin >> number;

	/* iterowanie przez każdą liczbę naturalną do podanej liczby i
	 * sprawdzanie ostatnich cyfr */
	for (int i = 0; i < number; i++) {
		if (i % 100 == 19 || i % 10 == 5)
			sum += i;
	}

	cout << "Suma liczb zakończonych na 5 lub 19 znajdujących się przed tą liczbą wynosi " << sum << "\n";

	return 0;
}
