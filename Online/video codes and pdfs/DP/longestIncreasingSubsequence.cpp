#include <iostream>
using namespace std;

int lis(int arr[],int n)
{
	int ans=0;
	int *dp=new int[n];
	fill(dp,dp+n,1);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<i;j++)
		{
			if(arr[j]<=arr[i])
			{
				dp[i]=max(dp[i],dp[j]+1);
			}
		}
		ans=max(ans,dp[i]);
	}

	// for(int i=0;i<n;i++)
	// {

	// 	cout<<dp[i]<<" ";
	// }
	// cout<<endl;

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
	cout<<lis(arr,n)<<endl;
	return 0;
}