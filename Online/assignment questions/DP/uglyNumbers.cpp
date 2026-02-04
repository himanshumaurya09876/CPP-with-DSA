// UGLY NUMBERS
// You are provided a sequence of number. All numbers of that sequence is in increasing order (including 1) and whose only prime factors are 2, 3 or 5 (except 1). You need to find the nth number of that sequence.

// Input Format:
// First line contains integer t which is number of test case. For each test case, it contains an integer n.

// Constraints:
// 1<=t<=100 1<=n<=10000

// Output Format
// Print nth number of that sequence.

// Sample Input
// 2
// 7
// 10
// Sample Output
// 8
// 12

// these approaches are fast but not good for large values of n
// one approach is similar to as used in prime seive
// here its recursive form is implemented u can also implement the iterative form as used in prime seive
// #include <iostream>
// #define ll long long int
// using namespace std;
// ll uglyList[10001];

// void fillUglyNum(bool dp[],ll num=1)
// {	
// 	if(num>=10000000)
// 	{
// 		return;
// 	}

// 	dp[num]=1;
// 	fillUglyNum(dp,num*2);
// 	fillUglyNum(dp,num*3);
// 	fillUglyNum(dp,num*5);
// }

// void uglyNum()
// {
// 	bool *dp=new bool[10000000];
// 	fill(dp,dp+10000000,0);
// 	fillUglyNum(dp);

// 	ll j=0;
// 	for(ll i=0;i<10000000 && j<10001;i++)
// 	{
// 		if(dp[i])
// 		{
// 			uglyList[j++]=i;
// 		}
// 	}
// }

// int main()
// {
// 	ll t;
// 	uglyNum();

// 	// for(ll i=0;i<500;i++)
// 	// {
// 	// 	cout<<"("<<i+1<<" -> "<<uglyList[i]<<") "<<endl;;
// 	// }

// 	// cin>>t;
// 	// while(t>0)
// 	// {
// 	// 	ll n;
// 	// 	cin>>n;
// 	// 	cout<<uglyList[n]<<endl;
// 	// 	t--;
// 	// }
// 	return 0;
// }


#include <iostream>
// #include <map>
#include <set>
#define ll long long int
using namespace std;
ll uglyList[10001];


//using set
void fillUglyNum()
{	
	set<ll> st;
	ll j=0;
	uglyList[j++]=1;
	st.insert(2);
	st.insert(3);
	st.insert(5);
	while(!st.empty() and j<10001)
	{
		ll entry=*(st.begin());
		uglyList[j++]=entry;
		st.insert(2*entry);
		st.insert(3*entry);
		st.insert(5*entry);
		st.erase(entry);
	}
}

// //using map
// void fillUglyNum()
// {	
// 	mp<ll,bool> mp;
// 	ll j=0;
// 	uglyList[j++]=1;
// 	mp.insert(make_pair(2,true));
// 	mp.insert(make_pair(3,true));
// 	mp.insert(make_pair(5,true));
// 	while(!mp.empty() and j<10001)
// 	{
// 		pair<ll,bool> entry=*(mp.begin());
// 		uglyList[j++]=entry.first;
// 		mp.insert(make_pair(entry.first*2,true));
// 		mp.insert(make_pair(entry.first*3,true));
// 		mp.insert(make_pair(entry.first*5,true));
// 		mp.erase(entry.first);
// 	}
// }


int main()
{
	ll t;
	fillUglyNum();

	for(ll i=0;i<10001;i++)
	{
		cout<<"("<<i+1<<" -> "<<uglyList[i]<<") "<<endl;;
	}

	cin>>t;
	while(t>0)
	{
		ll n;
		cin>>n;
		cout<<uglyList[n-1]<<endl;
		t--;
	}
	return 0;
}