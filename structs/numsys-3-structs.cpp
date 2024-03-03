#include <iostream>
#include <fstream>
using std::cout;
using std::ios;
using std::string;
using std::ifstream;
using std::ofstream;

/* Structy */
struct num {
    unsigned int base;
    string num;
    unsigned int dec;
};

/* Funkcje */
unsigned int ns_to_dec(string num, unsigned int base);
void SelectionSort(num nums[], unsigned int array_len);

int main() {
    ifstream infile;
    ofstream outfile;
    const unsigned short INFILE_LEN = 100;
    num nums[INFILE_LEN];

    infile.open("liczby.txt");
    outfile.open("wynik.txt", ios::app);
    
    /* sprawdzanie, czy plik nie jest uszkodzony */
    if (!infile.good() || !outfile.good()) {
        cout << "Plik nie mógł być otwarty" << "\n";
        return 1;
    }

    /* wczytanie całego pliku do tablic */
    for (short index = 0; index < INFILE_LEN; index++)
        infile >> nums[index].base >> nums[index].num;

    /* zamknięcie plików */
    infile.close();

    /* Utworzenie tablicy z liczbami w systemie dziesiętnym */
    for (short index = 0; index < INFILE_LEN; index++)
        nums[index].dec = ns_to_dec(nums[index].num, nums[index].base);

    /* Przesortowanie tablicy z oryginalnymi danymi */
    SelectionSort(nums, INFILE_LEN);

    /* Wypisanie przesortowanych tablic */
    for (short index = 0; index < INFILE_LEN; index++)
        outfile << index << ": " << nums[index].base << " | " << nums[index].num << "\n";

    outfile.close();
    return 0;
}

/* Funkcja zamieniająca liczbę z systemu o podstawie < 10
 * na system dziesiętny */
unsigned int ns_to_dec(string num, unsigned int base) {
    int decimal = 0;

    for (int index = 0; index < num.size(); index++)
        decimal = (decimal * base) + (num[index] - '0');

    return decimal;
}
 
/* Algorytm sortowania przez wstawianie */
void SelectionSort(num nums[], unsigned int array_len) {
    unsigned int current_index, compared_index, switching_index;
    num tmp;

    /* Iteracja przez całą tablicę */
    for (current_index = 0; current_index < array_len - 1; current_index++) {
        switching_index = current_index;
        /* Iteracja przez całą tablicę w poszukiwaniu najmniejszego elementu */
        for (compared_index = current_index + 1; compared_index < array_len; compared_index++)
            /* jeżeli znaleziono element mniejszy od poprzedniego minimum
             * to indeks najmniejszego jest aktualizowany */
            if (nums[compared_index].dec < nums[switching_index].dec)
                switching_index = compared_index;

        /* Zamiana pierwszego i najmniejszego nieposortowanego elementu */
        tmp = nums[current_index]; 
        nums[current_index] = nums[switching_index]; 
        nums[switching_index] = tmp;
    }
}
