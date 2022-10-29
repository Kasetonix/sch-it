#include <iostream>
using std::cout;
using std::cin;
using std::string;

int main() {
	string name;
	int num;

	cout << "/// Name iterator ///" << "\n";
	cout << "Enter your name: "; cin >> name;
	cout << "Enter how many times it should be iterated: "; cin >> num;

	for (int i = 1; i <= num; i++) {
		if (i < 10) 
			cout << i << ".  " << name << "\n";
		else if (i >= 10)
			cout << i << ". " << name << "\n";
	}

	return 0;
}
