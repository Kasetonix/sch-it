/* 
 * nst.h [numbering systems translations]
 * bindec -> binary to decimal
 * decbin -> decimal to binary
*/

int bindec(long long bin) {
	long long dec = 0, currentBinPower = 0, currentDecNum = 1;

	while (bin > 0) {
		currentDecNum = 1; 
		for (long long i = currentBinPower; i > 0; i--)
			currentDecNum *= 2;
		dec += (bin % 10) * currentDecNum;
		bin /= 10;
		currentBinPower++;
	}

	return dec;
}
