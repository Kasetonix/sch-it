#include <iostream>
#include <fstream>

using std::cout;
using std::ofstream;
using std::ifstream;
using std::string;

struct local {
    string mall_country_code;
    string mall_city;
    unsigned int length;
    unsigned int width;
};

const unsigned short CITY_NUM = 10, LOCAL_NUM = 70;

void SelectionSort(local tab[CITY_NUM][LOCAL_NUM], unsigned int array_len);

int main() {
    local local_tab[CITY_NUM][LOCAL_NUM];
    string current_country, current_city;
    int city_index = 0, local_index = 0, current_count = 1;

    /* pliki wejściowy i wyjściowy */
    ifstream infile;
    ofstream outfile;
    infile.open("galerie_przyklad.txt");
    outfile.open("wynik.txt", std::ios::app);
    
    /* sprawdzanie, czy pliki są otwarte poprawnie */
    if (!infile.good() || !outfile.good()) {
        cout << "Plik nie mógł być otwarty" << "\n";
        return 1;
    }
    
    /* wpisanie do tabeli informacji z pliku wejściowego */
    for (city_index = 0; city_index < CITY_NUM; city_index++) {
        infile >> current_country >> current_city;
        for (local_index = 0; local_index < LOCAL_NUM; local_index++) {
            /* Wpisanie kraju i miasta z tej operacji do odpowiednich pól */
            local_tab[city_index][local_index].mall_country_code = current_country;
            local_tab[city_index][local_index].mall_city = current_city;
            /* Wpisanie dł. i sz. danej galerii */
            infile >> local_tab[city_index][local_index].length;
            infile >> local_tab[city_index][local_index].width;
        }
    }

    /* Zamknięcie pliku wejściowego */
    infile.close();

    /* Nagłówek zadania */
    outfile << "----- 1 -----" << "\n";
    
    /* Przesortowanie tablicy według kodów kraju */
    SelectionSort(local_tab, CITY_NUM);

    /* Zliczanie kolejno występujących kodów państw:
     * równoważne ze zliczaniem liczby miast w danym pańswie <- miasta nie powtarzają się */
    for (city_index = 0; city_index < CITY_NUM; city_index++) {
        if (local_tab[city_index][0].mall_country_code == local_tab[city_index + 1][0].mall_country_code) {
            current_count++;
            continue;
        } else {
            outfile << local_tab[city_index][0].mall_country_code << ": " << current_count << "\n";
            current_count = 1;
        }
    }

    /* Wypisanie tablicy local_tab */
    /* for(int y = 0; y < CITY_NUM; y++) {
        outfile << local_tab[y][0].mall_country_code << " " << local_tab[y][0].mall_city << " ";
        for (int x = 0; x < LOCAL_NUM; x++) {
            outfile << local_tab[y][x].length << " " << local_tab[y][x].width << " ";
        }
        outfile << "\n";
    } */

    outfile << "\n\n";
    outfile.close();
    return 0;
}

void SelectionSort(local tab[CITY_NUM][LOCAL_NUM], unsigned int array_len) {
    unsigned int current_index, compared_index, switching_index;
    local tmp;

    /* Iteracja przez całą tablicę */
    for (current_index = 0; current_index < array_len - 1; current_index++) {
        switching_index = current_index;
        /* Iteracja przez całą tablicę w poszukiwaniu najmniejszego elementu */
        for (compared_index = current_index + 1; compared_index < array_len; compared_index++)
            /* jeżeli znaleziono element mniejszy od poprzedniego minimum
             * to indeks najmniejszego jest aktualizowany */
            if (tab[compared_index][0].mall_country_code < tab[switching_index][0].mall_country_code)
                switching_index = compared_index;

        /* Zamiana pierwszego i najmniejszego nieposortowanego elementu */
        tmp = tab[current_index][0]; 
        tab[current_index][0] = tab[switching_index][0]; 
        tab[switching_index][0] = tmp;
    }
}
