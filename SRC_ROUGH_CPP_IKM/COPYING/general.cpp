/*
 *
 */

#include <iostream>
#include "def.h"

using namespace std;

implicitCopy::implicitCopy()
{
	cout << "IMPINIT\n";

	pubVar = 0;
	proVar = 1;
	priVar = 2;
};

implicitCopy::~implicitCopy()
{
	cout << "IMPDEC\n";
};

definedCopy::definedCopy()
{
	cout << "DEFINIT\n";

	pubVar = 0;
	proVar = 1;
	priVar = 2;
};

definedCopy::~definedCopy()
{
	cout << "DEFDEC\n";
};

noCopy::noCopy()
{
	cout << "NOINIT\n";

	pubVar = 0;
	proVar = 1;
	priVar = 2;
};

noCopy::~noCopy()
{
	cout << "NODEC\n";
};

selectiveCopy::selectiveCopy()
{
	cout << "SELINIT\n";

	pubVar = 0;
	proVar = 1;
	priVar = 2;
};

selectiveCopy::~selectiveCopy()
{
	cout << "SELDEC\n";
};

definedCopy::definedCopy(const definedCopy& in)
{
	cout << "DEF STOCK\n";

	pubVar = 3;
	proVar = 4;
	priVar = 5;
};

definedCopy& definedCopy:: operator=(const definedCopy& in)
{
	definedCopy *retCopy = new definedCopy;
	
	cout << "DEF EOP CONST\n";

	pubVar = 3;
	proVar = 4;
	priVar = 5;

	return *retCopy;
};

selectiveCopy& selectiveCopy:: operator=(const selectiveCopy& in)
{
	selectiveCopy *retCopy = new selectiveCopy;
	
	cout << "SEL EOP CONST\n";	

	pubVar = 3;
	proVar = 4;
	priVar = 5;

	return *retCopy;
};
