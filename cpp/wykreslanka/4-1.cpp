#include <iostream>
#include <fstream>
using std::cout;
using std::string;
using std::ifstream;
using std::ofstream;

int main() {
    ifstream input;
    ofstream output;
    string currentLine;
    unsigned int column = 0, line = 0;
    char file[200][100];

    /* Otwarcie plików */
    input.open("wykreslanka.txt");
    output.open("wykreslanka-out.txt", std::ios::app);
    if (!input.good() || !output.good()) {
        cout << "Couldn't open input / output file" << "\n";
        return 1;
    }

    // output << "[POZIOMO]" << "\n";
    // /* Iteracja przez cały plik */
    // while (input >> currentLine) {
    //     /* Iteracja przez cały wiersz poza 5 ostatnimi znakami
    //      * Są one sprawdzane w pętli*/
    //     for (column = 0; column < currentLine.size() - 5; column++) {
    //         /* Odrzucanie przypadków, w których kolejne litery
    //          * słowa 'matura' nie są obecne na odpowiednim miejscu */
    //         if      (currentLine[column+0] != 'm') continue;
    //         else if (currentLine[column+1] != 'a') continue;
    //         else if (currentLine[column+2] != 't') continue;
    //         else if (currentLine[column+3] != 'u') continue;
    //         else if (currentLine[column+4] != 'r') continue;
    //         else if (currentLine[column+5] != 'a') continue;
    //         else /* Jeżeli znaki tworzą wyraz 'matura', zapisanie jego wiersza i kolumny */ 
    //             output << "Wiersz: " << line << " | " << "Kolumna: " << column << "\n";
    //     }
    //
    //     /* Aktualizacja zmiennej przechowującej numer linijki */
    //     line++;
    // }
    
    /* Skopiowanie pliku do tabeli dwuwymiarowej 'file' */
    while (input >> currentLine) {
        /* iteracja przez całą linijkę i przekopiowanie jej do tabeli */
        for (column = 0; column < 100; column++)
            file[line][column] = currentLine[column];
        line++; /* zwiększenie zmiennej przechowującej linijkę */
    }

    input.close();
    output.close();
    return 0;
}
