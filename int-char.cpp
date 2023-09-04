#include <iostream>
#include <typeinfo>
using std::cout;

int main() {
	int integer = 4; 
	char character = '0' + integer;
	cout << typeid(integer).name() << ": " << integer << "\n";
	cout << typeid(character).name() << ": " << character << "\n";

	return 0;
}
