 ///////////////////////////////////////////////////////////////////////////////
 // file: readme.txt
 // Project: COM 5336 cyptography assignment2
 // Description: 
 //
 // Change history: Apr. 18, 2018 - file created.
 // 				Apr. 22, 2018 - file modified.
 //
 ///////////////////////////////////////////////////////////////////////////////

files discription:
./AES.h		class and functions definitions.
./AES.cpp	class and functions implementation.
./main.cpp	main program. 

compilation instructions:
	type the following command to compiler the main.cpp program into executable main.out file in linux terminal:
		g++ main.cpp AES.cpp -o main.out -Wall
		
limitation of the program main.cpp:
	ues the following input format for the 16-byte of plaintext and key value each, and plese use space to sperate each byte:
		a3 c5 08 08 78 a4 ff d3 00 ff 36 36 28 5f 01 02
	