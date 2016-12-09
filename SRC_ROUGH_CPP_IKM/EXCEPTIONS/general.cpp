/*
 *
 */

#include <iostream>
#include <exception>
#include "def.h"

using namespace std;

verifyBadAllocStructure::verifyBadAllocStructure()
{
	cout << "INIT CHILD VERIFY BAD ALLOC";
};

void verifyBadAllocStructure::throwFreeFunc() throw() {};

const char * customException::what() const throw()
{
	return specification;
};

customException::customException()
{
	specification = (char*)DEFS_THROWSPC_DEFAULT;
};

customException::customException(char *specification)
{
	this->specification = specification;
};

void throwInFuncLiteral(void **in)
{
	cout << "THROW LITERAL SAMPLER\n";
	if(in == NULL)
		throw DEFS_THROWDEF_LITERALTHROW;
	throw (char*)(in[0]);
};

void throwInFuncActual(void **in)
{
	cout << "THROW ACTUAL ";
	if(*((bool*)in[0]))
		cout << "STANDARD ";
	else
		cout << "CUSTOM ";
	cout << "SAMPLER\n";
	throw *((exception*)in[1]);
};

void catchThrowLiteral(void **in)
{
	cout << "IN HANDLER LITERAL SAMPLER\n";
	if(in != NULL)
		cout << " " << (char*)(in[0]);
	cout << endl;
};

void catchThrowActual(void **in)
{
	cout << "IN HANDLER ACTUAL SAMPLER\n";
	if(in != NULL)
		cout << " " << (char*)(in[0]);
	cout << endl;
};

//viable to do void (*func)(void **) then call (*func)(args)
void runThrowThenCatch(void *funcThrow, void **argsThrow, void *funcCatch, void **argsCatch, char type)
{
	typedef void (*callbackPtr)(void **);
	
	callbackPtr runCallbackThrow = (callbackPtr)funcThrow;
	callbackPtr runCallbackCatch = (callbackPtr)funcCatch;

	try
	{
		if(!DEFS_THROWFN_ISVALID(type))	
			throwInFuncUndef<char *>((char*)DEFS_THROWDEF_UNKNOWNTHROW);
		runCallbackThrow(argsThrow);
	}
	catch(exception &in)
	{
		cout << "Exception " << in.what() << " caught\n";
		runCallbackCatch(argsCatch);
	}
	/*
	 *can catch individual "exception" types or derived classes
	catch(bad_alloc in)	//can be frowned upon as a child may enter 
								//and slice
	catch(bad_alloc &in)
	 */
	catch(const char *in)
	{
		cout << "Literal exception " << in << " caught\n";
		runCallbackCatch(argsCatch);
	}
	catch(...)
	{
		catchThrowUndef<char *>((char*)DEFS_THROWDEF_UNKNOWNCATCH);	
		cout << "\n\n<!>EXCEPTION UNDEFINED<!>\n\n";
	}
};
