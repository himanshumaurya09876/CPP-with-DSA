// There's a scientist named Brook who is interested in budding of cells.
// He has one container which initially contains only a single cell. 
// Now Brook wants n number of cells in his container. 
// So he can change the number of cells in container in 3 different ways -:

// Double the number of cells present in the container.

// Increase the number of cells in the container by 1.

// Decrease the number of cells in the container by 1.

// Now, all the above operations have different costs associated with them x,y,z respectively
// for above operations. Help brook in finding the minimum cost to generate n cells in the container 
// starting from one cell .

// Input Format
// Each test case contains 2 lines. First lines contains an integer n Second lines contains 3 space separated integers x, y, and z

// Constraints
// 1<=n<=10^5 1<=x<=y<=z<=10^5

// Output Format
// Output an integer denoting the minimum cost incurred to create n cells

// Sample Input
// 5
// 2 1 3 
// Sample Output
// 4
// Explanation
// Initial number of cell is 1. Applying 2nd operations four times will give 5 cells in the container , and its total cost will be 1x4 = 4. One other way to do is - first adding a single cell with operation 2nd ,then doubling the cells , and then again adding one more cell , with cost = 1+2+1 =4.

#include <iostream>
using namespace std;

// int minmCost(int n,int x,int y,int z,int num=1)
// {
// 	if(num>n || num<1)
// 	{
// 		return INT_MAX;
// 	}

// 	if(num==n)
// 	{
// 		return 0;
// 	}

// 	int minm=0;
// 	int q1=INT_MAX,q2=INT_MAX,q3=INT_MAX;
// 	q1=minmCost(n,x,y,z,2*num)+x;
// 	q2=minmCost(n,x,y,z,num+1)+y;
// 	q3=minmCost(n,x,y,z,num-1)+z;

// 	minm=min(q1,min(q2,q3));
// 	return minm;
// }

int minmCostBU(int n,int x,int y,int z)
{
	int dp[10000];
	dp[0]=0;
	dp[1]=0;
	for(int i=2;i<=n;i++)
	{
		if(i%2)//i is odd
		{
			dp[i]=min(dp[i-1]+y,dp[(i+1)/2]+x+z);
		}
		else// i is even
		{
			dp[i]=min(dp[i/2]+x,dp[i-1]+y);
		}
	}

	return dp[n];
}

int main(int argc, char const *argv[])
{
	int n,x,y,z;
	cin>>n>>x>>y>>z;
	cout<<minmCostBU(n,x,y,z)<<endl;
	return 0;
}