#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>

using std::cout;
using std::ifstream;
using std::ofstream;
using std::vector;
using std::fixed;
using std::setprecision;

struct Point {
    int x;
    int y;
};

struct Vec {
    Point A;
    Point B;
};

struct Quad {
    Vec side[4];
};

struct MaskingRectangle {
    int min_x;
    int max_x;
    int min_y;
    int max_y;
};

vector<Quad> GetQuadrilateralsFromFile(ifstream &infile);
float QuadsArea(Quad quad);
void DrawQuad(Quad quad);

int main() {
    vector<Quad> quad;
    unsigned int index;
    float total_area = 0, avg_area;

    // Pliki wejściowe / wyjściowe
    // infile tylko jest sprawdzany czy dobrze się otwiera
    ifstream infile("wielokaty.txt");
    ofstream outfile("wynik.txt", std::ios::app);
    if (!infile.good() || !outfile.good()) {
        cout << "Pliki nie mogły być otwarte." << "\n";
        return 1;
    }
    infile.close();

    // Otrzymanie czworokątów z pliku
    quad = GetQuadrilateralsFromFile(infile); 

    // Iteracja przez wszystkie czworokąty i sumowanie ich pól
    for (index = 0; index < quad.size(); index++) 
        total_area += QuadsArea(quad[index]);

    // Obliczanie średniego pola
    avg_area = total_area / index;

    outfile << "/// 4.5 ///" << "\n";
    outfile << "Średnie pole czworokąta: " << fixed << setprecision(2) << avg_area << "\n";

    outfile.close();
    return 0;
}

// Funkcja otrzymująca jedynie czworokąty z pliku
vector<Quad> GetQuadrilateralsFromFile(ifstream &infile) {
    // przedrostek c_ jako current
    unsigned short index, c_polygon_type;
    int c_x, c_y, tmp;
    Point c_vertices[4];
    Vec c_sides[4];
    vector<Quad> quad;

    // Plik na pewno działa, bo został sprawdzony w main()
    infile.open("wielokaty.txt");

    infile >> c_polygon_type;
    do {
        // Pomijanie wszystkich wielokątów niebędących czworokątami
        if (c_polygon_type != 4) {
            for (index = 0; index < 2*c_polygon_type; index++)
                infile >> tmp;
            continue;
        }

        for (index = 0; index < 4; index++) {
            // pobieranie współrzędnych jednego punktu
            infile >> c_x >> c_y;
            // Dodanie powyższego punktu do tablicy z wierzchołkami
            c_vertices[index] = { c_x, c_y };
        }

        // Tworzenie odcinków będących ścianami z wierzchołków otrzymanych wcześniej
        for (index = 0; index < 3; index++) {
            c_sides[index] = { c_vertices[index], c_vertices[index+1] };
        }
        // Bok od ostatniego wierzchołka do pierwszego
        c_sides[3] = { c_vertices[3], c_vertices[0] };

        // Dodanie obecnego wielokąta do vectora "Polygonów"
        quad.push_back({ c_sides[0], c_sides[1], c_sides[2], c_sides[3] });

    // Pętla iteruje się dopóki plik się nie skończy
    } while (infile >> c_polygon_type);

    infile.close();
    return quad;
}

// Funkcja znajdujące maksymalne i minimalne wartości współrzędnych czworokąta:
// "tworzy" najmniejszy możliwy kwadrat, który przykrywa cały czworokąt 
MaskingRectangle GetMaskingRectangle(Quad quad) {
    // Początkowe wartości skrajnych współrzędnych - pierwszy punkt
    Point c_point = quad.side[0].A;
    int min_x = c_point.x, 
        max_x = c_point.x, 
        min_y = c_point.y, 
        max_y = c_point.y;
    unsigned short index;
    
    // iteracja po każdym następnym punkcie i 
    // sprawdzanie czy ma jakąś skrajną współrzędną
    for (index = 1; index < 4; index++) {
        c_point = quad.side[index].A;
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

// Funkcja tworząca MaskingRectangle ale dla jednego wektora
MaskingRectangle GetVecMaskingRectangle(Vec vec) {
    int min_x, max_x, min_y, max_y;

    min_x = (vec.A.x <= vec.B.x) ? vec.A.x : vec.B.x;
    max_x = (vec.A.x >= vec.B.x) ? vec.A.x : vec.B.x;
    min_y = (vec.A.y <= vec.B.y) ? vec.A.y : vec.B.y;
    max_y = (vec.A.y >= vec.B.y) ? vec.A.y : vec.B.y;

    return { min_x, max_x, min_y, max_y };
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

// Funkcja sprawdzająca czy punkt leży na wektorze:
// sprawdza, czy jest współliniowy i czy mieści się w
// MaskingRectangle wektora
bool IsPointOnVec(Vec vec, Point P) {
    if (PointRelation(vec, P) != 'c')
        return false;

    MaskingRectangle mr = GetVecMaskingRectangle(vec);
    bool x_in_interval = false, y_in_interval = false;

    if (P.x >= mr.min_x && P.x <= mr.max_x)
        x_in_interval = true;
    if (P.y >= mr.min_y && P.y <= mr.max_y)
        y_in_interval = true;

    return (x_in_interval && y_in_interval);
}

// Funkcja sprawdzająca przynależność do dowolnego boku czworokąta
bool IsPointOnAnySide(Quad quad, Point P) {
    unsigned short index;
    for (index = 0; index < 4; index++) {
        if (IsPointOnVec(quad.side[index], P))
            return true;
    }

    return false;
}

// Funkcja sprawdzająca czy dwa punkty leżą po przeciwnych stronach wektora
// korzystając z wyróżnika
bool ArePointsOnOppositeSides(Vec vec, Point A, Point B) {
    return ((PointRelation(vec, A) == 'l' && PointRelation(vec, B) == 'r') ||
            (PointRelation(vec, A) == 'r' && PointRelation(vec, B) == 'l'));
}

// Funkcja sprawdzająca, czy dwa wektory przecinają się
bool DoVecsCross(Vec vec_a, Vec vec_b) {
    return (ArePointsOnOppositeSides(vec_a, vec_b.A, vec_b.B) &&
            ArePointsOnOppositeSides(vec_b, vec_a.A, vec_a.B));
}

// Funkcja tworząca wektor testowy - równoległy do osi Ox i 
// mający początek w danym punkcie oraz koniec wystający za czworokąt z prawej strony
Vec TestVector(Quad quad, Point P) {
    return { P, { GetMaskingRectangle(quad).max_x + 1, P.y} };
}

// Funkcja zliczająca przecięcia wektora testowego z bokami czworokąta
// Bierze ona pod uwagę wszystkie możliwe przypadki
unsigned short CountSideCrossings(Quad quad, Vec t_vec) {
    unsigned short counter = 0, index;
    MaskingRectangle mr_t_vec = GetVecMaskingRectangle(t_vec), mr_c_side;
    Vec c_side;

    // We wzorze Picka potrzebna jest jedynuie liczba punktów
    // znajdujących się wewnątrz z wyłączeniem krawędzi
    // Zwracając zero dalsze funkcje traktują punkt na krawędzi
    // jako nienależący do czworokąta
    if (IsPointOnAnySide(quad, t_vec.A))
        return 0;

    // Iteracja przez wszystkie boki
    for (index = 0; index < 4; index++) {
        c_side = quad.side[index];
        mr_c_side = GetVecMaskingRectangle(c_side);

        // Poniżej rozważane są trzy przypadki; naraz możliwy jest tylko jeden z nich, 
        // więc wykorzystane jest continue (wektor testowy może przeciąć bok tylko raz)

        // 1. przypadek:
        // Wektor testowy zawiera w sobie jeden z boków: tj jest z nim współliniowy oraz 
        // minimalny x boku jest większy od minimalnego x wierzchołka;
        // wynika to z konstrukcji wektora testowego.

        // 2. przypadek
        // Wektor testowy przecina wierzchołek.
        // Wykorzystany jest indeks mod 4 żeby na pewno nie wyjść poza tablicę,
        // a więc otrzymać dobry bok

        // W obu przypadkach należy sprawdzić czy poprzedni i następny wierzchołek
        // są po przeciwnych stronach wektora testowego
        // Jeżeli tak to licznik jest inkrementowany. Oba przypadki sprawdzane są na raz.

        if ((PointRelation(c_side, t_vec.A) == 'c' && mr_c_side.min_x >= mr_t_vec.min_x) || // 1. przypadek 
            (IsPointOnVec(t_vec, c_side.A))) {                                              // 2. przypadek
            if (ArePointsOnOppositeSides(t_vec, quad.side[(index - 1) % 4].A, c_side.B))
                counter++;
            continue;
        }

        // 3. przypadek
        // Wektor testowy zwyczajnie przecina bok; licznik jest inkrementowany
        if (DoVecsCross(t_vec, c_side))
            counter++;
    }

    return counter;
}

// Funkcja sprawdzająca, czy punkt należy do czworokąta na podstawie
// liczby przecięć wektora testowego z bokami tego czworokąta
bool IsPointInQuad(Quad quad, Point P) {
    if (CountSideCrossings(quad, TestVector(quad, P)) % 2 == 1)
        return true;
    return false;
}

// Funkcja zliczająca wszystkie punkty wewnątrz czworokąta
// Iteruje ona przez wszystkie punkty należące do MaskingRectangle
// i sprawdza dla każdego z nich czy należy do czworokąta
unsigned short CountPointsInsideQuad(Quad quad) {
    MaskingRectangle mr = GetMaskingRectangle(quad);
    int x, y;
    unsigned short points = 0;

    for (y = mr.max_y; y >= mr.min_y; y--)
        for (x = mr.min_x; x <= mr.max_x; x++)
            if (IsPointInQuad(quad, { x, y }))
                points++;

    return points;
}

// Funkcja zliczająca wszystkie punkty na krawędziach czworokąta
// Metoda taka sama jak w poprzedniej funkcji
unsigned short CountPointsOnQuadSides(Quad quad) {
    MaskingRectangle mr = GetMaskingRectangle(quad);
    int x, y;
    unsigned short points = 0;

    for (y = mr.max_y; y >= mr.min_y; y--)
        for (x = mr.min_x; x <= mr.max_x; x++)
            if (IsPointOnAnySide(quad, { x, y }))
                points++;

    return points;
}

// Funkcja obliczająca pole korzystając ze wzoru Picka
float QuadsArea(Quad quad) {
    return (CountPointsInsideQuad(quad) + CountPointsOnQuadSides(quad)/2.0 - 1);
}

// Funkcja rysująca czworokąt: przydatna do sprawdzania działania programu
void DrawQuad(Quad quad) {
    int x, y;
    MaskingRectangle mr = GetMaskingRectangle(quad);

    for (y = mr.max_y; y >= mr.min_y; y--) {
        for (x = mr.min_x; x <= mr.max_x; x++) {
            if (IsPointInQuad(quad, { x, y }))
                cout << "#";

            else if (IsPointOnAnySide(quad, { x, y }))
                cout << "@";
            else
                cout << " ";
        }
        cout << "\n";
    }
}
