#include <iostream>
using std::cout;
using std::cin;

int main() {
	int checkNum;
	float currentNum, sum = 0;
	cout << "Ile liczb chcesz zsumować: "; cin >> checkNum;

	/* dodawanie liczb odwrotności podanych liczb naturalnych */
	for (int i = 1; i <= checkNum; i++) {
		cout << "Wprowadź liczbę rzeczywistą: "; cin >> currentNum;
		sum += 1/currentNum;
	}

	cout << "Suma odwrotności podanych liczb wynosi " << sum << ".\n";

	return 0;
}
