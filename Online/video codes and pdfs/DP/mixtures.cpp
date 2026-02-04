// this problem is similar to MCM (Matrix Chain Multiplication)


// Harry Potter has n mixtures in front of him, arranged in a row. Each mixture has one of 100 different colors (colors have numbers from 0 to 99).

// He wants to mix all these mixtures together. At each step, he is going to take two mixtures that stand next to each other and mix them together, and put the resulting mixture in their place.

// When mixing two mixtures of colors a and b, the resulting mixture will have the color (a+b) mod 100.

// Also, there will be some smoke in the process. The amount of smoke generated when mixing two mixtures of colors a and b is a*b.

// Find out what is the minimum amount of smoke that Harry can get when mixing all the mixtures together.

// Input
// There will be a number of test cases in the input.

// The first line of each test case will contain n, the number of mixtures, 1 <= n <= 100.

// The second line will contain n integers between 0 and 99 - the initial colors of the mixtures.

// Output
// For each test case, output the minimum amount of smoke.

// Example
// Input:
// 2
// 18 19
// 3
// 40 60 20

// Output:
// 342
// 2400
// In the second test case, there are two possibilities:

// first mix 40 and 60 (smoke: 2400), getting 0, then mix 0 and 20 (smoke: 0); total amount of smoke is 2400
// first mix 60 and 20 (smoke: 1200), getting 80, then mix 40 and 80 (smoke: 3200); total amount of smoke is 4400
// The first scenario is a much better way to proceed.

#include <iostream>
#include <cstdio>
#include <cstring>
#include <climits>
using namespace std;
int memo[100][100];

int minmSmokeBU(int arr[],int csum[],int n)//bottom up approach
{
	int dp[100][100]={0};
	for(int i=n-2;i>=0;i--)
	{
		for(int j=i+1;j<n;j++)
		{
			int minm=INT_MAX;
			for(int k=i;k<j;k++)
			{
				int cs=csum[k];
				if(i!=0)
				{
					cs=cs-csum[i-1];
				}
				minm=min(minm,dp[i][k]+dp[k+1][j]+(cs%100)*((csum[j]-csum[k])%100));
			}
			dp[i][j]=minm;
		}
	}

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}

	return dp[0][n-1];
}

int minmSmokeTD(int arr[],int csum[],int s,int e)
{
	if(s>=e)
	{
		return 0;
	}

	if(memo[s][e]!=-1) 
	{
		return memo[s][e];
	}

	memo[s][e]=INT_MAX;
	for(int i=s;i<=e;i++)
	{
		int cs=csum[i];
		if(s!=0)
		{
			cs=cs-csum[s-1];
		}
		memo[s][e]=min(memo[s][e],minmSmokeTD(arr,csum,s,i)+minmSmokeTD(arr,csum,i+1,e)+(cs%100)*((csum[e]-csum[i])%100));
	}
	return memo[s][e];
}

int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		int *arr=new int[n];
		for(int i=0;i<n;i++)
		{
			cin>>arr[i];
		}
		int *csum=new int[n];
		csum[0]=arr[0];
		for(int i=1;i<n;i++)
		{
			csum[i]=csum[i-1]+arr[i];
		}
		memset(memo,-1,sizeof(memo));
		cout<<minmSmokeTD(arr,csum,0,n-1)<<endl;
		cout<<minmSmokeBU(arr,csum,n)<<endl;
	}
	return 0;
}