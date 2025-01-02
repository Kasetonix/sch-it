#include <iostream>
#include <string>
#include <fstream>
using std::string;
using std::cout;
using std::ifstream;
using std::ofstream;

const unsigned short ALPHABET_LEN = 26;
const unsigned FL = 100;
const string INPUT_FILE = "dane_6_1.txt";
const string OUTPUT_FILE = "wyniki_6_1.txt";

void GetData(string words[]);
string CeasarCipher(string plaintext, unsigned short key);
void ReturnData(string ciphertext[]);

int main() {
    string plaintext[FL];

    GetData(plaintext);
    ReturnData(plaintext);

    return 0;
}

void GetData(string words[]) {
    ifstream infile;
    unsigned index;

    infile.open(INPUT_FILE);
    if (!infile.good()) {
        cout << "Plik wejściowy nie mógł być otwarty." << "\n";
        exit(1);
    }

    for (index = 0; index < FL; ++index)
        infile >> words[index];

    infile.close();
}

string CeasarCipher(string plaintext, unsigned short key) {
    string ciphertext = "";
    char ascii_code;
    unsigned index;

    for (index = 0; index < plaintext.size(); ++index) {
        // Przesunięty kod ascii następnego znaku
        ascii_code = plaintext[index] + key;
        // Zapętlanie kodów ascii
        if (ascii_code > 'Z')
            ascii_code -= ALPHABET_LEN;
        ciphertext += ascii_code;
    }

    return ciphertext;
}

void ReturnData(string words[]) {
    ofstream outfile;
    unsigned index, key = 107 & ALPHABET_LEN;

    outfile.open(OUTPUT_FILE);
    if (!outfile.good()) {
        cout << "Plik wyjściowy nie mógł być otwarty." << "\n";
        exit(1);
    }

    outfile << "/// 6.1 ///" << "\n";
    for (index = 0; index < FL; ++index)
        outfile << CeasarCipher(words[index], key) << "\n";

    outfile.close();
}
