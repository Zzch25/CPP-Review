/*
 *
 */

#include <iostream>
#include "def.h"

using namespace std;

void takePointersAndArrs(void *funcPtr, void *arg)
{
	typedef void (*callBackPtr)(void*);

	callBackPtr runFunc = (callBackPtr)funcPtr;

	runFunc(arg);
	((void(*)(void*))funcPtr)(arg);
}

void funcToPassNorm(char *msg)
{
	cout << msg << endl;
};

void testFunc(int in0, int in1)
{
	cout << in0 << " " << in1 << endl;
};
