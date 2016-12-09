/*
 *
 */

#ifndef DEFS
#define DEFS

using namespace std;

//extern

extern int aGlobalValueWhichIsVirtuallyAlmostUnacceptable;
extern void aGlobalFunctionWhichIsVirtuallyAlmostUnacceptable();

//Note to self, reboot 25OS... iasm-x86-64jmp->c<-<kernel|ring3>->c++

//inline

inline void inlineFunc()
{
	cout << "FROM INLINE FUNC\n";
};

class useInline
{
	public:
		//inlines shall not be friended in func
		void implicitInlineFunc()
		{
			cout << "CLASS FUNC IMPLICIT INLINE\n";
		};
};

//static

void printStatic();

class staticTest
{
	static int sharedStaticInt;
	
	public:
		staticTest();
		~staticTest();
		static void sharedStaticFunc();
};

#endif
