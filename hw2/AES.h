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
	uint8_t irr_poly_;
	uint8_t* plaintext_;
	uint8_t* key_;
	uint8_t* round_key_;
	uint8_t* ciphertext_;
	uint8_t* state_;
	
public:
	AES();
	
	uint8_t irr_poly();
	void CoutSetting();
	void FprintfPlaintext();
	void FprintfKey();
	void FprintfState();
	
	void InputPlaintext();
	void InputKey();
	
	// returns a + b.
	uint8_t GF256Add(uint8_t a, uint8_t b);
	// Multiplied by x. 
	uint8_t GF256MultX(uint8_t a);
	// General multiplication
	uint8_t GF256Mult(uint8_t a, uint8_t b);
	// return Mx divided by b;
	uint8_t GF256MxDiv(uint8_t b);
	// Returns the multiplicative inverse of a.
	uint8_t GF256Inv(uint8_t); 
	
	void AddRoundKey();
	bool CountBitOdd(uint8_t);
	uint8_t AffineTransf(uint8_t);
	void ByteSub();
	
	// void AES_Encrypt();
	// void AES_Decrypt(); 

};

