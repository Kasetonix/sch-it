#include <iostream>
#include <cwchar>
#include <typeinfo>
using std::cout;

void BubbleSort(int array[], unsigned int arrayLen);
void PrintArray(int array[], unsigned int arrayLen);

int main() {
    int array[] = { 5, 3, 8, 9, 6, 12, 38, 5, 2, 27 };

    /* Uzyskanie długości tablicy
     * Nie wiadomo dlaczego, ale żeby drugie sizeof zwróciło poprawną wartość,
     * trzeba podzielić zwracaną wartość przez 2 */
    unsigned int arrayLen = ( sizeof(array) / (sizeof(typeid(array).name())/2) );

    cout << "[ARRAY] przed sortowaniem:" << "\n";
    PrintArray(array, arrayLen);

    BubbleSort(array, arrayLen);

    cout << "[ARRAY] po sortowaniu:" << "\n";
    PrintArray(array, arrayLen);

    return 0;
}

/* Algorytm sortowania bąbelkowego (przez prostą zamianę) */
void BubbleSort(int array[], unsigned int arrayLen) {
    /* Tymczasowa zmienna wykorzystywana przy zamianie */
    int tmp;

    /* Sortowanie kolejnych elementów tablicy */
    for (int sortedNum = 0; sortedNum < arrayLen; sortedNum++) {
        /* Porównywanie obecnej liczby z kolejnymi elementwami tablicy */
        for (int comparison = 0; comparison < arrayLen - sortedNum; comparison++) {
            /* Samo porównanie i zamiana ze sobą liczb */
            if (array[comparison] > array[comparison + 1]) {
                tmp = array[comparison];    
                array[comparison] = array[comparison + 1];
                array[comparison + 1] = tmp;
            }
        }
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
