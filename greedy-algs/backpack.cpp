#include <iostream>
#include <algorithm>
using std::cout;
using std::cin;
using std::sort;

// Przedmiot
struct Item {
    unsigned short val;
    unsigned short space;
    float v_s;
};

const unsigned ITEM_NUM = 6;

void AskForCrit(unsigned short &crit);
void Pack(Item item[], unsigned short quant[], unsigned short total_space, unsigned short crit);
unsigned short GetValue(Item item[], unsigned short quant[]);
void PrintItems(Item item[], unsigned short quant[]);

int main() {
    unsigned short crit, total_space = 23;
    unsigned short quant[ITEM_NUM] = { 0 };
    Item item[ITEM_NUM] = { 
        { 6, 6, 6.0/6.0 },
        { 4, 2, 4.0/2.0 },
        { 5, 3, 5.0/3.0 },
        { 7, 2, 7.0/2.0 }, 
        { 10, 3, 10.0/3.0 },
        { 2, 1, 2.0/1.0 } 
    };

    AskForCrit(crit);
    Pack(item, quant, total_space, crit);
    PrintItems(item, quant);
    cout << GetValue(item, quant) << "\n\n";

    return 0;
}

// Funckja pytająca o kryterium pakowania
void AskForCrit(unsigned short &crit) {
    cout << "Podaj kryterium pakowania:" << "\n";
    cout << "   1. Wartość" << "\n";
    cout << "   2. Objętość" << "\n";
    cout << "   3. Wartość / Objętość" << "\n";
    cout << "=> "; cin >> crit; cout << "\n";
}

// Funkcja porównania wartości dwóch przedmiotów
bool CompV(Item item_a, Item item_b) {
    return item_a.val > item_b.val;
}

// Funkcja porównania objętości dwóch przedmiotów
bool CompS(Item item_a, Item item_b) {
    return item_a.space < item_b.space;
}

// Funkcja porównania stosunku wartości do objętości dwóch przedmiotów
bool CompVS(Item item_a, Item item_b) {
    return item_a.v_s > item_b.v_s;
}

// Funckja sortująca tablicę zgodnie z wybranym kryterium
void SortItems(Item item[], unsigned short crit) {
    switch (crit) {
        case 1: // sortowanie wg value
            sort(item, item + ITEM_NUM, CompV);
            break;
        case 2: // sortowanie wg space 
            sort(item, item + ITEM_NUM, CompS);
            break;
        case 3: // sortowanie wg v_s 
            sort(item, item + ITEM_NUM, CompVS);
            break;
    }
}

// Funkcja pakująca plecak według danego kryterium
void Pack(Item item[], unsigned short quant[], unsigned short total_space, unsigned short crit) {
    unsigned short index;
    SortItems(item, crit);

    for (index = 0; index < ITEM_NUM; index++) {
        quant[index] = total_space / item[index].space;
        total_space %= item[index].space;
    }
}

// Funkcja obliczająca wartość plecaka
unsigned short GetValue(Item item[], unsigned short quant[]) {
    unsigned short value = 0, index;
    for (index = 0; index < ITEM_NUM; index++)
        value += quant[index] * item[index].val;
    
    return value;
}

// Funkcja wypisująca tablicę przedmiotów
void PrintItems(Item item[], unsigned short quant[]) {
    unsigned short index;

    for (index = 0; index < ITEM_NUM; index++) {
        cout << quant[index] << " x " 
             << "{ " << item[index].val<< ", " << item[index].space << ", " << item[index].v_s << " }" << "\n";
    }
}
