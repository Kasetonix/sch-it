#include <iostream>
using std::cout;
using std::cin;

int main() {
	int starNum;
	cout << "Wprowadź liczbę gwiazdek: "; cin >> starNum;

	for (int i = 1; i <= starNum; i++) {
		cout << "*";
		if (i % 20 == 0)
			cout << "\n";
	}

	return 0;
}
