#include<iostream>
#include <algorithm>
#define ll long long int
using namespace std;
bool comparator(ll a,ll b)
{
	ll n=a,m=b,c1=1,c2=1;
	while(a>0)
	{
		c1*=10;
		a/=10;
	}
	while(b>0)
	{
		c2*=10;
		b/=10;
	}
	//cout<<n<<" "<<m<<endl;
	ll n1=n*c2+m;
	ll m1=m*c1+n;
	//cout<<n1<<" "<<m1<<endl;
	return n1>m1;
}
int main() {
	ll t;
	cin>>t;
	while(t>0)
	{
		ll n,arr[100];
		cin>>n;
		for(ll i=0;i<n;i++)
		{
			cin>>arr[i];
		}
		sort(arr,arr+n,comparator);
		for(ll i=0;i<n;i++)
		{
			cout<<arr[i];
		}
		cout<<endl;
		t--;
	}
	return 0;
}