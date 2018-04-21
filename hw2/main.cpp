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
	
	// aes.InitState();
	// aes.InitRoundKey();
	// cout << "Init ";
	// aes.PrintfState();
	// aes.AddRoundKey();
	// cout << "S" << aes.round() << " ";
	// aes.PrintfState();
	// cout << "Round " << aes.round() << ": \n";
	// aes.ByteSub();
	// cout << "ByteSub ";
	// aes.PrintfState();
	// aes.ShiftRows();
	// cout << "ShiftRows ";
	// aes.PrintfState();
	// aes.MixColumns();
	// cout << "MixColumns ";
	// aes.PrintfState();

	aes.AES_Encrypt();
	
	return 0;
}


