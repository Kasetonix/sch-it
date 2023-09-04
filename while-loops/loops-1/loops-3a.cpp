#include <iostream>
#include <cmath>
using std::cout;
using std::cin;

int main() {
	float num;
	cout << "Podaj liczbę do spierwiastkowania: "; cin >> num;

	/* Liczymy tylko, gdy ma to sens w liczbach rzeczywistych */
	while (num < 0) {
		cout << "Nie podałeś liczby nieujemnej." << "\n";
		cout << "Podaj liczbę do spierwiastkowania: "; cin >> num;
	} 

	/* Wypisujemy wynik bez korzystania z jakiejś zmiennej */
	cout << "Pierwiastek z podanej liczy wynosi " << sqrt(num) << "\n";

	return 0;
}
