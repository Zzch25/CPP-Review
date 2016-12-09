#include <iostream>
#include "def.h"

using namespace std;

int main()
{
	base testBase;
	child testChild;
	base_virt testBaseVirt;
	child_virt testChildVirt;

	cout << "testing base...\n\n";

	testBase.pubFunc();
	testBase.basePubFunc();

	cout << "\ntesting child...\n\n";
	
	testChild.pubFunc();
	testChild.childPubFunc();

	cout << "\ntesting base virt...\n\n";

	testBaseVirt.pubFunc();
	testBaseVirt.basePubFunc();

	cout << "\ntesting child virt...\n\n";
	
	testChildVirt.pubFunc();
	testChildVirt.childPubFunc();

	cout << "\ntesting base virt virt...\n\n";

	testBaseVirt.pubFuncVirt();
	testBaseVirt.basePubFuncVirt();

	cout << "\ntesting child virt virt...\n\n";
	
	testChildVirt.pubFuncVirt();
	testChildVirt.childPubFuncVirt();

	cout << "\ntesting base child casts...\n\n";

	base &childToBase = testChild;
	base &convertBaseRef = static_cast<base&>(childToBase);
	base *convertBasePtr = static_cast<base*>(&childToBase);
	//child &convertChild = dynamic_cast<child&>(childToBase); //NOT POLYMORPHIC
	//child &convertChildRef = dynamic_cast<child&>(convertBaseRef); //NOT POLYMORPHIC

	cout << "REF\n";
	convertBaseRef.pubFunc();
	convertBaseRef.basePubFunc();
	//convertBaseRef.childPubFunc(); //SLICE

	cout << "PTR\n";
	convertBasePtr->pubFunc();
	convertBasePtr->basePubFunc();
	//convertBasePtr->childPubFunc(); //SLICE
	
	cout << "\ntesting base virt child virt casts...\n\n";
	
	base_virt &childToBaseVirt = testChildVirt;
	base_virt &convertBaseRefVirt = dynamic_cast<base_virt&>(childToBaseVirt);
	base_virt *convertBasePtrVirt = dynamic_cast<base_virt*>(&childToBaseVirt);
	child_virt *convertChildPtrVirt = dynamic_cast<child_virt*>(&childToBaseVirt);
	child_virt &convertChildRefVirt = dynamic_cast<child_virt&>(convertBaseRefVirt);

	cout << "REF\n";
	convertBaseRefVirt.pubFunc();
	convertBaseRefVirt.basePubFunc();
	convertBaseRefVirt.pubFuncVirt();
	convertBaseRefVirt.basePubFuncVirt();
	//convertBaseRefVirt.childPubFunc(); //SLICE
	//convertBaseRefVirt.childPubFuncVirt(); //SLICE

	cout << "PTR\n";
	convertBasePtrVirt->pubFunc();
	convertBasePtrVirt->basePubFunc();
	convertBasePtrVirt->pubFuncVirt();
	convertBasePtrVirt->basePubFuncVirt();
	//convertBasePtrVirt->childPubFunc(); //SLICE
	//convertBasePtrVirt->childPubFuncVirt(); //SLICE
	
	cout << "RECREF\n";
	convertChildRefVirt.pubFunc();
	//convertChildRefVirt.basePubFunc(); //SLICE
	convertChildRefVirt.pubFuncVirt();
	//convertChildRefVirt.basePubFuncVirt(); //SLICE
	convertChildRefVirt.childPubFunc();
	convertChildRefVirt.childPubFuncVirt();

	cout << "RECPTR\n";
	convertChildPtrVirt->pubFunc();
	//convertChildPtrVirt->basePubFunc(); //SLICE
	convertChildPtrVirt->pubFuncVirt();
	//convertChildPtrVirt->basePubFuncVirt(); //SLICE
	convertChildPtrVirt->childPubFunc();
	convertChildPtrVirt->childPubFuncVirt();

	return 0;
}
