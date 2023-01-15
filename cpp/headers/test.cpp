#include <iostream>
#include "./nst.h"
using std::cout;
using std::cin;

int main() {
	int decimal = 0, binary;
	cout << "[bin]: "; cin >> binary;
	decimal = bindec(binary);
	cout << "[dec]: " << decimal << "\n";

	return 0;
}
