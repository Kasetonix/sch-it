#include <iostream>
using std::cout;
using std::cin;

int main() {
	int w = 5, h = 6, nums[w][h];

	/* generowanie tablicy sumując jej indeksy*/
	for (int i = 0; i < w; i++) {
		for (int j = 0; j < h; j++) {
			nums[i][j] = i + j;
		}
	}

	/* wypisywanie tablicy */
	for (int i = 0; i < w; i++) {
		for (int j = 0; j < h; j++) {
			cout << nums[i][j] << " ";
		}
		cout << "\n";
	}
}
