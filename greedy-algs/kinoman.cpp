#include <iostream>
#include <fstream>
#include <algorithm>
using std::cout;
using std::ifstream;
using std::sort;

const unsigned short REH_NUM = 10;

// Próba
struct reh {
    unsigned short beg; // początek
    unsigned short len; // koniec
};

void GetRehs(reh reh[], ifstream &infile);
bool comp(reh a, reh b);
unsigned short CalcMaxRehs(reh reh[]);

int main() {
    reh reh[REH_NUM];
    ifstream infile;
    
    GetRehs(reh, infile);
    sort(reh, reh + REH_NUM, comp);

    return 0;
}

void GetRehs(reh reh[], ifstream &infile) {
    unsigned short index = 0;

    infile.open("proby.txt");
    if (!infile.good())
        cout << "Plik nie mógł być otwarty." << "\n";

    while (infile >> reh[index].beg >> reh[index].len) {
        index++;
    }

    infile.close();
}

bool comp(reh a, reh b) {
    return (a.beg * 60 + a.len < b.beg * 60 + b.len); 
}

unsigned short CalcMaxRehs(reh reh[]) {
    unsigned short reh_num = 1, last_reh = 0, index;

    for (index = 1; index < REH_NUM; index++) {
        if (reh[index].beg * 60 >= reh[last_reh].beg * 60 + reh[last_reh].len) {
            reh_num++;
            last_reh = index;
        }
    }

    return reh_num;
}
