#include <iostream>
using std::cout;
// using std::cin;
using std::ofstream;

unsigned int Indexify(unsigned int num);
unsigned int Deindexify(unsigned int num);
void PrepareTable(bool is_prime[], unsigned int max);
void SoE(bool is_prime[], unsigned int max); 
unsigned int Count_Primes(bool is_prime[], unsigned int max);
void CreateTable(unsigned int primes[], bool is_prime[], unsigned int max);

int main() {
    unsigned int a = 2, b = 1000, index;
    
    // Po odkomentowaniu poniższego komentarza działa też dla dowolnego przedziału
    
    // cout << "Podaj granice przedziału [a; b], w którym szukać liczb półpierwszych: " << "\n";
    // cout << "    a: "; cin >> a;
    // cout << "    b: "; cin >> b;

    // Stosujemy b - 1, bo parzyste wychodzą za duże a nieparzystym to nic nie zmienia
    bool is_prime[Indexify(b - 1)];

    PrepareTable(is_prime, Indexify(b - 1));
    SoE(is_prime, Indexify(b - 1));

    // Tworzenie tablicy z liczbami pierwszymi o odpowiedniej długości
    unsigned int primes[Count_Primes(is_prime, Indexify(b - 1))];
    CreateTable(primes, is_prime, Indexify(b - 1));

    unsigned int index_x = 0, index_y = 0;
    // W zasadzie połowa iloczynu kartezjańskiego primes x primes uciętego przy kwadracie
    // index_y iteruje się do momentu, gdy pozostaje mniejszy lub równy 
    for (index_y = 0; primes[index_x] * primes[index_y] <= b; index_y++) {
        for (index_x = 0; index_x <= index_y && primes[index_x] * primes[index_y] <= b; index_x++)
            // cout << "i_x = " << index_x << " | i_y = " << index_y << " | x = " << primes[index_x] << " | y = " << primes[index_y] << " | xy = " << primes[index_x] * primes[index_y] << "\n";
            if (primes[index_x] * primes[index_y] >= a)
                cout << primes[index_x] * primes[index_y] << " ";
        index_x = 0;
    }
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

// Tablica przygotowująca tablicę do działania algorytmu sita
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
// (zwraca ona liczbę otrzymanych liczb pierwszych)
void SoE(bool is_prime[], unsigned int max) {
    unsigned int pfactor, index; 

    // Dla każdego potencjalnego dzielnika...
    for (pfactor = 3; pfactor * pfactor <= max; pfactor += 2) {
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

// Funkcja zliczająca liczby pierwsze 
unsigned int Count_Primes(bool is_prime[], unsigned int max) {
    unsigned int index, prime_count = 0;
    for (index = 0; index <= max; index++)
        if (is_prime[index])
            prime_count++;

    // Uwzględniając dwójkę nie istniejącą w tablicy
    return prime_count + 1;
}

void CreateTable(unsigned int primes[], bool is_prime[], unsigned int max) {
    unsigned int index, primes_index = 1;
    primes[0] = 2;
    for (index = 1; index <= max; index++) {
        if (!is_prime[index])
            continue;

        primes[primes_index] = Deindexify(index);
        primes_index++;
    }
}

