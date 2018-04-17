 ///////////////////////////////////////////////////////////////////////////////
 // file: big_number.cpp
 // Project: COM 5336 cyptography assignment1
 // Description: 
 //
 // Change history: Mar. 13, 2018 - file created.
 //
 ///////////////////////////////////////////////////////////////////////////////
 
#include "big_number.h"

int HexCharToInt(char c)
{
    // TODO handle default / error
    switch(toupper(c))
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
        case 'A': return 10;
        case 'B': return 11;
        case 'C': return 12;
        case 'D': return 13;
        case 'E': return 14;
        case 'F': return 15;
    }
}


// initialize empty object to positive 0 with 1 bit
BigNumber::BigNumber(){
	sgn_ = true;		
	num_of_bits_ = 1;
	// data_ = new uint8_t[num_of_bits_];
	// data_[0] = 0;
	data_vect_.resize(num_of_bits_);
	data_vect_[0] = 1;
}

BigNumber::BigNumber(int number){
	
	if(number > 0){
		sgn_ = true;
	}else{
		sgn_ = false;
		number *= -1;
	}
	
	int num_of_bit = 0;
	int temp_num = number;
	while(temp_num != 0){
		++num_of_bit;
		temp_num >>= 1;
	}
	// cout << "num_of_bit = " << num_of_bit << endl;
	
	// data_ = new uint8_t[num_of_bit];	// bit width of int
	data_vect_.resize(num_of_bit);
	// for(int i=0; i<num_of_bit; i++){
		// data_[i] = 0;
	// }
	
	int current_bit = 0;
	while(number > 0){
		current_bit = (number & 0x01);
		data_vect_[num_of_bits_] = current_bit;
		number >>= 1;
		++num_of_bits_;
	}
	// cout << "num_of_bits_ = " << num_of_bits_ << endl;
}

BigNumber::BigNumber(bool sgn, unsigned int num_of_bits, vector<int>& data_vect){
	sgn_ = sgn;		
	num_of_bits_ = num_of_bits;
	// data_ = new uint8_t(*data);
	data_vect_.assign(data_vect.begin(), data_vect.end());
	
	// for(unsigned int i=0; i<num_of_bits; i++){
		// data_[i] = data[i];
	// }
}

BigNumber::BigNumber(char char_array[256]){
	sgn_ = true;
	int index = 0;
	while(char_array[index] != 0){
		++index;
	}
	num_of_bits_ = index*4;
	
	for(int i=index-1; i>=0; i--){
		
		int hex_number = HexCharToInt(char_array[i]);
		for(int i=0; i<4; i++){
			
			if(hex_number & 1){
				data_vect_.push_back(1);
			}else{
				data_vect_.push_back(0);
			}
			hex_number >>= 1;
		}
		
	}
	
}

// BigNumber::~BigNumber(){
	// delete []data_;
	// cout << "object has been deleted!\n";
// }

BigNumber BigNumber::operator+(BigNumber big_number){
	BigNumber big_sum;
	
}	

void BigNumber::Print(){
	
	if(sgn_){
		cout << "+";
	}else{
		cout << "-";
	}
	
	int index = (int)num_of_bits_;
	int remainder = index % 4;
	index -= remainder;
	// cout << "num_of_bits_ = " << num_of_bits_ << endl;
	// cout << "index = " << index << endl;
	// cout << "remainder = " << remainder << endl;
	
	int result_hex = 0;
	int base = 1;
	for(int i=0; i<remainder; i++){
		if(data_vect_[i+index] == 1){
			result_hex += base;
		}
		base *= 2;
	}
	if(remainder != 0){
		cout << hex << result_hex;
	}
	
	int num_of_hex = index / 4;
	// cout << "num_of_hex = " << num_of_hex << endl;
	for(int i=0; i<num_of_hex; i++){
		index -= 4;
		base = 1;
		result_hex = 0;
		for(int j=0; j<4; j++){
			if(data_vect_[j+index] == 1){
				result_hex += base;
			}
			base *= 2;
		}
		// cout << "i = " << i << endl;
		cout << hex << result_hex;
	}
	cout << endl;
	
	// for(int i=num_of_bits_-1; i>=0; i--){
		// cout << (int)data_vect_[i];
	// }
	// cout << endl;
}


