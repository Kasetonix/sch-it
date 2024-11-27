#include <iostream>
#include <fstream>
using std::cout;
using std::ifstream;
using std::ofstream;

const unsigned FILE_LEN = 1000;
void GetNums(unsigned nums[]);
void ReturnEven(unsigned nums[]);
void ReturnOdd(unsigned nums[]);

int main() {
    unsigned nums[FILE_LEN];
    GetNums(nums);
    ReturnEven(nums);
    ReturnOdd(nums);

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

// Funkcja zwracająca do pliku wyjściowego liczby parzyste
void ReturnEven(unsigned nums[]) {
    unsigned index, counter = 0;
    ofstream outfile;
    outfile.open("parzyste.txt");
    if (!outfile.good()) {
        cout << "Plik nie mógł być otwarty." << "\n";
        exit(1);
    }

    for (index = 0; index < FILE_LEN; index++)
        if (nums[index] % 2 == 0) {
            outfile << nums[index] << "\n"; 
            counter++;
        }

    outfile << "Liczba liczb parzystych: " << counter << "\n";
    outfile.close();
}

// Funkcja zwracająca do pliku wyjściowego liczby nieparzyste
void ReturnOdd(unsigned nums[]) {
    unsigned index, counter = 0;
    ofstream outfile;
    outfile.open("nparzyste.txt");
    if (!outfile.good()) {
        cout << "Plik nie mógł być otwarty." << "\n";
        exit(1);
    }

    for (index = 0; index < FILE_LEN; index++)
        if (nums[index] % 2 != 0) {
            outfile << nums[index] << "\n"; 
            counter++;
        }

    outfile << "Liczba liczb nieparzystych: " << counter << "\n";
    outfile.close();
}
