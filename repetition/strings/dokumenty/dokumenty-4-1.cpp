#include <iostream>
#include <fstream>
#include <string>
using std::string;
using std::cout;
using std::ifstream;
using std::ofstream;

const unsigned FILE_LEN = 200;
const string INFILE = "identyfikator.txt";
const string OUTFILE = "wyniki4_1.txt";

void GetData(string id[]);
unsigned GetNumSum(string id);
void ReturnData(string id[]);

int main() {
    string id[FILE_LEN];
    GetData(id);
    ReturnData(id);
    
    return 0;
}

void GetData(string id[]) {
    ifstream infile;
    unsigned index;

    infile.open(INFILE);
    if (!infile.good()) {
        cout << "Plik wejściowy nie mógł być otwarty." << "\n";
        exit(1);
    }

    for (index = 0; index < FILE_LEN; index++)
        infile >> id[index];

    infile.close();
}

unsigned GetNumSum(string id) {
    unsigned sum = 0, index;
    // Zakres, w którym są cyfry w identyfikatorze
    for (index = 3; index < 9; index++) {
        sum += unsigned(id[index] - '0');
    }

    return sum;
}

void ReturnData(string id[]) {
    ofstream outfile;
    unsigned index, num_sum, max_num_sum = 0;
    string max_num_id;

    outfile.open(OUTFILE);
    if (!outfile.good()) {
        cout << "Plik wyjściowy nie mógł być otwarty." << "\n";
        exit(1);
    }

    // Znajdywanie największej sumy
    for (index = 0; index < FILE_LEN; index++) {
        num_sum = GetNumSum(id[index]);

        if (num_sum > max_num_sum)
            max_num_sum = num_sum;
    }

    // Wypisywanie id o największej sumie
    outfile << "/// 4.1 ///" << "\n";
    for (index = 0; index < FILE_LEN; index++)
        if (GetNumSum(id[index]) == max_num_sum)
            outfile << id[index] << "\n";

    outfile.close();
}
