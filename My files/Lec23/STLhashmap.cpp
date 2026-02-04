#include <iostream>
#include <unordered_map>
//in stl we have ordered and unordered maps

using namespace std;
int main(int argc, char const *argv[])
{
	unordered_map<string, int> map;
	// pair<string, int> p=make_pair("Apple",201);
	// map.insert(p);
	map.insert(make_pair("Mango",500));
	map.insert(make_pair("Orange",50));
	map.insert(make_pair("Guava",20));
	map.insert(make_pair("Grapes",60));

	//map.insert_or_assign("Kiwi",95); ->in C++17

	map["Kiwi"]=95;
	map["Mango"]=100;

	//map.clear(); ->clears the whole Hashmap

	//map.erase("Orange");

	for(auto it:map)
	{
		// cout<<it.first<<" "<<map[it.first]<<endl;

		cout<<it.first<<" "<<it.second<<endl;
	}

	// if(!map.empty())
	// {
	// 	cout<<map.size()<<endl;
	// }
	// cout<<map.max_size()<<endl;

	if(map.find("Mango")!=map.end())
	{
		cout<<"Found"<<endl;
	}
	else
	{
		cout<<"Not Found"<<endl;
	}

	cout<<map.count("Orange")<<endl;
	cout<<map.count("Hello")<<endl;
	cout<<map.count("Mango")<<endl;
	return 0;
}