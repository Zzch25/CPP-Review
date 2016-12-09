#include <iostream>
#include <cstring>
#include "def.h"

using namespace std;

int main()
{
	cout << "\n\n<!>>>See source for comprehending ideas on all, minimal prints<<<!>\n\n\n";

	//struct simpleStructTypeNotInNamespace fails;
	simpleStructTypeNotInNamespace(); //technically not incorrect however the compiler sees a reference and dissallows during multiple inclusion

	defaultEnum testDefaultEnum = c;

	cout << "Default enum var 'c' :: " << testDefaultEnum << endl;

	customBooleanEnum testCustomBooleanEnum = customTrue;
	customBooleanEnum testSetCustomBooleanEnum = (customBooleanEnum)2;

	cout << "Custom boolean enum var 'customTrue' :: " << testCustomBooleanEnum << endl;
	cout << "Custom boolean enum custom set :: " << testSetCustomBooleanEnum << endl;

	customAndDefaultEnum testCustomAndDefaultEnum = e;

	cout << "Custom and default enum var 'e' :: " << testCustomAndDefaultEnum << endl;

	cout << "Print enums without declaration :a b c customTrue customFalse d e f g h i: " << a << b << c << customTrue << customFalse << d << e << f << g << h << i << endl;

	simpleUnion testSimpleUnion0 = {1};
	simpleUnion testSimpleUnion1;
	simpleUnion testSimpleUnion2;

	testSimpleUnion1.unionFunc();
	simpleUnion::unionClass testUnionClassToCopy;
	testUnionClassToCopy.unionClassSetFunc();
	memcpy(&testSimpleUnion2, &testUnionClassToCopy, sizeof(testUnionClassToCopy));

	cout << "\n\nSEE RES OF GET FROM UNION CLASS :: " << testSimpleUnion2.testUnionClass.unionClassGetFunc() << "\n\n";

	nestedClassesStruct testNestedClassesStruct;

	return 0;
}
