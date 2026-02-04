#include <iostream>
using namespace std;

int minCost(int arr[][100],int r,int c)
{
	int dp[100][100];

	dp[0][0]=arr[0][0];

	for(int i=1;i<c;i++)
	{
		dp[0][i]=arr[0][i]+dp[0][i-1];
	}

	for(int i=1;i<r;i++)
	{
		dp[i][0]=arr[i][0]+dp[i-1][0];
	}

	for(int i=1;i<r;i++)
	{
		for(int j=1;j<c;j++)
		{
			dp[i][j]=min(dp[i-1][j],dp[i][j-1])+arr[i][j];
		}
	}

	// for(int i=0;i<r;i++)
	// {
	// 	for(int j=0;j<c;j++)
	// 	{
	// 		cout<<dp[i][j]<<" ";
	// 	}
	// 	cout<<endl;
	// }

	return dp[r-1][c-1];
}

int main(int argc, char const *argv[])
{
	int arr[100][100]={{1,2,3},
				 	   {4,8,2},
				 	   {1,5,3}};

	int r=3;
	int c=3;

	cout<<minCost(arr,r,c)<<endl;
	return 0;
}