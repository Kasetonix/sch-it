#include <iostream>
#include <fstream>
using std::cout;
using std::string;
using std::ifstream;
using std::ofstream;

const unsigned FILE_LEN = 1000;
void GetNums(unsigned nums[], string nums_s[], bool ints);
unsigned DigitSumInt(unsigned num);
unsigned DigitSumString(string num);
void ReturnAnswer(unsigned nums[], string nums_s[]);

int main() {
    unsigned nums[FILE_LEN];
    string nums_s[FILE_LEN];
    GetNums(nums, nums_s, true);
    GetNums(nums, nums_s, false);
    ReturnAnswer(nums, nums_s);

    return 0;
}

// Funkcja pobierająca liczby z pliku
void GetNums(unsigned nums[], string nums_s[], bool ints) {
    unsigned index;
    ifstream infile;
    infile.open("liczby.txt");
    if (!infile.good()) {
        cout << "Plik nie mógł być otwarty." << "\n";
        exit(1);
    }

    if (ints)
        for (index = 0; index < FILE_LEN; index++)
            infile >> nums[index];
    else 
        for (index = 0; index < FILE_LEN; index++)
            infile >> nums_s[index];

    infile.close();
}

// Funkcja zwracająca do pliku rozkład liczb na czynniki pierwsze
unsigned DigitSumInt(unsigned num) {
    unsigned sum = 0;
    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }

    return sum;
}

unsigned DigitSumString(string num) {
    unsigned index, sum = 0;
    for (index = 0; index < num.size(); index++)
        sum += num[index] - '0';
    return sum;
}

void ReturnAnswer(unsigned nums[], string nums_s[]) {
    ofstream outfile_i, outfile_s;
    outfile_i.open("sumacyf1.txt");
    outfile_s.open("sumacyf2.txt");
    if (!outfile_i.good() || !outfile_s.good()) {
        cout << "Pliki nie mogły być otwarte." << "\n";
        exit(1);
    }

    unsigned max_sum_i = 0, min_sum_i = 4294967295, max_sum_s = 0, min_sum_s = 4294967295;
    unsigned max_sum_i_num, min_sum_i_num, max_sum_s_num, min_sum_s_num;
    unsigned index;
    // Sprawdzanie minimów i maksimów sum cyfr w liczbach
    for (index = 0; index < FILE_LEN; index++) {
        if (DigitSumInt(nums[index]) > max_sum_i) {
            max_sum_i = DigitSumInt(nums[index]);
            max_sum_i_num = index;
        } 

        if (DigitSumString(nums_s[index]) > max_sum_s) {
            max_sum_s = DigitSumString(nums_s[index]);
            max_sum_s_num = index;
        }

        if (DigitSumInt(nums[index]) < min_sum_i) {
            min_sum_i = DigitSumInt(nums[index]);
            min_sum_i_num = index;
        }

        if (DigitSumString(nums_s[index]) < min_sum_s) {
            min_sum_s = DigitSumString(nums_s[index]);
            min_sum_s_num = index;
        }
    }

    outfile_i << "[INT]: Liczba o największej sumie cyfr --> " << max_sum_i_num << "\n";
    outfile_i << "       +--------------------> Suma cyfr -> " << max_sum_i << "\n";
    outfile_i << "       Liczba o najmniejszej sumie cyfr -> " << min_sum_i_num << "\n";
    outfile_i << "       +--------------------> Suma cyfr -> " << min_sum_i << "\n";

    cout << "[INT]: Liczba o największej sumie cyfr --> " << max_sum_i_num << "\n";
    cout << "       +-------------------> Suma cyfr -> " << max_sum_i << "\n";
    cout << "       Liczba o najmniejszej sumie cyfr -> " << min_sum_i_num << "\n";
    cout << "       +-------------------> Suma cyfr -> " << min_sum_i << "\n";

    outfile_s << "[STR]: Liczba o największej sumie cyfr --> " << max_sum_s_num << "\n";
    outfile_s << "       +-------------------> Suma cyfr -> " << max_sum_s << "\n";
    outfile_s << "       Liczba o najmniejszej sumie cyfr -> " << min_sum_s_num << "\n";
    outfile_s << "       +-------------------> Suma cyfr -> " << min_sum_s << "\n";

    cout << "[STR]: Liczba o największej sumie cyfr --> " << max_sum_s_num << "\n";
    cout << "       +-------------------> Suma cyfr -> " << max_sum_s << "\n";
    cout << "       Liczba o najmniejszej sumie cyfr -> " << min_sum_s_num << "\n";
    cout << "       +-------------------> Suma cyfr -> " << min_sum_s << "\n";

    outfile_i.close();
    outfile_s.close();
}
