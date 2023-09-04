#include <iostream>
#include <fstream>
using std::cout;
using std::cin;
using std::ios;
using std::ofstream;
using std::string;

unsigned int countDiffDiv(int number);

int main() {
    int num;
    ofstream outputFile;

    outputFile.open("diffDivNum_out.txt");
    if (!outputFile.good()) {
        cout << "Couldn't open output file." << "\n";
        return 1;
    }

    cout << "Wprowadź liczbę do policzenia liczby" << "\n";
    cout << "jej różnych czynników pierwszych: "; cin >> num;
    
    outputFile << "Liczba czynników pierwszych podanej liczby: " << countDiffDiv(num);

    outputFile.close();
	return 0;
} 

unsigned int countDiffDiv(int number) {
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

    return diffDivCount;
}
