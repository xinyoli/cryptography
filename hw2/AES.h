 ///////////////////////////////////////////////////////////////////////////////
 // file: AES.h
 // Project: COM 5336 cyptography hw assignment2
 // Description: 
 //
 // Change history: Apr. 17, 2018 - file created.
 //
 ///////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <algorithm>
#include <numeric>
#include <iomanip>
#include <cstdlib>
#include <cmath>
#include <string>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdint.h>		// for uint8_t

using namespace std;


void InputFunction(uint8_t*);
void FprintfHex(uint8_t*);
// void InitByteArray(uint8_t*);


class AES{

private:
	int block_size_;
	int key_size_;
	int num_of_round_;
	uint8_t* plaintext_;
	uint8_t* key_;
	uint8_t* ciphertext_;
	
public:
	AES();
	
	void CoutSetting();
	void FprintfPlaintext();
	void FprintfKey();
	
	void InputPlaintext();
	void InputKey();
	
	

};

