#include <iostream>
#include <fstream>
using std::cout;
using std::ifstream;
using std::ofstream;
using std::string;

const string INFILE = "anomalie.txt";
const string OUTFILE = "wynik6_2.txt";
const unsigned LEN = 1000; // liczba rzędów
const unsigned NUM = 5; // liczba liczb w rzędzie

void GetData(unsigned num[NUM][LEN]);
unsigned Diff(unsigned num1, unsigned num2);
float GetAvgDiff(unsigned num[NUM][LEN]);
bool IsAnomalous(unsigned num[NUM][LEN], unsigned y, float avg);
string CreateBinNum(unsigned num[NUM][LEN], unsigned last);
unsigned BinToDec(string bin);
void ReturnData(unsigned num[NUM][LEN]);

int main() {
    unsigned num[NUM][LEN];
    GetData(num);
    ReturnData(num);

    return 0;
}

void GetData(unsigned num[NUM][LEN]) {
    unsigned x, y;
    ifstream infile;

    infile.open(INFILE);
    if (!infile.good()) {
        cout << "Plik wejściowy nie mógł być otwarty." << "\n";
        exit(1);
    }

    for (y = 0; y < LEN; y++)
        for (x = 0; x < NUM; x++)
            infile >> num[x][y];

    infile.close();
}

unsigned Diff(unsigned num1, unsigned num2) {
    return num1 > num2 ? num1 - num2 : num2 - num1;
}

float GetAvgDiff(unsigned num[NUM][LEN]) {
    unsigned x, y, diff_sum = 0;

    for (y = 0; y < LEN; y++)
        for (x = 1; x < NUM; x++)
            diff_sum += Diff(num[x][y], num[x-1][y]);

    return float(diff_sum) / ((NUM - 1) * LEN);
}

bool IsAnomalous(unsigned num[NUM][LEN], unsigned y, float avg) {
    unsigned x;

    // Jeżeli każda różnica między kolejnymi elementami wiersza
    // jest większa od średniej, mamy anomalię
    for (x = 1; x < NUM; x++)
        if (Diff(num[x][y], num[x-1][y]) <= avg)
            return false;

    return true;
}

string CreateBinNum(unsigned num[NUM][LEN], unsigned last) {
    unsigned y;
    string bin;
    
    for (y = LEN - last; y < LEN; y++)
        bin += char('0' + IsAnomalous(num, y, GetAvgDiff(num)));

    return bin;
}

unsigned BinToDec(string bin) {
    unsigned long long num = 0, multiplier = 1;
    short index;

    for (index = bin.size() - 1; index >= 0; index--) {
        num += unsigned(bin[index] - '0') * multiplier;
        multiplier *= 2;
    }

    return num;
}

void ReturnData(unsigned num[NUM][LEN]) {
    ofstream outfile;

    outfile.open(OUTFILE);
    if (!outfile.good()) {
        cout << "Plik wyjściowy nie mógł być otwarty." << "\n";
        exit(1);
    }

    outfile << "Liczba powstała z anomalii: " << BinToDec(CreateBinNum(num, 30)) << "\n";

    outfile.close();
}
