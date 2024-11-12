#include <fstream>
#include <iostream>
using std::cout;
using std::ifstream;
using std::ofstream;

bool isPrime(unsigned int num);

int main() {
    ifstream infile;
    ofstream outfile;
    unsigned short prime_counter;
    unsigned int num;

    // Sprawdzenie poprawności otwarcia pliku
    infile.open("liczby.txt");
    outfile.open("pierwsze.txt");
    if (!infile.good() || !outfile.good()) {
        cout << "Pliki nie mógły być otwarte." << "\n";
        return 1;
    }
    
    // Iteracja przez wszystkie liczby z pliki i sprawdzanie pierwszeństwa
    while (infile >> num) {
        if (isPrime(num)) {
            outfile << num << "\n";
            prime_counter++;
        }
    }
    outfile << "Liczba liczb pierwszych: " << prime_counter << "\n";

    return 0;
}

bool isPrime(unsigned int num) {
    unsigned short div_counter, index;
    
    // Najmniejszą liczbą pierwszą jest dwa
    if (num < 2) 
        return false;

    // Sprawdzenie każdej liczby do pierwiastka sprawdzanej
    for (index = 2; index * index <= num; index++) {
        if (num % index == 0)
            div_counter++;
    }
    
    if (div_counter == 0)
        return true;
    return false;
}
