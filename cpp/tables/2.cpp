#include <iostream>
using std::cout;
using std::cin;

int main() {
	float nums[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, number;
	cout << "Podaj liczbę: "; cin >> number;
	cout << "Suma podanej liczby i piątego elementu tablicy wynosi: " << nums[4] + number << ".\n";
	cout << "Iloraz podanej liczby i ostatniego elementu tablicy: " << number / nums[9] << ".\n";

	/* Wypisywanie elementów tablicy z 
	 * wyjątkiem 5 i 10 - już użytych */
	for (int i = 0; i < 10; i++) {
		if (i == 0)
			cout << "[ ";

		if (i != 4 && i != 9) 
			cout << nums[i] << " ";

		if (i == 9)
			cout << "]";
	}
}
