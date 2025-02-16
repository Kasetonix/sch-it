#include <iostream>
#include <fstream>

using std::cout;
using std::string;
using std::ifstream;
using std::ofstream;

const unsigned LEN = 805;
const string INFILE = "tekst.txt";
const string OUTFILE = "wyniki.txt";

void GetData(string str[]);
void ReturnData(string str[]);

int main() {
    string str[LEN];
    GetData(str);
    ReturnData(str);

    return 0;
}

void GetData(string str[]) {
    unsigned index;
    ifstream infile;

    infile.open(INFILE);
    if (!infile.good()) {
        cout << "Plik wejściowy nie mógł być otwarty." << "\n";
        exit(1);
    }

    for (index = 0; index < LEN; index++)
        infile >> str[index];

    infile.close();
}

void ReturnData(string str[]) {
    unsigned index;
    ofstream outfile;

    outfile.open(OUTFILE, std::ios::app);
    if (!outfile.good()) {
        cout << "Plik wyjściowy nie mógł być otwarty." << "\n";
        exit(1);
    }

    outfile << "/// 75.1 ///" << "\n";
    for (index = 0; index < LEN; index++)
        if (str[index][0] == 'd' && str[index][str[index].size() - 1] == 'd')
            outfile << str[index] << "\n";

    outfile.close();
}
