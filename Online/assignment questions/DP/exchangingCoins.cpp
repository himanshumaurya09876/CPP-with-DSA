// EXCHANGING COINS
// Tughlaq introduces a strange monetary system. He introduces copper coins and each coin has a number written on it. A coin n can be exchanged in a bank into three coins: n/2, n/3 and n/4. A coin can also be sold for gold. One can get as much grams of gold as the number written on the coin. You have one copper coin. What is the maximum weight of gold one can get from it?

// Input Format:
// The input file contains a single integer n, the number on the coin.

// Constraints:
// 0 <= n <= 1 000 000 000

// Output Format
// Print the maximum weight of gold you can get.

// Sample Input
// 12
// Sample Output
// 13

#include <iostream>
#include <unordered_map>
#define ll long long
using namespace std;
unordered_map<ll,ll> mp;
int count;

ll maxGold(ll n)
{
	count++;
	if(n==0)
	{
		return 0;
	}

	return max(n,maxGold(n/2)+maxGold(n/3)+maxGold(n/4));
}


ll maxGoldTD(ll n)
{
	count++;
	if(n==0)
	{
		return 0;
	}

	if(mp.count(n))
	{
		return mp[n];
	}
	mp[n]=max(n,maxGoldTD(n/2)+maxGoldTD(n/3)+maxGoldTD(n/4));
	return mp[n];
}

int main()
{
	ll n;
	cin>>n;
	count=0;
	cout<<maxGold(n)<<" "<<count<<endl;
	count=0;
	cout<<maxGoldTD(n)<<" "<<count<<endl;
	return 0;
}