#include <iostream>
#include <cctype>
using std::cout;
using std::cin;
using std::string;
using std::tolower;

string RemoveSpaces(string sen);
bool IsPalindrome(string sen);

int main() {
    int i = 0;
    string sentence;
    cout << "Wprowadź zdanie: "; getline(cin, sentence);

    if (IsPalindrome(RemoveSpaces(sentence)))
        cout << "Wprowadzone zdanie jest palindromem." << "\n";
    else
        cout << "Wprowadzone zdanie nie jest palindromem." << "\n";
    
	return 0;
}

string RemoveSpaces(string sen) {
    int i = 0; /* Wskaźnik na dany znak */
    /* Iteracja przez każdy znak stringa */
    while (i < sen.size()) {
        /* Sprawdzanie, czy znak nie jest literą
         * i usunięcie go
         * jeżeli nie, przejście do następnego znaku */ 
        if (!(tolower(sen[i]) >= 'a' && tolower(sen[i]) <= 'z'))
            sen.erase(i,1);
        else i++;
    }

    return sen;
}

bool IsPalindrome(string sen) {
    /* Algorytm sprawdzania, czy wyrażenie jest palindromem */
	bool isPal = true;
	int i = 0, j = sen.size() - 1;

    /* Iterowanie przez słowo i sprawdzanie, czy
     * znaki po przeciwległych stronach słowa są takie same */ 
	while (isPal && i < j) {
		if (tolower(sen[i]) == tolower(sen[j])) {
			i++; j--;
		} else return false; 
        /* Wyjście z funkcji w wypadku, 
         * gdy znaki nie są takie same */
	}

    /* Zwrócenie boola, czy wprowadzony wyraz jest palindromem */
	return true;
}
