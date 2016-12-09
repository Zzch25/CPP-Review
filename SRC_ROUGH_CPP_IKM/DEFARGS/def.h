/*
 *
 */

#ifndef DEFS
#define DEFS

using namespace std;

void func0(int x = 1, int y = 2);
void func2(int x, int y = 1); //allow for short front init

template <typename... T>
void func3(T ...args)
{
	using expander = int[];
	(void)expander{0, (void(cout << '\n' << std::forward<T>(args)),0)...};
	cout << endl;
};

class useDefaultArgs
{
	static int toFunc;
	int operator()(int x = 0) {};
	void classFunc0(int x = toFunc);
};

#endif
