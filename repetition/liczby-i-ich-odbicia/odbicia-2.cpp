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

unsigned Mirror(unsigned num) {
    unsigned mirrored = 0, index;
    while (num > 0) {
        mirrored = 10 * mirrored + num % 10;
        num /= 10;
    }

    return mirrored;
}

unsigned AbsVal(int num) {
    return num >= 0 ? num : -num; 
}

void Return(unsigned num[]) {
    unsigned index, max_index, max = 0, diff;
    ofstream outfile;
    outfile.open(OUTFILE, std::ios::app);
    if (!outfile.good()) {
        cout << "Plik wyjściowy nie mógł być otwarty." << "\n";
        exit(1);
    }

    outfile << "\n" << "/// 4.2 ///" << "\n";
    for (index = 0; index < LEN; index++) {
        diff = AbsVal(num[index] - Mirror(num[index]));
        if (diff > max) {
            max = diff;
            max_index = index;
        }
    }

    outfile << "Liczba:  " << num[max_index] << "\n";
    outfile << "Różnica: " << max << "\n";

    outfile.close();
}
