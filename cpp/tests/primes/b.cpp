#include <iostream>
#include <fstream>
using std::cout;
using std::cin;
using std::ifstream;
using std::ofstream;

bool isPrime(unsigned int num);

int main() {
    ifstream inputFile;
    ofstream outputFile;
    int currentNum;
    unsigned short primeNum = 0;

    inputFile.open("cyfry.txt");
    outputFile.open("wynik.txt", std::ios::app);

    if (!inputFile.good() || !outputFile.good()) {
        cout << "[ERR] couldn't open files" << "\n";
    }

    outputFile << "[ZADANIE B]" << "\n";

    while (inputFile >> currentNum) {
        if (isPrime(currentNum)) {
            outputFile << currentNum << "\n";
            primeNum++;
        }
    }

    outputFile << "[LICZBA LICZB PIERWSZYCH]: " << primeNum << "\n";

    outputFile << "\n \n \n";

    inputFile.close();
    outputFile.close();
	return 0;
}

bool isPrime(unsigned int num) {
    int divisor = 2;
    while (divisor * divisor <= num) {
        if (num % divisor == 0)
            return false;
        else divisor++;
    }

    return true;
}
