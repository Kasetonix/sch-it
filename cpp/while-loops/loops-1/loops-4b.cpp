#include <iostream>
using std::cout;
using std::cin;

int main() {
	float num;

	do {
		cout << "Podaj liczbę od zera do stu: "; cin >> num;
		/* Sprawdzenie czy liczba NIE należy do przedziału który sprawdzamy */
		if (!(num >= 0 && num <= 100))
			cout << "Podana liczba nie należy do przedziału od zera do stu." << "\n";
	} while (!(num >= 0 && num <= 100));

	cout << "Liczba " << num << " jest liczbą należącą do przedziału od zera do stu.";

	return 0;
}
