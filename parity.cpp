#include <iostream>
using std::cout;
using std::cin;
using std::string;

int main() {
	short a;
	string answer;

	cout << "/// Checking if a number is even of odd ///" << "\n";
	cout << "Enter a whole number: "; cin >> a;

	answer = a % 2 == 0 ? "The given number is even" : "The given number is odd";
	cout << answer << "\n";

	return 0;
}
