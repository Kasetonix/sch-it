#include <iostream>
#include <fstream>

using std::cout;
using std::cin;
using std::ios;
using std::fstream;
using std::string;

int main() {
    ifstream inputFile;
    ofstream outputFile;
    string pass1, pass2;

    /* Otwieranie obu plików - wejściowy i wyjściowy */
    inputFile.open("hasla.txt");
    outputFile.open("passCopy.txt");

    /* Wyjście z programu, gdy nie udało się otworzyć plików */
    if (!inputFile.good() || !outputFile.good()) {
        cout << "[ERR]: Wczytywanie pliku z hasłami się nie powiodło." << "\n";
        return 1;
    }
    
    /* Iteracja przez cały plik,
     * wczytywanie haseł w jednej linijce do dwóch zmiennych 
     * i zapisywanie tych zmiennych w pliku wyjściowym */
    for (int i = 0; i < 1000; i++) {
        inputFile >> pass1 >> pass2;
        outputFile << pass1 << " " << pass2 << "\n";
    }

    /* Zamknięcie obu plików */
    inputFile.close();
    outputFile.close();

    return 0;
}
