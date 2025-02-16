#include <cstring>
#include <iostream>
#include <fstream>
#include <string>
#include <strings.h>

using std::cout;
using std::string;
using std::to_string;
using std::ifstream;
using std::ofstream;

const unsigned ALPH_LEN = 26;
const unsigned MAX_KEYVAL = 25;
const unsigned LEN = 5;
const string INFILE = "probka.txt";
const string OUTFILE = "wyniki.txt";

struct Key {
    unsigned multiplier;
    unsigned summand;
};

struct Pair {
    string plaintext;
    string ciphertext;
};

void GetData(Pair pair[]);
char EncodeChar(char c, Key key);
string Encode(string plaintext, Key key);
Key FindKey(Pair pair, bool rev);
void ReturnData(Pair pair[]);

int main() {
    Pair pair[LEN];
    GetData(pair);
    ReturnData(pair);

    return 0;
}

void GetData(Pair pair[]) {
    unsigned index;
    ifstream infile;

    infile.open(INFILE);
    if (!infile.good()) {
        cout << "Plik wejściowy nie mógł być otwarty." << "\n";
        exit(1);
    }

    for (index = 0; index < LEN; index++)
        infile >> pair[index].plaintext >> pair[index].ciphertext;

    infile.close();
}

char EncodeChar(char c, Key key) {
    return (((c - 'a') * key.multiplier + key.summand) % ALPH_LEN) + 'a';
}

string Encode(string plaintext, Key key) {
    unsigned index;
    string ciphertext;

    for (index = 0; index < plaintext.size(); index++)
        ciphertext += EncodeChar(plaintext[index], key);

    return ciphertext;
}

Key FindKey(Pair pair, bool rev) {
    Key key;

    // Znajdowanie na siłę klucza szyfrującego
    if (!rev) {
        for (key.multiplier = 0; key.multiplier <= MAX_KEYVAL; key.multiplier++)
            for (key.summand = 0; key.summand <= MAX_KEYVAL; key.summand++)
                if (Encode(pair.plaintext, key) == pair.ciphertext)
                    return key; 
    // --||-- klucza deszyfrującego
    } else {
        for (key.multiplier = 0; key.multiplier <= MAX_KEYVAL; key.multiplier++)
            for (key.summand = 0; key.summand <= MAX_KEYVAL; key.summand++)
                if (Encode(pair.ciphertext, key) == pair.plaintext)
                    return key;
    }

    return {0, 0};
}

string CatKey(Key key) {
    return string("{ ") + to_string(key.multiplier) + string("; ") + to_string(key.summand) + string(" }");
}

void ReturnData(Pair pair[]) {
    unsigned index;
    ofstream outfile;

    outfile.open(OUTFILE, std::ios::app);
    if (!outfile.good()) {
        cout << "Plik wyjściowy nie mógł być otwarty." << "\n";
        exit(1);
    }

    outfile << "\n" << "/// 75.3 ///" << "\n";
    for (index = 0; index < LEN; index++)
        outfile << index + 1 << ". " << "Klucz szyfrujący: " << CatKey(FindKey(pair[index], false)) << "  |  Klucz deszyfrujący: " << CatKey(FindKey(pair[index], true)) << "\n";

    outfile.close();
}
