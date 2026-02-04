#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t>0)
	{
		int n;
		cin>>n;
		int ans=0;
		while(n>0)
		{
			if(n&1)
			{
				ans++;
			}
			n=n>>1;
		}
		cout<<ans<<endl;
		t--;
	}
	return 0;
}