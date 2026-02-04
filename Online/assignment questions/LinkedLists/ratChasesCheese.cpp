// RAT CHASES ITS CHEESE
// You are given an N*M grid. Each cell (i,j) in the grid is either blocked, or empty. The rat can move from a position towards left, right, up or down on the grid.
// Initially rat is on the position (1,1). It wants to reach position (N,M) where it's cheese is waiting for. There exits a unique path in the grid . Find that path and help the rat reach its cheese.

// Input Format:
// First line contains 2 integers N and M denoting the rows and columns in the grid.
// Next N line contains M characters each. An 'X' in position (i,j) denotes that the cell is blocked and ans 'O' denotes that the cell is empty.

// Constraints:
// 1 <= N , M <= 10

// Output Format
// Print N lines, containing M integers each. A 1 at a position (i,j) denotes that the (i,j)th cell is covered in the path and a 0 denotes that the cell is not covered in the path.
// If a path does not exits then print "NO PATH FOUND"

// Sample Input
// 5 4
// OXOO
// OOOX
// XOXO
// XOOX
// XXOO
// Sample Output
// 1 0 0 0 
// 1 1 0 0 
// 0 1 0 0 
// 0 1 1 0 
// 0 0 1 1 

#include<iostream>
using namespace std;

bool isPossible(char grid[][10],bool sol[][10],int n,int m,int i,int j)
{
	if(i>=0 && i<n && j>=0 && j<m && grid[i][j]!='X' && sol[i][j]!=1)
	{
		return true;
	}
	return false;
}

bool findPath(char grid[][10],bool sol[][10],int n,int m,int i=0,int j=0)
{
	if(i==n-1 && j==m-1)
	{
		if(isPossible(grid,sol,n,m,i,j))
		{
			sol[i][j]=1;
			for(int i=0;i<n;i++)
			{
				for(int j=0;j<m;j++)
				{
					cout<<sol[i][j]<<" ";
				}
				cout<<endl;
			}
			return true;
		}
		else
		{
			return false;
		}
	}
	if(isPossible(grid,sol,n,m,i,j))
	{
		sol[i][j]=1;
		//for upper cell
		if(findPath(grid,sol,n,m,i-1,j))
		{
			return true;
		}
		//for right cell
		if(findPath(grid,sol,n,m,i,j+1))
		{
			return true;
		}
		//for left cell
		if(findPath(grid,sol,n,m,i,j-1))
		{
			return true;
		}
		//for lower cell
		if(findPath(grid,sol,n,m,i+1,j))
		{
			return true;
		}
		sol[i][j]=0;
	}
	return false;
}

int main() {
	int n,m;
	char grid[10][10];
	bool sol[10][10]={0};
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>grid[i][j];
		}
	}
	if(!findPath(grid,sol,n,m))
	{
		cout<<"NO PATH FOUND"<<endl;
	}
	return 0;
}