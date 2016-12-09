/*
 *
 */

#include <iostream>
#include <typeinfo>
#include "def.h"

using namespace std;

bool base::skipDoubleInit = false;

base::base()
{
	cout << typeid(*this).name() << " INIT START\n";
	takeDoubleInit = this;
	if(!skipDoubleInit)
		base(false);
}

base::base(bool setSharedInt)
{
	cout << typeid(*this).name() << " INIT SECONDARY";
	if(setSharedInt)
	{
		cout << " SET SHARED";
		sharedInt = setSharedInt;
	}
	cout << endl;	
}

base::~base()
{
	cout << typeid(*this).name() << " DEINIT\n";
}

base::insideBase::insideBase()
{
	cout << typeid(*this).name() << " INIT\n";
}

void base::insideBase::stateLiveliness()
{
	cout << typeid(*this).name() << " ALIVE\n";
}

base::insideBase::~insideBase()
{
	cout << typeid(*this).name() << " DEINIT\n";
}

bool base::compareBasePtr()
{
	return (takeDoubleInit == this);
}

childOfBase::childOfBase()
{
	cout << typeid(*this).name() << " INIT\n";
}

void childOfBase::uniqueFunction()
{
	cout << typeid(*this).name() << " UNIQUE FUNC\n";
}

childOfBase::~childOfBase()
{
	cout << typeid(*this).name() << " DEINIT\n";
}

childOfChildOfBase::childOfChildOfBase()
{
	uniqueFunction();
	cout << typeid(*this).name() << " INIT\n";
}

childOfChildOfBase::~childOfChildOfBase()
{
	cout << typeid(*this).name() << " DEINIT\n";
}

void childOfChildOfBase::uniqueFunction()
{
	testInsideBase.stateLiveliness();
	cout << typeid(*this).name() << " UNIQUE FUNC\n";
}

friendClassDefined0::friendClassDefined0()
{
	cout << typeid(*this).name() << " INIT\n";
}

friendClassDefined0::~friendClassDefined0()
{
	cout << typeid(*this).name() << " DEINIT\n";
}

friendClassDefined1::friendClassDefined1()
{
	cout << typeid(*this).name() << " INIT\n";
}

friendClassDefined1::~friendClassDefined1()
{
	cout << typeid(*this).name() << " DEINIT\n";
}

friendClassInitialized0::friendClassInitialized0()
{
	base testBase;

	cout << typeid(*this).name() << " INIT\n";
}

friendClassInitialized0::~friendClassInitialized0()
{
	cout << typeid(*this).name() << " DEINIT\n";
}

friendClassInitialized1::friendClassInitialized1()
{
	cout << typeid(*this).name() << " INIT\n";
}

friendClassInitialized1::~friendClassInitialized1()
{
	cout << typeid(*this).name() << " DEINIT\n";
}

void friendClassInitialized1::initBase()
{
	base testBase;

	cout << typeid(*this).name() << " INIT\n";
}

void friendFuncInit()
{
	base testBase;

	cout << "Friend func init base\n";
}

void friendFuncNoInit()
{
	cout << "Friend func no init base\n";
}
