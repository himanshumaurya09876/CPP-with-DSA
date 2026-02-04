// LCS WITH 3 STRINGS
// Given 3 strings ,the task is to find the longest common sub-sequence in all three given sequences.

// Input Format:
// First line contains first string . Second line contains second string. Third line contains the third string.

// Constraints:
// The length of all strings is |s|< 200

// Output Format
// Output an integer denoting the length of longest common subsequence of above three strings.

// Sample Input
// GHQWNV
// SJNSDGH
// CPGMAH
// Sample Output
// 2

#include <iostream>
#include <string>
using namespace std;
int count;
int memo[200][200][200];

int lcs(string s1,string s2,string s3,int i=0,int j=0,int k=0)//recursive
{
	count++;
	if(s1[i]=='\0' || s2[j]=='\0' || s3[k]=='\0')
	{
		return 0;
	}

	int ans=0;
	if(s1[i]==s2[j] && s1[i]==s3[k])
	{
		ans=1+lcs(s1,s2,s3,i+1,j+1,k+1);
	}
	else
	{
		ans=max(lcs(s1,s2,s3,i+1,j,k),max(lcs(s1,s2,s3,i,j+1,k),lcs(s1,s2,s3,i,j,k+1)));
	}

	return ans;
}

int lcsTD(string s1,string s2,string s3,int i=0,int j=0,int k=0)//top down dp
{
	count++;
	if(s1[i]=='\0' || s2[j]=='\0' || s3[k]=='\0')
	{
		return 0;
	}

	if(memo[i][j][k]!=-1)
	{
		return memo[i][j][k];
	}

	int ans=0;
	if(s1[i]==s2[j] && s1[i]==s3[k])
	{
		ans=1+lcsTD(s1,s2,s3,i+1,j+1,k+1);
	}
	else
	{
		ans=max(lcsTD(s1,s2,s3,i+1,j,k),max(lcsTD(s1,s2,s3,i,j+1,k),lcsTD(s1,s2,s3,i,j,k+1)));
	}

	memo[i][j][k]=ans;
	return ans;
}

int lcsBU(string s1,string s2,string s3)//botoom up dp
{
	int dp[200][200][200];

	int l1=s1.length();
	int l2=s2.length();
	int l3=s3.length();

	for(int i=0;i<=l1;i++)
	{
		for(int j=0;j<=l2;j++)
		{
			dp[i][j][0]=0;
		}
	}
	for(int i=0;i<=l1;i++)
	{
		for(int k=0;k<=l3;k++)
		{
			dp[i][0][k]=0;
		}
	}
	for(int j=0;j<=l2;j++)
	{
		for(int k=0;k<=l3;k++)
		{
			dp[0][j][k]=0;
		}
	}

	for(int i=1;i<=l1;i++)
	{
		for(int j=1;j<=l2;j++)
		{
			for(int k=1;k<=l3;k++)
			{
				if(s1[i-1]==s2[j-1] && s1[i-1]==s3[k-1])
				{
					dp[i][j][k]=dp[i-1][j-1][k-1]+1;
				}
				else
				{
					dp[i][j][k]=max(dp[i-1][j][k],max(dp[i][j-1][k],dp[i][j][k-1]));
				}
			}
		}
	}
	return dp[l1][l2][l3];
}

int main(int argc, char const *argv[])
{
	string str1,str2,str3;
	cin>>str1>>str2>>str3;
	int l1=str1.length();
	int l2=str2.length();
	int l3=str3.length();

	cout<<lcsBU(str1,str2,str3)<<endl;

	for(int i=0;i<l1;i++)
	{
		for(int j=0;j<l2;j++)
		{
			for(int k=0;k<l3;k++)
			{
				memo[i][j][k]=-1;
			}
		}
	}
	count=0;
	cout<<lcsTD(str1,str2,str3)<<"  "<<count<<endl;


	count=0;
	cout<<lcs(str1,str2,str3)<<"  "<<count<<endl;
	return 0;
}