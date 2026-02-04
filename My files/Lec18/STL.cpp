//Standard Template Library->STL
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
	pair <string,int> p;
	p.first="Himanshu maurya";
	p.second=550522;

	pair <string,int> p1[2];
	p1[0].first="Hello";
	p1[0].second=505;
	p1[1].first="World";
	p1[1].second=566699;

	cout<<p.first<<" "<<p.second<<endl;
	cout<<p1[0].first<<" "<<p1[0].second<<endl;
	cout<<p1[1].first<<" "<<p1[1].second<<endl;

	// vector<int> v;
	// v.reserve(100);
	// for(int i=0;i<10;i++)
	// {
	// 	//v[i]=i;//segmentation fault or permission denied
	// 	v.push_back(i);
	// }
	// for(auto it:v)
	// {
	// 	cout<<it<<" ";
	// }
	// cout<<endl;
	// cout<<"Size of v is "<<v.size()<<endl;
	// cout<<"Capacity of v is "<<v.capacity()<<endl;
	// cout<<"Max size is "<<v.max_size()<<endl;
	// v.pop_back();
	// v.pop_back();
	// for(auto it:v)
	// {
	// 	cout<<it<<" ";
	// }
	// cout<<endl;
	// v.shrink_to_fit();
	// cout<<"Size of v is "<<v.size()<<endl;
	// cout<<"Capacity of v is "<<v.capacity()<<endl;
	// cout<<"Max size is "<<v.max_size()<<endl;
	// cout<<endl;
	// //we also have v.begin() and v.end() to iterate 
	// //vector can also be used to create 2D arrays ie vector of vectors
	// //vector <vector <int>> v1 ;

	return 0;
}