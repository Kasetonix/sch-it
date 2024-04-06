#include <iostream>
#include <cmath>

using std::cin;
using std::cout;

int main() {
    float left_arg, right_arg, c_arg, inter_width, area;
    unsigned int inter_num, index;

    cout << "Podaj lewą krawędź przedziału:       "; cin >> left_arg;
    cout << "Podaj prawą krawędź przedziału:      "; cin >> right_arg;
    cout << "Podaj liczbę tworzonych przedziałów: "; cin >> inter_num;

    /* Wyznaczenie szerokości każdego przedziału (prostokąta) */
    inter_width = (right_arg - left_arg) / inter_num;
    c_arg = left_arg;

    /* Przechodzenie przez cały podany przedział i sumowanie pól prostokątów */
    for (index = 1; index <= inter_num; index++) {
        c_arg += inter_width;
        area += inter_width * sin(c_arg);
    }

    cout << "Pole obszaru pod wykresem: " << area << "\n";
}
