#include <iostream>
using std::cout;

int main() {
	int sumBricks = 0, layer = 10;
	
	for (layer; layer > 0; layer--) {
		cout << "Liczba cegieł w tej warstwie: " << layer*layer << ".\n";
		sumBricks += layer*layer;
	}

	cout << "Suma cegieł w piramidzie o podstawie 10x10 wynosi " << sumBricks << ".\n";

	return 0;
}
