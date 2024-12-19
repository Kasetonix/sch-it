#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::string;
using std::getline;

int main() {
    string s;
    cout << "Podaj zdanie: "; getline(cin, s);
    cout << "Indeks pierwszego wystąpienia \"ma\":          " << s.find("ma") << "\n";
    cout << "Dwa znaki w czwartym indeksie:               " << s.substr(4, 2) << "\n";
    cout << "Usunięcie trzech znaków w czwartym indeksie: " << s.erase(4, 3) << "\n";
    cout << "Długość zdania:                              " << s.size() << "\n";

    return 0;
}
