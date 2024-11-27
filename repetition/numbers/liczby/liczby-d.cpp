#include <iostream>
#include <fstream>
using std::cout;
using std::ifstream;
using std::ofstream;

const unsigned FILE_LEN = 1000;
void GetNums(unsigned nums[]);
void ReturnFactorisation(unsigned nums[]);

int main() {
    unsigned nums[FILE_LEN];
    GetNums(nums);
    ReturnFactorisation(nums);

    return 0;
}

// Funkcja pobierająca liczby z pliku
void GetNums(unsigned nums[]) {
    unsigned index;
    ifstream infile;
    infile.open("liczby.txt");
    if (!infile.good()) {
        cout << "Plik nie mógł być otwarty." << "\n";
        exit(1);
    }

    for (index = 0; index < FILE_LEN; index++)
        infile >> nums[index];

    infile.close();
}

// Funkcja zwracająca do pliku rozkład liczb na czynniki pierwsze
void ReturnFactorisation(unsigned nums[]) {
    ofstream outfile;
    outfile.open("czynniki.txt");
    if (!outfile.good()) {
        cout << "Plik nie mógł być otwarty." << "\n";
        exit(1);
    }

    unsigned factor, index;
    for (index = 0; index < FILE_LEN; index++) {
        factor = 2;
        outfile << nums[index] << " -> "; 
        // Rozkład na czynniki pierwsze
        while (factor < nums[index]) {
            // Pomijanie liczb nie będących czynnikami
            if (nums[index] % factor != 0) {
                factor++;
                continue;
            }
            outfile << factor << " * ";
            nums[index] /= factor;
        }
        outfile << nums[index] << "\n";
    }


    outfile.close();
}
