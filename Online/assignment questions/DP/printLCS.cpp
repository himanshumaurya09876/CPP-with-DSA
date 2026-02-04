// PRINT LCS
// A subsequence is a sequence that can be derived from another sequence by deleting some elements without changing the order of the remaining elements. For example, the sequence {A,B,D} is a subsequence of {A,B,C,D,E,F}, obtained after removal of elements C, E and F.

// Given two strings A and B of size n and m respectively, you have to print the Longest Common Subsequence(LCS) of strings A and B, where LCS is the longest sequence present in both A and B.

// Note: It is gauranteed that there is only one unique longest common subsequence

// Input Format:
// Two strings A and B.

// Constraints:
// 1 <= n,m <= 10^3

// Output Format
// Output the LCS of A and B.

// Sample Input
// abc
// acd
// Sample Output
// ac

#include <iostream>
#include <string>
using namespace std;

string lcs(string a,string b)
{
	int la=a.length();
	int lb=b.length();

	// cout<<a<<" "<<la<<endl;
	// cout<<b<<" "<<lb<<endl;

	// int **dp=new int*[la+1];
	// for(int i=0;i<=la;i++)
	// {
	// 	dp[i]=new int[lb+1];
	// }

	int dp[1001][1001];
	
	for(int i=0;i<=la;i++)
	{
		dp[i][0]=0;
	}
	for(int i=0;i<=lb;i++)
	{
		dp[0][i]=0;
	}

	for(int i=1;i<=la;i++)
	{
		for(int j=1;j<=lb;j++)
		{
			if(a[i-1]==b[j-1])
			{
				dp[i][j]=dp[i-1][j-1]+1;
			}
			else
			{
				dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
			}
		}
	}

	for(int i=0;i<=la;i++)
	{
		for(int j=0;j<=lb;j++)
		{
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}

	int i=la,j=lb;
	string ans="";
	// while(i>0 && j>0)
	// {
	// 	// cout<<i<<" "<<j<<endl;
	// 	if(dp[i-1][j]==dp[i][j-1] && dp[i][j]-dp[i-1][j-1]==1)
	// 	{
	// 		// cout<<a[i-1]<<endl;
	// 		ans=a[i-1]+ans;
	// 		i--;
	// 		j--;
	// 	}
	// 	else
	// 	{
	// 		if(dp[i-1][j]>=dp[i][j-1])
	// 		{
	// 			i--;
	// 		}
	// 		else
	// 		{
	// 			j--;
	// 		}
	// 	}
	// }


	while(i>0 && j>0)
	{
		if(a[i-1]==b[j-1])
		{
			ans=a[i-1]+ans;
			i--;
			j--;
		}
		else if(dp[i-1][j]>dp[i][j-1])
		{
			i--;
		}
		else
		{
			j--;
		}
	}

	return ans;
}

int main(int argc, char const *argv[])
{
	string a,b;
	cin>>a>>b;
	cout<<lcs(a,b)<<endl;
	return 0;
}