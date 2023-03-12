#include <iostream>
using std::cout;
using std::cin;

void countDiffDiv(int number);

int main() {
    int num;
    cout << "Wprowadź liczbę policzenia liczby" << "\n";
    cout << "jej różnych czynników pierwszych: "; cin >> num;
    countDiffDiv(num);

	return 0;
} 

void countDiffDiv(int number) {
    /* Najmniejszy możliwy dzielnik poza 1 */
    unsigned int divisor = 2;
    unsigned int lastDivisor;
    unsigned short diffDivCount = 0; 
    int numInit = number;

    /* Nie trzeba sprawdzać, czy dzielnik jest liczbą pierwszą, 
     * bo zawsze najmniejszy dzielnik będzie taką liczbą */
    while (divisor <= number) {
        /* Sprawdzanie, czy znaleziono dzielnik tej liczby */
        if (number % divisor == 0) {
            /* Jeżeli dzielnik nie jest taki sam jak poprzedni,
             * Zwiększenie wartości przechowującej liczbę różnych
             * czynników pierwszych */
            /* Zawsze takie same dzielniki będę występowały tuż po sobie,
             * bo algorytm wyszukuje je w kolejności rosnącej */
            if (divisor != lastDivisor)
                diffDivCount++;
            /* Zauktualizowanie poprzedniego dzielnika */
            lastDivisor = divisor;
            /* Przejście do szukania następnego dzielnika */
            number /= divisor;
        } else divisor++;
    }

    cout << "Liczba różnych dzielników: " << diffDivCount << "\n";
}
