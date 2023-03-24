#include <iostream>
#include <fstream>
using std::cout;
using std::cin;
using std::ofstream;

bool isPrime(unsigned int number);
bool isHalfPrime(unsigned int number);

int main() {
    unsigned int num;
    ofstream outputFile;

    outputFile.open("isHalfPrime_out.txt");
    if (!outputFile.good()) {
        cout << "Couldn't open output file." << "\n";
        return 1;
    }

    cout << "Wprowadź liczbę do sprawdzenia: "; cin >> num;

    if (isHalfPrime(num))
        outputFile << "Liczba " << num << " jest liczbą półpierwszą." << "\n";
    else
        outputFile << "Liczba " << num << " nie jest liczbą półpierwszą. " << "\n";

    outputFile.close();
	return 0;
}

bool isPrime(unsigned int number) {
    unsigned int divisor = 2;
    /* Najszybszy algorytm sprawdza do momentu, 
     * gdy sprawdzany dzielnik nie przkroczył pierwiastka z tej liczby, 
     * a więc gdy kwadrat tego dzielnika nie przekroczył podanej liczby */
    while (divisor * divisor <= number) {
        /* Jeżeli znajdziemy dzielnik wychodzimy z ustawiamy isPrime na false 
         * i wychodzimy z pętli
         * W przeciwnym wypadku przechodzimy do następnego dzielnika */
        if (number % divisor == 0)
            return false;
        else 
            divisor++;
    }

    /* Zwrócenie true gdy nie znaleziono, że liczba nie jest pierwszą */
    return true;
}

bool isHalfPrime(unsigned int number) {
    /* Najmniejszy możliwy dzielnik poza 1 */
    unsigned int divisor = 2;
    unsigned int primeDivNum = 0;

    /* Nie trzeba sprawdzać, czy dzielnik jest liczbą pierwszą, 
     * bo zawsze najmniejszy dzielnik będzie taką liczbą 
     * Zastosowanie szybszego algorytmu zatrzymującego pętlę 
     * w momencie dojścia do połowy listy dzielników */
    while (divisor <= number) {
        if (number % divisor == 0) {
            /* Jeżeli znaleziony dzielnik nie jest liczbą pierwszą
             * zwrócenie, że liczba nie jest liczbą półpierwszą
             * Jeżeli jest liczbą pierwszą, dodanie do licznika dzielników */
            if (!isPrime(divisor))
                return false;
            else 
                primeDivNum++;

            /* Jeżeli dzielnikow jest więcej niż dwa, zwrócenie że
             * liczba nie jest liczbą półpierwszą */
            if (primeDivNum > 2) 
                return false;

            /* Podzielenie liczby przez znaleziony dzielnik */
            number /= divisor;
            
        } else divisor++;
    }

    /* Zwrócenie false, jeżeli pozostała liczba nie jest jedynką lub
     * jeżeli nie znaleziono dokładnie dwóch dzielników */
    if (number != 1 || primeDivNum != 2)
        return false;

    /* Jeżeli wszystkie konieczne warunki są spełnione, zwrócenie że
     * liczba jest liczbą półpierwszą */
    return true;
}
