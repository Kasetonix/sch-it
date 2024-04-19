#include <iostream>
#include <fstream>

using std::ofstream;
using std::ifstream;
using std::cout;

struct point {
    unsigned int x;
    unsigned int y;
};

const float EPS = 0.0001;

bool IsPointInsideCircle(point point);

int main() {
    const unsigned short POINT_NUM = 10000;
    point point[POINT_NUM]; 
    unsigned short index, countIn = 0, countIn1000 = 0, countIn5000 = 0;
    float pi, pi1000, pi5000, square_area;

    /* Pliki wejścia/wyjścia */
    ifstream infile;
    ofstream outfile;
    infile.open("punkty.txt");
    outfile.open("wynik.txt", std::ios::app);
    
    if (!infile.good() || !outfile.good()) {
        cout << "Pliki nie mogły być otwarte." << "\n";
        return 1;
    }
    
    /* Importowanie współrzędnuch punktów z pliku */
    for (index = 0; index < POINT_NUM; index++) {
        infile >> point[index].x >> point[index].y;
    }
    infile.close();

    /* Pk / P = nk / n */
    /* pi * r*r / P = nk / n */
    /* pi = (nk * P) / (r*r * n) */
    square_area = 400*400;

    for (index = 0; index < 1000; index++) {
        if (IsPointInsideCircle(point[index]))
            countIn1000++;
    }

    for (index = 0; index < 5000; index++) {
        if (IsPointInsideCircle(point[index]))
            countIn5000++;
    }

    for (index = 0; index < POINT_NUM; index++) {
        if (IsPointInsideCircle(point[index]))
            countIn++;
    }

    pi1000 = (1000.0 * square_area) / (200.0 * 200.0 * countIn1000);
    pi5000 = (5000.0 * square_area) / (200.0 * 200.0 * countIn5000);
    pi = (10000.0 * square_area) / (200.0 * 200.0 * countIn);

    outfile << "4.2:" << "\n";
    outfile << "π ≈ " << pi << "\n";
    outfile.close();
    return 0;
}

bool IsPointInsideCircle(point point) {
    return (point.x - 200)*(point.x - 200) + (point.y - 200)*(point.y - 200) <= 200*200;
}  
