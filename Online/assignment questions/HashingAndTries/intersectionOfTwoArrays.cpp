// ARRAYS-INTERSECTION OF TWO ARRAYS
// Take as input N, the size of array. Take N more inputs and store that in an array. Take N more inputs and store that in another array. Write a function which gives the intersection of two arrays in an ArrayList of integers and Print the ArrayList.

// Input Format:
// Constraints:
// Length of Arrays should be between 1 to 1000.

// Output Format
// Sample Input
// 7
// 1 2 3 1 2 4 1
// 2 1 3 1 5 2 2
// Sample Output
// [1, 1, 2, 2, 3]

#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int arr1[1000],arr2[1000],arr3[1000];
	for(int i=0;i<n;i++)
	{
		cin>>arr1[i];
	}
	for(int i=0;i<n;i++)
	{
		cin>>arr2[i];
	}
	unordered_map<int,int> mp;
	for(int i=0;i<n;i++)
	{
		if(mp.count(arr1[i]))
		{
			mp[arr1[i]]++;
		}
		else
		{
			mp[arr1[i]]=1;
		}
	}
	int j=0;
	for(int i=0;i<n;i++)
	{
		if(mp.count(arr2[i]))
		{
			if(mp[arr2[i]]>0)
			{
				mp[arr2[i]]--;
				arr3[j++]=arr2[i];
			}
			else
			{
				mp.erase(arr2[i]);
			}
		}
	}
	sort(arr3,arr3+j);
	cout<<"[";
	for(int i=0;i<j-1;i++)
	{
		cout<<arr3[i]<<", ";
	}
	cout<<arr3[j-1]<<"]"<<endl;
	return 0;
}