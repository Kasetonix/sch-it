#include <iostream>

using std::string;
using std::cout;
using std::cin;

struct point { float x; float y; };
struct line { float A; float B; float C; };
bool ArePointsOnTheSameSide(line L,  point P1, point P2);
void GetPoint(string question, point &P);
void GetLine(string question, line &L);

int main() {
    float A, B, C;
    point P1, P2;
    line L;

    GetPoint("Podaj współrzędne pierwszego punktu:", P1);
    GetPoint("Podaj współrzędne drugiego punktu:", P2);
    GetLine("Podaj współczynniki prostej:", L);

    if (ArePointsOnTheSameSide(L, P1, P2))
        cout << "Punkty leżą po tej samej stronie prostej." << "\n";
    else
        cout << "Punkty leżą po tej samej stronie prostej." << "\n";

    return 0;
}

bool ArePointsOnTheSameSide(line L, point P1, point P2) {
    return ((L.A*P1.x + L.B*P1.y + L.C) * (L.A*P2.x + L.B*P2.y + L.C));
}

void GetPoint(string question, point &P) {
    cout << question << "\n";
    cout << "    x = "; cin >> P.x;
    cout << "    y = "; cin >> P.y;
    cout << "\n";
}

void GetLine(string question, line &L) {
    cout << question << "\n";
    cout << "    A = "; cin >> L.A;
    cout << "    B = "; cin >> L.B;
    cout << "    C = "; cin >> L.C;
    cout << "\n";
}
