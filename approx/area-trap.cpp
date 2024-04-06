#include <iostream>
#include <cmath>

using std::cin;
using std::cout;

float f(float x);

int main() {
    float left_arg, right_arg, c_arg, inter_width, area, f1, f2;
    unsigned int inter_num, index;

    cout << "Podaj lewą krawędź przedziału:       "; cin >> left_arg;
    cout << "Podaj prawą krawędź przedziału:      "; cin >> right_arg;
    cout << "Podaj liczbę tworzonych przedziałów: "; cin >> inter_num;

    /* Wyznaczenie szerokości każdego przedziału (trapezu) */
    inter_width = (right_arg - left_arg) / inter_num;
    c_arg = left_arg;
    f1 = f(c_arg);

    /* Przechodzenie przez cały podany przedział i sumowanie pól trapezów */
    for (index = 1; index <= inter_num; index++) {
        c_arg += inter_width;
        /* Ustalenie wartości funkcji dla prawej krawędzi
         * (lewa pochodzi z poprzedniej iteracji) */
        f2 = f(c_arg);
        /* Wzór na pole trapezu - wysokość leży na osi Ox, a
         * długościami podstaw są wartości funkcji w danych punktach */
        area += ((f1 + f2) * inter_width) / 2;
        /* Zamiana poprzedniej prawej krawędzi na obecną lewą */
        f1 = f2;
    }

    cout << "Pole obszaru pod wykresem: " << area << "\n";
}

float f(float x) {
    return sin(x);
}
