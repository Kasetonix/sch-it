#include <iostream>
using std::cout;
using std::cin;

int main() {
	int bin = 0, dec = 0, currentBinPower = 0, currentDecNum = 1;
	cout << "Podaj liczbę w systemie binarnym: "; cin >> bin;
	int binInit = bin; /* Potrzebne tylko do cout na końcu programu */

	while (bin > 0) {
		/* ustawianie początkowej wartości zmiennej przechowującej
		 * potęgę 2 używaną przy tej iteracji */ 
		currentDecNum = 1; 

		/* obliczanie odpowiedniej potęgi 2 */
		for (int i = currentBinPower; i > 0; i--)
			currentDecNum *= 2;

		/* obliczanie liczby w systemie dziesiętnym */
		dec += (bin % 10) * currentDecNum;

		/* przygotowanie zmiennych do następnej iteracji */ 
		bin /= 10;
		currentBinPower++;
	}

	cout << binInit << " {2} -> " << dec << " {10} " << "\n";
	
	return 0;
}
