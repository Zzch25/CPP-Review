#include <iostream>
#include "def.h"

using namespace std;

int main()
{
	overloaded testOverload, testOverloadCopy, *testOverloadPtr;
	testOverloadPtr = new overloaded;

	cout << "Unary...\n";

	cout << -testOverload << endl;

	cout << "Binary...\n";

	cout << testOverload + testOverload << endl;

	cout << "Relational...\n";

	bool type = testOverload < testOverload;
	cout << type << endl;

	cout << "Assignment...\n";

	testOverloadCopy = testOverload;
	cout << testOverloadCopy << endl;

	cout << "Xop-crement...\n";

	testOverloadCopy++;
	cout << testOverloadCopy << endl;

	cout << "InputOutput...\n";

	cin >> testOverloadCopy;
	cout << testOverloadCopy << endl;

	cout << "FunctionCall...\n";

	testOverloadCopy();
	cout << testOverloadCopy << endl;

	cout << "Subscripting...\n";

	cout << testOverload[0] << endl;

	cout << "ClassAccess...\n";

	cout << "SEE TP\n";

	return 0;
}
