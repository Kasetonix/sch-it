#include <iostream>
using std::cout;
using std::cin;
using std::string;
using std::getline;

int main() {
	string binary, binaryInit;
	int currentPower = 1, decimal = 0;
	cout << "Podaj liczbę w systemie binarnym: "; getline(cin, binary);
	binaryInit = binary;
	cout << "binary: " << binary << "\n";
	
	/* wykonywanie do momentu, kiedy skończymy liczbę */
	for (int i = binary.size() - 1; i >= 0; i--) {
		/* jeżeli w systemie binarnym dana cyfra wynosi jeden to
		 * dodajemy do wyniku obecną potęgę dwójki */
		if (binary[i] == '1')
			decimal += currentPower;
		
		/* zwiększanie potęgi */
		currentPower *= 2;
	}

	cout << binaryInit << " {2} -> " << decimal << " {10}" << "\n";

	return 0;
}
