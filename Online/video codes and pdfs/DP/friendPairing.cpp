#include <iostream>
using namespace std;
int memo[100];

int totalWaysTD(int n)//top down approach
{
	if(n==1)
	{
		return 1;
	}
	if(n==2)
	{
		return 2;
	}

	if(memo[n]!=-1)
	{
		return memo[n];
	}

	int ans=totalWaysTD(n-1)+(n-1)*totalWaysTD(n-2);
	memo[n]=ans;
	return ans;
}

int totalWaysBU(int n)//bottom up approach
{
	int dp[100];
	dp[0]=0;
	dp[1]=1;
	dp[2]=2;
	for(int i=3;i<=n;i++)
	{
		dp[i]=dp[i-1]+(i-1)*dp[i-2];
	}
	
	return dp[n];
}

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	fill(memo,memo+n+1,-1);
	cout<<totalWaysTD(n)<<endl;
	cout<<totalWaysBU(n)<<endl;
	return 0;
}