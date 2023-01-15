#include <iostream>
using std::cout;
using std::cin; 

int main() {
	int numAmount = 10, num[numAmount]; 
	float sum = 0;

	/* Iterowanie przez wszystkie elementy tabeli,
	 * wypełnianie jej podanymi liczbami i 
	 * sumowanie ich */
	for (int i = 0; i < numAmount; i++) {
		cout << "Podaj " << i + 1 << " liczbę: "; cin >> num[i];
		sum += num[i];
	}

	cout << "Suma podanych liczb wynosi " << sum << ".\n";

	cout << "Tablica w normalnej i odwrotnej kolejności: " << "\n";

	/* Wypisywanie tablicy */
	for (int j = 0; j < numAmount; j++) {
		if (j == 0)
			cout << "[ ";

		cout << num[j] << " ";

		if (j == numAmount - 1)
			cout << "]" << "\n";
	}

	/* Wypisywanie tablicy w odwrotnej kolejności.
	 * Użyto numAmount - 1, aby kompensować k >= 0,
	 * by indeksy tablicy były odpowiednie. */
	for (int k = numAmount - 1; k >= 0; k--) {
		if (k == numAmount - 1)
			cout << "[ ";
		
		cout << num[k] << " ";

		if (k == 0)
			cout << "]" << "\n";
	}

	return 0;
}
