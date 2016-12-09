#include <iostream>
#include "def.h"

using namespace std;

int main()
{
	cout << "Examples reside in source, do not consider output as representation\nOther examples eg exception handling have implementations\nThis is merely a syntactical refresh\n\n";

	//These examples are hyper trivial and expect existing pointer knowledge. This merely is a syntactical refresher

	//int &illegal0;
	int anInt = 1;
	int &refInt = anInt;

	int * anIntPtr = new int(25);
	int &refIntPtrVal = *anIntPtr;
	int * &refIntPtr = anIntPtr;

	int * dupIntPtr = refIntPtr;
	int dupInt = refIntPtrVal;

	delete anIntPtr;

	//int illegal1[];
	int anArr0[] = {1,2,3};
	int anArr1[3];
	int *anArr2;
	int *anArrArr0[3];
	int *anArrArr1[3];

	anArr1[0] = 1;
	anArr1[1] = 2;
	anArr1[2] = 3;

	anArr2 = new int[2];
	anArr2[0] = 1;
	anArr2[1] = 2;
	delete [] anArr2;

	anArrArr0[0] = new int(1);
	anArrArr0[1] = new int(2);
	anArrArr0[2] = new int(3);
	delete [] anArrArr0[0];
	delete [] anArrArr0[1];
	delete [] anArrArr0[2];

	anArrArr1[0] = new int(*anArr0);
	anArrArr1[1] = new int[1];
	anArrArr1[2] = new int[3];
	delete [] anArrArr1[0];
	delete [] anArrArr1[1];
	delete [] anArrArr1[2];

	anInt = anArrArr1[0][2];
	anArrArr1[2][1] = 23;
	anInt = anArrArr1[2][1];

	//multi dimensional pointers are trivial... specifics ignored, see multi implementations in other examples eg exception handling
	
	const char *msg = "A message";

	cout << "Running NORM ON NORM...\n"	;
	
	takePointersAndArrs((void*)funcToPassNorm,(void*)msg);

	cout << "Running NORM ON TEMP...\n"	;
	
	takePointersAndArrs<int,int>((void*)testFunc,anInt,anInt - 1);
	takePointersAndArrs<char*>((void*)funcToPassNorm,const_cast<char*>(msg));
	takePointersAndArrs<char*>((void*)funcToPassNorm,(char*)(msg));

	cout << "Running TEMP ON NORM...\n"	;

	takePointersAndArrs((void*)funcToPassTemp<char*>,(char*)msg);	
		
	cout << "Running TEMP ON TEMP...\n"	;

	takePointersAndArrs<char*>((void*)funcToPassTemp<char*>,(char*)(msg));

	return 0;
}
