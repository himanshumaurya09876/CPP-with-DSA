#include <iostream>
#include <cstring>
using namespace std;

int memo[100][100];

int maxProfit(int arr[],int s,int e,int year)
{
	if(s>e)
	{
		return 0;
	}

	int q1=arr[s]*year+maxProfit(arr,s+1,e,year+1);
	int q2=arr[e]*year+maxProfit(arr,s,e-1,year+1);

	int ans=max(q1,q2);

	return ans;
}

int maxProfitTopDown(int arr[],int s,int e,int year)
{
	if(s>e)
	{
		return 0;
	}
	if(memo[s][e]!=-1)
	{
		return memo[s][e];
	}

	int q1=arr[s]*year+maxProfitTopDown(arr,s+1,e,year+1);
	int q2=arr[e]*year+maxProfitTopDown(arr,s,e-1,year+1);

	memo[s][e]=max(q1,q2);
	return memo[s][e];
}

int maxProfitBottomUp(int arr[],int n)
{
	 int **dp=new int*[n];
	 for(int i=0;i<n;i++)
	 {
	 	dp[i]=new int[n];
	 }

	 int year=n;
	 for(int i=0;i<n;i++)
	 {
	 	dp[i][i]=arr[i]*year;
	 }
	 year--;

	 for(int i=n-2;i>=0;i--)
	 {
	 	int temp=year;
	 	for(int j=i+1;j<n;j++)
	 	{
	 		dp[i][j]=max(temp*arr[j]+dp[i][j-1],temp*arr[i]+dp[i+1][j]);
	 		temp--;
	 	}
	 }

	 // for(int i=0;i<n;i++)
	 // {
	 // 	for(int j=0;j<n;j++)
	 // 	{
	 // 		cout<<dp[i][j]<<" ";
	 // 	}
	 // 	cout<<endl;
	 // }

	 return dp[0][n-1];
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
	cout<<maxProfitBottomUp(arr,n)<<endl;
	memset(memo,-1,sizeof(memo));
	cout<<maxProfitTopDown(arr,0,n-1,1)<<endl;
	cout<<maxProfit(arr,0,n-1,1)<<endl;
	return 0;
}