#include <iostream>
#include <fstream>
using std::cout;
using std::ifstream;
using std::ofstream;
using std::string;

const string INFILE = "anomalie.txt";
const string OUTFILE = "wynik6_3.txt";
const unsigned LEN = 1000; // liczba rzędów
const unsigned NUM = 5; // liczba liczb w rzędzie

struct Coords {
    unsigned x;
    unsigned y;
};

void GetData(unsigned num[NUM][LEN]);
unsigned GetRoute(unsigned num[NUM][LEN], Coords route[NUM + LEN - 1]);
void ReturnData(unsigned num[NUM][LEN], Coords route[NUM + LEN - 1]);

int main() {
    unsigned num[NUM][LEN];
    Coords route[NUM + LEN - 1];
    GetData(num);
    ReturnData(num, route);

    return 0;
}

void GetData(unsigned num[NUM][LEN]) {
    unsigned x, y;
    ifstream infile;

    infile.open(INFILE);
    if (!infile.good()) {
        cout << "Plik wejściowy nie mógł być otwarty." << "\n";
        exit(1);
    }

    for (y = 0; y < LEN; y++)
        for (x = 0; x < NUM; x++)
            infile >> num[x][y];

    infile.close();
}

// Function returns the cost
unsigned GetRoute(unsigned num[NUM][LEN], Coords route[NUM + LEN - 1]) {
    Coords pos = { 0, LEN - 1 }; // pozycja startowa
    int index, cost = num[pos.x][pos.y];

    route[0] = pos;
    for (index = 1; index < NUM + LEN - 1; index++) {
        // Jedna możliwość jak jest na skraju
        if (pos.x == NUM - 1) {
            while (pos.y != 0) {
                pos.y--;
                route[index] = pos;
                cost += num[pos.x][pos.y];
                index++;
            }
            break;
        }
        
        if (pos.y == 0) {
            while (pos.x != NUM - 1) {
                pos.x++;
                route[index] = pos;
                cost += num[pos.x][pos.y];
                index++;
            }
            break;
        }

        //  ↑ vs  →
        if (num[pos.x][pos.y - 1] <= num[pos.x + 1][pos.y])
            pos.y--;
        else
            pos.x++;

        cost += num[pos.x][pos.y];
        route[index] = pos;
    }

    return cost;
}

void ReturnData(unsigned num[NUM][LEN], Coords route[NUM + LEN - 1]) {
    ofstream outfile;
    unsigned cost;

    outfile.open(OUTFILE);
    if (!outfile.good()) {
        cout << "Plik wyjściowy nie mógł być otwarty." << "\n";
        exit(1);
    }

    cost = GetRoute(num, route);
    outfile << cost << "\n";
    for (unsigned index = 0; index < NUM + LEN - 1; index++) {
        outfile << "{ " << route[index].x << "; " << route[index].y << " }" << "\n"; 
    }

    outfile.close();
}
