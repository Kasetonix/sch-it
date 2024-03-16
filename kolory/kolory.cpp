#include <iostream>
#include <fstream>
#include <string>

using std::string;
using std::ifstream;
using std::ofstream;
using std::cout;

char GetPixel(unsigned int decimal, unsigned short index);

int main() {
    const unsigned int WIDTH = 96, HEIGTH = 96;
    unsigned int w = 0, h = 0, current_dec = 0, 
                 black_count = 0, white_count = 0,
                 current_chain = 0, longest_chain = 0;
    char pix_tab[HEIGTH][WIDTH];

    /* Pliki wejściowe */
    ifstream infile; ofstream outfile;
    infile.open("wuz2-zad1-obraz.txt");
    outfile.open("wynik.txt");
    if (!infile.good() || !outfile.good()) {
        cout << "Pliki nie mogły być otwarte." << "\n";
        return 1;
    }
    
    /* Wczytanie danych z pliku i tablicy */
    for (h = 0; h < HEIGTH; h++) {
        for (w = 0; w < WIDTH; w++) {
            /* Co czwartą iterację wczytanie nowej liczby z pliku */
            if (w % 4 == 0)
                infile >> current_dec;
            pix_tab[h][w] = GetPixel(current_dec, w % 4);
            
            /* Zliczanie białych i czarnych pikseli */
            if (pix_tab[h][w] == '0')
                black_count++;
            else if (pix_tab[h][w] == 'F')
                white_count++;
        }
    }

    outfile << "----- 1 -----" << "\n";
    outfile << "Liczba czarnych pikseli: " << black_count << "\n";
    outfile << "Liczba białych pikseli:  " << white_count << "\n";
    outfile << "\n";

    /* Szukanie najdłuższego ciągu znaków (w poziomie) */
    for (h = 0; h < HEIGTH; h++) {
        for (w = 0; w < WIDTH; w++) {
            if (pix_tab[h][w] == pix_tab[h][w + 1])
                current_chain++;
            else
                current_chain = 1;

            if (current_chain > longest_chain)
                longest_chain = current_chain;
        }
        /* Zerowanie licznika przy przejściu do następnej linijki */
        current_chain = 1;
    }

    outfile << "----- 2 -----" << "\n";
    outfile << "Najdłuższy ciąg (w poziomie): " << longest_chain << "\n";
    outfile << "\n";

    longest_chain = 1;
    current_chain = 1;
    /* Szukanie najdłuższego ciągu znaków (w pionie) */
    for (w = 0; w < WIDTH; w++) {
        for (h = 0; h < HEIGTH; h++) {
            if (pix_tab[h][w] == pix_tab[h + 1][w])
                current_chain++;
            else
                current_chain = 1;

            if (current_chain > longest_chain)
                longest_chain = current_chain;
        }
        /* Zerowanie licznika przy przejściu do następnej kolumny */
        current_chain = 1;
    }

    outfile << "----- 3 -----" << "\n";
    outfile << "Najdłuższy ciąg (w pionie): " << longest_chain << "\n";
    outfile << "\n";

    /* Wypisanie tablicy */
    /* for (h = 0; h < HEIGTH; h++) {
        for (w = 0; w < WIDTH; w++) {
            cout << pix_tab[h][w];
        }
        cout << "\n";
    } */

    return 0;
}

char GetPixel(unsigned int decimal, unsigned short index) {
	unsigned int currentDigit;
	string pixel = "";

	while (decimal > 0) {
		currentDigit = decimal % 16;

		if (currentDigit < 10)
			pixel = char ('0' + currentDigit) + pixel;
		else
			pixel = char ('A' - 10 + currentDigit) + pixel;
		
		decimal = decimal / 16;
	}

    for (int i = pixel.size(); i < 4 ; i++) {
        pixel = "0" + pixel;
    }

    return pixel[index];
}
