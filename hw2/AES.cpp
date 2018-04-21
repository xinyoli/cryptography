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
		for(i=0; i<4; i++){
			for(int j=0; j<4; j++){
				input[4*i+j] = ((16*temp1[3*(4*j+i)])+temp1[3*(4*j+i)+1]);     //transform to binary 
			}
		}
	}         
}

void PrintfHex(uint8_t* byte_arr){
	for(int i =0; i<4; i++){
		for(int j=0; j<4; j++){
			printf("%02x ", byte_arr[i+4*j]);
		}
	}
	printf("\n");
}



AES::AES(){
	block_size_ = 16;
	key_size_ = 16;
	num_of_round_ = 10;
	round_ = 0;
	irr_poly_ = 0x1b;
	plaintext_ = static_cast<uint8_t*>(malloc(block_size_*sizeof(uint8_t)));
	key_ = static_cast<uint8_t*>(malloc(key_size_*sizeof(uint8_t)));
	round_key_ = static_cast<uint8_t*>(malloc(key_size_*sizeof(uint8_t)));
	ciphertext_ = static_cast<uint8_t*>(malloc(block_size_*sizeof(uint8_t)));
	for(int i=0; i<block_size_; i++){
		ciphertext_[i] = 0;
	}
	state_ = static_cast<uint8_t*>(malloc(block_size_*sizeof(uint8_t)));
	
	plaintext_[0] = 0xa3;
	plaintext_[4] = 0xc5; 
	plaintext_[8] = 0x08; 
	plaintext_[12] = 0x08; 
	plaintext_[1] = 0x78; 
	plaintext_[5] = 0xa4; 
	plaintext_[9] = 0xff; 
	plaintext_[13] = 0xd3; 
	plaintext_[2] = 0x00; 
	plaintext_[6] = 0xff; 
	plaintext_[10] = 0x36; 
	plaintext_[14] = 0x36; 
	plaintext_[3] = 0x28; 
	plaintext_[7] = 0x5f; 
	plaintext_[11] = 0x01; 
	plaintext_[15] = 0x02;
	
	key_[0] = 0x36;
	key_[4] = 0x8a; 
	key_[8] = 0xc0; 
	key_[12]= 0xf4; 
	key_[1] = 0xed; 
	key_[5] = 0xcf; 
	key_[9] = 0x76; 
	key_[13]= 0xa6; 
	key_[2] = 0x08; 
	key_[6] = 0xa3; 
	key_[10]= 0xb6; 
	key_[14]= 0x78; 
	key_[3] = 0x31; 
	key_[7] = 0x31; 
	key_[11]= 0x27; 
	key_[15]= 0x6e;
}

uint8_t AES::irr_poly(){
	return irr_poly_;
}

int AES::round(){
	return round_;
}

void AES::CoutSetting(){
	cout << "AES parameters setting:\n";
	cout << "Plantext size = \t" << block_size_ << endl;
	cout << "key size = \t\t" << key_size_ << endl;
	cout << "number of round = \t" << num_of_round_ << "\n" << endl;
}

void AES::FprintfPlaintext(){
	printf("plaintext = \t");
	PrintfHex(plaintext_);
}

void AES::FprintfKey(){
	printf("Key = \t\t");
	PrintfHex(key_);
}

void AES::PrintfState(){
	// printf("%s", "state = \t");
	printf("%s", "= \t");
	PrintfHex(state_);
}

void AES::InputPlaintext(){
	cout << "plaintext: \t";
	InputFunction(plaintext_);
	// for(int i=0; i<block_size_; i++){
		// state_[i] = plaintext_[i];
	// }
}

void AES::InputKey(){
	cout << "key: \t\t";
	InputFunction(key_);
	// for(int i=0; i<key_size_; i++){
		// round_key_[i] = key_[i];
	// }
}

void AES::InitState(){
	for(int i=0; i<block_size_; i++){
		state_[i] = plaintext_[i];
	}
}

void AES::InitRoundKey(){
	for(int i=0; i<key_size_; i++){
		round_key_[i] = key_[i];
	}
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

uint8_t AES::GF256Inv(uint8_t a){
	uint8_t result = a;
	for(int i=0; i<253; i++){		// a^254 = a^-1
		result = GF256Mult(result,a);
	}
	return result;
}

void AES::AddRoundKey(){
	for(int i=0; i<block_size_; i++){
		state_[i] = GF256Add(state_[i],round_key_[i]);
	}
}

bool AES::CountBitOdd(uint8_t x)
{
    x = (x & 0x55) + ((x & 0xaa) >> 1);
    x = (x & 0x33) + ((x & 0xcc) >> 2);
    x = (x & 0x0f) + ((x & 0xf0) >> 4);
	if((x & 0x01) == 0){
		return false;
	}else{
		return true;
	}
}

uint8_t AES::AffineTransf(uint8_t byte){
	uint8_t mat[8] = {0xf1, 0xe3, 0xc7, 0x8f, 0x1f, 0x3e, 0x7c, 0xf8};
	// uint8_t transit = 0x63;
	bool transit[8] = {1,1,0,0,0,1,1,0};
	uint8_t digit = 0x01;
	uint8_t result = 0x00;
	for(int i=0; i<8; i++){
		uint8_t temp = byte & mat[i];
		if((CountBitOdd(temp) != transit[i])){
			result = result ^ digit;
		}
		digit <<= 1;
	}
	return result;
}

void AES::ByteSub(){
	for(int i=0; i<block_size_; i++){
		state_[i] = GF256Inv(state_[i]);
		state_[i] = AffineTransf(state_[i]);
	}
}

uint8_t AES::ByteSub(uint8_t byte){
	uint8_t temp = GF256Inv(byte);
	return AffineTransf(temp);
}

void AES::ShiftRows(){
	uint8_t* temp_state = static_cast<uint8_t*>(malloc(block_size_*sizeof(uint8_t)));
	
	// row0
	for(int i=0; i<4; i++){
		temp_state[i] = state_[i];
	}
	// row1
	temp_state[4] = state_[5];
	temp_state[5] = state_[6];
	temp_state[6] = state_[7];
	temp_state[7] = state_[4];
	// row2
	temp_state[8] = state_[10];
	temp_state[9] = state_[11];
	temp_state[10] = state_[8];
	temp_state[11] = state_[9];
	// row3
	temp_state[12] = state_[15];
	temp_state[13] = state_[12];
	temp_state[14] = state_[13];
	temp_state[15] = state_[14];
	
	for(int i=0; i<block_size_; i++){
		state_[i] = temp_state[i];
	}
}

void AES::MixColumns(){
	uint8_t mat[4] = {0x02,0x03,0x01,0x01};
	uint8_t* temp_state = static_cast<uint8_t*>(malloc(block_size_*sizeof(uint8_t)));
	for(int i=0; i<16; i++){
		uint8_t temp;
		temp = GF256Mult(mat[(0+3*(i/4))%4],state_[(i%4)+0]);
		temp_state[i] = GF256Add(temp_state[i],temp);
		temp = GF256Mult(mat[(1+3*(i/4))%4],state_[(i%4)+4]);
		temp_state[i] = GF256Add(temp_state[i],temp);
		temp = GF256Mult(mat[(2+3*(i/4))%4],state_[(i%4)+8]);
		temp_state[i] = GF256Add(temp_state[i],temp);
		temp = GF256Mult(mat[(3+3*(i/4))%4],state_[(i%4)+12]);
		temp_state[i] = GF256Add(temp_state[i],temp);
	}
	for(int i=0; i<block_size_; i++){
		state_[i] = temp_state[i];
	}
}

void AES::KeyExpansion(){
	uint8_t* temp_word = static_cast<uint8_t*>(malloc(4*sizeof(uint8_t)));
	uint8_t RC[10] = {0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80,0x1b,0x36};

	// RotWord
	temp_word[0] = round_key_[7];
	temp_word[1] = round_key_[11];
	temp_word[2] = round_key_[15];
	temp_word[3] = round_key_[3];
	
	for(int i=0; i<4; i++){
		temp_word[i] = ByteSub(temp_word[i]);
	}
	
	temp_word[0] ^= RC[round_-1];
	
	// xor
	for(int i=0; i<4; i++){		// first column
		round_key_[4*i] ^= temp_word[i];
	}
	
	for(int i=1; i<4; i++){		// column
		for(int j=0; j<4; j++){ // row
			round_key_[i + 4*j] ^= round_key_[i-1 + 4*j];
		}
	}
}

void AES::AES_Encrypt(){
	cout << "<AES Encryption>" << endl;
	// InputPlaintext();
	FprintfPlaintext();
	// InputKey();
	FprintfKey();
	
	InitState();
	InitRoundKey();
	cout << "Init ";
	PrintfState();
	AddRoundKey();
	cout << "S" << round_ << " ";
	PrintfState();
	++round_;
	
	while(round_ < 10){
		cout << "Round " << round_ << ": \n";
		ByteSub();
		cout << "ByteSub ";
		PrintfState();
		ShiftRows();
		cout << "ShiftRows ";
		PrintfState();
		MixColumns();
		cout << "MixColumns ";
		PrintfState();
		KeyExpansion();
		AddRoundKey();
		cout << "S" << round_ << " ";
		PrintfState();
		++round_;
	}
	
	// final round
	cout << "Round " << round_ << ": \n";
	ByteSub();
	cout << "ByteSub ";
	PrintfState();
	ShiftRows();
	cout << "ShiftRows ";
	PrintfState();
	KeyExpansion();
	AddRoundKey();
	cout << "S" << round_ << " ";
	PrintfState();
	
	// cout << "Round " << round() << ": \n";
	// ByteSub();
	// cout << "ByteSub ";
	// PrintfState();
	// ShiftRows();
	// cout << "ShiftRows ";
	// PrintfState();
	// MixColumns();
	// cout << "MixColumns ";
	// PrintfState();
	// KeyExpansion();
	// AddRoundKey();
	// ++round_;
	// cout << "S" << round() << " ";
	// PrintfState();
}

// void AES::AES_Decrypt(){
	
// }

