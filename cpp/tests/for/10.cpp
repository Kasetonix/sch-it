#include <iostream>
using std::cout;

int main() {
	const int brickMass = 2;
	int layerBricks = 100, layer = 0, sumMass = 0;

	while (sumMass < 2000) { 
		layer++; 
		sumMass += brickMass * layerBricks;
		layerBricks--;
		if (sumMass > 2000) 
			layer--;
	}
	
	cout << "Liczba pełnych warstw muru zanim osiągnie on dwie tony wynosi " << layer << ".\n";

	return 0;
}
