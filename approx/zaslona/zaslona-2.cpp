#include <cmath>
#include <iostream>
#include <fstream>

using std::ofstream;
using std::ios;
using std::sqrt;

const float INTER_NUM = 1000;

float f(float x);
float g(float x);
float curvelen(float (*f)(float), float l_index, float r_index);
int ceiling(float number);

int main() {
    float circumference, l_index, r_index;

    /* plik wyjściowy */
    ofstream outfile;
    outfile.open("wynik.txt", ios::app);

    /* początkowe wartości */
    l_index = 2.0; r_index = 10.0;
    circumference = 2 * (r_index - l_index) + f(r_index) - g(r_index);

    circumference += curvelen(f, l_index, r_index) + curvelen(g, l_index, r_index);

    outfile << "\n " << "/// 70.2 ///" << "\n";
    outfile << "Obwód: " << ceiling(circumference) << "\n";

    outfile.close();
    return 0;
}

float f(float x) {
    return x*x * ((2 * x*x - 5) / 1000) - 3.0/250;
}

float g(float x) {
    return x * ((-x*x) / 30 + 1.0/20) + 1.0/6;
}

/* Function calculating the length of the graph of a function in a given interval */
float curvelen(float (*f)(float), float l_index, float r_index) {
    int index;
    float x, delta_x, delta_y, curvelen = 0;

    x = l_index;
    delta_x = (r_index - l_index) / INTER_NUM;

    for (index = 0; index < INTER_NUM; index++) {
        delta_y = (*f)(x + delta_x) - (*f)(x);
        curvelen += sqrt( (delta_x * delta_x) + (delta_y * delta_y) );
        x += delta_x;
    }

    return curvelen;
}

int ceiling(float number) {
    return (int) number + 1;
}
