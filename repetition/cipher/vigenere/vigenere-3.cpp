#include <iomanip>
#include <iostream>
#include <fstream>
#include <string>
using std::cout;
using std::string;
using std::ifstream;
using std::ofstream;
using std::getline;
using std::setprecision;
using std::fixed;

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
float Kappa_0(unsigned letter_count[], unsigned total);
float FindEstimatedKeyLen(float kappa_0);
float AbsVal(float num);
void ReturnData(string key, unsigned letter_count[], unsigned total);

int main() {
    unsigned letter_count[ALPH_LEN];
    unsigned total;
    CipherText ciphertext = GetText();
    InitLetterCount(letter_count);
    CountLetters(ciphertext.text, letter_count, total);
    ReturnData(ciphertext.key, letter_count, total);

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

float Kappa_0(unsigned letter_count[], unsigned total) {
    float kappa_0 = 0;
    unsigned index;
    for (index = 0; index < ALPH_LEN; index++)
        kappa_0 += (letter_count[index] * (letter_count[index] - 1));
    kappa_0 /= (total * (total - 1));

    return kappa_0;
}

float FindEstimatedKeyLen(float kappa_0) {
    return 0.0285 / ( kappa_0 - 0.0385);
}

float AbsVal(float num) {
    return num >= 0 ? num : -num;
}

void ReturnData(string key, unsigned letter_count[], unsigned total) {
    unsigned index;
    float est_len;
    ofstream outfile;

    outfile.open(OUTPUT_FILE, std::ios::app);
    if (!outfile.good()) {
        cout << "Plik wejściowy nie mógł być otwarty." << "\n";
        exit(1);
    }

    est_len = FindEstimatedKeyLen(Kappa_0(letter_count, total));
    outfile << "/// 77.3 ///" << "\n";
    outfile << "Długość klucza:            " << key.size() << "\n";
    outfile << "Szacunkowa długość klucza: " << fixed << setprecision(2) << est_len << "\n";
    outfile << "Delta:                     " << fixed << setprecision(2) << AbsVal(key.size() - est_len) << "\n";

    outfile.close();
}
