/*
 *
 */

#include <iostream>
#include "def.h"

using namespace std;

overloaded overloaded::operator-()
{
	overloaded ret;

	return ret;
};

overloaded overloaded::operator+(const overloaded& in)
{
	overloaded ret;

	return ret;
};

bool overloaded::operator<(const overloaded& in)
{
	bool ret;

	ret = true;

	return ret;
};

overloaded overloaded::operator=(const overloaded& in)
{
	overloaded ret;

	return ret;
};

overloaded overloaded::operator++()
{
	overloaded ret;

	return ret;
};

overloaded overloaded::operator++(int)
{
	overloaded ret;

	return ret;
};

/*ostream &overloaded::operator<<(ostream &output, const overloaded &in)
{
	output << "ISOUTPUT";
	return output;
};*/

/*istream &overloaded::operator>>(istream &intput, overloaded &in)
{
	int dispose;
	input >> dispose;
	return input;
};*/

overloaded overloaded::operator()()
{
	overloaded ret;

	return ret;
};

int &overloaded::operator[](int i)
{
	int *ret = new int;

	*ret = 0;

	return *ret;
};
