#include <iostream>
#include <fstream>

using std::ofstream;
using std::ios;

const float MAT_WIDTH = 0.25;

float f(float x);
float g(float x);
float GetLen(float index);

int main() {
    float l_index, r_index, index;
    int mat_len = 0;

    /* plik wyjściowy */
    ofstream outfile;
    outfile.open("wynik.txt", ios::app);

    /* początkowe wartości */
    l_index = 2.0; r_index = 10.0;

    for (index = r_index - MAT_WIDTH; index >= l_index; index -= MAT_WIDTH) {
        mat_len += (int) GetLen(index); 
    }

    outfile << "\n" << "/// 70.3 ///" << "\n";
    outfile << "Długość pasów: " << mat_len << "\n";

    outfile.close();
    return 0;
}

float f(float x) {
    return x*x * ((2 * x*x - 5) / 1000) - 3.0/250;
}

float g(float x) {
    return x * ((-x*x) / 30 + 1.0/20) + 1.0/6;
}

float GetLen(float x) {
    return (f(x) - g(x));
}
