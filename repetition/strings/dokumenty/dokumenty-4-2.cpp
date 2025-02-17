#include <iostream>
#include <fstream>
#include <string>
using std::string;
using std::cout;
using std::ifstream;
using std::ofstream;

const unsigned FILE_LEN = 200;
const string INFILE = "identyfikator.txt";
const string OUTFILE = "wyniki4_2.txt";

void GetData(string id[]);
bool IsPalindrome(string str);
string GetSeries(string id);
string GetNum(string id);
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

bool IsPalindrome(string str) {
    unsigned index;
    for (index = 0; index <= str.size() / 2; index++)
        if (str[index] != str[str.size() - 1 - index])
            return false;
    return true;
}

string GetSeries(string id) { return id.substr(0, 3); }
string GetNum(string id)    { return id.substr(3, 8); }

void ReturnData(string id[]) {
    ofstream outfile;
    unsigned index, num_sum, max_num_sum = 0;
    string max_num_id;

    outfile.open(OUTFILE);
    if (!outfile.good()) {
        cout << "Plik wyjściowy nie mógł być otwarty." << "\n";
        exit(1);
    }

    outfile << "/// 4.2 ///" << "\n";
    for (index = 0; index < FILE_LEN; index++)
        if (IsPalindrome(GetSeries(id[index])) || IsPalindrome(GetNum(id[index])))
            outfile << id[index] << "\n";

    outfile.close();
}
