#include <iostream>
#include <fstream>
#include <string>
using std::string;
using std::cout;
using std::ifstream;
using std::ofstream;

const unsigned ID_LEN = 9;
const unsigned CN_POS = 3;
const unsigned WEIGHT[ID_LEN] = {7, 3, 1, 0, 7, 3, 1, 7, 3};
const unsigned FILE_LEN = 200;
const string INFILE = "identyfikator.txt";
const string OUTFILE = "wyniki4_3.txt";

void GetData(string id[]);
unsigned GetCharValue(char c);
bool Valid(string id);
void ReturnData(string id[]); 

int main() {
    string id[FILE_LEN];
    GetData(id);
    ReturnData(id);
    return 0;
}

void GetData(string id[]) {
    ifstream infile;
    unsigned index;

    infile.open(INFILE);
    if (!infile.good()) {
        cout << "Plik wejściowy nie mógł być otwarty." << "\n";
        exit(1);
    }

    for (index = 0; index < FILE_LEN; index++)
        infile >> id[index];

    infile.close();
}

unsigned GetCharValue(char c) { return unsigned( c - 'A' + 10 ); }

bool Valid(string id) {
    unsigned index, w_index, value, sum = 0;

    // Znaki serii
    for (index = 0; index < CN_POS; index++)
        sum += GetCharValue(id[index]) * WEIGHT[index];
    // Numer
    for (index = CN_POS + 1; index < ID_LEN; index++)
        sum += unsigned (id[index] - '0') * WEIGHT[index];

    // Porównanie cyfry kontrolnej z sumą mod 10
    return unsigned(id[CN_POS] - '0') == sum % 10;
}

void ReturnData(string id[]) {
    ofstream outfile;
    unsigned index;

    outfile.open(OUTFILE);
    if (!outfile.good()) {
        cout << "Plik wyjściowy nie mógł być otwarty." << "\n";
        exit(1);
    }

    outfile << "/// 4.3 ///" << "\n";
    for (index = 0; index < FILE_LEN; index++)
        // Wypisanie nieprawidłowych id
        if (!Valid(id[index]))
            outfile << id[index] << "\n";

    outfile.close();
}
