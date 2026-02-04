// AGGRESSIVE COWS
// Farmer John has built a new long barn, with N (2 <= N <= 100,000) stalls. The stalls are located along a straight line at positions x1,…,xN (0 <= xi <= 1,000,000,000).

// His C (2 <= C <= N) cows don't like this barn layout and become aggressive towards each other once put into a stall. To prevent the cows from hurting each other, FJ wants to assign the cows to the stalls, such that the minimum distance between any two of them is as large as possible. What is the largest minimum distance?

// Input Format:
// First line contains N and C, separated by a single space, representing the total number of stalls and number of cows respectively. The next line contains N integers containing the indexes of stalls.

// Constraints:
// Output Format
// Print one integer: the largest minimum distance.

// Sample Input
// 5 3
// 1 2 8 4 9
// Sample Output
// 3

#include <bits/stdc++.h>
//#include <iostream>

using namespace std;

bool check(long int arr[],int n,int c,long int mid)
{
	c--;
	long int prevCow=arr[0];
	for(int i=0;i<n;i++)
	{
		if(arr[i]>=prevCow+mid)
		{
			c--;
			if(c==0)
			{
				return true;
			}
			prevCow=arr[i];
		}
	}
	return false;
}

int arrangeCows(long int arr[],int n,int c)
{
	sort(arr,arr+n);
	long int low=arr[0],high=arr[n-1],ans=0;
	while(low<=high)
	{
		long int mid=low+(high-low)/2;
		bool possible=check(arr,n,c,mid);
		if(possible)
		{
			ans=mid;
			low=mid+1;
		}
		else
		{
			high=mid-1;
		}
	}
	return ans;
}

int main()
{
	long int n,c,arr[100000];
	cin>>n>>c;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	cout<<arrangeCows(arr,n,c);
	return 0;
}