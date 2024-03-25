#include <iostream>

using std::cout;

float f(float x);
float absval(float num);

int main() {
    /* Dokładność */
    const float EPS = 0.00001;
    float i_center, i_left, i_right, i_left_init, i_right_init;

    i_left_init = 2; i_left = 2;
    i_right_init = 4; i_right = 4;

    /* Początkowy indeks środka przedziału [i_left; i_right] */
    i_center = (i_left + i_right) / 2;

    /* Sprawdzanie, czy warunki bisekcji są spełnione */
    if (f(i_left) * f(i_right) >= 0) {
        cout << "Warunki bisekcji nie są spełnione:" << "\n";
        cout << "→ Wartości dla krańców przedziału mają ten sam znak." << "\n";
        return 1;
    }

    /* Wykonwyanie algorytmu dopóki nie znajdziemy dokładnego miejsca zerowego
     * lub osiągniemy określoną precyzję (dł. przedziału mniejsza od epsilon) */
    while (absval(f(i_center)) > EPS && i_right - i_left > EPS) {
        /* Dla m.z. znajdującego się po lewej stronie od środka
         * Indeks prawej strony przedziału zastępowany jest indeksem środka:
         * Przedział zmniejszamy dwukrotnie, ale m.z. nadal do niego należy */
        if (f(i_center) * f(i_left) < 0)
            i_right = i_center;
        /* Analogicznie dla m.z. znajdującego się po prawej stronie od środka */
        else if (f(i_center) * f(i_right) < 0)
            i_left = i_center;

        i_center = (i_left + i_right) / 2;
    }

    cout << "Miejsce zerowe tej funkcji w przedziale [" << i_left_init << "; " << i_right_init << "]: " << i_center << "\n";

    return 0;
}

/* ¼x² - 2 */
float f(float x) {
    return 0.25 * x * x - 2; 
}

/* Calculates absolute value of a float */
float absval(float num) {
    if (num < 0)
        return -num;
    return num;
}
