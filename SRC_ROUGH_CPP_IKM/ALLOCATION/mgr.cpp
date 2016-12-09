#include <iostream>
#include <stdlib.h>
#include "def.h"

using namespace std;

int main()
{
	int i, *arr123, *intPtr;
	string *testTwoStrings;

	/*
	 *Note that off the stack objects allocated must be triggered
	 *for destruction eg delete and such. Duh, duh duh duh
	 *
	 *Also keep in mind standard allocation cycle for stack object, tbd in orderdestruct
	 */

	cout << "\nSIMPLE MALLOC\n\n";

	//malloc does not throw exceptions AND there is no implicit conversion for pointers hence the cast
	if((arr123 = (int*)malloc(sizeof(int)*DEFS_ARR123_SZ)) == 0)
		return -1;

	for(i = 0; i < DEFS_ARR123_SZ; ++i)
	{
		arr123[i] = i + 1;
		cout << "ARR AT " << i << " is " << arr123[i] << endl;
	}

	free(arr123);

	cout << "\nSIMPLE NEW\n\n";

	//New is bulky and here should only fail in the event of no availble memory occurences, do not try catch
	if((arr123 = new int(3)) == NULL)
		return -1;

	for(i = 0; i < DEFS_ARR123_SZ; ++i)
	{
		arr123[i] = i + 1;
		cout << "ARR AT " << i << " is " << arr123[i] << endl;
	}

	delete[] arr123;

	cout << "\nSIMPLE SINGULAR NEW\n\n";

	//again, use of try catch is truly irrelevant here, besides new should be avoided in such trivial cases
	if((intPtr = new int) == NULL)
		return -1;
	*intPtr = 25;

	cout << "Int ptr " << *intPtr << endl;

	delete intPtr;

	cout << "\nSIMPLE INLINED ALLOCATOR\n\n";

	cout << "int arr...\n";

	arr123 = allocFill<int>(DEFS_ARR123_SZ);

	for(i = 0; i < DEFS_ARR123_SZ; ++i)
	{
		arr123[i] = i + 1;
		cout << "ARR AT " << i << " is " << arr123[i] << endl;
	}

	allocFree<int>(arr123, DEFS_ARR123_SZ);

	cout << "string arr...\n";

	testTwoStrings = allocFill<string>(DEFS_TESTTWOSTRINGS_SZ);

	for(i = 0; i < DEFS_TESTTWOSTRINGS_SZ; ++i)
	{
		(testTwoStrings[i]).assign("A STRING");
		cout << "ARR AT " << i << " is " << testTwoStrings[i] << endl;
	}

	allocFree<string>(testTwoStrings, DEFS_TESTTWOSTRINGS_SZ);
	//free(testTwoStrings); //may not operate on same heap
	
	for(i = 0; i < DEFS_TESTTWOSTRINGS_SZ; ++i)
	{
		(testTwoStrings[i]).assign("A STRING");
		cout << "ARR AT " << i << " is " << testTwoStrings[i] << endl;
	}

	cout << "simple int...\n";

	intPtr = allocFill<int>();
	*intPtr = 25;

	cout << "Int ptr " << *intPtr << endl;
	
	allocFree<int>(intPtr);

	int **x = new int*[1];
	*x = new int[1];

	x[0][0] = 2;

	cout << "ARRAY ARRAY :: " << x[0][0] << endl;
	
	delete [] *x;
	delete [] x;

	return 0;
}
