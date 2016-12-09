/*
 *
 */

#include <iostream>
#include "def.h"

using namespace std;

constCorrectness::constCorrectness()
{
	pubVar = 5;
	pubVarVolatile = 5;
	pubVarMutable = 5;
};

int& constCorrectness::varyByKeyword(int &in)
{
	cout << "VBK auto ran..." << endl;
		
	in = 2;
	return in;
};

const int& constCorrectness::varyByKeyword(const int &in) const
{
	cout << "VBK const ran..." << endl;
		
	//in = 2; //illegal
	return in;	
};

void constCorrectness::demonstrateAccess()
{
	cout << "DA auto ran..." << endl;
		
	pubVar = 1;
	pubVarVolatile = 1;
	//pubVarConst = 1; //illegal
	pubVarMutable = 1;
};

void constCorrectness::demonstrateAccess() const
{
	cout << "DA const ran..." << endl;
		
	//pubVar = 2; //illegal
	//pubVarVolatile = 2; //illegal
	//pubVarConst = 2; //illegal
	pubVarMutable = 2;
};

/*
 * Valid, returns copy according to syntax
int doNotModify(const int &in)
{
	//in = 5; //compiler violation
	return in;
}
*/

const int& doNotModify(const int &in)
{
	//in = 5; //compiler violation
	return in;
};

void improper_string_notconst(char * in)
{
	cout << "badstring: " << in << endl;
};
