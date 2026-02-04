// SUBARRAYS WITH DISTINCT ELEMENTS
// Given an array, the task is to calculate the sum of lengths of contiguous subarrays having all elements distinct

// Input Format:
// An integer n denoting size of array followed by n integers

// Constraints:
// 1<=N<=10^5

// Output Format
// The answer mod 10^9+7

// Sample Input
// 3
// 1 2 3
// Sample Output
// 10

#include <iostream>
#include <unordered_map>
using namespace std;
int m=1000000007;

// int findAns(int arr[],int n)
// {
// 	int ans=0;
// 	int inc=0;
// 	cout<<"findans"<<endl;
// 	for(int i=0;i<n;i+=inc)
// 	{
// 		int j=i;
// 		unordered_map<int,int> hash;
// 		while(j<n && hash.find(arr[j])==hash.end())
// 		{
// 			hash[arr[j]]=j;
// 			j++;
// 		}
// 		if(j<n && hash.count(arr[j])!=0)
// 		{
// 			inc=hash[arr[j]]+1-i;
// 		}
// 		int m=j-i;
// 		ans=(ans+((m*(m+1))%mod*(m+2))/6)%mod;
// 		cout<<ans<<endl;
// 		if(j==n)
// 		{
// 			break;
// 		}
// 	}
// 	cout<<"*************"<<endl;;
// 	return ans;
// }

int findAns1(int arr[],int n)
{
	int ans=0;
	unordered_map<int,int> hash;
	int j=0;
	cout<<"findans1"<<endl;
	for(int i=0;i<n;i++)
	{
		while(j<n && hash.find(arr[j])==hash.end())
		{
			hash[arr[j]]=j;
			j++;
		}
		ans=(ans+(((j-i)*(j-i+1))%m)/2)%m;
		cout<<ans<<endl;
		hash.erase(arr[i]);
	}
	cout<<"*************"<<endl;
	return ans;
}

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int *arr=new int[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	// cout<<findAns(arr,n)<<endl;
	cout<<findAns1(arr,n)<<endl;
	return 0;
}