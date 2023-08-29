#include <iostream>
#include <fstream>
using std::cout;
using std::string;
using std::ifstream;
using std::ofstream;

int main() {
    string currentBinNum;
    unsigned int index = 0, correctNum = 0;
    bool isCorrect = true;
    ifstream inputFile;
    ofstream outputFile;

    /* Otwarcie plików i obsługa błędów */
    inputFile.open("ciagi.txt");
    outputFile.open("63.txt", std::ios::app);
    if (!inputFile.good() || !outputFile.good()) {
        cout << "Couldn't open files." << "\n";
        return 1;
    }

    /* Nagłówek odpowiedzi */
    outputFile << "[63.2]" << "\n";

    /* Iteracja przez cały plik */
    while (inputFile >> currentBinNum) {
        /* Zakładanie, że liczba nie posiada 1 koło siebie */
        isCorrect = true;

        /* Iteracja przez całego stringa z obecną liczbą
         * poza ostatnią cyfrą - jest ona i tak sprawdzona w pętli */
        for (index = 0; index <= currentBinNum.size() - 2; index++) { 
            /* Kontynuowanie do następnej iteracji, 
             * jeżeli obecnie sprawdzana liczba to 0 */
            if (currentBinNum[index] == '0') continue;

            /* Zmiana wartości zmiennej przechowującej poprawność i wyjście z pętli */
            if (currentBinNum[index] == currentBinNum[index + 1]) {
                isCorrect = false;
                break;
            }
        }

        /* Zwiększenie liczby 'poprawnych' liczb */
        if (isCorrect) 
            correctNum++;
    }

    outputFile << "Liczba ciągów bez '1' koło siebie wynosi: " << correctNum << "\n";

    inputFile.close();
    outputFile.close();
    return 0;
}
