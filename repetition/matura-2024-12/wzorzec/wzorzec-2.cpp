#include <fstream>
#include <iostream>
#include <vector>
using std::cout;
using std::vector;
using std::string;
using std::ifstream;
using std::ofstream;

const unsigned NUM = 10;
struct Set {
    unsigned sublen;
    string str;
};

void GetData(Set set[]);
bool MonoSubtext(string sub);
unsigned SubtextNum(Set set);

int main() {
    Set set[NUM];
    GetData(set);

    return 0;
}

void GetData(Set set[]) {
    ifstream infile;
    unsigned index;
    infile.open("szyfrogram.txt");
    if (!infile.good()) {
        cout << "Plik wejściowy nie mógł być otwarty." << "\n";
        exit(1);
    }

    for (index = 0; index < NUM; index++)
        infile >> set[index].sublen >> set[index].str;

    infile.close();
}

// Funkcja sprawdzająca czy podtekst składa się tylko z jednego znaku
bool MonoSubtext(string sub) {
    bool mono;
    unsigned index;

    for (index = 1; index < sub.size(); index++) {
        if (sub[index - 1] != sub[index]) {
            mono = false;
            break;
        }
    }

    return mono;
}

unsigned SubtextNum(Set set) {
    unsigned index, v_index, s_index;
    bool repeat, skip;
    string c_sub;
    vector<string> sub;

    // Pierwszy podtekst
    sub.push_back(set.str.substr(0, set.sublen));

    for (index = 0; index < set.str.size() - set.sublen; index++) {
        c_sub = set.str.substr(index, set.sublen);

        // Pomijanie podtekstów złożonych z jednego znaku
        skip = true;
        for (s_index = 1; s_index < c_sub.size(); s_index++) {
            if (c_sub[s_index - 1] != c_sub[s_index]) {
                skip = false;
                break;
            }
        }

        if (skip)
            continue;

        // Sprawdzanie, czy podtekst się powtarza
        // jeżeli repeat == true, to tak
        repeat = false;
        for (v_index = 0; v_index < sub.size(); v_index++) {
            if (sub[v_index] == c_sub) {
                repeat = true;
                break;
            }
        }

        // Pomijanie powtarzającego się podtekstu
        if (repeat)
            continue;

        sub.push_back(c_sub);
    }

    // Liczba unikatowych podtekstów
    return sub.size();
}
