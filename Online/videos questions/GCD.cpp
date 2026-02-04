#include <iostream>
using namespace std;

int gcd(int a,int b)
{
	if(a==0)
	{
		return b;
	}

	return gcd(b%a,a);
}

int main(int argc, char const *argv[])
{
	int n1,n2;
	cin>>n1>>n2;
	cout<<gcd(n1,n2)<<endl;
	return 0;
}