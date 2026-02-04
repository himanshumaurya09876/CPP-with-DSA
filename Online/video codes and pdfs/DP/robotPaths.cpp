// All submissions for this problem are available.
// A robot is designed to move on a rectangular grid of M rows and N columns. The robot is initially positioned at (1, 1), i.e., the top-left cell. The robot has to reach the (M, N) grid cell. In a single step, robot can move only to the cells to its immediate east and south directions. That means if the robot is currently at (i, j), it can move to either (i + 1, j) or (i, j + 1) cell, provided the robot does not leave the grid.

// Now somebody has placed several obstacles in random positions on the grid, through which the robot cannot pass. Given the positions of the blocked cells, your task is to count the number of paths that the robot can take to move from (1, 1) to (M, N).

// Since the answer can get very large, output the answer modulo 1000000007.

// Input
// The first line contains 3 integers M, N and P denoting the number of rows, number of columns and number of blocked cells respectively.
// In the next P lines, each line has exactly 2 integers i and j denoting that the cell (i, j) is blocked.

// Output
// Output should contain a single integer, the number of paths modulo 1000000007.

// Constraints
// 1 <= M, N <= 103
// 0 <= P <= M * N
// 1 <= i <= M
// 1 <= j <= N
// Example
// Input
// 4 3 2
// 3 3
// 3 1

// Output
// 2

// Explanation
// The only 2 possible paths are
// (1, 1) -> (1, 2) -> (2, 2) -> (3, 2) -> (4, 2) -> (4, 3) and
// (1, 1) -> (2, 1) -> (2, 2) -> (3, 2) -> (4, 2) -> (4, 3)

#include <iostream>
#define ll long long
using namespace std;
ll mod=1000000007;

// this is bottom up approach
// we have seen its recursion with backtracking in rat in maze problem
ll totalPaths(ll arr[][1000],ll m,ll n)
{
	if(arr[0][0]==-1)
	{
		return 0;
	}
	arr[0][0]=1;
	for(int i=1;i<m;i++)
	{
		if(arr[i][0]==-1)
		{
			break;
		}
		arr[i][0]=1;
	}
	for(int i=1;i<n;i++)
	{
		if(arr[0][i]==-1)
		{
			break;
		}
		arr[0][i]=1;
	}
	for(int i=1;i<m;i++)
	{
		for(int j=1;j<n;j++)
		{
			if(arr[i][j]!=-1)
			{
				if(arr[i-1][j]!=-1)
				{
					arr[i][j]=arr[i-1][j];
				}
				if(arr[i][j-1]!=-1)
				{
					arr[i][j]+=arr[i][j-1];
				}
				arr[i][j]=arr[i][j]%mod;
			}
		}
	}
	// for(int i=0;i<m;i++)
	// {
	// 	for(int j=0;j<n;j++)
	// 	{
	// 		cout<<arr[i][j]<<" ";
	// 	}
	// 	cout<<endl;
	// }
	if(arr[m-1][n-1]==-1)
	{
		return 0;
	}
	return arr[m-1][n-1];
}

int main()
{
	ll m,n,p;
	cin>>m>>n>>p;
	// ll **arr=new ll*[m];
	// for(ll i=0;i<m;i++)
	// {
	// 	arr[i]=new ll[n];
	// }
	ll arr[1000][1000]={0};
	for(ll i=0;i<p;i++)
	{
		ll x,y;
		cin>>x>>y;
		arr[x-1][y-1]=-1;
	}
	cout<<totalPaths(arr,m,n)%mod<<endl;
	return 0;
}