/*
 *
 */

#include <iostream>
#include "def.h"

using namespace std;

friends::friends()
{
	cout << "SET\n";

	pubVar = 1;
	proVar = 2;
	priVar = 3;
};

friends::~friends()
{
	cout << "DEC\n";
};

void testPub(const friends& obj)
{
	cout << "TESTPUB " << obj.priVar << endl;
};

void testPro(const friends& obj)
{
	cout << "TESTPRO " << obj.proVar << endl;
};

void testPri(const friends& obj)
{
	cout << "TESTPRI " << obj.pubVar << endl;
};

void friendOfFriend::testPriVar(const friends& in)
{
	cout << "FOF TESTPRI " << in.priVar << endl;
};

void EXP::printVars()
{
	cout << "PARTEST " << this->priVar << proVar << pubVar << endl;
};
