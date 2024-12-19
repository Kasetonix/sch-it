#include <iostream>
#include <fstream>
using std::cout;
using std::string;
using std::ifstream;
using std::ofstream;

const unsigned FN = 1000; // Długość
bool HasOneLetter(string str);
bool AreAnagrams(string str1, string str2);
bool ValidatePair(string str1, string str2);

int main() {
    unsigned index, counter = 0;
    string str1, str2;
    ifstream infile; ofstream outfile;

    // Plik wejściowy
    infile.open("dane_napisy.txt");
    if (!infile.good()) {
        cout << "Plik wejściowy nie mógł być otwarty." << "\n";
        exit(1);
    }

    // Plik wyjściowy
    outfile.open("wyniki_anagramy.txt");
    if (!outfile.good()) {
        cout << "Plik wyjściowy nie mógł być otwarty." << "\n";
        exit(1);
    }

    for (index = 0; index < FN; ++index) {
        infile >> str1 >> str2;
        if (ValidatePair(str1, str2))
            counter++;
    }

    outfile << "/// 68.1 ///" << "\n";
    outfile << "    Liczba par napisów jednolitych anagramowych: " << counter << "\n";

    infile.close();
    outfile.close();
    
    return 0;
}

bool HasOneLetter(string str) {
    unsigned index;
    for (index = 1; index < str.size(); ++index)
        if (str[index - 1] != str[index])
            return false;
    return true;
}

bool HaveTheSameLen(string str1, string str2) {
    if (str1.size() == str2.size())
        return true;
    return false;
}

bool ValidatePair(string str1, string str2) {
    if (!HaveTheSameLen(str1, str2))
        return false;
    if (!HasOneLetter(str1))
        return false;
    if (!HasOneLetter(str2))
        return false;
    return true;
}
