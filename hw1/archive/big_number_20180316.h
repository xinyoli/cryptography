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
#include <ctime>
#include <bitset>
#include <fstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <math.h>
#include <time.h>
#include <stdint.h>		// for uint8_t

using namespace std;

// #define _DEBUG			// enable debug mode

// debug mode
#ifdef _DEBUG
#define LOG_MSG(...) printf(__VA_ARGS__)
#else
#define LOG_MSG(...)
#endif

// one element for 4-bit number (one hexidacimal) 
class BigNumber{

public:
	//constructors 
	BigNumber();  
	BigNumber(int);  //directly convert from an int 
	BigNumber(bool, unsigned int, vector<int>*); 
	
	~BigNumber();

	//overloaded arithmetic operators as member functions 
	// BigNumber operator+(BigNumber); 
	// BigNumber operator-(BigNumber); 
	// BigNumber operator*(BigNumber); 
	// BigNumber operator/(BigNumber); //integer division: 3/2==1 
	// BigNumber operator%(BigNumber); 

	//interface functions 
	void Print(); 
	// void GetData(bool& ,unsigned int& , uint8_t*);
   
private:
	bool sgn_; 						// ture for positive
	unsigned int num_of_bits_; 
	// unsigned int num_of_bytes_;
	// uint8_t *data_;					// one bit for each element 
	vector<int> data_vect_;

};

