#include <algorithm>
#include <iostream>
#include <fstream>

using std::cout;
using std::sort;
using std::string;
using std::ifstream;
using std::ofstream;

const unsigned FN = 1000;
const string INFILE = "dane_napisy.txt";
const string OUTFILE = "wyniki_anagramy.txt";

struct Pair { string str1; string str2; };

void GetPairs(Pair pair[]);
string SortString(string str);
bool AreAnagrams(Pair pair);
void ReturnData(Pair pair[]);

int main() {
    Pair pair[FN];
    unsigned index, counter = 0;
    GetPairs(pair);
    ReturnData(pair);

    return 0;
}

void GetPairs(Pair pair[]) {
    unsigned index;
    ifstream infile;
    infile.open(INFILE);
    if (!infile.good()) {
        cout << "Plik Wejściowy nie mógł być otwarty." << "\n";
        exit(1);
    }

    for (index = 0; index < FN; ++index)
        infile >> pair[index].str1 >> pair[index].str2;

    infile.close();
}

string SortString(string str) {
    sort(str.begin(), str.end());
    return str;
}

bool AreAnagrams(Pair pair) {
    if (SortString(pair.str1) == SortString(pair.str2))
        return true;
    return false;
}

void ReturnData(Pair pair[]) {
    unsigned index, counter = 0;

    ofstream outfile;
    outfile.open(OUTFILE, std::ios::app);
    if (!outfile.good()) {
        cout << "Plik Wyjściowy nie mógł być otwarty." << "\n";
        exit(1);
    }

    // Zliczanie anagramów 
    for (index = 0; index < FN; ++index)
        if (AreAnagrams(pair[index]))
            counter++;

    outfile << "\n" << "/// 68.2 ///" << "\n";
    outfile << "Liczba anagramów: " << counter << "\n";
    
    outfile.close();
}
