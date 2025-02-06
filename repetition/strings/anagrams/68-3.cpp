#include <algorithm>
#include <iostream>
#include <fstream>

using std::cout;
using std::sort;
using std::string;
using std::ifstream;
using std::ofstream;

const unsigned FN = 2*1000;
const string INFILE = "dane_napisy.txt";
const string OUTFILE = "wyniki_anagramy.txt";

void GetStrings(string str[]);
string SortString(string str);
void SortStringArray(string str[]);
void ReturnData(string str[]);

int main() {
    string str[FN];
    unsigned index;
    GetStrings(str);
    SortStringArray(str);
    ReturnData(str);

    return 0;
}

void GetStrings(string str[]) {
    unsigned index;
    ifstream infile;
    infile.open(INFILE);
    if (!infile.good()) {
        cout << "Plik Wejściowy nie mógł być otwarty." << "\n";
        exit(1);
    }

    for (index = 0; index < FN; ++index)
        infile >> str[index];

    infile.close();
}

string SortString(string str) {
    sort(str.begin(), str.end());
    return str;
}

void SortStringArray(string str[]) {
    unsigned index;
    // Sortowanie znaków w każdy stringu
    for (index = 0; index < FN; ++index)
        str[index] = SortString(str[index]);

    // Sortowanie alfabetycznie tablicy stringów
    sort(str, str + FN);
}

// Przyjmuje posortowaną tablicę posortowanych stringów
void ReturnData(string str[]) {
    unsigned index, counter = 1, max_chain = 0;

    ofstream outfile;
    outfile.open(OUTFILE, std::ios::app);
    if (!outfile.good()) {
        cout << "Plik Wyjściowy nie mógł być otwarty." << "\n";
        exit(1);
    }

    for (index = 1; index < FN; ++index) {
        // Resetowanie licznika
        if (str[index - 1] != str[index]) {
            counter = 1;
            continue;
        }

        counter++;
        if (counter > max_chain)
            max_chain = counter;
    }

    outfile << "\n" << "/// 68.3 ///" << "\n";
    outfile << "Liczba napisów będących wzajemnie anagramami: " << max_chain << "\n";
    
    outfile.close();
}
