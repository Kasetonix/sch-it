#include <iostream>
using std::cout;
using std::cin;

int main() {
	int number, product = 1;
	cout << "Wprowadź liczbę naturalną z wyłączeniem zera: "; cin >> number;

	/* mnożenie kolejnych liczb naturalnych do podanej - silnia */
	for (int i = 1; i <= number; i++) {
		product = product * i;
	}

	cout << "n! = " << product << ".\n";

	return 0;
}
