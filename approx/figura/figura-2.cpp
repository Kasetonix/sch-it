#include <cmath>
#include <iostream>
#include <fstream>

using std::ios;
using std::ofstream;
using std::cout;

unsigned int INTER_NUM = 1000;

float f(float x);
float g(float x);
float f_integral(float C);
float g_integral(float C);

int main() {
    float C = 10, x = 0, diff = 1;

    /* plik wyjściowy */
    ofstream outfile;
    outfile.open("wynik.txt", ios::app);
    if (!outfile.good()) {
        cout << "Plik wyjściowy nie mógł być otwarty." << "\n";
        return 1;
    }

    /* Dopóki  */
    while (true) {
        diff = g(x) - f(x);
        if (diff >= 26)
            break;
        x++;
    }

    if (g(x) != floor(g(x)) || f(x) != floor(f(x))) 
        x++;

    /* outfile << "a)" << "\n";
    outfile << "Pole powierzchni figury dla C = 10: " << area << "\n"; */
    std::cout << x << " "<< floor(g(x)) << " " << ceil(f(x)) << "\n";

    outfile.close();
    return 0;
}

/* -x²/50 */
float f(float x) {
    return (-x*x / 50.0);
}

/* x²/100 - x/200 + 1 */
float g(float x) {
    return (x*x / 100.0 - x / 200.0 + 1);
}
