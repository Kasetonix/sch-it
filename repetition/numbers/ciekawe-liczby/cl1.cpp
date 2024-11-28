#include <iostream>
#include <fstream>
using std::cout;
using std::ifstream;
using std::ofstream;

const unsigned FILE_LEN = 1000;
void GetArray(unsigned num[]);
bool HasThreeOddFactors(unsigned num);
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

bool HasThreeOddFactors(unsigned num) {
    unsigned counter = 0, factor = 3;
    if (num % 2 == 0)
        return false;

    while (num >= factor) {
        if (num % factor != 0) {
            factor += 2;
            continue;
        }

        while (num % factor == 0) {
            num /= factor;
        }

        counter++;
        factor += 2;
        if (counter > 3)
            return false;
    }

    if (counter == 3)
        return true;
    return false;

    // unsigned counter = 0;
    // unsigned factor = 3;
    // if (num % 2 == 0)
    //     return false;
    //
    // while (factor * factor <= num) {
    //     if (num % factor == 0) {
    //         while (num % factor == 0)
    //             num /= factor;
    //         counter++;
    //     }
    //     factor += 2;
    //     if (factor > 3)
    //         return false;
    // }
    // if (num != 1)
    //     counter++;
    //
    // if (counter == 3)
    //     return true;
    // return false;

}

void ReturnAnswer(unsigned num[]) {
    ofstream outfile;
    unsigned index, counter = 0;
    outfile.open("wyniki_liczby.txt", std::ios::app);
    if (!outfile.good()) {
        cout << "Plik wyjściowy nie mógł być otwarty." << "\n";
        exit(1);
    }
    
    for (index = 0; index < FILE_LEN; index++)
        if (HasThreeOddFactors(num[index]))
            counter++;
    outfile << "1: " << counter << "\n";
}
