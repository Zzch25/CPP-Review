/*
 *
 */

#ifndef DEFS
#define DEFS

#include <exception>

#define DEFS_THROWFN_ISLITERAL 0
#define DEFS_THROWFN_ISACTUAL 1

#define DEFS_THROWFN_MIN_ID DEFS_THROWFN_ISLITERAL
#define DEFS_THROWFN_MAX_ID DEFS_THROWFN_ISACTUAL

#define DEFS_THROWFN_ISVALID(IN) \
	((((IN) <= (DEFS_THROWFN_MAX_ID) ? (IN) : (DEFS_THROWFN_MAX_ID))	\
	==																							\
	((IN) >= (DEFS_THROWFN_MIN_ID) ? (IN) : (DEFS_THROWFN_MIN_ID)))		\
	? (1) : (0))

#define DEFS_THROWDEF_LITERALTHROW "KNOWN GENERIC LITERAL EXCEPTION"
#define DEFS_THROWDEF_ACTUALTHROW "KNOWN GENERIC LITERAL EXCEPTION"
#define DEFS_THROWDEF_UNKNOWNTHROW "UNKNOWN EXCEPTION"

#define DEFS_THROWDEF_UNKNOWNCATCH "CATCH UNKNOWN"
#define DEFS_THROWDEF_LITERALCATCH "CATCH LITERAL INPUT"
#define DEFS_THROWDEF_ACTUALCATCH "CATCH ACTUAL INPUT"

#define DEFS_THROWSPC_DEFAULT "exception thrown for example"
#define DEFS_THROWSPC_LITERAL "literal exception thrown for example"
#define DEFS_THROWSPC_ACTUAL "actual exception thrown for example"

using namespace std;

class verifyBadAllocStructure: public exception
{
	public:
		verifyBadAllocStructure();
		void throwFreeFunc() throw();//guarantees no exceptions will throw during this function call
};

class customException: public exception
{
	public:
		customException();
		customException(char *specification);
		const char * what() const throw();
	private:
		char *specification;
};

//warning potentially hazardous
template <typename T>
inline void throwInFuncUndef(T in)
{
	cout << "THROW ATTEMPT UNKNOWN SAMPLER\n";
	cout << in << endl;
	throw in;
};
void throwInFuncLiteral(void **in);
void throwInFuncActual(void **in);

template <typename T>
inline void catchThrowUndef(T in)
{
	cout << "IN HANDLER ATTEMPT UNDEF SAMPLER\n";
	if(in != NULL)
		cout << " " << in;
	cout << endl;
};
void catchThrowLiteral(void **in);
void catchThrowActual(void **in);

void runThrowThenCatch(void *funcThrow, void **argsThrow, void *funcCatch, void **argsCatch, char type);

//can be dangerous	
template <typename T>
void runThrowThenCatch(void *funcThrow, T argsThrow, void *funcCatch, T argsCatch)
{
	typedef void (*callbackPtrUndef)(T);

	callbackPtrUndef runCallbackThrow = (callbackPtrUndef)funcThrow;
	callbackPtrUndef runCallbackCatch = (callbackPtrUndef)funcCatch;

	try
	{
		cout << "Attempt throw undef\n";
		runCallbackThrow(argsThrow);
	}
	catch(exception &in)
	{
		cout << "Exception " << in.what() << " caught\n";
		runCallbackCatch(argsCatch);
	}
	catch(...)
	{
		catchThrowUndef((char*)DEFS_THROWDEF_UNKNOWNCATCH);	
		cout << "\n\n<!>EXCEPTION UNDEFINED<!>\n\n";
	}
};

#endif
