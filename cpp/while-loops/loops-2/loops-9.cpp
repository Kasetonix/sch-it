#include <iostream>
using std::cout;
using std::cin;

int main() {
	int number, digitsNumber = 0;
	cout << "Podaj liczbę naturalną: "; cin >> number;

	while (number > 0) {
		digitsNumber++;
		number /= 10;
	}

	cout << "Liczba cyfr tej liczny wynosi " << digitsNumber << "\n";

	return 0;
}
