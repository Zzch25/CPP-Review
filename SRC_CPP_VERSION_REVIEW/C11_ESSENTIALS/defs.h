/*
 *
 */

#ifndef DEFS_ROOT
#define DEFS_ROOT

#define THE_ANSWER 25

#include <memory>
#include <functional>

using namespace std;

/*AUTO****************************************/

//Three of the same function

//Anon type returns are available, useful in overloads
template <typename T>
auto anAutoTemplatedFunctionWithDecType(T in) -> decltype(in) //int, string, blah... useful as class item delcarations out of scope until the compilation completes are solved via auto ... -> type vs class::type ...
{
	return in;
}

template <typename T>
auto anAutoTemplatedFunctionWithoutDecType(T in) -> T
{
	return in;
}

template <typename T>
T aTemplatedFunctionWithTReturnType(T in)
{
	return in;
}

//Compilation scope demonstration
class aScopeDemonstrationNotInlined
{	
	public:
		enum testEnum_e
		{
			anElem
		};
		testEnum_e getTestEnum0();
		testEnum_e getTestEnum1();
	private:
		testEnum_e testEnum;
};

//Same as the next function
auto aScopeDemonstrationNotInlined::getTestEnum0() -> testEnum_e
{
	return testEnum;
}

aScopeDemonstrationNotInlined::testEnum_e aScopeDemonstrationNotInlined::getTestEnum1()
{
	return testEnum;
}

/*NULLPTR*************************************/

void aPtrFunc(int *in) {}
void aSharedPtrFunc(shared_ptr<int> in) {}

/*OVERRIDE*&*FINAL****************************/

//Without override protection
class primary
{
	public:
		virtual void aFunc(char) {cout << "primary\n";};
};

//Two examples on how overloads occur instead of overrides, or sometimes intended inheritance
class secondaryOverload0: public primary
{
	public:
		virtual void aFunc(int) {cout << "secondaryOverload0\n";};
};

class secondaryOverload1: public primary
{
	public:
		virtual void aFunc(char) const {cout << "secondaryOverload1\n";};
};

//A chain of examples, demonstrating how they cannot compile when incorrectly applied

class secondaryForFinal: public primary
{
	public:
		virtual void aFunc(char) final {cout << "secondaryForFinal\n";};
};

/*
class secondaryFailOverrideFinal: public secondaryForFinal
{
	public:
		virtual void aFunc(char) {cout << "secondaryFailOverrideFinal\n";};
};

class secondaryFailOverrideParent: public parent
{
	public:
		virtual void aFunc(int) override {cout << "secondaryFailOverrideParent\n";};
};
*/

class secondaryOverrideAndFinal: public primary
{
	public:
		virtual void aFunc(char) override final {cout << "secondaryOverideAndFinal\n";};
};

/*STRONGLY*TYPED*ENUMS************************/

//enums originally have the issue where they consume
//definitions, now enums can be set and used in a more
//restrictive format

enum class aStronglyTypedEnum
{
	elemOne,
	elemTwo = 1,
	elemThree
};

enum aWeaklyTypedEnum
{
	elemOne_e,
	elemTwo_e,
	elemThree
};

/*SMART*POINTERS******************************/

void smartPointerFunc(int *in) {};

/*LAMBDAS*************************************/

//Functions for anonymous calling

void aFuncForLambda0() {cout << "LF0\n";}
void aFuncForLambda1(int in) {cout << "LF1 " << in << endl;}
int aFuncForLambda2() {cout << "LF3\n"; return 25;}
int aFuncForLambda3(int in) {cout << "LF4\n"; return in;}
int aFuncForLambda4(int in0, int in1) {cout << "LF4\n"; return in0 + in1;}

struct aStructForLambda
{
	aStructForLambda(int in) : val(in) {cout << "SC\n";}
	void aStructFuncForLambda(int in) const {cout << "SF " << in << endl;}

	int val;
};

struct aStructForLambdaOverload
{
	void operator()(int in) const {cout << "SO " << in << endl;}
};

/*STATIC*ASSERT*AND*TYPE*TRAITS***************/

//Assume numeric
template <typename T0, typename T1>
auto anAddFuncWithAsserts(T0 x, T1 y) -> decltype(x + y)
{
	static_assert(is_integral<T0>::value, "T0 must be integral");
	static_assert(is_integral<T1>::value, "T1 must be integral");

	return x + y;
}

/*MOVE*SEMANTICS******************************/

//NOTE these will be initiated instead of a copy when given an rvalue, duh
template <typename T>
class forMoving
{
	static int gId;

	int id;
	unique_ptr<T> elem;

	public:
		forMoving(): id(gId), elem(new T) {}

		//Move
		forMoving(forMoving &&in):
			id(in.id),
			elem(move(in.elem))
		{
			in.id = 0;
			in.elem = nullptr;
		}

		//Move Assign
		forMoving& operator=(forMoving &&in)
		{
			assert(this != in);
			
			elem = nullptr;
			
			id = in.id;
			elem = move(in.elem);

			in.id = 0;
			in.elem = nullptr;
		}
};

template <typename T>
int forMoving<T>::gId = 0;

#endif
