#include <iostream>
#include <fstream>
using std::cout;
using std::ofstream;

void PrepareTable(bool is_prime[], unsigned int max);
void SoE(bool is_prime[], unsigned int max); 
unsigned int CreateTable(unsigned int primes[], bool is_prime[], unsigned int max);

int main() {
    ofstream outfile;
    outfile.open("sito.txt", std::ios::app);
    if (!outfile.good()) {
        cout << "Plik nie mógł być otwarty." << "\n";
        return 1;
    }

    unsigned int max = 1200, prime_max_num = 200, prime_num;
    bool is_prime[max];
    unsigned int primes[prime_max_num];

    PrepareTable(is_prime, max);
    SoE(is_prime, max);
    prime_num = CreateTable(primes, is_prime, max);

    unsigned int index;
    for (index = 0; index < prime_num; index++) 
        outfile << primes[index] << " ";
    outfile << "\n";

    return 0;
}

void PrepareTable(bool is_prime[], unsigned int max) {
    unsigned int index;

    // Wypełnianie tablicy
    is_prime[0] = false;
    is_prime[1] = false;
    is_prime[2] = true;

    for (index = 3; index <= max; index++) {
        if (index % 2 == 0)
            is_prime[index] = false;
        else 
            is_prime[index] = true;
    }
}

// Funkcja tworząca tablicę z pierwszością liczb do maxa
// (zwraca ona liczbę otrzymanych liczb pierwszych)
void SoE(bool is_prime[], unsigned int max) {
    unsigned int pdivisor, index; 

    // Dla każdego potencjalnego dzielnika...
    for (pdivisor = 2; pdivisor * pdivisor <= max; pdivisor++) {
        // Sprawdzanie czy jest on w tablicy -> jak nie przechodzenie do następnego
        if (is_prime[pdivisor] == false)
            continue;

        // dla każdej liczby oznaczonej jako pierwsza usuwanie wszystkich jej wielokrotności
        for (index = 2 * pdivisor; index <= max; index += pdivisor) {
            is_prime[index] = false;
        }
    }
}

unsigned int CreateTable(unsigned int primes[], bool is_prime[], unsigned int max) {
    unsigned int index, prime_index = 0;
    for (index = 0; index <= max; index++) {
        if (!is_prime[index])
            continue;
        primes[prime_index] = index;
        prime_index++;
    }
    return prime_index;
}

