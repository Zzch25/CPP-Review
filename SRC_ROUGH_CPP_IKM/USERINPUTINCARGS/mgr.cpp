#include <iostream>
#include "def.h"

using namespace std;

int main(int argc, char *argv[])
{

	//ANOTHER super simple template, nothing more is needed this is trivial

	cout << "Trivial topic, minimal template code\n\n";
	
	if(argc > DEFS_BASE_ARGS)
	{
		while(argc > DEFS_BASE_ARGS)
			cout << "ARG AT " << argc << " :: " << argv[--argc] << endl;
	}
	else
		cout << "INSUFFICIENT ARGS\n";

	return 0;
}
