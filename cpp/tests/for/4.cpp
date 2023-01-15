#include <iostream>
using std::cout;

int main() {
	int todaysMoney = 2, moneySum = 0;

	for (int i = 1; i <= 30; i++) {
		moneySum += todaysMoney;
		todaysMoney += 2;
	}

	cout << "Syn zaoszczędził " << moneySum << " złotych." << "\n";

	return 0;
}
