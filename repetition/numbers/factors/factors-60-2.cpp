#include <iostream>
#include <fstream>
#include <vector>
using std::cout;
using std::vector;
using std::ifstream;
using std::ofstream;

struct Num {
    unsigned value;
    vector<unsigned> factor;
    unsigned fn; // Liczba dzielników
};

const unsigned FILE_LEN = 200;
void GetNums(Num num[]);
Num GetFactors(Num num);
void ReturnAnswer(Num num[]);

int main() {
    unsigned index;
    Num num[FILE_LEN];
    GetNums(num);

    // Uzupełnienie structa
    for (index = 0; index < FILE_LEN; index++)
        num[index] = GetFactors(num[index]);

    ReturnAnswer(num);

    return 0;
}

// Funkcja otrzymująca dane z pliku
void GetNums(Num num[]) {
    unsigned index;
    ifstream infile;
    infile.open("liczby.txt");
    if (!infile.good()) {
        cout << "Plik wejściowy nie mógł być otwarty." << "\n";
        exit(1);
    }

    for (index = 0; index < FILE_LEN; index++) {
        infile >> num[index].value;
    }

    infile.close();
}

// Funkcja wykonująca faktoryzację
Num GetFactors(Num num) {
    unsigned factor;
    for (factor = 1; factor <= num.value; factor++)
        if (num.value % factor == 0)
            num.factor.push_back(factor);

    // Ostatnim dzielnikiem jest dana liczba
    num.fn = num.factor.size();
    num.factor[num.fn] = num.value;

    return num;
}

// Funkcja wypisująca odpowiedź do pliku
void ReturnAnswer(Num num[]) {
    unsigned index, f_index;
    ofstream outfile;
    outfile.open("wyniki.txt", std::ios::app);
    if (!outfile.good()) {
        cout << "Plik wyjściowy nie mógł być otwarty." << "\n";
    }

    outfile << "/// 60.2 ///" << "\n";
    for (index = 0; index < FILE_LEN; index++) {
        if (num[index].fn != 18)
            continue;

        outfile << "    " << num[index].value << " ==> D = {";
        for (f_index = 0; f_index < num[index].fn - 1; f_index++)
            outfile << num[index].factor[f_index] << "; ";
        outfile << num[index].factor[num[index].fn] << "}" << "\n";
    }
    outfile << "\n";

    outfile.close();
}
