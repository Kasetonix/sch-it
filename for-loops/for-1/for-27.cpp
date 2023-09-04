#include <iostream>
using std::cout;
using std::cin;

int main() {
	int checkNum;
	float currentNum, maxNum, minNum;
	cout << "Ile liczb chcesz sprawdzić: "; cin >> checkNum;

	/* sprawdzanie checkNum liczb, czy są największe czy najmniejsze ze wszystkich podanych wcześniej */
	for (int i = 1; i <= checkNum; i++) {
		cout << "Wprowadź liczbę rzeczywistą: "; cin >> currentNum;
		/* ustawianie początkowych wartości maksymalnej i minimalnej liczby */
		if (i == 1) {
			maxNum = currentNum;
			minNum = currentNum;
		}

		/* sprawdzanie czy podana liczba jest maksymalna lub minimalna */
		if (maxNum < currentNum)
			maxNum = currentNum;
		if (minNum > currentNum)
			minNum = currentNum;
	}
	
	cout << "Maksymalna liczba z podanych to " << maxNum << ", a minimalna to " << minNum << ".\n";

	return 0;
}
