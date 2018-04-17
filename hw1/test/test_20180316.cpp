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
	char buffer[80];
	time(&rawtime);
	timeinfo = localtime(&rawtime);
	strftime(buffer,80,"%F_%T",timeinfo);
	
	cout << "test2.out start!!!" << endl;
	cout << "start time = " << buffer << endl;
	
	time_t t;
	t=time(NULL);
	srand((unsigned)(t%RAND_MAX));
	
	BigNumber big_a;
	big_a.Print();
	
	BigNumber big_b(-59);
	big_b.Print();
	
	uint8_t *data_c = new uint8_t[5];
	data_c[4] = 1;
	for(int i=0; i<4; i++){
		data_c[i] = (int)(rand() % 2);
	}
	for(int i=4; i>=0; i--){
		cout << (int)data_c[i];
	}
	cout << endl;
	// BigNumber big_c(true, 5, data_c);
	// big_c.Print();
	
	
	
	
	// delete []data_c;
	
	return 0;
}


