#include <iostream>
using std::cout;
using std::cin;

double max(double a, double b);

int main() {
	double a, b;
	cout << "Wprowadź pierwszą liczbę: "; cin >> a;
	cout << "Wprowadź drugą liczbę: "; cin >> b;
	cout << "Większą liczbą jest " << max(a, b) << "\n";

	return 0;
}

double max(double a, double b) {
	if (a >= b) return a;
    else return b;
}
