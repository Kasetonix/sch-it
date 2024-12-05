#include <cstdint>
#include <fstream>
#include <iostream>
using std::cout;
using std::ifstream;
using std::ofstream;

const unsigned VN = 300; // Liczba wiosek
struct Village {
    unsigned long long start_elves = 0;
    unsigned long long log_entry = 0;
};

void GetData(Village village[]);
unsigned long long BTD(unsigned long long bin);
unsigned long long QP(unsigned long long base, unsigned long long power);

int main() {
    Village village[VN];
    unsigned long long current_elves, max_elves = 0, min_elves = UINT64_MAX;
    unsigned index;

    GetData(village);

    for (index = 0; index < VN; index++) {
        current_elves = QP(village[index].start_elves, BTD(village[index].log_entry));

        if (current_elves > max_elves)
            max_elves = current_elves;
        else if (current_elves < min_elves && current_elves > 1)
            min_elves = current_elves;
    }

    cout << "2^63: " << QP(2, 63) << "\n";
    cout << "DEC(1001010101010): " << BTD(1001010101010) << "\n";
    cout << "MAX: " << max_elves << "\n";
    cout << "MIN: " << min_elves << "\n";

    return 0;
}

void GetData(Village village[]) {
    ifstream infile;
    infile.open("wioski.txt");
    if (!infile.good()) {
        cout << "Plik wejściowy nie mógł być otwarty." << "\n";
        exit(1);
    }

    unsigned index;
    for (index = 0; index < VN; index++)
        infile >> village[index].start_elves >> village[index].log_entry;

    infile.close();
}

// Binarny -> Dziesiętny
unsigned long long BTD(unsigned long long bin) {
    unsigned long long dec = 0;
    unsigned long long power_2 = 1;

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
unsigned long long QP(unsigned long long base, unsigned long long power) {
    unsigned long long number = 1;

    while (power > 0) {
        if (power % 2 == 1)
            number *= base;

        base *= base;
        power /= 2;
    }

    return number;
}
