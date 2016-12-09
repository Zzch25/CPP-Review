/*
 *
 */

#ifndef DEFS
#define DEFS

using namespace std;

void takePointersAndArrs(void *funcPtr, void *arg);

template <typename... T>
void takePointersAndArrs(void *funcPtr, T... args)
{
	((void(*)(T...))funcPtr)(args...);
};

void funcToPassNorm(char *msg);
void testFunc(int in0, int in1);

template <typename T>
void funcToPassTemp(T msg)
{
	cout << msg << endl;
};

#endif
