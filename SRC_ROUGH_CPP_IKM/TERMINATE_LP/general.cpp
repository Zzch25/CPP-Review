/*
 *
 */

#include <iostream>
#include <exception>
#include <cstdlib>
#include "def.h"

using namespace std;

//Brutually short, simply provide a 'template'

void customTerminator()
{
	cout << "In Terminator\n\n";
	cerr << "Custom termination triggered\n";
	abort();
}
