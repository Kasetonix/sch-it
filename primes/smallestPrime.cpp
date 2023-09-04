#include <iostream>
#include <fstream>
using std::cout;
using std::cin;
using std::ofstream;

bool isPrime(unsigned int num);

int main() {
    unsigned int num;
    bool isFound = false;
    ofstream outputFile;

    outputFile.open("smallestPrime_out.txt");
    if (!outputFile.good()) {
        cout << "Couldn't open output file.";
        return 1;
    }

    cout << "Podaj badaną liczbę: "; cin >> num;
    
    while (!isFound) {
        num++;
        if (isPrime(num)) {
            isFound = true;
            break;
        }
    }

    outputFile << "Najmniejsza liczba pierwsza większa od podanej liczby: " << num << "\n";

    outputFile.close();
    return 0;
}

bool isPrime(unsigned int num) {
    int divisor = 2;
    /* Najszybszy algorytm sprawdza do momentu, 
     * gdy sprawdzany dzielnik nie przkroczył pierwiastka z tej liczby, 
     * a więc gdy kwadrat tego dzielnika nie przekroczył podanej liczby */
    while (divisor * divisor <= num) {
        /* Jeżeli znajdziemy dzielnik wychodzimy z ustawiamy isPrime na false 
         * i wychodzimy z pętli
         * W przeciwnym wypadku przechodzimy do następnego dzielnika */
        if (num % divisor == 0)
            return false;
        else divisor++;
    }

    /* Zwrócenie true gdy nie znaleziono, że liczba nie jest pierwszą */
    return true;
}
