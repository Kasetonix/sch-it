#include <iostream>
#include <fstream>
#include <cmath>

using std::cout;
using std::ifstream;
using std::ofstream;
using std::ios;
using std::string;

struct point {
    unsigned short x;
    unsigned short y;
};

const unsigned short POINT_NUM = 10000;

/* Sprawdza relację punktu i koła:
 * - code = 'i' => należy do koła 
 * - code = 'o' => należy do okręgu 
 * - code = 'I' => należy do koła z wył. okręgu */
bool PointCircleRel(point point, char code);
/* Zwraca szacowaną liczbę pi biorąc pod uwagę punkty zawarte w kole i w kwadracie */
float GetPiFromPoints(point points[POINT_NUM], unsigned short checked_points);
/* Zwraca błąd bezwzględny obliczonego pi */
float GetError(float pi);
/* Zwraca wartość bezwzględną podanej liczby */
float AbsVal(float number);

int main() {
    unsigned short index, point_count = 0;
    unsigned int square_area = 400 * 400, circle_radius = 200;
    point points[POINT_NUM];
    float circle_area;

    /* Pliki wejścia/wyjścia */
    ifstream infile;
    ofstream outfile, error_list;
    infile.open("punkty.txt");
    outfile.open("wynik.txt", ios::app);
    error_list.open("error_list.txt");
    if (!infile.good() || !outfile.good() || !error_list.good()) {
        cout << "Pliki nie mogły być otwarte" << "\n";
        return 1;
    }

    /* Wprowadzanie danych z pliku do tablicy */
    for (index = 0; index < POINT_NUM; index++)
        infile >> points[index].x >> points[index].y;
    infile.close();

    outfile << "/// 4.3 ///" << "\n";
    outfile << "EPS_1000 = " << GetError(GetPiFromPoints(points, 1000)) << "\n";
    outfile << "EPS_1700 = " << GetError(GetPiFromPoints(points, 1700)) << "\n";

    /* Zapisywanie kolejnych wartości błędu bezwzględnego obliczonego pi */
    for (index = 1; index <= 1700; index++)
        error_list << GetError(GetPiFromPoints(points, index)) << "\n"; 

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

float GetPiFromPoints(point points[POINT_NUM], unsigned short checked_points) {
    unsigned short index, point_count;
    unsigned int square_area = 400*400, circle_radius = 200;
    float circle_area, pi;

    /* Sprawdzanie ile punktów ze sprawdzanych zawiera się w kole */
    for (index = 0; index < checked_points; index++)
        if (PointCircleRel(points[index], 'i'))
            point_count++;

    /* Szacowanie pola koła na podstawie liczby punktów w kole i w kwadracie */
    circle_area = float(point_count) * (float(square_area) / float(checked_points));

    /* P = pi*r*r => pi = P/(r*r) */
    pi = circle_area / (circle_radius * circle_radius);

    return pi;
}

float GetError(float pi) {
    return AbsVal(M_PI - pi); 
}

float AbsVal(float number) {
    if (number < 0)
        return -number;
    return number;
}
