#include <iostream>
#include <string>
#include <fstream>
using std::string;
using std::cout;
using std::ifstream;
using std::ofstream;

const unsigned short ALPHABET_LEN = 26;
const unsigned FL = 700;
const string INPUT_FILE = "dane_6_2.txt";
const string OUTPUT_FILE = "wyniki_6_2.txt";

struct Word {
    string ciphertext;
    unsigned short key;
};

void GetData(Word word[]);
string CeasarCipherReverse(string ciphertext, unsigned short key);
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

    for (index = 0; index < FL; ++index) {
        infile >> word[index].ciphertext >> word[index].key;
        // Ustawianie klucza na liczbę z zakresu [0; 26]
        word[index].key %= ALPHABET_LEN;
    }

    infile.close();
}

string CeasarCipherReverse(string ciphertext, unsigned short key) {
    string plaintext;
    char ascii_code;
    unsigned index;

    for (index = 0; index < ciphertext.size(); ++index) {
        // Przesunięty kod ascii następnego znaku
        ascii_code = ciphertext[index] - key;
        // Zapętlanie kodów ascii
        if (ascii_code < 'A')
            ascii_code += ALPHABET_LEN;
        plaintext += ascii_code;
    }

    return plaintext;
}

void ReturnData(Word word[]) {
    ofstream outfile;
    unsigned index;

    outfile.open(OUTPUT_FILE);
    if (!outfile.good()) {
        cout << "Plik wyjściowy nie mógł być otwarty." << "\n";
        exit(1);
    }

    outfile << "/// 6.2 ///" << "\n";
    for (index = 0; index < FL; ++index)
        outfile << CeasarCipherReverse(word[index].ciphertext, word[index].key) << "\n";

    outfile.close();
}
