#include <iostream>
#include <fstream>
using std::cout;
using std::ifstream;
using std::ofstream;
using std::string;

const unsigned PT_NUM = 6;
const unsigned KEY_LEN = 50;
const string INFILE = "szyfr1.txt";
const string OUTFILE = "wyniki_szyfr1.txt";

void GetData(string text[], unsigned key[]);
string Encode(string text, unsigned key[]);
void ReturnData(string text[], unsigned key[]);

int main() {
    string text[PT_NUM];
    unsigned key[KEY_LEN];
    GetData(text, key);
    ReturnData(text, key);

    return 0;
}

void GetData(string text[], unsigned key[]) {
    unsigned index;
    ifstream infile;
    infile.open(INFILE);

    if (!infile.good()) {
        cout << "Plik wejściowy nie mógł być otwarty." << "\n";
        exit(1);
    }

    // Pobieranie napisów do zaszyfrowania
    for (index = 0; index < PT_NUM; index++)
        infile >> text[index];

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

        // Zamiana znaków
        tmp = text[swap_index];
        text[swap_index] = text[index];
        text[index] = tmp;
    }

    return text;
}

void ReturnData(string text[], unsigned key[]) {
    unsigned index;
    ofstream outfile;
    outfile.open(OUTFILE);

    if (!outfile.good()) {
        cout << "Plik wyjściowy nie mógł być otwarty." << "\n";
        exit(1);
    }

    outfile << "/// 76.1 ///" << "\n";
    for (index = 0; index < PT_NUM; index++)
        outfile << Encode(text[index], key) << "\n";

    outfile.close();
}
