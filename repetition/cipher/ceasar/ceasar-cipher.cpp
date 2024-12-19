#include <iostream>
#include <string>
#include <fstream>
using std::string;
using std::cin;
using std::cout;
using std::ifstream;
using std::ofstream;

const unsigned short alphabet_len = 26;

// Szyfruje szyfrem cezara
string CeasarCipher(string plaintext, unsigned short key);

int main() {
    unsigned short key;
    string plaintext;
    cout << "Wprowadź wiadomość do zaszyfrowania: "; cin >> plaintext;
    cout << "Wprowadź klucz:                      "; cin >> key;
    cout << "Zaszyfrowana wiadomość:              " << CeasarCipher(plaintext, key % alphabet_len) << "\n";

    return 0;
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
            ascii_code -= alphabet_len;
        ciphertext += ascii_code;
    }

    return ciphertext;
}
