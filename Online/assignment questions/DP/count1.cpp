// 1 COUNT
// Given an array of size n with 0s and 1s , flip at most k 0s to get the longest possible subarray of 1s.

// Input Format:
// First Line : n, size of array and k Second Line : n space separated numbers (0s or 1s)

// Constraints:
// n <= 10^5 0 <= k <= n

// Output Format
// First Line : Size of subarray Second Line : Array after flipping k 0s

// Sample Input
// 10 2
// 1 0 0 1 0 1 0 1 0 1
// Sample Output
// 5
// 1 0 0 1 1 1 1 1 0 1

#include <iostream>
using namespace std;

int maxLength(int arr[],int n,int k)
{
	int l=0,r=0;
	int a=-1,b=-1;
	int maxl=0;
	int count0=0;
	while(r<n)
	{
		if(arr[r]==0)
		{
			count0++;
			while(count0>k)
			{
				if(arr[l]==0)
				{
					count0--;
				}
				l++;
			}
		}
		// maxl=max(maxl,r-l+1);
		if(maxl<r-l+1)
		{
			a=l;
			b=r;
			maxl=r-l+1;
		}
		r++;
	}
	for(int i=a;i<=b;i++)
	{
		arr[i]=1;
	}
	return maxl;
}

int main(int argc, char const *argv[])
{
	int n,k;
	cin>>n>>k;
	int *arr=new int[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}

	cout<<maxLength(arr,n,k)<<endl;

	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
	return 0;
}