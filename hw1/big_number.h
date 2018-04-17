 ///////////////////////////////////////////////////////////////////////////////
 // file: big_number.h
 // Project: COM 5336 cyptography assignment1
 // Description: 
 //
 // Change history: Mar. 13, 2018 - file created.
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

// transfer ascii to integer
int HexCharToInt(uint8_t);
// transfer integer to ascii
uint8_t IntToHexChar(int);

// one element for 4-bit number (one hexidacimal) 
class BigNumber{

public:
	//constructors 
	BigNumber();    
	BigNumber(int);  //directly convert from an int 
	BigNumber(bool, unsigned int, uint8_t*); 

	// convert a const BigNumber pointer to a BigNumber object
	BigNumber BigNumberConverter(BigNumber* const);
	// Left shift a BigNumber by a number
	BigNumber LeftShiftBigNumber(BigNumber&, int);
	
	//overloaded arithmetic operators as member functions 
	BigNumber operator+(BigNumber); 
	BigNumber operator-(BigNumber); 
	BigNumber operator*(BigNumber); 
	BigNumber operator/(BigNumber); 	//integer division: 3/2==1 
	BigNumber operator%(BigNumber); 

	//interface functions 
	bool sgn();
	unsigned int num_of_hex();
	uint8_t* data();
	void Print(); 
	void GetData(bool&, unsigned int&, uint8_t*);
   
private:
	bool sgn_; 						// ture for positive
	unsigned int num_of_hex_;		// recode number of hex digits
	uint8_t *data_;					// one bit for each element 

};

// compare the size of two BigNumber object
bool Compare(BigNumber&, BigNumber&);