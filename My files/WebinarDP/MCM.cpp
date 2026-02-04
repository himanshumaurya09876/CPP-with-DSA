//MCM-> matrix chain multiplication
//matrix multiplication is associative ie (A*B)*C=A*(B*C)
//but order in which multiplication is performed determines the total number of operations
//here we have to find min no. of operations required to multiply a chain of matrices

#include <iostream>
using namespace std;

int dp[100][100];

int minOperations(int dim[],int n)//it uses bottom up dp
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(j<i)
			{
				dp[i][j]=-1;
			}
			else if(j==i)
			{
				dp[i][j]=0;
			}
		}
	}

	for(int i=n-2;i>=0;i--)
	{
		for(int j=i+1;j<n;j++)
		{
			// for maximum no. of steps
			// int maxm=INT_MIN;
			// for(int k=i;k<j;k++)
			// {
			// 	maxm=max(maxm,dp[i][k]+dp[k+1][j]+(dim[i]*dim[k+1]*dim[j+1]));
			// }
			// dp[i][j]=maxm;

			// for minimum no. of steps
			int minm=INT_MAX;
			for(int k=i;k<j;k++)
			{
				minm=min(minm,dp[i][k]+dp[k+1][j]+(dim[i]*dim[k+1]*dim[j+1]));
			}
			dp[i][j]=minm;
		}
	}

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}

	return dp[0][n-1];
}

int main(int argc, char const *argv[])
{
	int n,dimensions[100];
	cin>>n;//n denotes no of matrices
	for(int i=0;i<=n;i++)
	{
		cin>>dimensions[i];//dimensions required are n+1 to find min operations
	}
	cout<<minOperations(dimensions,n)<<endl;
	return 0;
}