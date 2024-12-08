#include <iostream>
using std::cout;
using std::cin;

unsigned BtD(unsigned long long bin);
unsigned long long EbS(unsigned long long base, unsigned power);

int main() {
    unsigned start_elves = 0, log_entry = 0;
    cout << "Podaj liczbę założycieli: "; cin >> start_elves;
    cout << "Podaj wpis z dziennika:   "; cin >> log_entry;

    cout << "Liczba elfów:             " << EbS(start_elves, BtD(log_entry)) << "\n";

    return 0;
}

// Binarny -> Dziesiętny
unsigned BtD(unsigned long long bin) {
    unsigned long long dec = 0;
    unsigned power_2 = 1;

    while (bin > 0) {
        // Jeżeli końcówka liczby w binarnym jest równa jeden, 
        // to do wyniku dodajemy odpowiadającą jej potęgę dwójki
        if (bin % 2 == 1)
            dec += power_2;

        // Przechodzimy do następnej cyfry
        power_2 *= 2;
        bin /= 10;
    }

    return dec;
}

// Szybkie podnoszenie do potęgi
unsigned long long EbS(unsigned long long base, unsigned power) {
    unsigned long long number = 1;

    while (power > 0) {
        if (power % 2 == 1)
            number *= base;

        base *= base;
        power /= 2;
    }

    return number;
}
