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
	
	// BigNumber big_a;
	// big_a.Print();
	
	// BigNumber big_b(-59);
	// big_b.Print();
	
	// vector<int> data_vect;
	// data_vect.resize(12);
	// for(int i=0; i<12; i++){
		// data_vect[i] = (rand() % 2);
	// }
	// data_vect[11] = 1;
	// BigNumber big_c(true, 12, data_vect);
	// big_c.Print();
	
	char char_array[256];
	cout << "a = ";
	cin >> char_array;
	// cout << "big number = " << char_array << endl;
	// cout << char_array[0] << endl;
	// int temp = HexCharToInt(char_array[0]);
	// cout << temp << endl;
	// cout << hex << temp << endl;
	
	BigNumber big_d(char_array);
	big_d.Print();
	
	return 0;
}


