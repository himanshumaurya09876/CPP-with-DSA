#include <iostream>
using namespace std;
//here solutions are forming a series called catalan series 1,1,2,5.....
//each member is given by 2nCn/(n+1)

int dp[100];
int calls;

int noOfBST(int n)
{
	calls++;
	if(n==0 || n==1)//base case
	{
		return 1;
	}
	// else if(n==2)
	// {
	// 	return 2;
	// }
	// else if(n==3)
	// {
	// 	return 5;
	// }

	int res=0;
	for(int i=1;i<=n;i++)
	{
		res+=noOfBST(i-1)*noOfBST(n-i);
	}

	return res;
}

int noOfBSTtopDownDP(int n)
{
	calls++;
	if(n==0 || n==1)
	{
		return 1;
	}
	
	if(dp[n]!=-1)
	{
		return dp[n];
	}

	int res=0;
	for(int i=1;i<=n;i++)
	{
		res+=noOfBSTtopDownDP(i-1)*noOfBSTtopDownDP(n-i);
	}
	dp[n]=res;
	return res;
}

int fact(int n)
{
	int res=1;
	while(n>0)
	{
		res*=n;
		n--;
	}
	return res;
}

int noOfBT(int n)
{
	return fact(n)*noOfBSTtopDownDP(n);
}

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	cout<<"******************Using recursion only******************"<<endl;
	calls=0;
	cout<<noOfBST(n)<<endl;
	cout<<"calls="<<calls<<endl;

	cout<<"******************Using recursion with top down dp******************"<<endl;
	for(int i=0;i<=n;i++)
	{
		dp[i]=-1;
	}
	calls=0;
	cout<<noOfBSTtopDownDP(n)<<endl;
	cout<<"calls="<<calls<<endl;
	for(int i=0;i<=n;i++)
	{
		cout<<dp[i]<<" ";
	}

	cout<<endl<<"for binary trees just multiply with n!"<<endl;
	cout<<noOfBT(n)<<endl;
	return 0;
}