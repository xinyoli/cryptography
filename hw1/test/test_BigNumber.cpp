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
	
	BigNumber big_a;
	big_a.Print();
	
	BigNumber big_b(-666);
	big_b.Print();
	
	// uint8_t buffer[256];
	uint8_t *buffer = static_cast<uint8_t*>(malloc(256*sizeof(uint8_t)));;
	cout << "a = ";			// f1245ab3341ff3461818881767676819ee
	cin >> buffer;
	cout << buffer << endl;
	unsigned int count = 0;
	while(buffer[count] != 0){
		++count;
	}
	// fprintf( stderr, "%d", count);
	BigNumber big_c(true, count, buffer);
	big_c.Print();
	
	uint8_t *ptr;
	ptr = static_cast<uint8_t*>(malloc(32*sizeof(uint8_t)));
	bool sgn;
	unsigned int num_of_hex;
	big_c.GetData(sgn, num_of_hex, ptr);
	cout << ptr << endl;
	
	// cout << "b = ";
	// cin >> buffer;
	// BigNumber big_b(buffer);
	// big_b.Print();
	
	
	return 0;
}


