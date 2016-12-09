#include <iostream>
#include "def.h"

using namespace std;

int main()
{
	implicitCopy testImplicitCopy, testImplicitCopyAssign, testImplicitCopyLval;
	definedCopy testDefinedCopy, testDefinedCopyAssign, testDefinedCopyLval;
	noCopy testNoCopy, testNoCopyAssign, testNoCopyLval;
	selectiveCopy testSelectiveCopy, testSelectiveCopyAssign, testSelectiveCopyLval;

	cout << "Copying...\n\n";

	cout << "IMP\n";

	//testImplicitCopyAssign(testImplicitCopy); NO SET IN POST
	testImplicitCopyLval = testImplicitCopy;
	implicitCopy testNewImplicitCopyAssign(testImplicitCopy);
	implicitCopy testNewImplicitCopyLval = testImplicitCopy;

	cout << "DEF\n";

	//testDefinedCopyAssign(testDefinedCopy); NO SET IN POST
	testDefinedCopyLval = testDefinedCopy;
	definedCopy testNewDefinedCopyAssign(testDefinedCopy);
	definedCopy testNewDefinedCopyLval = testDefinedCopy;
	
	cout << "NO\n";

	//testNoCopyAssign(testNoCopy); NO SET IN POST
	//testNoCopyLval = testNoCopy;
	//noCopy testNewNoCopyAssign(testNoCopy); CANNOT
	//noCopy testNewNoCopyLval = testNoCopy;

	cout << "SEL\n";

	//testSelectiveCopyAssign(testSelectiveCopy); NO SET IN POST
	testSelectiveCopyLval = testSelectiveCopy;
	//selectiveCopy testNewSelectiveCopyAssign(testSelectiveCopy); CANNOT
	//selectiveCopy testNewSelectiveCopyLval = testSelectiveCopy;

	cout << "\nRevealing...\n\n";

	cout << "ORIGINALS\n";

	reveal(testImplicitCopy);
	reveal(testDefinedCopy);
	reveal(testNoCopy);
	reveal(testSelectiveCopy);

	cout << "COPIES ASSIGN PRE\n";	

	reveal(testImplicitCopyAssign);
	reveal(testDefinedCopyAssign);
	reveal(testNoCopyAssign);
	reveal(testSelectiveCopyAssign);

	cout << "COPIES LVAL PRE\n";	

	reveal(testImplicitCopyLval);
	reveal(testDefinedCopyLval);
	reveal(testSelectiveCopyLval);

	cout << "COPIES ASSIGN POST\n";	

	reveal(testNewImplicitCopyAssign);
	reveal(testNewDefinedCopyAssign);

	cout << "COPIES LVAL POST\n";	

	reveal(testNewImplicitCopyLval);
	reveal(testNewDefinedCopyLval);
	
	return 0;
}
