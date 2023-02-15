/* Alternatywne rozwiązanie zadania 5 przy użyciu metody to_string() */
#include <iostream>
using std::cout;
using std::string;
using std::to_string;

int main() {
    unsigned short num;
    string numStr;

    /* iteracja przez każdą liczbę trzycyfrową */
    for (num = 100; num <= 999; num++) {
        /* Zamiana int -> string */
        numStr = to_string(num);

        /* Sprawdzanie, czy pierwsza i ostatnia cyfra
         * są takie same
         * (przy liczbach trzycyfrowych to wystarczy
         * by sprawdzić, że są palindromiczne)*/
        if (numStr[0] == numStr[2]) {
            /* Zwrócenie liczby palindromicznej */
            cout << num << "\n";
        }
    }

    return 0;
}
