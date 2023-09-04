#include <iostream>
#include <fstream>
using std::cout;
using std::ios;
using std::ifstream;
using std::ofstream;
using std::string;

int main() {
    ifstream inputFile;
    ofstream outputFile;
    string dataLine, maxDigitSumNum, minDigitSumNum;
    unsigned short currentLastDigit;
    unsigned int evenAmount = 0, currentDigitSum, maxDigitSum = 0, minDigitSum = 81, currentDigit, previousDigit, index = 0;
    bool isRaising;

    /* Otwieranie odpowiednich plików */
    inputFile.open("cyfry.txt");
    outputFile.open("wynik.txt", ios::app);

    /* Sprawdzanie czy odpowiednie pliki otworzyły się poprawnie */
    if (!inputFile.good() || !outputFile.good()) {
        cout << "[ERR] couldn't open files." << "\n"; 
        return 1;
    }

    /* Iteracja przez wszystkie liczby */
    for (int line = 0; line < 1000; line++) {
        inputFile >> dataLine;
        /* wczytywanie ostatniej cyfry ze stringa */
        currentLastDigit = dataLine[dataLine.size() - 1] - '0';

        /* Sprawdzanie, czy ostatnia cyfra danej liczby jest parzysta */
        if (currentLastDigit % 2 == 0)
            evenAmount++;
    }

    /* Wpisanie odpowiedniego wyniku do pliku wynikowego */
    outputFile << "Liczba liczb parzystych wynosi: " << evenAmount << "\n";

    /* Ponowne otwarcie pliku wejściowego */
    inputFile.close();
    inputFile.open("cyfry.txt");
    dataLine = "";

    /* Sprawdzanie czy odpowiednie pliki otworzyły się poprawnie */
    if (!inputFile.good() || !outputFile.good()) {
        cout << "[ERR] couldn't open files." << "\n";
        return 1;
    }

    /* Iteracja przez cały plik wejściowy */
    for (int line = 0; line < 1000; line++) {
        /* Zapisanie obecnej linijki w zmiennej */
        inputFile >> dataLine;
        currentDigitSum = 0;
        
        for (index = 0; index < dataLine.size(); index++) {
            /* Zamiana cyfry z stringa na inta */
            currentDigit = dataLine[index] - '0';
            /* Dodanie obecnej cyfry do sumy */
            currentDigitSum += currentDigit;
        }

        /* Jeżeli będzie znaleziona liczba z większą sumą
         * zmienna o maksymalnej sumie zostanie nadpisana.
         * Tak samo jest z minimalną sumą */
        if (currentDigitSum > maxDigitSum) { 
            maxDigitSum = currentDigitSum;
            maxDigitSumNum = dataLine;
        }

        if (currentDigitSum < minDigitSum) {
            minDigitSum = currentDigitSum;
            minDigitSumNum = dataLine;
        }
    }

    /* Wpisanie odpowiednich wyników do pliku wyjściowego */
    outputFile << "Liczba z maksymalną sumą cyfr: " << maxDigitSumNum << "\n"; 
    outputFile << "Liczba z minimalną sumą cyfr: " << minDigitSumNum << "\n"; 
    
    /* Ponowne otwarcie pliku wejściowego */
    inputFile.close();
    inputFile.open("cyfry.txt");
    dataLine = "";

    /* Sprawdzanie czy odpowiednie pliki otworzyły się poprawnie */
    if (!inputFile.good() || !outputFile.good()) {
        cout << "[ERR] couldn't open files." << "\n";
        return 1;
    }

    /* Iteracja przez cały plik wejściowy */
    for (int line = 0; line < 1000; line++) {
        /* Założenie, że liczba ma cyfry rosnące */
        isRaising = true;
        /* Wprowadzenie linijki do zmiennej */
        inputFile >> dataLine;
        /* Resetowanie wartości zmiennych */
        index = 0;
        currentDigit = dataLine[0];

        /* Pętla iterująca, gdy cyfry liczby nadal wydają się rosnące oraz
         * gdy nie zakończyło się słowo */
        while (isRaising && index < dataLine.size()) {
            /* Aktualizacja obecnej cyfry */
            currentDigit = dataLine[index];

            /* Sprawdzanie, czy liczba ma dotąd cyfry rosnące
             * (wykluczenie indexu == 0, bo wtedy nie ma sensu porównanie
             * z poprzednią cyfrą liczby) */
            if (!(previousDigit < currentDigit) && index != 0) {
                isRaising = false;
                break;
            }

            /* Jeżeli po zakończeniu się cyfry nie zauważono żeby cyfry nie były rosnące,
             * wpisanie ją do pliku wynikowego */
            if (index == dataLine.size() - 1) {
                outputFile << dataLine << "\n";
            }

            /* Przygotowanie pętli do następnej iteracji */
            previousDigit = currentDigit;
            index++;
        }
    }

    /* Zamknięcie obu programów */
    inputFile.close();
    outputFile.close();
    return 0;
}
