#include <iostream>
using std::cout;
using std::cin;

unsigned long long power(unsigned int base, unsigned int exponent);

int main() {
    unsigned int base, exponent;
    cout << "Podaj podstawę:  "; cin >> base;
    cout << "Podaj wykładnik: "; cin >> exponent;

    cout << base << "^" << exponent << " = " << power(base, exponent) << "\n";

    return 0;
}

unsigned long long power(unsigned int base, unsigned int exponent) {
    if (exponent == 0)
        return 1;

    return base * power(base, exponent - 1);
}
