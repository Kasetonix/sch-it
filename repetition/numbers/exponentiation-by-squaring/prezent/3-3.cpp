#include <iostream>
#include <fstream>
#include <string>
using std::cout;
using std::string;
using std::ifstream;
using std::ofstream;

const unsigned VN = 300; // Liczba wiosek
struct Village {
    unsigned long long current_elves;
    string log_entry;
};

void GetData(Village village[]);
unsigned long long BtD(string bin);
unsigned long long EbS(unsigned long long base, unsigned long long power);
bool ValidateVillage(Village village);

int main() {
    Village village[VN];
    unsigned index, counter;

    GetData(village);

    // For each village
    for (index = 0; index < VN; index++) {
        if (ValidateVillage(village[index]))
            continue;
        cout << village[index].current_elves << ' ' << village[index].log_entry << "\n";
        counter++;
    }

    cout << "Liczba wierszy z błędami: " << counter << "\n";

    return 0;
}

void GetData(Village village[]) {
    ifstream infile;
    infile.open("chochlik.txt");
    if (!infile.good()) {
        cout << "Plik wejściowy nie mógł być otwarty." << "\n";
        exit(1);
    }

    unsigned index;
    for (index = 0; index < VN; index++) {
        infile >> village[index].current_elves >> village[index].log_entry;
    }

    infile.close();
}


// Binarny -> Dziesiętny [string -> uint_64]
unsigned long long BtD(string bin) {
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
unsigned long long EbS(unsigned long long base, unsigned long long power) {
    unsigned long long number = 1;

    while (power > 0) {
        if (power % 2 == 1)
            number *= base;

        base *= base;
        power /= 2;
    }

    return number;
}

bool ValidateVillage(Village village) {
    unsigned long long c_elves_2, c_elves_3, c_elves_5;
    
    // Możliwe liczby elfów w danej wiosce
    c_elves_2 = EbS(2, BtD(village.log_entry));
    c_elves_3 = EbS(3, BtD(village.log_entry));
    c_elves_5 = EbS(5, BtD(village.log_entry));

    if (village.current_elves != c_elves_2 &&
        village.current_elves != c_elves_3 &&
        village.current_elves != c_elves_5)
        return false;

    return true;
}
