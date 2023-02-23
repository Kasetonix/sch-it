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
    string dataLine, maxDigitSumNum, minDigitSumNum;
    unsigned short currentLastDigit;
    unsigned int evenAmount = 0, currentDigitSum, maxDigitSum = 0, minDigitSum = 81, currentDigit, previousDigit;
    bool isRaising;

    /* Otwieranie odpowiednich plików */
    inputFile.open("cyfry.txt");
    outputFile.open("wynik.txt", ios::app);

    /* Sprawdzanie czy odpowiednie pliki otworzyły się poprawnie */
    if (!inputFile.good() || !outputFile.good())
        cout << "[ERR] couldn't open files." << "\n";

    /* Iteracja przez wszystkie liczby */
    for (int line = 0; line < 1000; line++) {
        inputFile >> dataLine;
        /* wczytywanie ostatniej cyfry ze stringa */
        currentLastDigit = dataLine[dataLine.size() - 1] - '0';

        /* Sprawdzanie, czy ostatnia cyfra danej liczby jest parzysta */
        if (currentLastDigit % 2 == 0)
            evenAmount++;
    }

    outputFile << "Liczba liczb parzystych wynosi: " << evenAmount << "\n";

    /* Ponowne otwarcie pliku wejściowego */
    inputFile.close();
    inputFile.open("cyfry.txt");
    dataLine = "";

    /* Sprawdzanie czy odpowiednie pliki otworzyły się poprawnie */
    if (!inputFile.good() || !outputFile.good())
        cout << "[ERR] couldn't open files." << "\n";

    /* Iteracja przez cały plik wejściowy */
    for (int line = 0; line < 1000; line++) {
        /* Zapisanie obecnej linijki w zmiennej */
        inputFile >> dataLine;
        currentDigitSum = 0;
        
        for (int index = 0; index < dataLine.size() - 1; index++) {
            /* Zamiana cyfry z stringa na inta */
            currentDigit = dataLine[index] - '0';
            /* Dodanie obecnej cyfry do sumy */
            currentDigitSum += currentDigit;
            
            /* Jeżeli będzie znaleziona liczba z większą sumą
             * zmienna o maksymalnej sumie zostanie nadpisana.
             * Tak samo jest z minimalną sumą */
            if (currentDigitSum > maxDigitSum) { 
                maxDigitSum = currentDigitSum;
                maxDigitSumNum = dataLine;
            } else if (currentDigitSum < minDigitSum) {
                minDigitSum = currentDigitSum;
                minDigitSumNum = dataLine;
            }
        }
    }

    outputFile << "Liczba z maksymalną sumą cyfr: " << maxDigitSumNum << "\n"; 
    outputFile << "Liczba z minimalną sumą cyfr: " << minDigitSumNum << "\n"; 
    
    /* Ponowne otwarcie pliku wejściowego */
    inputFile.close();
    inputFile.open("cyfry.txt");
    dataLine = "";

    /* Sprawdzanie czy odpowiednie pliki otworzyły się poprawnie */
    if (!inputFile.good() || !outputFile.good())
        cout << "[ERR] couldn't open files." << "\n";

    while (!inputFile.eof()) {
        isRaising = true;
    }

    inputFile.close();
    outputFile.close();
    return 0;
}
