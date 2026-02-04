#include <iostream>
#include "hashmap.h"
using namespace std;
int main(int argc, char const *argv[])
{
	hashmap<int> hash;
	hash.insert("apple",100);
	cout<<hash["apple"]<<endl;
	hash.insert("mango",50);
	hash.insert("guava",120);
	hash.insert("orange",190);
	hash["banana"]=105;
	hash["papaya"]=90;
	hash.print();
	hash.erase("apple");
	hash.erase("guava");
	hash.print();
	cout<<hash["papaya"]<<endl;
	cout<<*(hash.search("mango"))<<endl;
	return 0;
}