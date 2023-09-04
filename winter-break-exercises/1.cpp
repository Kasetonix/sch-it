#include <iostream>
using std::cout;
using std::cin;
using std::string;
using std::tolower;

int main() {
    string sentence, sentenceMod;

    cout << "Wprowadź zdanie: "; getline(cin, sentence);
    sentenceMod = sentence;

    /* Zamiana wszystkich znaków w sentenceMod na małe */
    for (int i = 0; i <= sentenceMod.size() - 1; i++) {
        if (sentenceMod[i] != tolower(sentenceMod[i]))
            sentenceMod[i] = tolower(sentenceMod[i]);
    }

    /* Sprawdzanie, czy zdanie po zamianie znaków
     * jest takie samo, jak to początkowe */
    if (sentenceMod == sentence)
        cout << "TAK" << "\n";
    else
        cout << "NIE" << "\n";

	return 0;
}
