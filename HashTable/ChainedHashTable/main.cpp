#include <iostream>
#include "ChainedHashTable.hpp"

using namespace std;

int main()
{
	ChainedHashTable<int, 10> hash;
	Item<int>* A = new Item<int>("Apple", 1);
	Item<int>* B = new Item<int>("Bana", 2);

	cout << "Hash table length: " << hash.Length() << endl;
	hash.Insert(A);
	cout << "Hash table length: " << hash.Length() << endl;
	cout << "Hsh table item number: " << hash.GetNumberOfItems() << endl;
	hash.Insert(B);
	cout << "Hash table length: " << hash.Length() << endl;
	cout << "Hsh table item number: " << hash.GetNumberOfItems() << endl;
	return 0;
}