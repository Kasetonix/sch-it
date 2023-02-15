#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::string;
using std::getline;
using std::find;

int main() {
	string sentence;
	cout << "Wprowadź zdanie: "; getline(cin, sentence);

	/* [size] zwraca długość zdania */
	cout << "\n---[size]---\n";
	cout << "Długość zdania wynosi: " << sentence.size() << "\n";
	
	/* [find] Wyszukiwanie frazy w stringu */
	cout << "\n---[find]---\n";
	string phraseToFind;
	int phraseFoundIndex = 0;
	cout << "Wprowadź szukaną frazę: "; getline(cin, phraseToFind);

	phraseFoundIndex = sentence.find(phraseToFind);

	/* Sprawdzanie, czy find zwróci indeks znajdujący się w stringu. 
	 * Jeżeli tego nie zrobi, oznacza to że szukana fraza się w nim nie znajduje*/
	if (sentence.find(phraseToFind) == sentence.npos)
		cout << "Podana fraza nie znajduje się w zdaniu." << "\n"; 
	else   
		cout << "Wprowadzona fraza została znaleziona na indeksie " << phraseFoundIndex << "\n"; 

	
	/* [substr] Zwracanie stringa od podanego indeksu i o podanej długości */
	cout << "\n---[substr]---\n";
	int stringIndex = 0, stringLen = 0;
	cout << "Podaj od jakiego indeksu zwrócić część zdania: "; cin >> stringIndex;
	cout << "Podaj, jak długa ma być ta część zdania: "; cin >> stringLen;

	cout << "Część zdania o podanych parametrach to " << sentence.substr(stringIndex, stringLen) << "\n";
	
	/* [erase] Usuwa część zdania o podanym indeksie i długości */
	cout << "\n---[erase]---\n";
	string sentenceErased = sentence;
	sentenceErased.erase(stringIndex, stringLen);
	cout << "Zdanie z częścią usuniętą zgodnie z wcześniej podanymi parametrami: " << sentenceErased << "\n";

	return 0;
}
