#include <cstdint>
#include <iostream>
#include <fstream>
using std::cout;
using std::string;
using std::ifstream;
using std::ofstream;

const string INFILE = "prostokaty.txt";
const unsigned LEN = 5000;
const string OUTFILE = "wyniki4.txt";

struct Rect { unsigned height; unsigned width; };

void GetData(Rect rect[]);
unsigned long long Area(Rect rect);
void ReturnData(Rect rect[]);

int main() {
    Rect rect[LEN];
    GetData(rect);
    ReturnData(rect);
    return 0;
}

void GetData(Rect rect[]) {
    unsigned index;
    ifstream infile;
    infile.open(INFILE);

    for (index = 0; index < LEN; ++index) {
        infile >> rect[index].height >> rect[index].width;
    }

    infile.close();
}

unsigned long long Area(Rect rect) {
    return rect.height * rect.width;
}

void ReturnData(Rect rect[]) {
    unsigned index;
    unsigned long long area, min_area = INT64_MAX, max_area = 0;
    ofstream outfile;
    outfile.open(OUTFILE, std::ios::app);


    outfile << "/// 4.1 ///" << "\n";
    for (index = 0; index < LEN; ++index) {
        area = Area(rect[index]);
        if (area > max_area)
            max_area = area;
        else if (area < min_area)
            min_area = area;
    }
    outfile << "Największe pole:  " << max_area << "\n";
    outfile << "Najmniejsze pole: " << min_area << "\n";

    outfile.close();
}
