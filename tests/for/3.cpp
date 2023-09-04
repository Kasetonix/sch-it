#include <iostream>
using std::cout;

int main() {
	int currentNum = 2, sum = 0;

	for (int i = 1; i <= 10; i++) {
		cout << currentNum << "\n";
		sum += currentNum;
		currentNum += 2;
	}

	cout << "Suma tych liczb wynosi " << sum << ".\n";

	return 0;
}
