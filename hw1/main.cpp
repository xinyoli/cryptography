 ///////////////////////////////////////////////////////////////////////////////
 // file: main.cpp
 // Project: COM 5336 cyptography assignment1
 // Description: 
 //
 // Change history: Mar. 07, 2018 - file created.
 //
 ///////////////////////////////////////////////////////////////////////////////

#include "big_number.h"

using namespace std;


int main(int argc, char **argv){
	
	cout << "main.out start!!!" << endl;

	// create buffer for input number
	uint8_t *buffer = static_cast<uint8_t*>(malloc(256*sizeof(uint8_t)));;
	cout << "a = ";			// f1245ab3341ff3461818881767676819ee
	cin >> buffer;
	unsigned int count = 0;
	while(buffer[count] != 0){			// count the number of digit
		++count;
	}
	BigNumber a(true, count, buffer);
	
	cout << "b = ";			// ffa24387539639853800bbecbcb494990
	cin >> buffer;
	count = 0;
	while(buffer[count] != 0){
		++count;
	}
	BigNumber b(true, count, buffer);
	
	BigNumber c;
	c = a + b;
	fprintf(stderr, "a+b = ");
	c.Print();
	
	BigNumber d;
	d = a - b;
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
	
	return 0;
}


