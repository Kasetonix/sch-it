#include <iostream>
#include <fstream>
#include <string>
#include <cstdint>
using std::cout;
using std::string;
using std::ifstream;
using std::ofstream;

const unsigned VN = 300; // Liczba wiosek
struct Village {
    unsigned long long start_elves;
    string log_entry;
};

void GetData(Village village[]);
unsigned long long BTD(string bin);
unsigned long long QP(unsigned long long base, unsigned long long power);

int main() {
    Village village[VN];
    unsigned long long current_elves, max_elves = 0, min_elves = UINT64_MAX;
    unsigned index;

    cout << "UINT64_MAX: " << min_elves << "\n";

    GetData(village);

    for (index = 0; index < VN; index++) {
        current_elves = QP(village[index].start_elves, BTD(village[index].log_entry));

        if (current_elves > max_elves)
            max_elves = current_elves;
        else if (current_elves < min_elves && current_elves > 1)
            min_elves = current_elves;
    }

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


// Binarny -> Dziesiętny [string -> uint_64]
unsigned long long BTD(string bin) {
    unsigned long long dec = 0;
    unsigned power2 = 1;
    int index;

    // Iteracja od końca liczby w systemie binarnym
    for (index = bin.size() - 1; index >= 0; index--) {
        // Jeżeli sprawdzana cyfra jest jedynką
        // dodanie odpowiedniej potęgi dwójki do wynikowej liczby
        if (bin[index] == '1')
            dec += power2;

        // Przejście do następnej potęgi dwójki
        power2 *= 2;
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
