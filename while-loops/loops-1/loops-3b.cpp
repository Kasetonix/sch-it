#include <iostream>
#include <cmath>
using std::cout;
using std::cin;

int main() {
	float num;

	do {
		cout << "Podaj liczbę do spierwiastkowania: "; cin >> num;
		if (num <= 0)
			cout << "Nie podałeś liczby nieujemnej." << "\n";
	} while (num <= 0); /* Liczymy tylko, gdy ma to sens w liczbach rzeczywistych */
		
	/* Wypisujemy wynik bez korzystania z dodatkowej zmiennej */
	cout << "Pierwiastek z podanej liczy wynosi " << sqrt(num) << "\n";

	return 0;
}
