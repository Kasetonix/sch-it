#include <iostream>
#include <fstream>

using std::ofstream;
using std::ifstream;
using std::cout;

struct point {
    unsigned int x;
    unsigned int y;
};

/* Sprawdza relację punktu i koła:
 * - code = 'i' => należy do koła 
 * - code = 'o' => należy do okręgu 
 * - code = 'I' => należy do koła z wył. okręgu */
bool PointCircleRel(point point, char code);

int main() {
    const unsigned short POINT_NUM = 10000;
    point points[POINT_NUM]; 
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
        infile >> points[index].x >> points[index].y;
    }
    infile.close();

    /* Iteracja przez wszystkie punkty w tablicy i
     * zliczanie liczby tych, które należą do okręgu i koła */
    for (index = 0; index < 10000; index++) {
        if (PointCircleRel(points[index], 'I'))
            countInside++;
        if (PointCircleRel(points[index], 'o'))
            countOn++;
    }

    outfile << "/// 4.1 ///" << "\n";
    outfile << "Liczba punktów w okręgu:  " << countInside << "\n";
    outfile << "Liczba punktów na okręgu: " << countOn << "\n\n";
    outfile.close();

    return 0;
}

/* Sprawdza relację punktu i koła:
 * - code = 'i' => należy do koła 
 * - code = 'o' => należy do okręgu 
 * - code = 'I' => należy do koła z wył. okręgu */
bool PointCircleRel(point point, char code) {
    struct point center = {200, 200};
    unsigned int radius = 200;

    /* Równanie okręgu: (x-a)² + (y-b)² = r² */

    /* Switch sprawdzający różne warianty relacji punktu i koła */
    switch (code) {
        case 'i':
            return ((point.x - center.x)*(point.x - center.x) +
                    (point.y - center.y)*(point.y - center.y) <= radius*radius);
        case 'o':
            return ((point.x - center.x)*(point.x - center.x) +
                    (point.y - center.y)*(point.y - center.y) == radius*radius);
        case 'I':
            return ((point.x - center.x)*(point.x - center.x) +
                    (point.y - center.y)*(point.y - center.y) <  radius*radius);
        default:
            return false;
    }
}
