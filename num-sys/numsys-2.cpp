#include <iostream>
#include <fstream>
using std::cout;
using std::ios;
using std::string;
using std::ifstream;
using std::ofstream;

int ns_to_dec(string num, int base);

int main() {
    ifstream infile;
    ofstream outfile;
    string num_tab[100];
    unsigned int base_tab[100];
    unsigned int checked_num, max_num = 0, min_num = 4294967295, max_num_index, min_num_index;
    const unsigned int INFILE_LEN = 100;

    infile.open("liczby.txt");
    outfile.open("wynik.txt", ios::app);
    
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
    for (int index = 0; index < INFILE_LEN; index++) {
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
    /* cout << "indeks, podstawa i wartość maksymalnej liczby => "
        << max_num_index << ": " << base_tab[max_num_index] << " / " << num_tab[max_num_index] << "\n"; 
    cout << "indeks, podstawa i wartość minimalnej liczby ==> "
        << min_num_index << ": " << base_tab[min_num_index] << " / " << num_tab[min_num_index] << "\n";  */

    /* wypisanie do pliku */
    outfile << "/// ZAD. 2 ///" << "\n";
    outfile << "Indeks, podstawa i wartość maksymalnej liczby => "
        << max_num_index << ": " << base_tab[max_num_index] << " / " << num_tab[max_num_index] << "\n"; 
    outfile << "Indeks, podstawa i wartość minimalnej liczby ==> "
        << min_num_index << ": " << base_tab[min_num_index] << " / " << num_tab[min_num_index] << "\n\n"; 

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
