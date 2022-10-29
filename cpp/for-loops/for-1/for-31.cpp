#include <iostream>
using std::cout;
using std::cin;

int main() {
	int number;
	cout << "Wprowadź liczbę naturalną większą od 0: "; cin >> number; 

	/* iterowanie wszystkich liczb naturalnych do podanej i
	 * wypisywanie kwadratu tych liczb */
	for (int i = 1; i <= number; i++) {
		cout << i*i << "\n";
	}

	return 0;
}
