// COUNT SUBSEQUENCES
// Given a string, count the number of distinct subsequences of it ( including empty subsequence ). For the uninformed, A subsequence of a string is a new string which is formed from the original string by deleting some of the characters without disturbing the relative positions of the remaining characters. For example, "AGH" is a subsequence of "ABCDEFGH" while "AHG" is not.

// Input Format:
// First line of input contains an integer 't' denoting number of test cases. Each of next t lines contains a string s.

// Constraints:
// 1<=t<=100 1<=length of s<=100000 s will contain upper letters only.

// Output Format
// For each test case print ans%1000000007 where ans is the number of distinct subsequences.

// Sample Input
// 2
// AAA
// ABCDEFG
// Sample Output
// 4
// 128

// #include <iostream>
// #include <unordered_map>
// #define ll long long int
// using namespace std;
// ll mod=1e9+7;
// ll findNoOfSubsequences(string str)
// {
// 	ll dp[100002];
// 	unordered_map<char,ll> mp;
// 	ll l=str.length();
// 	ll *prevOcc=new ll[l];
// 	for(ll i=0;i<l;i++)
// 	{
// 		if(mp.count(str[i]))
// 		{
// 			prevOcc[i]=mp[str[i]];
// 		}
// 		else
// 		{
// 			prevOcc[i]=-1;
// 		}
// 		mp[str[i]]=i;
// 	}

// 	// for(ll i=0;i<l;i++)
// 	// {
// 	// 	cout<<prevOcc[i]<<" ";
// 	// }
// 	// cout<<endl;

// 	dp[0]=1;
// 	for(int i=1;i<=l;i++)
// 	{
// 		dp[i]=(2*dp[i-1])%mod;
// 		if(prevOcc[i-1]!=-1)
// 		{
// 			dp[i]=(dp[i]+mod-dp[prevOcc[i-1]])%mod;
// 		}
// 	}

// 	return dp[l];
// }

// int main()
// {
// 	ll t;
// 	cin>>t;
// 	while(t>0)
// 	{
// 		string str;
// 		cin>>str;
// 		cout<<findNoOfSubsequences(str)<<endl;
// 		t--;
// 	}
// 	return 0;
// }

//*********************************************************************************************************************************************

#include <iostream>
#include <unordered_map>
#define ll long long int
using namespace std;
ll mod=1000000007;
ll findNoOfSubsequences(string str)
{
	ll dp[100002];
	ll l=str.length();
	ll *prevOcc=new ll[26];
	fill(prevOcc,prevOcc+26,-1);
	dp[0]=1;
	for(ll i=1;i<=l;i++)
	{
		dp[i]=(2*dp[i-1])%mod;
		if(prevOcc[str[i-1]-65]!=-1)
		{
			if(dp[i]<=dp[prevOcc[str[i-1]-65]])
			{
				dp[i]=dp[i]+mod-dp[prevOcc[str[i-1]-65]];
			}
			else
			{
				dp[i]-=dp[prevOcc[str[i-1]-65]];
			}
		}

		prevOcc[str[i-1]-65]=i-1;
	}

	return dp[l];
}

int main()
{
	ll t;
	cin>>t;
	while(t>0)
	{
		string str;
		cin>>str;
		cout<<findNoOfSubsequences(str)<<endl;
		t--;
	}
	return 0;
}