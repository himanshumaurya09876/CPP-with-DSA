// HIGHEST FREQUENCY( HASHING )
// Given an array find the number which comes with maximum frequency. It must work in O(n) time complexity.

// Input Format:
// Enter the size of the array N and add N more numbers and store in an array

// Constraints:
// Output Format
// Display the number with the maximum frequency.

// Sample Input
// 5
// 1
// 2
// 2
// 2
// 3
// Sample Output
// 2

#include <iostream>
// #include <unordered_map>
#include <map>
using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int *arr=new int[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	// unordered_map<int,int> hash;
	map<int,int> hash;
	for(int i=0;i<n;i++)
	{
		if(hash.count(arr[i]))
		{
			hash[arr[i]]++;
		}
		else
		{
			hash.insert(make_pair(arr[i],1));
		}
	}
	int maxm=0;
	int num;
	for(auto it:hash)
	{
		// cout<<it.first<<" -> "<<it.second<<endl;
		if(it.second>maxm)
		{
			maxm=it.second;
			num=it.first;
			// cout<<num<<"  "<<maxm<<endl;
		}
	}
	cout<<num<<endl;
	return 0;
}