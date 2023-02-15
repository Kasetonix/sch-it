#include <iostream>
#include <cctype>
using std::cout;
using std::cin;
using std::string;
using std::tolower;

bool isPalindrome(string word);

int main() {
    int spaceLocation;
    string sentence, word;
    cout << "Wprowadź zdanie: "; getline(cin, sentence);
    /* Dodanie spacji, by algorytm wykrył ostatni wyraz */
    sentence = sentence + ' ';
    
    /* Iterowanie pętli, dopóki nie przeszukamy całego zdania */
    while (sentence.size() > 0) {
        /* Wyszukiwanie pierwszej spacji w z daniu */
        spaceLocation = sentence.find(' ');  
        /* Sprawdzanie dopóki spacja jest dalej niż na pierwszym indeksie
         * W praktyce iterowanie dopóku nie sprawdzimy całego zdania */
        if (spaceLocation > 0) {
            /* Wyszukanie pierwszego wyrazu. 
             * indeks 0 -- indeks pierwszej     spacji */
            word = sentence.substr(0, spaceLocation);
            /* Jeżeli słowo jest palindromemy wypisujemy do STDOUT */
            if (isPalindrome(word))
                cout << word << "\n";
        }

        /* Usuwanie sprawdzonego słowa ze zdania */
        sentence.erase(0, spaceLocation + 1);
    }
    
    return 0;
}

bool isPalindrome(string word) {
    /* Algorytm sprawdzania, czy wyrażenie jest palindromem */
	bool isPal = true;
	int i = 0, j = word.size() - 1;

    /* Iterowanie przez słowo i sprawdzanie, czy
     * znaki po przeciwległych stronach słowa są takie same */ 
	while (isPal && i < j) {
		if (tolower(word[i]) == tolower(word[j])) {
			i++; j--;
		} else return false; 
        /* Wyjście z funkcji w wypadku, 
         * gdy znaki nie są takie same */
	}

    /* Zwrócenie boola, czy wprowadzony wyraz jest palindromem */
	return true;
}
