#include <iostream>
#include <fstream>
using std::cout;
using std::ifstream;
using std::ofstream;

const unsigned FILE_LEN = 1000;
const unsigned MAX_NUM = 1200;
const unsigned PRIME_LEN = 200;
void GetNums(unsigned nums[]);
void PrepareForSoE(bool is_prime[]);
void SoE(bool is_prime[]);
unsigned CreatePrimeArray(bool is_prime[], unsigned primes[]);
void ReturnPrimes(unsigned primes[], unsigned prime_num);

int main() {
    unsigned nums[FILE_LEN], primes[PRIME_LEN];
    bool is_prime[MAX_NUM];
    unsigned prime_num;

    GetNums(nums);
    PrepareForSoE(is_prime);
    SoE(is_prime);
    prime_num = CreatePrimeArray(is_prime, primes);
    ReturnPrimes(primes, prime_num);

    return 0;
}

// Funkcja pobierająca liczby z pliku
void GetNums(unsigned nums[]) {
    unsigned index;
    ifstream infile;
    infile.open("liczby.txt");
    if (!infile.good()) {
        cout << "Plik nie mógł być otwarty." << "\n";
        exit(1);
    }

    for (index = 0; index < FILE_LEN; index++)
        infile >> nums[index];

    infile.close();
}

// Funkcja przygotowująca tablicę pod algorytm sita
void PrepareForSoE(bool is_prime[]) {
    unsigned index;

    is_prime[0] = false;
    is_prime[1] = false;
    is_prime[2] = true;

    // Nieparzyste są oflagowane jako potencjalnie pierwsze
    for (index = 3; index < MAX_NUM; index += 2)
        is_prime[index] = true;
    // Parzyste automatycznie odrzucamy
    for (index = 4; index < MAX_NUM; index += 2)
        is_prime[index] = false;
}

// Algorytm Sita Eratostenesa
void SoE(bool is_prime[]) {
    unsigned index, cfactor;
    for (cfactor = 3; cfactor * cfactor < MAX_NUM; cfactor += 2) {
        if (is_prime[cfactor] == false)
            continue;

        for (index = cfactor * cfactor; index < MAX_NUM; index += 2 * cfactor)
            is_prime[index] = false;
    }
}

// Funkcja tworząca tablicę liczb pierwszych (przy okazji zwraca ich liczbę)
unsigned CreatePrimeArray(bool is_prime[], unsigned primes[]) {
    unsigned index, pindex = 0;
    for (index = 0; index < MAX_NUM; index++) {
        if (is_prime[index]) {
            primes[pindex] = index;
            pindex++;
        }
    }

    return pindex;
}

// Funkcja zwracająca liczby pierwsze do STDOUT i pliku
void ReturnPrimes(unsigned primes[], unsigned prime_num) {
    unsigned index; 
    ofstream outfile;
    outfile.open("sito.txt");
    if (!outfile.good()) {
        cout << "Plik nie mógł być otwarty." << "\n";
        exit(1);
    }

    for (index = 0; index < prime_num; index++) {
        outfile << primes[index] << "\n";
        cout << primes[index] << " ";
    }
    cout << "\n";

    outfile.close();
}
