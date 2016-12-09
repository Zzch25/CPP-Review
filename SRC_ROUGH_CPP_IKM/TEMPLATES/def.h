/*
 *Template functions
 */

#ifndef DEFS
#define DEFS

#include <iostream>

template <class T> void initial(T in)
{
	std::cout << in << std::endl;
};
template <> void initial<char *>(char *in)
{
	std::cout << "OTH" << in << std::endl;
};
template <> void initial(int in)
{
	std::cout << "INT" << in << std::endl;
}

template <class T> class varying
{
	public:
		T it;
		varying(T va): it(va) {};
};

#endif
