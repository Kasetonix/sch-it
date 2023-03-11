#include <iostream>
using std::cout;
using std::cin;

void factorise(int number);

int main() {
    int num;
    cout << "Wprowadź liczbę do faktoryzacji: "; cin >> num;
    cout << num << " = ";

    factorise(num);

	return 0;
} 

void factorise(int number) {
    /* Najmniejszy możliwy dzielnik poza 1 */
    int divisor = 2;
    int numInit = number;

    /* Nie trzeba sprawdzać, czy dzielnik jest liczbą pierwszą, 
     * bo zawsze najmniejszy dzielnik będzie taką liczbą 
     * Zastosowanie szybszego algorytmu zatrzymującego pętlę 
     * w momencie dojścia do połowy listy dzielników */
    while (divisor * divisor <= number) {
        /* Jeżeli dzielnik zostanie znaleziony, wypisanie go oraz
         * podzielenie przez niego liczby */
        if (number % divisor == 0) {
            cout << divisor << " * ";
            number /= divisor;
        } else divisor++;
    }

    /* Wypisanie liczby pozostałej po dzieleniach */
    cout << number << "\n";
}
