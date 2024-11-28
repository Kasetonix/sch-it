#include <iostream>
#include <fstream>
using std::cout;
using std::ifstream;
using std::ofstream;

const unsigned FILE_LEN = 1000;
void GetArray(unsigned num[]);
unsigned DigitProduct(unsigned num);
unsigned NumPower(unsigned num);
void ReturnAnswer(unsigned num[]);

int main() {
    unsigned num[FILE_LEN];
    GetArray(num);
    ReturnAnswer(num);

    return 0;
}

// Funkcja otrzymująca liczby z pliku
void GetArray(unsigned num[]) {
    unsigned index;
    ifstream infile;
    infile.open("liczby.txt");
    if (!infile.good()) {
        cout << "Plik wejściowy nie mógł by otwarty." << "\n";
        exit(1);
    }

    for (index = 0; index < FILE_LEN; index++)
        infile >> num[index];
}

unsigned DigitProduct(unsigned num) {
    unsigned product = 1;
    while (num > 0) {
        product *= num % 10;
        num /= 10;
    }
    return product;
}

unsigned NumPower(unsigned num) {
    unsigned counter = 0;
    while (num >= 10) {
        num = DigitProduct(num);
        counter++;

    }
    return counter;
}

void ReturnAnswer(unsigned num[]) {
    ofstream outfile;
    unsigned index, max_power_1 = 0, min_power_1 = 4294967295;
    unsigned counter[10];
    for (index = 0; index < 10; index++) {
        counter[index] = 0;
    }

    outfile.open("wyniki_liczby.txt", std::ios::app);
    if (!outfile.good()) {
        cout << "Plik wyjściowy nie mógł być otwarty." << "\n";
        exit(1);
    }

    for (index = 0; index < FILE_LEN; index++) {
        counter[NumPower(num[index])]++;
        if (NumPower(num[index]) == 1) {
            if (num[index] > max_power_1)
                max_power_1 = num[index];
            if (num[index] < min_power_1)
                min_power_1 = num[index];
        }
    }

    cout << "3: " << "\n";
    for (index = 1; index <= 8; index++)
        cout << "    Moc " << index << ": " << counter[index] << "\n";

    cout << "    MAX: " << max_power_1 << "\n";
    cout << "    MIN: " << min_power_1 << "\n";
}
