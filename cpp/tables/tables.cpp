#include <iostream>
using std::cout;

int main() {
/*  typ nazwa[zakres] = {wartości, początkowe} */
	int table[  5   ] = {1, 2, 3, 4, 5};
	/*  BARDZO nieefektywny sposób */
	/*
	 * cout << table[0] << "\n";
	 * cout << table[1] << "\n";
	 * cout << table[2] << "\n";
	 * cout << table[3] << "\n";
	 * cout << table[4] << "\n";
	*/

	/* DUŻO szybszy sposób */
	for (int i = 0; i < 5; i++)
		cout << table[i] << "\n";
		
	return 0;
}
