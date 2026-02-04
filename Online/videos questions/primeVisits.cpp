#include <iostream>
#define ll long long 
using namespace std;
int main()
{
	ll n;

	bool sieve[1000001];
	ll m=1000001;
	sieve[0]=false;
	sieve[1]=false;
	sieve[2]=true;
	for(ll i=3;i<m;i++)
	{
		if(i%2)
		{
			sieve[i]=true;
		}
		else
		{
			sieve[i]=false;
		}
	}

	for(ll i=3;i<m;i+=2)
	{
		if(sieve[i]==true)
		{
			for(ll j=i*i;j<m;j+=2*i)
			{
				sieve[j]=false;
			}
		}
	}

	cin>>n;
	while(n>0)
	{
		ll a,b;
		cin>>a>>b;
		ll count=0;
		for(ll i=a;i<=b;i++)
		{
			if(sieve[i])
			{
				// cout<<i<<" ";
				count++;
			}
		}
		// cout<<endl;
		cout<<count<<endl;
		n--;
	}
	return 0;
}