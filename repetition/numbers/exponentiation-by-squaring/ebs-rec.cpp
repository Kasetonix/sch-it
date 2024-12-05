#include <iostream>
using std::cout;
using std::cin;

unsigned long long qp(unsigned long long base, unsigned power);

int main() {
    unsigned base, power;
    cout << "Podaj podstawę potęgi:  "; cin >> base;
    cout << "Podaj wykładnik potęgi: "; cin >> power;

    cout << base << "^" << power << " = " << qp(base, power) << "\n";

}

unsigned long long qp(unsigned long long base, unsigned power) {
    if (power == 1)
        return base;
    if (power % 2 == 0)
        return qp(base, power/2) * qp(base, power/2);
    
    return base * qp(base, power - 1);
}
