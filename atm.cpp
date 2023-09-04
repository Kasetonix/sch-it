#include <iostream>
using std::cout;
using std::cin;
using std::string;

int main() {
	string savedpin = "2137";
	string enteredpin;
	string answer;

	cout << "/// ATM ///\n";
	cout << "Enter your PIN: "; cin >> enteredpin;

	answer = enteredpin == savedpin ? "You entered a correct PIN!" : "You entered a wrong PIN...";
	cout << answer << "\n";

	return 0;
}
