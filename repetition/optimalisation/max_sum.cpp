#include <iostream>
#include <fstream>
using std::cout;
using std::ifstream;
using std::ofstream;
using std::string;

const unsigned W = 5;
const unsigned H = 5;
const string INFILE = "msk.txt";

void InitTable(unsigned table[W+1][H+1]);
void GetTable(unsigned table[W+1][H+1]);
void Print(unsigned table[W+1][H+1]);
unsigned MaxSum(unsigned table[W+1][H+1]);

int main() {
    unsigned table[W+1][H+1];
    GetTable(table);
    Print(table);
    cout << "SUMA: " << MaxSum(table) << "\n";

    return 0;
}

void InitTable(unsigned table[W+1][H+1]) {
    unsigned x, y;
    for (x = 0; x <= W; x++)
        for (y = 0; y <= H; y++)
            table[x][y] = 0;
}

void GetTable(unsigned table[W+1][H+1]) {
    ifstream infile;
    unsigned x, y;

    infile.open(INFILE);
    if (!infile.good()) {
        cout << "Plik wejściowy nie mógł być otwarty." << "\n";
        exit(1);
    }

    InitTable(table);

    for (y = 0; y < H; y++)
        for (x = 0; x < W; x++)
            infile >> table[x][y];

    infile.close();
}

void Print(unsigned table[W+1][H+1]) {
    unsigned x, y;
    for (y = 0; y < H; y++) {
        for (x = 0; x < W; x++) {
            cout << table[x][y] << " ";
        }
        cout << "\n";
    }
}

unsigned MaxSum(unsigned table[W+1][H+1]) {
    unsigned x = 0, y = 0;
    unsigned sum = table[x][y];

    while (x != W && y != H) {
        if (table[x+1][y] >= table[x][y+1]) x++;
        else y++;

        sum += table[x][y];
    }

    return sum;
}
