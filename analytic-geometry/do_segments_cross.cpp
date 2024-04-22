#include <iostream>

using std::cout;
using std::cin;
using std::string;
using std::min;
using std::max;

struct point { float x; float y; };
struct segment { point A; point B; };

const float EPS = 0.0001;

void GetSegment(string question, struct segment &segment);
float Det(point A, point B, point P);
float PointRelation(struct segment seg, point P);
float AbsVal(float number);
bool IsPointOnSegment(struct segment seg, point P);
bool ArePointsOnDifferentSides(struct segment seg, point A, point B);
bool DoSegmentsCross(struct segment seg_a, struct segment seg_b);

int main() {
    segment seg_a, seg_b;

    GetSegment("Podaj współrzędne pierwszego odcinka", seg_a);
    GetSegment("Podaj współrzędne drugiego odcinka", seg_b);

    if (DoSegmentsCross(seg_a, seg_b))
        cout << "Odcinki przecinają się." << "\n";
    else
        cout << "Odcinki nie przecinają się." << "\n";

    return 0;
}

/* Pobieranie krańcy przedziału */
void GetSegment(string question, struct segment &segment) {
    cout << question << "\n";
    cout << "A:     x = "; cin >> segment.A.x;
    cout << "       y = "; cin >> segment.A.y;
    cout << "B:     x = "; cin >> segment.B.x;
    cout << "       y = "; cin >> segment.B.y;
    cout << "\n";
}

/* funkcja obliczająca wyznacznik macierzy kwadratowej */
float Det(point A, point B, point P) {
    return (P.y - A.y) * (B.x - A.x) - (B.y - A.y) * (P.x - A.x);
}

/* Funkcja korzystająca z wyznacznika by określić 
 * gdzie znajduje się punkt w stosunku do odcinka 
 * : > 0 -> nad odcinkiem 
 * : = 0 -> współliniowy z odcinkiem 
 * : < 0 -> pod odcinkiem */
float PointRelation(struct segment seg, point P) {
    return Det(seg.A, seg.B, P);
}

/* Wartość bezwzględna funkcji */
float AbsVal(float number) {
    if (number < 0)
        return -number;
    return number;
}

/* Funkcja sprawdzająca, czy punkt należy do odcinka */
bool IsPointOnSegment(struct segment seg, point P) {
    /* Sprawdzenie czy wyznacznik jest większy od "zera" (około) */
    if (AbsVal(PointRelation(seg, P)) > EPS)
        return false;

    /* Sprawdzanie czy punkt mieści się na odcinku
     * poprzedni krok sprawdził, że leży on na prostej
     * przechodzącej przez krańce odcinka*/
    return (P.x >= min(seg.A.x, seg.B.x) && P.x <= max(seg.A.x, seg.B.x) && 
            P.y >= min(seg.A.y, seg.B.y) && P.y <= max(seg.A.y, seg.B.y));
}

bool ArePointsOnDifferentSides(struct segment seg, point A, point B) {
    return (PointRelation(seg, A) * PointRelation(seg, B) < 0);
}

bool DoSegmentsCross(struct segment seg_a, struct segment seg_b) {
    /* Jeżeli którykolwiek z krańcy odcinka znajduje się na drugim,
     * to znaczy że te dwa odcinki się przecinają */
    if (IsPointOnSegment(seg_a, seg_b.A) ||
        IsPointOnSegment(seg_a, seg_b.B) ||
        IsPointOnSegment(seg_b, seg_b.A) ||
        IsPointOnSegment(seg_b, seg_b.B))
        return true;
    /* Jeżeli dla obu odcinków ich końce są po przeciwnych stronach tego drugiego, 
     * to wtedy się przecinają */
    else if (ArePointsOnDifferentSides(seg_a, seg_b.A, seg_b.B) && 
             ArePointsOnDifferentSides(seg_b, seg_a.A, seg_a.B))
        return true;

    return false;
}
