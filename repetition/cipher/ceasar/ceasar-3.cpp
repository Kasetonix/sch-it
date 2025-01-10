#include <iostream>
#include <string>
#include <fstream>
using std::string;
using std::cout;
using std::ifstream;
using std::ofstream;

const unsigned short ALPHABET_LEN = 26;
const unsigned FL = 3000;
const string INPUT_FILE = "dane_6_3.txt";
const string OUTPUT_FILE = "wyniki_6_3.txt";

struct Word {
    string plaintext;
    string ciphertext;
    bool valid;
};

void GetData(Word word[]);
unsigned CharDiff(char a, char b);
void Validate(Word &word);
void ReturnData(Word word[]);

int main() {
    Word word[FL];
    GetData(word);
    ReturnData(word);

    return 0;
}

void GetData(Word word[]) {
    ifstream infile;
    unsigned index;

    infile.open(INPUT_FILE);
    if (!infile.good()) {
        cout << "Plik wejściowy nie mógł być otwarty." << "\n";
        exit(1);
    }

    for (index = 0; index < FL; ++index)
        infile >> word[index].plaintext >> word[index].ciphertext;

    infile.close();
}

// p - plaintext | c - ciphertext 
unsigned CharDiff(char p, char c) {
    unsigned diff = 0;
    // ('Z' - p) + (c - 'A'): p -> 'Z' + 'A' -> c
    diff = p < c ? c - p : c - p + ALPHABET_LEN; 
    return diff;
}

void Validate(Word &word) {
    unsigned index, len, key;
    len = word.plaintext.size(); // Długość wyrazu 
    key = CharDiff(word.plaintext[0], word.ciphertext[0]); // rzekomy klucz

    // Sprawdzanie dla każdego znaku, czy jest zaszyfrowany tym samym kluczem
    for (index = 1; index < len; ++index) {
        if (CharDiff(word.plaintext[index], word.ciphertext[index]) != key) {
            word.valid = false;
            return;
        }
    }

    word.valid = true;
}

void ReturnData(Word word[]) {
    ofstream outfile;
    unsigned index;

    outfile.open(OUTPUT_FILE);
    if (!outfile.good()) {
        cout << "Plik wyjściowy nie mógł być otwarty." << "\n";
        exit(1);
    }

    for (index = 0; index < FL; ++index) {
        Validate(word[index]);
        if (!word[index].valid)
            cout << word[index].plaintext << "\n";
    }

    outfile.close();
}
