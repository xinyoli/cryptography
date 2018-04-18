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
	plaintext_ = static_cast<uint8_t*>(malloc(block_size_*sizeof(uint8_t)));
	key_ = static_cast<uint8_t*>(malloc(key_size_*sizeof(uint8_t)));
	ciphertext_ = static_cast<uint8_t*>(malloc(block_size_*sizeof(uint8_t)));
	for(int i=0; i<block_size_; i++){
		ciphertext_[i] = 0;
	}
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
