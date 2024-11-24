#include <iostream>
using std::cout;
using std::cin;
using std::ofstream;

unsigned int Indexify(unsigned int num);
unsigned int Deindexify(unsigned int num);
void PrepareTable(bool is_prime[], unsigned int max);
void SoE(bool is_prime[], unsigned int max); 

int main() {
    unsigned int a, b, index;
    
    cout << "Podaj granice przedziału [a; b], w którym szukać liczb pierwszych: " << "\n";
    cout << "    a: "; cin >> a;
    cout << "    b: "; cin >> b;

    // Uwzględnianie dwójki, nieobecnej w tablicy
    if (a <= 2)
        cout << "2 ";

    // Używamy b - 1, bo parzyste są za duże, a nieparzystym to nic nie zmienia
    bool is_prime[Indexify(b - 1)];

    PrepareTable(is_prime, Indexify(b - 1));
    SoE(is_prime, Indexify(b - 1));

    // Wypisywanie wszystkich liczb pierwszych
    for (index = a; index <= b; index += 2)
        if (is_prime[Indexify(index)])
            cout << index << " ";

    cout << "\n";

    return 0;
}

// Funkcja zamieniająca liczbę na odpowiadający jej indeks
unsigned int Indexify(unsigned int num) {
    if (num % 2 == 0)
        num = num / 2;
    else
        num = (num - 1) / 2;

    return num;
}

// Funkcja odwrotna do poprzedniej
// (Zwraca tylko nieparzyste)
unsigned int Deindexify(unsigned int num) {
    return 2 * num + 1;
}

void PrepareTable(bool is_prime[], unsigned int max) {
    unsigned int index;
    is_prime[0] = false; // <- jedynka
    // Wypełnienie tablicy (wszystkie indeksy traktujemy jako nieparzyste,
    // więc ustawiamy je na potencjalnie pierwsze)
    // Indeks tablicy = (liczba - 1) / 2
    for (index = 1; index <= max; index++) {
        is_prime[index] = true;
    }
}

// Funkcja tworząca tablicę z pierwszością liczb do maxa
void SoE(bool is_prime[], unsigned int max) {
    unsigned int pfactor, index; 

    // Dla każdego potencjalnego dzielnika...
    for (pfactor = 3; Indexify(pfactor) * Indexify(pfactor) <= max; pfactor += 2) {
        // Sprawdzanie czy jest on w tablicy -> jak nie, przechodzenie do następnego
        if (!is_prime[Indexify(pfactor)])
            continue;

        // dla każdej liczby oznaczonej jako pierwsza usuwanie wszystkich jej wielokrotności
        // zaczynanie od kwadratu liczby, bo wszystkie poprzednie dzielniki zostały usunięte
        // we wcześniejszych iteracjach pętli
        // dodajemy dwa razy potencjalny dzielnik żeby nie szukać liczb parzystych
        for (index = pfactor * pfactor; Indexify(index) <= max; index += 2 * pfactor) {
            is_prime[Indexify(index)] = false;
        }
    }
}
