#include <iostream>
#include <fstream>

using std::cout;
using std::ofstream;
using std::ifstream;
using std::string;

struct local {
    string country_code;
    string mall;
    unsigned short area;
};

const unsigned short CITY_NUM = 50, LOCAL_NUM = 70;

void SortLocals(local tab[CITY_NUM][LOCAL_NUM], unsigned short sorted_city, unsigned short array_len);

int main() {
    local local_tab[CITY_NUM][LOCAL_NUM];
    string c_country, c_mall, s_diff_locals_mall, g_diff_locals_mall;
    short mall_index = 0, local_index = 0, c_length = 0, c_width = 0,
          c_diff_locals = 0, s_diff_locals = 32767, g_diff_locals = 0;

    /* pliki wejściowy i wyjściowy */
    ifstream infile;
    ofstream outfile;
    infile.open("galerie.txt");
    outfile.open("wynik.txt", std::ios::app);
    
    /* sprawdzanie, czy pliki są otwarte poprawnie */
    if (!infile.good() || !outfile.good()) {
        cout << "Plik nie mógł być otwarty" << "\n";
        return 1;
    }
    
    /* wpisanie do tabeli informacji z pliku wejściowego */
    for (mall_index = 0; mall_index < CITY_NUM; mall_index++) {
        infile >> c_country >> c_mall;
        for (local_index = 0; local_index < LOCAL_NUM; local_index++) {
            /* Wpisanie kraju i miasta z tej operacji do odpowiednich pól */
            local_tab[mall_index][local_index].country_code = c_country;
            local_tab[mall_index][local_index].mall = c_mall;
            /* Wpisanie powierzchni danego lokalu */
            infile >> c_length >> c_width;
            local_tab[mall_index][local_index].area = c_length * c_width;
        }
    }

    /* Zamknięcie pliku wejściowego */
    infile.close();

    /* Nagłówek zadania */
    outfile << "----- 3 -----" << "\n";

    /* Sortowanie (przez wybieranie) lokali w danej galerii
     * ze względu na powierzchnię */
    for (mall_index = 0; mall_index < CITY_NUM; mall_index++)
        SortLocals(local_tab, mall_index, LOCAL_NUM);

    /* Zliczanie zmian powierzchni lokali -> rodzajów lokali w każdej galerii */
    for (mall_index = 0; mall_index < CITY_NUM; mall_index++) {
        for (local_index = 0; local_index < LOCAL_NUM; local_index++) {
            /* ignorujemy nieistniejące "lokale" o powierzchni 0 */
            if (local_tab[mall_index][local_index].area == 0)
                continue;

            /* Jeżeli następny lokal ma inną powierzchnię, to ma inny rodzaj */
            if (local_tab[mall_index][local_index].area != local_tab[mall_index][local_index + 1].area)
                c_diff_locals++;
        }

        /* Szukanie największej i najmniejszej liczby różnych lokali */
        if (c_diff_locals < s_diff_locals) {
            s_diff_locals = c_diff_locals;
            s_diff_locals_mall = local_tab[mall_index][0].mall;
        } else if (c_diff_locals > g_diff_locals) {
            g_diff_locals = c_diff_locals;
            g_diff_locals_mall = local_tab[mall_index][0].mall;
        }

        /* Zerowanie licznika */
        c_diff_locals = 0;
    }

    outfile << g_diff_locals_mall << " " << g_diff_locals << "\n";
    outfile << s_diff_locals_mall << " " << s_diff_locals << "\n";
    
    outfile << "\n";
    outfile.close();
    return 0;
}

void SortLocals(local tab[CITY_NUM][LOCAL_NUM], unsigned short sorted_city, unsigned short array_len) {
    unsigned int current_index, compared_index, switching_index;
    local tmp;

    /* Iteracja przez całą tablicę */
    for (current_index = 0; current_index < array_len - 1; current_index++) {
        switching_index = current_index;
        /* Iteracja przez całą tablicę w poszukiwaniu najmniejszego elementu */
        for (compared_index = current_index + 1; compared_index < array_len; compared_index++)
            /* jeżeli znaleziono element mniejszy od poprzedniego minimum
             * to indeks najmniejszego jest aktualizowany */
            if (tab[sorted_city][compared_index].area < tab[sorted_city][switching_index].area)
                switching_index = compared_index;

        /* Zamiana pierwszego i najmniejszego nieposortowanego elementu */
        tmp = tab[sorted_city][current_index]; 
        tab[sorted_city][current_index] = tab[sorted_city][switching_index]; 
        tab[sorted_city][switching_index] = tmp;
    }
}
