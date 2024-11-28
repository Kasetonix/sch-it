#include <iostream>
#include <fstream>
#include <vector>
using std::cout;
using std::vector;
using std::ifstream;
using std::ofstream;

struct Num {
    unsigned value;
    vector<unsigned> factor;
    unsigned fn; // Liczba dzielników
};

const unsigned FILE_LEN = 200;
void GetNums(Num num[]);
Num GetFactors(Num num);
unsigned NWD(unsigned a, unsigned b);
bool IsCoprime(Num num[], unsigned index);
void ReturnAnswer(unsigned max_coprime);

int main() {
    unsigned index, max_coprime = 0;
    Num num[FILE_LEN];
    GetNums(num);

    // Uzupełnienie structa
    for (index = 0; index < FILE_LEN; index++)
        num[index] = GetFactors(num[index]);

    for (index = 0; index < FILE_LEN; index++) {
        if (!IsCoprime(num, index))
            continue;
        if (num[index].value > max_coprime)
            max_coprime = num[index].value;
    }

    ReturnAnswer(max_coprime);

    return 0;
}

// Funkcja otrzymująca dane z pliku
void GetNums(Num num[]) {
    unsigned index;
    ifstream infile;
    infile.open("liczby.txt");
    if (!infile.good()) {
        cout << "Plik wejściowy nie mógł być otwarty." << "\n";
        exit(1);
    }

    for (index = 0; index < FILE_LEN; index++) {
        infile >> num[index].value;
    }

    infile.close();
}

// Funkcja wykonująca faktoryzację
Num GetFactors(Num num) {
    unsigned factor;
    for (factor = 1; factor <= num.value; factor++)
        if (num.value % factor == 0)
            num.factor.push_back(factor);

    // Ostatnim dzielnikiem jest dana liczba
    num.fn = num.factor.size();
    num.factor[num.fn] = num.value;

    return num;
}

// Algorytm Euklidesa (z modulo)
// NWD(a, b) = NWD(b, a % b)
unsigned NWD(unsigned a, unsigned b) {
    unsigned mod;
    while (b != 0) {
        mod = a % b;
        a = b;
        b = mod;
    }
    return a;
}

// Funkcja sprawdzająca, czy liczba jest względnie pierwsza z każdą inną
bool IsCoprime(Num num[], unsigned index) {
    unsigned i; // index
    
    // Liczba 1 jest względnie pierwsza z każdą inną
    if (num[index].value == 1)
        return true;

    for (i = 0; i < FILE_LEN; i++) {
        // Żadna liczba (poza jeden) nie jest względnie pierwsza ze sobą
        if (i == index)
            continue;

        // Jeżeli liczby są ze sobą względnie pierwsze,
        // to ich NWD równa się 1
        if (NWD(num[index].value, num[i].value) != 1)
            return false;
    }
    // Jeżeli NWD każdej liczby z tablicy i danej liczby jest równe 1,
    // to znaczy że dana liczba jest względnie pierwsza z każdą inną
    return true;
}

// Funkcja wypisująca odpowiedź do pliku
void ReturnAnswer(unsigned max_coprime) {
    unsigned index, f_index;
    ofstream outfile;
    outfile.open("wyniki.txt", std::ios::app);
    if (!outfile.good()) {
        cout << "Plik wyjściowy nie mógł być otwarty." << "\n";
    }

    outfile << "/// 60.3 ///" << "\n";
    outfile << "    Maksymalna liczba względnie pierwsza ze wszystkimi innymi: " << max_coprime << "\n";

    outfile.close();
}
