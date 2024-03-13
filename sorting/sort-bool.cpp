#include <iostream>
#include <fstream>
#include <algorithm>

using std::ofstream;
using std::string;
using std::sort;

bool compare_ascending (unsigned int a, unsigned int b);
bool compare_descending (unsigned int a, unsigned int b);

int main() {
    /* plik wyjściowy */
    ofstream outfile;
    outfile.open("wynik.txt");

    /* Dane do przesortowania */
    int tab_int[] = { 2, 4, 6, 3, 8, 6, 88, 1, 5, 84, 62 };

    /* Obliczanie długości tablic */
    unsigned short tab_int_len = (sizeof(tab_int) / sizeof(int));

    /* Wypisanie oryginalnej tablicy do pliku */
    outfile << "Tablica przesortowana malejąco: " << "\n";
    for (int index = 0; index < tab_int_len; index++)
        outfile << tab_int[index] << " ";

    /* Sortowanie tablicy z liczbami malejąco i jej wypisanie */
    sort(tab_int, tab_int + tab_int_len, compare_ascending);
    outfile << "\n" << "Tablica przesortowana rosnąco: " << "\n";
    for (int index = 0; index < tab_int_len; index++)
        outfile << tab_int[index] << " ";

    /* Sortowanie tablicy z liczbami malejąco i jej wypisanie */
    sort(tab_int, tab_int + tab_int_len, compare_descending);
    outfile << "\n" << "Tablica przesortowana malejąco: " << "\n";
    for (int index = 0; index < tab_int_len; index++)
        outfile << tab_int[index] << " ";

    outfile << "\n";
    outfile.close();
    return 0;
}

bool compare_ascending (unsigned int a, unsigned int b) { return a < b; }
bool compare_descending (unsigned int a, unsigned int b) { return a > b; }
