#include <iostream>

using namespace std;

int product(int n,int m)
{
	if(m==0)
	{
		return 0;
	}
	int res;
	if(m>0 && n>0)
	{
		res=n+product(n,m-1);
	}
	else if(m<0 && n>0)
	{
		res=-n+product(n,m+1);
	}
	else if(m<0 && n<0)
	{
		res=-n+product(n,m+1);
	}
	else
	{
		res=n+product(n,m-1);
	}
	return res;
}

int main()
{
	int n,m;
	cout<<"Enter two numbers: ";
	cin>>n>>m;
	cout<<"Product is: "<<product(n,m)<<endl;
}