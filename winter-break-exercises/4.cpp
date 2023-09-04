#include <iostream>
using std::cout;
using std::cin;
using std::string;
using std::tolower;

bool areAllWordsPalindromes(string sen);
bool isPalindrome(string word);
bool areAllWordsSameLen(string sen);

int main() {
    string sentence;
    cout << "Wprowadź zdanie: "; getline(cin, sentence);

    /* Dodanie wartownika */
    sentence = sentence + " ";

    /* Usunięcie spacji na początku zdania */
    while (sentence[0] == ' ') {
        sentence.erase(0, 1);
    }

    /* Sprawdzanie wymaganego warunku przy użyciu funkcji typu bool */ 
    if (areAllWordsSameLen(sentence) && areAllWordsPalindromes(sentence))
        cout << "TAK" << "\n";
    else
        cout << "NIE" << "\n";

	return 0;
}

bool areAllWordsPalindromes(string sen) {
    string currentWord;
    unsigned short currentWordLen = 0;

    /* Iteracja przez całe zdanie */
    while (sen.size() > 0) {
        /* Znajdowanie długości zdania */
        currentWordLen = sen.find(' ');
        /* Wybieranie pierwszego wyrazu ze zdania */
        currentWord = sen.substr(0, currentWordLen);
        /* Sprawdzanie, czy pierwszy wyraz w zdaniu jest palindromem
         * jeżeli nie, to wyjście z funkcji i zwrócenie wartości false */
        if (!isPalindrome(currentWord)) return false;

        /* Usunięcie sprawdzonego wyrazu wraz z następującymi go spacjami */
        sen.erase(0, currentWordLen);
        while (sen[0] == ' ') {
            sen.erase(0, 1);
        }
    }
    
    /* Zwrócenie wartości true, jeżeli poprzednia pętla nie wyłapała
     * że jakiś wyraz nie jest palindromem */
    return true;
}

bool isPalindrome(string word) {
    bool isPal = true;
    unsigned short i = 0, j = word.size() - 1;

    /* Iterowanie przez całe słowo i sprawdzanie,
     * czy znaki po przeciwległych stronach wyrazu są takie same.
     * Jeżeli nie, wyjście z funkcji i zwrócenie wartości false */
    while (isPal && i < j) {
        if (tolower(word[i]) == tolower(word[j])) {i++; j--;}
        else return false;
    }

    /* Jeżeli wcześniejsza pętla, nie złapała że dany wyraz nie jest
     * palindromem, zwrócenie wartości true */
    return true;
}

bool areAllWordsSameLen(string sen) {
    string currentWord;
    unsigned short currentWordLenA, currentWordLenB = sen.find(' ');

    /* Iteracja przez całe zdanie + wartownik */
    while (sen.size() - 1 > 1) {
        currentWordLenA = currentWordLenB;

        /* Usunięcie pierwszego wyrazu wraz z następującymi go spacjami
         * Nie usuwa ostatniej spacji w wypadku, gdy jest ona
         * ostatnim znakiem stringa (w praktyce wartownikiem) */
        sen.erase(0, currentWordLenA);
        while (sen[0] == ' ' && sen.size() - 1 > 0)
            sen.erase(0, 1);

        /* Znajdowanie długości drugiego wyrazu w wypadku, gdy
         * w zdaniu znajduje się coś poza wartownikiem*/
        if (sen.size() - 1 > 0)
            currentWordLenB = sen.find(' ');

        /* Zwrócenie wartości false, gdy długości słów nie są takie same */
        if (currentWordLenA != currentWordLenB)
            return false;
    }
    
    /* Zwrócenie wartości true, jeżeli pętla nie wyłapała
     * że wyrazy nie mają takiej samej długości */
    return true;
}