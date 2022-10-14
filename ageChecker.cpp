#include <iostream>
using std::cout;
using std::cin;
using std::string;

int main() {
	unsigned short age;
	string answer18, answer35;

	cout << "/// Adulthood checker ///\n";
	cout << "Enter your age: "; cin >> age;
	answer18 = age >= 18 ? "You're an adult!" : "You aren't an adult..."; 
	answer35 = age >= 35 ? "You can run for a presidency!" : "You can't run for a presidency..."; 
	cout << answer18 << "\n" << answer35 << "\n";

	return 0;
}
