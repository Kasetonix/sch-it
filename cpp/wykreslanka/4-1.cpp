#include <iostream>
#include <fstream>
using std::cout;
using std::string;
using std::ifstream;
using std::ofstream;

int main() {
    ifstream input;
    ofstream output;
    unsigned short column, line = 0;
    const unsigned short FILE_COLS = 200, FILE_LINES = 100;
    char file[FILE_COLS][FILE_LINES];
    string currentLine;

    /* Otwarcie plików */
    input.open("wykreslanka.txt");
    output.open("wykreslanka-out.txt", std::ios::app);
    if (!input.good() || !output.good()) {
        cout << "Couldn't open input / output file" << "\n";
        return 1;
    }

    /* Skopiowanie pliku do tabeli dwuwymiarowej 'file' */
    while (input >> currentLine) {
        /* iteracja przez całą linijkę i przekopiowanie jej do tabeli */
        for (column = 0; column < currentLine.size(); column++) {
            file[column][line] = currentLine[column];
        }
        line++; /* zwiększenie zmiennej przechowującej linijkę */
    }

    input.close();

    /* NOTE: Wyszukiwanie 'matura' poziomo */
    output << "[POZIOMO]" << "\n";
    /* Iteracja przez całą tablicę */
    for (line = 0; line < FILE_LINES; line++) {
        /* Iteracja przez cały wiersz poza 5 ostatnimi znakami
         * Są one sprawdzane w pętli*/
        for (column = 0; column < FILE_COLS - 5; column++) {
            /* Odrzucanie przypadków, w których kolejne litery
             * słowa 'matura' nie są obecne na odpowiednim miejscu */
            if      (file[column+0][line] != 'm') continue;
            else if (file[column+1][line] != 'a') continue;
            else if (file[column+2][line] != 't') continue;
            else if (file[column+3][line] != 'u') continue;
            else if (file[column+4][line] != 'r') continue;
            else if (file[column+5][line] != 'a') continue;
            else /* Jeżeli znaki tworzą wyraz 'matura', zapisanie jego wiersza i kolumny */ 
                output << "Wiersz: " << line << " | " << "Kolumna: " << column << "\n";
        }
    }

    output << "\n";

    /* NOTE: Wyszukiwanie 'matura' pionowo */
    output << "[PIONOWO]" << "\n";
    /* Iteracja przez wszystkie kolumny tablicy */
    for (column = 0; column < FILE_COLS; column++) {
        /* Iteracja przez całą kolumnę poza 5 ostatnimi znakami
         * Są one sprawdzane w pętli*/
        for (line = 0; line < FILE_LINES - 5; line++) {
            /* Odrzucanie przypadków, w których kolejne litery
             * słowa 'matura' nie są obecne na odpowiednim miejscu */
            if      (file[column][line+0] != 'm') continue;
            else if (file[column][line+1] != 'a') continue;
            else if (file[column][line+2] != 't') continue;
            else if (file[column][line+3] != 'u') continue;
            else if (file[column][line+4] != 'r') continue;
            else if (file[column][line+5] != 'a') continue;
            else /* Jeżeli znaki tworzą wyraz 'matura', zapisanie jego wiersza i kolumny */ 
                output << "Kolumna: " << column << " | " << "Wiersz: " << line << "\n";
        }
    }

    output.close();
    return 0;
}
