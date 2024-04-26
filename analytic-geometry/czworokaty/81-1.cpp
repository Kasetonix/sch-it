#include <fstream>
#include <iostream>

using std::cout;
using std::ifstream;
using std::ofstream;
using std::ios;

struct point { int x; int y; };
struct point_set { point A; point B; point C; };

short CheckQuater(point p);

int main() {
    const unsigned short SET_NUM = 100;
    point_set point_sets[100];
    unsigned short index, point_sets_num = 0;

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
        if (CheckQuater(point_sets[index].A) == 1 &&
            CheckQuater(point_sets[index].B) == 1 &&
            CheckQuater(point_sets[index].C) == 1)
            point_sets_num++;

    outfile << "/// 81.1 ///" << "\n";
    outfile << "Liczba zestawów punktów w pierwszej ćwiartce: " << point_sets_num << "\n";
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
