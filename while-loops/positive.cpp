#include <iostream>
using std::cout;
using std::cin;
using std::string;

int main() {
	int number;

	cout << "Podaj liczbę dodatnią: "; cin >> number;

	while (number < 0) {
		cout << "Nie podałeś liczby dodatniej" << "\n";
		cout << "Podaj liczbę dodatnią: "; cin >> number;
	}

	cout << "Liczba dodatnia wynosi " << number << "\n";

	return 0;
}
