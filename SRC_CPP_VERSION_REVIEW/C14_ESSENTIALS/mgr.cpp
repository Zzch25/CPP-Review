/*
 *NOTE
 *
 *ANY overlap from the C11 review that has only been slightly updated
 *in C14 will be addressed very, very, very lightly. There will not
 *be small exercises for obvious updates, only enough to register the
 *change
 *
 */

#include <iostream>
#include <vector>
#include <functional> 
#include <algorithm> 
#include "defs.h"

using namespace std;

int main()
{
	/*RETURN*TYPE*DEDUCTION***************/

	//See defs
	//The changes mentioned are INSANELY useful for refactoring
	//type changes no longer pose a problem if done correctly
	//
	//decltype has now gained the ability to auto capture types!
	
	int *x = nullptr;

	decltype(auto) y = x;

	//unlike auto this yields the deref type instead of just the type
	//
	//EXP		AUTO		DAUTO
	//1		int		int
	//x		int		int
	//(x)		int		int &
	//f(x)	int		int &&

	cout << "RETURN TYPE DEDUCTION, SEE SOURCE\n\n";

	/*GENERIC*LAMBDAS*********************/

	//Lambdas can be completely anon in a sense

	string result0, result1;	
	vector<string> aStringVector = {"A ", "String ", "Vector"};

	//C11
	auto c11Adder = [](auto x, auto y){return x + y;};
	result0 = accumulate(aStringVector.begin(), aStringVector.end(), string(""), c11Adder);
	//C14
	result1 = accumulate(aStringVector.begin(), aStringVector.end(), string(""), [](auto x, auto y){return x + y;});

	cout << "GENERIC LAMBDAS, SEE SOURCE\n\n";	

	/*INITIALIZED*LAMBDA*CAPTURES*********/	

	string stringForCapture = "string";

	//An example of capture by reference being used as a parameter per say
	auto matchStringRef = [&stringForCapture](const string &in) {in == stringForCapture;};
	//NOTE the above is not a local copy, local captures are done by value
	auto matchStringLoc = [stringForCapture](const string &in) {in == stringForCapture;};

	//KEEP in mind this raises the issue that non copyable items will not willingly accept this and allow compilation. For example unique pointers

	cout << "INITIALIZED LAMBDA CAPTURES, SEE SOURCE\n\n";	

	/*BINARY*LITERALS*&*DIGIT*SEPARATORS**/
	
	//HUUUUURRRRRRAY... Binary literals finally
	//Also. digit seperators have been introduced for readabilty
	
	int aBinaryLiteralInit = 0b11001;
	int aBinarySeperatorInit = 0b0001'1001;
	int aSeperatorInit = 9'000.01;

	//Obviously only syntactical sugar

	cout << "BINARY LITERALS & DIGIT SEPERATORS, SEE SOURCE\n\n";

	/*DEPRECIATED*************************/

	//View defs
	obsoleted0();
	obsoleted1();

	cout << "DEPRECATED, SEE SOURCE\n\n";

	/*OTHER*******************************/

	//Variable templates now exist
	//constexpr is now related allowing for multiple returns, inside case and if statements, loops, etc
	//Misc syntax updates

	cout << pi<int>::pi_def << ' ' << pi<double>::pi_def << endl;

	//And just a friendly reminder that constexpr is simply a hint to the compiler that the value can be solved at compile time. It is usable before function and variabe decs

	funcCE(1);
	
	cout << "OTHER, SEE SOURCE\n\n";

	return 0;
}
