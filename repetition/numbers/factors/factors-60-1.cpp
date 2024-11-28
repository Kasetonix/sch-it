#include <iostream>
#include <fstream>
using std::cout;
using std::ifstream;
using std::ofstream;

const unsigned FILE_LEN = 200;
void GetNums(unsigned num[]);
void ReturnAnswer(unsigned num_lt1000, unsigned ans1, unsigned ans2);

int main() {
    unsigned num[200];
    unsigned index, counter = 0, ans1, ans2;
    GetNums(num);

    // Zliczanie liczb mniejszych od tysiąca
    for (index = 0; index < 200; index++) {
        if (num[index] >= 1000)
            continue;

        counter++;
        // Zachowywanie dwóch ostatnich liczb
        ans2 = ans1;
        ans1 = num[index];
    } 

    ReturnAnswer(counter, ans1, ans2);

    return 0;
}

// Funkcja otrzymująca dane z pliku
void GetNums(unsigned num[]) {
    unsigned index;
    ifstream infile;
    infile.open("liczby.txt");
    if (!infile.good()) {
        cout << "Plik wejściowy nie mógł być otwarty." << "\n";
        exit(1);
    }

    for (index = 0; index < FILE_LEN; index++) {
        infile >> num[index];
    }

    infile.close();
}

// Funkcja wypisująca odpowiedź do pliku
void ReturnAnswer(unsigned num_lt1000, unsigned ans1, unsigned ans2) {
    unsigned index;
    ofstream outfile;
    outfile.open("wyniki.txt", std::ios::app);
    if (!outfile.good()) {
        cout << "Plik wyjściowy nie mógł być otwarty." << "\n";
    }

    outfile << "/// 60.1 ///" << "\n";
    outfile << "    Liczba liczb mniejszych od tysiąca:       " << num_lt1000 << "\n";
    outfile << "    Ostatnia liczba mniejsza od tysiąca:      " << ans1 << "\n";
    outfile << "    Przedostatnia liczba mniejsza od tysiąca: " << ans2 << "\n";
    outfile << "\n";

    outfile.close();
}
