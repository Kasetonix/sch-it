#include <iostream>
using std::cout;
using std::cin;

int main() {
	int number, numberReversed = 0;
	cout << "Podaj liczbę całkowitą: "; cin >> number;

	/* Podobnie do algorytmu sumowania cyfr liczby */
	while(number > 0) {
		numberReversed += number % 10;
		number /= 10;
		/* uniknięcie mnożenia razy 10 przy ostatniej cyfrze */
		if (number > 0)
			numberReversed = numberReversed * 10;
	} 

	cout << "Podana liczba w odwrotnej kolejności to " << numberReversed << "\n";

	return 0;
}
