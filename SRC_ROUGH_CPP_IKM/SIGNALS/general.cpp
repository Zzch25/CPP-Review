/*
 *
 */

#include <iostream>
#include <csignal>
#include "def.h"

using namespace std;

//Another hyper simple example, again this is trivial stuuuph

void handler_sigint(int raised)
{
	cout << "Interuption raised with " << raised << endl << "No exit\n\n";

	//exit(raised)
}
