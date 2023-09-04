#include <iostream>
#include <fstream>

using std::cout;
using std::cin;
using std::ios;
using std::ifstream;
using std::ofstream;
using std::string;

int main() {
    ifstream inputFile;
    ofstream outputFile;
    string dataLine;
    int currentLastDigit;
    int evenAmount = 0;

    /* Otwieranie odpowiednich plików */
    inputFile.open("dane.txt");
    outputFile.open("evenNums.txt");

    /* Sprawdzanie, czy plik się otworzył poprawnie */
    if (!inputFile.good() || !outputFile.good()) {
        cout << "[ERR] couldn't open files" << "\n";
    }

    /* Iteracja przez cały plik */
    for (int i = 0; i < 200; i++) {
        /* Wczytanie linijki z pliku */
        inputFile >> dataLine;
        /* wczytanie z linijki ostatniej cyfry */
        currentLastDigit = dataLine[dataLine.size() - 1] - '0';
        
        /* sprawdzanie, czy ostatnia cyfra liczby jest parzysta */
        if (currentLastDigit % 2 == 0) {
            outputFile << dataLine << "\n";
            evenAmount++;
        }
    }

    cout << "Liczba liczb parzystych w tym pliku: " << evenAmount << "\n";

    inputFile.close();
    outputFile.close();
    return 0;
}
