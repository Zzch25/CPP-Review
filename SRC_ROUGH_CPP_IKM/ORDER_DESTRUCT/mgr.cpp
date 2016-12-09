#include <iostream>
#include "def.h"

using namespace std;

int main()
{
	/*Utilization of new for isolation within a sector of the heap*/

	/*Double init*/
	base *testBase = new base;

	cout << testBase->compareBasePtr() << endl;

	delete testBase; //essential for destruction

	//disable double init
	base::setSkipDoubleInit(true);

	childOfBase *testChildOfBase = new childOfBase;

	delete testChildOfBase;
	
	childOfChildOfBase *testChildOfChildOfBase = new childOfChildOfBase;

	delete testChildOfChildOfBase;

	friendClassDefined0 *testFriendClassDefined0 = new friendClassDefined0;
	
	delete testFriendClassDefined0;

	friendClassDefined1 *testFriendClassDefined1 = new friendClassDefined1;
	
	delete testFriendClassDefined1;

	friendClassInitialized0 *testFriendClassInitialized0 = new friendClassInitialized0;

	delete testFriendClassInitialized0;
	
	friendClassInitialized1 *testFriendClassInitialized1 = new friendClassInitialized1;

	testFriendClassInitialized1->initBase();
	
	delete testFriendClassInitialized1;

	friendFuncInit();

	friendFuncNoInit();

	childOfChildOfBase testInitOrder;

	return 0;
}
