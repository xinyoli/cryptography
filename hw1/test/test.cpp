 ///////////////////////////////////////////////////////////////////////////////
 // file: test.cpp
 // Project: COM 5336 cyptography assignment1
 // Description: 
 //
 // Change history: Mar. 07, 2018 - file created.
 //
 ///////////////////////////////////////////////////////////////////////////////

#include "big_number.h"

using namespace std;


int main(int argc, char **argv){
	
	// create time
	time_t rawtime;
	struct tm* timeinfo;
	char char_array[80];
	time(&rawtime);
	timeinfo = localtime(&rawtime);
	strftime(char_array,80,"%F_%T",timeinfo);
	
	cout << "test.out start!!!" << endl;
	cout << "start time = " << char_array << endl;
	
	time_t t;
	t=time(NULL);
	srand((unsigned)(t%RAND_MAX));
	
	// BigNumber a(5);
	// a.Print();
	
	// BigNumber b(3);
	// b.Print();
	// BigNumber c = a + b;
	// c.Print();
	
	
	
	uint8_t *buffer = static_cast<uint8_t*>(malloc(256*sizeof(uint8_t)));;
	cout << "a = ";			// f1245ab3341ff3461818881767676819ee
	cin >> buffer;
	unsigned int count = 0;
	while(buffer[count] != 0){
		++count;
	}
	BigNumber a(true, count, buffer);
	// a.Print();
	
	cout << "b = ";			// ffa24387539639853800bbecbcb494990
	cin >> buffer;
	count = 0;
	while(buffer[count] != 0){
		++count;
	}
	BigNumber b(true, count, buffer);
	// b.Print();
	
	BigNumber c;
	if(a.sgn() ^ b.sgn()){
		c = a - b;
	}else{
		c = a + b;
	}
	fprintf(stderr, "a+b = ");
	c.Print();
	
	BigNumber d;
	if(a.sgn() == b.sgn()){
		d = a - b;
	}else{
		d = a + b;
	}
	fprintf(stderr, "a-b = ");
	d.Print();
	
	BigNumber e;
	e = a * b;
	fprintf(stderr, "a*b = ");
	e.Print();
	
	BigNumber f;
	f = a / b;
	fprintf(stderr, "a/b = ");
	f.Print();
	
	BigNumber g;
	g = a % b;
	fprintf(stderr, "a%%b = ");
	g.Print();
	
	
	// uint8_t *ptr;
	// ptr = static_cast<uint8_t*>(malloc(32*sizeof(uint8_t)));
	// bool sgn;
	// unsigned int num_of_hex;
	// big_c.GetData(sgn, num_of_hex, ptr);
	// cout << ptr << endl;
	
	
	return 0;
}


