#include <iostream>
using namespace std;
//no. of BSTs using n nodes is given by nth catalan number

int catalan(int n)
{
	if(n==0)
	{
		return 1;
	}

	int num=0;
	for(int i=1;i<=n;i++)
	{
		num+=catalan(i-1)*catalan(n-i);
	}
	return num;
}

long long int fact(int n,int m=1)
{
	long long int res=1;
	if(n<m)
	{
		return 1;
	}
	while(n!=m)
	{
		res*=n;
		n--;
	}
	return res;
}

long long int nCr(int n,int r)
{
	if(r<n-r)
	{
		return fact(n,n-r)/fact(r);
	}
	else
	{
		return fact(n,r)/fact(n-r);
	}
}

long long int noOfBSTusingNnodes(int n)
{
	return nCr(2*n,n)/(n+1);
}

long long int noOfBTsUsingNnodes(int n)//binary trees
{
	return (nCr(2*n,n)/(n+1))*fact(n);
}

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	cout<<"Using recursive approach:-"<<endl;
	for(int i=0;i<=n;i++)
	{
		cout<<catalan(i)<<", ";
	}
	cout<<endl<<"Using formula:-"<<endl;
	for(int i=0;i<=n;i++)
	{
		cout<<nCr(2*i,i)/(i+1)<<", ";
	}
	cout<<endl<<"No of BST using "<<n<<" nodes = "<<noOfBSTusingNnodes(n)<<endl;
	cout<<endl<<"No of Binary Trees using "<<n<<" nodes = "<<noOfBTsUsingNnodes(n)<<endl;
	return 0;
}