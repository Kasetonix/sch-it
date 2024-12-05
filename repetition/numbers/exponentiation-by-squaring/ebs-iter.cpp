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
    unsigned long long number;

    while (power > 0) {
        // Jeżeli wykładnik jest nieparzysty dodatkowo mnożymy go razy podstawę
        if (power % 2 == 1)
            number *= base;

        // Podnoszenie podstawy do kwadratu i dzielenie wykładnika przez dwa
        // Nie zmienia wyniku po poprzednim kroku
        base *= base;
        power /= 2;
    }

    return number;
}
