#include <iostream>
using namespace std;
int memo[1000];

int nthFib(int n)//recursive
//it is most bekaar approach because it is calculating repeated things again and again
//ie it is performing same tasks again and again 
//here we have subproblems which are repeating themselves or we can say overlapping subproblems
//so Dynamic Programming DP can be used here
{
	if(n==0)
	{
		return 0;
	}
	if(n==1)
	{
		return 1;
	}

	int ans=nthFib(n-1)+nthFib(n-2);
	return ans;
}

int nthFibTopDownDP(int n)//top down DP also called memoization
//it fails sometimes because
//it is fast but it uses stack to call functions again and again (recursion) which results in wastage of time 
//and space, we will see pure DP which is best
{
	if(n==0)
	{
		return 0;
	}
	if(n==1)
	{
		return 1;
	}

	if(memo[n]!=-1)
	{
		return memo[n];
	}

	int ans=nthFibTopDownDP(n-1)+nthFibTopDownDP(n-2);
	memo[n]=ans;
	return ans;
}

int nthFibBottomUpDP(int n)//bottom up DP also called pure DP
//it is fastest as it doesnot uses stack ie recursion is not required 
{
	int DP[1000];
	DP[0]=0;
	DP[1]=1;
	for(int i=2;i<=n;i++)
	{
		DP[i]=DP[i-1]+DP[i-2];
	}

	return DP[n];
}

int nthFibBest(int n)//most optimized in terms of space also
{
	int a=0;
	int b=1;
	int res=a+b;
	while(n>0)
	{
		a=b;
		b=res;
		res=a+b;
		n--;
	}

	return a;
}

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;

	cout<<"Particularly for Fibonacci number -> most optimized and fast"<<endl;
	cout<<nthFibBest(n)<<endl;

	cout<<"Bottom Up DP also called pure DP -> Fastest"<<endl;
	cout<<nthFibBottomUpDP(n)<<endl;

	cout<<"Top Down DP also called memoization -> Fast"<<endl;
	for(int i=0;i<=n;i++)
	{
		memo[i]=-1;
	}
	cout<<nthFibTopDownDP(n)<<endl;

	cout<<"Recursive -> Very Slow"<<endl;
	cout<<nthFib(n)<<endl;
	return 0;
}