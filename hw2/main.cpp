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
	
	cout << "<AES>" << endl;
	
	AES aes;
	aes.CoutSetting();

	aes.AES_Encrypt();
	aes.AES_Decrypt();
	
	return 0;
}


