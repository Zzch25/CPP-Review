/*
 *
 */

#include <iostream>
#include "def.h"

using namespace std;

//inline

//global

int aGlobalValueWhichIsVirtuallyAlmostUnacceptable = 24;

void aGlobalFunctionWhichIsVirtuallyAlmostUnacceptable()
{
	cout << "A GLOBAL FUNCTION\n";
};

//static

static int aLocallyGlobalVariableWhichIsVeryFrownedUpon = 2;

void printStatic()
{
	cout << "A STATIC VARIABLE " << aLocallyGlobalVariableWhichIsVeryFrownedUpon << endl;
};

int staticTest::sharedStaticInt = 0;

staticTest::staticTest()
{
	cout << "Creating staticTest instance...\n";
	sharedStaticInt++;
};

staticTest::~staticTest()
{
	sharedStaticInt--;
};

void staticTest::sharedStaticFunc()
{
	cout << "INSTANCES " << sharedStaticInt << endl;
};
