/*
 *
 */

#ifndef DEFS
#define DEFS

#include <iostream>

using namespace std;

class overloaded
{
	public:
		int pubVar;
		overloaded operator-();
		overloaded operator+(const overloaded& in);
		bool operator<(const overloaded& in);
		overloaded operator=(const overloaded& in);
		overloaded operator++();
		overloaded operator++(int);
		friend ostream &operator<<(ostream &output, const overloaded &in)
		{
			output << "ISOUTPUT";
			return output;
		};
		friend istream &operator>>(istream &input, const overloaded &in)
		{
			char * dispose;
			input >> dispose;
			return input;
		};
		overloaded operator()();
		int &operator[](int i);
	protected:
		int proVar;
	private:
		int priVar;
};

#endif
