//unordered_map is unsorted 
//map is ordered it is sorted
//look at the output strings as keys are sorted in map but unsorted in unordered_map
#include <iostream>
#include <map>
#include <unordered_map>
using namespace std;
int main(int argc, char const *argv[])
{
	cout<<"**********************************unordered_map************************************"<<endl;
	unordered_map<string, int> unOrderHash;

	//insertion-1
	unOrderHash["apple"]=500;
	unOrderHash["mango"]=1000;

	//insertion-2
	unOrderHash.insert(make_pair("banana",200));
	unOrderHash.insert(make_pair("guava",250));

	//searching-1
	if(unOrderHash.count("apple")==1)//count returns count of the elements or value whose key is apple 
	//but unordered_map stores only unique values corresponding to a particular key
	//so it returns 1 if present and 0 if not present 
	{
		cout<<"apple price = "<<unOrderHash["apple"]<<endl;
	}
	else
	{
		cout<<"apple does not exist"<<endl;
	}

	//searching-2
	auto itr2=unOrderHash.find("apple");//or we can do-> unordered_map<string,int>:: iterator itr=unOrderHash.find("apple");
	if(itr2!=unOrderHash.end())//begin() and end() returns iterator to begin and end respectively
	{
		cout<<"apple price = "<<itr2->second<<endl;
	}
	else
	{
		cout<<"apple does not exist"<<endl;
	}

	//print hashmap
	for(auto itr:unOrderHash)
	{
		cout<<itr.first<<" -> "<<itr.second<<endl;
	}

	//deletion
	unOrderHash.erase("apple");
	unOrderHash.erase("guava");

	//print hashmap
	cout<<"After deletion................."<<endl;
	for(auto itr:unOrderHash)
	{
		cout<<itr.first<<" -> "<<itr.second<<endl;
	}

	cout<<"**********************************map(it is ordered)************************************"<<endl;
	map<string,int> order;

	//insertion-1
	order["apple"]=500;
	order["mango"]=1000;

	//insertion-2
	order.insert(make_pair("banana",200));
	order.insert(make_pair("guava",250));

	//searching-1
	if(order.count("apple")==1)//count returns count of the elements or value whose key is apple 
	//but unordered_map stores only unique values corresponding to a particular key
	//so it returns 1 if present and 0 if not present 
	{
		cout<<"apple price = "<<order["apple"]<<endl;
	}
	else
	{
		cout<<"apple does not exist"<<endl;
	}

	//searching-2
	auto itr1=order.find("apple");//or we can do-> unordered_map<string,int>:: iterator itr=order.find("apple");
	if(itr1!=order.end())//begin() and end() returns iterator to begin and end respectively
	{
		cout<<"apple price = "<<itr1->second<<endl;
	}
	else
	{
		cout<<"apple does not exist"<<endl;
	}

	//print hashmap
	for(auto itr:order)
	{
		cout<<itr.first<<" -> "<<itr.second<<endl;
	}

	//deletion
	order.erase("apple");
	order.erase("guava");

	//print hashmap
	cout<<"After deletion................."<<endl;
	for(auto itr:order)
	{
		cout<<itr.first<<" -> "<<itr.second<<endl;
	}

	return 0;
}