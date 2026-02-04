#include <iostream>
#include <string>
using namespace std;
int count;
int memo[100][100];

int lcs(string s1,string s2,int i=0,int j=0)//recursive
{
	count++;
	if(s1[i]=='\0' || s2[j]=='\0')
	{
		return 0;
	}

	int ans=0;
	if(s1[i]==s2[j])
	{
		ans=1+lcs(s1,s2,i+1,j+1);
	}
	else
	{
		ans=max(lcs(s1,s2,i+1,j),lcs(s1,s2,i,j+1));
	}

	return ans;
}

int lcsTD(string s1,string s2,int i=0,int j=0)//top down dp
{
	count++;
	if(s1[i]=='\0' || s2[j]=='\0')
	{
		return 0;
	}

	if(memo[i][j]!=-1)
	{
		return memo[i][j];
	}

	int ans=0;
	if(s1[i]==s2[j])
	{
		ans=1+lcsTD(s1,s2,i+1,j+1);
	}
	else
	{
		ans=max(lcsTD(s1,s2,i+1,j),lcsTD(s1,s2,i,j+1));
	}

	memo[i][j]=ans;
	return ans;
}

int lcsBU(string s1,string s2)//botoom up dp
{
	int dp[100][100];

	int l1=s1.length();
	int l2=s2.length();

	for(int i=0;i<=l1;i++) dp[0][i]=0;
	for(int i=0;i<=l2;i++) dp[i][0]=0;

	for(int i=1;i<=l1;i++)
	{
		for(int j=1;j<=l2;j++)
		{
			if(s1[i-1]==s2[j-1])
			{
				dp[i][j]=dp[i-1][j-1]+1;
			}
			else
			{
				dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
			}
		}
	}

	return dp[l1][l2];
}

int main(int argc, char const *argv[])
{
	string str1,str2;
	cin>>str1>>str2;
	int l1=str1.length();
	int l2=str2.length();


	cout<<lcsBU(str1,str2)<<endl;


	for(int i=0;i<l1;i++)
	{
		for(int j=0;j<l2;j++)
		{
			memo[i][j]=-1;
		}
	}
	count=0;
	cout<<lcsTD(str1,str2)<<"  "<<count<<endl;


	count=0;
	cout<<lcs(str1,str2)<<"  "<<count<<endl;
	return 0;
}