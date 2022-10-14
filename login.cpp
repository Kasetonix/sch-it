#include <iostream>
using std::cout;
using std::cin;
using std::string;

int main() {
	string login, pass;
	string savedLogin = "admin";
	string savedPass = "123";

	cout << "/// Login ///\n";
	cout << "Enter your login:    "; cin >> login;
	cout << "Enter your password: "; cin >> pass;

	if (login == savedLogin && pass == savedPass) { 
		cout << "You've logged in!\n"; 
		return 0;
	} else if (login == savedLogin || pass == savedPass) {
		cout << "You entered a wrong login or password!\n";
		return 1;
	} else if (login != savedLogin && pass != savedPass) {
		cout << "You entered a wrong login and password\n";
		return 1;
	}
}
