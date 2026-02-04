// 0-N KNAPSACK
// You've heard of 0-1 knapsack. Below is the problem statement for the same.

// Given weights and values of n items, put these items in a knapsack of capacity cap to get the maximum total value in the knapsack. In other words, given two integer arrays val[0..n-1] and wt[0..n-1] which represent values and weights associated with n items respectively. Also given an integer cap which represents knapsack capacity, find out the maximum value subset of val[] such that sum of the weights of this subset is smaller than or equal to cap. You cannot break an item, either pick the complete item, or don’t pick it (0-1 property).
// There is a little twist for 0-N knapsack. You can pick an element more than once. Now you have to find maximum value multi subset of val[] such that sum of the weights of this subset is smaller than or equal to cap.

// Note: Maximum value subset means the sunset with maximum sum of all the values in subset.

// Input Format:
// The first line contains two integers, representing n(size of val[]) and cap respectively. The subsequent line contains n integers representing the wt[] array. The next line, again, contains n integers representing the val[] array.

// Constraints:
// 1 <= n,cap <= 1000 1 <= wt[i] <= cap 1 <= val[i] <= 100000

// Output Format
// Print a single integer, the answer to the problem.

// Sample Input
// 5 11
// 3 2 4 5 1
// 4 3 5 6 1
// Sample Output
// 16


// this is using 2D DP but this question can be solved using 1D DP
// #include <iostream>
// #include <cstring>
// using namespace std;
// int count;
// int memo[1000][1000];

// int maxValue(int size[],int value[],int n,int s,int idx=0)
// {
// 	count++;

// 	if(idx>=n)
// 	{
// 		return 0;
// 	}

// 	int inc=0,exc=0;
// 	int num=1;
// 	while(s-num*size[idx]>=0)
// 	{
// 		inc=max(inc,num*value[idx]+maxValue(size,value,n,s-num*size[idx],idx+1));
// 		num++;
// 	}
// 	exc=maxValue(size,value,n,s,idx+1);
// 	return max(inc,exc);
// }

// int maxValueTD(int size[],int value[],int n,int s,int idx=0)
// {
// 	count++;

// 	if(idx>=n)
// 	{
// 		return 0;
// 	}

// 	if(memo[s][idx]!=-1)
// 	{
// 		return memo[s][idx];
// 	}

// 	int inc=0,exc=0;
// 	int num=1;
// 	while(s-num*size[idx]>=0)
// 	{
// 		inc=max(inc,num*value[idx]+maxValue(size,value,n,s-num*size[idx],idx+1));
// 		num++;
// 	}
// 	exc=maxValueTD(size,value,n,s,idx+1);
// 	memo[s][idx]= max(inc,exc);
// 	return memo[s][idx];
// }

// int maxValueBU(int size[],int value[],int n,int s)
// {
// 	int dp[100][100];
// 	for(int i=0;i<=s;i++)
// 	{
// 		dp[0][i]=0;
// 	}
// 	for(int i=0;i<=n;i++)
// 	{
// 		dp[i][0]=0;
// 	}

// 	for(int i=1;i<=n;i++)
// 	{
// 		for(int j=1;j<=s;j++)
// 		{
// 			int inc=0,exc=0;
// 			exc=dp[i-1][j];
// 			if(size[i-1]<=j)
// 			{
// 				inc=value[i-1]+dp[i-1][j-size[i-1]];
// 			}

// 			dp[i][j]=max(inc,exc);
// 		}
// 	}

// 	// for(int i=0;i<=n;i++)
// 	// {
// 	// 	for(int j=0;j<=s;j++)
// 	// 	{
// 	// 		cout<<dp[i][j]<<" ";
// 	// 	}
// 	// 	cout<<endl;
// 	// }

// 	return dp[n][s];
// }


// int main()
// {
// 	int n,s;
// 	cin>>n>>s;
// 	int *size=new int[n];
// 	int *value=new int[n];
// 	for(int i=0;i<n;i++)
// 	{
// 		cin>>size[i];
// 	}
// 	for(int i=0;i<n;i++)
// 	{
// 		cin>>value[i];
// 	}

// 	// cout<<maxValueBU(size,value,n,s)<<endl;

// 	memset(memo,-1,sizeof(memo));
// 	count=0;
// 	cout<<maxValueTD(size,value,n,s)<<" "<<count<<endl;
// 	// for(int i=0;i<=n;i++)
// 	// {
// 	// 	for(int j=0;j<=s;j++)
// 	// 	{
// 	// 		cout<<memo[i][j]<<" ";
// 	// 	}
// 	// 	cout<<endl;
// 	// }

// 	count=0;
// 	cout<<maxValue(size,value,n,s)<<" "<<count<<endl;
// 	return 0;
// }

#include <iostream>
using namespace std;

int maxValueBU(int size[],int value[],int n,int s)
{
	int dp[1001];
	fill(dp,dp+s+1,0);
	for(int i=1;i<=s;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(size[j]<=i)
			{
				dp[i]=max(dp[i],value[j]+dp[i-size[j]]);
			}
		}
	}

	return dp[s];
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
	return 0;
}