#include <iostream>
#include <fstream>
using std::cout;
using std::string;
using std::ifstream;
using std::ofstream;

const unsigned FL = 200;

bool IsPalindrome(string str);

int main() {
    unsigned index;
    string pass;

    ifstream infile; ofstream outfile;
    infile.open("hasla.txt"); outfile.open("wynik4b.txt");
    if (!infile.good() || !outfile.good()) {
        cout << "Pliki nie mogły być otwarte." << "\n";
        exit(1);
    }


    outfile << "/// 4B ///" << "\n";
    for (index = 0; index < FL; ++index) {
        infile >> pass;
        if (IsPalindrome(pass))
            outfile << pass << "\n";
    }

    infile.close();
    outfile.close();
    return 0;
}

bool IsPalindrome(string str) {
    unsigned short a, b;
    a = 0; b = str.size() - 1;

    while (a < b) {
        if (str[a] != str[b])
            return false;
        a++;
        b--;
    }

    return true;
}
