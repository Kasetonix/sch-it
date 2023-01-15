#include <iostream>
using std::cout;
using std::cin;
using std::string;

int main() {
	unsigned int decimal = 0, numberSys, currentDigit = 0;
	string given;

	cout << "Wprowadź liczbę w dowolnym systemie liczbowym: "; cin >> given;
	cout << "Wprowadź system liczbowy: "; cin >> numberSys;

	/* Iterowanie pętli dokóki nie przekonwertujemy całej liczby */
	for (int i = 0; i < given.size(); i++)
		/* Dodanie do wyniku cyfrę zamienioną na system dziesiętny */
		decimal = decimal * numberSys + given[i] - '0';

	cout << given << "{" << numberSys << "}" << " -> " << decimal << "{10}" << "\n";

	return 0;
}
