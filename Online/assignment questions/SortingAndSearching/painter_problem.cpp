// PAINTER PROBLEM
// You have to paint N boards of length {A0, A1, A2, A3 … AN-1}. There are K painters available and you are also given how much time a painter takes to paint 1 unit of board. You have to get this job done as soon as possible under the constraints that any painter will only paint contiguous sections of board. Return the ans % 10000003

// Input Format:
// 1<=N<=100000 1<=K<=100000 1<=T<=1000000 1<=Li<=100000

// Constraints:
// 1<=N<=100000 1<=K<=100000 1<=T<=1000000 1<=Li<=100000

// Output Format
// Return minimum time required to paint all boards % 10000003.

// Sample Input
// 2
// 2          
// 5
// 1 10
// Sample Output
// 50

#include<bits/stdc++.h>

using namespace std;

bool check(int arr[],int n,int k,int mid)
{
	int sum=0;
	for(int i=0;i<n;i++)
	{
		if(mid<arr[i])
		{
			return false;
		}
		sum+=arr[i];
		if(sum>mid)
		{
			k--;
			if(k==0)
			{
				return false;
			}
			sum=arr[i];
		}
	}
	return true;
}

int findmin(int arr[],int n,int k,int t)
{
	int low=INT_MAX,high=0,ans=0;
	for(int i=0;i<n;i++)
	{
		if(arr[i]<=low)
		{
			low=arr[i];
		}
		high+=arr[i];
	}
	while(low<=high)
	{
		int mid=low+(high-low)/2;
		bool possible=check(arr,n,k,mid);
		if(possible)
		{
			ans=mid;
			high=mid-1;
		}
		else
		{
			low=mid+1;
		}
	}
	return ans*t;
}

int main()
{
	int n,k,t,arr[100000];
	cin>>n>>k>>t;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	cout<<findmin(arr,n,k,t);
	return 0; 
}