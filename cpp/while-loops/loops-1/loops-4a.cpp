#include <iostream>
using std::cout;
using std::cin;

int main() {
	float num;
	cout << "Podaj liczbę od zera do stu: "; cin >> num;

	/* Sprawdzenie czy liczba NIE należy do przedziału który sprawdzamy */
	while (!(num >= 0 && num <= 100)) {
		cout << "Podana liczba nie należy do przedziału od zera do stu." << "\n";
		cout << "Podaj liczbę od zera do stu: "; cin >> num;
	}

	cout << "Liczba " << num << " jest liczbą należącą do przedziału od zera do stu.";

	return 0;
}
