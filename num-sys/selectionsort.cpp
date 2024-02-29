#include <iostream>
#include <cwchar>
#include <typeinfo>
using std::cout;

void SelectionSort(int array[], unsigned int arrayLen);
void PrintArray(int array[], unsigned int arrayLen);

int main() {
    int array[] = { 0, 5, 3, 8, 9, 6, 12, 38, 5, 2, 27 };

    /* Uzyskanie długości tablicy
     * Nie wiadomo dlaczego, ale żeby drugie sizeof zwróciło poprawną
     * wartość, to trzeba podzielić zwracaną wartość przez 2.
    * Dla efektywności licznik jest mnożony przez 2 */
    unsigned int arrayLen = (2 * sizeof(array) / sizeof(typeid(array).name()));

    cout << "[ARRAY] przed sortowaniem:" << "\n";
    PrintArray(array, arrayLen);

    /* [NIEMALEJĄCO] */
    SelectionSort(array, arrayLen);
    cout << "\n";
    cout << "[ARRAY] po sortowaniu niemalejacym: " << "\n";
    PrintArray(array, arrayLen);

    return 0;
}

/* Algorytm sortowania przez wstawianie */
void SelectionSort(int array[], unsigned int arrayLen) {
    unsigned int tmp, currentIndex, comparedIndex, switchingIndex;

    /* Iteracja przez całą tablicę */
    for (currentIndex = 0; currentIndex < arrayLen - 1; currentIndex++) {
        switchingIndex = currentIndex;
        /* Iteracja przez całą tablicę w poszukiwaniu najmniejszego elementu */
        for (comparedIndex = currentIndex + 1; comparedIndex < arrayLen; comparedIndex++) {
            /* jeżeli znaleziono element mniejszy od poprzedniego minimum
             * to indeks najmniejszego jest aktualizowany */
            if (array[comparedIndex] < array[switchingIndex])
                switchingIndex = comparedIndex;
        }

        /* Zamiana pierwszego i najmniejszego nieposortowanego elementu */
        tmp = array[currentIndex]; 
        array[currentIndex] = array[switchingIndex]; 
        array[switchingIndex] = tmp;
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
