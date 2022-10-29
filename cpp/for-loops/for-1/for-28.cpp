#include <iostream>
using std::cout;
using std::cin;

int main() {
	int number;
	cout << "Wprowadź liczbę naturalną większą od 0: "; cin >> number;

	/* iterowanie wszystkich liczb naturalnych do podanej
	 * i sprawdzanie, czy są podzielne przez 7 i kończą się na 1 */
	for (int i = 1; i <= number; i++) {
		if (i % 7 == 0 && i % 10 == 1)
			cout << i  << " jest liczbą podzielną przez 7 kończącą się na 1."<< "\n";
	}

	return 0;
}
