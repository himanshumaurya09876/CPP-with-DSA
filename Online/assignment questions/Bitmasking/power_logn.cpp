//power in O(logn)

#include<iostream>
using namespace std;
long long int calPower(int n,int p)
{
	if(p==0)
	{
		return 1;
	}
	long long int res=1;
	long long int sol=calPower(n,p/2);
	res=sol*sol;
	if(p&1)
	{
		res*=n;
	}
	return res;
}

int main() {
	int n,p;
	cin>>n>>p;
	cout<<calPower(n,p);
	return 0;
}