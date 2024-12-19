#include <iostream>
#include <fstream>
using std::cout;
using std::string;
using std::ifstream;
using std::ofstream;

const unsigned FL = 200;

bool Check(string str);

int main() {
    unsigned index;
    string pass;

    ifstream infile; ofstream outfile;
    infile.open("hasla.txt"); outfile.open("wynik4c.txt");
    if (!infile.good() || !outfile.good()) {
        cout << "Pliki nie mogły być otwarte." << "\n";
        exit(1);
    }

    outfile << "/// 4C ///" << "\n";
    for (index = 0; index < FL; ++index) {
        infile >> pass;
        if (Check(pass))
            outfile << pass << "\n";
    }

    infile.close();
    outfile.close();
    return 0;
}

bool Check(string str) {
    unsigned index;
    for (index = 1; index < str.size(); ++index) {
        if (str[index - 1] + str[index] == 220)
            return true;
    }
    return false;
}
