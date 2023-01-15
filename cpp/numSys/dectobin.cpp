#include <iostream>
using std::cout;
using std::cin;
using std::string;

int main() {
	string binary = ""; 
	long long decimal, decimalInit; 
	cout << "Podaj liczbę w systemie dziesiętnym: "; cin >> decimal;
	decimalInit = decimal;

	while(decimal > 0) {
		/* dokładamy na początek stringa z liczbą w systemie binarnym:
		 * 0 - liczba jest podzielna przez dwa
		 * 1 - liczba nie jest podzielna przez dwa */
		if (decimal % 2 == 0)
			binary = "0" + binary;
		else if (decimal % 2 == 1)
			binary = "1" + binary;

		/* przechodzimy do następnej liczby - dzielimy całkowicie przez dwa */
		decimal /= 2;
	}

	cout << decimalInit << " {10} -> " << binary << " {2}" << "\n";

	return 0;
}
