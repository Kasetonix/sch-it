#include <iostream>
#include <fstream>
using std::string;
using std::ifstream;
using std::ofstream;

const string INFILE = "prostokaty.txt";
const unsigned LEN = 5000;
const string OUTFILE = "wyniki4.txt";

struct Rect { unsigned height; unsigned width; };

void GetData(Rect rect[]);
bool RectFits(Rect rect_out, Rect rect_in);
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

bool RectFits(Rect rect_out, Rect rect_in) {
    return rect_out.height >= rect_in.height && rect_out.width >= rect_in.width;
}

void ReturnData(Rect rect[]) {
    unsigned index, chain_len, max_chain_len = 0;
    Rect last_in_chain;
    ofstream outfile;
    outfile.open(OUTFILE, std::ios::app);

    outfile << "\n" << "/// 4.2 ///" << "\n";
    
    for (index = 1; index < LEN; ++index) {
        // Pomijanie niepasujących
        if (!RectFits(rect[index - 1], rect[index])) {
            chain_len = 1;
            continue;
        }

        chain_len++;
        // Zapisywanie ostatniego prostokąta w ciągu
        if (chain_len > max_chain_len) {
            max_chain_len = chain_len;
            last_in_chain = rect[index];
        }
    }

    outfile << "Długość najdłuższego ciągu:      " << max_chain_len << "\n";
    outfile << "Wysokość ostatniego prostokąta:  " << last_in_chain.height << "\n";
    outfile << "Szerokość ostatniego prostokąta: " << last_in_chain.width << "\n";

    outfile.close();
}
