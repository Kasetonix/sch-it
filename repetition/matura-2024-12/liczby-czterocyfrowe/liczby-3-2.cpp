#include <cmath>
#include <iostream>
#include <fstream>
using std::string;
using std::ifstream;
using std::ofstream;

// const unsigned LEN = 20;
// const string INFILE = "liczby_przyklad.txt";
const unsigned LEN = 2000;
const string INFILE = "liczby.txt";
const string OUTFILE = "wyniki3.txt";
void GetData(unsigned num[]);
unsigned FactorNum(unsigned num);
void ReturnData(unsigned num[]);

int main() {
    unsigned num[LEN];
    GetData(num);
    ReturnData(num);
    return 0;
}

void GetData(unsigned num[]) {
    unsigned index;
    ifstream infile;
    infile.open(INFILE);

    for (index = 0; index < LEN; ++index) {
        infile >> num[index];
    }

    infile.close();
}

// Funkcja zliczająca dzielniki pierwsze
unsigned FactorNum(unsigned num) {
    unsigned counter = 0, factor = 3;
    if (num % 2 == 0) {
        num /= 2;
        counter = 1;
    }

    while (num >= factor) {
        if (num % factor == 0) {
            counter++;
            while (num % factor == 0)
                num /= factor;
        }
        
        factor += 2;
    }

    return counter;
}

void ReturnData(unsigned num[]) {
    unsigned index, counter = 0;
    ofstream outfile;
    outfile.open(OUTFILE, std::ios::app);

    outfile << "\n" << "/// 3.2 ///" << "\n";
    for (index = 0; index < LEN; ++index)
        if (FactorNum(num[index]) >= 5)
            outfile << num[index] << "\n";

    outfile.close();
}
