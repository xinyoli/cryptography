 ///////////////////////////////////////////////////////////////////////////////
 // file: big_number.cpp
 // Project: COM 5336 cyptography assignment1
 // Description: 
 //
 // Change history: Mar. 13, 2018 - file created.
 // 				Mar. 22, 2018 - file modified.
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
	num_of_hex_ = 1;
	data_ = static_cast<uint8_t*>(malloc(num_of_hex_*sizeof(uint8_t)));
	data_[0] = 0;
}

BigNumber::BigNumber(int number){
	
	num_of_hex_ = 0;
	int tmp = number;
	if(tmp < 0){
		tmp *= -1;
		sgn_ = false;
	}else{
		sgn_ = true;
	}
	
	// int type: 32 bits
	data_ = static_cast<uint8_t*>(malloc(8*sizeof(uint8_t)));
	
	while(tmp > 0){
		
		data_[num_of_hex_] = (tmp % 16);
		// fprintf(stderr, "data_[%d] = %d\n", num_of_hex_, data_[num_of_hex_]);
		
		tmp >>= 4;
		++num_of_hex_;
	} 
	data_ = static_cast<uint8_t*>(realloc(data_, num_of_hex_*sizeof(uint8_t)));
}

BigNumber::BigNumber(bool sgn, unsigned int num_of_hex, uint8_t* data){
	sgn_ = sgn;
	num_of_hex_ = num_of_hex;

	data_ = static_cast<uint8_t*>(malloc(num_of_hex_*sizeof(uint8_t)));
	for(unsigned int i=0; i<num_of_hex_; i++){
		data_[i] = HexCharToInt(data[num_of_hex_-i-1]);
	}
}

BigNumber BigNumber::BigNumberConverter(BigNumber* const big){
	BigNumber tmp;
	tmp.sgn_ = big->sgn_;
	tmp.num_of_hex_ = big->num_of_hex_;
	tmp.data_ = big->data_;
	return tmp;
}	

BigNumber BigNumber::operator+(BigNumber b){
	
	BigNumber c;
	
	unsigned int max_num_of_hex = (this->num_of_hex_ > b.num_of_hex_) ? (this->num_of_hex_) : (b.num_of_hex_);
	
	c.data_ = static_cast<uint8_t*>(malloc((max_num_of_hex+1)*sizeof(uint8_t)));
	
	int carry = 0;
	for(unsigned int i=0; i<max_num_of_hex; i++){
		uint8_t tmp_a, tmp_b;
		tmp_a = ( ( i >= this->num_of_hex_) ? 0 : this->data_[i]);
		tmp_b = ( ( i >= b.num_of_hex_) 	? 0 : b.data_[i]);
		
		c.data_[i] = (tmp_a + tmp_b + carry) % 16;
		carry = (tmp_a + tmp_b + carry) / 16;
	}
	if(carry > 0){
		c.data_[max_num_of_hex] = carry;
		++max_num_of_hex;
	}
	c.num_of_hex_ = max_num_of_hex;
	c.data_ = static_cast<uint8_t*>(realloc(c.data_, c.num_of_hex_*sizeof(uint8_t)));
	
	return c;
}

BigNumber BigNumber::operator-(BigNumber b){
		
	BigNumber c;
	
	if(this->num_of_hex_ == b.num_of_hex_){	
		
		int index = this->num_of_hex_;
		while((data_[index-1] == b.data_[index-1]) && (index > 0)){
			--index;
		}
		
		if(index == 0){				// a equal b
			c.num_of_hex_ = 1;
			c.data_ = static_cast<uint8_t*>(realloc(c.data_, 1*sizeof(uint8_t)));
			c.data_[0] = 0;
			return c;
		}
		
		if(this->data_[index-1] < b.data_[index-1]){
			c.sgn_ = false;
		}
		c.num_of_hex_ = index;
		c.data_ = static_cast<uint8_t*>(realloc(c.data_, c.num_of_hex_*sizeof(uint8_t)));
		
	}else if(this->num_of_hex_ < b.num_of_hex_){
		c.sgn_ = false;
		c.num_of_hex_ = b.num_of_hex_;
		c.data_ = static_cast<uint8_t*>(realloc(c.data_, c.num_of_hex_*sizeof(uint8_t)));
	}else{
		c.num_of_hex_ = this->num_of_hex_;
		c.data_ = static_cast<uint8_t*>(realloc(c.data_, c.num_of_hex_*sizeof(uint8_t)));
	}
	
	unsigned int max_num_of_hex;
	if(c.sgn_){			// a - b
		max_num_of_hex = this->num_of_hex_;
		c.data_ = static_cast<uint8_t*>(realloc(c.data_,(max_num_of_hex)*sizeof(uint8_t)));
		
		int sub = 0;
		for(unsigned int i=0; i<max_num_of_hex; i++){
			int tmp_a, tmp_b, tmp_c;
			tmp_a = ( ( i >= this->num_of_hex_) ? 0 : this->data_[i]);
			tmp_b = ( ( i >= b.num_of_hex_) 	? 0 : b.data_[i]);
			tmp_c = tmp_a - tmp_b - sub;
			if(tmp_c < 0){
				sub = 1;
				tmp_c += 16;
			}else{
				sub = 0;
			}
			c.data_[i] = tmp_c;
		}
		if(c.data_[c.num_of_hex_-1] == 0){
			--c.num_of_hex_;
			c.data_ = static_cast<uint8_t*>(realloc(c.data_, c.num_of_hex_*sizeof(uint8_t)));
		}
		
	}else{				// b - a 
		max_num_of_hex = b.num_of_hex_;
		c.data_ = static_cast<uint8_t*>(malloc((max_num_of_hex)*sizeof(uint8_t)));
		
		int sub = 0;
		for(unsigned int i=0; i<max_num_of_hex; i++){
			int tmp_a, tmp_b, tmp_c;
			tmp_a = ( ( i >= this->num_of_hex_) ? 0 : this->data_[i]);
			tmp_b = ( ( i >= b.num_of_hex_) 	? 0 : b.data_[i]);
			tmp_c = tmp_b - tmp_a - sub;
			if(tmp_c < 0){
				sub = 1;
				tmp_c += 16;
			}else{
				sub = 0;
			}
			c.data_[i] = tmp_c;
		}
		if(c.data_[c.num_of_hex_-1] == 0){
			--c.num_of_hex_;
			c.data_ = static_cast<uint8_t*>(realloc(c.data_, c.num_of_hex_*sizeof(uint8_t)));
		}
	}
	
	return c;
}

BigNumber BigNumber::operator*(BigNumber b){
	
	BigNumber c;
	unsigned int max_of_hex = this->num_of_hex_ + b.num_of_hex_;		// the initial size of the result
	c.data_ = static_cast<uint8_t*>(malloc(max_of_hex*sizeof(uint8_t)));
	c.num_of_hex_ = max_of_hex;
	memset(c.data_, 0, max_of_hex);
	
	int carry = 0;
	for(unsigned int i=0; i<this->num_of_hex_; i++){
		
		carry = 0;
		int tmp = 0;
		for(unsigned int j=0; j<b.num_of_hex_; j++){

			tmp = c.data_[i+j];
			c.data_[i+j] = (tmp + (this->data_[i] * b.data_[j] + carry)) % 16;
			
			carry = (this->data_[i] * b.data_[j] + carry + tmp) / 16;
		}
		c.data_[i+b.num_of_hex_] += carry;
	}
	if(c.data_[c.num_of_hex_-1] == 0){			// if the MSB bit is 0
		--c.num_of_hex_;
		c.data_ = static_cast<uint8_t*>(realloc(c.data_, c.num_of_hex_*sizeof(uint8_t)));
	}
	
	return c;
}

BigNumber BigNumber::operator/(BigNumber b){
	
	BigNumber a = BigNumberConverter(this);		// convert const pointer to BigNumber object
	BigNumber c;
	BigNumber big_one(1);
	BigNumber big_16(16);
	
	bool flag = false;
	while(Compare(a, b)){						// if a > b, do the operation
		
		int num_of_shift = a.num_of_hex_ - b.num_of_hex_ - 1;	// calculate the difference in digits
		BigNumber tmp_b = b * big_one;
		BigNumber tmp_remainder(1);
		for(int i=0; i<num_of_shift; i++){		// multiply b in number of num_of_shift times
			tmp_b = tmp_b * big_16;
			tmp_remainder = tmp_remainder * big_16;
		}

		a = a - tmp_b;
		c = c + tmp_remainder;
		
		flag = true;
	}
	
	if(flag){				// if we have calculated before, return quotient 
		return c;
	}
	
	c.sgn_ = true;
	c.num_of_hex_ = 1;
	c.data_[0] = 0;
	
	return c;
}

BigNumber BigNumber::operator%(BigNumber b){
	
	BigNumber a = BigNumberConverter(this);		// convert const pointer to BigNumber object
	BigNumber c;
	BigNumber big_one(1);
	BigNumber big_16(16);
	
	bool flag = false;
	while(Compare(a, b)){						// if a > b, do the operation
		
		int num_of_shift = a.num_of_hex_ - b.num_of_hex_ - 1;		// calculate the difference in digits
		BigNumber tmp_b = b * big_one;
		BigNumber tmp_remainder(1);
		for(int i=0; i<num_of_shift; i++){		// multiply b in number of num_of_shift times
			tmp_b = tmp_b * big_16;
			tmp_remainder = tmp_remainder * big_16;
		}
		
		a = a - tmp_b;
		c = a;
		
		flag = true;
	}
	
	if(flag){					// if we have calculated before, return quotient 
		return c;
	}
	
	c.sgn_ = true;
	c.num_of_hex_ = 1;
	c.data_[0] = 0;
	
	return c;
}

bool BigNumber::sgn(){
	return sgn_;
}

unsigned int BigNumber::num_of_hex(){
	return num_of_hex_;
}

uint8_t* BigNumber::data(){
	return data_;
}

void BigNumber::GetData(bool& sgn, unsigned int& num_of_hex, uint8_t* data){
	sgn = sgn_;
	num_of_hex = num_of_hex_;
	data = static_cast<uint8_t*>(malloc(num_of_hex*sizeof(uint8_t)));
	data = data_;
}

void BigNumber::Print(){
	if(!sgn_){
		fprintf(stderr, "-");
	}
	int i = num_of_hex_;
	for(i = i -1; i>0; i--){
		fprintf(stderr, "%0x", data_[i]);
	}
	fprintf(stderr, "%0x\n", data_[i]);
}

bool Compare(BigNumber& a, BigNumber& b){
	if(a.num_of_hex() == b.num_of_hex()){
		
		int index = a.num_of_hex();
		while((a.data()[index-1] == b.data()[index-1]) && (index > 0)){
			--index;
		}
		
		if(index == 0){				// a equal b
			return true;
		}
		
		if(a.data()[index-1] < b.data()[index-1]){
			return false;
		}else{
			return true;
		}
		
	}else if(a.num_of_hex() < b.num_of_hex()){
		return false;
	}else{
		return true;
	}
}