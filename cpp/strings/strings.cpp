#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::string;

int main() {
	string sentence;
	cout << "Wprowadź zdanie:      "; getline(cin, sentence);
	cout << "Całe zdanie:          " << sentence << "\n";
	cout << "Długość zdania:       " << sentence.size() << "\n";
	cout << "Pierwszy znak zdania: " << sentence[0] << "\n";
	cout << "Ostatni znak zdania:  " << sentence[sentence.size() - 1] << "\n";
	cout << "10 znak zdania:       " << sentence[9] << "\n";

	return 0;
}
