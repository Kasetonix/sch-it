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
    unsigned int base_tab[100];
    unsigned int checked_num, max_num = 0, min_num = 4294967295, max_num_index, min_num_index;
    const unsigned int INFILE_LEN = 100;

    infile.open("liczby.txt");
    
    /* sprawdzanie, czy plik nie jest uszkodzony */
    if (!infile.good()) {
         cout << "Plik nie mógł być otwarty" << "\n";
        return 1;
    }

    /* wczytanie całego pliku do tablic */
    for (int index = 0; index < INFILE_LEN; index++) {
        infile >> base_tab[index] >> num_tab[index];
    }

    /* zamknięcie plików */
    infile.close();

    /* znalezienie maksymalnej i minimalnej liczby wraz z ich indeksami */
    for (int index = 1; index < INFILE_LEN; index++) {
        checked_num = ns_to_dec(num_tab[index], base_tab[index]);
        if (checked_num > max_num) {
            max_num = checked_num; 
            max_num_index = index;
        } else if (checked_num < min_num) {
            min_num = checked_num; 
            min_num_index = index;
        }
    }

    /* wypisanie znalezionych liczb i indeksów */
    cout << "Indeks i wartość maksymalnej liczby => "
        << max_num_index << ": " << max_num << "\n"; 
    cout << "Indeks i wartość minimalnej liczby ==> "
        << min_num_index << ": " << min_num << "\n"; 

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
