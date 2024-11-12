#include <iostream>
using std::cout;
using std::cin;

unsigned long long pow(unsigned int base, unsigned int power);

int main() {
    unsigned int base, power;
    cout << "Podaj podstawę:  "; cin >> base;
    cout << "Podaj wykładnik: "; cin >> power;

    cout << base << "^" << power << " = " << pow(base, power) << "\n";

    return 0;
}

unsigned long long pow(unsigned int base, unsigned int power) {
    unsigned int index;
    unsigned long long result;

    for (index = 1; index <= power; index++)
        result *= base;

    return result;
}
