#include <iostream>
#include "def.h"

using namespace std;

int main()
{
	//Another very simple section, basic examples

	cout << "Trivial topic, virtually no template code, see source\n\n";

	#ifdef NOTDEF
	cout << "NOTDEF IS DEF\n";
	#else
		#if CANENTER
		cout << "CANENTER WAS GO, THIS COMPILED\n";
		#elif CANENTER == 2
		cout << "CANENTER WAS 2, THIS COMPILED\n";
		#else
		cout << "CANENTER WAS SOMETHING ELSE, THIS COMPILED\n";
		#endif
	#endif

	#undef HASDEF
	#ifdef HASDEF
	cout << "HASDEF DID NOT UNDEF\n";
	#endif

	cout << "COMPILER INSERTS ::(LINE,FILE,DATE,TIME,CV)::\n" << __LINE__ << endl << __FILE__ << endl << __DATE__ << endl << __TIME__ << endl << __cplusplus << endl;

	return 0;
}
