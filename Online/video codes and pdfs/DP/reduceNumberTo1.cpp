#include <iostream>
using namespace std;

int memo[10000];

int minSteps(int n)//normal recursive approach
{
	if(n==1)
	{
		return 0;
	}

	int q1=INT_MAX,q2=INT_MAX,q3=INT_MAX;
	if(n%3==0) q3=1+minSteps(n/3);
	if(n%2==0) q2=1+minSteps(n/2);
	q1=1+minSteps(n-1);

	int ans=min(q1,min(q2,q3));
	return ans;
}

int minStepsTopDownDP(int n)//top down dp approach
{
	if(n==1)
	{
		return 0;
	}
	if(memo[n]!=-1)
	{
		return memo[n];
	}

	int q1=INT_MAX,q2=INT_MAX,q3=INT_MAX;
	if(n%3==0) q3=1+minStepsTopDownDP(n/3);
	if(n%2==0) q2=1+minStepsTopDownDP(n/2);
	q1=1+minStepsTopDownDP(n-1);

	int ans=min(q1,min(q2,q3));
	memo[n]=ans;
	return ans;
}

int minStepsBottomUpDP(int n)//bottom up dp approach
{
	int dp[10000];
	dp[0]=-1;
	dp[1]=0;
	dp[2]=1;
	dp[3]=1;
	for(int i=4;i<=n;i++)
	{
		int q1=INT_MAX,q2=INT_MAX,q3=INT_MAX;
		if(i%3==0) q3=1+dp[i/3];
		if(i%2==0) q2=1+dp[i/2];
		q1=1+dp[i-1];
		dp[i]=min(q1,min(q2,q3));
	}

	return dp[n];
}


int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	cout<<minStepsBottomUpDP(n)<<endl;
	fill(memo,memo+n+1,-1);
	cout<<minStepsTopDownDP(n)<<endl;
	cout<<minSteps(n)<<endl;
	return 0;
}