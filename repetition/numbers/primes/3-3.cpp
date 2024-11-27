#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>
using std::cout;
using std::ifstream;
using std::ofstream;

const unsigned FILE_LEN = 100;
const unsigned MAX_NUM = 1000000;

struct Num {
    unsigned val; // Wartość
    unsigned nos = 0; // Liczba sposobów na przedstawienie jej jako sumę dwóch liczb pierwszych
};

void GetArray(Num nums[]);
void PrepareArrayForSoE(bool is_prime[]);
void SoE(bool is_prime[]);
unsigned CountPrimes(bool is_prime[]);
void CreatePrimeArray(unsigned primes[], bool is_prime[]);
void GetNumOfSums(Num nums[], unsigned primes[]);
void GetNumOfSums2(Num nums[], unsigned primes[], unsigned nop);
void WriteAnswer(Num nums[]);

int main() {
    unsigned index, nop; // nop := liczba liczb pierwszych
    bool is_prime[MAX_NUM];
    Num nums[FILE_LEN];

    GetArray(nums); // Otrzymywanie liczb z pliku
    PrepareArrayForSoE(is_prime); // Przygotowywanie tablicy dla sita
    SoE(is_prime); // Algorytm Sita Eratostenesa
    
    nop = CountPrimes(is_prime);
    unsigned primes[nop]; // Tworzenie tablicy z liczbami pierwszymi
    CreatePrimeArray(primes, is_prime); // Wypełnienie jej
    GetNumOfSums(nums, primes); // Zliczanie rozkładów na sumy liczb pierwszych
    // GetNumOfSums2(nums, primes, nop); // Zliczanie rozkładów na sumy liczb pierwszych
    WriteAnswer(nums); // Znalezienie min/maxa i zwrócenie odpowiedzi

    return 0;
}

// Funkcja otrzymująca tablicę liczb z pliku
void GetArray(Num nums[]) {
    unsigned index;
    ifstream infile;
    infile.open("liczby.txt"); 
    if (!infile.good()) {
        cout << "Plik wejściowy nie mógł być otwarty." << "\n";
        exit(1);
    }

    for (index = 0; index < FILE_LEN; ++index) {
        infile >> nums[index].val; 
    }

    infile.close();
}

// Funkcja przygotowująca tablicę do zastosowania algorytmu sita
void PrepareArrayForSoE(bool is_prime[]) {
    unsigned index;
    is_prime[0] = false;
    is_prime[1] = false;
    is_prime[2] = true;

    for (index = 3; index < MAX_NUM; index++) {
        if (index % 2 == 0)
            is_prime[index] = false;
        else
            is_prime[index] = true;
    }
}

// Algorytm sita eratostenesa
void SoE(bool is_prime[]) {
    unsigned index, pfactor;
    for (pfactor = 3; pfactor * pfactor <= MAX_NUM; pfactor += 2) {
        if (!is_prime[pfactor])
            continue;

        for (index = pfactor * pfactor; index <= MAX_NUM; index += 2 * pfactor)
            is_prime[index] = false;
    }
}

// Funkcja zliczająca liczby pierwsze
unsigned CountPrimes(bool is_prime[]) {
    unsigned index, counter = 1; // 2
    for (index = 3; index < MAX_NUM; index += 2) {
        if (is_prime[index])
            counter++;
    }
    return counter;
}

// Funkcja tworząca tablicę z liczbami pierwszymi
void CreatePrimeArray(unsigned primes[], bool is_prime[]) {
    unsigned index, pindex = 0;
    for (index = 0; index < MAX_NUM; ++index) {
        if (!is_prime[index])
            continue;

        primes[pindex] = index;
        pindex++;
    }
}

// Sprawdzanie liczby możliwych rozkładów liczb z pliku na sumę dwóch liczb pierwszych
void GetNumOfSums(Num nums[], unsigned primes[]) {
    unsigned num_index, index_x, index_y; 
    // Iteracja przez wszystkie liczby w nums
    cout << "\n";
    for (num_index = 0; num_index < FILE_LEN; num_index++) {
        // Iteracja przez wszystkie liczby pierwsze (do sprawdzanej liczby - najmniejsza liczba pierwsza)
        for (index_y = 0; primes[index_y] <= nums[num_index].val - 2; index_y++) {
            // maksymalna wartość primes[index_x] + primes[index_y] dla każdego index_y
            // wynosi 2 * primes[index_y], dlatego można pominąć wszystkie index_y
            // do momentu, gdy 2 * primes[index_y] jest mniejszy od szukanej liczby
            // poprawia wydajność o ~30%
            while (2 * primes[index_y] < nums[num_index].val)
                index_y++;
             
            // Iteracja przez wszystkie liczby pierwsze do przekątnej iloczynu karteznańskiego
            for (index_x = 0; index_x <= index_y && primes[index_x] <= nums[num_index].val - 2; index_x++)
                // Inkrementacja liczby sum jeżeli suma tych dwóch liczb pierwszych równa się sprawdzanej liczbie
                if (primes[index_x] + primes[index_y] == nums[num_index].val)
                    nums[num_index].nos++;
        }

        // Magia z ANSI Escape Codami (mam nadzieję że działa na windowsie)
        cout << "\x1b[1A\x1b[2K";
        // cout << num_index + 1 << " / " << FILE_LEN << "\n";
        cout << ((num_index + 1) * FILE_LEN) / 100 << "%" << "\n";
    }
}

void GetNumOfSums2(Num nums[], unsigned primes[], unsigned nop) {
    unsigned a, b, num_index;
    cout << "\n";
    for (b = 0; b < nop; ++b) {
        for (a = b + 1; a < nop - (b + 1); ++a)
            for (num_index = 0; num_index < FILE_LEN; num_index++)
                if (nums[num_index].val == primes[a] + primes[b])
                    nums[num_index].nos++;
        cout << "\x1b[1A\x1b[2K";
        cout << b << " / " << nop << "\n";
    }
}

// Funkcja wypisująca odpowiedź do pliku
// (lub gdy nie jest on dostępny do STDOUT)
void WriteAnswer(Num nums[]) {
    unsigned index;
    Num max_num, min_num;

    // Maksymalna wartość unsigned inta ------V
    max_num.nos = 0; min_num.nos = (unsigned) 2*INT_MAX + 1; 
    max_num.val = nums[0].val; min_num.val = nums[0].val;

    // Sprawdzanie minimalnej i maksymalnej wartości możliwych sum
    for (index = 0; index < FILE_LEN; ++index) {
        if (nums[index].nos > max_num.nos)
            max_num = nums[index];
        if (nums[index].nos < min_num.nos)
            min_num = nums[index];
    }

    ofstream outfile;
    outfile.open("wyniki3.txt", std::ios::app); 
    if (!outfile.good()) {
        cout << "Plik wyjściowy nie mógł być otwarty." << "\n";
        cout << "MAX: {" << max_num.val << "; " << max_num.nos << "}" << "\n";
        cout << "MIN: {" << min_num.val << "; " << min_num.nos << "}" << "\n";
        exit(1);
    }

    outfile << "3.3 --> MAX: {" << max_num.val << "; " << max_num.nos << "}" << "\n";
    outfile << "        MIN: {" << min_num.val << "; " << min_num.nos << "}" << "\n";

    outfile.close();
}
