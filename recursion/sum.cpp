#include <iostream>
using std::cout;
using std::cin;

unsigned long long fibonacci_seq(unsigned int n);

int main() {
    cout << fibonacci_seq(4) << "\n";
    
    
    return 0;
}

unsigned long long fibonacci_seq(unsigned int n) {
    if (n == 0) return 0;
    else if (n == 1) return 1;
    else return fibonacci_seq(n - 2) + fibonacci_seq(n - 1);
}
