#include <iostream>
#include <cctype>
using std::cout;
using std::cin;
using std::string;
using std::tolower;

bool isPalindrome(string sentence);

int main() {
	string sentence;
	cout << "Wprowadź wyrażenie: "; getline(cin, sentence);

    if (isPalindrome(sentence) == true)
        cout << "Wprowadzone wyrażenie jest palindromem." << "\n";
    else
        cout << "Wprowadzone wyrażenie nie jest palindromem. " << "\n";

	return 0;
}

bool isPalindrome(string sentence) {
    /* Algorytm sprawdzania, czy wyrażenie jest palindromem */
	bool isPal = true;
	int i = 0, j = sentence.size() - 1;

	while (isPal && i < j) {
		if (tolower(sentence[i]) == tolower(sentence[j])) {
			i++; j--;
		} else isPal = false;
	}

    /* Zwrócenie boola, czy wprowadzony wyraz jest palindromem */
	return isPal;
}
