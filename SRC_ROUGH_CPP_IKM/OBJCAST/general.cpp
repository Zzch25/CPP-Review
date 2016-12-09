/*
 *
 */

#include <iostream>
#include "def.h"

using namespace std;

base::base()
					{
					pubVar = 0,
					pubVarBase = 0,
					proVar = 0,
					proVarBase = 0,
					priVar = 0,
					priVarBase = 0;
					};
base::~base() {};

child::child()
					{
					pubVar = 1,
					pubVarChild = 1,
					proVar = 1,
					proVarChild = 1,
					priVar = 1,
					priVarChild = 1;
					};
child::~child() {};

base_virt::base_virt()
					{
					pubVar = 0,
					pubVarBase = 0,
					proVar = 0,
					proVarBase = 0,
					priVar = 0,
					priVarBase = 0;
					};
base_virt::~base_virt() {};

child_virt::child_virt()
					{
					pubVar = 1,
					pubVarChild = 1,
					proVar = 1,
					proVarChild = 1,
					priVar = 1,
					priVarChild = 1;
					};
child_virt::~child_virt() {};


void base::pubFunc()
{
	cout << "BASE PUB\n" << pubVar << pubVarBase << endl;
	proFunc();
};

void base::basePubFunc()
{
	cout << "BASE BASE PUB\n" << pubVar << pubVarBase << endl;
	baseProFunc();
};

void base::proFunc()
{
	cout << "BASE PRO\n" << proVar << proVarBase << endl;
	priFunc();
};

void base::baseProFunc()
{
	cout << "BASE BASE PRO\n" << proVar << proVarBase << endl;
	basePriFunc();
};

void base::priFunc()
{
	cout << "BASE PRI\n" << priVar << priVarBase << endl;
};

void base::basePriFunc()
{
	cout << "BASE BASE PRI\n" << priVar << priVarBase << endl;
};

void child::pubFunc()
{
	cout << "CHILD PUB\n" << pubVar << pubVarChild << endl;
	proFunc();
};

void child::childPubFunc()
{
	cout << "CHILD CHILD PUB\n" << pubVar << pubVarChild << endl;
	childProFunc();
};

void child::proFunc()
{
	cout << "CHILD PRO\n" << proVar << proVarChild << endl;
	priFunc();
};

void child::childProFunc()
{
	cout << "CHILD CHILD PRI\n" << proVar << proVarChild << endl;
	childPriFunc();
};

void child::priFunc()
{
	cout << "CHILD PRI\n" << priVar << priVarChild << endl;
};

void child::childPriFunc()
{
	cout << "CHILD CHILD PRI\n" << priVar << priVarChild << endl;
};

void base_virt::pubFunc()
{
	cout << "VIRT " << "BASE PUB\n" << pubVar << pubVarBase << endl;
	proFunc();
};

void base_virt::basePubFunc()
{
	cout << "VIRT " << "BASE BASE PUB\n" << pubVar << pubVarBase << endl;
	baseProFunc();
};

void base_virt::proFunc()
{
	cout << "VIRT " << "BASE PRO\n" << proVar << proVarBase << endl;
	priFunc();
};

void base_virt::baseProFunc()
{
	cout << "VIRT " << "BASE BASE PRO\n" << proVar << proVarBase << endl;
	basePriFunc();
};

void base_virt::priFunc()
{
	cout << "VIRT " << "BASE PRI\n" << priVar << priVarBase << endl;
};

void base_virt::basePriFunc()
{
	cout << "VIRT " << "BASE BASE PRI\n" << priVar << priVarBase << endl;
};

void child_virt::pubFunc()
{
	cout << "VIRT " << "CHILD PUB\n" << pubVar << pubVarChild << endl;
	proFunc();
};

void child_virt::childPubFunc()
{
	cout << "VIRT " << "CHILD CHILD PUB\n" << pubVar << pubVarChild << endl;
	childProFunc();
};

void child_virt::proFunc()
{
	cout << "VIRT " << "CHILD PRO\n" << proVar << proVarChild << endl;
	priFunc();
};

void child_virt::childProFunc()
{
	cout << "VIRT " << "CHILD CHILD PRI\n" << proVar << proVarChild << endl;
	childPriFunc();
};

void child_virt::priFunc()
{
	cout << "VIRT " << "CHILD PRI\n" << priVar << priVarChild << endl;
};

void child_virt::childPriFunc()
{
	cout << "VIRT " << "CHILD CHILD PRI\n" << priVar << priVarChild << endl;
};

void base_virt::pubFuncVirt()
{
	cout << "VIRT " << "BASE PUB VIRT\n" << pubVar << pubVarBase << endl;
	proFuncVirt();
};

void base_virt::basePubFuncVirt()
{
	cout << "VIRT " << "BASE BASE PUB VIRT\n" << pubVar << pubVarBase << endl;
	baseProFuncVirt();
};

void base_virt::proFuncVirt()
{
	cout << "VIRT " << "BASE PRO VIRT\n" << proVar << proVarBase << endl;
	priFuncVirt();
};

void base_virt::baseProFuncVirt()
{
	cout << "VIRT " << "BASE BASE PRO VIRT\n" << proVar << proVarBase << endl;
	basePriFuncVirt();
};

void base_virt::priFuncVirt()
{
	cout << "VIRT " << "BASE PRI VIRT\n" << priVar << priVarBase << endl;
};

void base_virt::basePriFuncVirt()
{
	cout << "VIRT " << "BASE BASE PRI VIRT\n" << priVar << priVarBase << endl;
};

void child_virt::pubFuncVirt()
{
	cout << "VIRT " << "CHILD PUB VIRT\n" << pubVar << pubVarChild << endl;
	proFuncVirt();
};

void child_virt::childPubFuncVirt()
{
	cout << "VIRT " << "CHILD CHILD PUB VIRT\n" << pubVar << pubVarChild << endl;
	childProFuncVirt();
};

void child_virt::proFuncVirt()
{
	cout << "VIRT " << "CHILD PRO VIRT\n" << proVar << proVarChild << endl;
	priFuncVirt();
};

void child_virt::childProFuncVirt()
{
	cout << "VIRT " << "CHILD CHILD PRI VIRT\n" << proVar << proVarChild << endl;
	childPriFuncVirt();
};

void child_virt::priFuncVirt()
{
	cout << "VIRT " << "CHILD PRI VIRT\n" << priVar << priVarChild << endl;
};

void child_virt::childPriFuncVirt()
{
	cout << "VIRT " << "CHILD CHILD PRI VIRT\n" << priVar << priVarChild << endl;
};
