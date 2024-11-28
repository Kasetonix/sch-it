#include <cmath>
#include <iostream>
#include <fstream>
using std::cout;
using std::ifstream;
using std::ofstream;

const unsigned FILE_LEN = 1000;
void GetArray(unsigned num[]);
unsigned Reverse(unsigned num);
void ReturnAnswer(unsigned num[]);

int main() {
    unsigned num[FILE_LEN];
    GetArray(num);
    ReturnAnswer(num);

    return 0;
}

// Funkcja otrzymująca liczby z pliku
void GetArray(unsigned num[]) {
    unsigned index;
    ifstream infile;
    infile.open("liczby.txt");
    if (!infile.good()) {
        cout << "Plik wejściowy nie mógł by otwarty." << "\n";
        exit(1);
    }

    for (index = 0; index < FILE_LEN; index++)
        infile >> num[index];
}

unsigned Reverse(unsigned num) {
    unsigned palnum = 0;
    while (num > 0) {
        palnum = 10 * palnum + (num % 10);
        num /= 10;
    }

    return palnum;
}

void ReturnAnswer(unsigned num[]) {
    ofstream outfile;
    unsigned index, counter = 0, sum;
    outfile.open("wyniki_liczby.txt", std::ios::app);
    if (!outfile.good()) {
        cout << "Plik wyjściowy nie mógł być otwarty." << "\n";
        exit(1);
    }

    for (index = 0; index < FILE_LEN; index++) {
        sum = num[index] + Reverse(num[index]);
        if (sum == Reverse(sum))
            counter++;
    }

    outfile << "2: " << counter << "\n";
    
    outfile.close();
}
