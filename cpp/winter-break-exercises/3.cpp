#include <iostream>
using std::cout;
using std::cin;
using std::string;
using std::toupper;

string ConvertToUppercase(string sen);

int main() {
    string sentence;
    cout << "Wprowadź zdanie: "; getline(cin, sentence);

    cout << "Wprowadzone zdanie z wszystkimi pierwszymi literami dużymi: \n" << ConvertToUppercase(sentence) << "\n";

	return 0;
}

string ConvertToUppercase(string sen) {
    /* Zamiana pierwszego znaku zdania */
    sen[0] = toupper(sen[0]);
    /* Iteracja przez całe zdanie i zamiana każdej litery po spacji na wielką */
    for (unsigned short i = 0; i <= sen.size() - 1; i++)
        if (sen[i] == ' ')
            sen[i + 1] = toupper(sen[i + 1]);

    return sen;
}
