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
	
	cout << "<AES Encryption>" << endl;
	aes.InputPlaintext();
	aes.FprintfPlaintext();
	aes.InputKey();
	aes.FprintfKey();
	
	aes.FprintfState();
	aes.AddRoundKey();
	aes.FprintfState();
	aes.ByteSub();
	aes.FprintfState();
	aes.ShiftRows();
	aes.FprintfState();

	
	return 0;
}


