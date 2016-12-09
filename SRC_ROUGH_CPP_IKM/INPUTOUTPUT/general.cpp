/*
 *
 */

#include <iostream>
#include <fstream>
#include "def.h"

using namespace std;

//request permission to utilize homemade c lib made under contract
void runReadAndWriteCPort()
{
	cout << "\n<!>\nREQUEST PERMISSION FROM STIGROUP TO UTILIZE HOMEMADE FILE LIBRARY\n<!>\n";
}

void runReadAndWriteCPP0()
{
	char *data;
	ifstream::pos_type file_sz;

	ifstream inputFile;
	ofstream outputFile;

	inputFile.open(DEFS_FILEIN, ios::binary);
	outputFile.open(DEFS_FILEOUT, ios::binary);

	inputFile.seekg(0, ios::end);
	file_sz = inputFile.tellg();
	inputFile.seekg(0, ios::beg);

	data = new char[file_sz];

	inputFile.read(&data[0], file_sz);

	cout << "\n\nREAD ::\n" << data << endl; 

	outputFile.write(data, file_sz);

	inputFile.close();
	outputFile.close();
}
