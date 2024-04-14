#include <iostream>

using std::string;
using std::cout;
using std::cin;

struct point { float x; float y; };
struct line { float A; float B; float C; };

bool ArePointsOnTheSameSide(line Line, point Point1, point Point2);
void GetPoint(string question, point &Point);
void GetLine(string question, line &Line);

int main() {
    float A, B, C;
    point Point1, Point2;
    line Line;

    GetPoint("Podaj współrzędne pierwszego punktu:", Point1);
    GetPoint("Podaj współrzędne drugiego punktu:", Point2);
    GetLine("Podaj współczynniki prostej:", Line);

    if (ArePointsOnTheSameSide(Line, Point1, Point2))
        cout << "Punkty leżą po tej samej stronie prostej." << "\n";
    else
        cout << "Punkty leżą po tej samej stronie prostej." << "\n";

    return 0;
}

bool ArePointsOnTheSameSide(line Line, point Point1, point Point2) {
    return ((Line.A * Point1.x + Line.B * Point1.y + Line.C) * (Line.A * Point2.x + Line.B * Point2.y + Line.C));
}

void GetPoint(string question, point &Point) {
    cout << question << "\n";
    cout << "    x = "; cin >> Point.x;
    cout << "    y = "; cin >> Point.y;
    cout << "\n";
}

void GetLine(string question, line &Line) {
    cout << question << "\n";
    cout << "    A = "; cin >> Line.A;
    cout << "    B = "; cin >> Line.B;
    cout << "    C = "; cin >> Line.C;
    cout << "\n";
}
