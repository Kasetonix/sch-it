#include <iostream>
#include <fstream>
using std::cout;
using std::ifstream;
using std::ofstream;
using std::string;

const unsigned KEY_LEN = 6;
const string INFILE = "szyfr3.txt";
const string OUTFILE = "wyniki_szyfr3.txt";

void GetText(string &text);
string Decode(string text, unsigned key[]);
void ReturnData(string text, unsigned key[]);

int main() {
    string text;
    unsigned key[KEY_LEN] = {6, 2, 4, 1, 5, 3};
    GetText(text);
    ReturnData(text, key);

    return 0;
}

void GetText(string &text) {
    unsigned index;
    ifstream infile;
    infile.open(INFILE);

    if (!infile.good()) {
        cout << "Plik wejściowy nie mógł być otwarty." << "\n";
        exit(1);
    }

    // Pobieranie tekstu do zaszyfrowania
    infile >> text;
    infile.close();
}

string Decode(string text, unsigned key[]) {
    char tmp;
    int index, swap_index;

    for (index = text.size() - 1; index >= 0; index--) {
        swap_index = key[index % KEY_LEN] - 1; // -1, bo klucz liczy indeksy od 1

        if (index == swap_index)
            continue;

        // Zamiana znaków
        tmp = text[swap_index];
        text[swap_index] = text[index];
        text[index] = tmp;
    }

    return text;
}

void ReturnData(string text, unsigned key[]) {
    ofstream outfile;
    outfile.open(OUTFILE);

    if (!outfile.good()) {
        cout << "Plik wyjściowy nie mógł być otwarty." << "\n";
        exit(1);
    }

    outfile << "/// 76.3 ///" << "\n";
    outfile << Decode(text, key) << "\n";

    outfile.close();
}
