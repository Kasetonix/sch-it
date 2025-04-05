#include <cmath>
#include <iostream>
#include <fstream>
using std::cout;
using std::string;
using std::ifstream;
using std::ofstream;

const string INFILE = "liczby.txt";
const unsigned LEN = 100;
const string OUTFILE = "wyniki4.txt";

void GetNums(unsigned num[]);
bool IsPrime(unsigned num);
unsigned Mirror(unsigned num);
void Return(unsigned num[]);

int main() {
    unsigned num[LEN];
    GetNums(num);
    Return(num);

    return 0;
}

void GetNums(unsigned num[]) {
    unsigned index;
    ifstream infile;
    infile.open(INFILE);
    if (!infile.good()) {
        cout << "Plik wejściowy nie mógł być otwarty." << "\n";
        exit(1);
    }

    for (index = 0; index < LEN; index++)
        infile >> num[index];

    infile.close();
}

bool IsPrime(unsigned num) {
    unsigned factor;

    // Liczba jest dwójką:
    if (num == 2)
        return true;

    // Liczba jest podzielna przez dwa lub jest zerem lub jedynką
    if (num % 2 == 0 || num == 0 || num == 1)
        return false;
    
    // Każdy inny przypadek
    for (factor = 3; factor * factor <= num; factor += 2)
        // Jeżeli istnieje dzielnik to liczba nie jest piersza
        if (num % factor == 0)
            return false;

    return true;
}

unsigned Mirror(unsigned num) {
    unsigned mirrored = 0, index;
    while (num > 0) {
        mirrored = 10 * mirrored + num % 10;
        num /= 10;
    }

    return mirrored;
}

void Return(unsigned num[]) {
    unsigned index; 
    ofstream outfile;
    outfile.open(OUTFILE, std::ios::app);
    if (!outfile.good()) {
        cout << "Plik wyjściowy nie mógł być otwarty." << "\n";
        exit(1);
    }

    outfile << "\n" << "/// 4.3 ///" << "\n";
    for (index = 0; index < LEN; index++) {
        if (IsPrime(num[index]) && IsPrime(Mirror(num[index])))
            outfile << num[index] << "\n";
    }

    outfile.close();
}
