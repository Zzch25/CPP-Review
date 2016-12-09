#include <iostream>
#include <sstream>
#include <string>
#include "def.h"

using namespace std;

int main()
{
	int x, y, z;
	string cinString, getlineString;

	cout << "Hyper basic input and output, requested permission to STIGroup c io libraries given usefulnessand that they were written in house\nsee code for some disabled items...\n";

	cout << "\nRunning C Port...\n";
	runReadAndWriteCPort();

	cout << "Running CPP 0...\n";
	runReadAndWriteCPP0();

	cout << "basic grab from user 3 vars\n";
	cin >> x >> y >> z;
	cout << "grabbed " << x << " " << y << " " << z << endl;

	cout << "getting strings\n";
	cin >> cinString;
	getline(cin,getlineString);
	cout << "grabbed " << cinString << " <&&> " << getlineString << endl;

	cout << "\nNOTE istream getline and others perform varied tasks, this simply allows for delimiter moifications whereas others allow for size and delim\n";

	//cerr << "To error stream";
	//clog << "To log stream";

	return 0;
}
