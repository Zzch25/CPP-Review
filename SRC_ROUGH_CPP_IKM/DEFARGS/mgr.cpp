#include <iostream>
#include "def.h"

using namespace std;

int main()
{
	//Another very simple section, basic examples

	cout << "Trivial topic, minimal template code - see code for more - not fully deffed as it is unecesary - see notes on l expressions\n\n";

	func0(4,5);
	func0(4);
	func0();
	func2(3);
	func2(4);
	func3<int,int,int>(1,2,3);
	
	return 0;
}
