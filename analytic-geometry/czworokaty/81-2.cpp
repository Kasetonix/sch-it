#include <fstream>
#include <iostream>

using std::cout;
using std::ifstream;
using std::ofstream;
using std::ios;

struct point { int x; int y; };
struct point_set { point A; point B; point C; };

short CheckQuater(point p);
float Det(point A, point B, point P);
float DetFromSet(point_set ps);

int main() {
    const unsigned short SET_NUM = 100;
    point_set point_sets[100];
    unsigned short index, count = 0;

    /* pliki wejściowe */
    ifstream infile;
    ofstream outfile;
    infile.open("wspolrzedne.txt");
    outfile.open("wynik.txt", ios::app);
    if (!infile.good() || !outfile.good()) {
        cout << "Plik nie mógł być otwarty." << "\n";
        return 1;
    }

    /* Wczytanie współrzędnych z pliku do tablicy */
    for (index = 0; index < SET_NUM; index++)
        infile >> point_sets[index].A.x
               >> point_sets[index].A.y
               >> point_sets[index].B.x
               >> point_sets[index].B.y
               >> point_sets[index].C.x
               >> point_sets[index].C.y;
    infile.close();

    /* Sprawdzenie, czy każdy punkt z zestawu jest w pierwszej ćwiartce */
    for (index = 0; index < SET_NUM; index++)
        if (DetFromSet(point_sets[index]) == 0)
            count++;


    outfile << "/// 81.2 ///" << "\n";
    outfile << "Liczba zestawów punktów, które są współliniowe: " << count << "\n";
    outfile.close();

    return 0;
}

/* Zwraca numer ćwiartki, w której znajduje się punkt */
short CheckQuater(point p) {
    if (p.x > 0 && p.y > 0)
        return 1;
    if (p.x < 0 && p.y > 0)
        return 2;
    if (p.x < 0 && p.y < 0)
        return 3;
    if (p.x > 0 && p.y < 0)
        return 4;

    return 0;
}

/* funkcja obliczająca wyznacznik macierzy kwadratowej */
float Det(struct point A, struct point B, struct point P) {
    return (P.y - A.y) * (B.x - A.x) - (B.y - A.y) * (P.x - A.x);
}

/* Funckja licząca wyznacznik z całego zbioru */
float DetFromSet(point_set ps) {
    return Det(ps.A, ps.B, ps.C);
}
