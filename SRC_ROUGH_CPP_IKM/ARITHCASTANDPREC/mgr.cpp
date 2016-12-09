#include <iostream>
#include <iomanip>
#include <typeinfo>
#include "def.h"

using namespace std;

int main()
{
	int i, intLiterals[] = {DEFS_I0, DEFS_I1, DEFS_I2, DEFS_I3, DEFS_I4, DEFS_I5, DEFS_I6, DEFS_I7, DEFS_I8, DEFS_I9, DEFS_I10, DEFS_I11};
	double floatingPointLiterals[] = {DEFS_FP0, DEFS_FP1};
	char characterValueLiterals[] = {DEFS_CHV0, DEFS_CHV1};

	cout << "DEFS_Integer Literals...\n";
	for(i = 0; i < DEFS_NUMDEFS_I; i++)
		cout << intLiterals[i] << endl;
	cout << "Floating Point Literals...\n";
	for(i = 0; i < DEFS_NUMDEFS_FP; i++)
		cout << floatingPointLiterals[i] << endl;
	cout << "Character Value Literals...\n";
	for(i = 0; i < DEFS_NUMDEFS_CHV; i++)
		cout << (int)characterValueLiterals[i] << endl;

	signed int iX, iY, iRes;
	double dX, dRes;
	float fX, fY, fRes;
	char cX, cRes;
	short int sIX, sIRes;
	long int lIX, lIRes;
	unsigned int uIX, uIRes;

	iX = 1;
	dX = 1.0;
	fX = 1.0;
	cX = 1;
	sIX = 1;
	lIX = 1;
	uIX = 1;	

	cout << "Int ops\n" << typeid(iX + dX).name() << endl << typeid(iX + fX).name() << endl << typeid(iX + cX).name() << endl << typeid(iX + sIX).name() << endl << typeid(iX + lIX).name() << endl << typeid(iX + uIX).name() << "(aka unsigned int)" << endl;	

	iX = 22;
	iY = 7;
	dX = 7.0;
	
	dRes = iX / iY;
	fRes = iX / iY;

	cout << "Float implicit ints...\n" << typeid(dRes).name() << "::" << dRes << endl << typeid(fRes).name() << "::" << fRes << endl; 

	cout << "Precision instream set at " << DEFS_PRECISION << "...\n";

	dRes = iX / ((float)iY);
	fRes = iX / ((double)iY);

	cout << setprecision(DEFS_PRECISION) << "Float implicit cast...\n" << typeid(dRes).name() << "::" << dRes << endl << typeid(fRes).name() << "::" << fRes << endl; 
	
	cout.precision(DEFS_PRECISION);
	cout << "Precision at " << DEFS_PRECISION << "...\n";

	dRes = iX / dX;
	fRes = iX / dX;

	cout << "Float implicit one float...\n" << typeid(dRes).name() << "::" << dRes << endl << typeid(fRes).name() << "::" << fRes << endl; 

	dX = 1.0;
	fX = 1.0;

	cout << "Float Vs Double Float...\n" << typeid(dX + fX).name() << endl << typeid(fX + dX).name() << endl; //second is silly and paranoid

	lIX = 1;
	fX = 1.0;

	cout << "Float Vs Long Int...\n" << typeid(dX + lIX).name() << endl; 

	return 0;
}
