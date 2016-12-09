/*
 *
 */

#ifndef DEFS_BP
#define DEFS_BP

using namespace std;

//STRUCTS

struct simpleStruct
{
	int x;
};

//independent struct aliased to a type for independent use
typedef struct simpleStruct typedefAliasForSimpleStruct;

//forward declaration REQUIRES static as the alias is shared
static struct simpleStructInits
{
	int x;
}aliasSimpleStructInits;

//Cannot typedef given alias redefinition

//alias becomes only in namespace
typedef struct simpleStructTypeNotInNamespace
{
	int x;
}simpleStructType;

void simpleStructTypeNotInNamespace(); //valid however confuses the compiler given there exists a reference during multiple inclusion
//void simpleStructType(); //invalid

struct nestedClassesStruct
{
	class base
	{
		int priv;

		public:
			base();
			~base();
		private:
			class inBase
			{
				public:
					inBase();
					~inBase();
			};
			inBase testInBase;
	};

	class child: base
	{
		int priv;

		public:
			child();
			~child();
	};

	child testChild;
};

//ENUMS

enum defaultEnum
{
	a,
	b,
	c
};

enum customBooleanEnum
{
	customTrue = 1,
	customFalse = 0
};

enum customAndDefaultEnum
{
	d = 3,
	e,
	f,
	g = 1,
	h,
	i
};

//UNIONS - Behaves similar to struct however maintains same memory space therefore requires a singular use. It also declares as a type

union simpleUnion
{
	int x;
	int unionFunc() {return 1;};
	class unionClass
	{
		public:
			int x;
			unionClassSetFunc() {x = 25;};
			unionClassGetFunc() {return x;};
	};
	unionClass testUnionClass;
};

struct containUnionStruct
{
	union //anon, merge two variables into memory space
	{
		int y;
		short int z;
	};
};

#endif
