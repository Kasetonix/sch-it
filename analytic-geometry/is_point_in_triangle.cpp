#include <iostream>

using std::cout;
using std::cin;
using std::string;

struct point { float x; float y; };
struct vec { point A; point B; };

void GetPoint(string question, struct point &A);
void CreateSideVectors(point A, point B, point C, vec &vec_a, vec &vec_b, vec &vec_c);
float Det(point A, point B, point P);
float PointRelation(struct vec vec, point P);
bool IsPointInTriangle(vec vec_a, vec vec_b, vec vec_c, point p);

int main() {
    vec vec_a, vec_b, vec_c;
    point A, B, C, P;

    cout << "Podaj współrzędne wierzchołków wielokąta." << "\n";
    GetPoint("Podaj współrzędne punktu A: ", A);
    GetPoint("Podaj współrzędne punktu B: ", B);
    GetPoint("Podaj współrzędne punktu C: ", C);

    GetPoint("Podaj współrzędne sprawdzanego punktu: ", P);

    CreateSideVectors(A, B, C, vec_a, vec_b, vec_c);

    if (IsPointInTriangle(vec_a, vec_b, vec_c, P))
        cout << "Punkt znajduje się w wielokącie." << "\n";
    else
        cout << "Punkt nie znajduje się w wielokącie." << "\n";

    return 0;
}

/* Funkcja do otrzymywania od użytkownika współrzędnych danego punktu */
void GetPoint(string question, struct point &A) {
    cout << question << "\n";
    cout << "    x = "; cin >> A.x;
    cout << "    y = "; cin >> A.y;
    cout << "\n";
}

/* Funkcja do tworzenia wektorów stanowiących boki trójkąta */
void CreateSideVectors(point A, point B, point C, vec &vec_a, vec &vec_b, vec &vec_c) {
    vec_a = {A, B};
    vec_b = {B, C};
    vec_c = {C, A};
}

/* funkcja obliczająca wyznacznik macierzy kwadratowej */
float Det(struct point A, struct point B, struct point P) {
    return (P.y - A.y) * (B.x - A.x) - (B.y - A.y) * (P.x - A.x);
}

/* Funkcja korzystająca z wyznacznika by określić
 * gdzie znajduje się punkt w stosunku do wektora
 * : > 0 -> po lewej stronie wektora
 * : = 0 -> współliniowy z wektorem 
 * : < 0 -> po prawej stronie wektora */
float PointRelation(struct vec vec, struct point P) {
    return Det(vec.A, vec.B, P);
}

bool IsPointInTriangle(vec vec_a, vec vec_b, vec vec_c, point p) {
    /* Jeżeli punkt leży po jednej stronie (lewej lub prawej)
     * każdego z tych wektorów (lub na nim), to znaczy, że leży w środku trójkąta */
    return ((PointRelation(vec_a, p) >= 0 && PointRelation(vec_b, p) >= 0 && PointRelation(vec_c, p) >= 0) ||
            (PointRelation(vec_a, p) <= 0 && PointRelation(vec_b, p) <= 0 && PointRelation(vec_c, p) <= 0));
}
