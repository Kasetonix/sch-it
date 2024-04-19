#include <iostream>
#include <fstream>

using std::ofstream;
using std::ifstream;
using std::cout;

struct point {
    unsigned int x;
    unsigned int y;
};

bool IsPointOnCircle(point point); 
bool IsPointInsideCircle(point point);

int main() {
    const unsigned short POINT_NUM = 10000;
    point point[POINT_NUM]; 
    unsigned short index, countOn = 0, countInside = 0;

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

    /* Iteracja przez wszystkie punkty w tablicy i
     * zliczanie liczby tych, które należą do okręgu i koła */
    for (index = 0; index < 10000; index++) {
        if (IsPointInsideCircle(point[index]))
            countInside++;
        if (IsPointOnCircle(point[index]))
            countOn++;
    }

    outfile << "4.1:" << "\n";
    outfile << "Liczba punktów w okręgu:  " << countInside << "\n";
    outfile << "Liczba punktów na okręgu: " << countOn << "\n\n";
    outfile.close();

    return 0;
}

bool IsPointOnCircle(point point) {
    return (point.x - 200)*(point.x - 200) + (point.y - 200)*(point.y - 200) == 200*200;
}  

bool IsPointInsideCircle(point point) {
    return (point.x - 200)*(point.x - 200) + (point.y - 200)*(point.y - 200) < 200*200;
}  
