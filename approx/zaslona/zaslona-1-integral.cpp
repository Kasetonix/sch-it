#include <iostream>
#include <cmath>
#include <vector>
using std::cout;
using std::pow;
using std::vector;

// coefficients are for monomials with rising degrees
// (0, 1, 2, ..., degree)
struct Polynomial {
    vector<float> coefficient;
    unsigned degree;
};

struct Interval {
    float l;
    float r;
};

void DisplayPolynomial(Polynomial polynomial);
Polynomial Antiderivative(Polynomial polynomial);
float MonomialValue(float x, float coefficient, unsigned degree);
float Integral(Polynomial antiderivative, Interval interval);

int main() {
    float area = 0;
    Interval interval;
    Polynomial f;
    
    // Defining f as a polynomial
    f.degree = 4; 
    f.coefficient.reserve(f.degree + 1);
    f.coefficient = { -3.0/250 - 1.0/6, -1.0/20, -1.0/200, 1.0/30, 1.0/500 };

    interval.l = 2.0;
    interval.r = 10.0;

    cout << "/// NORMALNIE ///" << "\n";
    DisplayPolynomial(f);
    cout << "\n";
    cout << "/// FUNKCJA PIERWOTNA ///" << "\n";
    DisplayPolynomial(Antiderivative(f));

    cout << "Pole pod wykresem: " << Integral(Antiderivative(f), interval) << "\n";

    return 0;
}

void DisplayPolynomial(Polynomial polynomial) {
    int power;
    for (power = polynomial.degree; power >= 0; power--) {
        if (power == 1) {
            cout << polynomial.coefficient[1] << "x + ";
            cout << polynomial.coefficient[0] << "\n";
            break;
        }

        cout << polynomial.coefficient[power] << "x^" << power << " + ";
    }
}

Polynomial Antiderivative(Polynomial polynomial) {
    unsigned power;
    Polynomial antiderivative;

    antiderivative.degree = polynomial.degree + 1;
    antiderivative.coefficient.reserve(antiderivative.degree + 1);
    
    // Calculating the new coefficients
    antiderivative.coefficient.push_back(0.0);
    for (power = 0; power < antiderivative.degree; power++)
        antiderivative.coefficient.push_back(polynomial.coefficient[power] / (power + 1));

    return antiderivative;
}

float MonomialValue(float x, float coefficient, unsigned degree) {
    return coefficient * pow(x, degree);
}

float Integral(Polynomial antiderivative, Interval interval) {
    float integral = 0;
    unsigned power;

    for (power = 0; power <= antiderivative.degree; power++)
        integral += MonomialValue(interval.r, antiderivative.coefficient[power], power) - 
                    MonomialValue(interval.l, antiderivative.coefficient[power], power);

    return integral;
}
