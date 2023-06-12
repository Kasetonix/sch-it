#include <iostream>
#include <fstream>
using std::cout;
using std::string;
using std::ifstream;
using std::ofstream;

/* Ustawienie rozmiaru pliku */
const unsigned short FILE_COLS = 200, FILE_LINES = 100;
int FindLongestSeqLen(char file[FILE_COLS][FILE_LINES], unsigned short line);

int main() {
    ifstream input;
    ofstream output;
    unsigned short column = 0, line = 0;
    unsigned short longestSeqLen = 1;
    char file[FILE_COLS][FILE_LINES];
    string currentLine;

    /* Otwarcie plików */
    input.open("wykreslanka.txt");
    output.open("4-2_out.txt");
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

    /* Sprawdzenie długości najdłuższego ciągu znaków w danej linijce i
     * nadpisanie najdłuższej długości ciągu w pliku.*/
    for (line = 0; line < FILE_LINES; line++) {
        if (FindLongestSeqLen(file, line) > longestSeqLen)
            longestSeqLen = FindLongestSeqLen(file, line);
        // cout << "[DEBUG] longestSeqLen @ " << line << ": " << FindLongestSeqLen(file, line) << "\n";
    }

    /* Wyszukanie linijek posiadających ciągu znaków o wcześniej znalezionej długości */
    output << "Najdłuższy ciąg takich samych znaków ma długość: " << longestSeqLen << "\n";
    output << "Ciagi o tej długości znajdują się w linijkach: ";
    for (line = 0; line < FILE_LINES; line++) {
        if (FindLongestSeqLen(file, line) == longestSeqLen)
            output << line << " ";
    }
    output << "\n";

    output.close();
    return 0;
}

int FindLongestSeqLen(char file[FILE_COLS][FILE_LINES], unsigned short line) {
    unsigned int column = 0, longestSeqLen = 1, currentSeqLen = 1;
    char currChar, prevChar;

    /* Utworzenie zmiennej przechowującej początkowy znak do porównania */
    prevChar = file[column][line];

    /* Iteracja przez całą linijkę pliku poza indeksem 0 - najpierw porównujemy indeks 1 i 0 */
    for (column = 1; column < FILE_COLS; column++) {
        /* (dla czytelności)
         * utworzenie zmiennej przechowującej obecnie przetrzymywany znak */
        currChar = file[column][line];

        /* Sprawdzenie, czy obecnie sprawdzany znak jest taki sam jak poprzedni - 
         * tworząc lub kontynuując ciąg */
        if (currChar == prevChar) {
            /* Jeżeli jest, zwiększenie długości obecnego ciągu */
            currentSeqLen++;
            /* Ewentualne nadpisanie długości najdłuższego ciągu */
            if (currentSeqLen > longestSeqLen)
                longestSeqLen = currentSeqLen;
        } else {
            /* Jeżeli znak nie jest taki sam, zresetowanie długości ciągu do 1 */
            currentSeqLen = 1;
        }

        /* Przejście do następnego porównania */
        prevChar = currChar;
    }

    /* Zwrócenie szukanej długości ciągu */
    return longestSeqLen;
}
