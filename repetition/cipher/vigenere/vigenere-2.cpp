#include <iostream>
#include <fstream>
#include <string>
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
char OffsetLetterRev(char letter, char key);
string VigenereDecode(string ciphertext, string key);
void ReturnData(string plaintext);

int main() {
    unsigned key_counter = 1;
    CipherText ciphertext = GetText();
    ReturnData(VigenereDecode(ciphertext.text, ciphertext.key));

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

char OffsetLetterRev(char letter, char key) {
    char result;
    result = letter - (key - 'A');
    return result < 'A' ? result + ALPH_LEN : result;
}

string VigenereDecode(string ciphertext, string key) {
    unsigned index, key_index = 0;
    string plaintext;

    for (index = 0; index < ciphertext.size(); index++) {
        if (ciphertext[index] < 'A' || ciphertext[index] > 'Z') {
            plaintext += ciphertext[index];
            continue;
        }

        plaintext += OffsetLetterRev(ciphertext[index], key[key_index]);
        key_index++;
        key_index %= key.size(); 
    }

    return plaintext;
}

void ReturnData(string plaintext) {
    ofstream outfile;

    outfile.open(OUTPUT_FILE, std::ios::app);
    if (!outfile.good()) {
        cout << "Plik wejściowy nie mógł być otwarty." << "\n";
        exit(1);
    }

    outfile << "/// 77.2 ///" << "\n";
    outfile << plaintext << "\n";
    outfile << "\n";
    
    outfile.close();
}
