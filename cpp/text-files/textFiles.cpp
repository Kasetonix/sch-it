#include <iostream>
#include <fstream>
using std::cout;
using std::cin;
using std::ios;
using std::fstream;
using std::string;

int main() {
    /* Deklarowanie zmiennych obsługi plików */
    fstream dataFile;
    /* Otwarcie pliku i oznaczenie, że jest on otwarty tylko do odczytu */
    dataFile.open("dane.txt", ios::in);

    /* Jeżeli plik został poprawnie otwarty, wykonujemy operacje w ifie */
    if (dataFile.is_open()) {
        string dataLine;
        cout << "File's contents: " << "\n";

        /* Jeżeli plik się nie skończył (nie doszedł do EOF) */
        while (!dataFile.eof()) {
            getline(dataFile, dataLine); 
            cout << dataLine << "\n";
        }

        /* Zamknięcie pliku */
        dataFile.close();
    } else cout << "[ERR] Couldn't open file [dane.txt]" << "\n";

	return 0;
}
