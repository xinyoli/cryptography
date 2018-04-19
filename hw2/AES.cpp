 ///////////////////////////////////////////////////////////////////////////////
 // file: AES.cpp
 // Project: COM 5336 cyptography hw assignment2
 // Description: 
 //
 // Change history: Apr. 17, 2018 - file created.
 // 				
 //
 ///////////////////////////////////////////////////////////////////////////////
 
#include "AES.h"


// collect the input char (include whitespace) and transfer it into uint8_t array with size 16.
// the input format should be: a3 c5 08 08 78 a4 ff d3 00 ff 36 36 28 5f 01 02
void InputFunction(uint8_t* input){ 
	uint8_t temp[49];  
	int i,c; 
	int temp1[49]; 
	for(c=0;c<48;c++){   
		temp[c] = getchar();                 //collect input(hex)  
	}
	for(c=0;c<48;c++){                       //transform to decimal 
		if(temp[c] >= '0' && temp[c] <= '9') temp1[c]= temp[c]-'0'; 
		if(temp[c] >= 'a' && temp[c] <= 'f') temp1[c]= 10+temp[c]-'a'; 
		if(temp[c] >= 'A' && temp[c] <= 'F') temp1[c]= 10+temp[c]-'A'; 
		for(i=0;i<16;i++){ 
			input[i]=((16*temp1[3*i])+temp1[3*i+1]);     //transform to binary 
		}
	}         
}

void FprintfHex(uint8_t* byte_arr){
	int i;
	for(i = 0; i<15; i++){
		fprintf(stderr, "%02x ", byte_arr[i]);
	}
	fprintf(stderr, "%02x\n", byte_arr[i]);
}



AES::AES(){
	block_size_ = 16;
	key_size_ = 16;
	num_of_round_ = 10;
	irr_poly_ = 0x1b;
	plaintext_ = static_cast<uint8_t*>(malloc(block_size_*sizeof(uint8_t)));
	key_ = static_cast<uint8_t*>(malloc(key_size_*sizeof(uint8_t)));
	ciphertext_ = static_cast<uint8_t*>(malloc(block_size_*sizeof(uint8_t)));
	for(int i=0; i<block_size_; i++){
		ciphertext_[i] = 0;
	}
}

uint8_t AES::irr_poly(){
	return irr_poly_;
}

void AES::CoutSetting(){
	cout << "AES parameters setting:\n";
	cout << "Plantext size = \t" << block_size_ << endl;
	cout << "key size = \t\t" << key_size_ << endl;
	cout << "number of round = \t" << num_of_round_ << "\n" << endl;
}

void AES::FprintfPlaintext(){
	fprintf(stderr, "plaintext = \t");
	int i;
	for(i = 0; i<15; i++){
		fprintf(stderr, "%02x ", plaintext_[i]);
	}
	fprintf(stderr, "%02x\n", plaintext_[i]);
}

void AES::FprintfKey(){
	fprintf(stderr, "Key = \t\t");
	int i;
	for(i = 0; i<15; i++){
		fprintf(stderr, "%02x ", key_[i]);
	}
	fprintf(stderr, "%02x\n", key_[i]);
}

void AES::InputPlaintext(){
	cout << "plaintext: \t";
	InputFunction(plaintext_);
	// FprintfHex(plaintext_);
}

void AES::InputKey(){
	cout << "key: \t\t";
	InputFunction(key_);
	// FprintfHex(key_);
}

uint8_t AES::GF256Add(uint8_t a, uint8_t b){
	uint8_t result = a ^ b;
	return result;
}

uint8_t AES::GF256MultX(uint8_t a){
	uint8_t result = a << 1;
	if(a >= 0x80){
		return (result ^ irr_poly_);
	}else{
		return result;
	}
}

uint8_t AES::GF256Mult(uint8_t a, uint8_t b){
	uint8_t product = 0;
	uint8_t digit = 0x01;
	for(int i=0; i<8; i++){
		if((b & digit) != 0){	// digit i of b is 1
			uint8_t temp = a;
			for(int j=0; j<i; j++){
				temp = GF256MultX(temp);
			}
			product = GF256Add(product, temp);
		}
		digit <<= 1;
	}
	return product;
}

uint8_t AES::GF256MxDiv(uint8_t b){
	uint8_t r = irr_poly_;
	uint8_t temp_sub = b;
	uint8_t q = 0x01;
	uint8_t digit = 0x01;		// digit of b
	uint8_t order = 0x80;		// order of mx
	while(temp_sub < 0x80){	
		temp_sub <<= 1;
		q <<= 1;
		digit <<= 1;
	}
	q <<= 1;
	digit <<= 1;
	temp_sub <<= 1;
	r = GF256Add(r, temp_sub);
	temp_sub >>= 1;
	temp_sub = GF256Add(temp_sub, 0x80);	// for later substraction
	
	while(digit != 0){
		digit >>= 1;
		if((r & order) != 0){	// x^order == 1
			r = GF256Add(r, temp_sub);
		}
		temp_sub >>= 1;
		order >>= 1;
	}
	return r;
}

// extended Eculidean 
uint8_t AES::GF256Inv(uint8_t b){
	// int i = 0;
	// uint8_t s_old = 0x01;
	// uint8_t t_old = 0x00;
	// uint8_t r_old = irr_poly_;
	// uint8_t s = 0x00;
	// uint8_t t = 0x01;
	// uint8_t r = b;
	// uint8_t q = 0x00;
	
	// while(r != 0){
		
	// }
	
	uint8_t result = b;
	for(int i=0; i<254; i++){
		result = GF256Mult(result,b);
	}
	return result;
}


