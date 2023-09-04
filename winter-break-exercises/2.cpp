#include <iostream>
using std::cout;
using std::cin;
using std::string;
using std::tolower;

int main() {
    string sentence;
    unsigned int numSpaces = 0;
    cout << "Wprowadź zdanie: "; getline(cin, sentence);
    
    /* Pętla sprawdzająca liczbę spacji w zdaniu */
    for (unsigned int i = 0; i <= sentence.size() - 1; i++)
        if (sentence[i] == ' ')
            numSpaces++;

    /* Liczba wyrazów w zdaniu jest of jeden większa od liczby spacji */
    cout << "Liczba wyrazów w tym zdaniu: " << numSpaces + 1 << "\n";

	return 0;
}
