#include <iostream>
#include <cctype>
#include <fstream>
using std::cout;
using std::cin;
using std::string;
using std::ofstream;

void sortWord(string &word);
bool isAnagram(string word1, string word2);

int main() {
    string firstWord, secondWord;
    ofstream outfile("isAnagram_out.txt");

    if (!outfile.good()) {
        cout << "Nie powiodło się otwieranie pliku wyjściowego." << "\n";
        return 1;
    }

    cout << "/// Anagram ///" << "\n";
    cout << "Podaj pierwszy wyraz: "; cin >> firstWord;
    cout << "Podaj drugi wyraz:    "; cin >> secondWord;

    /* Przesortowanie liter w słowie alfabetycznie */
    sortWord(firstWord); sortWord(secondWord);

    if (isAnagram(firstWord, secondWord))
        outfile << "Słowa są anagramami" << "\n";
    else 
        outfile << "Słowa nie są anagramami" << "\n";

    outfile.close();
}

void sortWord(string &word) {
    int currentIndex, comparedIndex;
    char tmp;
    
    for (currentIndex = 1; currentIndex < word.size(); currentIndex++) {
        tmp = word[currentIndex];
        comparedIndex = currentIndex - 1;

        while (comparedIndex >= 0 && word[comparedIndex] > tmp) {
            word[comparedIndex + 1] = word[comparedIndex];
            comparedIndex--;
        }

        word[comparedIndex + 1] = tmp;
    }
}

bool isAnagram(string word1, string word2) {
    /* Wczesny return w razie, gdy długość słów jest inna */
    if (word1.size() != word2.size())
        return false;

    /* Zwrócenie, czy słowa są takie same */
    return (word1 == word2);
}
