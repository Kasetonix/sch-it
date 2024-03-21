#include <iostream>
#include <fstream>

using std::cout;
using std::string;
using std::ifstream;
using std::ofstream;

unsigned int GetDecimal(string binary);
string GetBinary(unsigned int decimal);

struct num {
    unsigned int dec;
    string bin;
};

int main() {
    const unsigned short FILE_LEN = 1000;
    unsigned int index, even_count = 0, largest_num_index, largest_num = 0, nine_len_count = 0, nine_sum = 0;
    num num_tab[FILE_LEN]; 

    /* Pliki */
    ifstream infile; ofstream outfile;
    infile.open("liczby.txt");
    outfile.open("wynik.txt");
    if (!infile.good() || !outfile.good()) {
        cout << "Plik nie mógł być otwarty" << "\n";
        return 1;
    }

    /* Wypełnianie tablicy */
    for (index = 0; index < FILE_LEN; index++) {
        infile >> num_tab[index].bin;
        num_tab[index].dec = GetDecimal(num_tab[index].bin);
    }

    outfile << "----- 1 -----" << "\n";
    
    /* Pętla iterująca przez cały plik i sprawdzająca parzystość liczb */
    for (index = 0; index < FILE_LEN; index++) {
        if (num_tab[index].bin[num_tab[index].bin.size() - 1] == '0') {
            even_count++;
        }
    }
    outfile << "Liczba liczb parzystych w pliku: " << even_count << "\n\n";

    outfile << "----- 2 -----" << "\n";
    for (index = 0; index < FILE_LEN; index++) {
        if (num_tab[index].dec > largest_num) {
            largest_num = num_tab[index].dec;
            largest_num_index = index;
        }
    }

    outfile << "Największa liczba (10): " << num_tab[largest_num_index].dec << "\n";
    outfile << "Najwięszka liczba (2):  " << num_tab[largest_num_index].bin << "\n\n";

    outfile << "----- 3 -----" << "\n";
    for (index = 0; index < FILE_LEN; index++) {
        if (num_tab[index].bin.length() == 9) {
            nine_len_count++;
            nine_sum += num_tab[index].dec;
        }
    }

    outfile << "Liczba liczb o długości 9:   " << nine_len_count << "\n";
    outfile << "Suma liczb o długości 9 (2): " << GetBinary(nine_sum) << "\n";

    return 0;
}

unsigned int GetDecimal(string binary) {
    unsigned int decimal = 0; 

    for (int index = 0; index < binary.length(); index++) {
        decimal = decimal * 2 + int(binary[index] - '0');
    }

    return decimal;
}

string GetBinary(unsigned int decimal) {
    string binary;
    
    while (decimal > 0) {
        /* Sprawdzanie, czy liczba jest podzielna przez dwa
         * - Jeżeli jest, to dokładamy '0' na jej początek 
         * - Jeżeli nie jest, to dokładamy '1' */
        if (decimal % 2 == 0)
            binary = '0' + binary;
        else
            binary = '1' + binary;

        /* Przechodzenie do następnej liczby */
        decimal /= 2;
    }

    return binary;
}
