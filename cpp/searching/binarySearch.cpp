#include <iostream>
#include <fstream>
using std::cout;
using std::cin;
using std::ios;
using std::ifstream;
using std::ofstream;

int BinarySearch (int checkedNum, int array[], unsigned int arrayLen);
void PrintArray (int array[], unsigned int arrayLen);

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
    foundIndex = BinarySearch(checkedNum, array, ARRAYLEN);

    /* Wypisanie indeksu znalezionej cyfry */
    if (foundIndex == -1)
        outputFile << "Elementu nie znaleziono w zbiorze" << "\n";
    else
        outputFile << "Element znajduje się w zbiorze pod indeksem: " << foundIndex << "\n";

    inputFile.close(); 
    outputFile.close();
    return 0;
}

int BinarySearch(int checkedNum, int array[], unsigned int arrayLen) {
    /* Ustawienie lewego indeksu na  */
    unsigned int leftIndex = 0, rightIndex = arrayLen - 1, centerIndex;
    
    /* Dopóki lewy i prawy indeks nie zrównły się bądź minęły się */
    while (leftIndex < rightIndex) {
        /* Obliczenie środkowego indeksu spawdzanego przedziału */
        centerIndex = (leftIndex + rightIndex) / 2;
        /* Jeżeli liczba pod indeksem środka sprawdzanego przedziału
         * jest mniejsza od sprawdzanej liczby, to lewa granica przedziału
         * jest przesuwana na jeden indeks po poprzednim środku 
         * W przeciwnym wypadku przesuwa się prawa granica przedziału */
        if (array[centerIndex] < checkedNum)
            leftIndex = centerIndex + 1;
        else
            rightIndex = centerIndex;
    }
    
    if (centerIndex > 0)
        return centerIndex;

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
