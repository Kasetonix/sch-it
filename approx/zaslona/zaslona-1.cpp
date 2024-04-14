#include <iostream>
#include <fstream>

using std::ofstream;
using std::ios;

float f(float x);
float g(float x);
float integral(float (*f)(float), float left_arg, float right_arg, float inter_num);

int main() {
    const float INTER_NUM = 300;
    float area, l_index, r_index;
    area = 0.0;
    l_index = 2.0; r_index = 10.0;

    /* plik wyjściowy */
    ofstream outfile;
    outfile.open("wynik.txt", ios::app);

    area += integral(f, l_index, r_index, INTER_NUM);
    area -= integral(g, l_index, r_index, INTER_NUM);

    outfile << "/// 70.1 ///" << "\n";
    outfile << "Pole obszaru pod wykresem: " << area << "\n";

    outfile.close();
    return 0;
}

float f(float x) {
    return x*x * ((2 * x*x - 5) / 1000) - 3.0/250;
}

float g(float x) {
    return x * ((-x*x) / 30 + 1.0/20) + 1.0/6;
}

float integral(float (*f)(float), float left_arg, float right_arg, float inter_num) {
    unsigned int index;
    float inter_width, c_arg, f1, f2, area;
    area = 0;

    /* Wyznaczenie szerokości każdego przedziału (trapezu) */
    inter_width = (right_arg - left_arg) / inter_num;
    c_arg = left_arg;
    f1 = f(c_arg);

    /* Przechodzenie przez cały podany przedział i sumowanie pól trapezów */
    for (index = 1; index <= inter_num; index++) {
        c_arg += inter_width;
        f2 = f(c_arg);
        area += ((f1 + f2) * inter_width) / 2;
        f1 = f2;
    }

    return area;
}
