#include <cstdlib>
#include <iostream>
#include <fstream>
using std::cout;
using std::ifstream;
using std::ofstream;

const unsigned FILE_LEN = 100;

void GetArray(unsigned array[]);
bool IsPrime(unsigned num);
unsigned CountPrimes(unsigned array[]);
void WriteValue(unsigned prime_num);

int main() {
    unsigned nums[FILE_LEN], index;
    GetArray(nums);
    WriteValue(CountPrimes(nums));

    return 0;
}

// Funkcja otrzymująca tablicę liczb z pliku
void GetArray(unsigned array[]) {
    unsigned index;
    ifstream infile;
    infile.open("liczby.txt"); 
    if (!infile.good()) {
        cout << "Plik wejściowy nie mógł być otwarty." << "\n";
        exit(1);
    }

    for (index = 0; index < FILE_LEN; ++index) {
        infile >> array[index]; 
    }

    infile.close();
}

// Funkcja sprawdzająca pierwszość liczby
bool IsPrime(unsigned num) {
    unsigned pfactor; // potencjalny dzielnik
    // Sprawdzanie podzielności przez każdy potencjalny dzielnik
    // do pierwiastka z liczby (symetria rozkładu dzielników względem
    // kwadratu liczby)
    for (pfactor = 2; pfactor * pfactor <= num; pfactor++)
        if (num % pfactor == 0)
            return false;
    return true;
}

// Funkcja zliczająca liczbę liczb pierwszych
// w zbiorze liczb x-1
unsigned CountPrimes(unsigned array[]) {
    unsigned index, counter = 0;
    for (index = 0; index < FILE_LEN; index++)
        if (IsPrime(array[index] - 1))
            counter++;
    return counter;
}

// Funkcja wypisująca odpowiedź do pliku
// (lub gdy nie jest on dostępny do STDOUT)
void WriteValue(unsigned prime_num) {
    ofstream outfile;
    outfile.open("wyniki3.txt", std::ios::app); 
    if (!outfile.good()) {
        cout << "Plik wyjściowy nie mógł być otwarty." << "\n";
        cout << "Liczba liczb pierwszych: " << prime_num << "\n";
        exit(1);
    }

    outfile << "3.2 --> Liczba liczb pierwszych: " << prime_num << "\n";
    outfile.close();
}
