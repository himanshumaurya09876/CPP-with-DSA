// BRACKETS ALL OVER
// You are given a string containing only opening and closing brackets "(" and ")" of size m. You have to append 2 strings a and b in the order a+s+b and make them valid string of size n with the following properties,

// At any index, number of opening brackets should be greater than closing brackets
// No. of opening and closing brackets should be equal. You have to tell number of combinations of string a and b if its possible, otherwise print "0" Print the asnwer with modulo 10^9 + 7.
// Input Format:
// 1st Line: n m 2nd Line: string s

// Constraints:
// 1<= m <= n <= 10^5 n-m <= 1200

// Output Format
// The number of combinations of a and b. Otherwise -1

// Sample Input
// 4 2
// ((
// Sample Output
// 1

//*************************************************************************************************************************************************
// #include <iostream>
// #include <stack>
// using namespace std;

// bool isBalanced(string str)
// {
// 	stack<char> ch;
// 	ll i=0;
// 	while(str[i]!='\0')
// 	{
// 		if(str[i]=='(')
// 		{
// 			ch.push(str[i]);
// 		}
// 		else
// 		{
// 			if(ch.empty() || ch.top()!='(')
// 			{
// 				return false;
// 			}
// 			else
// 			{
// 				ch.pop();
// 			}
// 		}
// 		i++;
// 	}
// 	if(ch.empty())
// 	{
// 		return true;
// 	}
// 	return false;
// }

// ll noOfComb(string str,ll n,ll m,ll nOpen,ll nClose)
// {
// 	if(n==m)
// 	{
// 		// cout<<str<<endl;
// 		if(nOpen==nClose && isBalanced(str))
// 		{
// 			return 1;
// 		}
// 		else
// 		{
// 			return 0;
// 		}
// 	}

// 	ll ans=0;

// 	// wrong approach
// 	// if(str[0]=='(')
// 	// {
// 	// 	ans+=noOfComb(')'+str,n,m+1,nOpen,nClose+1);
// 	// }
// 	// else
// 	// {
// 	// 	ans+=noOfComb('('+str,n,m+1,nOpen+1,nClose);
// 	// }


// 	// if(str[m-1]=='(')
// 	// {
// 	// 	ans+=noOfComb(str+')',n,m+1,nOpen,nClose+1);
// 	// }
// 	// else
// 	// {
// 	// 	ans+=noOfComb(str+'(',n,m+1,nOpen+1,nClose);
// 	// }


// 	if(nOpen>nClose)
// 	{
// 		ans+=noOfComb(str+')',n,m+1,nOpen,nClose+1);
// 	}
// 	else if(nOpen<nClose)
// 	{
// 		ans+=noOfComb('('+str,n,m+1,nOpen+1,nClose);
// 	}
// 	else
// 	{
// 		ans+=noOfComb(str+'(',n,m+1,nOpen+1,nClose);
// 		ans+=noOfComb(')'+str,n,m+1,nOpen,nClose+1);
// 	}

// 	return ans;
// }

// ll main(ll argc, char const *argv[])
// {
// 	ll n,m;
// 	cin>>n>>m;
// 	string str;
// 	cin>>str;
// 	ll nOpen=0,nClose=0;
// 	for(ll i=0;i<m;i++)
// 	{
// 		if(str[i]=='(')
// 		{
// 			nOpen++;
// 		}
// 		else
// 		{
// 			nClose++;
// 		}
// 	}

// 	cout<<noOfComb(str,n,m,nOpen,nClose)<<endl;

// 	return 0;
// }
//*************************************************************************************************************************************************


// #include <iostream>
// #include <stack>
// #define ll long long int
// using namespace std;
// ll mod=1000000007;
// ll noOfComb(string str,ll n,ll m,ll nOpen,ll nClose,bool forward)
// {
// 	if(forward)
// 	{
// 		if(nOpen>n/2 || nClose>nOpen)
// 		{
// 			return 0;
// 		}
// 	}
// 	else
// 	{
// 		if(nClose>n/2 || nOpen>nClose)
// 		{
// 			return 0;
// 		}
// 	}

// 	if(n==m)
// 	{
// 		cout<<str<<endl;
// 		if(nOpen==nClose)
// 		{
// 			return 1;
// 		}
// 		else
// 		{
// 			return 0;
// 		}
// 	}

// 	ll ans=0;

// 	// if(nOpen>nClose)
// 	// {
// 	// 	ans+=noOfComb(str+')',n,m+1,nOpen,nClose+1);
// 	// 	ans=ans%mod;
// 	// }
// 	// else if(nOpen<nClose)
// 	// {
// 	// 	ans+=noOfComb('('+str,n,m+1,nOpen+1,nClose);
// 	// 	ans=ans%mod;
// 	// }
// 	// else
// 	// {
// 	// 	ans+=noOfComb(str+'(',n,m+1,nOpen+1,nClose);
// 	// 	ans=ans%mod;
// 	// 	ans+=noOfComb(')'+str,n,m+1,nOpen,nClose+1);
// 	// 	ans=ans%mod;
// 	// }
 
// 	if(forward)
// 	{
// 		ans+=noOfComb(str+'(',n,m+1,nOpen+1,nClose,true);
// 		ans+=noOfComb(str+')',n,m+1,nOpen,nClose+1,true);
// 	}
// 	else
// 	{
// 		ans+=noOfComb('('+str,n,m+1,nOpen+1,nClose,false);
// 		ans+=noOfComb(')'+str,n,m+1,nOpen,nClose+1,false);
// 	}

// 	return ans;
// }

// string balance(string str)
// {
// 	string temp=str;
// 	stack<char> ch;
// 	ll i=0;
// 	while(str[i]!='\0')
// 	{
// 		if(str[i]=='(')
// 		{
// 			ch.push(str[i]);
// 		}
// 		else
// 		{
// 			if(ch.empty())
// 			{
// 				temp='('+temp;
// 			}
// 			else
// 			{
// 				ch.pop();
// 			}
// 		}
// 		i++;
// 	}
// 	while(!ch.empty())
// 	{
// 		temp+=')';
// 		ch.pop();
// 	}
// 	// cout<<temp<<endl;
// 	return temp;
// }

// int main()
// {
// 	ll n,m;
// 	cin>>n>>m;
// 	string str;
// 	cin>>str;

// 	str=balance(str);
// 	m=str.length();

// 	ll nOpen=0,nClose=0;
// 	for(ll i=0;i<m;i++)
// 	{
// 		if(str[i]=='(')
// 		{
// 			nOpen++;
// 		}
// 		else
// 		{
// 			nClose++;
// 		}
// 	}
// 	if(n<m)
// 	{
// 		cout<<0<<endl;
// 	}
// 	else
// 	{
// 		int ans1=noOfComb(str,n,m,nOpen,nClose,true);
// 		cout<<ans1<<endl<<endl;
// 		int ans2=noOfComb(str,n,m,nOpen,nClose,false);
// 		cout<<ans2<<endl;
// 		cout<<ans1+ans2<<endl;
// 	}

// 	return 0;
// }

//*************************************************************************************************************************************************

// #include <iostream>
// #define ll long long int
// using namespace std;

// ll noOfComb(string str,ll n,ll m,ll nOpen,ll nClose)
// {
// 	if(nOpen > n/2 or nClose > n/2 or n<m)
// 	{
// 		return 0;
// 	}

// 	if(n==m)
// 	{
// 		cout<<str<<endl;
// 		return 1;
// 	}

// 	if(nOpen<nClose)
// 	{
// 		return noOfComb('('+str,n,m+1,nOpen+1,nClose);
// 	}
// 	else if(nOpen>nClose)
// 	{
// 		return noOfComb(str+')',n,m+1,nOpen,nClose+1);
// 	}
// 	else
// 	{
// 		return noOfComb('('+str,n,m+1,nOpen+1,nClose)+noOfComb(str+')',n,m+1,nOpen,nClose+1)+noOfComb(')'+str,n,m+1,nOpen,nClose+1)+noOfComb(str+'(',n,m+1,nOpen+1,nClose);
// 	}
// }

// int main()
// {
// 	ll n,m;
// 	cin>>n>>m;
// 	string str;
// 	cin>>str;
// 	ll nOpen=0,nClose=0;
// 	for(ll i=0;i<m;i++)
// 	{
// 		if(str[i]=='(')
// 		{
// 			nOpen++;
// 		}
// 		else
// 		{
// 			nClose++;
// 		}
// 	}

// 	if(n%2==0)
// 	{
// 		cout<<noOfComb(str,n,m,nOpen,nClose)<<endl;
// 	}
// 	else
// 	{
// 		cout<<0<<endl;
// 	}

// 	return 0;
// }

//*************************************************************************************************************************************************

#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;

ll mod = 1e9 + 7;
char ss[100001];
int n, m;
ll dp[2222][2222][2];

int pre = 0, bef = 0;
int L;
ll solve(int p, int open, int take){
	if (p == L)return take && (open == 0);
	ll &ret = dp[p][open][take];
	if (ret != -1)return ret;
	ret = 0;
	if (!take){
		if (open >= pre)
			ret = (ret + solve(p + 1, open - pre +bef, 1)) % mod;
	}
	ret = (ret + solve(p + 1, open +1, take)) % mod;
	if(open)ret = (ret + solve(p + 1, open - 1, take)) % mod;
	return ret;
}
int main(){
	cin >> n >> m;
	L = n - m + 1;
	scanf("%s", ss);
	string s(ss);
	if (n % 2){
		cout << 0;
		return 0;
	}
	
	int x = 0;
	rep(i, m){
		if (s[i] == '(') x++;
		else x--;
		if (x < 0)pre++, x++;
	}
	bef = x;
	memset(dp, -1, sizeof dp);
	cout << solve(0, 0, 0);
	return 0;
}