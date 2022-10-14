#include <iostream>
using std::cout;
using std::cin;

int main() {
	float a,b,great;

	cout << "/// Greater than checker ///\n";
	cout << "Enter the first number:  "; cin >> a;
	cout << "Enter the second number: "; cin >> b;

	great = a > b ? a : b;
	cout << "The greater number is " << great << "\n";

	return 0;
}
