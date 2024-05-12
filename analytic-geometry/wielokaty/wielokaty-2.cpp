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

struct Triangle {
    Vec side[3];
};

struct MaskingRectangle {
    int min_x;
    int max_x;
    int min_y;
    int max_y;
};

vector<Polygon> GetPolygonsFromFile(ifstream &infile);
vector<Triangle> GetTriangles(vector<Polygon> polygon);
float GetTrianglesArea(Triangle triangle);
void DrawTriangle(Triangle triangle);

int main() {
    vector<Triangle> triangle;
    unsigned int index;
    float c_area, min_area, max_area;

    // Pliki wejściowe / wyjściowe
    // infile tylko jest sprawdzany czy dobrze się otwiera
    ifstream infile("wielokaty.txt");
    ofstream outfile("wynik.txt", std::ios::app);
    if (!infile.good() || !outfile.good()) {
        cout << "Pliki nie mogły być otwarte." << "\n";
        return 1;
    }
    infile.close();

    // Otrzymanie Trójkątów z pliku
    triangle = GetTriangles(GetPolygonsFromFile(infile));
    
    // Ustawianie początkowych wartości maksymalnych i minimalnych
    min_area = GetTrianglesArea(triangle[0]);
    max_area = 0;

    // Sprawdzanie jaka jest minimalna i maksymalna powierzchnia
    for (index = 1; index < triangle.size(); index++) {
        c_area = GetTrianglesArea(triangle[index]);
        if (c_area < min_area)
            min_area = c_area;
        else if (c_area > max_area)
            max_area = c_area;
    }

    outfile << "/// 4.2 ///" << "\n";
    outfile << "Minimalne pole trójkąta: " << min_area << "\n";
    outfile << "Maksymalne pole trójkąta: " << max_area << "\n\n";

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

vector<Triangle> GetTriangles(vector<Polygon> polygon) {
    unsigned short index;
    vector<Triangle> triangle;
    vector<Vec> c_sides;

    for (index = 0; index < polygon.size(); index++) {
        if (polygon[index].num_of_sides == 3) {
            // Dla każdego trójkąta do tablicy
            // z bokami wrzucamy boki zapisane w
            // vectorze w polygonie
            c_sides = polygon[index].side;
            triangle.push_back({{c_sides[0], c_sides[1], c_sides[2]}});
            // Czyszczenie obecnych boków polygona
            c_sides.clear();
        }
    }

    return triangle;
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

// Funkcja sprawdzająca, czy punkt leży w trójkącie 
// lub na jego krawędzi
bool IsPointInTriangle(Triangle triangle, Point P) {
    bool is_on_left_side = true, is_on_right_side = true;
    unsigned short index;

    // sprawdzanie każdej ściany czy dany punkt jest 
    // po jej lewej stronie lub jest współliniowy
    for (index = 0; index < 3; index++) {
        if (PointRelation(triangle.side[index], P) == 'r') {
            is_on_left_side = false;
            break;
        }
    }

    // to samo co wcześniej tylko z prawą stroną
    for (index = 0; index < 3; index++) {
        if (PointRelation(triangle.side[index], P) == 'l') {
            is_on_right_side = false;
            break;
        }
    }

    // jeżeli punkt jest po lewej lub prawej stronie każdej ściany,
    // to znaczy że jest w środku tego wielokąta
    return (is_on_left_side || is_on_right_side);
}

// Funkcja sprawdzająca czy punkt leży na jednym z boków trójkąta
bool IsPointOnTrianglesSide(Triangle triangle, Point P) {
    unsigned short index;

    // punkt leży na boku trójkąta, jeżeli jest z nim współliniowy
    // i leży w wielokącie
    if (!IsPointInTriangle(triangle, P))
        return false;

    for (index = 0; index < 3; index++) {
        if (PointRelation(triangle.side[index], P) == 'c')
            return true;
    }

    return false;
}

// Funkcja znajdujące maksymalne i minimalne wartości współrzędnych trójkąta:
// "tworzy" najmniejszy możliwy kwadrat, który przykrywa cały trójkąt
MaskingRectangle GetMaskingRectangle(Triangle triangle) {
    // Początkowe wartości skrajnych współrzędnych - pierwszy punkt
    Point c_point = triangle.side[0].A;
    int min_x = c_point.x, 
        max_x = c_point.x, 
        min_y = c_point.y, 
        max_y = c_point.y;
    unsigned short index;
    
    // iteracja po każdym następnym punkcie i 
    // sprawdzanie czy ma jakąś skrajną współrzędną
    for (index = 1; index < 3; index++) {
        c_point = triangle.side[index].A;
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

// Funkcja zliczająca wszystkie punkty w środku wielokąta
// (ale nie na jego krawędzi)
unsigned int PointsInsideTriangle(Triangle triangle) {
    MaskingRectangle mr = GetMaskingRectangle(triangle);
    unsigned short points_inside = 0;
    int x, y;
    
    // Iteracja przez wszystkie punkty należące do kwadratu maskującego
    for (y = mr.max_y; y >= mr.min_y; y--) {
        for (x = mr.min_x; x <= mr.max_x; x++) {
            // Jeżeli sprawdzany punkt jest w wielokącie ale nie na krawędzi,
            // to leży wewnątrz (nie licząc krawędzi), więc zwiększamy licznik
            if (IsPointInTriangle(triangle, { x, y }) && !IsPointOnTrianglesSide(triangle, { x, y })) {
                points_inside++;
            }
        }
    }

    return points_inside;
}

// Funkcja zliczająca wszystkie punkty na krawędziach wielokąta
unsigned int PointsOnTrianglesSide(Triangle triangle) {
    MaskingRectangle masking_rectangle = GetMaskingRectangle(triangle);
    unsigned short points_on_side = 0;
    int x, y;
    
    // Iteracja przez wszystkie punkty należące do kwadratu maskującego
    for (y = masking_rectangle.max_y; y >= masking_rectangle.min_y; y--)
        for (x = masking_rectangle.min_x; x <= masking_rectangle.max_x; x++)
            // Jeżeli sprawdzany punkt leży na krawędzi wielokąta zwiększamy licznik
            if (IsPointOnTrianglesSide(triangle, { x, y }))
                points_on_side++;

    return points_on_side;
}

// Funkcja obliczająca pole wielokąta używając wzoru Picka
float GetTrianglesArea(Triangle triangle) {
    return (PointsInsideTriangle(triangle) + PointsOnTrianglesSide(triangle)/2.0 - 1);
}
