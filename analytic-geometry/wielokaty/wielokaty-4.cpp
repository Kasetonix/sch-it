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

struct Vec {
    Point A;
    Point B;
};

struct Polygon {
    unsigned short num_of_sides;
    vector<Vec> side;
};

struct MaskingRectangle {
    int min_x;
    int max_x;
    int min_y;
    int max_y;
};

vector<Polygon> GetPolygonsFromFile(ifstream &infile);
unsigned int PointsOnSide(Polygon polygon);

int main() {
    vector<Polygon> polygon;
    unsigned int index;
    unsigned int c_count, c_sides,
                 max_point_count = 0, max_point_count_sides = 0,
                 max_2_point_count = 0, max_2_point_count_sides = 0;

    // Pliki wejściowe / wyjściowe
    // infile tylko jest sprawdzany czy dobrze się otwiera
    ifstream infile("wielokaty.txt");
    ofstream outfile("wynik.txt", std::ios::app);
    if (!infile.good() || !outfile.good()) {
        cout << "Pliki nie mogły być otwarte." << "\n";
        return 1;
    }
    infile.close();

    polygon = GetPolygonsFromFile(infile);
    
    for (index = 0; index < polygon.size(); index++) {
        c_count = PointsOnSide(polygon[index]);
        c_sides = polygon[index].num_of_sides;

        if (c_count > max_point_count) {
            max_2_point_count = max_point_count;
            max_2_point_count_sides = max_point_count_sides;
            
            max_point_count = c_count;
            max_point_count_sides = c_sides;
        } else if (c_count > max_2_point_count) {
            max_2_point_count = c_count;
            max_2_point_count_sides = c_sides;
        }
    }

    outfile << "/// 4.4 ///" << "\n";
    outfile << "Maksymalna liczba punktów kratowych krawędzi; liczba krawędzi tego wielokątu:       " << max_point_count << " " << max_point_count_sides << "\n";
    outfile << "Druga maksymalna liczba punktów kratowych krawędzi; liczba krawędzi tego wielokątu: " << max_2_point_count << " " << max_2_point_count_sides << "\n\n";

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

    // Wczytanie pierwszej linijki
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

    // pętla iteruje się dopóki da się wczytać dane z pliku
    } while (infile >> c_polygon_type);

    return polygon;
}

// Wyznacznik macierzy z trzema punktami
// | A.x  A.y  1 |
// | B.x  B.y  1 |
// | P.x  P.y  1 |
float Det(Point A, Point B, Point P) {
    return ((A.x * B.y) + (B.x * P.y) + (P.x * A.y) -
            (A.y * B.x) - (B.y * P.x) - (P.y * A.x));
}


// Funkcja zwracająca relację między punktem a wektorem;
// - 'l' -> po lewej stronie
// - 'r' -> po prawej stronie
// - 'c' -> współliniowy z wektorem
char PointRelation(Vec vec, Point P) {
    if (Det(vec.A, vec.B, P) > 0)
        return 'l';
    else if (Det(vec.A, vec.B, P) < 0)
        return 'r';
    return 'c';
}

// Funkcja znajdujące maksymalne i minimalne wartości współrzędnych wielokąta:
// "tworzy" najmniejszy możliwy prostokąt, który przykrywa cały wielokąt
MaskingRectangle GetMaskingRectangle(Polygon polygon) {
    // Początkowe wartości skrajnych współrzędnych - pierwszy punkt
    Point c_point = polygon.side[0].A;
    int min_x = c_point.x, 
        max_x = c_point.x, 
        min_y = c_point.y, 
        max_y = c_point.y;
    unsigned short index;
    
    // iteracja po każdym następnym punkcie i 
    // sprawdzanie czy ma jakąś skrajną współrzędną
    for (index = 1; index < polygon.num_of_sides; index++) {
        c_point = polygon.side[index].A;
        if (c_point.x < min_x)
            min_x = c_point.x;
        if (c_point.x > max_x)
            max_x = c_point.x; 
        if (c_point.y < min_y)
            min_y = c_point.y;
        if (c_point.y > max_y)
            max_y = c_point.y; 
    }

    // Zwracanie czterech współrzędnych jako struct MaskingRectangle
    return { min_x, max_x, min_y, max_y };
}

// Funkcja znajdujące maksymalne i minimalne wartości współrzędnych jednego boku:
// "tworzy" najmniejszy możliwy prostokąt, który przykrywa cały trójkąt
MaskingRectangle GetSideMaskingRectangle(Vec side) {
    int min_x, max_x, min_y, max_y;

    min_x = side.A.x <= side.B.x ? side.A.x : side.B.x;
    max_x = side.A.x >= side.B.x ? side.A.x : side.B.x;
    min_y = side.A.y <= side.B.y ? side.A.y : side.B.y;
    max_y = side.A.y >= side.B.y ? side.A.y : side.B.y;

    return { min_x, max_x, min_y, max_y };
}

// Funkcja sprawdzająca czy punkt leży na jednym z boków wielokąta
bool IsPointOnSide(Polygon polygon, Point P) {
    unsigned short index;
    bool in_x_interval = false, in_y_interval = false;
    Vec c_side;
    MaskingRectangle mr;

    for (index = 0; index < polygon.num_of_sides; index++) {
        c_side = polygon.side[index];
        // pomijamy wszystkie ściany z którymi punkt nie jest współliniowy
        if (PointRelation(c_side, P) != 'c')
            continue;
        
        mr = GetSideMaskingRectangle(c_side);

        if (P.x >= mr.min_x && P.x <= mr.max_x)
            in_x_interval = true;
        if (P.y >= mr.min_y && P.y <= mr.max_y)
            in_y_interval = true;

        // Sprawdzamy kolejny bok, jeżeli punkt
        // nie znajduje się na obecnym
        if (!in_x_interval || !in_y_interval)
            continue;

        return true;
    }

    return false;
}

// Funkcja zliczająca wszystkie punkty na krawędziach wielokąta
unsigned int PointsOnSide(Polygon polygon) {
    MaskingRectangle masking_rectangle = GetMaskingRectangle(polygon);
    unsigned short points_on_side = 0;
    int x, y;
    
    // Iteracja przez wszystkie punkty należące do prostokąta maskującego
    for (y = masking_rectangle.max_y; y >= masking_rectangle.min_y; y--)
        for (x = masking_rectangle.min_x; x <= masking_rectangle.max_x; x++)
            // Jeżeli sprawdzany punkt leży na krawędzi wielokąta zwiększamy licznik
            if (IsPointOnSide(polygon, { x, y }))
                points_on_side++;

    return points_on_side;
}
