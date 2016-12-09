#include <iostream>
#include <exception>
#include "def.h"

using namespace std;

int main()
{
	//Brutually short, simply provide a 'template'

	cout << "Trivial topic, minimal template code\n\n";

	set_terminate(customTerminator);

	throw 24;

	return 0;
}
