#include <iostream>
using std::cout;
using std::cin;

int main() {
	int sideLength;
	cout << "Podaj długość boku kwadratu: "; cin >> sideLength;

	/* Liczymy tylko wtedy, kiedy ma to sens w geometrii */
	while (sideLength <= 0) {
		cout << "Podana długość jest niedodatnia." << "\n";
		cout << "Podaj długość boku kwadratu: "; cin >> sideLength;
	}
	
	/* Wypisujemy od razu wynik bez przypisywania go do jakiejś zmiennej */
	cout << "Pole kwadratu o tym boku wynosi " << sideLength * sideLength << "\n";
	return 0;
}
