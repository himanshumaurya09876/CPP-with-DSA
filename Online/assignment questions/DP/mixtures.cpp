// MIXTURES
// Harry Potter has n mixtures in front of him, arranged in a row. Each mixture has one of 100 different colors (colors have numbers from 0 to 99).

// He wants to mix all these mixtures together. At each step, he is going to take two mixtures that stand next to each other and mix them together, and put the resulting mixture in their place.

// When mixing two mixtures of colors a and b, the resulting mixture will have the color (a+b) mod 100.

// Also, there will be some smoke in the process. The amount of smoke generated when mixing two mixtures of colors a and b is a*b.

// Find out what is the minimum amount of smoke that Harry can get when mixing all the mixtures together.
// You can find the original problem here.

// Input Format:
// The first line of each input file will contain n, the number of mixtures. The second line will contain n integers between 0 and 99 - the initial colors of the mixtures.

// Constraints:
// 1 <= n <= 100

// Output Format
// Output the minimum amount of smoke.

// Sample Input
// 3
// 40 60 20
// Sample Output
// 2400

#include <iostream>
#include <cstdio>
#include <cstring>
#include <climits>
using namespace std;

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
	return dp[0][n-1];
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

		cout<<minmSmokeBU(arr,csum,n)<<endl;
	}
	return 0;
}