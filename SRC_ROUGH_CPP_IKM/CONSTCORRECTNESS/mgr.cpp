#include <iostream>
#include <vector>
#include "def.h"

using namespace std;

int main()
{
	int anInt = 25;
	int const aConstInt0 = 1;
	const int aConstInt1 = 1;
	
	int ptrToInts[2] = {1,2}; //Not made const pointer as incrementable
	int * const ptrToIntHeap = new int(1);
	int * const ptrToIntStack = &anInt;

	//char * aConstString0 = "hello world"; //illegal
	const char * aConstString1 = "hello world";

	const int ptrToConstInts[2] {1,2}; //Not made const pointer as incrementable
	const int * const constPtrToConstIntHeap = new const int(1);
	const int * const constPtrToConstIntStack = &aConstInt0;

	constCorrectness testConstCorrectness;
	const constCorrectness testConstCorrectnessConst;

	vector<int> aVector;

	cout << "\nCONST CORRECTNESS -- view source for elaboration\n\n";

	cout << "Const func " << doNotModify(anInt) << endl; //Same as below
	cout << "Const func " << doNotModify(aConstInt0) << endl;
	
	cout << "String cast\n";
	improper_string_notconst(const_cast<char *>(aConstString1));

	cout << "\nTEST CLASSES\n\n";

	testConstCorrectness.demonstrateAccess();	
	testConstCorrectnessConst.demonstrateAccess();

	testConstCorrectness.varyByKeyword(anInt);	
	testConstCorrectness.varyByKeyword(aConstInt0);	
	testConstCorrectnessConst.varyByKeyword(anInt);	
	testConstCorrectnessConst.varyByKeyword(aConstInt0);	

	cout << "\nCONST VEC ITERATOR OVER NON CONST VECTOR TO PREVENT CHANGE AKA CONST VEC ACTION\n\n";

	aVector.push_back(1);
	aVector.push_back(2);
	aVector.push_back(3);

	for(vector<int>::const_iterator i = aVector.begin(), j = aVector.end(); i != j; ++i)
	{
		//*i = 4; //illegal
		cout << *i << endl;
	}
	
	return 0;
}
