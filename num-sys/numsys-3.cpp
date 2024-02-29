#include <iostream>
#include <fstream>
using std::cout;
using std::ios;
using std::string;
using std::ifstream;
using std::ofstream;

int ns_to_dec(string num, unsigned int base);
void SelectionSort(unsigned int array[], string num_array[], unsigned int base_array[], unsigned int array_len);

int main() {
    ifstream infile;
    ofstream outfile;
    string num_tab[100];
    unsigned int base_tab[100], num_dec_tab[100];
    const unsigned int INFILE_LEN = 100;

    infile.open("liczby.txt");
    outfile.open("wynik.txt", ios::app);
    
    /* sprawdzanie, czy plik nie jest uszkodzony */
    if (!infile.good() || !outfile.good()) {
        cout << "Plik nie mógł być otwarty" << "\n";
        return 1;
    }

    /* wczytanie całego pliku do tablic */
    for (int index = 0; index < INFILE_LEN; index++)
        infile >> base_tab[index] >> num_tab[index];

    /* zamknięcie plików */
    infile.close();

    /* Utworzenie tablicy z liczbami w systemie dziesiętnym */
    for (int index = 0; index < INFILE_LEN; index++)
        num_dec_tab[index] = ns_to_dec(num_tab[index], base_tab[index]);

    /* Przesortowanie tablic z oryginalnymi danymi */
    SelectionSort(num_dec_tab, num_tab, base_tab, INFILE_LEN);

    outfile << "/// ZAD. 3 ///" << "\n";
    /* Wypisanie przesortowanych tablic */
    for (int index = 0; index < INFILE_LEN; index++) {
        // cout << index << ": " << base_tab[index] << " | " << num_tab[index] << "\n";
        outfile << index << ": " << base_tab[index] << " | " << num_tab[index] << "\n";
    }
    outfile << "\n";

    outfile.close();
    return 0;
}

/* funkcja zamieniająca liczbę z systemu o podstawie < 10
 * na system dziesiętny */
int ns_to_dec(string num, unsigned int base) {
    int decimal = 0;

    for (int index = 0; index < num.size(); index++)
        decimal = (decimal * base) + (num[index] - '0');

    return decimal;
}
 
/* Algorytm sortowania przez wstawianie */
void SelectionSort(unsigned int array[], string num_array[], unsigned int base_array[], unsigned int array_len) {
    unsigned int tmp, current_index, compared_index, switching_index;
    string tmp_num;

    /* Iteracja przez całą tablicę */
    for (current_index = 0; current_index < array_len - 1; current_index++) {
        switching_index = current_index;
        /* Iteracja przez całą tablicę w poszukiwaniu najmniejszego elementu */
        for (compared_index = current_index + 1; compared_index < array_len; compared_index++)
            /* jeżeli znaleziono element mniejszy od poprzedniego minimum
             * to indeks najmniejszego jest aktualizowany */
            if (array[compared_index] < array[switching_index])
                switching_index = compared_index;

        /* Zamiana pierwszego i najmniejszego nieposortowanego elementu */
        tmp = array[current_index]; 
        array[current_index] = array[switching_index]; 
        array[switching_index] = tmp;

        /* Zamiana elementów oryginalnych tablic z liczbami i podstawami systemów */
        tmp_num = num_array[current_index]; 
        num_array[current_index] = num_array[switching_index]; 
        num_array[switching_index] = tmp_num;

        tmp= base_array[current_index]; 
        base_array[current_index] = base_array[switching_index]; 
        base_array[switching_index] = tmp;
    }
}
