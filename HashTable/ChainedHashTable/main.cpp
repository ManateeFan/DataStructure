//**************************************************************
//  main.cpp
//  HashTable
//
//  Created by vlyf on December 2, 2019.
//  Demonstrate a simple Hash Table in C++.
//  Implements a Link List class.
//**************************************************************

#include <iostream>
#include "ChainedHashTable.hpp"

using namespace std;

int main()
{
	ChainedHashTable<string, 10> hash;
	
	Item<string>* A = new Item<string>("Apple", "fuck");
	Item<string>* B = new Item<string>("Bana", "bitch");
	Item<string>* C = new Item<string>("Dog", "vlyf");
	Item<string>* D = new Item<string>("Handsome", "geniusvlyf");
	cout << "Hash table length: " << hash.Length() << endl;

	hash.Insert(A);
	cout << "Insert A(Apple, fuck)" << endl;
	cout << "Hash table item number: " << hash.GetNumberOfItems() << endl;
	cout << "Get item A value: " << hash.Get("Apple")->value << endl;

	cout << "-----------------------------------------" << endl;

	hash.Insert(B);
	cout << "Insert B(Bana, bitch)" << endl;
	cout << "Hash table item number: " << hash.GetNumberOfItems() << endl;
	cout << "Get item B value: " << hash.Get("Bana")->value << endl;

	cout << "-----------------------------------------" << endl;

	hash.Insert(C);
	cout << "Insert C(Dog, vlyf)" << endl;
	cout << "Hash table item number: " << hash.GetNumberOfItems() << endl;
	cout << "Get item C value: " << hash.Get("Dog")->value << endl;

	cout << "-----------------------------------------" << endl;

	hash.Insert(D);
	cout << "Insert D(Handsome, geniusvlyf)" << endl;
	cout << "Hash table item number: " << hash.GetNumberOfItems() << endl;
	cout << "Get item D value: " << hash.Get("Handsome")->value << endl;

	cout << "-----------------------------------------" << endl;
	hash.Remove("Dog");
	cout << "Remove C" << endl;
	cout << "Hash table item number: " << hash.GetNumberOfItems() << endl;
	return 0;
}