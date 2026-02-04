// MINIMUM JUMPS REQUIRED
// You are provided an array of integers where each element represents the max number of steps you can take to move ahead. You need to check that how many minimum steps required to reach at the end of the array.

// Hint - If N==0 you can never move forward, your return INT_MAX (Infinity).

// Input Format:
// First line contains integer t which is number of test case. For each test case, it contains an integers n which the size of array A[]. Next line contains n space separated integers.

// Constraints:
// 1<=t<=50 1<=n<=1000 0<=A[i]<=100

// Output Format
// Print the minimum number of jumps.

// Sample Input
// 1
// 11
// 1 3 5 8 9 2 6 7 6 8 9
// Sample Output
// 3

#include <iostream>
using namespace std;
int count;
int memo[1000];
int inf=1000000;

int minJumps(int arr[],int n,int idx=0)
{
	count++;
	if(idx==n-1)
	{
		return 0;
	}

	if(idx>=n)
	{
		return inf;
	}

	int ans=inf;
	for(int i=1;i<=arr[idx];i++)
	{
		ans=min(ans,minJumps(arr,n,idx+i));
	}

	return ans+1;
}

int minJumpsTD(int arr[],int n,int idx=0)
{
	count++;
	if(idx==n-1)
	{
		return 0;
	}

	if(idx>=n)
	{
		return inf;
	}

	if(memo[idx]!=-1)
	{
		return memo[idx];
	}

	int ans=inf;
	for(int i=1;i<=arr[idx];i++)
	{
		ans=min(ans,minJumpsTD(arr,n,idx+i));
	}
	memo[idx]=ans+1;
	return ans+1;
}

int minJumpsBU(int arr[],int n)
{
	int *dp=new int[n];
	dp[n-1]=0;
	for(int idx=n-2;idx>=0;idx--)
	{
		int ans=inf;
		for(int i=1;i<=arr[idx];i++)
		{
			if(idx+i<n)
			{
				ans=min(ans,dp[idx+i]);
			}
		}
		dp[idx]=ans+1;
	}
	return dp[0];
}

int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t>0)
	{
		int n;
		cin>>n;
		int *arr=new int[n];
		for(int i=0;i<n;i++)
		{
			cin>>arr[i];
		}

		cout<<minJumpsBU(arr,n)<<endl;

		fill(memo,memo+1000,-1);
		count=0;		
		cout<<minJumpsTD(arr,n)<<" "<<count<<endl;

		count=0;		
		cout<<minJumps(arr,n)<<" "<<count<<endl;
		t--;
	}
	return 0;
}