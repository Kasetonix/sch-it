#include <iostream>

using std::cout;

int main() {
    float c, c_sqrt, i_left, i_right;
    const float EPS = 0.00001;

    /* c to liczba pierwiastkowana */
    c = 3;

    i_left = 1;
    i_right = c;

    c_sqrt = (i_left + i_right) / 2;
    while (i_right - i_left > EPS) {
        if (c_sqrt * c_sqrt < c)
            i_left = c_sqrt;
        else
            i_right = c_sqrt;

        c_sqrt = (i_left + i_right) / 2;
    }

    cout << "c = " << c << " => sqrt(c) = " << c_sqrt << "\n";

    return 0;
}
