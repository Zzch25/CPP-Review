#include <iostream>
#include "def.h"

using namespace std;

int main()
{
	baseAccess testBaseAccess;
	baseShareAccess testBaseShareAccess;
	baseFriendAccess testBaseFriendAccess;
	childAccess0 testChildAccess0;
	childAccess1 testChildAccess1;
	childAccess2 testChildAccess2;

	friendFuncShared();

	cout << "demo friends of scope access...\n";
	friendFuncPub();
	friendFuncPro();
	friendFuncPri();

	cout << "demo classes scope of access...\n";

	testBaseFriendAccess.demoAccess();	
	testChildAccess0.demoAccess();	
	testChildAccess1.demoAccess();	
	testChildAccess2.demoAccess();

	cout << "Further demonstration unecesary eg static et all\n";

	return 0;
}
