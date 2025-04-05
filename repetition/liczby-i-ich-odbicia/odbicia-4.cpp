#include <iostream>
#include <fstream>
#include <vector>
using std::cout;
using std::string;
using std::ifstream;
using std::ofstream;
using std::vector;

const string INFILE = "liczby.txt";
const unsigned LEN = 100;
const string OUTFILE = "wyniki4.txt";

struct Number {
    unsigned val;
    unsigned repeats; 
};

void GetNums(vector<unsigned> &num);
void GetRepeats(vector<unsigned> num, unsigned rep[3]);
void Return(vector<unsigned> num);

int main() {
    vector<unsigned> num;
    GetNums(num);
    Return(num);

    return 0;
}

void GetNums(vector<unsigned> &num) {
    unsigned index;
    ifstream infile;
    infile.open(INFILE);
    if (!infile.good()) {
        cout << "Plik wejściowy nie mógł być otwarty." << "\n";
        exit(1);
    }

    num.resize(LEN);
    for (index = 0; index < LEN; index++)
        infile >> num[index];



    infile.close();
}

void GetRepeats(vector<unsigned> num, unsigned rep[3]) {
    unsigned index, searched_num, repeats;
    while (num.size() > 0) {
        // resetowanie zmiennych
        searched_num = num[0];
        repeats = 0;
        index = 0;

        // iteracja po całym vectorze
        while (index < num.size()) {
            // usuwanie każdej liczby która się powtarza i 
            // zwiększenie licznika powtórzeń
            // inkrementacja indexu tylko gdy liczba nie jest usunięta,
            // gdy liczba jest usuwana indeks każdej kolejnej przesuwa się
            // o jeden w lewo
            if (num[index] == searched_num) {
                num.erase(num.begin() + index);
                repeats++;
            } else index++;

            // Maksymalnie trzy powtórzenia
            if (repeats == 3)
                break;
        }
        // Zapisanie liczby powtórzeń
        rep[repeats - 1]++;
    }

    // Uwzględnianie powtarzających się w liczniku unikalnych
    rep[0] += rep[1] + rep[2];
}

void Return(vector<unsigned> num) {
    unsigned index; 
    unsigned rep[3] = {0};
    ofstream outfile;
    outfile.open(OUTFILE, std::ios::app);
    if (!outfile.good()) {
        cout << "Plik wyjściowy nie mógł być otwarty." << "\n";
        exit(1);
    }

    GetRepeats(num, rep);
    outfile << "\n" << "/// 4.4 ///" << "\n";
    outfile << "Różne:                      " << rep[0] << "\n";
    outfile << "Powtarzające się dwa razy:  " << rep[1] << "\n";
    outfile << "Powtarzające się trzy razy: " << rep[2] << "\n";


    outfile.close();
}
