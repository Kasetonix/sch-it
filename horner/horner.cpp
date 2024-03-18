#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::string;

int main() {
    unsigned int decimal = 0, base, index;
    string num;

    cout << "Podaj liczbę w systemie 2-10: "; cin >> num;
    cout << "Podaj podstawę tego systemu:  "; cin >> base;

    for (index = 0; index < num.size(); index++) {
        decimal = decimal * base + int(num[index] - '0');
    }

    cout << num << " (" << base << ") = " << decimal << " (10)" << "\n";

    return 0;
}
