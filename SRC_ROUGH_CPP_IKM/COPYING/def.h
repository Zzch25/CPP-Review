/*
 *
 */

#ifndef DEFS
#define DEFS

#include <typeinfo>

using namespace std;

class implicitCopy
{
	public:
		implicitCopy();
		~implicitCopy();
		template<class T>
		friend void reveal(T& obj);
		mutable int pubVar;
	protected:
		mutable int proVar;
	private:
		mutable int priVar;
};

class definedCopy
{
	public:
		definedCopy();
		~definedCopy();
		definedCopy(const definedCopy& in);
		definedCopy& operator=(const definedCopy& in);
		template <class T>
		friend void reveal(T& obj);
		mutable int pubVar;
	protected:
		mutable int proVar;
	private:
		mutable int priVar;
};

class noCopy
{
	public:
		noCopy();
		~noCopy();
		template <class T>
		friend void reveal(T& obj);
		mutable int pubVar;
	protected:
		mutable int proVar;
	private:
		noCopy(const noCopy& in) {};
		noCopy& operator=(const noCopy& in) {};
		mutable int priVar;
};

class selectiveCopy
{
	public:
		selectiveCopy();
		~selectiveCopy();
		selectiveCopy& operator=(const selectiveCopy& in);
		template <class T>
		friend void reveal(T& obj);
		mutable int pubVar;
	protected:
		mutable int proVar;
	private:
		selectiveCopy(const selectiveCopy& in) {};
		mutable int priVar;
};

template<class T>
void reveal(T& obj)
{
	cout << typeid(obj).name() << " VARS " << obj.pubVar << " " << obj.proVar << " " << obj.priVar << endl;
};

#endif
