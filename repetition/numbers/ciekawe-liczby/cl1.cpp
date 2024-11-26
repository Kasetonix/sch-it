#include <iostream>
#include <fstream>
using std::cout;
using std::ifstream;
using std::ofstream;

const unsigned FILE_LEN = 1000;
void GetArray(unsigned num[]);
unsigned CountOddFactors(unsigned num);
void ReturnAnswer(unsigned num[]);

int main() {
    unsigned num[FILE_LEN];
    GetArray(num);
    ReturnAnswer(num);

    return 0;
}

// Funkcja otrzymująca liczby z pliku
void GetArray(unsigned num[]) {
    unsigned index;
    ifstream infile;
    infile.open("liczby.txt");
    if (!infile.good()) {
        cout << "Plik wejściowy nie mógł by otwarty." << "\n";
        exit(1);
    }

    for (index = 0; index < FILE_LEN; index++)
        infile >> num[index];
}

// Funkcja zliczająca nieparzyste dzielniki
unsigned CountOddFactors(unsigned num) {
    unsigned factor = 2, counter = 0;

    // Sprawdzanie ile czynników pierwszych nieparzystych ma liczba
    while (factor * factor <= num) {
        // Przechodzenie do następnego czynnika
        if (num % factor != 0) {
            factor++;
            continue;
        } 
        // Dla nieparzystego dzielnika inkrementacja licznika
        if (factor % 2 == 1)
            counter++;
        num /= factor;
    }

    // Uwzględnianie ostatniego czynnika
    if (num % 2 == 1)
        counter++;

    return counter;
}

void ReturnAnswer(unsigned num[]) {
    ofstream outfile;
    unsigned index, counter = 0;
    outfile.open("wyniki_liczby.txt", std::ios::app);
    if (!outfile.good()) {
        cout << "Plik wyjściowy nie mógł być otwarty." << "\n";
        exit(1);
    }
    
    for (index = 0; index < FILE_LEN; index++)
        if (CountOddFactors(num[index]))
            counter++;
    cout << counter << "\n";
}
