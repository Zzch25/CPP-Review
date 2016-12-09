/*
 *
 */

#include <iostream>
#include <typeinfo>
#include "def.h"

void simpleStructTypeNotInNamespace()
{
}

nestedClassesStruct::base::base()
{
	cout << typeid(*this).name() << " INIT" << endl;
}

nestedClassesStruct::base::~base()
{
	cout << typeid(*this).name() << " DEINIT" << endl;
}

nestedClassesStruct::base::inBase::inBase()
{
	cout << typeid(*this).name() << " INIT" << endl;
}

nestedClassesStruct::base::inBase::~inBase()
{
	cout << typeid(*this).name() << " DEINIT" << endl;
}

nestedClassesStruct::child::child()
{
	cout << typeid(*this).name() << " INIT" << endl;
}

nestedClassesStruct::child::~child()
{
	cout << typeid(*this).name() << " DEINIT" << endl;
}
