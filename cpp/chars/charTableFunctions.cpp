#include <iostream>
#include <cstring>
using std::cout;
using std::strlen;
using std::strcpy;
using std::strcat;
using std::strcmp;

int main() {
	char table[] = " Ala ma kota :> ";
	char table1[48] = {0}, table2[32] = " Alek ma psa :) ";

	cout << "Tablica table:  " << table << "\n";
	cout << "Tablica table1: " << table1 << "\n";
	cout << "Tablica table2: " << table2 << "\n";

	/* Sprawdzanie długości tablicy [strlen] */
	cout << "Długość tablicy table: " << strlen(table) << "\n";

	/* kopiowanie tablicy do innej tablicy [strcpy] */
	strcpy(table1, table);
	cout << "table1 po skopiowaniu do niej wartości tablicy table: " << "\n" << table1 << "\n";

	/* konkatynacja dwóch tablic [strcat] */
	strcat(table2, table1);
	cout << "table2 po konkatynacji table2 i table1: " << "\n" << table2 << "\n";
	
	/* porównywanie dwóch tablic [strcmp]
	 * jeżeli tabele są równe, zwraca 0
	 * jeżeli pierwsza jest wcześniej alfabetycznie zwraca liczbę ujemną
	 * jeżeli pierwsza jest później alfabetycznie zwraca liczbę dodatnią */
	cout << "Czy table1 i table2 są takie same?: " << strcmp(table1, table2) << "\n";

	return 0;
}
