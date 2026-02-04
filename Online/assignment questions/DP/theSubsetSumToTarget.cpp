// THE SUBSET SUM TO TARGET
// Given a set of "n" non-negative integers, and a value "sum", determine if there is a subset of the given set with sum equal to given sum.

// Input Format:
// 1st Line: n sum 2nd Line: a1 a2……an (Array Values)

// Constraints:
// 1<= n <= 5000 1<= sum <= 10^7 1<= Ai <=10^5

// Output Format
// Yes, if sum exist No, it sum does not exist

// Sample Input
// 5 10
// 1 2 3 4 5
// Sample Output
// Yes


//this question is specially demanding for bottom up approach due to its constraints
#include <iostream>
#include <unordered_map>
using namespace std;
// int memo[501][10001];
// int count;

// bool isPossible(int arr[],int n,int sum,int i=0)
// {
// 	count++;
// 	if(sum==0)
// 	{
// 		return true;
// 	}

// 	if(sum<0)
// 	{
// 		return false;
// 	}

// 	if(i==n)
// 	{
// 		return false;
// 	}

// 	return isPossible(arr,n,sum,i+1) || isPossible(arr,n,sum-arr[i],i+1);
// }

// bool isPossibleTD(int arr[],int n,int sum,int i=0)
// {
// 	count++;
// 	if(sum==0)
// 	{
// 		return true;
// 	}

// 	if(sum<0)
// 	{
// 		return false;
// 	}

// 	if(i==n)
// 	{
// 		return false;
// 	}

// 	if(memo[i][sum]!=-1)
// 	{
// 		return memo[i][sum];
// 	}

// 	memo[i][sum]=isPossibleTD(arr,n,sum,i+1) || isPossibleTD(arr,n,sum-arr[i],i+1);
// 	return memo[i][sum];
// }

bool isPossibleBU(int arr[],int n,int sum)
{
	bool **dp=new bool*[n+1];
	for(int i=0;i<=n;i++)
	{
		dp[i]=new bool[sum+1];
	}

	for(int i=0;i<=n;i++) dp[i][0]=true;
	for(int i=1;i<=sum;i++) dp[0][i]=false;

	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=sum;j++)
		{
			if(j<arr[i-1])
			{
				dp[i][j]=dp[i-1][j];
			}
			else
			{
				dp[i][j]=dp[i-1][j] || dp[i-1][j-arr[i-1]];
			}
		}
	}

	return dp[n][sum];
}

int main(int argc, char const *argv[])
{
	int n,sum;
	cin>>n>>sum;
	int *arr=new int[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}

	if(isPossibleBU(arr,n,sum))
	{
		cout<<"Yes"<<endl;
	}
	else
	{
		cout<<"No"<<endl;
	}

	// count=0;
	// if(isPossible(arr,n,sum))
	// {
	// 	cout<<"Yes"<<endl;
	// }
	// else
	// {
	// 	cout<<"No"<<endl;
	// }
	// cout<<count<<endl;

	// for(int i=0;i<=n;i++)
	// {
	// 	for(int j=0;j<=sum;j++)
	// 	{
	// 		memo[i][j]=-1;
	// 	}
	// }
	// count=0;
	// if(isPossibleTD(arr,n,sum))
	// {
	// 	cout<<"Yes"<<endl;
	// }
	// else
	// {
	// 	cout<<"No"<<endl;
	// }
	// cout<<count<<endl;

	// for(int i=0;i<=n;i++)
	// {
	// 	for(int j=0;j<=sum;j++)
	// 	{
	// 		cout<<memo[i][j]<<" ";
	// 	}
	// 	cout<<endl;
	// }
	return 0;
}