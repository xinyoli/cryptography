 ///////////////////////////////////////////////////////////////////////////////
 // file: big_number.cpp
 // Project: COM 5336 cyptography assignment1
 // Description: 
 //
 // Change history: Mar. 13, 2018 - file created.
 //
 ///////////////////////////////////////////////////////////////////////////////
 
#include "big_number.h"

int HexCharToInt(uint8_t c)
{
    //TODO handle default / error
    switch(tolower(c))
    {
        case '0': return 0;
        case '1': return 1;
        case '2': return 2;
        case '3': return 3;
        case '4': return 4;
        case '5': return 5;
        case '6': return 6;
        case '7': return 7;
        case '8': return 8;
        case '9': return 9;
        case 'a': return 10;
        case 'b': return 11;
        case 'c': return 12;
        case 'd': return 13;
        case 'e': return 14;
        case 'f': return 15;
		default: return 0;
    }
}

uint8_t IntToHexChar(int number){
	switch(number)
    {
        case 0:  return '0';
        case 1:  return '1';
        case 2:  return '2';
        case 3:  return '3';
        case 4:  return '4';
        case 5:  return '5';
        case 6:  return '6';
        case 7:  return '7';
        case 8:  return '8';
        case 9:  return '9';
        case 10: return 'a';
        case 11: return 'b';
        case 12: return 'c';
        case 13: return 'd';
        case 14: return 'e';
        case 15: return 'f';
		default: return '0';
    }
}

// initialize empty object to positive 0 with 1 bit
BigNumber::BigNumber(){
	sgn_ = true;		
	num_of_bits_ = 1;
	data_ = static_cast<uint8_t*>(malloc(num_of_bits_*sizeof(uint8_t)));
	data_[0] = 0;
}

BigNumber::BigNumber(int number){
	
	num_of_bits_ = 0;
	if(number < 0){
		number *= -1;
		sgn_ = false;
	}else{
		sgn_ = true;
	}
	
	fprintf(stderr, "BigNumber(int %d)\n", number);
	// int type: 32 bitset
	data_ = static_cast<uint8_t*>(malloc(32*sizeof(uint8_t)));
	
	int tmp = number;
	int index = 0;
	while(tmp > 0){
		// fprintf(stderr, "num_of_bits_ = %d)\n", num_of_bits_);
		// fprintf(stderr, "tmp = %d)\n", tmp);
		data_[index] = (tmp % 16);
		// fprintf(stderr, "data_[num_of_bits_] = %d\n", tmp % 16);
		// fprintf(stderr, "data_[num_of_bits_] = %d\n", IntToHexChar(tmp % 16));
		// fprintf(stderr, "data_[num_of_bits_] = %d\n", data_[num_of_bits_]);
		
		tmp >>= 4;
		++index;
	}
	num_of_bits_ =  
	data_ = static_cast<uint8_t*>(malloc(num_of_bits_*sizeof(uint8_t)));
}

void BigNumber::Print(){
	if(!sgn_){
		fprintf(stderr, "-");
	}
	int i = num_of_bits_ / 4 + 1;
	for(i = i -1; i>0; i--){
		fprintf(stderr, "%d", data_[i]);
	}
	fprintf(stderr, "%d\n", data_[i]);
}
