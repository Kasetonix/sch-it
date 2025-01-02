#include <cctype>
#include <iostream>
using std::cout;
using std::cin;
using std::string;

const unsigned KEY = 3;
const unsigned ALPHLEN = 26;
string Cipher(string text);

int main() {
    string plaintext;
    unsigned index;
    cout << "Podaj tekst do zaszyfrowania:  "; cin >> plaintext;
    
    // Zamienianie wszystkich znaków na wielkie litery
    for (index = 0; index < plaintext.size(); ++index)
        plaintext[index] = toupper(plaintext[index]);

    cout << "Zaszyfrowany tekst (klucz: 3): " << Cipher(plaintext) << "\n";

    return 0;
}

string Cipher(string text) {
    string ciphertext;
    char ascii_code;
    unsigned index;

    for (index = 0; index < text.size(); ++index) {
        ascii_code = text[index] + KEY;
        // "Zapętlanie" alfabetu
        if (ascii_code > 'Z')
            ascii_code -= ALPHLEN;
        // Dodanie odpowiedniej litery do zakodowanego tekstu
        ciphertext += ascii_code;
    }

    return ciphertext;
}
