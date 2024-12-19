#include <algorithm>
#include <iostream>
#include <fstream>

const unsigned FN = 1000;
using std::cout;
using std::sort;
using std::string;
using std::ifstream;
using std::ofstream;

struct Pair {string str1; string str2;};

void GetPairs(Pair pair[]);
string SortString(string str);
bool AreAnagrams(string str1, string str2);

int main() {
    Pair pair[FN];
    unsigned index, counter = 0;
    GetPairs(pair);

    // Zliczanie anagramów 
    for (index = 0; index < FN; ++index)
        if (AreAnagrams(pair[index].str1, pair[index].str2))
            counter++;

    return 0;
}

void GetPairs(Pair pair[]) {
    unsigned index;
    ifstream infile;
    infile.open("dane_napisy.txt");
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
