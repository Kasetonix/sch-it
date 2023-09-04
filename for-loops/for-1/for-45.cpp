#include <iostream>
using std::cout;
using std::cin;

int main() {
	int number;
	cout << "Podaj liczbę naturalną: "; cin >> number;

	for (int i = 0; i < number; i++) {
		cout << i * 3;
		if (i + 1 != number)
			cout << ", ";
	}

	return 0;
}
