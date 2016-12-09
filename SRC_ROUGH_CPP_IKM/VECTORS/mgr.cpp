#include <iostream>
#include <vector>
#include "def.h"

using namespace std;

int main()
{
	int i, j, intArr[] = {1,2,3,4};

	vector< vector<int> > vecVecInts;
	vector<int> vecInts;
	vector<int> vecIntsInit(5, 25);
	vector<int> vecIntsVecItrInit(vecIntsInit.begin(),vecIntsInit.end());
	vector<int> vecIntsVecCopyItrInit(vecIntsVecItrInit);
	vector<int> vecIntsArrCopyItrInit(intArr, intArr + sizeof(intArr) / sizeof(int));

	vecVecInts.push_back(vecInts);
	vecVecInts.push_back(vecIntsInit);
	vecVecInts.push_back(vecIntsVecItrInit);
	vecVecInts.push_back(vecIntsVecCopyItrInit);
	vecVecInts.push_back(vecIntsArrCopyItrInit);

	vector< vector<int> >::iterator itrVecs;
	vector<int>::iterator itrInts;

	for(i = 0, itrVecs = vecVecInts.begin(); itrVecs != vecVecInts.end(); ++itrVecs)
	{
		cout << "Iterating vector " << ++i << endl;
		for(j = 0, itrInts = itrVecs->begin(); itrInts != itrVecs->end(); ++itrInts)
			cout << "Vector Elem " << ++j << " == " << *itrInts << endl; 
	}

	cout << "See reference for more functionality\n\n";

	return 0;
}
