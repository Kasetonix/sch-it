#include <iostream>
using std::cout;
using std::cin;

int main() {
	int number, numberInitial, numberReversed = 0;
	cout << "Podaj liczbę całkowitą: "; cin >> number;
	numberInitial = number;

	/* Podobnie do algorytmu sumowania cyfr liczby */
	while(number > 0) {
		numberReversed += number % 10;
		number /= 10;
		/* uniknięcie mnożenia razy 10 przy ostatniej cyfrze */
		if (number > 0)
			numberReversed = numberReversed * 10;
	} 

	if (numberReversed == numberInitial)
		cout << "Podana liczba jest palindromem" << "\n";
	else
		cout << "Podana liczba nie jest palindromem" << "\n";

	return 0;
}
