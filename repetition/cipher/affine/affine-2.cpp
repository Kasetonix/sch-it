#include <iostream>
#include <fstream>

using std::cout;
using std::string;
using std::ifstream;
using std::ofstream;

const unsigned ALPH_LEN = 26;
const unsigned LEN = 805;
const string INFILE = "tekst.txt";
const string OUTFILE = "wyniki.txt";

struct Key {
    unsigned multiplier;
    unsigned summand;
};

void GetData(string str[]);
char EncodeChar(char c, Key key);
string Encode(string plaintext, Key key);
void ReturnData(string str[], Key key);

int main() {
    string str[LEN];
    Key key = { 5, 2 };
    GetData(str);
    ReturnData(str, key);

    return 0;
}

void GetData(string str[]) {
    unsigned index;
    ifstream infile;

    infile.open(INFILE);
    if (!infile.good()) {
        cout << "Plik wejściowy nie mógł być otwarty." << "\n";
        exit(1);
    }

    for (index = 0; index < LEN; index++)
        infile >> str[index];

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

void ReturnData(string str[], Key key) {
    unsigned index;
    ofstream outfile;

    outfile.open(OUTFILE, std::ios::app);
    if (!outfile.good()) {
        cout << "Plik wyjściowy nie mógł być otwarty." << "\n";
        exit(1);
    }

    outfile << "\n" << "/// 75.2 ///" << "\n";
    for (index = 0; index < LEN; index++)
        if (str[index].size() >= 10)
            outfile << Encode(str[index], key) << "\n";

    outfile.close();
}
