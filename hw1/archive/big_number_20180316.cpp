 ///////////////////////////////////////////////////////////////////////////////
 // file: big_number.cpp
 // Project: COM 5336 cyptography assignment1
 // Description: 
 //
 // Change history: Mar. 13, 2018 - file created.
 //
 ///////////////////////////////////////////////////////////////////////////////
 
#include "big_number.h"

// initialize empty object to positive 0 with 1 bit
BigNumber::BigNumber(){
	sgn_ = true;		
	num_of_bits_ = 1;
	data_ = new uint8_t[num_of_bits_];
	data_[0] = 0;
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
	
	data_ = new uint8_t[num_of_bit];	// bit width of int
	// for(int i=0; i<num_of_bit; i++){
		// data_[i] = 0;
	// }
	
	int current_bit = 0;
	while(number > 0){
		current_bit = (number & 0x01);
		data_[num_of_bits_] = (uint8_t)current_bit;
		number >>= 1;
		++num_of_bits_;
	}
	cout << "num_of_bits_ = " << num_of_bits_ << endl;
}

BigNumber::BigNumber(bool sgn, unsigned int num_of_bits, uint8_t* data){
	sgn_ = sgn;		
	num_of_bits_ = num_of_bits;
	// data_ = new uint8_t(*data);
	data_ = new uint8_t[num_of_bits];
	
	for(unsigned int i=0; i<num_of_bits; i++){
		data_[i] = data[i];
	}
}

BigNumber::~BigNumber(){
	delete []data_;
	// cout << "object has been deleted!\n";
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
	cout << "num_of_bits_ = " << num_of_bits_ << endl;
	cout << "index = " << index << endl;
	cout << "remainder = " << remainder << endl;
	
	int result_hex = 0;
	int base = 1;
	for(int i=0; i<remainder; i++){
		if(data_[i+index] == 1){
			result_hex += base;
		}
		base *= 2;
	}
	cout << hex << result_hex << " ";
	
	int num_of_hex = index / 4;
	cout << "num_of_hex = " << num_of_hex << endl;
	for(int i=0; i<num_of_hex; i++){
		index -= 4;
		base = 1;
		result_hex = 0;
		for(int j=0; j<4; j++){
			if(data_[j+index] == 1){
				result_hex += base;
			}
			base *= 2;
		}
		cout << "i = " << i << endl;
		// cout << hex << result_hex << " ";
	}
	cout << endl;
	
	// for(int i=num_of_bits_-1; i>=0; i--){
		// cout << (int)data_[i];
	// }
	// cout << endl;
}


