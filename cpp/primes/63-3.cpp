#include <ios>
#include <iostream>
#include <fstream>
using std::cout;
using std::ifstream;
using std::ofstream;

bool IsPrime(unsigned int number);
bool IsHalfPrime(unsigned int number);
unsigned int BinToDec(unsigned long long bin);

int main() {
    unsigned long long currentBinNum;
    unsigned int currentHalfPrime, halfPrimeCount = 0, 
                 smallestHP = 4294967295, largestHP = 0;
    ifstream inputFile;
    ofstream outputFile;

    /* Otwarcie plików i obsługa błędów */
    inputFile.open("ciagi.txt");
    outputFile.open("63.txt", std::ios::app);
    if (!inputFile.good() || !outputFile.good()) {
        cout << "Couldn't open files." << "\n";
        return 1;
    }

    /* Iteracja przez cały plik */
    while (inputFile >> currentBinNum) {
        /* Pomijanie liczby, która nie jest półpierwsza */
        if (!IsHalfPrime(BinToDec(currentBinNum)))
            continue;

        /* Nadpisanie obecnej liczby półpierwszej i dodanie do licznika */
        currentHalfPrime = BinToDec(currentBinNum);
        halfPrimeCount++;

        /* Nadpisanie wartości największej i najmniejszej liczby półpierwszej */
        if (currentHalfPrime < smallestHP)
            smallestHP = currentHalfPrime;
        if (currentHalfPrime > largestHP)
            largestHP = currentHalfPrime;
    }

    outputFile << "[63.3]" << "\n";
    outputFile << "Liczba liczb półpierwszych:     " << halfPrimeCount << "\n";
    outputFile << "Najmniejsza liczba półpierwsza: " << smallestHP << "\n";
    outputFile << "Największa liczba półpierwsza:  " << largestHP << "\n";

    /* Dodanie przerwy między odpowiedziami */
    outputFile << "\n";

    inputFile.close();
    outputFile.close();
	return 0;
}

bool IsPrime(unsigned int number) {
    unsigned int divisor = 2;
    /* Najszybszy algorytm sprawdza do momentu, 
     * gdy sprawdzany dzielnik nie przkroczył pierwiastka z tej liczby, 
     * a więc gdy kwadrat tego dzielnika nie przekroczył podanej liczby */
    while (divisor * divisor <= number) {
        /* Jeżeli znajdziemy dzielnik ustawiamy IsPrime na false 
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

bool IsHalfPrime(unsigned int number) {
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
            if (!IsPrime(divisor))
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

unsigned int BinToDec(unsigned long long bin) {
	unsigned int dec = 0, currentBinPower = 0, currentDecNum = 1;

	while (bin > 0) {
		/* ustawianie początkowej wartości zmiennej przechowującej
		 * potęgę 2 używaną przy tej iteracji */ 
		currentDecNum = 1; 

		/* obliczanie odpowiedniej potęgi 2 */
		for (int i = currentBinPower; i > 0; i--)
			currentDecNum *= 2;

		/* obliczanie liczby w systemie dziesiętnym */
		dec += (bin % 10) * currentDecNum;

		/* przygotowanie zmiennych do następnej iteracji */ 
		bin /= 10;
		currentBinPower++;
	}

    return dec;
}
