#include<iostream>
#include <algorithm>
using namespace std;
bool comparator(int a,int b)
{
	int n=0,m=0;
	while(a>0)
	{
		n=n*10+a%10;
		a/=10;
	}
	while(b>0)
	{
		m=m*10+b%10;
		b/=10;
	}
	while(n>0 || m>0)
	{
		if(n%10 > m%10)
		{
			return true;
		}
		else if(n%10 < m%10)
		{
			return false;
		}
		else
		{
			n/=10;
			m/=10;
		}
	}
	return true;
}
int main() {
	int t;
	cin>>t;
	while(t>0)
	{
		int n,arr[100];
		cin>>n;
		for(int i=0;i<n;i++)
		{
			cin>>arr[i];
		}
		sort(arr,arr+n,comparator);
		for(int i=0;i<n;i++)
		{
			cout<<arr[i];
		}
		cout<<endl;
		t--;
	}
	return 0;
}