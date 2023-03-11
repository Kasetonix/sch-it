#include <iostream>
using std::cout;
using std::cin;

bool isPrime(unsigned int number);

int main() {
    unsigned short counter = 0, limit;
    /* Zaczynamy od trzech, ponieważ jest to pierwsza liczba pierwsza
     * która może mieć liczbę pierwszą większą o dwa */
    unsigned int currentNum = 3;

    cout << "Wprowadź ile liczb bliźniaczych wypisać: "; cin >> limit;

    /* Iteracja przez nieparzyste liczby naturalne */
    while (counter < limit) {
        /* Sprawdzamy, czy obecna liczba i liczba o dwa od niej większa
         * są liczbami pierwszymi
         * W razie spełnienia warunku wypisanie tych liczb i 
         * zwiększenie liczby wypisanych liczb */
        if (isPrime(currentNum) && isPrime(currentNum + 2)) {
            cout << currentNum << " | " << currentNum + 2 << "\n";
            counter++;
        }

        /* Powiększanie o dwa gwarantuje nam 
         * sprawdzanie tylko liczb nieparzystych */
        currentNum += 2;
    }

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
        else divisor++;
    }

    /* Zwrócenie true gdy nie znaleziono, że liczba nie jest pierwszą */
    return true;
}
