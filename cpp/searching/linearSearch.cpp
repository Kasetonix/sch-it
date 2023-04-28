#include <iostream>
#include <fstream>
using std::cout;
using std::cin;
using std::ios;
using std::ifstream;
using std::ofstream;

int LinearSearch(int checkedNum, int array[], unsigned int arrayLen);
void PrintArray(int array[], unsigned int arrayLen);

int main() {
    ifstream inputFile;
    ofstream outputFile;
    const unsigned int ARRAYLEN = 1000;
    int array[ARRAYLEN], checkedNum;
    unsigned int foundIndex;

    /* Otwarcie plików wejściowego i wyjściowego */
    inputFile.open("liczby.txt");
    outputFile.open("linearSearch_out.txt", std::ios::app);

    /* Zwrócenie błędu w razie niepoprawnego otwarcia plików */
    if (!inputFile.good() || !outputFile.good()) {
        cout << "[ERR] couldn't open files" << "\n";
        return 1;
    }

    /* Zapytanie o liczbę do wyszukania */
    cout << "Wprowadź liczbę do wyszukania: "; cin >> checkedNum;
    
    /* Przerzucenie całego pliku do tabeli */
    for (int currentIndex = 0; currentIndex < ARRAYLEN; currentIndex++)
        inputFile >> array[currentIndex];
    
    /* Zapisanie odpowiedzi */
    foundIndex = LinearSearch(checkedNum, array, ARRAYLEN);

    /* Wypisanie indeksu znalezionej cyfry */
    if (foundIndex == -1)
        outputFile << "Elementu nie znaleziono w zbiorze" << "\n";
    else
        outputFile << "Element znajduje się w zbiorze pod indeksem: " << foundIndex << "\n";

    inputFile.close(); 
    outputFile.close();
    return 0;
}

int LinearSearch(int checkedNum, int array[], unsigned int arrayLen) {
    int currentIndex;

    /* Iteracja przez całą tablicę i zwrócenie true w wypadku znalezienia tego elementu */
    for (currentIndex = 0; currentIndex < arrayLen; currentIndex++)
        if (array[currentIndex] == checkedNum)
            return currentIndex;

    /* Zwrócenie -1, kiedy nie znajdzie liczby na żadnym indeksie */
    return -1;
}

void PrintArray(int array[], unsigned int arrayLen) {
    unsigned int currentElement;
    /* Iteracja przez całą tablicę */
    for (currentElement = 0; currentElement < arrayLen; currentElement++) {
        /* Jeżeli dany element nie jest ostatnią liczbą tablicy wypisanie 
         * go z przecinkiem. Jeżeli jest, wypisanie go z nową linią */
        if (currentElement != arrayLen - 1)
            cout << array[currentElement] << ", ";
        else cout << array[currentElement] << "\n";
    }
}
