#include <iostream>
#include <set>
using std::cout;
using std::cin;
using std::set;
using std::ofstream;

// &primes powoduje działanie na oryginalnych danych, a nie kopiowanie ich
// i działanie na kopiach
void PrepareSet(set<unsigned int> &primes, unsigned int max);
void SoE(set<unsigned int> &primes, unsigned int max);

int main() {
    unsigned int a, b, index;
    set<unsigned int> primes;
    set<unsigned int>::iterator it;
    
    cout << "Podaj granice przedziału [a; b], w którym szukać liczb pierwszych: " << "\n";
    cout << "    a: "; cin >> a;
    cout << "    b: "; cin >> b;

    PrepareSet(primes, b);
    SoE(primes, b);

    // początkowa wartość iteratora to najmniejszy element zbioru większy lub równy a
    // używamy a - 1 bo upper_bound znajduje najmniejszy element zbioru większy od argumentu
    for (it = primes.find(*primes.upper_bound(a - 1)); it != primes.end(); it++) {
        cout << *it << " ";
    }

    cout << "\n";

    return 0;
}

// Funkcja wypełniająca zbiór liczbami nieparzystymi (i dwa)
void PrepareSet(set<unsigned int> &primes, unsigned int max) {
    unsigned int index;
    primes.insert(2);
    for (index = 3; index <= max; index += 2)
        primes.insert(index);
}

// Funkcja tworząca tablicę z pierwszością liczb do maxa
// (zwraca ona liczbę otrzymanych liczb pierwszych)
void SoE(set<unsigned int> &primes, unsigned int max) {
    unsigned int index, pfactor;
    // Dodajemy do iteratora 2 lub 2 * pdivisor by omijać liczby parzyste
    // Iteracja po kolejnych potencjalnych dzielnikach
    for (pfactor = 3; pfactor * pfactor <= max; pfactor += 2)
        // Usuwanie kolejnych wielokrotności potencjalnego dzielnika
        // (z wyjątkiem parzystych, których w zbiorze nie ma)
        for (index = 3 * pfactor; index <= max; index += 2 * pfactor)
            primes.erase(index);
}
