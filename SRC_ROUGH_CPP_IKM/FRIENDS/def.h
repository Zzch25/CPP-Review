/*
 *
 */

#ifndef DEFS
#define DEFS

using namespace std;

class EXP
{
	public:
		void printVars();
		int pubVar;
	protected:
		int proVar;
	private:
		int priVar;
};

class friends: public EXP
{
	friend class friendOfFriend;
	
	public:
		friends();
		~friends();
		friend void testPub(const friends& obj);
		template <typename T>
		friend void testTempPub(const T& obj);
		int pubVar;
	protected:
		friend void testPro(const friends& obj);
		template <typename T>
		friend void testTempPro(const T& obj);
		int proVar;
	private:
		friend void testPri(const friends& obj);
		template <typename T>
		friend void testTempPri(const T& obj);
		int priVar;
};

class friendOfFriend
{
	public:
		void testPriVar(const friends& in);
};

template <typename T> void testTempPub(const T& obj)
{
	cout << "TESTPUB " << obj.pubVar << endl;
};

template <typename T> void testTempPro(const T& obj)
{
	cout << "TESTPRO " << obj.proVar << endl;
};

template <typename T> void testTempPri(const T& obj)
{
	cout << "TESTPRI " << obj.priVar << endl;
};

#endif
