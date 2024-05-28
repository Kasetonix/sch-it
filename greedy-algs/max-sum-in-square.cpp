#include <cstdlib>
#include <iostream>
using std::cout;

const unsigned short CR = 5;

void RandTab(unsigned short tab[][CR]);
unsigned short CalcSum(unsigned short tab[][CR]);
void Draw(unsigned short tab[][CR]);

int main() {
    unsigned short tab[CR][CR];
    srand(time(NULL));
    RandTab(tab);
    Draw(tab);
    cout << "Suma: " << CalcSum(tab) << "\n";
    return 0;
}

void RandTab(unsigned short tab[][CR]) {
    unsigned short col, row;
    // Dla każdego elementu tablicy losowanie liczby [1;9]
    for (col = 0; col < CR; col++)
        for (row = 0; row < CR; row++)
            tab[col][row] = rand() % 9 + 1;
}

unsigned short CalcSum(unsigned short tab[][CR]) {
    unsigned short sum = tab[0][0];
    unsigned short index, col = 0, row = 0;

    for (index = 0; index < 2*(CR-1); index++) {
        if (col + 1 == CR) // przypadek, gdy jesteśmy w ostatniej kolumnie
            row++;
        else if (row + 1 == CR) // przypadek, gdy jesteśmy w ostatnim rzędzie
            col++;

        // sprawdzenie, czy pole na dół jest większe od pola na prawo
        else if (tab[col+1][row] > tab[col][row+1])
            col++;
        else if (tab[col][row+1] > tab[col+1][row])
            row++;

        sum += tab[col][row];
    }

    return sum;
}

void Draw(unsigned short tab[][CR]) {
    unsigned short col, row;
    // Wypisywanie każdego pola
    for (col = 0; col < CR; col++) {
        for (row = 0; row < CR; row++)
            cout << tab[col][row] << " ";
        cout << "\n";
    }
}
