#include <iostream>
using std::cout;

int main() {
    unsigned short number;

    /* Pętla iterująca przez wszytkie liczby trzycyfrowe */
    for (number = 100; number <= 999; number++)
        /* Jeżeli pierwsza cyfra (dzielenie całkowite liczby trzycyfrowej
         * przez sto daje pierwszą liczbę) oraz ostatnia cyfra
         * (reszta z dzielenia liczby trzycyfrowej przez 10 daje ostatnią cyfrę) 
         * jest taka sama, to liczba trzycyfrowa jest liczbą palindromiczną
         * (Przy liczbach o nieparzystej liczbie cyfr środek nie ma znaczenia) */
        if (number / 100 == number % 10)
            cout << number << "\n";

	return 0;
}
