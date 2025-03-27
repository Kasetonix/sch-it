#include <iostream>
#include <fstream>
using std::cout;
using std::ifstream;
using std::ofstream;
using std::string;

const string INFILE = "anomalie.txt";
const string OUTFILE = "wynik6_1.txt";
const unsigned LEN = 1000; // liczba rzędów
const unsigned NUM = 5; // liczba liczb w rzędzie

bool IsIncreasing(unsigned num[NUM]);

int main() {
    unsigned num[NUM];
    unsigned index, tab_index, counter = 0;
    ifstream infile;
    ofstream outfile;

    infile.open(INFILE);
    if (!infile.good()) {
        cout << "Plik wejściowy nie mógł być otwarty." << "\n";
        exit(1);
    }

    outfile.open(OUTFILE);
    if (!outfile.good()) {
        cout << "Plik wyjściowy nie mógł być otwarty." << "\n";
        exit(1);
    }

    // Iteracja przez wszystkie rzędy tablicy
    for (index = 0; index < LEN; index++) {
        // Tworzenie tablicy z rzędem
        for (tab_index = 0; tab_index < NUM; tab_index++)
            infile >> num[tab_index];
        
        // Sprawdzanie monotoniczności ciągu
        if (IsIncreasing(num))
            counter++;
    }

    outfile << "Liczba wierszy z ciągami posortowanymi niemalejąco: " << counter << "\n";

    infile.close();
    outfile.close();

    return 0;
}

void GetData(unsigned num[LEN][NUM]) {
    unsigned x, y;
    ifstream infile;

    infile.open(INFILE);
    if (!infile.good()) {
        cout << "Plik wejściowy nie mógł być otwarty." << "\n";
        exit(1);
    }

    for (y = 0; y < LEN; y++)
        for (x = 0; x < NUM; x++)
            infile >> num[y][x];

    infile.close();
}

bool IsIncreasing(unsigned num[NUM]) {
    unsigned index;
    for (index = 1; index < NUM; index++)
        if (num[index - 1] > num[index])
            return false;
    return true;
}

void ReturnData(unsigned num[NUM][LEN]) {
    unsigned index, counter = 0, row[NUM];
    ofstream outfile;

    outfile.open(OUTFILE);
    if (!outfile.good()) {
        cout << "Plik wyjściowy nie mógł być otwarty." << "\n";
        exit(1);
    }



    for (index = 0; index < LEN; index++) 
        if (IsIncreasing(num[LEN]))
            counter++;

    cout << "Liczba wierszy z ciągami posortowanymi niemalejąco: " << counter << "\n";

    outfile.close();
}
