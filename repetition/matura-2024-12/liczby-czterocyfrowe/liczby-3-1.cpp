#include <cmath>
#include <iostream>
#include <fstream>
using std::sqrt;
using std::floor;
using std::string;
using std::ifstream;
using std::ofstream;

const unsigned LEN = 2000;
const string INFILE = "liczby.txt";
const string OUTFILE = "wyniki3.txt";
void GetData(unsigned num[]);
bool IsSquare(unsigned num);
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

bool IsSquare(unsigned num) {
    if (num == floor(sqrt(num)) * floor(sqrt(num)))
        return true;
    return false;
}

void ReturnData(unsigned num[]) {
    unsigned index, counter = 0;
    ofstream outfile;
    outfile.open(OUTFILE, std::ios::app);

    outfile << "/// 3.1 ///" << "\n";
    for (index = 0; index < LEN; ++index) {
        if (IsSquare(num[index])) {
            outfile << "Pierwsza liczba będąca kwadratem: " << num[index] << "\n";
            counter++;
            break;
        }
    }

    for (index++; index < LEN; ++index) {
        if (IsSquare(num[index])) {
            counter++;
        }
    }

    outfile << "Liczba liczb będących kwadratami: " << counter << "\n";
    outfile.close();
}
