/*
 *
 */

#include <iostream>
#include "def.h"

using namespace std;

baseAccess::baseAccess()
{
	pubVar = 1;
	proVar = 2;
	priVar = 3;

	cout << "Base vars set PUB::" << pubVar << " PRO::" << proVar << " PRI::" << priVar << endl;
}

void baseAccess::pubFunc()
{
	cout << "BASE FUNC PUB\n";
}

void baseAccess::proFunc()
{
	cout << "BASE FUNC PRO\n";
}

void baseAccess::priFunc()
{
	cout << "BASE FUNC PRI\n";
}

baseShareAccess::baseShareAccess()
{
	priVar = 4;

	cout << "Share base var set PRI::" << priVar << endl;
}

void baseFriendAccess::demoAccess()
{
	baseAccess testBaseAccess;

	cout << "Friend base access::" << testBaseAccess.pubVar << testBaseAccess.proVar << testBaseAccess.priVar << endl;

	cout << "Touching functions...\n";
	testBaseAccess.pubFunc();
	testBaseAccess.proFunc();
	testBaseAccess.priFunc();
}

void childAccess0::demoAccess()
{
	cout << "Child0 'PUBLIC' accesses member... " << toAccess.pubVar << '-' << '-' << endl;
	cout << "Child0 'PUBLIC' accesses self... " << pubVar << proVar << '-' << endl;

	cout << "Child0 call funcs MINUS uninherited friends...\n";
	pubFunc();
	proFunc();
}

void childAccess1::demoAccess()
{
	cout << "Child1 'PROTECTED' accesses member... " << toAccess.pubVar << '-' << '-' << endl;
	cout << "Child1 'PROTECTED' accesses self... " << pubVar << proVar << '-' << endl;
	
	cout << "Child1 call funcs MINUS uninherited friends...\n";
	pubFunc();
	proFunc();
}

void childAccess2::demoAccess()
{
	cout << "Child2 'PRIVATE' accesses member... " << toAccess.pubVar << '-' << '-' << endl;
	cout << "Child2 'PRIVATE' accesses self... " << pubVar << proVar << '-' << endl;
	
	cout << "Child2 call funcs MINUS uninherited friends...\n";
	pubFunc();
	proFunc();
}

void friendFuncShared()
{
	baseAccess testBaseAccess;
	baseShareAccess testBaseShareAccess;

	cout << "BASE " << testBaseAccess.priVar << " SHARED " << testBaseShareAccess.priVar << endl;
}

void friendFuncPub()
{
	baseAccess testBaseAccess;
	cout << "friend func from public" << testBaseAccess.pubVar << testBaseAccess.proVar << testBaseAccess.priVar << "...\n";
}

void friendFuncPro()
{
	baseAccess testBaseAccess;
	cout << "friend func from protected" << testBaseAccess.pubVar << testBaseAccess.proVar << testBaseAccess.priVar << "...\n";
}

void friendFuncPri()
{
	baseAccess testBaseAccess;
	cout << "friend func from private" << testBaseAccess.pubVar << testBaseAccess.proVar << testBaseAccess.priVar << "...\n";
}
