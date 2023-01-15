#include <iostream>
using std::cout;
using std::cin;
using std::string;

int main() {
	unsigned int decimal = 0, numberSys, currentDigit = 0;
	string given;

	cout << "Wprowadź liczbę w dowolnym systemie liczbowym: "; cin >> given;
	cout << "Wprowadź system liczbowy: "; cin >> numberSys;

	/* Zapętlanie dopóki nie przekonwertujemy całej liczby */
	for (int i = 0; i < given.size(); i++) {
		/* odpowiednia konwersja cyfry w danym systemie na wartość dziesiętną */
		/* jeżeli zamieniamy cyfrę 0 - 9 */
		if (given[i] <= '9')
			currentDigit = given[i] - '0';
		/* jeżeli zamieniamy literę A - Z */
		if (given[i] >= 'A')
			currentDigit = given[i] - 'A' + 10;

		/* dodanie do wyniku cyfrę zamienioną na system dziesiętny */
		decimal = decimal * numberSys + currentDigit;
	}

	cout << given << "{" << numberSys << "}" << " -> " << decimal << "{10}" << "\n";

	return 0;
}
