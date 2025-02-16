#include <iostream>
#include <fstream>
#include <algorithm>
#include <pthread.h>
using std::string;
using std::sort;
using std::cout;
using std::ifstream;
using std::ofstream;

const string INFILE = "prostokaty.txt";
const unsigned LEN = 5000;
const string OUTFILE = "wyniki4.txt";

struct Rect { unsigned height; unsigned width; };

void GetData(Rect rect[]);
void SortRects(Rect rect[]);
unsigned ConnectRects(Rect rect[], unsigned num);
void ReturnData(Rect rect[]);

int main() {
    Rect rect[LEN];
    unsigned index = 0;
    GetData(rect);
    SortRects(rect);
    ReturnData(rect);
    return 0;
}

void GetData(Rect rect[]) {
    unsigned index;
    ifstream infile;
    infile.open(INFILE);

    for (index = 0; index < LEN; ++index)
        infile >> rect[index].height >> rect[index].width;

    infile.close();
}

bool RectSorter(Rect const& left, Rect const& right) {
    if (left.height != right.height)
        return left.height < right.height;
    return left.width > right.width;
}

void SortRects(Rect rect[]) {
    sort(rect, rect + LEN, &RectSorter);
}

unsigned ConnectRects(Rect rect[], unsigned num) {
    unsigned index, r_index, c_width = 0, max_width = 0;

    for (index = 0; index < LEN - num; index++) {
        // Szukanie ciągu kolejnych łączalnych prostokątów
        if (rect[index].height != rect[index + num - 1].height)
            continue;

        // sumowanie kolejnych prostokątów
        for (r_index = 0; r_index < num; r_index++)
            c_width += rect[index + r_index].width;

        if (c_width > max_width)
            max_width = c_width;

        c_width = 0;

        // pomijanie sumowania prostokątów o takich samych wysokościach
        while (rect[index].height == rect[index + 1].height)
            index++;
    }

    return max_width;
}

void ReturnData(Rect rect[]) {
    unsigned index, chain_len, max_chain_len = 0;
    Rect last_in_chain;
    ofstream outfile;
    outfile.open(OUTFILE, std::ios::app);

    outfile << "\n" << "/// 4.3 ///" << "\n";
    outfile << "Najszerszy prostokąt złożony z dwóch innych:  " << ConnectRects(rect, 2) << "\n";
    outfile << "Najszerszy prostokąt złożony z trzech innych: " << ConnectRects(rect, 3) << "\n";
    outfile << "Najszerszy prostokąt złożony z pięciu innych: " << ConnectRects(rect, 5) << "\n";
    
    outfile.close();
}
