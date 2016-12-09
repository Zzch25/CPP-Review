/*
 *
 */

#include <iostream>
#include "def.h"

using namespace std;

int useDefaultArgs::toFunc = 0;

void func0(int x, int y)
{
	cout << "X :: " << x << " Y :: " << y << endl;
}

void func2(int x, int y)
{
	cout << "X :: " << x << " Y :: " << y << endl;
}
