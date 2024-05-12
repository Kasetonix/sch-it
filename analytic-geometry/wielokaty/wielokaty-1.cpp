#include <iostream>
#include <fstream>
#include <vector>

using std::cout;
using std::ifstream;
using std::ofstream;
using std::vector;

struct Point {
    int x;
    int y;
};

struct Polygon {
    unsigned short num_of_sides;
    vector<Point> vert;
};

int main() {
    // przedrostek c_ jako current
    unsigned short index, c_polygon_type;
    int c_x, c_y;
    Point c_point;
    vector<Point> c_vertices;
    Polygon c_polygon;
    vector<Polygon> polygon;

    unsigned short triangle_num = 0, pentagon_num = 0;

    // Pliki wejściowe / wyjściowe
    ifstream infile("wielokaty.txt");
    ofstream outfile("wynik.txt", std::ios::app);
    if (!infile.good() || !outfile.good()) {
        cout << "Pliki nie mogły być otwarte." << "\n";
        return 1;
    }

    // Pobieranie danych z pliku
    infile >> c_polygon_type;
    do {
        for (index = 0; index < c_polygon_type; index++) {
            // pobieranie współrzędnych jednego punktu
            infile >> c_x >> c_y;
            // wpisywanie powyższych punktów do structa "Point"
            c_point = { c_x, c_y };
            // Dodanie powyższego punktu do wektora "Pointów"
            c_vertices.push_back(c_point);
        }

        // Utworzenie wielokątą z danych pobranych wcześniej
        c_polygon = { c_polygon_type, c_vertices };
        // dodanie obecnego wielokąta do vectora "Polygonów"
        polygon.push_back(c_polygon);

        // Czyszczenie wektora zawierającego wierzchołki
        c_vertices.clear();

    } while (infile >> c_polygon_type);
    infile.close();

    // Sprawdzanie dla każdego wielokąta czy ma 3 lub 5 boków
    // i przy każdym znalezionym inkrementacja licznika
    for (index = 0; index < polygon.size(); index++) {
        if (polygon[index].num_of_sides == 3)
            triangle_num++;
        else if (polygon[index].num_of_sides == 5)
            pentagon_num++;
    }

    outfile << "/// 4.1 ///" << "\n";
    outfile << "Liczba trójkątów:   " << triangle_num << "\n";
    outfile << "Liczba pięciokątów: " << pentagon_num << "\n\n";

    outfile.close();
    return 0;
}
