#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>

using std::cout;
using std::ofstream;
using std::string;
using std::sort;
using std::transform;
using std::tolower;

int main() {
    /* plik wyjściowy */
    ofstream outfile;

    /* Dane do przesortowania */
    string word = "jsluksaym";
    string sentence = "string do posortowania abzwcdexyfh";
    int tab_int[] = { 2, 4, 6, 3, 8, 6, 88, 1, 5, 84, 62 };
    string tab_string[] = { "test", "bB", "A", "D", "1A", "a", "ds", "asd", "Bb", "z" };

    /* Obliczanie długości tablic */
    unsigned short tab_int_len = (sizeof(tab_int) / sizeof(int));
    unsigned short tab_string_len = (sizeof(tab_string) / sizeof(string));

    /* Zamiana elementów tablicy ze stringami na małe litery */
    for (int index = 0; index < tab_string_len; index++)
        transform(tab_string[index].cbegin(), tab_string[index].cend(), tab_string[index].begin, ::tolower);

    /* Sortowanie tablicy z liczbami i stringami */
    sort(tab_int, tab_int + tab_int_len);
    sort(tab_string, tab_string + tab_string_len);
    
    return 0;
}
