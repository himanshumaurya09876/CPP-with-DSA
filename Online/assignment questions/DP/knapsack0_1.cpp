// 0-1 KNAPSACK
// You are packing for a vacation on the sea side and you are going to carry only one bag with capacity S (1 <= S <= 1000). You also have N (1<= N <= 1000) items that you might want to take with you to the sea side. Unfortunately you can not fit all of them in the knapsack so you will have to choose. For each item you are given its size and its value. You want to maximize the total value of all the items you are going to bring. What is this maximum total value?

// Input Format:
// On the first line you are given N and S. Next line contains N space separated integer which is the size of things and next line contains the corresponding value of things.

// Constraints:
// 1 <= S,N <= 1000

// Output Format
// You should output a single integer on one like - the total maximum value from the best choice of items for your trip.

// Sample Input
// 5 4
// 1 2 3 2 2 
// 8 4 0 5 3
// Sample Output
// 13

#include <iostream>
#include <cstring>
using namespace std;
int count;
int memo[1000][1000];

int maxValue(int size[],int value[],int n,int s,int idx=0)
{
	count++;
	if(idx>=n)
	{
		return 0;
	}

	int inc=0,exc=0;
	if(s-size[idx]>=0)
	{
		inc=value[idx]+maxValue(size,value,n,s-size[idx],idx+1);
	}
	exc=maxValue(size,value,n,s,idx+1);
	return max(inc,exc);
}

int maxValueTD(int size[],int value[],int n,int s,int idx=0)
{
	count++;
	if(idx>=n)
	{
		return 0;
	}

	if(memo[s][idx]!=-1)
	{
		return memo[s][idx];
	}

	int inc=0,exc=0;
	if(s-size[idx]>=0)
	{
		inc=value[idx]+maxValueTD(size,value,n,s-size[idx],idx+1);
	}
	exc=maxValueTD(size,value,n,s,idx+1);
	memo[s][idx]= max(inc,exc);
	return memo[s][idx];
}

int maxValueBU(int size[],int value[],int n,int s)
{
	int dp[100][100];
	for(int i=0;i<=s;i++)
	{
		dp[0][i]=0;
	}
	for(int i=0;i<=n;i++)
	{
		dp[i][0]=0;
	}

	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=s;j++)
		{
			int inc=0,exc=0;
			exc=dp[i-1][j];
			if(size[i-1]<=j)
			{
				inc=value[i-1]+dp[i-1][j-size[i-1]];
			}

			dp[i][j]=max(inc,exc);
		}
	}

	// for(int i=0;i<=n;i++)
	// {
	// 	for(int j=0;j<=s;j++)
	// 	{
	// 		cout<<dp[i][j]<<" ";
	// 	}
	// 	cout<<endl;
	// }

	return dp[n][s];
}


int main()
{
	int n,s;
	cin>>n>>s;
	int *size=new int[n];
	int *value=new int[n];
	for(int i=0;i<n;i++)
	{
		cin>>size[i];
	}
	for(int i=0;i<n;i++)
	{
		cin>>value[i];
	}

	cout<<maxValueBU(size,value,n,s)<<endl;

	memset(memo,-1,sizeof(memo));
	count=0;
	cout<<maxValueTD(size,value,n,s)<<" "<<count<<endl;

	count=0;
	cout<<maxValue(size,value,n,s)<<" "<<count<<endl;
	return 0;
}