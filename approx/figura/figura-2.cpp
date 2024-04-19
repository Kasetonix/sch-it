#include <cmath>
#include <iostream>
#include <fstream>

using std::ios;
using std::ofstream;
using std::cout;

unsigned int INTER_NUM = 100;

float f(float x);
float g(float x);

int main() {
    float C = 130, x = 0;
    int diff = 1;

    /* plik wyjściowy */
    ofstream outfile;
    outfile.open("wynik.txt", ios::app);
    if (!outfile.good()) {
        cout << "Plik wyjściowy nie mógł być otwarty." << "\n";
        return 1;
    }

    while (true) {
        /* dla każdego x: g(x) > f(x) i f(x) < 0 
         * suma to jest g(x) - f(x)*/
        diff = floor(g(x)) - ceil(f(x));
        if (diff >= 26)
            break;
        x++;
    }

    outfile << "b)" << "\n";
    outfile << "Współrzędne punktów prostokąta:" << "\n";
    outfile << "A: (" << floor(g(x)) << "; " << x << ")\n";
    outfile << "B: (" << floor(g(x)) - 26 << "; " << x << ")\n";
    outfile << "C: (" << floor(g(x)) - 26 << "; " << C << ")\n";
    outfile << "D: (" << floor(g(x)) << "; " << C << ")\n";

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
