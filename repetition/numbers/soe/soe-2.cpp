#include <iostream>
using std::cout;
using std::ofstream;

void PrepareTable(bool is_prime[], unsigned int max);
void SoE(bool is_prime[], unsigned int max); 
bool IsTwinPrime(unsigned int prime, bool is_prime[]);

int main() {
    unsigned int a = 2, b = 1000000, index;
    bool is_prime[b];

    PrepareTable(is_prime, b);
    SoE(is_prime, b);

    for (index = 0; index < b; index++) 
        if (IsTwinPrime(index, is_prime))
            cout << "(" << index << "; " << index + 2 << ")" << "\n";

    return 0;
}

void PrepareTable(bool is_prime[], unsigned int max) {
    unsigned int index;

    // Wypełnianie tablicy
    is_prime[0] = false;
    is_prime[1] = false;
    is_prime[2] = true;

    // zaznaczanie liczb parzysych jako nie-pierwszych, a
    // nieparzystych jako potencjalnie pierwszych
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
        // Sprawdzanie czy jest on w tablicy -> jak nie, przechodzenie do następnego
        if (is_prime[pdivisor] == false)
            continue;

        // dla każdej liczby oznaczonej jako pierwsza usuwanie wszystkich jej wielokrotności
        for (index = 2 * pdivisor; index <= max; index += pdivisor) {
            is_prime[index] = false;
        }
    }
}

bool IsTwinPrime(unsigned int prime, bool is_prime[]) {
    if (is_prime[prime] && is_prime[prime + 2])
        return true;
    return false;
}

