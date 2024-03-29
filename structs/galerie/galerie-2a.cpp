#include <iostream>
#include <fstream>

using std::cout;
using std::ofstream;
using std::ifstream;
using std::string;

struct local {
    string mall_country_code;
    string mall_city;
    unsigned int area;
};

const unsigned short CITY_NUM = 50, LOCAL_NUM = 70;

int main() {
    local local_tab[CITY_NUM][LOCAL_NUM];
    string c_country, c_city;
    short mall_index = 0, local_index = 0, c_length = 0, c_width = 0, c_area = 0, c_local_num = 0;

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
        infile >> c_country >> c_city;
        for (local_index = 0; local_index < LOCAL_NUM; local_index++) {
            /* Wpisanie kraju i miasta z tej operacji do odpowiednich pól */
            local_tab[mall_index][local_index].mall_country_code = c_country;
            local_tab[mall_index][local_index].mall_city = c_city;
            /* Wpisanie powierzchni danego lokalu */
            infile >> c_length >> c_width;
            local_tab[mall_index][local_index].area = c_length * c_width;
        }
    }

    /* Zamknięcie pliku wejściowego */
    infile.close();

    /* Nagłówek zadania */
    outfile << "----- 2a -----" << "\n";
    
    /* sumowanie wszystkich powierzchni i zliczanie lokali */
    for (mall_index = 0; mall_index < CITY_NUM; mall_index++) {
        for (local_index = 0; local_index < LOCAL_NUM; local_index++) {
            if (local_tab[mall_index][local_index].area != 0) {
                c_area += local_tab[mall_index][local_index].area;
                c_local_num++;
            }
        }
        
        /* Wypisanie otrzymanych danych do pliku */
        outfile << local_tab[mall_index][0].mall_city << " " << c_area << " " << c_local_num << "\n"; 

        /* Zerowanie liczników */
        c_area = 0;
        c_local_num = 0;
    }

    outfile << "\n\n";
    outfile.close();
    return 0;
}
