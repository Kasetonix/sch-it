#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::string;

int main() {
	string word;
	char character;
	int characterNumber = 0;
	cout << "Wprowadź wyraz: "; cin >> word;
	cout << "Wprowadź znak, który ma wyć wyszukany: "; cin >> character;

	for (int i = 0; i < word.size(); i++) {
		if (word[i] == character)
			characterNumber++;
	}

	cout << "Liczba występowań podanego znaku w podanym wyrazie wynosi: " << characterNumber << "\n";
}
