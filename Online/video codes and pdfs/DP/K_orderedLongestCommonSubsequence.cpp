#include <iostream>
#include <cstring>
using namespace std;
int count;
int memo[100][100][10];

int lcs(string s1,string s2,int k,int i=0,int j=0)//recursive
{
	count++;
	if(s1[i]=='\0' || s2[j]=='\0')
	{
		return 0;
	}

	int ans=0;
	if(s1[i]==s2[j])
	{
		ans=1+lcs(s1,s2,k,i+1,j+1);
	}
	else
	{
		if(k>0)
		{
			ans=1+lcs(s1,s2,k-1,i+1,j+1);
		}
		ans=max(ans,max(lcs(s1,s2,k,i+1,j),lcs(s1,s2,k,i,j+1)));
	}

	return ans;
}

int lcsTD(string s1,string s2,int k,int i=0,int j=0)//top down dp
{
	count++;
	if(s1[i]=='\0' || s2[j]=='\0')
	{
		return 0;
	}

	if(memo[i][j][k]!=-1)
	{
		return memo[i][j][k];
	}

	int ans=0;
	if(s1[i]==s2[j])
	{
		ans=1+lcs(s1,s2,k,i+1,j+1);
	}
	else
	{
		if(k>0)
		{
			ans=1+lcs(s1,s2,k-1,i+1,j+1);
		}
		ans=max(ans,max(lcs(s1,s2,k,i+1,j),lcs(s1,s2,k,i,j+1)));
	}
	memo[i][j][k]=ans;
	return ans;
}

// note:- it is very difficult to think about bottom up approach of dp

int main(int argc, char const *argv[])
{
	string str1,str2;
	int k;
	cin>>str1>>str2>>k;
	int l1=str1.length();
	int l2=str2.length();

	for(int i=0;i<=l1;i++)
	{
		for(int j=0;j<=l2;j++)
		{
			for(int p=0;p<=k;p++)
			{
				memo[i][j][k]=-1;
			}
		}
	}
	count=0;
	cout<<lcsTD(str1,str2,k)<<"  "<<count<<endl;


	count=0;
	cout<<lcs(str1,str2,k)<<"  "<<count<<endl;
	return 0;
}