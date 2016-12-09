#include <iostream>
#include "def.h"

int main()
{
	friends test;
	friendOfFriend testFriendClass;

	testPub(test);
	testPro(test);
	testPri(test);

	testTempPub(test);
	testTempPro(test);
	testTempPri(test);

	testFriendClass.testPriVar(test);

	test.printVars();

	return 0;
}
