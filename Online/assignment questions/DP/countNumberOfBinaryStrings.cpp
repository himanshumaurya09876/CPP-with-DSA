// COUNT NUMBER OF BINARY STRINGS
// You are provided an integers N. You need to count all possible distinct binary strings of length N such that there are no consecutive 1’s.

// Input Format:
// First line contains integer t which is number of test case. For each test case, it contains an integer n which is the the length of Binary String.

// Constraints:
// 1<=t<=100 1<=n<=90

// Output Format
// Print the number of all possible binary strings.

// Sample Input
// 2
// 2
// 3
// Sample Output
// 3
// 5


//Here if you will notice the solutions -> (2,3,5,8,13,21....) then u will find that for n it is nth fibonacci number

#include <iostream>
#include <cstring>
#define ll long long int
using namespace std;

// ll memo[2][100];

// ll totalStrings(ll n,string str="")
// {
// 	ll l=str.length();
// 	if(l==n)
// 	{
// 		// cout<<str<<endl;
// 		return 1;
// 	}

// 	ll ans=totalStrings(n,"0"+str);
// 	if(l==0)
// 	{
// 		ans+=totalStrings(n,"1"+str);
// 	}
// 	else if(str[0]!='1')
// 	{
// 		ans+=totalStrings(n,"1"+str);
// 	}
// 	return ans;
// }

// ll totalStringsTD(ll n,int ch=0)
// {
// 	if(n==1 && ch==0)
// 	{
// 		return 2;
// 	}
// 	else if(n==1 && ch==1)
// 	{
// 		return 1;
// 	}

// 	if(memo[ch][n]!=-1)
// 	{
// 		return memo[ch][n];
// 	}

// 	ll ans=totalStringsTD(n-1,0);
// 	if(ch==0)
// 	{
// 		ans+=totalStringsTD(n-1,1);
// 	}
// 	memo[ch][n]=ans;
// 	return ans;
// }

ll totalStringsBU(ll n)
{
	ll dp[2][100];
	dp[0][0]=0;
	dp[1][0]=0;
	dp[0][1]=1;
	dp[1][1]=1;
	for(int i=2;i<=n;i++)
	{
		dp[0][i]=dp[0][i-1]+dp[1][i-1];
		dp[1][i]=dp[0][i-1];
	}

	return dp[0][n]+dp[1][n];
}

int main()
{
	ll t;
	cin>>t;
	while(t>0)
	{
		ll n;
		cin>>n;
		// memset(memo,-1,sizeof(memo));
		// cout<<totalStrings(n)<<endl;
		// cout<<totalStringsTD(n)<<endl;
		cout<<totalStringsBU(n)<<endl;
		t--;
	}
	return 0;
}