 ///////////////////////////////////////////////////////////////////////////////
 // file: main.cpp
 // Project: COM 5336 cyptography hw assignment2
 // Description: 
 //
 // Change history: Apr. 18, 2018 - file created.
 //
 ///////////////////////////////////////////////////////////////////////////////

#include "AES.h"

using namespace std;


int main(int argc, char **argv){
	
	cout << "test.out start!!!" << endl;
	
	AES aes;
	aes.CoutSetting();
	
	uint8_t a = 0x8a;
	uint8_t b = 0x03;
	fprintf(stderr, "%02x + %02x = %02x\n", a,b,aes.GF256Add(a,b));
	fprintf(stderr, "GF256MultX(%02x) = %02x\n", a, aes.GF256MultX(a));
	fprintf(stderr, "GF256MultX(%02x) = %02x\n", b, aes.GF256MultX(b));
	fprintf(stderr, "GF256Mult(%02x,%02x) = %02x\n", a, b, aes.GF256Mult(a,b));
	fprintf(stderr, "GF256MxDiv(%02x) = %02x\n", a, aes.GF256MxDiv(a));
	fprintf(stderr, "GF256Inv(%02x) = %02x\n", a, aes.GF256Inv(a));
	fprintf(stderr, "CountBitOdd(%02x) = %d\n", a, aes.CountBitOdd(a));
	fprintf(stderr, "AffineTransf(%02x) = %02x\n", a, aes.AffineTransf(a));
	
	return 0;
}


