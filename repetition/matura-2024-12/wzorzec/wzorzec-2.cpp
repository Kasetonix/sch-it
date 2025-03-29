#include <fstream>
#include <iostream>
#include <vector>
using std::cout;
using std::vector;
using std::string;
using std::ifstream;
using std::ofstream;

const string INFILE = "szyfrogram.txt";
const string OUTFILE = "wyniki4.txt";
const unsigned NUM = 10;
struct Set {
    unsigned sublen;
    string str;
};

void GetData(Set set[]);
bool MonoSubtext(string sub);
bool Repeat(string c_sub, vector<string> sub);
unsigned SubtextNum(Set set);
void ReturnData(Set set[]);

int main() {
    Set set[NUM];
    GetData(set);
    ReturnData(set);

    return 0;
}

void GetData(Set set[]) {
    unsigned index;
    ifstream infile;
    infile.open(INFILE);
    if (!infile.good()) {
        cout << "Plik wejściowy nie mógł być otwarty." << "\n";
        exit(1);
    }

    for (index = 0; index < NUM; index++)
        infile >> set[index].sublen >> set[index].str;

    infile.close();
}

// Funkcja sprawdzająca czy podtekst składa się tylko z jednego znaku
bool MonoSubtext(string sub) {
    bool mono = true;
    unsigned index;

    // Iteracja po całym stringu i sprawdzanie, czy znajdzie się chociaż
    // jeden znak inny niż poprzedni
    for (index = 1; index < sub.size(); index++) {
        if (sub[index - 1] != sub[index]) {
            mono = false;
            break;
        }
    }

    return mono;
}

// Funkcja sprawdzająca czy podtekst znajduje się już w wectorze 
bool Repeat(string c_sub, vector<string> sub) {
    unsigned index;
    bool repeat = false;

    // Iteracja po całym wektorze i sprawdzanie, czy sprawdzany podtekst
    // już się w nim znajduje
    for (index = 0; index < sub.size(); index++) {
        if (sub[index] == c_sub) {
            repeat = true;
            break;
        }
    }
    
    return repeat;
}

// Funkcja zliczająca unikatowe podteksty
unsigned SubtextNum(Set set) {
    unsigned index;
    string c_sub;
    vector<string> sub;

    for (index = 0; index < set.str.size() - set.sublen; index++) {
        c_sub = set.str.substr(index, set.sublen);

        // Pomijanie podtekstów złożonych z jednego znaku
        // lub już powtarzających się
        if (MonoSubtext(c_sub) || Repeat(c_sub, sub))
            continue;

        sub.push_back(c_sub);
    }

    // Liczba unikatowych podtekstów
    return sub.size();
}

void ReturnData(Set set[]) {
    unsigned index;
    ofstream outfile;
    outfile.open(OUTFILE, std::ios::app);
    if (!outfile.good()) {
        cout << "Plik wejściowy nie mógł być otwarty." << "\n";
        exit(1);
    }

    outfile << "/// 4.2 ///" << "\n";
    for (index = 0; index < NUM; index++)
        outfile << index + 1 << ": " << SubtextNum(set[index]) << "\n";
    outfile << "\n";

    outfile.close();
}
