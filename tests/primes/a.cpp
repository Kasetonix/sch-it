#include <iostream>
#include <fstream>
using std::cout;
using std::cin;
using std::ios;
using std::ifstream;
using std::ofstream;

int main() {
    ifstream inputFile;
    ofstream outputFile;
    int currentNum;
    unsigned short evenNum = 0, oddNum = 0;

    inputFile.open("cyfry.txt");
    outputFile.open("wynik.txt", std::ios::app);

    if (!inputFile.good() || !outputFile.good()) {
        cout << "[ERR] couldn't open files" << "\n";
    }

    outputFile << "[ZADANIE A]" << "\n";

    /* LICZBY PARZYSTE */
    outputFile << "LICZBY PARZYSTE: " << "\n";
    while (inputFile >> currentNum) {
        if (currentNum % 2 == 0) {
            outputFile << currentNum << "\n";
            evenNum++;
        }
    }

    outputFile << "\n";
    inputFile.close();

    /* LICZBY NIEPARZYSTE */
    inputFile.open("cyfry.txt");
    outputFile << "LICZBY NIEPARZYSTE: " << "\n";
    while (inputFile >> currentNum) {
        if (currentNum % 2 == 1) {
            outputFile << currentNum << "\n";
            oddNum++;
        }
    }

    outputFile << "\n";
    outputFile << "[Liczba liczb parzystych]:    " << evenNum << "\n";
    outputFile << "[Liczba liczb nieparzystych]: " << oddNum << "\n";

    outputFile << "\n \n \n";

    inputFile.close();
    outputFile.close();
    return 0;
}
