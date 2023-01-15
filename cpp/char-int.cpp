#include <iostream>
#include <typeinfo>
using std::cout;

int main() {
	char character = '4';
	int integer = character - '0';
	cout << typeid(character).name() << ": " << character << "\n";
	cout << typeid(integer).name() << ": " << integer << "\n";

	return 0;
}
