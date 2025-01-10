#include <iostream>
#include <fstream>
using std::cout;
using std::string;
using std::ifstream;
using std::ofstream;
using std::getline;

const string 

int main() {
    ifstream infile;
    ofstream outfile;
    string text;
    string cipher = "LUBIMYCZYTAC";
    

    return 0;
}

void GetData(string words[]) {
    ifstream infile;
    unsigned index;

    infile.open(INPUT_FILE);
    if (!infile.good()) {
        cout << "Plik wejściowy nie mógł być otwarty." << "\n";
        exit(1);
    }

    for (index = 0; index < FL; ++index)
        infile >> words[index];

    infile.close();
}
