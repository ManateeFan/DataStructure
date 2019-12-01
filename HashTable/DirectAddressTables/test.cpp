#include "DirectAddressTables.h"
#include <iostream>

using namespace std;

int main()
{
	DirectAddressTable<int, 20> table;
	table.Insert(1, 1);
	table.Insert(2, 2);
	cout << table.Search(1)->value << endl;
	cout << table.Search(2)->value << endl;
	return 0;
}
