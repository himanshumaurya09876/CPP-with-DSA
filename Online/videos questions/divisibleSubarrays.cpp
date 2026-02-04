#include <iostream>
#define ll long long int
using namespace std;
int main()
{
	ll t;
	cin>>t;
	while(t>0)
	{
		ll n;
		cin>>n;
		ll *arr=new ll[n];
		for(ll i=0;i<n;i++)
		{
			cin>>arr[i];
		}

		ll *csum=new ll[n+1];
		csum[0]=0;
		for(ll i=1;i<=n;i++)
		{
			csum[i]=csum[i-1]+arr[i-1];
			csum[i]=csum[i]%n;
			if(csum[i]<0)
			{
				csum[i]=csum[i]+n;
			}
			// cout<<csum[i]<<" ";
		}
		// cout<<endl;

		ll *freqArr=new ll[n+1];
		fill(freqArr,freqArr+n+1,0);
		for(ll i=0;i<=n;i++)
		{
			freqArr[csum[i]]++;
		}

		ll ans=0;
		for(ll i=0;i<=n;i++)
		{
			ll num=freqArr[i];
			// cout<<num<<" ";
			ans+=num*(num-1)/2;
		}
		cout<<ans<<endl;
		t--;
	}
	return 0;
}