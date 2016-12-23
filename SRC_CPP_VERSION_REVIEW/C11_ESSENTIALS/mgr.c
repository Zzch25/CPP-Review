/*
 *
 */

#include <iostream>
#include <map>
#include <vector>
#include <functional>
#include <algorithm>
#include "defs.h"

using namespace std;

/*
 *auto
 *
 *
 *
 *
 */
int main()
{
	/*AUTO****************************************/

	//MUST be intialized
	auto i = 25;
	auto l = 25l;
	auto s = 25ul;

	//decltype continue in defs
	//decltype extracts the type of an object
	//The following are the same
	int i_d0 = 1;
	auto i_d1 = 2;
	decltype(i_d0) i_d2 = 3;
	decltype(i_d1) i_d3 = 4;
	decltype(i_d2) i_d4 = 5;

	cout << "SEE MGR & FUNCTION DEFS REGARDING CASES FOR AUTO AND DECL\n\n";

	/*NULLPTR**************************************/

	int *p1, *p2, assignInt;
	bool assignBool;

	p1 = NULL;
	p2 = nullptr;

	if(p1 == p2)
		cout << "NULLS COMPARED EQUAL\n";

	aPtrFunc(p1);
	aPtrFunc(p2);
	aSharedPtrFunc(nullptr);
	//aSharedPtrFunc(p1/p2);

	assignBool = p2;

	cout << "SEE DEFS REGARDING NULL FUNCS\n\n";

	/*RANGES**************************************/

	//Iterations via different structures
	int anArr[] = {1,2,3};
	map<string, vector<string>> aMap;
	vector<string> aVector;

	aVector.push_back("A ");
	aVector.push_back("Map ");
	aVector.push_back("Element");

	aMap["aStringIdentifierForAccess"] = aVector;

	for(int& itr : anArr)
		cout << itr << ' ';
	cout << endl;

	for(const auto& forEachItr : aMap)
	{
		cout << forEachItr.first << " index...\n";
		for(auto vectorIterator : aVector)
			cout << vectorIterator;
		cout << endl;
	}

	cout << "RANGES, SEE SOURCE\n\n";	

	/*OVERRIDE*&*FINAL****************************/	

	cout << "OVERIDE AND FINAL, SEE SOURCE\n\n";	

	/*STRONGLY*TYPED*ENUMS************************/

	//Out of scope
	//int takeElemOne = elemOne;	
	int takeElemOne = elemOne_e;
	//Strong declaration
	//int takeElemTwo = aStronglyTypedEnum::elemTwo;
	aStronglyTypedEnum testAStronglyTypedEnum = aStronglyTypedEnum::elemTwo;

	cout << "STRONGLY TYPED ENUMS, SEE SOURCE\n\n";

	/*SMART*POINTERS******************************/

	//Only allows move construct
	unique_ptr<int> aUniquePointer(new int);
	unique_ptr<int> aUniquePointerNoInit;

	//Allows modding and swapping.. copying and such
	shared_ptr<int> aSharedPointer(new int);
	shared_ptr<int> aSharedPointerNoInit;

	//Shares and does not dictate life of a pointer
	weak_ptr<int> toTake;
	toTake = aSharedPointer;

	//And on and on
	aSharedPointerNoInit = aSharedPointer;
	aUniquePointerNoInit = move(aUniquePointer);
	aSharedPointerNoInit = make_shared<int>(); //More effective allocation, no memory leaks EG seed()
	
	//C14
	//aUniquePointerNoInit = make_unique<int>(); //More effective allocation, no memory leaks EG seed()
	
	//C11
	aUniquePointerNoInit = unique_ptr<int>();

	aSharedPointerNoInit = shared_ptr<int>();

	//Weak access must affirm
	int ret = *toTake.lock();
	aSharedPointer.reset();
	bool isDone = toTake.expired();

	cout << "SMART POINTERS, SEE SOURCE\n\n";

	/*LAMBDA**************************************/

	//aFuncForLambda () int
	//aStructForLambda ()W/INT aStructFuncForLambda ()W/INT

	function<void()> lFunc0 = aFuncForLambda0;
	function<void(int)> lFunc1 = aFuncForLambda1;
	function<int()> lFunc2 = aFuncForLambda2;	
	function<int(int)> lFunc3 = aFuncForLambda3;
	
	lFunc0();
	lFunc1(1);
	lFunc2();
	lFunc3(1);

	function<void()> lFunc4 = []()
	{
		aFuncForLambda0();
	};
	function<void()> lFunc5 = bind(aFuncForLambda1, 1);

	lFunc4();
	lFunc5();

	function<void(const aStructForLambda&, int)> lFunc6 = &aStructForLambda::aStructFuncForLambda;
	function<int(aStructForLambda const&)> lFunc7 = &aStructForLambda::val;

	aStructForLambda testAStructForLambda(1);
	lFunc6(testAStructForLambda,2);
	lFunc7(testAStructForLambda);

	//placeholders go _1 to _N

	auto placeholderSample0 = bind(aFuncForLambda1,std::placeholders::_1);
	auto placeholderSample1 = bind(aFuncForLambda4,100,std::placeholders::_1);
	placeholderSample0(1);
	placeholderSample1(1);

	function<void(int)> lFunc8 = bind(&aStructForLambda::aStructFuncForLambda, testAStructForLambda, std::placeholders::_1);
	function<void(int)> lFunc9 = bind(&aStructForLambda::aStructFuncForLambda, &testAStructForLambda, std::placeholders::_1);

	lFunc8(1);
	lFunc9(1);

	function<void(int)> lFunc10 = aStructForLambdaOverload();

	lFunc10(1);

	vector<int> aVectorForLambda;
	aVectorForLambda.push_back(2);
	aVectorForLambda.push_back(1);

	//Pure anon
	auto newFunc = [](int in) {return (int)(in == 1);};
	for_each(begin(aVectorForLambda), end(aVectorForLambda), [](int in) {cout << in << endl;});

	auto iterForOne = find_if(begin(aVectorForLambda), end(aVectorForLambda), newFunc);
	if(iterForOne != end(aVectorForLambda))
		cout << "One is not last: " << *iterForOne << endl;

	function<int(int)> decrease = [&decrease](int in) {return (in > 1) ? decrease(in - 1) : in;};
	
	cout << "LAMBDA, SEE SOURCE\n\n";

	/*NON*MEMBER*BEGIN*&*END**********************/

	int anArrForBeginAndEnd[] = {23,25,26};

	for_each(begin(anArrForBeginAndEnd), end(anArrForBeginAndEnd), [](int in) {cout << in << endl;});
	
	auto iterFor25 = find_if(begin(anArrForBeginAndEnd), end(anArrForBeginAndEnd), [](int in) {return in == 25;});
	
	if(iterFor25 != end(anArrForBeginAndEnd))
		cout << "25 is never last: " << *iterFor25 << endl;

	cout << "NON MEMBER BEGIN & END, SEE SOURCE\n\n";

	/*STATIC*ASSERT*AND*TYPE*TRAITS***************/
	
	//compile time warnings
	
	static_assert(25 == THE_ANSWER, "The world most surely is on fire...");

	//anAddFuncWithAsserts("one", 2); //fails
	anAddFuncWithAsserts(1, 2);

	cout << "STATIC ASSERT AND TYPE TRAITS, SEE SOURCE\n\n";

	/*MOVE*SEMANTICS******************************/

	//PLEASE note the example is in defs, it is simple. If an rvalue is passed they will execute

	cout << "MOVE SEMANTICS, SEE SOURCE\n\n";

	return 0;
}
