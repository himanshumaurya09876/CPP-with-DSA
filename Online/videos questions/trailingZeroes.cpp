#include <iostream>
#define ll long long
using namespace std;

// ll numberOf0(ll n)
// {
// 	ll count=0;
// 	ll num=1;
// 	while(n>0)
// 	{
// 		if(n%5==0 || n%2==0)
// 		{
// 			num=num*n;
// 		}
// 		while(num%10==0)
// 		{
// 			num=num/10;
// 			count++;
// 		}
// 		n--;
// 	}

// 	return count;
// }

ll numberOfTrailing0s(ll n)
{
	ll num=5;
	ll count=0;
	while(num<=n)
	{
		count+=n/num;
		num*=5;
	}
	return count;
}

int main()
{
	ll n;
	cin>>n;
	cout<<numberOfTrailing0s(n)<<endl;
	return 0;
}