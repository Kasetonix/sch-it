#include <iostream>
using std::cout;
using std::cin;
using std::string;

/* Poniższy algorytm działa dla liczb o
 * systemach liczbowych od 2 - 10 */

int main() {
	unsigned int decimal, numberSys;
	string converted = "";

	cout << "Wprowadź liczbę w systemie dziesiętnym: "; cin >> decimal;
	cout << "Wprowadź system liczbowy: "; cin >> numberSys;

	unsigned int decimalInit = decimal;

	while (decimal > 0) {
		/* konwersja typu int na typ char */
		/* do converted dodajemy resztę z dzielenia
		 * wprowadzonej liczby przez podstawę systemu */
		converted = char('0' + decimal % numberSys) + converted;
		
		/* przejście do następnej cyfry */
		decimal = decimal / numberSys;
	}

	cout << decimalInit << " {10} -> " << converted << " {" << numberSys << "}" << "\n";

	return 0;
}
