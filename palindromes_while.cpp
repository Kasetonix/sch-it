#include <iostream>
#include <cctype>
using std::cout;
using std::cin;
using std::tolower;
using std::string;

int main() {
	/* Założenie, że wyraz jest palindromem */
	bool isPalindrome = true;
	string sentence;
	cout << "Wprowadź wyrażenie: "; getline(cin, sentence);
	int i = 0, j = sentence.size() - 1;

	/* Pętla, która iteruje dopuki nie dojdzie 
	 * do środka wyrazu */
	while (isPalindrome && i < j) {
		/* Sprawdzanie, czy znaki po dwóch stronach
		 * środka wyrazu w takiej samej odległości
		 * od niego są takie same.
		 * Jeżeli nie, to wyraz nie jest palindromem */
		if (tolower(sentence[i]) == tolower(sentence[j])) {
			i++;
			j--;
		} else isPalindrome = false;
	}

	if (isPalindrome)
		cout << "Wprowadzone wyrażenie jest palindromem." << "\n";
	else 
		cout << "Wprowadzone wyrażenie nie jest palindromem." << "\n";

	return 0;
}
