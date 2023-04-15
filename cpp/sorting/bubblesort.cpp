#include <iostream>
#include <cwchar>
#include <typeinfo>
using std::cout;

void bsort(int array[]);

int main() {
    int array[] = { 5, 3, 8, 7 };
    unsigned int arrayLen = (sizeof(array) / sizeof(typeid(array).name()));

    return 0;
}

void bsort(int array[], unsigned int arrayLen) {
    int tmp;

    for (int sortedNum = 0; sortedNum < arrayLen; sortedNum++) {
        for (int comparison = 0; comparison < arrayLen - sortedNum; comparison++) {
            if (array[comparison] > array[comparison + 1]) {
                tmp = array[comparison];    
                array[comparison + 1] = array[comparison];
                array[comparison] = tmp;
            }
        }
    }
}
