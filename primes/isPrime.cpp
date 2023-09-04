#include <iostream>
using std::cout;
using std::cin;

bool isPrime(unsigned int num);

int main() {
    int num;
    cout << "Podaj badaną liczbę: "; cin >> num;

    if (isPrime(num))   cout << "Podana liczba jest liczbą pierwszą." << "\n";
    else    cout << "Podana liczba nie jest liczbą pierwszą." << "\n";

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
