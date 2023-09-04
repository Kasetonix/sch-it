#include <iostream>
using std::cout;
using std::cin;
using std::string;

int main() {
	unsigned int decimal, numberSys, currentDigit;
	string converted = "";

	cout << "Wprowadź liczbę w systemie dziesiętnym: "; cin >> decimal;
	cout << "Wprowadź system liczbowy: "; cin >> numberSys;

	unsigned int decimalInit = decimal;

	while (decimal > 0) {
		/* obecna cyfra w systemie docelowym */
		currentDigit = decimal % numberSys;

		/* sprawdzanie, czy liczba może zawierać znaki, a nie tylko liczby
		 * wymagana konwersja int -> char */
		if (currentDigit < 10)
			/* dodajemy do '0', by otrzymać oczekiwaną cyfrę */
			converted = char ('0' + currentDigit) + converted;
		else
			/* dodajemy do 'A' i odejmujemy 10, by otrzymać oczekiwaną literę tuż po skończeniu się cyfr */
			converted = char ('A' - 10 + currentDigit) + converted;
		
		/* przejście do następnej cyfry */
		decimal = decimal / numberSys;
	}

	cout << decimalInit << " {10} -> " << converted << " {" << numberSys << "}" << "\n";

	return 0;
}
