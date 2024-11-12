#include <iostream>
using std::cout;
using std::cin;

unsigned long long factorial_rec(unsigned short n);
unsigned long long factorial_iter(unsigned short n);

int main() {
    unsigned short n;
    cout << "Podaj argument silni: "; cin >> n;
    cout << n << "! = " << factorial_rec(n) << "    [REC]" << "\n";
    cout << n << "! = " << factorial_iter(n) << "    [ITER]" << "\n";

    return 0;
}

unsigned long long factorial_rec(unsigned short n) {
    if (n <= 1) 
        return 1;
    else 
        return factorial_rec(n - 1) * n;
}

unsigned long long factorial_iter(unsigned short n) {
    unsigned short index;
    unsigned int factorial = 1;

    for (index = 2; index <= n; index++)
        factorial *= index;

    return factorial;
}
