#include <iostream>
#include <fstream>
using std::cout;
using std::ifstream;
using std::ofstream;
using std::string;

const unsigned KEY_LEN = 15;
const string INFILE = "szyfr2.txt";
const string OUTFILE = "wyniki_szyfr2.txt";

void GetData(string &text, unsigned key[]);
string Encode(string text, unsigned key[]);
string Decode(string text, unsigned key[]);
void ReturnData(string text, unsigned key[]);

int main() {
    string text;
    unsigned key[KEY_LEN];
    GetData(text, key);
    ReturnData(text, key);

    return 0;
}

void GetData(string &text, unsigned key[]) {
    unsigned index;
    ifstream infile;
    infile.open(INFILE);

    if (!infile.good()) {
        cout << "Plik wejściowy nie mógł być otwarty." << "\n";
        exit(1);
    }

    // Pobieranie tekstu do zaszyfrowania
    infile >> text;

    // Pobieranie klucza
    for (index = 0; index < KEY_LEN; index++)
        infile >> key[index];

    infile.close();
}

string Encode(string text, unsigned key[]) {
    char tmp;
    unsigned index, swap_index;

    for (index = 0; index < text.size(); index++) {
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
    string encoded_text, decoded_text;

    if (!outfile.good()) {
        cout << "Plik wyjściowy nie mógł być otwarty." << "\n";
        exit(1);
    }

    outfile << "/// 76.2 ///" << "\n";
    outfile << Encode(text, key) << "\n";

    outfile.close();
}
