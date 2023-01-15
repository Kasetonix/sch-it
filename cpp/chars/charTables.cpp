#include <iostream>
using std::cout;
using std::cin;

int main() {
	char table1[15] = {'A', 'l', 'a', ' ', 'm', 'a', ' ', 'k', 'o', 't', 'a', ' ', ':', ')', '\0'};

	/* gcc sam ogarnie, że potrzebuje 15 bajtów */
	char table2[] = {'A', 'l', 'a', ' ', 'm', 'a', ' ', 'k', 'o', 't', 'a', ' ', ':', ']', '\0'}; 

	char table3[] = "Ala ma kota :>";

	cout << table1 << "\n";
	cout << table2 << "\n";
	cout << table3 << "\n";

	return 0;
}
