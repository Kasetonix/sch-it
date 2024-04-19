#include <algorithm>
#include <fstream>
#include <iostream>

using std::cout;
using std::cin;
using std::min;
using std::max;
using std::string;
using std::ofstream;

const float EPS = 0.000001;

struct point {
    float x;
    float y;
};

float Det(point A, point B, point P);
void GetPoint(point &Point, string question);
float AbsVal(float number);
bool IsPointOnSegment(point A, point B, point P);

int main() {
    point pointA, pointB, pointP;

    /* Plik wyjściowy */
    ofstream outfile;
    outfile.open("wynik.txt");
    if (!outfile.good()) {
        cout << "Plik wyjściowy nie mógł być otwarty." << "\n";
        return 1;
    }

    GetPoint(pointA, "Podaj współrzędne punktu A: ");
    GetPoint(pointB, "Podaj współrzędne punktu B: ");
    GetPoint(pointP, "Podaj współrzędne punktu P: ");

    if (IsPointOnSegment(pointA, pointB, pointP))
        outfile << "Punkt P leży na odcinku AB." << "\n";
    else
        outfile << "Punkt P nie leży na odcinku AB." << "\n";

    outfile.close();
    return 0;
}

/* Wyznacznik "macierzy" */
float Det(point A, point B, point P) {
    return (P.y - A.y) * (B.x - A.x) - (B.y - A.y) * (P.x - A.x);
}

bool IsPointOnSegment(point A, point B, point P) {
    if (AbsVal(Det(A, B, P)) > EPS)
        return false;

    return (P.x >= min(A.x, B.x) && P.x <= max(A.x, B.x) && 
            P.y >= min(A.y, B.y) && P.y <= max(A.y, B.y));
}

void GetPoint(point &Point, string question) {
    cout << question << "\n";
    cout << "    x = "; cin >> Point.x;
    cout << "    y = "; cin >> Point.y;
    cout << "\n";
}

float AbsVal(float number) {
    if (number < 0)
        return -number;
    return number;
}
