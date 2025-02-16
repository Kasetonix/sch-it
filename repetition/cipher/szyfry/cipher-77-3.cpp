#include <iostream>
#include <fstream>
#include <string>
#include <utility>
using std::cout;
using std::string;
using std::ifstream;
using std::ofstream;
using std::getline;

struct CipherText {
    string text;
    string key;
};

const string INPUT_FILE = "szyfr.txt";
const string OUTPUT_FILE = "Vigenere_wyniki.txt";
const unsigned ALPH_LEN = 26;
CipherText GetText();
void InitLetterCount(unsigned letter_count[]);
void CountLetters(string ciphertext, unsigned letter_count[], unsigned &total);
unsigned Kappa_0(unsigned letter_count[], unsigned total);
void ReturnData(unsigned letter_count[]);

int main() {
    unsigned letter_count[ALPH_LEN];
    unsigned total = 0;
    CipherText ciphertext = GetText();
    InitLetterCount(letter_count);
    CountLetters(ciphertext.text, letter_count, total);
    cout << total << "\n";
    cout << Kappa_0(letter_count, total) << "\n";
    ReturnData(letter_count);

    return 0;
}

CipherText GetText() {
    ifstream infile;
    string text, key;

    infile.open(INPUT_FILE);
    if (!infile.good()) {
        cout << "Plik wejściowy nie mógł być otwarty." << "\n";
        exit(1);
    }

    getline(infile, text);
    infile >> key;
    infile.close();

    return {text, key};
}

void InitLetterCount(unsigned letter_count[]) {
    unsigned index;
    for (index = 0; index < ALPH_LEN; index++)
        letter_count[index] = 0;
}

void CountLetters(string ciphertext, unsigned letter_count[], unsigned &total) {
    unsigned index;
    int c_letter;
    total = 0;
    for (index = 0; index < ciphertext.size(); index++) {
        c_letter = ciphertext[index] - 'A';
        if (c_letter < 0 || c_letter >= ALPH_LEN)
            continue;

        letter_count[c_letter]++;
        total++;
    }
}

unsigned Kappa_0(unsigned letter_count[], unsigned total) {
    float kappa_0 = 0;
    unsigned index;
    for (index = 0; index < ALPH_LEN; index++)
        kappa_0 += letter_count[index] * (letter_count[index] - 1);
    cout << kappa_0 << "\n";
    cout << total * (total - 1) << "\n";
    kappa_0 /= float(total * (total - 1));

    return kappa_0;
}

void ReturnData(unsigned letter_count[]) {
    unsigned index;
    ofstream outfile;

    outfile.open(OUTPUT_FILE, std::ios::app);
    if (!outfile.good()) {
        cout << "Plik wejściowy nie mógł być otwarty." << "\n";
        exit(1);
    }

    outfile << "/// 77.3 ///" << "\n";
    for (index = 0; index < ALPH_LEN; index++) {
        outfile << char(index + 'A') << ". " << letter_count[index] << "\n";
    }
    outfile << "\n";

    outfile.close();
}
