/*
 *
 */

#include <iostream>
#include "def.h"

using namespace std;

base::base()
{
	protVar = 25;
	privVar = 250;

	cout << "BASE INIT\n"; 
}

base::~base()
{
	cout << "BASE DEC\n";
}

void base::funcA()
{
	cout << "BASE FUNCA\n";
}

void base::funcB()
{
	cout << "BASE FUNCB\n";
}

base::heeha::heeha()
{
	cout << "BASE HEEHA INIT\n";
}

base::heeha::~heeha()
{
	cout << "BASE HEEHA DEC\n";
}

base::heeha::heehaRun()
{
	cout << "HEEHA RAN\n";
}

childA::childA()
{
	cout << "CHILDA INIT\n"; 
}

childA::~childA()
{
	cout << "CHILDA DEC\n";
}

void childA::funcA()
{
	cout << "CHILDA FUNCA\n";
}

void childA::funcB()
{
	cout << "CHILDA FUNCB\n";
}

childB::childB()
{
	cout << "CHILDB INIT\n"; 
}

childB::~childB()
{
	cout << "CHILDB DEC\n";
}

void childB::funcA()
{
	cout << "CHILDB FUNCA\n";
}

childC::childC()
{
	cout << "CHILDC INIT\n"; 
}

childC::~childC()
{
	cout << "CHILDC DEC\n";
}

void childC::funcB()
{
	cout << "CHILDC FUNCB\n";
}

childD::childD()
{
	cout << "CHILDD INIT\n"; 
}

childD::~childD()
{
	cout << "CHILDD DEC\n";
}

void childD::accessProt()
{
	cout << "CHILDD PROT " << base::protVar << endl;
}

void childD::accessPriv()
{
	cout << "CHILDD PRIV " << base::privVar << endl;
}

childE::childE()
{
	cout << "CHILDE INIT\n"; 
}

childE::~childE()
{
	cout << "CHILDE DEC\n";
}

void childE::runheeha()
{
	cout << "CHILDE RUNHEEHA\n";
	heeha::heehaRun();
}
