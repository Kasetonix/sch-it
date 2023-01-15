#include <iostream>
using std::cout;
using std::cin;

int main() {
	int limit, currentNum, positive = 0, negative = 0;
	cout << "Wprowadź, ile chcesz wpisać liczb: "; cin >> limit;

	for (int i = 1; i <= limit; i++) {
		cout << "Wprowadź liczbę całkowitą: "; cin >> currentNum;
		if (currentNum > 0)
			positive++;
		if (currentNum < 0)
			negative++;
	}

	cout << "Liczb większych od zera: " << positive << "\n";
	cout << "Liczb mniejszych od zera: " << negative << "\n";

	return 0;
}
