#include <iostream>
#include <fstream>
using std::cout;
using std::string;
using std::ifstream;
using std::ofstream;

int ns_to_dec(string num, int base);

int main() {
    ifstream infile;
    string num_tab[100];
    unsigned int base_tab[100], sum = 0;
    const unsigned int INFILE_LEN = 100;

    infile.open("liczby.txt");
    
    /* sprawdzanie, czy plik nie jest uszkodzony */
    if (!infile.good()) {
         cout << "Plik nie mógł być otwarty" << "\n";
        return 1;
    }

    /* wczytanie całego pliku do tablic */
    for (int index = 1; index <= INFILE_LEN; index++) {
        infile >> base_tab[index-1] >> num_tab[index-1];
    }

    /* zamknięcie plików */
    infile.close();

    /* zsumowanie wszystkich wartości w systemie dziesiętnym */
    for (int index = 1; index <= INFILE_LEN; index++) {
        sum += ns_to_dec(num_tab[index-1], base_tab[index-1]);
    }

    /* wypisanie sumy */
    cout << "Suma: " << sum << "\n";

    return 0;
}

/* funkcja zamieniająca liczbę z systemu o podstawie < 10
 * na system dziesiętny */
int ns_to_dec(string num, int base) {
    int decimal = 0;

    for (int index = 0; index < num.size(); index++) {
        decimal = (decimal * base) + (num[index] - '0');
    }

    return decimal;
}
