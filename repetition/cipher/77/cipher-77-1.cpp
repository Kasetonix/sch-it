#include <iostream>
#include <fstream>
#include <string>
using std::cout;
using std::string;
using std::ifstream;
using std::ofstream;
using std::getline;

const string INPUT_FILE = "dokad.txt";
const string OUTPUT_FILE = "Vigenere_wyniki.txt";
const unsigned ALPH_LEN = 26;
string GetText();
char OffsetLetter(char letter, char key);
string VigenereEncode(string plaintext, string key, unsigned& key_counter);
void ReturnData(string ciphertext, unsigned key_counter);

int main() {
    string plaintext, ciphertext, key = "LUBIMYCZYTAC";
    unsigned key_counter = 1;
    ReturnData(VigenereEncode(GetText(), key, key_counter), key_counter);

    return 0;
}

string GetText() {
    ifstream infile;
    string text;

    infile.open(INPUT_FILE);
    if (!infile.good()) {
        cout << "Plik wejściowy nie mógł być otwarty." << "\n";
        exit(1);
    }

    getline(infile, text);
    infile.close();

    return text;
}

char OffsetLetter(char letter, char key) {
    char result;
    result = letter + key - 'A';
    return result > 'Z' ? result - ALPH_LEN : result;
}

string VigenereEncode(string plaintext, string key, unsigned& key_counter) {
    unsigned index, key_index = 0;
    string ciphertext;

    for (index = 0; index < plaintext.size(); index++) {
        if (plaintext[index] == ' ' || plaintext[index] == ',' || plaintext[index] == '.') {
            ciphertext += plaintext[index];
            continue;
        }

        ciphertext += OffsetLetter(plaintext[index], key[key_index]);
        
        // Zapętlanie klucza
        if (key_index == key.size() - 1) {
            key_index = 0;
            key_counter++;
            continue;
        }
        key_index++;
    }

    return ciphertext;
}

void ReturnData(string ciphertext, unsigned key_counter) {
    ofstream outfile;

    outfile.open(OUTPUT_FILE, std::ios::app);
    if (!outfile.good()) {
        cout << "Plik wejściowy nie mógł być otwarty." << "\n";
        exit(1);
    }

    outfile << "/// 77.1 ///" << "\n";
    outfile << ciphertext << "\n";
    outfile << "Liczba powtórzeń klucza: " << key_counter << "\n";
    outfile << "\n";
    
    outfile.close();
}
