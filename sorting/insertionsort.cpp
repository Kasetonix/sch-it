#include <iostream>
#include <cwchar>
#include <typeinfo>
using std::cout;

void InsertionSort(int array[], unsigned int arrayLen);
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
    InsertionSort(array, arrayLen);
    cout << "\n";
    cout << "[ARRAY] po sortowaniu niemalejacym: " << "\n";
    PrintArray(array, arrayLen);

    return 0;
}

/* Algorytm sortowania przez wstawianie */
void InsertionSort(int array[], unsigned int arrayLen) {
    unsigned int currentIndex, comparedIndex;
    
    /* Iteracja przez całą tablicę od 2 indeksu
     * indeks 0 to wartownik i zmienna pomocnicza
     * indeks 1 to pierwsza porównywana liczba */
    for (currentIndex = 2; currentIndex <= arrayLen; currentIndex++) {
        /* Wstawienie obecnej liczby do "zmiennej pomocniczej" */
        array[0] = array[currentIndex];
        /* Ustawienie porównywanej obecnie liczby */
        comparedIndex = currentIndex - 1;

        /* Sprawdzanie kolejnych liczb w tabeli od tyłu 
         * Wyjście z pętli, gdy znajdzie się miejsce,
         * do którego należy wstawić sprawdzaną liczbę */
        while (array[comparedIndex] > array[0]) {
            array[comparedIndex + 1] = array[comparedIndex];
            comparedIndex--;
        }

        /* Kiedy pętla się zakończy wstawienie sprawdzanej liczby
         * w indeks po tym, który spowodował wyjście z pętli*/
        array[comparedIndex + 1] = array[0];
    }
}

void PrintArray(int array[], unsigned int arrayLen) {
    unsigned int currentElement;
    /* Iteracja przez całą tablicę */
    for (currentElement = 1; currentElement < arrayLen; currentElement++) {
        /* Jeżeli dany element nie jest ostatnią liczbą tablicy wypisanie 
         * go z przecinkiem. Jeżeli jest, wypisanie go z nową linią */
        if (currentElement != arrayLen - 1)
            cout << array[currentElement] << ", ";
        else cout << array[currentElement] << "\n";
    }
}
