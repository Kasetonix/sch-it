#include <iostream>
#include <cwchar>
#include <typeinfo>
using std::cout;

void SelectionSortAsc(int array[], unsigned int arrayLen);
void SelectionSortDesc(int array[], unsigned int arrayLen);
void PrintArray(int array[], unsigned int arrayLen);

int main() {
    int array[] = { 5, 3, 8, 9, 6, 12, 38, 5, 2, 27 };

    /* Uzyskanie długości tablicy
     * Nie wiadomo dlaczego, ale żeby drugie sizeof zwróciło poprawną
     * wartość, to trzeba podzielić zwracaną wartość przez 2.
    * Dla efektywności licznik jest mnożony przez 2 */
    unsigned int arrayLen = (2 * sizeof(array) / sizeof(typeid(array).name()));

    cout << "[ARRAY] przed sortowaniem:" << "\n";
    PrintArray(array, arrayLen);
    cout << "\n";

    cout << "[ARRAY] po przesortowaniu nierosnącym" << "\n";
    SelectionSortAsc(array, arrayLen);
    PrintArray(array, arrayLen);
    cout << "\n";

    cout << "[ARRAY] po przesortowaniu niemalejącym" << "\n";
    SelectionSortDesc(array, arrayLen);
    PrintArray(array, arrayLen);

    return 0;
}

void SelectionSortAsc(int array[], unsigned int arrayLen) {
    unsigned int checkedNum;
    unsigned int smallestIndex;
    unsigned int comparedIndex;
    unsigned int swapTmp;

    /* Iteracja przez całość tablicy poza ostatnim - 
     * po wszystkich poprzednich iteracjach ostatnia 
     * cyfra będzie największa */
    for (checkedNum = 0; checkedNum < arrayLen - 1; checkedNum++) {
        /* Szukanie indeksu najmniejszej liczby tablicy */
        smallestIndex = checkedNum;
        for (comparedIndex = checkedNum + 1; comparedIndex < arrayLen; comparedIndex++)
            if (array[comparedIndex] < array[smallestIndex]) 
                smallestIndex = comparedIndex; 

        /* Ustawienie najmniejszej liczby tabeli na początek */
        swapTmp = array[checkedNum];
        array[checkedNum] = array[smallestIndex];
        array[smallestIndex] = swapTmp;
    }
}

void SelectionSortDesc(int array[], unsigned int arrayLen) {
    unsigned int checkedNum;
    unsigned int largestIndex;
    unsigned int comparedIndex;
    unsigned int swapTmp;

    /* Iteracja przez całość tablicy poza ostatnim - 
     * po wszystkich poprzednich iteracjach ostatnia 
     * cyfra będzie największa */
    for (checkedNum = 0; checkedNum < arrayLen - 1; checkedNum++) {
        /* Szukanie indeksu najmniejszej liczby tablicy */
        largestIndex = checkedNum;
        for (comparedIndex = checkedNum + 1; comparedIndex < arrayLen; comparedIndex++)
            if (array[comparedIndex] > array[largestIndex]) 
                largestIndex = comparedIndex; 

        /* Ustawienie najmniejszej liczby tabeli na początek */
        swapTmp = array[checkedNum];
        array[checkedNum] = array[largestIndex];
        array[largestIndex] = swapTmp;
    }
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
