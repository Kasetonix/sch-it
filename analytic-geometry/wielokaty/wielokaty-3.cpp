#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

using std::cout;
using std::ifstream;
using std::ofstream;
using std::vector;
using std::sqrt;

struct Point {
    int x;
    int y;
};

struct Vec {
    Point A;
    Point B;
};

struct Polygon {
    unsigned short num_of_sides;
    vector<Vec> side;
};

vector<Polygon> GetPolygonsFromFile(ifstream &infile);
float GetSmallestMaskingCircleRadius(Polygon pol);

int main() {
    vector<Polygon> polygon;
    unsigned int index;
    float c_radius, max_radius;

    // Pliki wejściowe / wyjściowe
    // infile tylko jest sprawdzany czy dobrze się otwiera
    ifstream infile("wielokaty.txt");
    ofstream outfile("wynik.txt", std::ios::app);
    if (!infile.good() || !outfile.good()) {
        cout << "Pliki nie mogły być otwarte." << "\n";
        return 1;
    }
    infile.close();

    // Otrzymanie wielokątów w pliku
    polygon = GetPolygonsFromFile(infile);

    for (index = 0; index < polygon.size(); index++) {
        c_radius = GetSmallestMaskingCircleRadius(polygon[index]);
        if (c_radius > max_radius)
            max_radius = c_radius;
    }

    outfile << "/// 4.3 ///" << "\n";
    outfile << "Minimalny promień koła o środku w (0; 0), które przykryje wszystkie wielokąty: " << max_radius << "\n\n";

    outfile.close();
    return 0;
}

vector<Polygon> GetPolygonsFromFile(ifstream &infile) {
    // przedrostek c_ jako current
    unsigned short index, c_polygon_type;
    int c_x, c_y;
    Point c_point;
    vector<Point> c_vertices;
    vector<Vec> c_sides;
    Polygon c_polygon;
    vector<Polygon> polygon;

    // Plik na pewno działa, bo został sprawdzony w main()
    infile.open("wielokaty.txt");

    do {
        infile >> c_polygon_type;
        for (index = 0; index < c_polygon_type; index++) {
            // pobieranie współrzędnych jednego punktu
            infile >> c_x >> c_y;
            // wpisywanie powyższych punktów do structa "Point"
            c_point = { c_x, c_y };
            // Dodanie powyższego punktu do wektora "Pointów"
            c_vertices.push_back(c_point);
        }

        // Tworzenie odcinków będących ścianami z wierzchołków otrzymanych wcześniej
        for (index = 0; index < c_polygon_type - 1; index++) {
            c_sides.push_back({c_vertices[index], c_vertices[index+1]});
        }
        // bok od ostatniego wierzchołka do pierwszego
        c_sides.push_back({c_vertices[c_polygon_type-1], c_vertices[0]});

        // Utworzenie wielokątą z danych pobranych wcześniej
        c_polygon = { c_polygon_type, c_sides };
        // dodanie obecnego wielokąta do vectora "Polygonów"
        polygon.push_back(c_polygon);

        // Czyszczenie wszystkich vectorów poza "polygon"
        c_vertices.clear();
        c_sides.clear();

    // Pętla iteruje się dopóki plik się nie skończy
    } while (!infile.eof());

    return polygon;
}

// Funkcja zwracająca najmniejszy promień koła o
// środku w punkcie (0; 0), które zakrywa cały wielokąt
float GetSmallestMaskingCircleRadius(Polygon pol) {
    unsigned short index;
    float c_radius, max_radius = 0;

    // Pętla sprawdza odległość od punktu (0; 0)
    // każdego wierzchołka -> tylko wierzchołek może być
    // punktem najdalej oddalonym od punktu (0; 0)
    // największa z tych odległości to najmniejszy promień koła
    // o środku w (0; 0), które przykryłoby cały wielokąt;
    for (index = 0; index < pol.num_of_sides; index++) {
        c_radius = sqrt(pol.side[index].A.x * pol.side[index].A.x + pol.side[index].A.y * pol.side[index].A.y);

        if (c_radius > max_radius)
            max_radius = c_radius;
    }

    return max_radius;
}
