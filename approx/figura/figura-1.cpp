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
    const float C = 10;
    float area = 0;

    /* plik wyjściowy */
    ofstream outfile;
    outfile.open("wynik.txt", ios::app);
    if (!outfile.good()) {
        cout << "Plik wyjściowy nie mógł być otwarty." << "\n";
        return 1;
    }

    area = int(100 * (g_integral(C) - f_integral(C))) / 100.0;

    outfile << "a)" << "\n";
    outfile << "Pole powierzchni figury dla C = 10: " << area << "\n";

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

float f_integral(float C) {
    float area = 0, x = 0, inter_len;
    unsigned int index;
    inter_len = C / INTER_NUM;

    for (index = 0; index < INTER_NUM; index++) {
        area += ((f(x) + f(x+inter_len)) * inter_len) / 2;
        x += inter_len;
    }

    return area;
}

float g_integral(float C) {
    float area = 0, x = 0, inter_len;
    unsigned int index;
    inter_len = C / INTER_NUM;

    for (index = 0; index < INTER_NUM; index++) {
        area += ((g(x) + g(x+inter_len)) * inter_len) / 2;
        x += inter_len;
    }

    return area;
}
