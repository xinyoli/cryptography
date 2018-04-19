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
	
	cout << "main.out start!!!" << endl;
	
	AES aes;
	aes.CoutSetting();
	
	// cout << "<AES Encryption>" << endl;
	// aes.InputPlaintext();
	// aes.FprintfPlaintext();
	// aes.InputKey();
	// aes.FprintfKey();
	
	uint8_t a = 7;
	uint8_t b = 15;
	fprintf(stderr, "%02x + %02x = %02x\n", a,b,GF256Add(a,b));
	
	return 0;
}


