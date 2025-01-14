#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <string>
using std::string;
using std::ifstream;
using std::ofstream;
using std::sort;
using std::cout;

struct Num {
    unsigned val;
    unsigned perm_diff;
};

// const unsigned LEN = 20;
// const string INFILE = "liczby_przyklad.txt";
const unsigned LEN = 2000;
const string INFILE = "liczby.txt";
const string OUTFILE = "wyniki3.txt";
const unsigned NUM_LEN = 4;
void GetData(Num num[]);
string utos(unsigned num);
unsigned stou(string num);
unsigned GetPermDiff(string num);
void ReturnData(Num num[]);

int main() {
    Num num[LEN];
    GetData(num);
    ReturnData(num);

    return 0;
}

// Funkcja otrzymująca dane z pliku
void GetData(Num num[]) {
    unsigned index;
    ifstream infile;
    infile.open(INFILE);

    for (index = 0; index < LEN; ++index) {
        infile >> num[index].val;
        // otrzymanie różnicy między permutacjami liczb
        num[index].perm_diff = GetPermDiff(utos(num[index].val));
    }

    infile.close();
}

// Funkcja zamieniająca liczbę unsigned -> string
string utos(unsigned num) {
    if (num == 0)
        return "0";

    string result = "";
    while (num > 0) {
        //       ostatnia cyfra jako char
        result = char((num % 10) + '0') + result;
        num /= 10;
    }

    return result;
}

// Funkcja zamieniająca liczbę string -> unsigned
unsigned stou(string num) {
    unsigned result = 0, index;
    for (index = 0; index < num.size(); ++index)
        //       ostatnia cyfra jako unsigned 
        result = unsigned(num[index] - '0') + result * 10;

    return result;
}

// Funkcja otrzymująca różnicę między permutacjami
unsigned GetPermDiff(string num) {
    unsigned diff, number = stou(num);
    int index = 0;
    const unsigned NUM_LEN = num.size();
    unsigned digits_asc[NUM_LEN];
    string max_perm, min_perm;

    // Wypełnienie tablicy cyframi
    for (index = NUM_LEN - 1; index >= 0; index--) {
        digits_asc[index] = number % 10;
        number /= 10;
    }

    // Przesortowanie tablicy z cyframi
    sort(digits_asc, digits_asc + NUM_LEN);

    for (index = 0; index < NUM_LEN; ++index) {
        min_perm.push_back(utos(digits_asc[index])[0]);
        max_perm.push_back(utos(digits_asc[NUM_LEN - index - 1])[0]);
    }

    return stou(max_perm) - stou(min_perm);
}

void ReturnData(Num num[]) {
    unsigned index, gt_counter = 0, lt_counter = 0, eq_counter = 0;
    ofstream outfile;
    outfile.open(OUTFILE, std::ios::app);

    outfile << "/// 3.3 ///" << "\n";

    for (index = 0; index < LEN; ++index) {
        if (num[index].perm_diff == num[index].val) {
            eq_counter++;
            outfile << num[index].val << "\n";
        }

        if (num[index].perm_diff > num[index].val)
            gt_counter++;
        if (num[index].perm_diff < num[index].val)
            lt_counter++;
    }

    cout << "Różnica jest większa od liczby:  " << gt_counter << "\n";
    cout << "Różnica jest mniejsza od liczby: " << lt_counter << "\n";
    cout << "Różnica jest równa liczbie:      " << eq_counter << "\n";
    outfile.close();
}
