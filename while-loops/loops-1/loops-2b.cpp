#include <iostream>
using std::cout;
using std::cin;

int main() {
	int sideLength;

	do {
		cout << "Podaj długość boku kwadratu: "; cin >> sideLength;
		if (sideLength <= 0)
			cout << "Długość boku kwadratu musi być nieujemna." << "\n";
	} while (sideLength <= 0); /* Liczymy tylko wtedy, kiedy ma to sens w geometrii */
	
	/* Wypisujemy wynik bez przypisywania go do jakiejś zmiennej */
	cout << "Pole kwadratu o tym boku wynosi " << sideLength * sideLength << "\n";
	return 0;
}
