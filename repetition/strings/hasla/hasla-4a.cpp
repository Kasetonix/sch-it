#include <iostream>
#include <fstream>
using std::cout;
using std::string;
using std::ifstream;
using std::ofstream;

const unsigned FL = 200;

int main() {
    unsigned index, counter = 0;
    string pass;

    ifstream infile; ofstream outfile;
    infile.open("hasla.txt"); outfile.open("wynik4a.txt");
    if (!infile.good() || !outfile.good()) {
        cout << "Pliki nie mogły być otwarte." << "\n";
        exit(1);
    }

    for (index = 0; index < FL; ++index) {
        infile >> pass;
        if (pass.size() % 2 == 0)
            counter++;
    }

    outfile << "/// 4A ///" << "\n";
    outfile << "Liczba haseł o parzystej liczbie znaków:    " << counter << "\n";
    outfile << "Liczba haseł o nieparzystej liczbie znaków: " << FL - counter << "\n";

    infile.close();
    outfile.close();
    return 0;
}
