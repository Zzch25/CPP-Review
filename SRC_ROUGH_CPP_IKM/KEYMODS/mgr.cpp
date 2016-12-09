#include <iostream>
#include "def.h"

using namespace std;

int main()
{
	useInline testUseInline;

	cout << "\nTEST EXTERN\n\n";

	cout << aGlobalValueWhichIsVirtuallyAlmostUnacceptable << endl;
	aGlobalFunctionWhichIsVirtuallyAlmostUnacceptable;

	cout << "\nTEST CLASS\n\n";

	testUseInline.implicitInlineFunc();

	cout << "\nTEST FUNC\n\n";

	inlineFunc();

	cout << "\nTEST STATIC\n\n";

	printStatic();

	cout << "Testing class...\n";

	staticTest::sharedStaticFunc();

	staticTest testStaticTest;

	staticTest::sharedStaticFunc();

	return 0;
}
