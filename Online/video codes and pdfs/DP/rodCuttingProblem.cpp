#include <iostream>
using namespace std;
int memo[1000];//here we are taking 1D array/memo but it is an example of 2D DP
int count;

int profit(int price[],int len)//recursive
{
	count++;
	if(len==0)
	{
		return 0;
	}

	int maxm=0;
	for(int i=1;i<=len;i++)
	{
		int curr=price[i]+profit(price,len-i);
		maxm=max(maxm,curr);
	}

	return maxm;
}

int profitTD(int price[],int len)//top down DP
{
	count++;
	if(len==0)
	{
		return 0;
	}

	if(memo[len]!=-1)
	{
		return memo[len];
	}

	int maxm=0;
	for(int i=1;i<=len;i++)
	{
		int curr=price[i]+profitTD(price,len-i);
		maxm=max(maxm,curr);
	}
	memo[len]=maxm;
	return maxm;
}

int profitBU(int price[],int len)
{
	int dp[1000];
	dp[0]=0;
	for(int i=1;i<=len;i++)
	{
		int maxm=0;
		for(int j=1;j<=i;j++)
		{
			maxm=max(maxm,price[j]+dp[i-j]);
		}
		dp[i]=maxm;
	}

	for(int i=0;i<=len;i++)
	{
		cout<<dp[i]<<"  "; 
	}
	cout<<endl;

	return dp[len];
}

int main(int argc, char const *argv[])
{
	int len;
	cin>>len;
	int *price=new int[len+1];
	price[0]=0;
	for(int i=1;i<=len;i++)
	{
		cin>>price[i];
	}

	cout<<profitBU(price,len)<<endl;
	for(int i=0;i<=len;i++)
	{
		memo[i]=-1;
	}
	count=0;
	cout<<profitTD(price,len)<<"   "<<count<<endl;
	count=0;
	cout<<profit(price,len)<<"   "<<count<<endl;
	return 0;
}