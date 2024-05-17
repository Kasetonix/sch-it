#include <iostream>

using std::cout;
using std::cin;

const unsigned short N = 15;
const unsigned short DENOM[N] = { 50000, 20000, 10000, 5000, 2000, 1000, 500, 200, 100, 50, 20, 10, 5, 2, 1 };
void Change(unsigned short money, unsigned short change[]);
void PrintChange(unsigned short change[]);

int main() {
    unsigned short change[15] = { 0 };
    unsigned short money;

    cout << "Podaj resztę do wydania: "; cin >> money;
    Change(money, change);
    PrintChange(change);

    return 0;
}

void Change(unsigned short money, unsigned short change[]) {
    unsigned short index;

    // Iterujemy po każdym nominale
    for (index = 0; index < N; index++) {
        // dzielimy kwotę przez obecny nominał - otrzymujemy liczbę
        // banknotów / monet o danym nominale
        change[index] = money / DENOM[index];
        // kwotą staje się reszta z dzielenia obecnej kwoty
        // przez nominał - pozostałość z poprzedniego dzielenia
        money %= DENOM[index];
    }
}

void PrintChange(unsigned short change[]) {
    unsigned short index;

    for (index = 0; index < N; index++)
        if (change[index])
            cout << DENOM[index] << ": " << change[index] << "x" << "\n";
}
