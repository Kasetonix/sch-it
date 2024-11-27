#include <iostream>
#include <fstream>
using std::cout;
using std::ifstream;
using std::ofstream;

const unsigned FILE_LEN = 1000;
void GetNums(unsigned nums[]);
bool IsPrime(unsigned num);
void ReturnPrimes(unsigned nums[]);

int main() {
    unsigned nums[FILE_LEN];
    GetNums(nums);
    ReturnPrimes(nums);

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

bool IsPrime(unsigned num) {
    unsigned factor;
    
    // Dwa i trzy są liczbami pierwszymi
    if (num == 2)
        return true;
    if (num == 3)
        return true;

    // Wszystkie liczby pierwsze począwszy od pięć posiadają
    // formę 6n+1 lub 6n+5
    if (num % 6 != 1 && num % 6 != 5)
        return false;

    // Iteracja po wszystkich dzielnikach
    for (factor = 2; factor * factor <= num; ++factor)
        if (num % factor == 0)
            return false;

    return true;
} 

void ReturnPrimes(unsigned nums[]) {
    unsigned index, counter = 0;
    ofstream outfile;
    outfile.open("pierwsze.txt");
    if (!outfile.good()) {
        cout << "Plik nie mógł być otwarty." << "\n";
        exit(1);
    }

    for (index = 0; index < FILE_LEN; index++)
        if (IsPrime(nums[index])) {
            outfile << nums[index] << "\n"; 
            counter++;
        }

    outfile << "Liczba liczb pierwszych: " << counter << "\n";
    outfile.close();
}
