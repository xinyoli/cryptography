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
	
	cout << "test.out start!!!" << endl;
	cout << "start time = " << buffer << endl;
	
	time_t t;
	t=time(NULL);
	srand((unsigned)(t%RAND_MAX));
	
	
	char char_array[256];
	cout << "a = ";
	cin >> char_array;
	BigNumber big_a(char_array);
	big_a.Print();
	
	cout << "b = ";
	cin >> char_array;
	BigNumber big_b(char_array);
	big_b.Print();
	
	
	return 0;
}


