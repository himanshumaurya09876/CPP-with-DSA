// TILLING PROBLEM - II
// Given a floor of size n x m. Find the number of ways to tile the floor with tiles of size 1 x m . A tile can either be placed horizontally or vertically.

// Input Format:
// First line of input contains an integer T denoting the number of test cases. Then T test cases follow.
// The first line of each test case contains two integers N and M.

// Constraints:
// 1 <= T<= 1000 1 <= N,M <= 100000

// Output Format
// Print answer for every test case in a new line modulo 10^9+7.

// Sample Input
// 2
// 2 3
// 4 4
// Sample Output
// 1
// 2

#include <iostream>
#define ll long long int
using namespace std;
ll mod=1000000007;
ll count;
ll memo[100001];

ll arrangeTiles(ll n,ll m)
{
	count++;
	if(n==m)
	{
		return 2;
	}
	else if(n<m)
	{
		return 1;
	}

	ll ans=(arrangeTiles(n-1,m)+arrangeTiles(n-m,m))%mod;
	return ans;
}

ll arrangeTilesTD(ll n,ll m)
{
	count++;
	if(n==m)
	{
		return 2;
	}
	else if(n<m)
	{
		return 1;
	}

	if(memo[n]!=-1)
	{
		return memo[n];
	}

	ll ans=(arrangeTilesTD(n-1,m)+arrangeTilesTD(n-m,m))%mod;
	memo[n]=ans;
	return ans;
}

ll arrangeTilesBU(ll n,ll m)
{
	ll dp[100001];
	dp[0]=0;
	for(int i=1;i<m;i++)
	{
		dp[i]=1;
	}
	dp[m]=2;
	for(int i=m+1;i<=n;i++)
	{
		dp[i]=(dp[i-1]+dp[i-m])%mod;
	}
	return dp[n];
}

int main()
{
	ll t;
    cin>>t;
    while(t>0)
    {
        ll n,m;
	    cin>>n>>m;

	    cout<<arrangeTilesBU(n,m)<<endl;

	    fill(memo,memo+n+1,-1);
	    count=0;
	    cout<<arrangeTilesTD(n,m)<<" "<<count<<endl;

	    count=0;
	    cout<<arrangeTiles(n,m)<<" "<<count<<endl;
        t--;
    }
    return 0;
}