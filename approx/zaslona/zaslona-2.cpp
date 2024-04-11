#include <cmath>
#include <iostream>
#include <fstream>

using std::ofstream;
using std::ios;
using std::sqrt;

const float INTER_NUM = 300;

float f(float x);
float g(float x);
float f_curvelen(float l_index, float r_index);
float g_curvelen(float l_index, float r_index);

int main() {
    float circumference, l_index, r_index;

    /* plik wyjściowy */
    ofstream outfile;
    outfile.open("wynik.txt", ios::app);

    /* początkowe wartości */
    l_index = 2.0; r_index = 10.0;
    circumference = 2 * (r_index - l_index) + f(r_index) - g(r_index);

    std::cout << "Obwód: " << circumference << "\n";
    circumference += f_curvelen(l_index, r_index) + g_curvelen(l_index, r_index);
    std::cout << "Obwód: " << circumference << "\n";

/*     outfile << "/// 70.2 ///" << "\n"; */
    outfile.close();
    return 0;
}

float f(float x) {
    return x*x * ((2 * x*x - 5) / 1000) - 3.0/250;
}

float g(float x) {
    return x * ((-x*x) / 30 + 1.0/20) + 1.0/6;
}

float f_curvelen(float l_index, float r_index) {
    int index;
    float x, delta_x, delta_y, curvelen;

    x = l_index;
    delta_x = (r_index - l_index) / INTER_NUM;

    for (index = 0; index < INTER_NUM; index++) {
        delta_y = f(x + delta_x) - f(x);
        curvelen += sqrt((delta_x * delta_x) + (delta_y * delta_y));
        x += delta_x;
    }

    return curvelen;
}

float g_curvelen(float l_index, float r_index) {
    int index;
    float x, delta_x, delta_y, curvelen;

    x = l_index;
    delta_x = (r_index - l_index) / INTER_NUM;

    for (index = 0; index < INTER_NUM; index++) {
        delta_y = g(x + delta_x) - g(x);
        curvelen += sqrt((delta_x * delta_x) + (delta_y * delta_y));
        x += delta_x;
    }

    return curvelen;
}
