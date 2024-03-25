#include <iostream>

using std::cout;

float absval(float x);

int main() {
    float side_a, side_b, area;
    const float EPS = 0.00001;

    area = 3;
    side_a = 1;
    side_b = area;

    while (absval(side_b - side_a) > EPS) {
        side_a = (side_a + side_b) / 2;
        side_b = area / side_a;
    }

    cout << "P = " << area << " => sqrt(P) = " << side_a << "\n";

    return 0;
}

float absval(float x) { return x < 0 ? -x : x; }
