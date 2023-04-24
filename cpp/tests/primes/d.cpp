#include <iostream>
#include <fstream>
using std::cout;
using std::ifstream;
using std::ofstream;

void factorise(unsigned int number);

ifstream inputFile("cyfry.txt");
ofstream outputFile("wynik.txt", std::ios::app);

int main() {
    int currentNum;
    unsigned short primeNum = 0;

    if (!inputFile.good() || !outputFile.good()) {
        cout << "[ERR] couldn't open files" << "\n";
    }

    outputFile << "[ZADANIE D]" << "\n";

    while (inputFile >> currentNum) {
        factorise(currentNum);
    }

    inputFile.close();
    outputFile.close();
	return 0;
} 

void factorise(unsigned int number) {
    int divisor = 2;

    outputFile << number << " -> ";

    while (divisor * divisor <= number) {
        if (number % divisor == 0) {
            outputFile << divisor << " * ";
            number /= divisor;
        } else divisor++;
    }

    outputFile << number << "\n";
}
